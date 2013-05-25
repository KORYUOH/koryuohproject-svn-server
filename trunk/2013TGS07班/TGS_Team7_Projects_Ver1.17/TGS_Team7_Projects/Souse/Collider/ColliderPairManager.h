/******************************************************************************
* File Name : ColliderPair.h                      Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		衝突ペア管理者クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _COLLIDER_PAIR_MANAGER_H_
#define _COLLIDER_PAIR_MANAGER_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<list>
#include"ColliderPair.h"

/*---- 先行宣言 -------------------------------------------------------------*/

/// <summary>
/// 衝突ペアコンテナ.
/// </summary>
//typedef std::list<ColliderPair&> PairConter;
typedef std::list<PairPtr> PairConter;


/// <summary>
/// 衝突ペア管理者クラス.
/// </summary>
class ColliderPairManager
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	ColliderPairManager();
	/// <summary>
	/// ペアの追加.
	/// </summary>
	void AddPair( PairPtr& pair );
	/// <summary>
	/// ペアのソート.
	/// </summary>
	void SortPair();
	/// <summary>
	/// 衝突応答処理.
	/// </summary>
	void CollisionResponse();
	/// <summary>
	/// 消去.
	/// </summary>
	void Clear();
private:
	/// <summary>
	/// 新規ペアのソート.
	/// </summary>
	/// <param name="run">実行ペア</param>
	void SortEntryPair( PairConter::iterator& run );
	/// <summary>
	/// 新規衝突処理.
	/// </summary>
	void CollideEnter();
	/// <summary>
	/// 継続衝突処理.
	/// </summary>
	void CollideStay();
	/// <summary>
	/// 衝突解消後処理.
	/// </summary>
	void CollideExit();


public:
	/// <summary>
	/// 衝突ペアコンテナ
	/// </summary>
	PairConter	mPairsRun;
	/// <summary>
	/// 新規ペアコンテナ.
	/// </summary>
	PairConter mPairEntry;
	/// <summary>
	/// 削除されるペアコンテナ.
	/// </summary>
	PairConter	mPairsDel;


}; // class ColliderPairMangaer end

#endif // _COLLIDER_PAIR_MANAGER_H_ end

/********** End of File ******************************************************/
