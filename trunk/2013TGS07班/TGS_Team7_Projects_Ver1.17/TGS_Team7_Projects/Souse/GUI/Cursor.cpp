/******************************************************************************
* File Name : Cursor.cpp                            Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		カーソルGUIクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Cursor.h"
#include"../Draw/Renderer.h"
#include"../Draw/TextureID.h"
#include"GUICommand.h"
#include"../Utility/ToString.h"
#include"../Flag/FlagID.h"

	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="collider">衝突情報</param>
	/// <param name="flagManager">フラグ管理者</param>
	/// <param name="position">位置情報</param>
CursorGUI::CursorGUI( Collider& collider, IFlagManager& flagManager, const GSvector2* position ) :
	GUI( collider, flagManager, FLAG_NONE ),
	mAnimation( TEXTURE_UNIT_PLAYER ),
	mPosition( position )
{
	mAnimation.AddCell( "1", 0, 1,32, 32 );
	mAnimation.Initialize();
}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームレート</param>
void CursorGUI::Update( float frameTimer )
{
	// 位置を更新する.
	mCollider.mPosition = *mPosition;

	// アニメーションを更新する.
	mAnimation.Update( frameTimer, "1" );
}

/// <summary>
/// 描画.
/// </summary>
/// <param name="position">フレームの位置</param>
/// <param name="angle">角度</param>
void CursorGUI::Draw( const GSvector2& position, float angle ) const
{
	// 画像の中心.
	GSvector2 center( mCollider.mRadius, mCollider.mRadius );

	// ボタンを描画.
	mAnimation.Draw( mCollider.mPosition+position, center, angle );
}

/********** End of File ******************************************************/
