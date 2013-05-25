/******************************************************************************
* File Name : WorldActor.cpp                     Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		ワールドユニットクラス．
*
******************************************************************************/
#include	"WorldUnit.h"
#include	"UnitManager.h"
#include	"../Unit/UnitID.h"
#include	"../Unit/UnitPtr.h"
#include	<algorithm>


/// <summary>
/// コンストラクタ.
/// </summary>
WorldUnit::WorldUnit():
	mColliderManager()
{
	// アクターマネージャーの初期化.
	Clear();

	// アクターマネージャーを生成.
	AddManager( UNIT_PLAYER );
	AddManager( UNIT_CAMERA );
	AddManager( UNIT_SPACE );
	AddManager( UNIT_STAR );
	AddManager( UNIT_HOUSING );
	AddManager( UNIT_FARM );
	AddManager( UNIT_FACTORY );


}

/// <summary>
/// デストラクタ.
/// </summary>
WorldUnit::~WorldUnit()
{
}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void WorldUnit::Update( float frameTimer )
{
	// すべてのマネージャーを更新.
	each( [&]( UnitManagerPtr manager )
	{
		manager->Update( frameTimer ); 
	});

	mManagers[UNIT_PLAYER]->Collide( *mManagers[UNIT_STAR] );
	mManagers[UNIT_PLAYER]->Collide( *mManagers[UNIT_HOUSING] );
	mManagers[UNIT_PLAYER]->Collide( *mManagers[UNIT_FACTORY] );
	mManagers[UNIT_PLAYER]->Collide( *mManagers[UNIT_FARM] );


	// すべてのマネージャーのアクター削除
	each([&](UnitManagerPtr manager)
	{ 
		// 死亡しているアクターを削除
		manager->Remove(); 
	});

	// ペアをソートする.
	mColliderManager.SortPair();
	// 衝突ペアの衝突応答処理を行う.
	mColliderManager.CollisionResponse();
}

/// <summary>
/// 生産処理.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void WorldUnit::Production( float frameTimer )
{
	// すべてのユニットマネージャーに生成処理を行わせる.
	each( [&]( UnitManagerPtr manager )
	{
		manager->Production( frameTimer );
	});
}

/// <summary>
/// 維持コスト支払い処理.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void WorldUnit::Maintenance( float frameTimer )
{
		// すべてのユニットマネージャーに維持コスト処理を行わせる.
	each( [&]( UnitManagerPtr manager )
	{
		manager->Maintenance( frameTimer );
	});
}

/// <summary>
/// 描画.
/// </summary>
void WorldUnit::Draw()
{
	// すべてのマネージャーの描画
	each([&](UnitManagerPtr manager) 
	{ 
		manager->Draw(); 
	});
}

/// <summary>
/// UIの描画.
/// </summary>
void WorldUnit::DrawUI()
{
	// すべてのマネージャーのUIの描画.
	each( [&](UnitManagerPtr manager)
	{
		manager->DrawUI();
	});
}

/// <summary>
/// アクターの追加.
/// </summary>
/// <param name="id">アクターマネージャID</param>
/// <param name="unit">追加するアクター</param>
void WorldUnit::Add( UnitID id, UnitPtr unit )
{
	// 指定したマネージャーに引数のアクターを追加
	mManagers[id]->Add(unit);
}

/// <summary>
/// マネージャーの追加.
/// </summary>
/// <param name="id">追加するアクターマネージャID</param>
void WorldUnit::AddManager( UnitID id )
{
	// マネージャーを追加.
	mManagers[id] = std::make_shared<UnitManager>(mColliderManager);
}

/// <summary>
/// 消去.
/// </summary>
void WorldUnit::Clear()
{
	// すべてのマネージャーのアクター削除を行う.
	each([](UnitManagerPtr manager) 
	{ 
		// アクターの削除.
		manager->Clear(); 
	});

	// 衝突管理者を消去.
	mColliderManager.Clear();
}

/// <summary>
/// foreachの省略宣言.
/// </summary>
void WorldUnit::each(UnitManagerFunction f)
{
	std::for_each(mManagers.begin(), mManagers.end(),[&](UnitManagerPair pair) 
	{
		f(pair.second); 
	});
}

/********** End of File ******************************************************/