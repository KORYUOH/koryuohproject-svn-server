/******************************************************************************
* File Name : Button.h                           Ver : 1.00  Date : 2013-04-25
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
/// UIフレームクラス.
/// </summary>
class Button : public GUI
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="collider">衝突情報</param>
	/// <param name="flag">フラグ管理者.</param>
	/// <param name="flagID">フラグID.</param>
	/// <param name="textureID">テクスチャID.</param>
	Button( Collider& collider, IFlagManager& flag, FlagID flagID, TextureID textureID );
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
	Animation		mAnimation;

}; // class Button end


#endif // _GUI_BOTTON_H_ end

/********** End of File ******************************************************/
