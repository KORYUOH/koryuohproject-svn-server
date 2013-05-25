/******************************************************************************
* File Name : Factory.cpp                        Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		工場施設クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Factory.h"
#include"../World/IWorld.h"
#include"../Draw/Renderer.h"
#include"../Utility/ToString.h"
#include"../GUI/Button.h"
#include"../Utility/SubVector.h"
#include"../GUI/GUILevel.h"
#include"../GUI/GUIBarChart.h"
#include"../Flag/FlagID.h"

	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="world">ワールド</param>
	/// <param name="flag">フラグ管理者</param>
	/// <param name="parent">親ユニット</param>
	///	 <param name="collider">星の衝突情報</param>
	/// <param name="angle">星から見た角度</param>
Factory::Factory( IWorld& world, IFlagManager& flag, Unit* parent, const Collider& collider, float angle ):
	Unit( world, flag, parent, UNIT_FACTORY , collider.mPosition, collider.mRadius ),
	mNumber( TEXTURE_GUI_NUMBER , 10,16 ),
	mAngle( angle+90.0f )
{
	// 数字の表示桁数を設定.
	mNumber.SetField( 6 );

	// 人材の最大値を取得する.
	mElement.mHuman.SetHumanMax( mWorld.GetParameter().GetHumanMax(mElement) );

	// アニメーションを設定.
	mAnimation.SetTextureID( TEXTURE_UNIT_FACTORY );
	mAnimation.AddCell( "1", 0, 1, 64, 64 );
	mAnimation.Initialize();

	// 位置を設定.
	float radius = gsGetTexture( TEXTURE_UNIT_HOUSE )->dwHeight / 2;
	mCollder.mPosition = mCollder.mPosition + Velocity( angle, mCollder.mRadius+radius);
	mCollder.mRadius = radius;

	// 操作衝突しないGUIを設定
	GSvector2 vec = Velocity( angle, mCollder.mRadius*2.0f );
	GUIFramePtr guiFrame = std::make_shared<GUIFrame>( vec+mCollder.mPosition, mAngle );
	guiFrame->AddGUI( std::make_shared<GUILevel>( Collider(GSvector2(-12.0f,0.0f),8.0f), mFlags, &mElement.mLevel, mAngle ) );
	//guiFrame->AddGUI( std::make_shared<GUIBarChart>( Collider(GSvector2(0.0f,0.0f), 8.0f), mFlags, &mElement.mHumanMax, 180.0f, GScolor(0.0f,1.0f,1.0f,1.0f) ) ); 
	//guiFrame->AddGUI( std::make_shared<GUIBarChart>( Collider(GSvector2(0.0f,0.0f), 8.0f), mFlags, &mElement.mHuman, 180.0f, GScolor(1.0f,0.0f,0.0f,1.0f) ) ); 
	mWorld.AddGUI( guiFrame );

	// GUIを追加
	// 人材移動ボタンを追加する.
	mElement.mGUIframe->AddGUI( std::make_shared<Button>( Collider( GSvector2(20.0f,20.0f),16.0f ), mFlags, FLAG_HUMAN_MUVEMENT, TEXTURE_GUI_BUTTON) );
	// レベルアップボタンを追加する.
	mElement.mGUIframe->AddGUI( std::make_shared<Button>( Collider( GSvector2(60.0f,20.0f),16.0f ), mFlags, FLAG_FACILITY_LEVEL_UP, TEXTURE_GUI_BOTTON_LEVEL_UP) );
	mElement.mGUIframe->AddWindow( mFlags );
}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void Factory::Update( float frameTimer )
{
	mAnimation.Update( frameTimer, "1" );
	//mAnimation.Update( frameTimer, IntToString( mElement.mLevel ) );

}

/// <summary>
/// 生産処理.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void Factory::Production( float frameTimer )
{
	// 資金を生産する.
	mHierarchy.mParent->AccessMoney( mWorld.GetParameter().GetProduction( mElement ) * frameTimer );
}

/// <summary>
/// 維持コスト支払い処理.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void Factory::Maintenance( float frameTimer )
{
	// 維持コスト(資金を払う)
	if( !mHierarchy.mParent->AccessMoney( -mWorld.GetParameter().GetCost(mElement) * frameTimer ) )
	{
		// 資金が支払えないのでレベルを下げる.
		LevelDown();
	}
}

/// <summary>
/// 描画.
/// </summary>
void Factory::Draw()
{
	// 画像の中心点.
	const GSvector2 center( mCollder.mRadius,mCollder.mRadius );

	// 衝突している時.
	if( mCollder.mIsCollision )
	{
		// 点滅して描画する.
		mAnimation.DrawBlink( mCollder.mPosition, center, mAngle );
	}
	else
	{
		// 普通に描画する.
		mAnimation.Draw( mCollder.mPosition, center, mAngle );
	}
}

/// <summary>
/// UIの描画.
/// </summary>
void Factory::DrawUI()
{
}


/********** End of File ******************************************************/
