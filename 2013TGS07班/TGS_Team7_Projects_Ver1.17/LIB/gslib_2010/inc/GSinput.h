/******************************************************************************
* File Name : gsinput.h                            Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       ���̓f�o�C�X�V�X�e�� �w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSINPUT_H_
#define		_GSINPUT_H_

#include	"ginput.h"

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/// <summary>
/// ���̓f�o�C�X�V�X�e���̏�����.
/// </summary>
/// <param name="hwnd">�E�B���h�E�n���h��</param>
/// <returns>�������ɐ�������ΐ^�C���s����΋U��Ԃ�</returns>
BOOL
gsInitInput
(
	HWND			hwnd			/* �E�B���h�E�n���h��           */
);

/// <summary>
/// ���̓f�o�C�X�V�X�e���̏I������.
/// </summary>
void
gsFinishInput
(
	void
);

/// <summary>
/// �E�B���h�E���A�N�e�B�u�ɂȂ������̏���.
/// </summary>
/// <param name="active">�A�N�e�B�u�t���O</param>
void
gsActivateInput
(
	BOOL		active				/* �A�N�e�B�u�t���O             */
);

/// <summary>
/// ���̓f�o�C�X�̏�Ԃ�ǂݍ���.
/// </summary>
void
gsReadInput
(
	void
);

/// <summary>
/// �L�[�̓��͏�Ԃ𒲂ׂ�.
/// </summary>
/// <param name="key_code">�L�[�R�[�h</param>
/// <returns>�L�[��������Ă���ΐ^�C������Ă��Ȃ���΋U��Ԃ�</returns>
BOOL
gsGetKeyState
(
	GKEYCODE		key_code		/* �L�[�R�[�h                   */
);

/// <summary>
/// �L�[�������ꂽ�����ׂ�.
/// </summary>
/// <param name="key_code">�L�[�R�[�h</param>
/// <returns>�L�[��������Ă���ΐ^�C������Ă��Ȃ���΋U��Ԃ�</returns>
BOOL
gsGetKeyTrigger
(
	GKEYCODE		key_code		/* �L�[�R�[�h                   */
);

/// <summary>
/// �L�[�������ꂽ�����ׂ�.
/// </summary>
/// <param name="key_code">�L�[�R�[�h</param>
/// <returns>�L�[���������ΐ^�C������Ă��Ȃ���΋U��Ԃ�</returns>
BOOL
gsGetKeyDetach
(
	GKEYCODE		key_code		/* �L�[�R�[�h                   */
);

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
);

/// <summary>
/// �ڑ�����Ă���W���C�X�e�B�b�N���𒲂ׂ�.
/// </summary>
/// <returns>�ڑ�����Ă���W���C�X�e�B�b�N����Ԃ�.</returns>
int
gsGetJoyCount
(
	void
);

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
);

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
);

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
);

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
);

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
);

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
);

/// <summary>
/// �}�E�X�̃{�^���̉�����Ԃ��擾.
/// </summary>
/// <param name="state">���ׂ����}�E�X�̃{�^��</param>
/// <returns>������Ă���ΐ^�C������Ă��Ȃ���΋U��Ԃ�.</returns>
BOOL
gsGetMouseButtonState
(
	GMOUSTATE		state			/* ���ׂ����}�E�X�̃{�^��       */
);

/// <summary>
/// �}�E�X�̃{�^���������ꂽ�����ׂ�D
/// </summary>
/// <param name="state">���ׂ����}�E�X�̃{�^��</param>
/// <returns>�����ꂽ��^�C������Ȃ���΋U��Ԃ��D</returns>
BOOL
gsGetMouseButtonTrigger
(
	GMOUSTATE		state			/* ���ׂ����}�E�X�̃{�^��       */
);

/// <summary>
/// �}�E�X�̃{�^���������ꂽ�����ׂ�.
/// </summary>
/// <param name="state">���ׂ����}�E�X�̃{�^��</param>
/// <returns>�}�E�X�̃{�^���̗����ꂽ��Ԃ�Ԃ�.</returns>
BOOL
gsGetMouseButtonDetach
(
	GMOUSTATE		state			/* ���ׂ����}�E�X�̃{�^��       */
);

/// <summary>
/// �}�E�X�J�[�\���̈ړ��䗦�̐ݒ�.
/// </summary>
/// <param name="ratio">�ړ��䗦</param>
void
gsSetMouseMoveRatio
(
	FLOAT			ratio			/* �ړ��䗦                     */
);

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
);

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
);

#ifdef __cplusplus
}
#endif

/****** ���C�u�����ݒ� ********************************************************/

#pragma comment( lib, "dinput.lib"  )
#pragma comment( lib, "dxguid.lib"  )

#ifdef	NDEBUG
# ifdef _MT
#  ifdef _DLL
#   pragma comment( lib, "gsinput_md.lib" )
#   pragma comment( lib, "gsutil_md.lib" )
#  else
#   pragma comment( lib, "gsinput_mt.lib" )
#   pragma comment( lib, "gsutil_mt.lib" )
#  endif
# else
#  pragma comment( lib, "gsinput_ml.lib" )
#  pragma comment( lib, "gsutil_ml.lib" )
# endif
#else
# ifdef _MT
#  ifdef _DLL
#   pragma comment( lib, "gsinput_mdd.lib" )
#   pragma comment( lib, "gsutil_mdd.lib" )
#  else
#   pragma comment( lib, "gsinput_mtd.lib" )
#   pragma comment( lib, "gsutil_mtd.lib" )
#  endif
# else
#  pragma comment( lib, "gsinput_mld.lib" )
#  pragma comment( lib, "gsutil_mld.lib" )
# endif
#endif

#endif

/********** End of File ******************************************************/
