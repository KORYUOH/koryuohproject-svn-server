/******************************************************************************
* File Name : JoyStickState.h                  Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		ジョイスティック入力クラス．
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
/// 入力クラス.
/// </summary>
class JoyStickState
{

public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	JoyStickState(){}
	/// <summary>
	/// デストラクタ.
	/// </summary>
	~JoyStickState(){}
	/// <summary>
	/// 移動方向の取得.
	/// </summary>
	/// <param name="joyNumber">ジョイスティック番号</param>
	/// <returns>移動方向</returns>
	GSvector2 GetVelocity( int joyNumber = 0 ) const;
	// キーボード.
public:
	/// <summary>
	/// 指定したキーの入力判定(押し続けられているかを判定.
	/// </summary>
	/// <param name="state">指定ボタン</param>
	/// <param name="joyNumber">ジョイスティック番号</param>
	/// <returns>押されている間真、そうでなければ偽を返す.</returns>
	bool IsKeyState( const GJOYSTATE state, int joyNumber = 0 ) const;
	/// <summary>
	/// 指定したキーの入力判定(押し続けられているかを判定.
	/// </summary>
	/// <param name="state">指定ボタン</param>
	/// <param name="joyNumber">ジョイスティック番号</param>
	/// <returns>離された瞬間真、そうでなければ偽を返す.</returns>
	bool IsGetKeyUP( const GJOYSTATE state, int joyNumber = 0 ) const;
	/// <summary>
	/// 指定したキーの入力判定(押し続けられているかを判定.
	/// </summary>
	/// <param name="state">指定ボタン</param>
	/// <param name="joyNumber">ジョイスティック番号</param>
	/// <returns>押されている時真、そうでなければ偽を返す.</returns>
	bool IsGetKeyTrigger( const GJOYSTATE state, int joyNumber = 0 ) const;
	/// <summary>
	/// ジョイスティックの軸の状態を調べる.
	/// </summary>
	/// <param name="joy_no">ジョイスティックナンバ</param>
	/// <returns>ジョイスティックの軸の方向を返す.</returns>
	GSvector3 GetAxis( int joyNumber = 0 );
	/// <summary>
	/// ジョイスティックの数を取得.
	/// </summary>
	int GetJoyCount();



private:
	/// <summary>
	/// コピーコンストラクタ.
	/// <para>外部アクセスの禁止.</para>
	/// </summary>
	JoyStickState( const JoyStickState& other );
	/// <summary>
	/// 代入演算子.
	/// <para>外部アクセスの禁止.</para>
	/// </summary>
	JoyStickState& operator =( const JoyStickState& other );

};


#endif // !_KEY_BOARD_STATE_H_

/********** End of File ******************************************************/
