/******************************************************************************
* File Name : GUIBarChart.cpp                    Ver : 1.00  Date : 2013-05-06
*
* Description :
*
*		棒グラフGUIクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"GUIBarChart.h"
#include"../Draw/Renderer.h"
#include"../Draw/TextureID.h"
#include"GUICommand.h"
#include"../Utility/SubVector.h"
#include"../Flag/FlagID.h"

/// <summary>
/// スケール倍率.
/// </summary>
const float GUIBarChart::SCALE_RATE = 0.5F;

/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="collider">衝突情報</param>
/// <param name="flagManager">フラグ管理者</param>
/// <param name="maxValue">値へのパス</param>
/// <param name="angle">角度</param>
/// <param name="color">色</param>
GUIBarChart::GUIBarChart( Collider& collider, IFlagManager& flagManager, float* value, float angle, const GScolor& color ) :
	GUI( collider, flagManager, FLAG_NONE ),
	mValue( value ),
	mAngle( angle ),
	mColor( color )
{
}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームレート</param>
void GUIBarChart::Update( float frameTimer )
{
	(void)frameTimer;
}

/// <summary>
/// 描画.
/// </summary>
/// <param name="position">フレームの位置</param>
/// <param name="angle">角度</param>
void GUIBarChart::Draw( const GSvector2& position, float angle ) const
{
	// 画像の中心.
	GSvector2 center( mCollider.mRadius, 0.0f );

	float value = *mValue * SCALE_RATE;

	// 描画位置.
	GSvector2 pos = GetFreamPositon( angle );

	// グラフの黒い部分を描画する.
	Renderer::GetInstance()->DrawTexture( TEXTURE_GUI_BAR_CHART, pos+position, center, mAngle+angle, GSvector2(1.0f,value), mColor );

}

/********** End of File ******************************************************/
