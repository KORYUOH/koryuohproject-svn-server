/******************************************************************************
* File Name : UnitParameter.cpp                  Ver : 1.00  Date : 2013-04-29
*
* Description :
*
*		ユニットパラメータクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"UnitParameter.h"
#include"../CSV/CSVReader.h"
#include"Unit.h"
#include<algorithm>

/// <summary>
/// コンストラクタ.
/// </summary>
UnitParameter::UnitParameter()
{
	mHumanMax.clear();
	mProduction.clear();
	mCost.clear();
}

/// <summary>
/// 初期化.
/// </summary>
void UnitParameter::Initialize()
{
	// 読み取り機.
	CSVReader reader;

	reader.Load( "Resouse/Space.csv" );
	Initialize( UNIT_SPACE , reader.GetFloatData() );
	reader.Load( "Resouse/Star.csv" );
	Initialize( UNIT_STAR , reader.GetFloatData() );
	reader.Load( "Resouse/Farm.csv" );
	Initialize( UNIT_FARM , reader.GetFloatData() );
	reader.Load( "Resouse/Factory.csv" );
	Initialize( UNIT_FACTORY , reader.GetFloatData() );
	reader.Load( "Resouse/Housing.csv" );
	Initialize( UNIT_HOUSING , reader.GetFloatData() );
	reader.Load( "Resouse/Airfield.csv" );
	Initialize( UNIT_AIRFIELD , reader.GetFloatData() );
}

/// <summary>
/// 初期化.
/// </summary>
/// <param name="id">ユニットＩＤ</param>
/// <param name="unitLevel">初期化データ</param>
void UnitParameter::Initialize( UnitID id ,const DataFloat& data )
{
	// データが空の時.
	if( data.size() == 0 )
	{
		// 早期終了.
		return;
	}

	// 追加用の変数を宣言する.
	UnitLevel human;
	human.clear();
	UnitLevel production;
	production.clear();
	UnitLevel cost;
	cost.clear();
	UnitLevel levelCost;
	levelCost.clear();

	// データを追加する.
	for( int level = 0 ; level < UNIT_LEVEL_MAX ; level++ )
	{
		human.insert( UnitLevel::value_type(level, data[0][level]) );
		production.insert( UnitLevel::value_type( level, data[1][level] ) );
		cost.insert( UnitLevel::value_type( level, data[2][level] ) );
		levelCost.insert( UnitLevel::value_type( level, data[3][level] ) );
	}

	mHumanMax.insert( ParameterContener::value_type(id,human) );
	mProduction.insert( ParameterContener::value_type(id,production) );
	mCost.insert( ParameterContener::value_type(id,cost) );
	mLevelUpCost.insert( ParameterContener::value_type(id,levelCost) );
}

/// <summary>
/// 人材の最大値を取得.
/// </summary>
/// <param name="element">ユニットの属性</param>
/// <returns>人材の最大値を返す.</returns>
float UnitParameter::GetHumanMax( const UnitElement& element ) const
{	
	return mHumanMax.find(element.mID)->second.find(element.mLevel-1)->second;
}

/// <summary>
/// 生産率の最大値を取得.
/// </summary>
/// <param name="element">ユニットの属性</param>
/// <returns>生産率の最大値を返す.</returns>
float UnitParameter::GetProduction( const UnitElement& element ) const
{
	return mProduction.find(element.mID)->second.find(element.mLevel-1)->second;
}

/// <summary>
/// 消費コストの最大値を取得.
/// </summary>
/// <param name="element">ユニットの属性</param>
/// <returns>消費コスト値を返す.</returns>
float UnitParameter::GetCost( const UnitElement& element ) const
{
	return mCost.find(element.mID)->second.find(element.mLevel-1)->second;
}

/// <summary>
/// レベルアップ消費コストの最大値を取得.
/// </summary>
/// <param name="element">ユニットの属性</param>
/// <returns>レベルアップ消費コスト値を返す.</returns>
float UnitParameter::GetLevelUpCost( const UnitElement& element ) const
{
	return mLevelUpCost.find(element.mID)->second.find(element.mLevel-1)->second;
}

/********** End of File ******************************************************/
