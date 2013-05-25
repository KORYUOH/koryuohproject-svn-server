/******************************************************************************
* File Name : Collider.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�Փ˃N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Collider.h"


/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="position">�ʒu���</param>
/// <param name="radius">�Փ˗p���a</param>
Collider::Collider( const GSvector2& position, float radius ):
	mPosition( position ),
	mRadius( radius ),
	mIsCollision( false )
{
}

/// <summary>
/// �Փ˔���.
/// </summary>
/// <param name="other">�Փˑ���</param>
bool Collider::IsCollide( const Collider& other )
{
	return( mPosition.distance(other.mPosition) <= (mRadius+other.mRadius) );
}

/********** End of File ******************************************************/
