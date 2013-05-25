/******************************************************************************
* File Name : FlagManager.h                      Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		フラグ管理者クラス．
*
******************************************************************************/
#include"FlagManager.h"


/// <summary>
/// コンストラクタ.
/// </summary>
FlagManager::FlagManager()
{
	mFlagContainer.clear();
}

/// <summary>
/// 初期化.
/// </summary>
void FlagManager::Initialize()
{
	// 消去する.
	Clear();

	Add( FlagID::FLAG_NONE );
	Add( FlagID::FLAG_CREATE_AIRFIELD );
	Add( FlagID::FLAG_HUMAN_MUVEMENT );
	Add( FlagID::FLAG_FACILITY_LEVEL_UP );
	Add( FlagID::FLAG_CREATE_FACTORY );
	Add( FlagID::FLAG_CREATE_FARM );
	Add( FlagID::FLAG_CREATE_HOUSING );
	Add( FlagID::FLAG_CREATE_AIRFIELD );
}
/// <summary>
/// フラグの追加.
/// </summary>
/// <param name="id">フラグID</param>
void FlagManager::Add( FlagID id )
{
	mFlagContainer.insert( FlagContainer::value_type( id, false ) );
}

/// <summary>
/// フラグを取得する.
/// </summary>
/// <param name="id">フラグID</param>
/// <returns>フラグを返す.</returns>
bool FlagManager::IsFlag( FlagID id ) const
{
	return mFlagContainer.find( id )->second;
}


/// <summary>
/// フラグを交換する.
/// </summary>
/// <param name="id">フラグID</param>
void FlagManager::ChangeFlag( FlagID id )
{
	mFlagContainer.find( id )->second = ( IsFlag( id ) ) ? ( false ) : ( true );
}

/// <summary>
/// フラグを有効にする.
/// </summary>
/// <param name="id">フラグID</param>
void FlagManager::FlagEnable( FlagID id )
{
	mFlagContainer.find( id )->second = true;
}

/// <summary>
/// フラグを無効にする.
/// </summary>
/// <param name="id">フラグID</param>
void FlagManager::FlagDisable( FlagID id )
{
	mFlagContainer.find( id )->second = false;
}

/// <summary>
/// 消去.
/// </summary>
void FlagManager::Clear()
{
	mFlagContainer.clear();
}

/********** End of File ******************************************************/

