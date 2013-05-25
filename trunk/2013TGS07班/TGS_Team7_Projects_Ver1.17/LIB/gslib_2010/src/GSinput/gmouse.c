/******************************************************************************
* File Name : gmouse.c                             Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       �Q�[���V�X�e���p �}�E�X����.
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"gmouse.h"
#include	"heap.h"
#define		DIRECTINPUT_VERSION		0x0700
#include	<dinput.h>

/****** �f�[�^�^�錾 *********************************************************/

/*----- �}�E�X���͍\���� ----------------------------------------------------*/

typedef	struct
{
	HINSTANCE            hinst;		/* �C���X�^���X�n���h��         */
	HWND                 hwnd;		/* �E�B���h�E�n���h��           */
	LPDIRECTINPUT        dinp;		/* DirectInput�n���h��          */
	LPDIRECTINPUTDEVICE2 idev;		/* �L�[�{�[�h�f�o�C�X           */
	int                  ox;		/* �O�񂩂�̂������ړ���       */
	int                  oy;		/* �O�񂩂�̂������ړ���       */
	int                  oz;		/* �O�񂩂�̂������ړ���       */
	FLOAT                px;		/* �}�E�X�J�[�\�������W         */
	FLOAT                py;		/* �}�E�X�J�[�\�������W         */
	FLOAT                pz;		/* �}�E�X�J�[�\�������W         */
	GMOUSTATE            newbtn;	/* ���݂̃}�E�X�̃{�^���̏��   */
	GMOUSTATE            oldbtn;	/* �O��̃}�E�X�̃{�^���̏��   */
	RECT                 clip;		/* �}�E�X�J�[�\���̈ړ��͈�     */
	FLOAT                ratio;		/* �}�E�X�J�[�\���̈ړ��䗦     */

} GINPMOUSE;

/****** �֐��v���g�^�C�v�錾 *************************************************/

static BOOL	init_mouse_input( GINPMOUSE*, HINSTANCE, HWND );
static void	cleanup_mouse_input( GINPMOUSE* );
static void	read_mouse_input( GINPMOUSE* );
static BOOL	reacquire_mouse_input( GINPMOUSE* );
static void	clip_mouse_cursor( GINPMOUSE* );
static BOOL	reacquire_input( LPDIRECTINPUTDEVICE2 );

/// <summary>
/// �}�E�X�̐���.
/// </summary>
/// <param name="hinst">�C���X�^���X�n���h��</param>
/// <param name="hwnd">�E�B���h�E�n���h��</param>
/// <returns>�}�E�X�n���h����Ԃ�.</returns>
GMOUSE
GMouseNew
(
	HINSTANCE		hinst,			/* �C���X�^���X�n���h��     */
	HWND			hwnd			/* �E�B���h�E�n���h��       */
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
/// �}�E�X�̏���.
/// </summary>
/// <param name="hnd">�}�E�X�n���h��</param>
void
GMouseDelete
(
	GMOUSE			hnd				/* �}�E�X�n���h��           */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	cleanup_mouse_input( mouse );

	del_object( mouse );
}

/// <summary>
/// �}�E�X�̓ǂݍ���.
/// </summary>
/// <param name="hnd">�}�E�X�n���h��</param>
void
GMouseReadDevice
(
	GMOUSE			hnd				/* �}�E�X�n���h��           */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	/* �}�E�X�̏�Ԃ̓ǂݍ��� */
	read_mouse_input( mouse );

	/* �ړ��ʂ̉��Z */
	mouse->px += ( mouse->ox * mouse->ratio );
	mouse->py += ( mouse->oy * mouse->ratio );
	mouse->pz += ( mouse->oz * mouse->ratio );

	/* �}�E�X�ʒu�̃N���b�s���O */
	clip_mouse_cursor( mouse );
}

/// <summary>
/// �}�E�X�̈ړ��ʂ��擾.
/// </summary>
/// <param name="hnd">�}�E�X�n���h��</param>
/// <param name="x">X�����ړ���</param>
/// <param name="y">Y�����ړ���</param>
/// <param name="z">Z�����ړ���</param>
void
GMouseGetOffsetPosition
(
	GMOUSE			hnd,			/* �}�E�X�n���h��           */
	int*			x,				/*-> �������ړ���           */
	int*			y,				/*-> �������ړ���           */
	int*			z				/*-> �������ړ���           */
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
/// �}�E�X�J�[�\���̈ʒu���擾.
/// </summary>
/// <param name="hnd">�}�E�X�n���h��</param>
/// <param name="x">X���W</param>
/// <param name="y">Y���W</param>
void
GMouseGetCursorPosition
(
	GMOUSE			hnd,			/* �}�E�X�n���h��           */
	int*			x,				/*-> �����W                 */
	int*			y				/*-> �����W                 */
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
/// �}�E�X�̃{�^���̉�����Ԃ��擾.
/// </summary>
/// <param name="hnd">�}�E�X�n���h��</param>
/// <param name="state">���ׂ����}�E�X�̃{�^��</param>
/// <returns>������Ă���ΐ^�C������Ă�����΋U��Ԃ�.</returns>
BOOL
GMouseGetButtonState
(
	GMOUSE			hnd,			/* �}�E�X�n���h��           */
	GMOUSTATE		state			/* ���ׂ����}�E�X�̃{�^��   */
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
/// �}�E�X�̃{�^���̉����ꂽ�����ׂ�.
/// </summary>
/// <param name="hnd">�}�E�X�n���h��</param>
/// <param name="state">���ׂ����}�E�X�̃{�^��</param>
/// <returns>������Ă���ΐ^�C������Ă�����΋U��Ԃ�.</returns>
BOOL
GMouseGetButtonTrigger
(
	GMOUSE			hnd,			/* �}�E�X�n���h��           */
	GMOUSTATE		state			/* ���ׂ����}�E�X�̃{�^��   */
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
/// �}�E�X�̃{�^���������ꂽ�����ׂ�.
/// </summary>
/// <param name="hnd">�}�E�X�n���h��</param>
/// <param name="state">���ׂ����}�E�X�̃{�^��</param>
/// <returns>������Ă���ΐ^�C������Ă�����΋U��Ԃ�.</returns>
BOOL
GMouseGetButtonDetach
(
	GMOUSE			hnd,			/* �}�E�X�n���h��           */
	GMOUSTATE		state			/* ���ׂ����}�E�X�̃{�^��   */
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
/// �}�E�X�J�[�\���̈ړ��䗦�̎擾.
/// </summary>
/// <param name="hnd">�}�E�X�n���h��</param>
/// <returns>�ړ��䗦.</returns>
FLOAT
GMouseGetMoveRatio
(
	GMOUSE			hnd				/* �}�E�X�n���h��           */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	return	mouse->ratio;
}

/// <summary>
/// �}�E�X�J�[�\���̈ړ��䗦�̐ݒ�.
/// </summary>
/// <param name="hnd">�}�E�X�n���h��</param>
/// <param name="hnd">�ړ��䗦</param>
void
GMouseSetMoveRatio
(
	GMOUSE			hnd,			/* �}�E�X�n���h��           */
	FLOAT			ratio			/* �ړ��䗦                 */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	mouse->ratio = ratio;
}

/// <summary>
/// �}�E�X�J�[�\���̈ʒu��ݒ�.
/// </summary>
/// <param name="hnd">�}�E�X�n���h��</param>
/// <param name="x">X���W</param>
/// <param name="y">Y���W</param>
void
GMouseSetCursorPosition
(
	GMOUSE			hnd,			/* �}�E�X�n���h��           */
	int				x,				/* �����W                   */
	int				y				/* �����W                   */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	/* �}�E�X�J�[�\���̈ʒu��ݒ� */
	mouse->px = (FLOAT)x;
	mouse->py = (FLOAT)y;

	/* �}�E�X�ʒu�̃N���b�s���O */
	clip_mouse_cursor( mouse );
}

/// <summary>
/// �}�E�X�J�[�\���̈ړ��͈͂�ݒ�.
/// </summary>
/// <param name="hnd">�}�E�X�n���h��</param>
/// <param name="xmin">X���W�ŏ��l</param>
/// <param name="xmax">X���W�ő�l</param>
/// <param name="ymin">Y���W�ŏ��l</param>
/// <param name="ymax">Y���W�ő�l</param>
void
GMouseSetPhysicalBlock
(
	GMOUSE			hnd,			/* �}�E�X�n���h��           */
	int				xmin,			/* �����W�ŏ��l             */
	int				xmax,			/* �����W�ő�l             */
	int				ymin,			/* �����W�ŏ��l             */
	int				ymax			/* �����W�ő�l             */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	mouse->clip.left   = xmin;
	mouse->clip.right  = xmax;
	mouse->clip.top    = ymin;
	mouse->clip.bottom = ymax;
}

/// <summary>
/// �}�E�X�J�[�\���̈ړ��͈͂̎擾.
/// </summary>
/// <param name="hnd">�}�E�X�n���h��</param>
/// <param name="xmin">X���W�ŏ��l</param>
/// <param name="xmax">X���W�ő�l</param>
/// <param name="ymin">Y���W�ŏ��l</param>
/// <param name="ymax">Y���W�ő�l</param>
void
GMouseGetPhysicalBlock
(
	GMOUSE			hnd,			/* �}�E�X�n���h��           */
	int*			xmin,			/*-> �����W�ŏ��l           */
	int*			xmax,			/*-> �����W�ő�l           */
	int*			ymin,			/*-> �����W�ŏ��l           */
	int*			ymax			/*-> �����W�ŏ��l           */
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
/// �}�E�X�̃A�N�Z�X���̍Ď擾.
/// </summary>
/// <param name="hnd">�}�E�X�n���h��</param>
/// <returns>�擾�ł���ΐ^�C�擾�ł��Ȃ���΋U��Ԃ�.</returns>
BOOL
GMouseReacquire
(
	GMOUSE				hnd			/* �}�E�X�n���h��           */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	return	reacquire_mouse_input( mouse );
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�}�E�X�f�o�C�X�̏������D
*
* Return  : �������ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
init_mouse_input
(
	GINPMOUSE*			mouse,		/* �}�E�X�n���h��           */
	HINSTANCE			hinst,		/* �C���X�^���X�n���h��     */
	HWND				hwnd		/* �E�B���h�E�n���h��       */
)
{
	LPDIRECTINPUT 			pdi;
	LPDIRECTINPUTDEVICE		ptmp;
	LPDIRECTINPUTDEVICE2	pdev;
	DIDEVICEINSTANCE		di;

	/* �}�E�X�f�o�C�X�̏����� */
	mouse->hwnd = hwnd;
	mouse->dinp = NULL;
	mouse->idev = NULL;

	/* DirectInput�̐��� */
	if( DirectInputCreate( hinst, DIRECTINPUT_VERSION, &pdi, NULL) != DI_OK )
	{
		OutputDebugString( "DirectInputCreate FAILED\n" );

		return FALSE;
	}

	/* DirectInput�}�E�X�f�o�C�X�̐��� */
	if( pdi->lpVtbl->CreateDevice( pdi, &GUID_SysMouse,
													   &ptmp, NULL ) != DI_OK )
	{
		OutputDebugString( "CreateDevice FAILED\n" );

		return	FALSE;
	}

	/* �V�����o�[�W������DirectInput�̃}�E�X�̐��� */
	if ( ptmp->lpVtbl->QueryInterface( ptmp, &IID_IDirectInputDevice2,
												   (LPVOID *)&pdev ) != DI_OK )
	{
		OutputDebugString( "CreateDevice2 FAILED\n" );

		ptmp->lpVtbl->Release( ptmp );

		return	FALSE;
	}
	ptmp->lpVtbl->Release( ptmp );

	/* �}�E�X�f�[�^�t�H�[�}�b�g�̐ݒ� */
	if( pdev->lpVtbl->SetDataFormat( pdev, &c_dfDIMouse ) != DI_OK )
	{
		OutputDebugString( "SetDataFormat FAILED\n" );

		pdev->lpVtbl->Release( pdev );

		return	FALSE;
	}

	/* �������x���̐ݒ� */
	if( pdev->lpVtbl->SetCooperativeLevel( pdev, mouse->hwnd,
							 DISCL_NONEXCLUSIVE | DISCL_FOREGROUND ) != DI_OK )
	{
		OutputDebugString( "SetCooperativeLevel FAILED\n" );

		pdev->lpVtbl->Release( pdev );

		return	FALSE;
	}

	/* ���ʏ��̎擾 */
	di.dwSize = sizeof( di );
	if ( pdev->lpVtbl->GetDeviceInfo( pdev, &di ) != DI_OK )
	{
		OutputDebugString( "GetDeviceInfo FAILED\n" );

		pdev->lpVtbl->Release( pdev );

		return	FALSE;
	}

	/* �A�N�Z�X���̎擾���s�� */
	reacquire_input( pdev );

	/* DirectInput�n���h���̕ۑ� */
	mouse->dinp = pdi;
	mouse->idev = pdev;

	/* �}�E�X�̏�Ԃ̏����� */
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
* Purpose : DirectInput�}�E�X�f�o�C�X�̏I�������D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
cleanup_mouse_input
(
	GINPMOUSE*		mouse			/* �}�E�X�n���h��           */
)
{
	/* DirectInput�L�[�{�[�h�f�o�C�X�̏��� */
	if ( mouse->idev != NULL )
	{
		mouse->idev->lpVtbl->Unacquire( mouse->idev );
		mouse->idev->lpVtbl->Release( mouse->idev );
		mouse->idev = NULL;
	}

	/* DirectInput�n���h���̏��� */
	if ( mouse->dinp != NULL )
	{
		mouse->dinp->lpVtbl->Release( mouse->dinp );
		mouse->dinp = NULL;
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�}�E�X�f�[�^�̓ǂݍ��݁D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
read_mouse_input
(
	GINPMOUSE*		mouse			/* �}�E�X�n���h��           */
)
{
	LPDIRECTINPUTDEVICE2	idev;
	DIMOUSESTATE			im;
	HRESULT					hres;

	if ( ( idev = mouse->idev ) == NULL )
	{
		return;
	}

	/* �O��̏�Ԃ�ۑ�   */
	mouse->oldbtn = mouse->newbtn;

	hres = idev->lpVtbl->GetDeviceState( idev, sizeof( im ), &im );
	if( hres == DI_OK )
	{
		/* �ړ��ʂ̎擾 */
		mouse->ox = im.lX;
		mouse->oy = im.lY;
		mouse->oz = im.lZ;

		/* �{�^���̏�Ԃ̎擾 */
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
		/* �ǂݎ��Ɏ��s�����ꍇ */
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
* Purpose : DirectInput�}�E�X�f�o�C�X�̃A�N�Z�X���̍Ď擾�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
reacquire_mouse_input
(
	GINPMOUSE*		mouse			/* �}�E�X�n���h��           */
)
{
	return	reacquire_input( mouse->idev );
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�}�E�X�f�o�C�X�̃A�N�Z�X���̍Ď擾�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
clip_mouse_cursor
(
	GINPMOUSE*		mouse			/* �}�E�X�n���h��           */
)
{
	/* �����W�̃N���b�v */
	if ( mouse->px < mouse->clip.left )
	{
		mouse->px = (FLOAT)mouse->clip.left;
	}
	else if ( mouse->px > mouse->clip.right )
	{
		mouse->px = (FLOAT)mouse->clip.right;
	}

	/* �����W�̃N���b�v */
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
* Purpose : DirectInput�f�o�C�X�̃A�N�Z�X���̍Ď擾�D
*
* Return  : �擾�ł���ΐ^�C�擾�ł��Ȃ���΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
reacquire_input
(
	LPDIRECTINPUTDEVICE2	idev	/* DirectInput�f�o�C�X      */
)
{
	HRESULT					hres;

	if( idev != NULL )
	{
		/* DirectInput�f�o�C�X�̃A�N�Z�X���̎擾 */
		hres = idev->lpVtbl->Acquire( idev );

		if( SUCCEEDED( hres ) )
		{
			/* �擾�ɐ������� */
			return	TRUE;
		}
		else
		{
			/* �擾�Ɏ��s���� */
			return	FALSE;
		}
	}

	/* �f�o�C�X�����݂��Ȃ� */
	return	FALSE;
}

/********** End of File ******************************************************/
