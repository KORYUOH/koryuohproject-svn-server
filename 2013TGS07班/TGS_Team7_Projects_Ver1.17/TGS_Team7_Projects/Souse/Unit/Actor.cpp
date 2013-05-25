/******************************************************************************
* File Name : Actor.cpp                           Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�A�N�^�[���ۃN���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Actor.h"
#include"../World/IWorld.h"
#include"../Draw/TextureID.h"

	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="world">���[���h</param>
	/// <param name="flag">�t���O�Ǘ���</param>
	///	 <param name="position">�������W</param>
	/// <param name="radius">�Փ˔���p�̔��a</param>
Actor::Actor( IWorld& world, IFlagManager& flag, const GSvector2& position ,float radius ) :
	mWorld( world ),
	mFlags( flag ),
	mCollder( position , radius ),
	mAnimation( TEXTURE_NULL ),
	mIsAlive( true )
{
}


/// <summary>
/// ���S����.
/// </summary>
/// <returns>���S���Ă���ΐ^�A���Ă��Ȃ���΋U��Ԃ�</returns>
bool Actor::IsDead() const
{
	return !mIsAlive;
}


/// <summary>
/// �������S����.
/// </summary>
void Actor::Dead()
{
	// ���S������
	mIsAlive = false;
}


/********** End of File ******************************************************/