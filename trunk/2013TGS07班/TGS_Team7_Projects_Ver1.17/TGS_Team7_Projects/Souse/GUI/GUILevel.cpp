/******************************************************************************
* File Name : GUILevel.cpp                        Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		レベルGUIクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"GUILevel.h"
#include"../Draw/Renderer.h"
#include"../Draw/TextureID.h"
#include"GUICommand.h"
#include"../Utility/SubVector.h"
#include"../Flag/FlagID.h"

	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="collider">衝突情報</param>
	/// <param name="flagManager">フラグ管理者</param>
	/// <param name="level">レベルへのパス</param>
	/// <param name="angle">角度</param>
GUILevel::GUILevel( Collider& collider, IFlagManager& flagManager, int* level, float angle ) :
	GUI( collider, flagManager, FLAG_NONE ),
	mLevel( level ),
	mAngle( angle )
{
}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームレート</param>
void GUILevel::Update( float frameTimer )
{
	(void)frameTimer;
}

/// <summary>
/// 描画.
/// </summary>
/// <param name="position">フレームの位置</param>
/// <param name="angle">角度</param>
void GUILevel::Draw( const GSvector2& position, float angle ) const
{
	// 画像の中心.
	GSvector2 center( mCollider.mRadius, mCollider.mRadius );

	// 描画位置の修正量
	GSvector2 vec = Velocity( mAngle-90.0f, mCollider.mRadius*2.0f );

	// 描画位置.
	//GSvector2 pos( mCollider.mPosition );

	// 描画位置.
	GSvector2 pos = GetFreamPositon( angle );

	// レベルの個数繰り返す.
	for( int i = 0 ; i < *mLevel ; i++ )
	{
		// 描画する.
		Renderer::GetInstance()->DrawTexture( TEXTURE_GUI_LEVEL, pos+position, center, mAngle+angle );

		// 位置をずらす.
		pos += vec;
	}

}

/********** End of File ******************************************************/
