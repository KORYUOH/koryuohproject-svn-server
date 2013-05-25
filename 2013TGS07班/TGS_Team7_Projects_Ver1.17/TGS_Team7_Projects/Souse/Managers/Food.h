/******************************************************************************
* File Name : FoodManager.h                       Ver : 1.00  Date : 2013-05-13
*
* Description :
*
*		食料管理者クラス．
*
******************************************************************************/
#ifndef _FOOD_MANAGER_H_
#define _FOOD_MANAGER_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<map>

/*---- 先行宣言 -------------------------------------------------------------*/

class Unit;
class UnitParameter;
class UnitHierarchy;
typedef std::map<Unit*, float>	FoodContainer;


/// <summary>
/// 人材管理者.
/// </summary>
class FoodManager
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="parameter">パラメータ</param>
	FoodManager();
	/// <summary>
	/// 初期化.
	/// </summary>
	void Initialize();
	/// <summary>
	/// 人材の最大値を更新する.
	/// </summary>
	/// <param name="unit">ユニット</param>
	void HumanUpdate( Unit* unit );
	/// <summary>
	/// 人材の最大値を更新する.
	/// </summary>
	/// <param name="unit">ユニット</param>
	/// <param name="hierarchy">階層</param>
	void HumanUpdate( Unit* unit, UnitHierarchy& hierarchy );
	/// <summary>
	/// 食料の追加.
	/// </summary>
	/// <param name="unit">ユニット</param>
	void Add( Unit* unit );
	/// <summary>
	/// 増減できるとか判定する.
	/// </summary>
	/// <param name="unit">ユニット</param>
	/// <param name="food">増減量</param>
	/// <returns>増減できる時真、そうでなければ偽を返す.</returns>
	bool IsAccess( Unit* unit, float food ) const;
	/// <summary>
	/// 人材を増減させる.
	/// </summary>
	/// <param name="my">ユニット</param>
	/// <param food="food">増減量</param>
	/// <returns>移動できれば真、できなければ偽を返す.</returns>
	bool Fluctuation( Unit* my, float food );
	/// <summary>
	/// 人材を移動させる.
	/// </summary>
	/// <param name="my">移動元ユニット</param>
	/// <param name="target">移動先ユニット</param>
	/// <param name="food">増減量</param>
	/// <returns>移動できれば真、できなければ偽を返す.</returns>
	bool Fluctuation( Unit* my, Unit* target, float food );
	/// <summary>
	/// 消去.
	/// </summary>
	void Clear();
private:
	/// <summary>
	/// 食料コンテナ.
	/// </summary>
	FoodContainer	mFoodContainer;

};


#endif // !_HUMAN_MANAGER_H_

/********** End of File ******************************************************/