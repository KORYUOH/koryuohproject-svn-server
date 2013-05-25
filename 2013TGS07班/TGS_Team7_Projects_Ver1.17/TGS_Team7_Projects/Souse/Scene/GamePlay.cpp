/******************************************************************************
* File Name : GamePlay.cpp                       Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		ゲームプレイシーンクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include	"GamePlay.h"
#include<gslib.h>
#include	"../Scene\Scene.h"
#include"../Unit/Player.h"
#include"../Unit/Space.h"
#include"../Draw/Renderer.h"
#include"../Input/InputState.h"


/// <summary>
/// コンストラクタ.
/// </summary>
GamePlay::GamePlay():
	mWorld(),
	mFlagManager()
{		 
}

/// <summary>
/// 初期化.
/// </summary>
void GamePlay::Initialize()
{	
	// シーン終了フラグを初期化.
	mIsEnd = false;

	// ワールドの初期化.
	mWorld.Clear();
	// フラグ管理者の初期化.
	mFlagManager.Initialize();

	/*---- キャラクター画像ID -----------------------------------------------*/

	// 画像の読み込み.
	// プレイヤー画像の読み込み.
	Renderer::GetInstance()->LoadTexture( TEXTURE_UNIT_PLAYER , "Resouse/Player.bmp" , true );
	Renderer::GetInstance()->LoadTexture( TEXTURE_UNIT_PLAYER2 , "Resouse/Player2.bmp" , true );

	/*---- 施設画像の読み込み -----------------------------------------------*/

	// 宇宙画像の読み込み.
	Renderer::GetInstance()->LoadTexture( TEXTURE_UNIT_SPACE , "Resouse/Space.bmp" , true );
	// 宇宙画像の読み込み.
	Renderer::GetInstance()->LoadTexture( TEXTURE_UNIT_STAR , "Resouse/Star.bmp" , true );
	// 農場施設画像の読み込み.
	Renderer::GetInstance()->LoadTexture( TEXTURE_UNIT_FARM , "Resouse/Farm.bmp" , true );
	// 住宅施設画像の読み込み.
	Renderer::GetInstance()->LoadTexture( TEXTURE_UNIT_HOUSE , "Resouse/House.bmp" , true );
	// 工場施設画像の読み込み.
	Renderer::GetInstance()->LoadTexture( TEXTURE_UNIT_FACTORY, "Resouse/Factory.bmp" , true );

	/*---- UI系画像の読み込み -----------------------------------------------*/

	// タイマー画像の読み込み.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_TIMER, "Resouse/Timer.bmp" ,true );
	// 資金画像の読み込み.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_MONEY, "Resouse/Money.bmp" ,true );
	// 人材画像の読み込み.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_HUMAN, "Resouse/Human.bmp" ,true );
	// 人材最大画像の読み込み.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_HUMAN_MAX, "Resouse/HumanMax.bmp", true );
	// 食料画像の読み込み.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_FOOD, "Resouse/Food.bmp" ,true );
	// レベル画像の読み込み.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_LEVEL, "Resouse/Level.bmp" ,true );
	// 数字画像の読み込み.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_NUMBER, "Resouse/Number.bmp" , true );

	// GUIのフレーム画像を読み込む.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_FRAME, "Resouse/UIFrame.bmp" );
	// GUIのボタン画像を読み込む.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_BUTTON, "Resouse/Button.bmp", true );
	// GUIの閉じるボタン画像を読み込む.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_BOTTON_CLOSE, "Resouse/ButtonClose.bmp", true );
	// GUIのレベルアップボタン画像を読み込む.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_BOTTON_LEVEL_UP, "Resouse/ButtonLevelUp.bmp", true );
	// GUIの住宅作成ボタン画像を読み込む.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_BOTTON_HOUSING, "Resouse/ButtonHouse.bmp", true );
	// GUIの工場作成ボタン画像を読み込む.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_BOTTON_FACTORY, "Resouse/ButtonFactory.bmp", true );
	// GUIの農場作成ボタン画像を読み込む.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_BOTTON_FRAM, "Resouse/ButtonFarm.bmp", true );
	// GUI棒グラフ画像の読み込み
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_BAR_CHART, "Resouse/BarChart.bmp" );

	/*---- その他画像の読み込み ---------------------------------------------*/

	// デバッグ画像の読み込み.
	Renderer::GetInstance()->LoadTexture( TEXTURE_DEBUG , "Resouse/Debug.bmp" , true ); 

	/*---- 読み込みの終了ID -------------------------------------------------*/



	// Playerを追加する
	mWorld.AddPlayer( std::make_shared<Player>( mWorld, mFlagManager, GSvector2(500.0f,100.0f) ) );
	mWorld.Add( UNIT_SPACE, std::make_shared<Space>( mWorld, mFlagManager, GSvector2(0.0f,0.0f), 0.0f ) );
}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void GamePlay::Update( float frameTimer )
{
	// 世界を更新.
	mWorld.Update( frameTimer );

	if( InputState::GetInstance()->IsReStart() )
	{
		mIsEnd = true;
	}
}

/// <summary>
/// 描画.
/// </summary>
void GamePlay::Draw()
{
	// 世界を描画.
	mWorld.Draw();

	// 世界のUIを描画.
	mWorld.DrawUI();
}

/// <summary>
/// シーンの終了判定.
/// </summary>
bool GamePlay::IsEnd() const
{
	// シーンを終了しない
	return mIsEnd;
}

/// <summary>
/// 次のシーンに移行.
/// </summary>
Scene GamePlay::Next() const
{
	// ダミーのシーンを返す
	return Scene::SCENE_TITLE;
}

/// <summary>
/// 終了.
/// </summary>
void GamePlay::Shutdown()
{
	mWorld.Clear();

	// 画像の開放.
	// プレイヤー画像の読み込み.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_UNIT_PLAYER );
	Renderer::GetInstance()->DeleteTexture( TEXTURE_UNIT_PLAYER2 );

	/*---- 施設画像の読み込み -----------------------------------------------*/

	// 宇宙画像の読み込み.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_UNIT_SPACE );
	// 宇宙画像の読み込み.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_UNIT_STAR );
	// 農場施設画像の読み込み.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_UNIT_FARM );
	// 住宅施設画像の読み込み.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_UNIT_HOUSE );
	// 工場施設画像の読み込み.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_UNIT_FACTORY );

	/*---- UI系画像の読み込み -----------------------------------------------*/

	// タイマー画像の読み込み.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_TIMER );
	// 資金画像の読み込み.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_MONEY );
	// 人材画像の読み込み.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_HUMAN );
	// 人材最大画像の読み込み.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_HUMAN_MAX );
	// 食料画像の読み込み.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_FOOD );
	// レベル画像の読み込み.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_LEVEL );
	// 数字画像の読み込み.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_NUMBER );

	// GUIのフレーム画像を読み込む.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_FRAME );
	// GUIのボタン画像を読み込む.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_BUTTON );
	// GUIの閉じるボタン画像を読み込む.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_BOTTON_CLOSE );
	// GUIのレベルアップボタン画像を読み込む.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_BOTTON_LEVEL_UP );
	// GUIの住宅作成ボタン画像を読み込む.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_BOTTON_HOUSING );
	// GUIの工場作成ボタン画像を読み込む.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_BOTTON_FACTORY );
	// GUIの農場作成ボタン画像を読み込む.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_BOTTON_FRAM );
	// GUI棒グラフ画像の読み込み
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_BAR_CHART );

	/*---- その他画像の読み込み ---------------------------------------------*/

	// デバッグ画像の読み込み.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_DEBUG ); 

}

/********** End of File ******************************************************/
