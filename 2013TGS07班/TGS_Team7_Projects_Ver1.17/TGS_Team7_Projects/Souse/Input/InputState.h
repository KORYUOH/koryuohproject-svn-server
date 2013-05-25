/******************************************************************************
* File Name : InputState.cpp                      Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		���̓N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef		_INPUT_STATE_H_
#define		_INPUT_STATE_H_

#include"IInputState.h"
#include"KeyBoardState.h"
#include"MouseState.h"
#include"JoyStickState.h"

/// <summary>
/// ���̓N���X.
/// </summary>
class InputState : public IInputState
{

public:
	/*�f�X�g���N�^*/
	~InputState(){}
	/// <summary>
	/// �ړ������̎擾.
	/// </summary>
	/// <returns>�ړ�����</returns>
	virtual GSvector2 GetVelocity() const;

public:
	/// <summary>
	/// ����{�^���̓��͔���(�����������Ă��邩�𔻒�.
	/// </summary>
	/// <returns>������Ă��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
	virtual bool IsEnterButton() const;
	/// <summary>
	/// �L�����Z���{�^���̓��͔���(�����ꂽ�u�Ԃ𔻒�.
	/// </summary>
	/// <returns>������Ă��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
	virtual bool IsCancelButton() const;
	/// <summary>
	/// �ċN���{�^���̓��͔���.
	/// </summary>
	/// <returns>������Ă��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
	virtual bool IsReStart() const;


public:
	/// <summary>
	/// ���̂��擾.
	/// <para>�V���O���g��</para>
	/// </summary>
	/// <returns>���̂�Ԃ�.</returns>
	static InputState* GetInstance()
	{
		static InputState mInstance;
		return &mInstance;
	}

private:
	/// <summary>
	/// �R���X�g���N�^.
	/// <para>�O���A�N�Z�X�̋֎~.</para>
	/// </summary>
	InputState(){}
	/// <summary>
	/// �R�s�[�R���X�g���N�^.
	/// <para>�O���A�N�Z�X�̋֎~.</para>
	/// </summary>
	InputState( const InputState& other );
	/// <summary>
	/// ������Z�q.
	/// <para>�O���A�N�Z�X�̋֎~.</para>
	/// </summary>
	InputState& operator =( const InputState& other );

private:
	/// <summary>
	/// �L�[�{�[�h���̓N���X.
	/// </summary>
	KeyBoardState	mKeyBoard;
	/// <summary>
	/// �}�E�X���̓N���X.
	/// </summary>
	MouseState		mMouse;
	/// <summary>
	/// �W���C�X�e�B�b�N���̓N���X.
	/// </summary>
	JoyStickState	mJoyStick;

};


#endif // !_I_INPUT_STATE_H_

/********** End of File ******************************************************/
