/******************************************************************************
* File Name : JoyStickState.cpp                      Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�W���C�X�e�B�b�N���̓N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"JoyStickState.h"


/// <summary>
/// �ړ������̎擾.
/// </summary>
/// <param name="joyNumber">�W���C�X�e�B�b�N�ԍ�</param>
/// <returns>�ړ�����</returns>
GSvector2 JoyStickState::GetVelocity( int joyNumber ) const
{
	GSvector2 velocity( 0.0f,0.0f );

	if( IsKeyState( GJOY_UP, joyNumber ) )
	{
		velocity.y = -1.0f;
	}
	if( IsKeyState( GJOY_DOWN, joyNumber ) )
	{
		velocity.y = +1.0f;
	}
	if( IsKeyState( GJOY_LEFT, joyNumber ) )
	{
		velocity.x = -1.0f;
	}
	if( IsKeyState( GJOY_RIGHT, joyNumber ) )
	{
		velocity.x = +1.0f;
	}
	return velocity.getNormalized();
}


/// <summary>
/// �w�肵���L�[�̓��͔���(�����������Ă��邩�𔻒�.
/// </summary>
/// <param name="state">�w��{�^��</param>
/// <param name="joyNumber">�W���C�X�e�B�b�N�ԍ�</param>
/// <returns>������Ă���Ԑ^�A�����łȂ���΋U��Ԃ�.</returns>
bool JoyStickState::IsKeyState( const GJOYSTATE state, int joyNumber ) const
{
	return gsGetJoyState( joyNumber, state ) == GS_TRUE;
}




/// <summary>
/// �w�肵���L�[�̓��͔���(�����������Ă��邩�𔻒�.
/// </summary>
/// <param name="state">�w��{�^��</param>
/// <param name="joyNumber">�W���C�X�e�B�b�N�ԍ�</param>
/// <returns>�����ꂽ�u�Ԑ^�A�����łȂ���΋U��Ԃ�.</returns>
bool JoyStickState::IsGetKeyUP( const GJOYSTATE state, int joyNumber ) const

{
	return gsGetJoyDetach( joyNumber, state ) == GS_TRUE;
}

/// <summary>
/// �w�肵���L�[�̓��͔���(�����������Ă��邩�𔻒�.
/// </summary>
/// <param name="state">�w��{�^��</param>
/// <param name="joyNumber">�W���C�X�e�B�b�N�ԍ�</param>
/// <returns>������Ă��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
bool JoyStickState::IsGetKeyTrigger( const GJOYSTATE state, int joyNumber ) const
{
	return gsGetJoyTrigger( joyNumber, state ) == GS_TRUE;
}

/// <summary>
/// �W���C�X�e�B�b�N�̎��̏�Ԃ𒲂ׂ�.
/// </summary>
/// <param name="joy_no">�W���C�X�e�B�b�N�i���o</param>
/// <returns>�W���C�X�e�B�b�N�̎��̕�����Ԃ�.</returns>
GSvector3 JoyStickState::GetAxis( int joyNumber )
{
	int x,y,z;
	gsGetJoyAxis( joyNumber, &x, &y, &z );
	return GSvector3( x, y, z );
}

/// <summary>
/// �W���C�X�e�B�b�N�̐����擾.
/// </summary>
int JoyStickState::GetJoyCount()
{
	return gsGetJoyCount();
}

/********** End of File ******************************************************/
