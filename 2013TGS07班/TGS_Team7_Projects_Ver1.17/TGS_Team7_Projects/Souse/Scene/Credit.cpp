/******************************************************************************
* File Name : Credit.h                           Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		クレジットシーンクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include	"Credit.h"
#include	"../Utility\Screen.h"
#include	"../Scene\Scene.h"
#include<gslib.h>


/// <summary>
/// コンストラクタ.
/// </summary>
Credit::Credit()
{		 
}

/// <summary>
/// 初期化.
/// </summary>
void Credit::Initialize()
{	
}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void Credit::Update(float frameTimer)
{
	(void)frameTimer;
}

/// <summary>
/// 描画.
/// </summary>
void Credit::Draw()
{
}

/// <summary>
/// シーンの終了判定.
/// </summary>
bool Credit::IsEnd() const
{
	// シーンを終了しない
	return false;
}

/// <summary>
/// 次のシーンに移行.
/// </summary>
Scene Credit::Next() const
{
	// ダミーのシーンを返す
	return Scene::SCENE_TITLE;
}

/// <summary>
/// 終了.
/// </summary>
void Credit::Shutdown()
{
}

/********** End of File ******************************************************/
