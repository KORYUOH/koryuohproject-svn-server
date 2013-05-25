/******************************************************************************
* File Name : FoodManager.cpp                     Ver : 1.00  Date : 2013-05-13
*
* Description :
*
*		食料管理者クラス．
*
******************************************************************************/
#include"Food.h"
#include"../Unit/Unit.h"

/// <summary>
/// コンストラクタ.
/// </summary>
FoodManager::FoodManager()
{
	Clear();
}

/// <summary>
/// 初期化.
/// </summary>
void FoodManager::Initialize()
{
	// 初期化する.
	Clear();
}

/// <summary>
/// フラグの追加.
/// </summary>
/// <param name="unit">ユニット</param>
void FoodManager::Add( Unit* unit )
{
	mFoodContainer.insert( FoodContainer::value_type( unit, 0.0f ) );
}



/// <summary>
/// 増減できるとか判定する.
/// </summary>
/// <param name="unit">ユニット</param>
/// <param name="food">増減量</param>
/// <returns>増減できる時真、そうでなければ偽を返す.</returns>
bool FoodManager::IsAccess( Unit* unit, float food ) const
{
	return ( food + mFoodContainer.find(unit)->second ) > 0.0f;
}

/// <summary>
/// 人材を増減させる.
/// </summary>
/// <param name="my">ユニット</param>
/// <param food="food">増減量</param>
/// <returns>移動できれば真、できなければ偽を返す.</returns>
bool FoodManager::Fluctuation( Unit* my, float food )
{
	if( !IsAccess( my, food ) )
	{
		return false;
	}
	mFoodContainer.find(my)->second += food;
	return true;
}

/// <summary>
/// 人材を移動させる.
/// </summary>
/// <param name="my">移動元ユニット</param>
/// <param name="target">移動先ユニット</param>
/// <param name="food">増減量</param>
/// <returns>移動できれば真、できなければ偽を返す.</returns>
bool FoodManager::Fluctuation( Unit* my, Unit* target, float food )

{
	// 人材がどちらか移動できない時.
	if( !IsAccess( my, -food ) || !IsAccess( target, food ) )
	{
		// 早期終了.
		return false;
	}

	// 人材を増減させる.
	Fluctuation( my, -food );
	Fluctuation( target, food );
	return true;
}


/// <summary>
/// 消去.
/// </summary>
void FoodManager::Clear()
{
	mFoodContainer.clear();
}

/********** End of File ******************************************************/