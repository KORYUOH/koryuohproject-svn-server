/******************************************************************************
* File Name : KeyBoardState.h                     Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�L�[�{�[�h���̓N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef		_KEY_BOARD_STATE_H_
#define		_KEY_BOARD_STATE_H_

#include<gslib.h>
#include"KeyCode.h"
#include"InputID.h"

/// <summary>
/// ���̓N���X.
/// </summary>
class KeyBoardState
{

public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	KeyBoardState(){}
	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	~KeyBoardState(){}
	/// <summary>
	/// �ړ������̎擾.
	/// </summary>
	/// <returns>�ړ�����</returns>
	virtual GSvector2 GetVelocity() const;

	// �L�[�{�[�h.
public:
	/// <summary>
	/// �w�肵���L�[�̓��͔���(�����������Ă��邩�𔻒�.
	/// </summary>
	/// <param name="id">�w��L�[��ID</param>
	/// <returns>�����ꂽ�u�Ԑ^�A�����łȂ���΋U��Ԃ�.</returns>
	virtual bool IsKeyDown( const InputID id ) const;
	/// <summary>
	/// �w�肵���L�[�̓��͔���(�����������Ă��邩�𔻒�.
	/// </summary>
	/// <param name="key">�w��L�[�R�[�h</param>
	/// <returns>�����ꂽ�u�Ԑ^�A�����łȂ���΋U��Ԃ�.</returns>
	virtual bool IsKeyDown( const KeyCode key ) const;
	/// <summary>
	/// �w�肵���L�[�̓��͔���(�����ꂽ�u�Ԃ𔻒�.
	/// </summary>
	/// <param name="id">�w��L�[��ID</param>
	/// <returns>�����ꂽ�u�Ԑ^�A�����łȂ���΋U��Ԃ�.</returns>
	virtual bool IsGetKeyUP( const InputID id ) const;
	/// <summary>
	/// �w�肵���L�[�̓��͔���(�����ꂽ�u�Ԃ𔻒�.
	/// </summary>
	/// <param name="key">�w��L�[�R�[�h</param>
	/// <returns>�����ꂽ�u�Ԑ^�A�����łȂ���΋U��Ԃ�.</returns>
	virtual bool IsGetKeyUP( const KeyCode key ) const;
	/// <summary>
	/// �w�肵���L�[�̓��͔���(1��̓��͂𔻒�).
	/// </summary>
	/// <param name="id">�w��L�[��ID</param>
	/// <returns>������Ă��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
	virtual bool IsGetKeyTrigger( const InputID id ) const;
	/// <summary>
	/// �w�肵���L�[�̓��͔���(1��̓��͂𔻒�).
	/// </summary>
	/// <param name="key">�w��L�[�R�[�h</param>
	/// <returns>������Ă��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
	virtual bool IsGetKeyTrigger( const KeyCode key ) const;


private:
	/// <summary>
	/// �R�s�[�R���X�g���N�^.
	/// <para>�O���A�N�Z�X�̋֎~.</para>
	/// </summary>
	KeyBoardState( const KeyBoardState& other );
	/// <summary>
	/// ������Z�q.
	/// <para>�O���A�N�Z�X�̋֎~.</para>
	/// </summary>
	KeyBoardState& operator =( const KeyBoardState& other );


};


#endif // !_KEY_BOARD_STATE_H_

/********** End of File ******************************************************/
