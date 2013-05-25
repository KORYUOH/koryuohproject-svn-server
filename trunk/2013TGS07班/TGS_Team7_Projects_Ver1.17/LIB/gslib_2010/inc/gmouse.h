/******************************************************************************
* File Name : gmouse.h                             Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       �Q�[���V�X�e���p �}�E�X���� �w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GMOUSE_H_
#define		_GMOUSE_H_

#include	"type.h"

/****** �f�[�^�^�錾 *********************************************************/

typedef	void*		GMOUSE;			/* �}�E�X�n���h��           */

/*----- �}�E�X�{�^�����͏�� ------------------------------------------------*/

/// <summary>
/// �}�E�X�{�^�����͗񋓌^.
/// </summary>
typedef	enum
{
	/// <summary>
	/// �}�E�X�{�^��1.
	/// <para>���{�^��.</para>
	/// </summary>
	GMOUSE_BUTTON_1 = 0x0001U,
	/// <summary>
	/// �}�E�X�{�^��2.
	/// <para>�E�{�^��.</para>
	/// </summary>
	GMOUSE_BUTTON_2 = 0x0002U,
	/// <summary>
	/// �}�E�X�{�^��3.
	/// <para>���{�^��(�z�C�[��).</para>
	/// </summary>
	GMOUSE_BUTTON_3 = 0x0004U,
	/// <summary>
	/// �}�E�X�{�^��4.
	/// </summary>
	GMOUSE_BUTTON_4 = 0x0008U,

} GMOUSTATE;

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

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
		);

	/// <summary>
	/// �}�E�X�̏���.
	/// </summary>
	/// <param name="hnd">�}�E�X�n���h��</param>
	void
		GMouseDelete
		(
		GMOUSE			hnd				/* �}�E�X�n���h��           */
		);

	/// <summary>
	/// �}�E�X�̓ǂݍ���.
	/// </summary>
	/// <param name="hnd">�}�E�X�n���h��</param>
	void
		GMouseReadDevice
		(
		GMOUSE			hnd				/* �}�E�X�n���h��           */
		);

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
		);

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
		);

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
		);

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
		);

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
		);

	/// <summary>
	/// �}�E�X�J�[�\���̈ړ��䗦�̎擾.
	/// </summary>
	/// <param name="hnd">�}�E�X�n���h��</param>
	/// <returns>�ړ��䗦.</returns>
	FLOAT
		GMouseGetMoveRatio
		(
		GMOUSE			hnd				/* �}�E�X�n���h��           */
		);

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
		);

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
		);

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
		);

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
		);

	/// <summary>
	/// �}�E�X�̃A�N�Z�X���̍Ď擾.
	/// </summary>
	/// <param name="hnd">�}�E�X�n���h��</param>
	/// <returns>�擾�ł���ΐ^�C�擾�ł��Ȃ���΋U��Ԃ�.</returns>
	BOOL
		GMouseReacquire
		(
		GMOUSE				hnd			/* �}�E�X�n���h��           */
		);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
