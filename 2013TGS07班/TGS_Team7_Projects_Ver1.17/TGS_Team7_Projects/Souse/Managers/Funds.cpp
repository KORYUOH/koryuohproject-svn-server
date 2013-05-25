/******************************************************************************
* File Name : FundsManager.h                      Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		資金管理者クラス．
*
******************************************************************************/
#include"Funds.h"
#include"../Unit/UnitParameter.h"

/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="parameter">パラメータ</param>
FundsManager::FundsManager( UnitParameter& parameter ):
	mParameter( parameter ),
	mFunds( 0.0f ),
	mFundsAll( 0.0f )
{
}

/// <summary>
/// 初期化.
/// </summary>
void FundsManager::Initialize()
{
	Clear();
}

/// <summary>
/// 増減できるとか判定する.
/// </summary>
/// <param name="funds">増減量</param>
/// <returns>増減できる時真、そうでなければ偽を返す.</returns>
bool FundsManager::IsAccess( float funds ) const
{
	return ( funds + mFunds ) > 0.0f;
}

/// <summary>
/// 資金を増減させる.
/// </summary>
/// <param name="target">ユニット</param>
/// <param name="human">増減量</param>
/// <returns>移動できれば真、できなければ偽を返す.</returns>
bool FundsManager::PersonnelChange( Unit* my, float funds )
{
	if( !IsAccess( funds ) )
	{
		return false;
	}
	mFunds += funds;
	mFundsAll = ( funds > 0.0f ) ? ( mFundsAll + funds ) : ( mFundsAll );
}

/// <summary>
/// 消去.
/// </summary>
void FundsManager::Clear()
{
	mFunds = 0.0f;
	mFundsAll = 0.0f;
}


/********** End of File ******************************************************/