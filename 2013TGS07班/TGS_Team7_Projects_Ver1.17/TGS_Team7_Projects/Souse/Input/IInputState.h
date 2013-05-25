/******************************************************************************
* File Name : IInputState.h                      Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		入力抽象クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef		_I_INPUT_STATE_H_
#define		_I_INPUT_STATE_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include	<gslib.h>
#include	"KeyCode.h"
#include	"InputID.h"


/// <summary>
/// 入力抽象クラス.
/// </summary>
class IInputState
{

public:
	/*デストラクタ*/
	~IInputState(){}

public:
	/// <summary>
	/// 移動方向の取得.
	/// </summary>
	/// <returns>移動方向</returns>
	virtual GSvector2 GetVelocity() const = 0;
	/// <summary>
	/// 決定ボタンの入力判定(押し続けられているかを判定.
	/// </summary>
	/// <returns>押されている時真、そうでなければ偽を返す.</returns>
	virtual bool IsEnterButton() const = 0;
	/// <summary>
	/// キャンセルボタンの入力判定(離された瞬間を判定.
	/// </summary>
	/// <returns>押されている時真、そうでなければ偽を返す.</returns>
	virtual bool IsCancelButton() const = 0;
	/// <summary>
	/// 再起動ボタンの入力判定.
	/// </summary>
	/// <returns>押されている時真、そうでなければ偽を返す.</returns>
	virtual bool IsReStart() const = 0;

}; // class IInputState end


#endif // !_I_INPUT_STATE_H_

/********** End of File ******************************************************/
