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
#include	"InputState.h"
#include	"../Utility/Screen.h"


/// <summary>
/// �ړ������̎擾.
/// </summary>
/// <returns>�ړ�����</returns>
GSvector2 InputState::GetVelocity() const
{
	GSvector2 velocity( 0.0f, 0.0f );
	velocity += mKeyBoard.GetVelocity() + mMouse.GetVelocity() + mJoyStick.GetVelocity();

	return velocity.getNormalized();
}


/// <summary>
/// ����{�^���̓��͔���(�����������Ă��邩�𔻒�.
/// </summary>
/// <returns>������Ă��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
bool InputState::IsEnterButton() const
{
	return mKeyBoard.IsGetKeyTrigger( KEY_A ) ||
		mMouse.IsMouseButtonTrigger( GMOUSE_BUTTON_1 ) ||
		mJoyStick.IsGetKeyTrigger(GJOY_BUTTON_1);
}

/// <summary>
/// �L�����Z���{�^���̓��͔���(�����ꂽ�u�Ԃ𔻒�.
/// </summary>
/// <returns>������Ă��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
bool InputState::IsCancelButton() const
{
	return mKeyBoard.IsGetKeyTrigger( KEY_D ) ||
		mMouse.IsMouseButtonTrigger( GMOUSE_BUTTON_2 ) ||
		mJoyStick.IsGetKeyTrigger(GJOY_BUTTON_2);
}

/// <summary>
/// �ċN���{�^���̓��͔���.
/// </summary>
/// <returns>������Ă��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
bool InputState::IsReStart() const
{
	return mKeyBoard.IsGetKeyTrigger( KEY_R ) ||
		mJoyStick.IsGetKeyTrigger(GJOY_BUTTON_3);
}

/********** End of File ******************************************************/
