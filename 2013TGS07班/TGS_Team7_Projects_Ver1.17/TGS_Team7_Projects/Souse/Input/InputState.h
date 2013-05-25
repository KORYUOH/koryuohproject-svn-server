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
#ifndef		_INPUT_STATE_H_
#define		_INPUT_STATE_H_

#include"IInputState.h"
#include"KeyBoardState.h"
#include"MouseState.h"
#include"JoyStickState.h"

/// <summary>
/// 入力クラス.
/// </summary>
class InputState : public IInputState
{

public:
	/*デストラクタ*/
	~InputState(){}
	/// <summary>
	/// 移動方向の取得.
	/// </summary>
	/// <returns>移動方向</returns>
	virtual GSvector2 GetVelocity() const;

public:
	/// <summary>
	/// 決定ボタンの入力判定(押し続けられているかを判定.
	/// </summary>
	/// <returns>押されている時真、そうでなければ偽を返す.</returns>
	virtual bool IsEnterButton() const;
	/// <summary>
	/// キャンセルボタンの入力判定(離された瞬間を判定.
	/// </summary>
	/// <returns>押されている時真、そうでなければ偽を返す.</returns>
	virtual bool IsCancelButton() const;
	/// <summary>
	/// 再起動ボタンの入力判定.
	/// </summary>
	/// <returns>押されている時真、そうでなければ偽を返す.</returns>
	virtual bool IsReStart() const;


public:
	/// <summary>
	/// 実体を取得.
	/// <para>シングルトン</para>
	/// </summary>
	/// <returns>実体を返す.</returns>
	static InputState* GetInstance()
	{
		static InputState mInstance;
		return &mInstance;
	}

private:
	/// <summary>
	/// コンストラクタ.
	/// <para>外部アクセスの禁止.</para>
	/// </summary>
	InputState(){}
	/// <summary>
	/// コピーコンストラクタ.
	/// <para>外部アクセスの禁止.</para>
	/// </summary>
	InputState( const InputState& other );
	/// <summary>
	/// 代入演算子.
	/// <para>外部アクセスの禁止.</para>
	/// </summary>
	InputState& operator =( const InputState& other );

private:
	/// <summary>
	/// キーボード入力クラス.
	/// </summary>
	KeyBoardState	mKeyBoard;
	/// <summary>
	/// マウス入力クラス.
	/// </summary>
	MouseState		mMouse;
	/// <summary>
	/// ジョイスティック入力クラス.
	/// </summary>
	JoyStickState	mJoyStick;

};


#endif // !_I_INPUT_STATE_H_

/********** End of File ******************************************************/
