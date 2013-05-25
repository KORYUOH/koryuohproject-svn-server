/******************************************************************************
* File Name : Ranking.cpp                         Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ランキングシーン．
*
******************************************************************************/
#include	"Ranking.h"
#include	"../Utility\Screen.h"
#include	"Scene.h"


/// <summary>
/// コンストラクタ.
/// </summary>
Ranking::Ranking()
{	
}

/// <summary>
/// 初期化.
/// </summary>
void Ranking::Initialize()
{	
}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void Ranking::Update(float frameTimer)
{
	(void)frameTimer;
}

/// <summary>
/// 描画.
/// </summary>
void Ranking::Draw()
{
}

/// <summary>
/// シーンの終了判定.
/// </summary>
bool Ranking::IsEnd() const
{
	// シーンを終了しない
	return false;
}

/// <summary>
/// 次のシーンに移行.
/// </summary>
Scene Ranking::Next() const
{
	// ダミーのシーンを返す
	return Scene::SCENE_TITLE;
}

/// <summary>
/// 終了.
/// </summary>
void Ranking::Shutdown()
{
}

/********** End of File ******************************************************/
