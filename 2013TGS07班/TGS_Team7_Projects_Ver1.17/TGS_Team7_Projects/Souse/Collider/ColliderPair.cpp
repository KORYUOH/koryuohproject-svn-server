/******************************************************************************
* File Name : ColliderPair.cpp                    Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�Փ˃N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"ColliderPair.h"
#include"../Unit/Unit.h"


/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="unitA">���j�b�gA</param>
/// <param name="unitB">���j�b�gB</param>
ColliderPair::ColliderPair( Unit& unitA, Unit& unitB ) : 
	mType( PAIR_NEW ),
	mUnitA( unitA ),
	mUnitB( unitB )
{

}

/// <summary>
/// �Փˉ�������.
/// </summary>
void ColliderPair::CollisionResponse()
{
	// �V�K�Փ˂̎�.
	CollideEnter();
	// �p���I�ȏՓ˂̎�.
	CollideStay();
	// �Փ˂��������ꂽ��.
	CollideExit();
}

/// <summary>
/// �V�K�Փˏ���.
/// </summary>
void ColliderPair::CollideEnter()
{
	// �V�K�Փ˂̎�.
	if( mType == PAIR_NEW )
	{
		mUnitA.OnCollideEnter( mUnitB );
		mUnitB.OnCollideEnter( mUnitA );
	}
}

/// <summary>
/// �p���Փˏ���.
/// </summary>
void ColliderPair::CollideStay()
{
	if( mType == PAIR_KEEP )
	{
		mUnitA.OnCollideStay( mUnitB );
		mUnitB.OnCollideStay( mUnitA );
	}
}

/// <summary>
/// �Փˉ����㏈��.
/// </summary>
void ColliderPair::CollideExit()
{
	if( mType == PAIR_DELLETE )
	{
		mUnitA.OnCollideExit( mUnitB );
		mUnitB.OnCollideExit( mUnitA );
	}

}

bool ColliderPair::operator == ( const ColliderPair& other )
{
	if( &mUnitA == &other.mUnitA )
	{
		return ( &mUnitB == &other.mUnitB );
	}
	else if( &mUnitA == &other.mUnitB )
	{
		return ( &mUnitB == &other.mUnitA );
	}

	return false;
}

/********** End of File ******************************************************/
