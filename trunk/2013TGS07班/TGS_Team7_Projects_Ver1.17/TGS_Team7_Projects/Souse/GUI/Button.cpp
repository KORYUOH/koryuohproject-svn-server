/******************************************************************************
* File Name : Button.cpp                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ユーザーインターフェースフレームクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Button.h"
#include"GUICommand.h"
#include"../Draw/Renderer.h"
#include"../Draw/TextureID.h"
#include"../Utility/ToString.h"



/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="collider">衝突情報</param>
/// <param name="flag">フラグ管理者.</param>
/// <param name="flagID">フラグID.</param>
/// <param name="textureID">テクスチャID.</param>
Button::Button( Collider& collider, IFlagManager& flag, FlagID flagID, TextureID textureID ):
	GUI( collider, flag, flagID ),
	mAnimation( textureID )
{
	mAnimation.AddCell( BoolToString(true), 0, 1, 32, 32 );
	mAnimation.AddCell( BoolToString(false), 1, 1, 32, 32 );
	mAnimation.Initialize();
}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームレート</param>
void Button::Update( float frameTimer )
{
	// アニメーションを更新する.
	mAnimation.Update( frameTimer, BoolToString(mCollider.mIsCollision) );

	// フラグを有効にする.
	FlagEnable();
}

/// <summary>
/// 描画.
/// </summary>
/// <param name="position">フレームの位置</param>
/// <param name="angle">角度</param>
void Button::Draw( const GSvector2& position, float angle ) const
{
	// 中心位置.
	GSvector2 center( mCollider.mRadius, mCollider.mRadius );

	// ボタンを描画.
	mAnimation.Draw( mCollider.mPosition+position, center, angle );
}

/********** End of File ******************************************************/
