/******************************************************************************
* File Name : MouseState.h                             Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		マウスクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef		_MOUSE_STATE_H_
#define		_MOUSE_STATE_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<gslib.h>


/// <summary>
/// マウスクラス.
/// </summary>
class MouseState
{

public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	MouseState();
	/// <summary>
	/// デストラクタ.
	/// </summary>
	~MouseState();
	/// <summary>
	/// 初期化.
	/// </summary>
	void initialize();
	/// <summary>
	/// 移動方向の取得.
	/// </summary>
	/// <returns>移動方向</returns>
	GSvector2 GetVelocity() const;
	/// <summary>
	/// マウスの位置を取得.
	/// </summary>
	/// <returns>位置情報</returns>
	GSvector2 GetMousePosition() const;
	/// <summary>
	/// マウスのボタンの押下状態を取得.
	/// </summary>
	/// <param name="state">調べたいマウスのボタン</param>
	/// <returns>押されていれば真，押されていなければ偽を返す.</returns>
	bool IsMouseButtonDown( GMOUSTATE state ) const;
	/// <summary>
	/// マウスのボタンが押されたか調べる．
	/// </summary>
	/// <param name="state">調べたいマウスのボタン</param>
	/// <returns>押されたら真，押されなければ偽を返す．</returns>
	bool IsMouseButtonTrigger( GMOUSTATE state ) const;
	/// <summary>
	/// マウスのボタンが離されたか調べる.
	/// </summary>
	/// <param name="state">調べたいマウスのボタン</param>
	/// <returns>マウスのボタンの離された状態を返す.</returns>
	bool IsMouseButtonUp( GMOUSTATE state ) const;
	/// <summary>
	/// マウスの移動範囲を固定する.
	/// </summary>
	void MouseMoveLimit() const;


private:
	/// <summary>
	/// コピーコンストラクタ.
	/// <para>外部アクセスの禁止.</para>
	/// </summary>
	MouseState( const MouseState& other );
	/// <summary>
	/// 代入演算子.
	/// <para>外部アクセスの禁止.</para>
	/// </summary>
	MouseState& operator =( const MouseState& other );

};

#endif // !_MOUSE_STATE_H_

/********** End of File ******************************************************/
