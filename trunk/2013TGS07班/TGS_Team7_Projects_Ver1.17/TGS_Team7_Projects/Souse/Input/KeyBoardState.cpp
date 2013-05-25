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
#include	"KeyBoardState.h"


/// <summary>
/// 移動方向の取得.
/// </summary>
/// <returns>移動方向</returns>
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
/// 指定したキーの入力判定(押し続けられているかを判定.
/// </summary>
/// <param name="id">指定キーのID</param>
/// <returns>離された瞬間真、そうでなければ偽を返す.</returns>
bool KeyBoardState::IsKeyDown( const InputID id ) const
{
	return gsGetKeyState( id ) == GS_TRUE;
}

/// <summary>
/// 指定したキーの入力判定(押し続けられているかを判定.
/// </summary>
/// <param name="key">指定キーコード</param>
/// <returns>離された瞬間真、そうでなければ偽を返す.</returns>
bool KeyBoardState::IsKeyDown( const KeyCode key ) const
{
	return gsGetKeyState( key ) == GS_TRUE;
}

/// <summary>
/// 指定したキーの入力判定(離された瞬間を判定.
/// </summary>
/// <param name="id">指定キーのID</param>
/// <returns>離された瞬間真、そうでなければ偽を返す.</returns>
bool KeyBoardState::IsGetKeyUP( const InputID id ) const
{
	return gsGetKeyDetach( id ) == GS_TRUE;
}

/// <summary>
/// 指定したキーの入力判定(離された瞬間を判定.
/// </summary>
/// <param name="key">指定キーコード</param>
/// <returns>離された瞬間真、そうでなければ偽を返す.</returns>
bool KeyBoardState::IsGetKeyUP( const KeyCode key ) const
{
	return gsGetKeyDetach( key ) == GS_TRUE;
}

/// <summary>
/// 指定したキーの入力判定(1回の入力を判定).
/// </summary>
/// <param name="id">指定キーのID</param>
/// <returns>押されている時真、そうでなければ偽を返す.</returns>
bool KeyBoardState::IsGetKeyTrigger( const InputID id ) const
{
	return gsGetKeyTrigger( id ) == GS_TRUE;
}

/// <summary>
/// 指定したキーの入力判定(1回の入力を判定).
/// </summary>
/// <param name="key">指定キーコード</param>
/// <returns>押されている時真、そうでなければ偽を返す.</returns>
bool KeyBoardState::IsGetKeyTrigger( const KeyCode key ) const
{
	return gsGetKeyTrigger( key ) == GS_TRUE;
}

/********** End of File ******************************************************/
