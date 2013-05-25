/******************************************************************************
* File Name : JoyStickState.h                  Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�W���C�X�e�B�b�N���̓N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef		_JOY_STICK_STATE_H_
#define		_JOY_STICK_STATE_H_

#include<gslib.h>
#include"KeyCode.h"
#include"InputID.h"

/// <summary>
/// ���̓N���X.
/// </summary>
class JoyStickState
{

public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	JoyStickState(){}
	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	~JoyStickState(){}
	/// <summary>
	/// �ړ������̎擾.
	/// </summary>
	/// <param name="joyNumber">�W���C�X�e�B�b�N�ԍ�</param>
	/// <returns>�ړ�����</returns>
	GSvector2 GetVelocity( int joyNumber = 0 ) const;
	// �L�[�{�[�h.
public:
	/// <summary>
	/// �w�肵���L�[�̓��͔���(�����������Ă��邩�𔻒�.
	/// </summary>
	/// <param name="state">�w��{�^��</param>
	/// <param name="joyNumber">�W���C�X�e�B�b�N�ԍ�</param>
	/// <returns>������Ă���Ԑ^�A�����łȂ���΋U��Ԃ�.</returns>
	bool IsKeyState( const GJOYSTATE state, int joyNumber = 0 ) const;
	/// <summary>
	/// �w�肵���L�[�̓��͔���(�����������Ă��邩�𔻒�.
	/// </summary>
	/// <param name="state">�w��{�^��</param>
	/// <param name="joyNumber">�W���C�X�e�B�b�N�ԍ�</param>
	/// <returns>�����ꂽ�u�Ԑ^�A�����łȂ���΋U��Ԃ�.</returns>
	bool IsGetKeyUP( const GJOYSTATE state, int joyNumber = 0 ) const;
	/// <summary>
	/// �w�肵���L�[�̓��͔���(�����������Ă��邩�𔻒�.
	/// </summary>
	/// <param name="state">�w��{�^��</param>
	/// <param name="joyNumber">�W���C�X�e�B�b�N�ԍ�</param>
	/// <returns>������Ă��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
	bool IsGetKeyTrigger( const GJOYSTATE state, int joyNumber = 0 ) const;
	/// <summary>
	/// �W���C�X�e�B�b�N�̎��̏�Ԃ𒲂ׂ�.
	/// </summary>
	/// <param name="joy_no">�W���C�X�e�B�b�N�i���o</param>
	/// <returns>�W���C�X�e�B�b�N�̎��̕�����Ԃ�.</returns>
	GSvector3 GetAxis( int joyNumber = 0 );
	/// <summary>
	/// �W���C�X�e�B�b�N�̐����擾.
	/// </summary>
	int GetJoyCount();



private:
	/// <summary>
	/// �R�s�[�R���X�g���N�^.
	/// <para>�O���A�N�Z�X�̋֎~.</para>
	/// </summary>
	JoyStickState( const JoyStickState& other );
	/// <summary>
	/// ������Z�q.
	/// <para>�O���A�N�Z�X�̋֎~.</para>
	/// </summary>
	JoyStickState& operator =( const JoyStickState& other );

};


#endif // !_KEY_BOARD_STATE_H_

/********** End of File ******************************************************/
