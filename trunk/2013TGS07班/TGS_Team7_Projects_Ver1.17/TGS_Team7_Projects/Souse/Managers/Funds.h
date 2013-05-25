/******************************************************************************
* File Name : FundsManager.h                      Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		資金管理者クラス．
*
******************************************************************************/
#ifndef _FUNDS_MANAGER_H_
#define _FUNDS_MANAGER_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<map>

/*---- 先行宣言 -------------------------------------------------------------*/

class Unit;
class UnitParameter;


/// <summary>
/// 人材管理者.
/// </summary>
class FundsManager
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="parameter">パラメータ</param>
	FundsManager( UnitParameter& parameter );
	/// <summary>
	/// 初期化.
	/// </summary>
	void Initialize();
	/// <summary>
	/// 増減できるとか判定する.
	/// </summary>
	/// <param name="funds">増減量</param>
	/// <returns>増減できる時真、そうでなければ偽を返す.</returns>
	bool IsAccess( float funds ) const;
	/// <summary>
	/// 人材を増減させる.
	/// </summary>
	/// <param name="target">ユニット</param>
	/// <param name="human">増減量</param>
	/// <returns>移動できれば真、できなければ偽を返す.</returns>
	bool PersonnelChange( Unit* my, float funds );
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
	/// 資金.
	/// </summary>
	float			mFunds;
	/// <summary>
	/// 今までの資金の合計.
	/// </summary>
	float			mFundsAll;

};


#endif // !_HUMAN_MANAGER_H_

/********** End of File ******************************************************/