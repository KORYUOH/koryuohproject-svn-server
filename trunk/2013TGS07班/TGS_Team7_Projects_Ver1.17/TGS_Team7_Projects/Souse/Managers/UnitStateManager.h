/******************************************************************************
* File Name : UnitStateManager.h                  Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		ユニット状態管理者クラス．
*
******************************************************************************/
#ifndef _HUMAN_MANAGER_H_
#define _HUMAN_MANAGER_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<map>

/*---- 先行宣言 -------------------------------------------------------------*/

class Unit;
class UnitParameter;
class UnitHierarchy;
typedef std::map<Unit*, float>	HumanContainer;


/// <summary>
/// ユニット状態管理者.
/// </summary>
class UnitStateManager
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="parameter">パラメータ</param>
	UnitStateManager( UnitParameter& parameter );
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
	/// フラグの追加.
	/// </summary>
	/// <param name="unit">ユニット</param>
	void Add( Unit* unit );
	/// <summary>
	/// 増減できるとか判定する.
	/// </summary>
	/// <param name="unit">ユニット</param>
	/// <param name="human">増減量</param>
	/// <returns>増減できる時真、そうでなければ偽を返す.</returns>
	bool IsAccess( Unit* unit, float human ) const;
	/// <summary>
	/// 人材を増減させる.
	/// </summary>
	/// <param name="target">ユニット</param>
	/// <param name="human">増減量</param>
	/// <returns>移動できれば真、できなければ偽を返す.</returns>
	bool PersonnelChange( Unit* my, float human );
	/// <summary>
	/// 人材を移動させる.
	/// </summary>
	/// <param name="target">移動元ユニット</param>
	/// <param name="human">移動先ユニット</param>
	/// <param name="human">増減量</param>
	/// <returns>移動できれば真、できなければ偽を返す.</returns>
	bool PersonnelChange( Unit* my, Unit* target, float human );
	/// <summary>
	/// 消去.
	/// </summary>
	void Clear();
private:
	/// <summary>
	/// ユニットパラメータ.
	/// </summary>
	UnitParameter&	mParameter;
	/// <summary>
	/// フラグコンテナ.
	/// </summary>
	HumanContainer	mHumanContainer;
	/// <summary>
	/// フラグコンテナ.
	/// </summary>
	HumanContainer	mHumanMaxContainer;

};


#endif // !_HUMAN_MANAGER_H_

/********** End of File ******************************************************/