/******************************************************************************
* File Name : FlagManager.h                      Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		�t���O�Ǘ��҃N���X�D
*
******************************************************************************/
#include"FlagManager.h"


/// <summary>
/// �R���X�g���N�^.
/// </summary>
FlagManager::FlagManager()
{
	mFlagContainer.clear();
}

/// <summary>
/// ������.
/// </summary>
void FlagManager::Initialize()
{
	// ��������.
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
/// �t���O�̒ǉ�.
/// </summary>
/// <param name="id">�t���OID</param>
void FlagManager::Add( FlagID id )
{
	mFlagContainer.insert( FlagContainer::value_type( id, false ) );
}

/// <summary>
/// �t���O���擾����.
/// </summary>
/// <param name="id">�t���OID</param>
/// <returns>�t���O��Ԃ�.</returns>
bool FlagManager::IsFlag( FlagID id ) const
{
	return mFlagContainer.find( id )->second;
}


/// <summary>
/// �t���O����������.
/// </summary>
/// <param name="id">�t���OID</param>
void FlagManager::ChangeFlag( FlagID id )
{
	mFlagContainer.find( id )->second = ( IsFlag( id ) ) ? ( false ) : ( true );
}

/// <summary>
/// �t���O��L���ɂ���.
/// </summary>
/// <param name="id">�t���OID</param>
void FlagManager::FlagEnable( FlagID id )
{
	mFlagContainer.find( id )->second = true;
}

/// <summary>
/// �t���O�𖳌��ɂ���.
/// </summary>
/// <param name="id">�t���OID</param>
void FlagManager::FlagDisable( FlagID id )
{
	mFlagContainer.find( id )->second = false;
}

/// <summary>
/// ����.
/// </summary>
void FlagManager::Clear()
{
	mFlagContainer.clear();
}

/********** End of File ******************************************************/

