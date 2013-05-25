/******************************************************************************
* File Name : Space.cpp                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		宇宙クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Space.h"
#include"../World/IWorld.h"
#include"../Draw/Renderer.h"
#include"../Input/InputState.h"
#include"../Unit/Star.h"
#include"../Utility/Screen.h"

/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="world">ワールド</param>
/// <param name="flag">フラグ管理者</param>
///	 <param name="position">初期座標</param>
/// <param name="radius">衝突判定用の半径</param>
Space::Space( IWorld& world, IFlagManager& flag, const GSvector2& position, float radius ):
	Unit( world, flag, NULL , UNIT_SPACE, position, radius ),
	mManey( 0.0f ),
	mNumber( TEXTURE_GUI_NUMBER, 16, 32 ) 
{
	/// 初期の資金を設定.
	mManey = 10000;

	// 星を追加.
	AddUnit( UNIT_STAR , std::make_shared<Star>( mWorld, mFlags, &*this, GSvector2(Screen::WIDTH*0.5f,Screen::HEIGHT*0.5f) ) );
}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void Space::Update( float frameTimer ) 
{
	(void)frameTimer;
}

/// <summary>
/// 生産処理.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void Space::Production( float frameTimer )
{
	(void)frameTimer;
}

/// <summary>
/// 維持コスト支払い処理.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void Space::Maintenance( float frameTimer )
{
	(void)frameTimer;
}

/// <summary>
/// 描画.
/// </summary>
void Space::Draw()
{
	Renderer::GetInstance()->DrawTexture( TEXTURE_UNIT_SPACE );
}

/// <summary>
/// UIの描画.
/// </summary>
void Space::DrawUI()
{
	const GSvector2 center( 256.0f , 0.0f );

	Renderer::GetInstance()->DrawTexture( TEXTURE_GUI_MONEY, center  );
	mNumber.Draw( center+GSvector2(64.0f,0.0f), (int)mManey );
}

/// <summary>
/// 資金へのアクセス.
/// </summary>
/// <param name="money">資金の増減量</param>
/// <returns>正常にアクセスできれば真、できなければ偽を返す.</returns>
bool Space::AccessMoney( float money )
{
	// 資金を計算する.
	float rezultMoney = mManey + money;

	// 資金がゼロ以下になった時.
	if( rezultMoney < 0.0f )
	{
		return false;
	}
	// ゼロでない時、結果を反映する.
	mManey = rezultMoney;

	return true;
}



/********** End of File ******************************************************/
