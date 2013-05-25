/******************************************************************************
* File Name : Star.cpp                           Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		惑星クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Star.h"
#include"../World/IWorld.h"
#include"../Draw/Renderer.h"
#include"../Input/InputState.h"
#include"Housing.h"
#include"Farm.h"
#include"Factory.h"
#include<algorithm>
#include"../GUI/Button.h"
#include"../GUI/GUICommand.h"
#include"../Utility/SubVector.h"
#include"../Flag/IFlagManager.h"

/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="world">ワールド</param>
/// <param name="flag">フラグ管理者</param>
/// <param name="parent">親ユニット</param>
///	 <param name="position">初期座標</param>
Star::Star( IWorld& world, IFlagManager& flag, Unit* parent, const GSvector2& position ):
	Unit( world, flag, parent, UNIT_STAR, position, gsGetTexture(TEXTURE_UNIT_STAR)->dwWidth/2 ),
	mHumanResources( 0 ),
	mFood( 0 ),
	mNumber( TEXTURE_GUI_NUMBER, 16, 32 )
{
	// 数字の表示桁数を設定.
	mNumber.SetField( 6 );

	// アニメーションを設定.
	mAnimation.SetTextureID( TEXTURE_UNIT_STAR );
	mAnimation.AddCell( "1", 0, 1, mCollder.mRadius*2, mCollder.mRadius*2 );
	mAnimation.Initialize();

	mElement.mGUIframe->AddWindow( mFlags );
	// 住宅施設ボタンを追加する.
	mElement.mGUIframe->AddGUI( std::make_shared<Button>( Collider( GSvector2(20.0f,20.0f),16.0f ), mFlags, FLAG_CREATE_HOUSING, TEXTURE_GUI_BOTTON_HOUSING ) );
	// 工場施設ボタンを追加する.
	mElement.mGUIframe->AddGUI( std::make_shared<Button>( Collider( GSvector2(80.0f,20.0f),16.0f ), mFlags, FLAG_CREATE_FACTORY, TEXTURE_GUI_BOTTON_FACTORY ) );
	// 農場施設ボタンを追加する.
	mElement.mGUIframe->AddGUI( std::make_shared<Button>( Collider( GSvector2(140.0f,20.0f),16.0f ), mFlags, FLAG_CREATE_FARM, TEXTURE_GUI_BOTTON_FRAM ) );

}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void Star::Update( float frameTimer ) 
{
	// アニメーションを更新する.
	mAnimation.Update( frameTimer, "1" );


	//mElement.mHuman = 0;
	// 人材の初期化.
	mElement.mHuman.Initialize();

	float humanMax = 0;
	float human = 0;

	std::for_each( mHierarchy.mChild.begin(), mHierarchy.mChild.begin(), [&]( Unit* unit )
	{
		if( mElement.mID == UNIT_HOUSING )
		{
			humanMax += unit->GetElement().mHuman.GetHumanMax();
		}
		human += unit->GetElement().mHuman.GetHuman();
	});

	mElement.mHuman.SetHumanMax( humanMax );
	mElement.mHuman.PersonnelChange( human );

	// コマンドから新たな施設を作る.
	CreateFacility();

}

/// <summary>
/// 生産処理.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void Star::Production( float frameTimer )
{
	(void)frameTimer;
}

/// <summary>
/// 維持コスト支払い処理.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void Star::Maintenance( float frameTimer )
{
	// 食料を減らす.
	mFood -= mElement.mHuman.GetHuman() * frameTimer * 0.005f;
	// マイナスになるのを防ぐ.
	mFood = MAX( mFood , 0 );
}

/// <summary>
/// 描画.
/// </summary>
void Star::Draw()
{


	// 中心位置.
	GSvector2 center( mCollder.mRadius, mCollder.mRadius );

	if( mCollder.mIsCollision )
	{
		// 点滅して描画する.
		mAnimation.DrawBlink( mCollder.mPosition , center );
	}
	else
	{
		// 普通に描画する.
		mAnimation.Draw( mCollder.mPosition , center );
	}

}


/// <summary>
/// UIの描画.
/// </summary>
void Star::DrawUI()
{
	/*---- 人材の最大値の描画 -----------------------------------------------*/

	// 人材.
	Renderer::GetInstance()->DrawTexture( TEXTURE_GUI_HUMAN_MAX , mCollder.mPosition+GSvector2(75.0f,0.0f) );
	// 数字を表示.
	mNumber.Draw( mCollder.mPosition+GSvector2(150.0f,10.0f) , (int)mElement.mHuman.GetHumanMax() );

	/*---- 人材の現在値の描画 -----------------------------------------------*/

	// 人材.
	Renderer::GetInstance()->DrawTexture( TEXTURE_GUI_HUMAN , mCollder.mPosition+GSvector2(75.0f,40.0f) );
	// 数字を表示.
	mNumber.Draw( mCollder.mPosition+GSvector2(150.0f,40.0f) , (int)mElement.mHuman.GetHuman() );

	/*---- 食料の現在値の描画 -----------------------------------------------*/

	// 食料.
	Renderer::GetInstance()->DrawTexture( TEXTURE_GUI_FOOD, mCollder.mPosition+GSvector2(75.0f,80.0f) );
	// 数字を表示.
	mNumber.Draw( mCollder.mPosition+GSvector2(150.0f,80.0f), (int)mFood );
}

/// <summary>
/// 食料へのアクセス.
/// </summary>
/// <param name="food">食料の増減量</param>
/// <returns>正常にアクセスできれば真、できなければ偽を返す.</returns>
bool Star::AccessFood( float food )
{
	float rezultFood = mFood + food;

	if( rezultFood < 0.0f )
	{
		return false;
	}

	// 結果を反映する.
	mFood = rezultFood;

	return true;
}

/// <summary>
/// 資金へのアクセス.
/// </summary>
/// <param name="money">資金の増減量</param>
/// <returns>正常にアクセスできれば真、できなければ偽を返す.</returns>
bool Star::AccessMoney( float money )
{
	// 資金を宇宙へ送る.
	return mHierarchy.mParent->AccessMoney( money );
}

/// <summary>
/// 人材へのアクセス.
/// </summary>
/// <param name="human">人の増減量</param>
/// <returns>正常にアクセスできれば真、できなければ偽を返す.</returns>
bool Star::AccessHuman( float human )
{
	for( std::list<Unit*>::iterator it = mHierarchy.mChild.begin() ; it != mHierarchy.mChild.end() ; it++  )
	{
		// 型の置きなおし.
		Unit* unit = *it;

		// ユニットが住宅施設の時.
		if( unit->GetElement().mID == UNIT_HOUSING )
		{
			// 人材にアクセス.
			if( unit->AccessHuman( human ) )
			{
				// アクセスできたので真を返す.
				return true;
			}
		}
	}

	// 住宅施設がないためアクセスに失敗しました.
	return false;

}

/// <summary>
/// 施設の作成.
/// </summary>
void Star::CreateFacility()
{
	// 施設の最大値.
	const int FACILITY_MAX = 8;
	// 角度の最大値.
	const int ANGLE_MAX = 360;

	// 施設の最大値を超えていた時.
	if( mHierarchy.mChild.size() >= FACILITY_MAX )
	{
		// 早期終了.
		return;
	}

	// 現在個数と最大値から次の施設の角度を求める.
	float angle = mHierarchy.mChild.size() * (ANGLE_MAX / FACILITY_MAX) - 90.0f;

	// 施設を作成する.
	CreateHousing( angle );
	CreateFactory( angle );
	CreateFarm( angle );

}

/// <summary>
/// 住宅施設の作成.
/// </summary>
/// <param name="angle">角度</param>
void Star::CreateHousing( float angle )
{
	// 住宅施設を作成.
	if( mFlags.IsFlag( FLAG_CREATE_HOUSING ) )
	{
		UnitPtr unit = std::make_shared<Housing>
			( mWorld, mFlags, &*this, mCollder, angle );
		// 住宅施設を追加.
		AddUnit( UNIT_HOUSING, unit );
		// フラグを無効にする.
		mFlags.FlagDisable( FLAG_CREATE_HOUSING );
	}
}

/// <summary>
/// 施設の作成.
/// </summary>
/// <param name="angle">角度</param>
void Star::CreateFactory( float angle )
{
	// 工場施設を作成.
	if( mFlags.IsFlag( FLAG_CREATE_FACTORY ) )
	{
		UnitPtr unit = std::make_shared<Factory>
			( mWorld, mFlags, &*this, mCollder, angle );
		// 工場施設を追加.
		AddUnit( UNIT_FACTORY, unit );
		// フラグを無効にする.
		mFlags.FlagDisable( FLAG_CREATE_FACTORY );
	}
}

/// <summary>
/// 農場施設の作成.
/// </summary>
/// <param name="angle">角度</param>
void Star::CreateFarm( float angle )
{
	// 農場施設を作成.
	if( mFlags.IsFlag( FLAG_CREATE_FARM ) )
	{
		UnitPtr unit = std::make_shared<Farm>
			( mWorld, mFlags, &*this, mCollder, angle);
		// 農場施設を追加.
		AddUnit( UNIT_FARM, unit );
		// フラグを無効にする.
		mFlags.FlagDisable( FLAG_CREATE_FARM );

	}
}

/********** End of File ******************************************************/
