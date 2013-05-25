/******************************************************************************
* File Name : ShootingApplication.cpp.cpp         Ver : 1.00  Date : 2012-12-13
*
* Description :
*
*		シューティングアプリケーション処理．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"ShootingApplication.h"
#include"../Utility/Screen.h"
#include"../Scene\Scene.h"
#include"../Scene\GamePlay.h"
#include"../Scene/Title.h"
// シェアードポインタ用のインクルード.
#include<algorithm>

/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="argc">コマンドラインオプションの数のポインタ</param>
/// <param name="argv">コマンドラインオプションを表す文字列の配列</param>
ShootingApplication::ShootingApplication(int argc,char *argv[]):
	GameApplication( argc, argv )
{
	//画面のサイズ設定.
	SetWindowWidth( Screen::WIDTH );
	SetWindowHeight( Screen::HEIGHT );

	// フルスクリーンに設定する.
	//SetFullScreenMode( true );
}

/// <summary>
/// 初期化.
/// </summary>
void ShootingApplication::Initialize( void )
{
	// シーン管理者の初期化
	mSceneManager.Initialize();
	mSceneManager.Add( SCENE_TITLE, std::make_shared<Title>() );
	// ゲームプレイシーンを追加する.
	mSceneManager.Add( SCENE_GAMEPLAY, std::make_shared<GamePlay>() );
	// 現在のシーンをタイトルシーンに変更する.
	mSceneManager.Change( SCENE_TITLE );
}

/// <summary>
// 更新.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void ShootingApplication::Update( float frameTimer )
{
	// シーンを更新する.
	mSceneManager.Update( frameTimer );
}

/// <summary>
// 描画.
/// </summary>
void ShootingApplication::Draw( void )
{
	// シーンを描画する.
	mSceneManager.Draw();
}

/// <summary>
// 終了.
/// </summary>
void ShootingApplication::Finish( void )
{
	mSceneManager.Shutdown();
}

/********** End of File ******************************************************/
