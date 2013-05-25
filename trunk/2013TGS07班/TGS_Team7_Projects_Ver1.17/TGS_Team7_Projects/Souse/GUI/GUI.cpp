/******************************************************************************
* File Name : IUI.cpp                            Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		���[�U�[�C���^�[�t�F�[�X�t���[���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"GUI.h"
#include"../Draw/Renderer.h"
#include"GUICommand.h"
#include"../Utility/SubVector.h"
#include"../Flag/IFlagManager.h"
#include"../Input/InputState.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="collider">�Փˏ��</param>
/// <param name="command">�t���O�Ǘ���.</param>
/// <param name="command">�t���OID.</param>
GUI::GUI( Collider& collider, IFlagManager& flag, FlagID flagID ) :
	mFlagManager( flag ),
	mFlagID( flagID ),
	mCollider( collider )
{
}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[�����[�g</param>
void GUI::Update( float frameTimer )
{
	(void)frameTimer;
}

/// <summary>
/// �Փ˃t���O���X�V����.
/// </summary>
/// <param name="other">�Փˑ���</param>
void GUI::CollisionUpdate( GUI& other )
{
	if( mCollider.IsCollide( other.mCollider ) )
	{
		mCollider.mIsCollision = true;
		other.mCollider.mIsCollision = true;
	}
	else
	{
		mCollider.mIsCollision = false;
		other.mCollider.mIsCollision = false;
	}
}

/// <summary>
/// �t���[���Ƃ̈ʒu�֌W���擾����.
/// </summary>
/// <param name="angle">�p�x</param>
const GSvector2& GUI::GetFreamPositon( float angle ) const
{
	return Velocity( Angle( mCollider.mPosition ) + angle, mCollider.mPosition.length() );
}

/// <summary>
/// �t���O�̖�����.
/// </summary>
void GUI::FlagDisable()
{
	mFlagManager.FlagDisable( mFlagID );
}

/// <summary>
/// �t���O�̗L����.
/// </summary>
void GUI::FlagEnable()
{
	if( mCollider.mIsCollision && InputState::GetInstance()->IsEnterButton() )
	{
		mFlagManager.FlagEnable( mFlagID );
	}
}

/// <summary>
/// �Փˏ����擾.
/// </summary>
/// <returns>�Փˏ���Ԃ�.</returns>
Collider GUI::GetCollider() const
{
	return mCollider;
}

/********** End of File ******************************************************/
