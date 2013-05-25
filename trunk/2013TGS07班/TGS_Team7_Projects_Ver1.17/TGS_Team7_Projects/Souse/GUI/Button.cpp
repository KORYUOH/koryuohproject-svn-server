/******************************************************************************
* File Name : Button.cpp                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		���[�U�[�C���^�[�t�F�[�X�t���[���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Button.h"
#include"GUICommand.h"
#include"../Draw/Renderer.h"
#include"../Draw/TextureID.h"
#include"../Utility/ToString.h"



/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="collider">�Փˏ��</param>
/// <param name="flag">�t���O�Ǘ���.</param>
/// <param name="flagID">�t���OID.</param>
/// <param name="textureID">�e�N�X�`��ID.</param>
Button::Button( Collider& collider, IFlagManager& flag, FlagID flagID, TextureID textureID ):
	GUI( collider, flag, flagID ),
	mAnimation( textureID )
{
	mAnimation.AddCell( BoolToString(true), 0, 1, 32, 32 );
	mAnimation.AddCell( BoolToString(false), 1, 1, 32, 32 );
	mAnimation.Initialize();
}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[�����[�g</param>
void Button::Update( float frameTimer )
{
	// �A�j���[�V�������X�V����.
	mAnimation.Update( frameTimer, BoolToString(mCollider.mIsCollision) );

	// �t���O��L���ɂ���.
	FlagEnable();
}

/// <summary>
/// �`��.
/// </summary>
/// <param name="position">�t���[���̈ʒu</param>
/// <param name="angle">�p�x</param>
void Button::Draw( const GSvector2& position, float angle ) const
{
	// ���S�ʒu.
	GSvector2 center( mCollider.mRadius, mCollider.mRadius );

	// �{�^����`��.
	mAnimation.Draw( mCollider.mPosition+position, center, angle );
}

/********** End of File ******************************************************/
