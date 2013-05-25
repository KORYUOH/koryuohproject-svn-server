/******************************************************************************
* File Name : Collider.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		衝突クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Collider.h"


/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="position">位置情報</param>
/// <param name="radius">衝突用半径</param>
Collider::Collider( const GSvector2& position, float radius ):
	mPosition( position ),
	mRadius( radius ),
	mIsCollision( false )
{
}

/// <summary>
/// 衝突判定.
/// </summary>
/// <param name="other">衝突相手</param>
bool Collider::IsCollide( const Collider& other )
{
	return( mPosition.distance(other.mPosition) <= (mRadius+other.mRadius) );
}

/********** End of File ******************************************************/
