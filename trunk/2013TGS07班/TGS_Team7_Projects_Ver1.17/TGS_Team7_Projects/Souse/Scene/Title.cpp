/******************************************************************************
* File Name : Title.h                           Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		タイトルシーンクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include	"Title.h"
#include	"../Utility\Screen.h"
#include	"../Scene\Scene.h"
#include<gslib.h>
#include"../Input/InputState.h"
#include"../Draw/Renderer.h"


/// <summary>
/// コンストラクタ.
/// </summary>
Title::Title()
{		 
}

/// <summary>
/// 初期化.
/// </summary>
void Title::Initialize()
{	
	mIsEnd = false;

	// タイトル画像の読み込み.
	Renderer::GetInstance()->LoadTexture( TEXTURE_SCENE_TITLE, "Resouse/Title.bmp" );
}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void Title::Update(float frameTimer)
{
	(void)frameTimer;

	if( InputState::GetInstance()->IsReStart() )
	{
		mIsEnd = true;
	}
}

/// <summary>
/// 描画.
/// </summary>
void Title::Draw()
{
	Renderer::GetInstance()->DrawTexture( TEXTURE_SCENE_TITLE );
}

/// <summary>
/// シーンの終了判定.
/// </summary>
bool Title::IsEnd() const
{
	// シーンを終了しない
	return mIsEnd;
}

/// <summary>
/// 次のシーンに移行.
/// </summary>
Scene Title::Next() const
{
	// ダミーのシーンを返す
	return Scene::SCENE_GAMEPLAY;
}

/// <summary>
/// 終了.
/// </summary>
void Title::Shutdown()
{
	// タイトル画像の読み込み.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_SCENE_TITLE );
}

/********** End of File ******************************************************/
