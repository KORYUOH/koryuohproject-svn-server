/******************************************************************************
* File Name : ActorManager.cpp                          Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		アクターマネージャークラス．
*
******************************************************************************/
#include	"UnitManager.h"
#include	"../Unit/Unit.h"
#include	<algorithm>
#include	<functional>

/// <summary>
/// コンストラクタ.
/// </summary>
UnitManager::UnitManager( ColliderPairManager& collder ) :
	mColliderManager( collder )
{
	// アクターマネージャーを消去する.
	Clear();
}

/// <summary>
/// デストラクタ.
/// </summary>
UnitManager:: ~UnitManager()
{
	// アクターマネージャーを消去する.
	Clear();
}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void UnitManager::Update( float frameTimer )
{
	// ラムダ式で全てを繰り返す
	each( [&](UnitPtr unit)
	{
		//アクターを更新させる
		unit->Update(frameTimer); 
	});
}

/// <summary>
/// 生産処理.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void UnitManager::Production( float frameTimer )
{
	// ラムダ式で全てを繰り返す
	each( [&](UnitPtr unit)
	{
		//アクターを更新させる
		unit->Production(frameTimer); 
	});
}

/// <summary>
/// 維持コスト支払い処理.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void UnitManager::Maintenance( float frameTimer )
{
	// ラムダ式で全てを繰り返す
	each( [&](UnitPtr unit)
	{
		//アクターを更新させる
		unit->Maintenance(frameTimer); 
	});
}

/// <summary>
/// 描画.
/// </summary>
void UnitManager::Draw()
{
	// ラムダ式版
	each( [&](UnitPtr unit)
	{
		//アクターを描画する
		unit->Draw();
	});
}

/// <summary>
/// UIの描画.
/// </summary>
void UnitManager::DrawUI()
{
	// 全ユニットに実行する.
	each( [&](UnitPtr unit)
	{
		unit->DrawUI();
	});
}

/// <summary>
/// アクターの追加.
/// </summary>
/// <param name="actor">追加するアクター</param>
void UnitManager::Add( UnitPtr unit )
{
	//アクターリストの前に追加する
	mUnits.push_front( unit );
}


/// <summary>
/// 消去.
/// </summary>
void UnitManager::Clear()
{
	// すべての要素を削除する
	mUnits.clear();
}


/// <summary>
/// 死亡しているアクターの削除.
/// </summary>
void UnitManager::Remove()
{
	// 死亡している時アクターを削除.
	mUnits.remove_if( [](UnitPtr unit)
	{
		// 死亡しているか判定.
		return unit->IsDead();
	});
}

/// <summary>
/// アクター間の衝突判定.
/// </summary>
/// <param name="other">相手アクター</param>
void UnitManager::Collide( Unit& other )
{
	each([&]( UnitPtr unit ) 
	{
		// アクターが衝突している時.
		if( unit->IsCollide(other) )
		{
			PairPtr addPair = std::make_shared<ColliderPair>( *unit,other );
			// ペアを登録する.
			mColliderManager.AddPair( addPair );
		}
	});

}

/// <summary>
/// 他のマネージャーを衝突判定.
/// </summary>
/// <param name="other">相手マネージャー</param>
void UnitManager::Collide( UnitManager& other )
{
	// 自身のマネージャーを全て繰り返す.
	each([&]( UnitPtr unit ) 
	{
		// 相手のアクターマネージャーにこちらのアクターを送り.
		// 衝突処理を行わせる.
		other.Collide( *unit ); 
	});

}

/*=============================================================================
*
* Purpose : foreachを省略する関数．
*
* Return  : なし
*
*============================================================================*/
void UnitManager:: each(ActorFunction f)
{
	// foreach関数
	std::for_each(mUnits.begin(), mUnits.end(), f);
}

/********** End of File ******************************************************/