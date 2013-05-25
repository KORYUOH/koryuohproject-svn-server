/******************************************************************************
* File Name : FundsManager.h                      Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		�����Ǘ��҃N���X�D
*
******************************************************************************/
#include"Funds.h"
#include"../Unit/UnitParameter.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="parameter">�p�����[�^</param>
FundsManager::FundsManager( UnitParameter& parameter ):
	mParameter( parameter ),
	mFunds( 0.0f ),
	mFundsAll( 0.0f )
{
}

/// <summary>
/// ������.
/// </summary>
void FundsManager::Initialize()
{
	Clear();
}

/// <summary>
/// �����ł���Ƃ����肷��.
/// </summary>
/// <param name="funds">������</param>
/// <returns>�����ł��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
bool FundsManager::IsAccess( float funds ) const
{
	return ( funds + mFunds ) > 0.0f;
}

/// <summary>
/// �����𑝌�������.
/// </summary>
/// <param name="target">���j�b�g</param>
/// <param name="human">������</param>
/// <returns>�ړ��ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
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
/// ����.
/// </summary>
void FundsManager::Clear()
{
	mFunds = 0.0f;
	mFundsAll = 0.0f;
}


/********** End of File ******************************************************/