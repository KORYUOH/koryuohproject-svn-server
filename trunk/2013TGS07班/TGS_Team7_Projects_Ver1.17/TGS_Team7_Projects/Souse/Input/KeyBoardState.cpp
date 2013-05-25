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
#include	"KeyBoardState.h"


/// <summary>
/// �ړ������̎擾.
/// </summary>
/// <returns>�ړ�����</returns>
GSvector2 KeyBoardState::GetVelocity() const
{
	GSvector2 velocity( 0.0f,0.0f );

	if( IsKeyDown(KEY_UPARROW) )
	{
		velocity.y = -1.0f;
	}
	if( IsKeyDown(KEY_DOWNARROW) )
	{
		velocity.y = +1.0f;
	}
	if( IsKeyDown(KEY_LEFTARROW) )
	{
		velocity.x = -1.0f;
	}
	if( IsKeyDown(KEY_RIGHTARROW) )
	{
		velocity.x = +1.0f;
	}
	return velocity.getNormalized();
}


/// <summary>
/// �w�肵���L�[�̓��͔���(�����������Ă��邩�𔻒�.
/// </summary>
/// <param name="id">�w��L�[��ID</param>
/// <returns>�����ꂽ�u�Ԑ^�A�����łȂ���΋U��Ԃ�.</returns>
bool KeyBoardState::IsKeyDown( const InputID id ) const
{
	return gsGetKeyState( id ) == GS_TRUE;
}

/// <summary>
/// �w�肵���L�[�̓��͔���(�����������Ă��邩�𔻒�.
/// </summary>
/// <param name="key">�w��L�[�R�[�h</param>
/// <returns>�����ꂽ�u�Ԑ^�A�����łȂ���΋U��Ԃ�.</returns>
bool KeyBoardState::IsKeyDown( const KeyCode key ) const
{
	return gsGetKeyState( key ) == GS_TRUE;
}

/// <summary>
/// �w�肵���L�[�̓��͔���(�����ꂽ�u�Ԃ𔻒�.
/// </summary>
/// <param name="id">�w��L�[��ID</param>
/// <returns>�����ꂽ�u�Ԑ^�A�����łȂ���΋U��Ԃ�.</returns>
bool KeyBoardState::IsGetKeyUP( const InputID id ) const
{
	return gsGetKeyDetach( id ) == GS_TRUE;
}

/// <summary>
/// �w�肵���L�[�̓��͔���(�����ꂽ�u�Ԃ𔻒�.
/// </summary>
/// <param name="key">�w��L�[�R�[�h</param>
/// <returns>�����ꂽ�u�Ԑ^�A�����łȂ���΋U��Ԃ�.</returns>
bool KeyBoardState::IsGetKeyUP( const KeyCode key ) const
{
	return gsGetKeyDetach( key ) == GS_TRUE;
}

/// <summary>
/// �w�肵���L�[�̓��͔���(1��̓��͂𔻒�).
/// </summary>
/// <param name="id">�w��L�[��ID</param>
/// <returns>������Ă��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
bool KeyBoardState::IsGetKeyTrigger( const InputID id ) const
{
	return gsGetKeyTrigger( id ) == GS_TRUE;
}

/// <summary>
/// �w�肵���L�[�̓��͔���(1��̓��͂𔻒�).
/// </summary>
/// <param name="key">�w��L�[�R�[�h</param>
/// <returns>������Ă��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
bool KeyBoardState::IsGetKeyTrigger( const KeyCode key ) const
{
	return gsGetKeyTrigger( key ) == GS_TRUE;
}

/********** End of File ******************************************************/
