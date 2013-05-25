/******************************************************************************
* File Name : gmouse.c                             Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       ゲームシステム用 マウス入力.
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"gmouse.h"
#include	"heap.h"
#define		DIRECTINPUT_VERSION		0x0700
#include	<dinput.h>

/****** データ型宣言 *********************************************************/

/*----- マウス入力構造体 ----------------------------------------------------*/

typedef	struct
{
	HINSTANCE            hinst;		/* インスタンスハンドラ         */
	HWND                 hwnd;		/* ウィンドウハンドラ           */
	LPDIRECTINPUT        dinp;		/* DirectInputハンドラ          */
	LPDIRECTINPUTDEVICE2 idev;		/* キーボードデバイス           */
	int                  ox;		/* 前回からのｘ方向移動量       */
	int                  oy;		/* 前回からのｙ方向移動量       */
	int                  oz;		/* 前回からのｚ方向移動量       */
	FLOAT                px;		/* マウスカーソルｘ座標         */
	FLOAT                py;		/* マウスカーソルｙ座標         */
	FLOAT                pz;		/* マウスカーソルｚ座標         */
	GMOUSTATE            newbtn;	/* 現在のマウスのボタンの状態   */
	GMOUSTATE            oldbtn;	/* 前回のマウスのボタンの状態   */
	RECT                 clip;		/* マウスカーソルの移動範囲     */
	FLOAT                ratio;		/* マウスカーソルの移動比率     */

} GINPMOUSE;

/****** 関数プロトタイプ宣言 *************************************************/

static BOOL	init_mouse_input( GINPMOUSE*, HINSTANCE, HWND );
static void	cleanup_mouse_input( GINPMOUSE* );
static void	read_mouse_input( GINPMOUSE* );
static BOOL	reacquire_mouse_input( GINPMOUSE* );
static void	clip_mouse_cursor( GINPMOUSE* );
static BOOL	reacquire_input( LPDIRECTINPUTDEVICE2 );

/// <summary>
/// マウスの生成.
/// </summary>
/// <param name="hinst">インスタンスハンドラ</param>
/// <param name="hwnd">ウィンドウハンドラ</param>
/// <returns>マウスハンドラを返す.</returns>
GMOUSE
GMouseNew
(
	HINSTANCE		hinst,			/* インスタンスハンドラ     */
	HWND			hwnd			/* ウィンドウハンドラ       */
)
{
	GINPMOUSE*		mouse;

	mouse = new_object( sizeof( GINPMOUSE ) );

	if ( init_mouse_input( mouse, hinst, hwnd ) == FALSE )
	{
		del_object( mouse );

		return	NULL;
	}

	return	(GMOUSE)mouse;
}

/// <summary>
/// マウスの消滅.
/// </summary>
/// <param name="hnd">マウスハンドラ</param>
void
GMouseDelete
(
	GMOUSE			hnd				/* マウスハンドラ           */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	cleanup_mouse_input( mouse );

	del_object( mouse );
}

/// <summary>
/// マウスの読み込み.
/// </summary>
/// <param name="hnd">マウスハンドラ</param>
void
GMouseReadDevice
(
	GMOUSE			hnd				/* マウスハンドラ           */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	/* マウスの状態の読み込み */
	read_mouse_input( mouse );

	/* 移動量の加算 */
	mouse->px += ( mouse->ox * mouse->ratio );
	mouse->py += ( mouse->oy * mouse->ratio );
	mouse->pz += ( mouse->oz * mouse->ratio );

	/* マウス位置のクリッピング */
	clip_mouse_cursor( mouse );
}

/// <summary>
/// マウスの移動量を取得.
/// </summary>
/// <param name="hnd">マウスハンドラ</param>
/// <param name="x">X方向移動量</param>
/// <param name="y">Y方向移動量</param>
/// <param name="z">Z方向移動量</param>
void
GMouseGetOffsetPosition
(
	GMOUSE			hnd,			/* マウスハンドラ           */
	int*			x,				/*-> ｘ方向移動量           */
	int*			y,				/*-> ｙ方向移動量           */
	int*			z				/*-> ｚ方向移動量           */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	if ( x != NULL )
	{
		*x = (int)mouse->ox;
	}
	if ( y != NULL )
	{
		*y = (int)mouse->oy;
	}
	if ( z != NULL )
	{
		*z = (int)mouse->oz;
	}
}

/// <summary>
/// マウスカーソルの位置を取得.
/// </summary>
/// <param name="hnd">マウスハンドラ</param>
/// <param name="x">X座標</param>
/// <param name="y">Y座標</param>
void
GMouseGetCursorPosition
(
	GMOUSE			hnd,			/* マウスハンドラ           */
	int*			x,				/*-> ｘ座標                 */
	int*			y				/*-> ｙ座標                 */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	if ( x != NULL )
	{
		*x = (int)mouse->px;
	}
	if ( y != NULL )
	{
		*y = (int)mouse->py;
	}
}

/// <summary>
/// マウスのボタンの押下状態を取得.
/// </summary>
/// <param name="hnd">マウスハンドラ</param>
/// <param name="state">調べたいマウスのボタン</param>
/// <returns>押されていれば真，押されていければ偽を返す.</returns>
BOOL
GMouseGetButtonState
(
	GMOUSE			hnd,			/* マウスハンドラ           */
	GMOUSTATE		state			/* 調べたいマウスのボタン   */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	if ( ( mouse->newbtn & state ) != 0 )
	{
		return	TRUE;
	}

	return	FALSE;
}

/// <summary>
/// マウスのボタンの押されたか調べる.
/// </summary>
/// <param name="hnd">マウスハンドラ</param>
/// <param name="state">調べたいマウスのボタン</param>
/// <returns>押されていれば真，押されていければ偽を返す.</returns>
BOOL
GMouseGetButtonTrigger
(
	GMOUSE			hnd,			/* マウスハンドラ           */
	GMOUSTATE		state			/* 調べたいマウスのボタン   */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	if ( ( ( ~mouse->oldbtn & mouse->newbtn ) & state ) != 0 )
	{
		return	TRUE;
	}

	return	FALSE;
}

/// <summary>
/// マウスのボタンが離されたか調べる.
/// </summary>
/// <param name="hnd">マウスハンドラ</param>
/// <param name="state">調べたいマウスのボタン</param>
/// <returns>押されていれば真，押されていければ偽を返す.</returns>
BOOL
GMouseGetButtonDetach
(
	GMOUSE			hnd,			/* マウスハンドラ           */
	GMOUSTATE		state			/* 調べたいマウスのボタン   */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	if ( ( ( mouse->oldbtn & ~mouse->newbtn ) & state ) != 0 )
	{
		return	TRUE;
	}

	return	FALSE;
}

/// <summary>
/// マウスカーソルの移動比率の取得.
/// </summary>
/// <param name="hnd">マウスハンドラ</param>
/// <returns>移動比率.</returns>
FLOAT
GMouseGetMoveRatio
(
	GMOUSE			hnd				/* マウスハンドラ           */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	return	mouse->ratio;
}

/// <summary>
/// マウスカーソルの移動比率の設定.
/// </summary>
/// <param name="hnd">マウスハンドラ</param>
/// <param name="hnd">移動比率</param>
void
GMouseSetMoveRatio
(
	GMOUSE			hnd,			/* マウスハンドラ           */
	FLOAT			ratio			/* 移動比率                 */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	mouse->ratio = ratio;
}

/// <summary>
/// マウスカーソルの位置を設定.
/// </summary>
/// <param name="hnd">マウスハンドラ</param>
/// <param name="x">X座標</param>
/// <param name="y">Y座標</param>
void
GMouseSetCursorPosition
(
	GMOUSE			hnd,			/* マウスハンドラ           */
	int				x,				/* ｘ座標                   */
	int				y				/* ｙ座標                   */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	/* マウスカーソルの位置を設定 */
	mouse->px = (FLOAT)x;
	mouse->py = (FLOAT)y;

	/* マウス位置のクリッピング */
	clip_mouse_cursor( mouse );
}

/// <summary>
/// マウスカーソルの移動範囲を設定.
/// </summary>
/// <param name="hnd">マウスハンドラ</param>
/// <param name="xmin">X座標最小値</param>
/// <param name="xmax">X座標最大値</param>
/// <param name="ymin">Y座標最小値</param>
/// <param name="ymax">Y座標最大値</param>
void
GMouseSetPhysicalBlock
(
	GMOUSE			hnd,			/* マウスハンドラ           */
	int				xmin,			/* ｘ座標最小値             */
	int				xmax,			/* ｘ座標最大値             */
	int				ymin,			/* ｙ座標最小値             */
	int				ymax			/* ｙ座標最大値             */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	mouse->clip.left   = xmin;
	mouse->clip.right  = xmax;
	mouse->clip.top    = ymin;
	mouse->clip.bottom = ymax;
}

/// <summary>
/// マウスカーソルの移動範囲の取得.
/// </summary>
/// <param name="hnd">マウスハンドラ</param>
/// <param name="xmin">X座標最小値</param>
/// <param name="xmax">X座標最大値</param>
/// <param name="ymin">Y座標最小値</param>
/// <param name="ymax">Y座標最大値</param>
void
GMouseGetPhysicalBlock
(
	GMOUSE			hnd,			/* マウスハンドラ           */
	int*			xmin,			/*-> ｘ座標最小値           */
	int*			xmax,			/*-> ｘ座標最大値           */
	int*			ymin,			/*-> ｙ座標最小値           */
	int*			ymax			/*-> ｙ座標最小値           */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	if ( xmin != NULL )
	{
		*xmin = mouse->clip.left;
	}
	if ( xmax != NULL )
	{
		*xmax = mouse->clip.right;
	}
	if ( ymin != NULL )
	{
		*ymin = mouse->clip.top;
	}
	if ( ymax != NULL )
	{
		*ymax = mouse->clip.bottom;
	}
}

/// <summary>
/// マウスのアクセス権の再取得.
/// </summary>
/// <param name="hnd">マウスハンドラ</param>
/// <returns>取得できれば真，取得できなければ偽を返す.</returns>
BOOL
GMouseReacquire
(
	GMOUSE				hnd			/* マウスハンドラ           */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	return	reacquire_mouse_input( mouse );
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInputマウスデバイスの初期化．
*
* Return  : 初期化に成功すれば真，失敗すれば偽を返す．
*
*----------------------------------------------------------------------------*/
static BOOL
init_mouse_input
(
	GINPMOUSE*			mouse,		/* マウスハンドラ           */
	HINSTANCE			hinst,		/* インスタンスハンドラ     */
	HWND				hwnd		/* ウィンドウハンドラ       */
)
{
	LPDIRECTINPUT 			pdi;
	LPDIRECTINPUTDEVICE		ptmp;
	LPDIRECTINPUTDEVICE2	pdev;
	DIDEVICEINSTANCE		di;

	/* マウスデバイスの初期化 */
	mouse->hwnd = hwnd;
	mouse->dinp = NULL;
	mouse->idev = NULL;

	/* DirectInputの生成 */
	if( DirectInputCreate( hinst, DIRECTINPUT_VERSION, &pdi, NULL) != DI_OK )
	{
		OutputDebugString( "DirectInputCreate FAILED\n" );

		return FALSE;
	}

	/* DirectInputマウスデバイスの生成 */
	if( pdi->lpVtbl->CreateDevice( pdi, &GUID_SysMouse,
													   &ptmp, NULL ) != DI_OK )
	{
		OutputDebugString( "CreateDevice FAILED\n" );

		return	FALSE;
	}

	/* 新しいバージョンのDirectInputのマウスの生成 */
	if ( ptmp->lpVtbl->QueryInterface( ptmp, &IID_IDirectInputDevice2,
												   (LPVOID *)&pdev ) != DI_OK )
	{
		OutputDebugString( "CreateDevice2 FAILED\n" );

		ptmp->lpVtbl->Release( ptmp );

		return	FALSE;
	}
	ptmp->lpVtbl->Release( ptmp );

	/* マウスデータフォーマットの設定 */
	if( pdev->lpVtbl->SetDataFormat( pdev, &c_dfDIMouse ) != DI_OK )
	{
		OutputDebugString( "SetDataFormat FAILED\n" );

		pdev->lpVtbl->Release( pdev );

		return	FALSE;
	}

	/* 協調レベルの設定 */
	if( pdev->lpVtbl->SetCooperativeLevel( pdev, mouse->hwnd,
							 DISCL_NONEXCLUSIVE | DISCL_FOREGROUND ) != DI_OK )
	{
		OutputDebugString( "SetCooperativeLevel FAILED\n" );

		pdev->lpVtbl->Release( pdev );

		return	FALSE;
	}

	/* 識別情報の取得 */
	di.dwSize = sizeof( di );
	if ( pdev->lpVtbl->GetDeviceInfo( pdev, &di ) != DI_OK )
	{
		OutputDebugString( "GetDeviceInfo FAILED\n" );

		pdev->lpVtbl->Release( pdev );

		return	FALSE;
	}

	/* アクセス権の取得を行う */
	reacquire_input( pdev );

	/* DirectInputハンドラの保存 */
	mouse->dinp = pdi;
	mouse->idev = pdev;

	/* マウスの状態の初期化 */
	mouse->ox          = 0;
	mouse->oy          = 0;
	mouse->oz          = 0;
	mouse->px          = 0;
	mouse->py          = 0;
	mouse->pz          = 0;
	mouse->newbtn      = 0;
	mouse->oldbtn      = 0;
	mouse->clip.left   = 0;
	mouse->clip.right  = 640 - 1;
	mouse->clip.top    = 0;
	mouse->clip.bottom = 480 - 1;
	mouse->ratio       = 1.0;

	return	TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInputマウスデバイスの終了処理．
*
* Return  : なし．
*
*----------------------------------------------------------------------------*/
static void
cleanup_mouse_input
(
	GINPMOUSE*		mouse			/* マウスハンドラ           */
)
{
	/* DirectInputキーボードデバイスの消滅 */
	if ( mouse->idev != NULL )
	{
		mouse->idev->lpVtbl->Unacquire( mouse->idev );
		mouse->idev->lpVtbl->Release( mouse->idev );
		mouse->idev = NULL;
	}

	/* DirectInputハンドラの消滅 */
	if ( mouse->dinp != NULL )
	{
		mouse->dinp->lpVtbl->Release( mouse->dinp );
		mouse->dinp = NULL;
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInputマウスデータの読み込み．
*
* Return  : なし．
*
*----------------------------------------------------------------------------*/
static void
read_mouse_input
(
	GINPMOUSE*		mouse			/* マウスハンドラ           */
)
{
	LPDIRECTINPUTDEVICE2	idev;
	DIMOUSESTATE			im;
	HRESULT					hres;

	if ( ( idev = mouse->idev ) == NULL )
	{
		return;
	}

	/* 前回の状態を保存   */
	mouse->oldbtn = mouse->newbtn;

	hres = idev->lpVtbl->GetDeviceState( idev, sizeof( im ), &im );
	if( hres == DI_OK )
	{
		/* 移動量の取得 */
		mouse->ox = im.lX;
		mouse->oy = im.lY;
		mouse->oz = im.lZ;

		/* ボタンの状態の取得 */
		mouse->newbtn = 0;
		if ( ( im.rgbButtons[0] & 0x80 ) != 0 )
		{
			mouse->newbtn |= GMOUSE_BUTTON_1;
		}
		if ( ( im.rgbButtons[1] & 0x80 ) != 0 )
		{
			mouse->newbtn |= GMOUSE_BUTTON_2;
		}
		if ( ( im.rgbButtons[2] & 0x80 ) != 0 )
		{
			mouse->newbtn |= GMOUSE_BUTTON_3;
		}
		if ( ( im.rgbButtons[3] & 0x80 ) != 0 )
		{
			mouse->newbtn |= GMOUSE_BUTTON_4;
		}
	}
	else
	{
		/* 読み取りに失敗した場合 */
		mouse->ox     = 0;
		mouse->oy     = 0;
		mouse->oz     = 0;
		mouse->newbtn = 0;

		if ( ( hres == DIERR_INPUTLOST   )
		  || ( hres == DIERR_NOTACQUIRED ) )
		{
			reacquire_input( idev );
		}
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInputマウスデバイスのアクセス権の再取得．
*
* Return  : なし．
*
*----------------------------------------------------------------------------*/
static BOOL
reacquire_mouse_input
(
	GINPMOUSE*		mouse			/* マウスハンドラ           */
)
{
	return	reacquire_input( mouse->idev );
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInputマウスデバイスのアクセス権の再取得．
*
* Return  : なし．
*
*----------------------------------------------------------------------------*/
static void
clip_mouse_cursor
(
	GINPMOUSE*		mouse			/* マウスハンドラ           */
)
{
	/* ｘ座標のクリップ */
	if ( mouse->px < mouse->clip.left )
	{
		mouse->px = (FLOAT)mouse->clip.left;
	}
	else if ( mouse->px > mouse->clip.right )
	{
		mouse->px = (FLOAT)mouse->clip.right;
	}

	/* ｙ座標のクリップ */
	if ( mouse->py < mouse->clip.top )
	{
		mouse->py = (FLOAT)mouse->clip.top;
	}
	else if ( mouse->py > mouse->clip.bottom )
	{
		mouse->py = (FLOAT)mouse->clip.bottom;
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInputデバイスのアクセス権の再取得．
*
* Return  : 取得できれば真，取得できなければ偽を返す．
*
*----------------------------------------------------------------------------*/
static BOOL
reacquire_input
(
	LPDIRECTINPUTDEVICE2	idev	/* DirectInputデバイス      */
)
{
	HRESULT					hres;

	if( idev != NULL )
	{
		/* DirectInputデバイスのアクセス権の取得 */
		hres = idev->lpVtbl->Acquire( idev );

		if( SUCCEEDED( hres ) )
		{
			/* 取得に成功した */
			return	TRUE;
		}
		else
		{
			/* 取得に失敗した */
			return	FALSE;
		}
	}

	/* デバイスが存在しない */
	return	FALSE;
}

/********** End of File ******************************************************/
