/******************************************************************************
* File Name : gsinput.c                            Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       入力デバイスシステム．
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"gsinput.h"

/****** 変数宣言 *************************************************************/

static GINPUT	GInput = NULL;		/* 入力デバイスハンドラ        */

/// <summary>
/// 入力デバイスシステムの初期化.
/// </summary>
/// <param name="hwnd">ウィンドウハンドラ</param>
/// <returns>初期化に成功すれば真，失敗すれば偽を返す</returns>
BOOL
gsInitInput
	(
	HWND			hwnd			/* ウィンドウハンドラ           */
	)
{

	/* 入力デバイスハンドラの生成 */
	if ( GInput == NULL )
	{
		// インスタンスハンドラ.
		HINSTANCE		hinst;

		// アプリケーションのインスタンスハンドラを取得.
		hinst = GetModuleHandle( NULL );
		if ( ( GInput = GInputNew( hinst, hwnd ) ) == NULL )
		{
			return	FALSE;
		}
	}

	return	TRUE;
}

/// <summary>
/// 入力デバイスシステムの終了処理.
/// </summary>
void
	gsFinishInput
	(
	void
	)
{
	/* 入力デバイスハンドラの消滅 */
	if ( GInput != NULL )
	{
		GInputDelete( GInput );
	}

	GInput = NULL;
}

/// <summary>
/// ウィンドウがアクティブになった時の処理.
/// </summary>
/// <param name="active">アクティブフラグ</param>
void
	gsActivateInput
	(
	BOOL		active				/* アクティブフラグ             */
	)
{
	if ( GInput == NULL )
	{
		return;
	}

	GInputActivateApp( GInput, active );
}

/// <summary>
/// 入力デバイスの状態を読み込む.
/// </summary>
void
	gsReadInput
	(
	void
	)
{
	GInputReadDevice( GInput );
}

/// <summary>
/// キーの入力状態を調べる.
/// </summary>
/// <param name="key_code">キーコード</param>
/// <returns>キーが押されていれば真，押されていなければ偽を返す</returns>
BOOL
	gsGetKeyState
	(
	GKEYCODE		key_code		/* キーコード                   */
	)
{
	GKEYINP			key;

	if ( ( key = GInputGetKeyborad( GInput ) ) == NULL )
	{
		return	FALSE;
	}

	return	GKeyInpGetState( key, key_code );
}

/// <summary>
/// キーが押されたか調べる.
/// </summary>
/// <param name="key_code">キーコード</param>
/// <returns>キーが押されていれば真，押されていなければ偽を返す</returns>
BOOL
	gsGetKeyTrigger
	(
	GKEYCODE		key_code		/* キーコード                   */
	)
{
	GKEYINP			key;

	if ( ( key = GInputGetKeyborad( GInput ) ) == NULL )
	{
		return	FALSE;
	}

	return	GKeyInpGetTrigger( key, key_code );
}

/// <summary>
/// キーが離されたか調べる.
/// </summary>
/// <param name="key_code">キーコード</param>
/// <returns>キーが離されれば真，離されていなければ偽を返す</returns>
BOOL
	gsGetKeyDetach
	(
	GKEYCODE		key_code		/* キーコード                   */
	)
{
	GKEYINP			key;

	if ( ( key = GInputGetKeyborad( GInput ) ) == NULL )
	{
		return	FALSE;
	}

	return	GKeyInpGetDetach( key, key_code );
}

/// <summary>
/// キーボードの押されているキーを調べる.
/// </summary>
/// <returns>押されているキーのキーコードを返す.
/// <para>何も押されていなければ０を返す</para>
/// </returns>
GKEYCODE
	gsGetKey
	(
	void
	)
{
	GKEYINP			key;

	if ( ( key = GInputGetKeyborad( GInput ) ) == NULL )
	{
		return	0;
	}

	return	GKeyInpGetKey( key );
}

/// <summary>
/// 接続されているジョイスティック数を調べる.
/// </summary>
/// <returns>接続されているジョイスティック数を返す.</returns>
int
	gsGetJoyCount
	(
	void
	)
{
	GJOYINP			joy;

	if ( ( joy = GInputGetJoystick( GInput ) ) == NULL )
	{
		return	0;
	}

	return	GJoyInpGetCount( joy );
}

/// <summary>
/// ジョイスティックの入力状態を調べる.
/// </summary>
/// <param name="joy_no">ジョイスティックナンバ</param>
/// <param name="state">調べたいジョイステックの状態</param>
/// <returns>押されていれば真，押されていなければ偽を返す.</returns>
BOOL
	gsGetJoyState
	(
	int				joy_no,			/* ジョイスティックナンバ       */
	GJOYSTATE		state			/* 調べたいジョイステックの状態 */
	)
{
	GJOYINP			joy;

	if ( ( joy = GInputGetJoystick( GInput ) ) == NULL )
	{
		return	0;
	}

	return	GJoyInpGetState( joy, joy_no, state );
}

/// <summary>
/// ジョイスティックが押されたか調べる.
/// </summary>
/// <param name="joy_no">ジョイスティックナンバ</param>
/// <param name="state">調べたいジョイステックの状態</param>
/// <returns>押されたら真，押されなければ偽を返す.</returns>
BOOL
	gsGetJoyTrigger
	(
	int				joy_no,			/* ジョイスティックナンバ       */
	GJOYSTATE		state			/* 調べたいジョイステックの状態 */
	)
{
	GJOYINP			joy;

	if ( ( joy = GInputGetJoystick( GInput ) ) == NULL )
	{
		return	0;
	}

	return	GJoyInpGetTrigger( joy, joy_no, state );
}

/// <summary>
/// ジョイスティックが離されたか調べる.
/// </summary>
/// <param name="joy_no">ジョイスティックナンバ</param>
/// <param name="state">調べたいジョイステックの状態</param>
/// <returns>離されたら真，離されなければ偽を返す.</returns>
BOOL
	gsGetJoyDetach
	(
	int				joy_no,			/* ジョイスティックナンバ       */
	GJOYSTATE		state			/* 調べたいジョイステックの状態 */
	)
{
	GJOYINP			joy;

	if ( ( joy = GInputGetJoystick( GInput ) ) == NULL )
	{
		return	0;
	}

	return	GJoyInpGetDetach( joy, joy_no, state );
}

/// <summary>
/// ジョイスティックの軸の状態を調べる.
/// </summary>
/// <param name="joy_no">ジョイスティックナンバ</param>
/// <param name="x">ジョイステッィクのX軸の状態</param>
/// <param name="y">ジョイステッィクのY軸の状態</param>
/// <param name="z">ジョイステッィクのZ軸の状態</param>
void
	gsGetJoyAxis
	(
	int				joy_no,			/* ジョイスティックナンバ           */
	int*			x,				/*-> ジョイステッィクのｘ軸の状態   */
	int*			y,				/*-> ジョイステッィクのｙ軸の状態   */
	int*			z				/*-> ジョイステッィクのｚ軸の状態   */
	)
{
	GJOYINP			joy;
	int				wx;
	int				wy;
	int				wz;

	if ( ( joy = GInputGetJoystick( GInput ) ) == NULL )
	{
		wx = 0;
		wy = 0;
		wz = 0;
	}
	else
	{
		/* ジョイステックの軸の状態を読み込む */
		GJoyInpGetAxis( joy, joy_no, &wx, &wy, &wz );
	}

	if ( x != NULL )
	{
		*x = wx;
	}
	if ( y != NULL )
	{
		*y = wy;
	}
	if ( z != NULL )
	{
		*z = wz;
	}
}

/// <summary>
/// マウスの移動量を取得.
/// </summary>
/// <param name="x">X方向移動量</param>
/// <param name="x">Y方向移動量</param>
/// <param name="x">Z方向移動量</param>
void
	gsGetMouseOffsetPosition
	(
	int*			x,				/*-> ｘ方向移動量               */
	int*			y,				/*-> ｙ方向移動量               */
	int*			z				/*-> ｚ方向移動量               */
	)
{
	GMOUSE			mou;

	if ( ( mou = GInputGetMouse( GInput ) ) == NULL )
	{
		*x = 0;
		*y = 0;
		*z = 0;

		return;
	}

	GMouseGetOffsetPosition( mou, x, y, z );
}

/// <summary>
/// マウスカーソルの位置を取得.
/// </summary>
/// <param name="x">X座標</param>
/// <param name="y">Y座標</param>
void
	gsGetMouseCursorPosition
	(
	int*			x,				/*-> ｘ座標                     */
	int*			y				/*-> ｙ座標                     */
	)
{
	GMOUSE			mou;

	if ( ( mou = GInputGetMouse( GInput ) ) == NULL )
	{
		*x = 0;
		*y = 0;

		return;
	}

	GMouseGetCursorPosition( mou, x, y );
}

/// <summary>
/// マウスのボタンの押下状態を取得.
/// </summary>
/// <param name="state">調べたいマウスのボタン</param>
/// <returns>マウスのボタンの離された状態を返す.</returns>
BOOL
	gsGetMouseButtonState
	(
	GMOUSTATE		state			/* 調べたいマウスのボタン       */
	)
{
	GMOUSE			mou;

	if ( ( mou = GInputGetMouse( GInput ) ) == NULL )
	{
		return	0;
	}

	return	GMouseGetButtonState( mou, state );
}

/// <summary>
/// マウスのボタンが押されたか調べる.
/// </summary>
/// <param name="state">調べたいマウスのボタン</param>
/// <returns>マウスのボタンの離された状態を返す.</returns>
BOOL
	gsGetMouseButtonTrigger
	(
	GMOUSTATE		state			/* 調べたいマウスのボタン       */
	)
{
	GMOUSE			mou;

	if ( ( mou = GInputGetMouse( GInput ) ) == NULL )
	{
		return	0;
	}

	return	GMouseGetButtonTrigger( mou, state );
}

/// <summary>
/// マウスのボタンが離されたか調べる.
/// </summary>
/// <param name="state">調べたいマウスのボタン</param>
/// <returns>マウスのボタンの離された状態を返す.</returns>
BOOL
	gsGetMouseButtonDetach
	(
	GMOUSTATE		state			/* 調べたいマウスのボタン       */
	)
{
	GMOUSE			mou;

	if ( ( mou = GInputGetMouse( GInput ) ) == NULL )
	{
		return	0;
	}

	return	GMouseGetButtonDetach( mou, state );
}

/// <summary>
/// マウスカーソルの移動比率の設定.
/// </summary>
/// <param name="ratio">移動比率</param>
void
	gsSetMouseMoveRatio
	(
	FLOAT			ratio			/* 移動比率                     */
	)
{
	GMOUSE			mou;

	if ( ( mou = GInputGetMouse( GInput ) ) == NULL )
	{
		return;
	}

	GMouseSetMoveRatio( mou, ratio );
}

/// <summary>
/// マウスカーソルの位置を設定.
/// </summary>
/// <param name="x">X座標</param>
/// <param name="y">X座標</param>
void
	gsSetMouseCursorPosition
	(
	int				x,				/* ｘ座標                       */
	int				y				/* ｙ座標                       */
	)
{
	GMOUSE			mou;

	if ( ( mou = GInputGetMouse( GInput ) ) == NULL )
	{
		return;
	}

	GMouseSetCursorPosition( mou, x, y );
}

/// <summary>
/// マウスカーソルの移動範囲を設定.
/// </summary>
/// <param name="xmin">X座標最小値</param>
/// <param name="xmax">X座標最大値</param>
/// <param name="ymin">Y座標最小値</param>
/// <param name="ymax">Y座標最大値</param>
void
	gsSetMousePhysicalBlock
	(
	int				xmin,			/* ｘ座標最小値                 */
	int				xmax,			/* ｘ座標最大値                 */
	int				ymin,			/* ｙ座標最小値                 */
	int				ymax			/* ｙ座標最大値                 */
	)
{
	GMOUSE			mou;

	if ( ( mou = GInputGetMouse( GInput ) ) == NULL )
	{
		return;
	}

	GMouseSetPhysicalBlock( mou, xmin, xmax, ymin, ymax );
}

/********** End of File ******************************************************/
