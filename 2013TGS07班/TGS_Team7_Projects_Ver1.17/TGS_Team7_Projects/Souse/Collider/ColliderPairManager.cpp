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
#include"ColliderPairManager.h"
#include<algorithm>

/// <summary>
/// コンストラクタ.
/// </summary>
ColliderPairManager::ColliderPairManager()
{
	Clear();
}

/// <summary>
/// ペアの追加.
/// </summary>
void ColliderPairManager::AddPair( PairPtr& pair )
{
	mPairEntry.push_back( pair );
}

/// <summary>
/// ペアのソート.
/// </summary>
void ColliderPairManager::SortPair()
{

	// ソートする.
	//mPairEntry.sort();
	//mPairsRun.sort();

	// 実行ペアがない時.
	if( mPairsRun.size() == 0 )
	{
		return;
	}


	// 実行ペアをループさせる.
	for( PairConter::iterator run = mPairsRun.begin(); run != mPairsRun.end() ; run++ )
	{
		// 継続的なペアを探す.
		SortEntryPair( run );

		// 今回の衝突に発見されていない時.
		if( run->get()->mType == PAIR_DELLETE )
		{
			PairConter::iterator delPair = run;
			mPairsDel.push_back( *delPair );
			//mPairsRun.erase( delPair );
			//run--;
		}
	}

	// 破棄される要素を削除する.
	mPairsRun.remove_if( [](PairPtr Pair)
	{
		// 死亡しているか判定.
		return Pair->mType == PAIR_DELLETE;
	});
}

/// <summary>
/// 新規ペアのソート.
/// </summary>
/// <param name="run">実行ペア</param>
void ColliderPairManager::SortEntryPair( PairConter::iterator& run )
{
	ColliderPair& runPair = *run->get();

	// 新規ペアをループさせる.
	for( PairConter::iterator entry = mPairEntry.begin() ; entry != mPairEntry.end() ; entry++ )
	{

		ColliderPair& entryPair = *entry->get();

		// 新規ペアの中に継続的な衝突がある時.
		if( runPair == entryPair )
		{
			run->get()->mType = PAIR_KEEP;
			mPairEntry.erase( entry );
			// 早期終了.
			return;
		}
	}
}

/// <summary>
/// 衝突応答処理.
/// </summary>
void ColliderPairManager::CollisionResponse()
{
	// 継続ペアの衝突応答処理を行う.
	CollideStay();
	// 新規ペアの衝突応答処理を行う.
	CollideEnter();
	// 解消されたペアの衝突応答処理を行う.
	CollideExit();
}

/// <summary>
/// 新規衝突処理.
/// </summary>
void ColliderPairManager::CollideEnter()
{
	if( mPairEntry.size() == 0 )
	{
		return;
	}
	// 衝突ペアを繰り返す.
	std::for_each( mPairEntry.begin(), mPairEntry.end(), []( PairPtr pair )
	{
		pair->CollisionResponse();
		pair->mType = PAIR_DELLETE;
	});

	// 実行ペアに新規ペアを併合する.
	mPairsRun.merge( mPairEntry );
	// 新規ペアを初期化する.
	mPairEntry.clear();
}

/// <summary>
/// 継続衝突処理.
/// </summary>
void ColliderPairManager::CollideStay()
{
	if( mPairsRun.size() == 0 )
	{
		return;
	}
	// 衝突ペアを繰り返す.
	std::for_each( mPairsRun.begin(), mPairsRun.end(), []( PairPtr pair )
	{
		pair->CollisionResponse();
		pair->mType = PAIR_DELLETE;
	});
}

/// <summary>
/// 衝突解消後処理.
/// </summary>
void ColliderPairManager::CollideExit()
{
	if( mPairsDel.size() == 0 )
	{
		return;
	}
	// 衝突ペアを繰り返す.
	std::for_each( mPairsDel.begin(), mPairsDel.end(), []( PairPtr pair )
	{
		pair->CollisionResponse();
	});
	// 削除ペアを消去する.
	mPairsDel.clear();
}

/// <summary>
/// 消去.
/// </summary>
void ColliderPairManager::Clear()
{
	mPairEntry.clear();
	mPairsRun.clear();
	mPairsDel.clear();
}

/********** End of File ******************************************************/
