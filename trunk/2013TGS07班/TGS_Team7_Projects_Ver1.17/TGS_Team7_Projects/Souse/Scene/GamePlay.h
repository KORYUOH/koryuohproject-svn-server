/******************************************************************************
* File Name : GamePlay.h                         Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		ゲームプレイクラス．
*
******************************************************************************/
#ifndef _GAMEPLAY_H_
#define _GAMEPLAY_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include"../Scene\IScene.h"
#include"../World/World.h"
#include"../Flag/FlagManager.h"

/*---- 先行宣言 -------------------------------------------------------------*/

class World;
class FlagManager;
enum Scene;


/// <summary>
/// ゲームプレイシーンクラス.
/// </summary>
class GamePlay : public IScene
{
public:
/// <summary>
/// コンストラクタ.
/// </summary>
	GamePlay();
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


private:
	/// <summary>
	/// ワールド.
	/// </summary>
	World	mWorld;
	/// <summary>
	/// フラグ管理者.
	/// </summary>
	FlagManager	mFlagManager;

}; // class GamePlay end


#endif // !_GAMEPLAY_H_

/********** End of File ******************************************************/
