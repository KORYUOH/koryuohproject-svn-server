/******************************************************************************
* File Name : SceneNull.cpp                      Ver : 1.00  Date : 2013-02-06
*
* Description :
*
*		空のシーンクラス．
*
******************************************************************************/
#include	"SceneNull.h"
#include	"Scene.h"

/// <summary>
/// コンストラクタ.
/// </summary>
SceneNull::SceneNull()
{
}

/// <summary>
/// 初期化.
/// </summary>
void SceneNull::Initialize()
{
}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void SceneNull::Update(float frameTimer)
{
	//引数を無効化する
	(void)frameTimer;
}

/// <summary>
/// 描画.
/// </summary>
void SceneNull::Draw()
{
}

/// <summary>
/// シーンの終了判定.
/// </summary>
bool SceneNull::IsEnd() const
{
	//シーンを終了しない
	return false;
}

/// <summary>
/// 次のシーンに移行.
/// </summary>
Scene SceneNull::Next() const
{
	//ダミーのシーンを返す
	return SCENE_NONE;
}

/// <summary>
/// 終了.
/// </summary>
void SceneNull::Shutdown()
{
}

/********** End of File ******************************************************/
