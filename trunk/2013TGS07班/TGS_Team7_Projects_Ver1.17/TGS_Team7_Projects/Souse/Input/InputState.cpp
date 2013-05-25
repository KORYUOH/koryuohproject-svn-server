/******************************************************************************
* File Name : InputState.cpp                      Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		入力クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include	"InputState.h"
#include	"../Utility/Screen.h"


/// <summary>
/// 移動方向の取得.
/// </summary>
/// <returns>移動方向</returns>
GSvector2 InputState::GetVelocity() const
{
	GSvector2 velocity( 0.0f, 0.0f );
	velocity += mKeyBoard.GetVelocity() + mMouse.GetVelocity() + mJoyStick.GetVelocity();

	return velocity.getNormalized();
}


/// <summary>
/// 決定ボタンの入力判定(押し続けられているかを判定.
/// </summary>
/// <returns>押されている時真、そうでなければ偽を返す.</returns>
bool InputState::IsEnterButton() const
{
	return mKeyBoard.IsGetKeyTrigger( KEY_A ) ||
		mMouse.IsMouseButtonTrigger( GMOUSE_BUTTON_1 ) ||
		mJoyStick.IsGetKeyTrigger(GJOY_BUTTON_1);
}

/// <summary>
/// キャンセルボタンの入力判定(離された瞬間を判定.
/// </summary>
/// <returns>押されている時真、そうでなければ偽を返す.</returns>
bool InputState::IsCancelButton() const
{
	return mKeyBoard.IsGetKeyTrigger( KEY_D ) ||
		mMouse.IsMouseButtonTrigger( GMOUSE_BUTTON_2 ) ||
		mJoyStick.IsGetKeyTrigger(GJOY_BUTTON_2);
}

/// <summary>
/// 再起動ボタンの入力判定.
/// </summary>
/// <returns>押されている時真、そうでなければ偽を返す.</returns>
bool InputState::IsReStart() const
{
	return mKeyBoard.IsGetKeyTrigger( KEY_R ) ||
		mJoyStick.IsGetKeyTrigger(GJOY_BUTTON_3);
}

/********** End of File ******************************************************/
