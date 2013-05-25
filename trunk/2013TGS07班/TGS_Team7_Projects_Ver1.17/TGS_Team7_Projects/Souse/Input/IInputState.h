/******************************************************************************
* File Name : IInputState.h                      Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		���͒��ۃN���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef		_I_INPUT_STATE_H_
#define		_I_INPUT_STATE_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include	<gslib.h>
#include	"KeyCode.h"
#include	"InputID.h"


/// <summary>
/// ���͒��ۃN���X.
/// </summary>
class IInputState
{

public:
	/*�f�X�g���N�^*/
	~IInputState(){}

public:
	/// <summary>
	/// �ړ������̎擾.
	/// </summary>
	/// <returns>�ړ�����</returns>
	virtual GSvector2 GetVelocity() const = 0;
	/// <summary>
	/// ����{�^���̓��͔���(�����������Ă��邩�𔻒�.
	/// </summary>
	/// <returns>������Ă��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
	virtual bool IsEnterButton() const = 0;
	/// <summary>
	/// �L�����Z���{�^���̓��͔���(�����ꂽ�u�Ԃ𔻒�.
	/// </summary>
	/// <returns>������Ă��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
	virtual bool IsCancelButton() const = 0;
	/// <summary>
	/// �ċN���{�^���̓��͔���.
	/// </summary>
	/// <returns>������Ă��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
	virtual bool IsReStart() const = 0;

}; // class IInputState end


#endif // !_I_INPUT_STATE_H_

/********** End of File ******************************************************/
