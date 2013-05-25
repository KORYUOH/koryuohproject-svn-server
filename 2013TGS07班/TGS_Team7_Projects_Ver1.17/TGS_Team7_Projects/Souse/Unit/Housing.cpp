/******************************************************************************
* File Name : Housing.CPP                        Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		住宅施設クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Housing.h"
#include"../World/IWorld.h"
#include"../Draw/Renderer.h"
#include"../Input/InputState.h"
#include"../GUI/Button.h"
#include"../GUI/GUILevel.h"
#include"../GUI/GUIBarChart.h"
#include"../Utility/SubVector.h"
#include"../Flag/IFlagManager.h"

	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="world">ワールド</param>
	/// <param name="flag">フラグ管理者</param>
	/// <param name="parent">親ユニット</param>
	///	 <param name="collider">星の衝突情報</param>
	/// <param name="angle">星から見た角度</param>
Housing::Housing( IWorld& world, IFlagManager& flag, Unit* parent, const Collider& collider, float angle ):
	Unit( world, flag, parent, UNIT_HOUSING , collider.mPosition, collider.mRadius ),
	mNumber( TEXTURE_GUI_NUMBER , 10,16 ),
	mAngle( angle+90.0f )
{
	// 数字の表示桁数を設定.
	mNumber.SetField( 6 );

	// 人材の最大値を取得する.
	mElement.mHuman.SetHumanMax( mWorld.GetParameter().GetHumanMax( mElement ) );


	// アニメーションを設定.
	mAnimation.SetTextureID( TEXTURE_UNIT_HOUSE );
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
void Housing::Update( float frameTimer )
{
	mAnimation.Update( frameTimer , "1" );
}

/// <summary>
/// 生産処理.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void Housing::Production( float frameTimer )
{
	// 人材が定員に達している時.
	if( mElement.mHuman.IsHumanCapacity() )
	{
		return;
	}

	// 増加数を計算.
	float productionHuman = mWorld.GetParameter().GetProduction(mElement) * frameTimer;

	// 住宅施設に人を増加させる.
	mElement.mHuman.PersonnelChange( productionHuman );

}

/// <summary>
/// 維持コスト支払い処理.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void Housing::Maintenance( float frameTimer )
{
	(void)frameTimer;
}

/// <summary>
/// 描画.
/// </summary>
void Housing::Draw()
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
void Housing::DrawUI()
{}

/********** End of File ******************************************************/
