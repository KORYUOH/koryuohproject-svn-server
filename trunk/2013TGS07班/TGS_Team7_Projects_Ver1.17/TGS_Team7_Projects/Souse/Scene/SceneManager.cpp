/******************************************************************************
* File Name : SceneManager.cpp                   Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		シーン管理クラス．
*
******************************************************************************/
#include"SceneManager.h"
#include"IScene.h"
#include"SceneNull.h"

/// <summary>
/// コンストラクタ.
/// </summary>
SceneManager::SceneManager():
	currentScene( std::make_shared<SceneNull>() )
{
}

/// <summary>
/// シーンの追加.
/// </summary>
/// <param name="name">登録するのシーン列挙</param>
/// <param name="scene">登録するのシーン情報</param>
void SceneManager::Add( Scene name, IScene* scene)
{
	//引数でもらったシーンを追加する
	scenes[name] = IScenePtr(scene);

}

/// <summary>
/// シーンの追加.
/// </summary>
/// <param name="name">登録するのシーン列挙</param>
/// <param name="scene">登録するのシーン情報</param>
void SceneManager::Add( Scene name, IScenePtr scene)
{
	scenes[name] = scene;
}

/// <summary>
/// 初期化.
/// </summary>
void SceneManager::Initialize()
{
	Shutdown();
	// シーンの要素を空にする
	scenes.clear();
}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void SceneManager::Update(float frameTimer)
{

	// 現在のシーンを更新する
	currentScene->Update(frameTimer);

	// 現在のシーンが終了しているか？
	if( currentScene->IsEnd() == true )
	{
		// 次のシーンに変更する
		Change( currentScene->Next() );
	}

}

/// <summary>
/// 描画.
/// </summary>
void SceneManager::Draw()
{

	// 現在のシーンを描画する
	currentScene->Draw();

}

/// <summary>
/// シーンの変更
/// </summary>
/// <param name="name">次のシーン列挙</param>
void SceneManager::Change(Scene name)
{
	// 現在のシーンを終了する
	Shutdown();
	// 現在のシーンを引数のシーンに変更する
	currentScene = scenes[name];
	// 現在のシーンを初期化する
	currentScene->Initialize();

}

/// <summary>
/// 終了.
/// </summary>
void SceneManager::Shutdown()
{
	// 現在のシーンを終了する
	currentScene->Shutdown();
	// 現在のシーンをヌルポインタを入れる
	currentScene = std::make_shared<SceneNull>();
}

/********** End of File ******************************************************/
