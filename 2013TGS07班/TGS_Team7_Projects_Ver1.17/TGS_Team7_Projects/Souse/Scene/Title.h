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
#ifndef _TITLE_H_
#define _TITLE_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include	"../Scene\IScene.h"
#include	"../World/World.h"

/*---- 先行宣言 -------------------------------------------------------------*/

class World;
enum Scene;

/// <summary>
/// ゲームプレイシーンクラス.
/// </summary>
class Title : public IScene
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	Title();
	/// <summary>
	/// 初期化.
	/// </summary>
	virtual void Initialize();
	/// <summary>
	/// 更新.
	/// </summary>
	/// <param name="frameTimer">フレームタイマー</param>
	virtual void Update(float frameTimer);
	/// <summary>
	/// 描画.
	/// </summary>
	virtual void Draw();
	/// <summary>
	/// シーンの終了判定.
	/// </summary>
	/// <returns>シーンが終了していれば真、していなければ偽を返す</returns>
	virtual bool IsEnd() const;
	/// <summary>
	/// 次のシーンに移行.
	/// </summary>
	/// <returns>次のシーン列挙型を返す</returns>
	virtual Scene Next() const;
	/// <summary>
	/// 終了.
	/// </summary>
	virtual void Shutdown();


}; // class Title end

#endif

/********** End of File ******************************************************/
