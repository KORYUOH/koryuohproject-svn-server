/******************************************************************************
* File Name : JoyStickState.cpp                      Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		ジョイスティック入力クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"JoyStickState.h"


/// <summary>
/// 移動方向の取得.
/// </summary>
/// <param name="joyNumber">ジョイスティック番号</param>
/// <returns>移動方向</returns>
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
/// 指定したキーの入力判定(押し続けられているかを判定.
/// </summary>
/// <param name="state">指定ボタン</param>
/// <param name="joyNumber">ジョイスティック番号</param>
/// <returns>押されている間真、そうでなければ偽を返す.</returns>
bool JoyStickState::IsKeyState( const GJOYSTATE state, int joyNumber ) const
{
	return gsGetJoyState( joyNumber, state ) == GS_TRUE;
}




/// <summary>
/// 指定したキーの入力判定(押し続けられているかを判定.
/// </summary>
/// <param name="state">指定ボタン</param>
/// <param name="joyNumber">ジョイスティック番号</param>
/// <returns>離された瞬間真、そうでなければ偽を返す.</returns>
bool JoyStickState::IsGetKeyUP( const GJOYSTATE state, int joyNumber ) const

{
	return gsGetJoyDetach( joyNumber, state ) == GS_TRUE;
}

/// <summary>
/// 指定したキーの入力判定(押し続けられているかを判定.
/// </summary>
/// <param name="state">指定ボタン</param>
/// <param name="joyNumber">ジョイスティック番号</param>
/// <returns>押されている時真、そうでなければ偽を返す.</returns>
bool JoyStickState::IsGetKeyTrigger( const GJOYSTATE state, int joyNumber ) const
{
	return gsGetJoyTrigger( joyNumber, state ) == GS_TRUE;
}

/// <summary>
/// ジョイスティックの軸の状態を調べる.
/// </summary>
/// <param name="joy_no">ジョイスティックナンバ</param>
/// <returns>ジョイスティックの軸の方向を返す.</returns>
GSvector3 JoyStickState::GetAxis( int joyNumber )
{
	int x,y,z;
	gsGetJoyAxis( joyNumber, &x, &y, &z );
	return GSvector3( x, y, z );
}

/// <summary>
/// ジョイスティックの数を取得.
/// </summary>
int JoyStickState::GetJoyCount()
{
	return gsGetJoyCount();
}

/********** End of File ******************************************************/
