/******************************************************************************
* File Name : GUIFrame.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ユーザーインターフェースフレームクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_FRAME_H_
#define _GUI_FRAME_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include"GUIPtr.h"
#include"../Collider/Collider.h"
#include"../Flag/IFlagManager.h"
#include<memory>

/*---- 先行宣言 -------------------------------------------------------------*/


/// <summary>
/// UIフレームクラス.
/// </summary>
class GUIFrame
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	GUIFrame();
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="position">フレームの中央座標</param>
	/// <param name="angle">角度</param>
	GUIFrame( const GSvector2& position, float angle );
	/// <summary>
	/// UIを追加する.
	/// </summary>
	/// <param name="addUI">追加するUI</param>
	void AddGUI( GUIPtr addUI );
	/// <summary>
	/// ウインドウを追加する.
	/// </summary>
	/// <param name="frameTimer">フラグ管理者</param>
	void AddWindow( IFlagManager& flagManager );
	/// <summary>
	/// 更新.
	/// </summary>
	/// <param name="frameTimer">フレームレート</param>
	void Update( float frameTimer );
	/// <summary>
	/// 描画.
	/// </summary>
	void Draw() const;
	/// <summary>
	/// コマンドを取得.
	/// </summary>
	void RangeExpansion( Collider& collider );
	/// <summary>
	/// 衝突の更新.
	/// </summary>
	/// <param name="other">衝突相手GUI</param>
	void CollisionUpdate( GUIFrame& other );
	/// <summary>
	/// 衝突の更新.
	/// </summary>
	/// <param name="other">衝突情報</param>
	void CollisionUpdate( GUI& other );
	/// <summary>
	/// フラグの無効化.
	/// </summary>
	void FlagDisable();

private:
	/// <summary>
	/// GUIコンテナ.
	/// </summary>
	GUIContainer	mGUIs;
	/// <summary>
	/// フレームの位置.
	/// </summary>
	GSvector2		mPosition;
	/// <summary>
	/// 角度.
	/// </summary>
	float			mAngle;
	/// <summary>
	/// GUIの範囲.
	/// </summary>
	GSrect			mRange;
	/// <summary>
	/// ウインドウフラグ.
	/// </summary>
	bool			mIsWindow;
};

#endif // _GUI_FRAME_H_ end

/********** End of File ******************************************************/
