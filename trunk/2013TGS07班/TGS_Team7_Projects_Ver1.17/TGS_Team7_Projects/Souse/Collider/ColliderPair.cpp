/******************************************************************************
* File Name : ColliderPair.cpp                    Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		衝突クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"ColliderPair.h"
#include"../Unit/Unit.h"


/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="unitA">ユニットA</param>
/// <param name="unitB">ユニットB</param>
ColliderPair::ColliderPair( Unit& unitA, Unit& unitB ) : 
	mType( PAIR_NEW ),
	mUnitA( unitA ),
	mUnitB( unitB )
{

}

/// <summary>
/// 衝突応答処理.
/// </summary>
void ColliderPair::CollisionResponse()
{
	// 新規衝突の時.
	CollideEnter();
	// 継続的な衝突の時.
	CollideStay();
	// 衝突が解消された時.
	CollideExit();
}

/// <summary>
/// 新規衝突処理.
/// </summary>
void ColliderPair::CollideEnter()
{
	// 新規衝突の時.
	if( mType == PAIR_NEW )
	{
		mUnitA.OnCollideEnter( mUnitB );
		mUnitB.OnCollideEnter( mUnitA );
	}
}

/// <summary>
/// 継続衝突処理.
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
/// 衝突解消後処理.
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
