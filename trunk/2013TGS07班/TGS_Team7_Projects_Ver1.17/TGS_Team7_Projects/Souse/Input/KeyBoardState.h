/******************************************************************************
* File Name : KeyBoardState.h                     Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		キーボード入力クラス．
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
/// 入力クラス.
/// </summary>
class KeyBoardState
{

public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	KeyBoardState(){}
	/// <summary>
	/// デストラクタ.
	/// </summary>
	~KeyBoardState(){}
	/// <summary>
	/// 移動方向の取得.
	/// </summary>
	/// <returns>移動方向</returns>
	virtual GSvector2 GetVelocity() const;

	// キーボード.
public:
	/// <summary>
	/// 指定したキーの入力判定(押し続けられているかを判定.
	/// </summary>
	/// <param name="id">指定キーのID</param>
	/// <returns>離された瞬間真、そうでなければ偽を返す.</returns>
	virtual bool IsKeyDown( const InputID id ) const;
	/// <summary>
	/// 指定したキーの入力判定(押し続けられているかを判定.
	/// </summary>
	/// <param name="key">指定キーコード</param>
	/// <returns>離された瞬間真、そうでなければ偽を返す.</returns>
	virtual bool IsKeyDown( const KeyCode key ) const;
	/// <summary>
	/// 指定したキーの入力判定(離された瞬間を判定.
	/// </summary>
	/// <param name="id">指定キーのID</param>
	/// <returns>離された瞬間真、そうでなければ偽を返す.</returns>
	virtual bool IsGetKeyUP( const InputID id ) const;
	/// <summary>
	/// 指定したキーの入力判定(離された瞬間を判定.
	/// </summary>
	/// <param name="key">指定キーコード</param>
	/// <returns>離された瞬間真、そうでなければ偽を返す.</returns>
	virtual bool IsGetKeyUP( const KeyCode key ) const;
	/// <summary>
	/// 指定したキーの入力判定(1回の入力を判定).
	/// </summary>
	/// <param name="id">指定キーのID</param>
	/// <returns>押されている時真、そうでなければ偽を返す.</returns>
	virtual bool IsGetKeyTrigger( const InputID id ) const;
	/// <summary>
	/// 指定したキーの入力判定(1回の入力を判定).
	/// </summary>
	/// <param name="key">指定キーコード</param>
	/// <returns>押されている時真、そうでなければ偽を返す.</returns>
	virtual bool IsGetKeyTrigger( const KeyCode key ) const;


private:
	/// <summary>
	/// コピーコンストラクタ.
	/// <para>外部アクセスの禁止.</para>
	/// </summary>
	KeyBoardState( const KeyBoardState& other );
	/// <summary>
	/// 代入演算子.
	/// <para>外部アクセスの禁止.</para>
	/// </summary>
	KeyBoardState& operator =( const KeyBoardState& other );


};


#endif // !_KEY_BOARD_STATE_H_

/********** End of File ******************************************************/
