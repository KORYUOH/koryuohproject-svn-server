/******************************************************************************
* File Name : Ranking.h                         Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ランキングシーン．
*
******************************************************************************/
#ifndef _RANKING_H_
#define _RANKING_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include	"../Scene\IScene.h"

/*---- 先行宣言 -------------------------------------------------------------*/

class World;
enum Scene;

/// <summary>
/// ランキングシーン.
/// </summary>
class Ranking : public IScene
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	Ranking();
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

};

#endif

/********** End of File ******************************************************/
