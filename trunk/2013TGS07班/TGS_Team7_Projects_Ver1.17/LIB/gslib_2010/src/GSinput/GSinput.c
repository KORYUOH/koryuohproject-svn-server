/******************************************************************************
* File Name : gsinput.c                            Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       ���̓f�o�C�X�V�X�e���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"gsinput.h"

/****** �ϐ��錾 *************************************************************/

static GINPUT	GInput = NULL;		/* ���̓f�o�C�X�n���h��        */

/// <summary>
/// ���̓f�o�C�X�V�X�e���̏�����.
/// </summary>
/// <param name="hwnd">�E�B���h�E�n���h��</param>
/// <returns>�������ɐ�������ΐ^�C���s����΋U��Ԃ�</returns>
BOOL
gsInitInput
	(
	HWND			hwnd			/* �E�B���h�E�n���h��           */
	)
{

	/* ���̓f�o�C�X�n���h���̐��� */
	if ( GInput == NULL )
	{
		// �C���X�^���X�n���h��.
		HINSTANCE		hinst;

		// �A�v���P�[�V�����̃C���X�^���X�n���h�����擾.
		hinst = GetModuleHandle( NULL );
		if ( ( GInput = GInputNew( hinst, hwnd ) ) == NULL )
		{
			return	FALSE;
		}
	}

	return	TRUE;
}

/// <summary>
/// ���̓f�o�C�X�V�X�e���̏I������.
/// </summary>
void
	gsFinishInput
	(
	void
	)
{
	/* ���̓f�o�C�X�n���h���̏��� */
	if ( GInput != NULL )
	{
		GInputDelete( GInput );
	}

	GInput = NULL;
}

/// <summary>
/// �E�B���h�E���A�N�e�B�u�ɂȂ������̏���.
/// </summary>
/// <param name="active">�A�N�e�B�u�t���O</param>
void
	gsActivateInput
	(
	BOOL		active				/* �A�N�e�B�u�t���O             */
	)
{
	if ( GInput == NULL )
	{
		return;
	}

	GInputActivateApp( GInput, active );
}

/// <summary>
/// ���̓f�o�C�X�̏�Ԃ�ǂݍ���.
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
/// �L�[�̓��͏�Ԃ𒲂ׂ�.
/// </summary>
/// <param name="key_code">�L�[�R�[�h</param>
/// <returns>�L�[��������Ă���ΐ^�C������Ă��Ȃ���΋U��Ԃ�</returns>
BOOL
	gsGetKeyState
	(
	GKEYCODE		key_code		/* �L�[�R�[�h                   */
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
/// �L�[�������ꂽ�����ׂ�.
/// </summary>
/// <param name="key_code">�L�[�R�[�h</param>
/// <returns>�L�[��������Ă���ΐ^�C������Ă��Ȃ���΋U��Ԃ�</returns>
BOOL
	gsGetKeyTrigger
	(
	GKEYCODE		key_code		/* �L�[�R�[�h                   */
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
/// �L�[�������ꂽ�����ׂ�.
/// </summary>
/// <param name="key_code">�L�[�R�[�h</param>
/// <returns>�L�[���������ΐ^�C������Ă��Ȃ���΋U��Ԃ�</returns>
BOOL
	gsGetKeyDetach
	(
	GKEYCODE		key_code		/* �L�[�R�[�h                   */
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
/// �L�[�{�[�h�̉�����Ă���L�[�𒲂ׂ�.
/// </summary>
/// <returns>������Ă���L�[�̃L�[�R�[�h��Ԃ�.
/// <para>����������Ă��Ȃ���΂O��Ԃ�</para>
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
/// �ڑ�����Ă���W���C�X�e�B�b�N���𒲂ׂ�.
/// </summary>
/// <returns>�ڑ�����Ă���W���C�X�e�B�b�N����Ԃ�.</returns>
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
/// �W���C�X�e�B�b�N�̓��͏�Ԃ𒲂ׂ�.
/// </summary>
/// <param name="joy_no">�W���C�X�e�B�b�N�i���o</param>
/// <param name="state">���ׂ����W���C�X�e�b�N�̏��</param>
/// <returns>������Ă���ΐ^�C������Ă��Ȃ���΋U��Ԃ�.</returns>
BOOL
	gsGetJoyState
	(
	int				joy_no,			/* �W���C�X�e�B�b�N�i���o       */
	GJOYSTATE		state			/* ���ׂ����W���C�X�e�b�N�̏�� */
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
/// �W���C�X�e�B�b�N�������ꂽ�����ׂ�.
/// </summary>
/// <param name="joy_no">�W���C�X�e�B�b�N�i���o</param>
/// <param name="state">���ׂ����W���C�X�e�b�N�̏��</param>
/// <returns>�����ꂽ��^�C������Ȃ���΋U��Ԃ�.</returns>
BOOL
	gsGetJoyTrigger
	(
	int				joy_no,			/* �W���C�X�e�B�b�N�i���o       */
	GJOYSTATE		state			/* ���ׂ����W���C�X�e�b�N�̏�� */
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
/// �W���C�X�e�B�b�N�������ꂽ�����ׂ�.
/// </summary>
/// <param name="joy_no">�W���C�X�e�B�b�N�i���o</param>
/// <param name="state">���ׂ����W���C�X�e�b�N�̏��</param>
/// <returns>�����ꂽ��^�C������Ȃ���΋U��Ԃ�.</returns>
BOOL
	gsGetJoyDetach
	(
	int				joy_no,			/* �W���C�X�e�B�b�N�i���o       */
	GJOYSTATE		state			/* ���ׂ����W���C�X�e�b�N�̏�� */
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
/// �W���C�X�e�B�b�N�̎��̏�Ԃ𒲂ׂ�.
/// </summary>
/// <param name="joy_no">�W���C�X�e�B�b�N�i���o</param>
/// <param name="x">�W���C�X�e�b�B�N��X���̏��</param>
/// <param name="y">�W���C�X�e�b�B�N��Y���̏��</param>
/// <param name="z">�W���C�X�e�b�B�N��Z���̏��</param>
void
	gsGetJoyAxis
	(
	int				joy_no,			/* �W���C�X�e�B�b�N�i���o           */
	int*			x,				/*-> �W���C�X�e�b�B�N�̂����̏��   */
	int*			y,				/*-> �W���C�X�e�b�B�N�̂����̏��   */
	int*			z				/*-> �W���C�X�e�b�B�N�̂����̏��   */
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
		/* �W���C�X�e�b�N�̎��̏�Ԃ�ǂݍ��� */
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
/// �}�E�X�̈ړ��ʂ��擾.
/// </summary>
/// <param name="x">X�����ړ���</param>
/// <param name="x">Y�����ړ���</param>
/// <param name="x">Z�����ړ���</param>
void
	gsGetMouseOffsetPosition
	(
	int*			x,				/*-> �������ړ���               */
	int*			y,				/*-> �������ړ���               */
	int*			z				/*-> �������ړ���               */
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
/// �}�E�X�J�[�\���̈ʒu���擾.
/// </summary>
/// <param name="x">X���W</param>
/// <param name="y">Y���W</param>
void
	gsGetMouseCursorPosition
	(
	int*			x,				/*-> �����W                     */
	int*			y				/*-> �����W                     */
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
/// �}�E�X�̃{�^���̉�����Ԃ��擾.
/// </summary>
/// <param name="state">���ׂ����}�E�X�̃{�^��</param>
/// <returns>�}�E�X�̃{�^���̗����ꂽ��Ԃ�Ԃ�.</returns>
BOOL
	gsGetMouseButtonState
	(
	GMOUSTATE		state			/* ���ׂ����}�E�X�̃{�^��       */
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
/// �}�E�X�̃{�^���������ꂽ�����ׂ�.
/// </summary>
/// <param name="state">���ׂ����}�E�X�̃{�^��</param>
/// <returns>�}�E�X�̃{�^���̗����ꂽ��Ԃ�Ԃ�.</returns>
BOOL
	gsGetMouseButtonTrigger
	(
	GMOUSTATE		state			/* ���ׂ����}�E�X�̃{�^��       */
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
/// �}�E�X�̃{�^���������ꂽ�����ׂ�.
/// </summary>
/// <param name="state">���ׂ����}�E�X�̃{�^��</param>
/// <returns>�}�E�X�̃{�^���̗����ꂽ��Ԃ�Ԃ�.</returns>
BOOL
	gsGetMouseButtonDetach
	(
	GMOUSTATE		state			/* ���ׂ����}�E�X�̃{�^��       */
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
/// �}�E�X�J�[�\���̈ړ��䗦�̐ݒ�.
/// </summary>
/// <param name="ratio">�ړ��䗦</param>
void
	gsSetMouseMoveRatio
	(
	FLOAT			ratio			/* �ړ��䗦                     */
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
/// �}�E�X�J�[�\���̈ʒu��ݒ�.
/// </summary>
/// <param name="x">X���W</param>
/// <param name="y">X���W</param>
void
	gsSetMouseCursorPosition
	(
	int				x,				/* �����W                       */
	int				y				/* �����W                       */
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
/// �}�E�X�J�[�\���̈ړ��͈͂�ݒ�.
/// </summary>
/// <param name="xmin">X���W�ŏ��l</param>
/// <param name="xmax">X���W�ő�l</param>
/// <param name="ymin">Y���W�ŏ��l</param>
/// <param name="ymax">Y���W�ő�l</param>
void
	gsSetMousePhysicalBlock
	(
	int				xmin,			/* �����W�ŏ��l                 */
	int				xmax,			/* �����W�ő�l                 */
	int				ymin,			/* �����W�ŏ��l                 */
	int				ymax			/* �����W�ő�l                 */
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
