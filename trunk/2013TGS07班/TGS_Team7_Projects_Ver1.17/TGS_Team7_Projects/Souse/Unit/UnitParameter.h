/******************************************************************************
* File Name : UnitParameter.h                    Ver : 1.00  Date : 2013-04-29
*
* Description :
*
*		ユニットパラメータクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_PARAMETER_H_
#define _UNIT_PARAMETER_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include"UnitID.h"
#include"../CSV/CSVReader.h"
#include<map>

/*---- 先行宣言 -------------------------------------------------------------*/

/// <summary>
/// ユニットレベルの最大値.
/// </summary>
static const int UNIT_LEVEL_MAX = 5;
/// <summary>
/// ユニットレベルの最小値.
/// </summary>
static const int UNIT_LEVEL_MIN = 1;
/// <summary>
/// ユニット要素構造体.
/// </summary>
struct UnitElement;



/// <summary>
/// ユニットパラメータクラス.
/// </summary>
class UnitParameter
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	UnitParameter();
	/// <summary>
	/// 初期化.
	/// </summary>
	void Initialize();
	/// <summary>
	/// 人材の最大値を取得.
	/// </summary>
	/// <param name="element">ユニットの属性</param>
	/// <returns>人材の最大値を返す.</returns>
	float GetHumanMax( const UnitElement& element ) const;
	/// <summary>
	/// 生産率の最大値を取得.
	/// </summary>
	/// <param name="element">ユニットの属性</param>
	/// <returns>生産率の最大値を返す.</returns>
	float GetProduction( const UnitElement& element ) const;
	/// <summary>
	/// 消費コストの最大値を取得.
	/// </summary>
	/// <param name="element">ユニットの属性</param>
	/// <returns>消費コスト値を返す.</returns>
	float GetCost( const UnitElement& element ) const;
	/// <summary>
	/// レベルアップ消費コストの最大値を取得.
	/// </summary>
	/// <param name="element">ユニットの属性</param>
	/// <returns>レベルアップ消費コスト値を返す.</returns>
	float GetLevelUpCost( const UnitElement& element ) const;
private:
	/// <summary>
	/// 初期化.
	/// </summary>
	/// <param name="id">ユニットＩＤ</param>
	/// <param name="unitLevel">初期化データ</param>
	void Initialize( UnitID id ,const DataFloat& data );

	typedef std::map<int,float> UnitLevel;
	typedef std::map<UnitID,UnitLevel>	ParameterContener;
	/// <summary>
	/// 最大値人材値.
	/// </summary>
	ParameterContener	mHumanMax;
	/// <summary>
	/// 生産率.
	/// </summary>
	ParameterContener	mProduction;
	/// <summary>
	/// 消費コスト.
	/// </summary>
	ParameterContener	mCost;
	/// <summary>
	/// レベルアップコスト.
	/// </summary>
	ParameterContener	mLevelUpCost;
};

#endif // _UNIT_PARAMETER_H_ end

/********** End of File ******************************************************/
