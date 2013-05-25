/******************************************************************************
* File Name : GUILevel.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ユーザーインターフェースフレームクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_LEVEL_H_
#define _GUI_LEVEL_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<list>
#include"GUI.h"
#include"../Draw/Animation.h"

/*---- 先行宣言 -------------------------------------------------------------*/

class IFlagManager;

/// <summary>
/// カーソルGUI.
/// </summary>
class GUILevel : public GUI
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="collider">衝突情報</param>
	/// <param name="flagManager">フラグ管理者</param>
	/// <param name="level">レベルへのパス</param>
	/// <param name="angle">角度</param>
	GUILevel( Collider& collider, IFlagManager& flagManager, int* level, float angle );
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
	/// レベルへのパス.
	/// </summary>
	int*		mLevel;
	/// <summary>
	/// 角度.
	/// </summary>
	float		mAngle;


}; // class Button end


#endif // CursorGUI end

/********** End of File ******************************************************/
