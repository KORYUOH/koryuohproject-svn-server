/******************************************************************************
* File Name : Cursor.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ユーザーインターフェースフレームクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_BOTTON_H_
#define _GUI_BOTTON_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<list>
#include"GUI.h"
#include"../Draw/Animation.h"

/*---- 先行宣言 -------------------------------------------------------------*/


/// <summary>
/// カーソルGUI.
/// </summary>
class CursorGUI : public GUI
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="collider">衝突情報</param>
	/// <param name="flagManager">フラグ管理者</param>
	/// <param name="position">位置情報</param>
	CursorGUI( Collider& collider, IFlagManager& flagManager, const GSvector2* position );
	/// <summary>
	/// 更新.
	/// </summary>
	/// <param name="frameTimer">フレームレート</param>
	virtual void Update( float frameTimer );
	/// <summary>
	/// 描画.
	/// </summary>
	/// <param name="position">フレームの位置</param>
	/// <param name="angle">角度</param>
	virtual void Draw( const GSvector2& position, float angle ) const;
private:
	/// <summary>
	/// アニメーション.
	/// </summary>
	Animation			mAnimation;
	/// <summary>
	/// アニメーション.
	/// </summary>
	const GSvector2*	mPosition;


}; // class Button end


#endif // CursorGUI end

/********** End of File ******************************************************/
