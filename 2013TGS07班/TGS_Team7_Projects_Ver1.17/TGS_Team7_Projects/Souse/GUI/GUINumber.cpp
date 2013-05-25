/******************************************************************************
* File Name : IUI.cpp                            Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ユーザーインターフェースフレームクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"GUINumber.h"
#include"../Draw/Renderer.h"
#include"../Draw/TextureID.h"
#include"../Utility/ToString.h"
#include"../Flag/FlagID.h"

/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="collider">衝突情報</param>
/// <param name="flagManager">フラグ管理者</param>
/// <param name="drawNumber">描画する数字へのパス</param>
GUINumber::GUINumber( Collider& collider, IFlagManager& flagManager, float* drawNumber  ) :
	GUI( collider, flagManager, FLAG_NONE ),
	mNumber( drawNumber ),
	mDrawNumber( TEXTURE_GUI_NUMBER, 10, 16 )
{
}


/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームレート</param>
void GUINumber::Update( float frameTimer )
{
}

/// <summary>
/// 描画.
/// </summary>
/// <param name="position">フレームの位置</param>
/// <param name="angle">角度</param>
void GUINumber::Draw( const GSvector2& position, float angle ) const
{
	(void)position;
	(void)angle;

	// 画像の中心.
	const GSvector2 center( -mCollider.mRadius, -mCollider.mRadius );

	// ボタンを描画.
	//mNumber.Draw( 
}

/********** End of File ******************************************************/
