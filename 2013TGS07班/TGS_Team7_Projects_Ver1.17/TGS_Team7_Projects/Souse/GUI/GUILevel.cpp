/******************************************************************************
* File Name : GUILevel.cpp                        Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		���x��GUI�N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"GUILevel.h"
#include"../Draw/Renderer.h"
#include"../Draw/TextureID.h"
#include"GUICommand.h"
#include"../Utility/SubVector.h"
#include"../Flag/FlagID.h"

	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="collider">�Փˏ��</param>
	/// <param name="flagManager">�t���O�Ǘ���</param>
	/// <param name="level">���x���ւ̃p�X</param>
	/// <param name="angle">�p�x</param>
GUILevel::GUILevel( Collider& collider, IFlagManager& flagManager, int* level, float angle ) :
	GUI( collider, flagManager, FLAG_NONE ),
	mLevel( level ),
	mAngle( angle )
{
}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[�����[�g</param>
void GUILevel::Update( float frameTimer )
{
	(void)frameTimer;
}

/// <summary>
/// �`��.
/// </summary>
/// <param name="position">�t���[���̈ʒu</param>
/// <param name="angle">�p�x</param>
void GUILevel::Draw( const GSvector2& position, float angle ) const
{
	// �摜�̒��S.
	GSvector2 center( mCollider.mRadius, mCollider.mRadius );

	// �`��ʒu�̏C����
	GSvector2 vec = Velocity( mAngle-90.0f, mCollider.mRadius*2.0f );

	// �`��ʒu.
	//GSvector2 pos( mCollider.mPosition );

	// �`��ʒu.
	GSvector2 pos = GetFreamPositon( angle );

	// ���x���̌��J��Ԃ�.
	for( int i = 0 ; i < *mLevel ; i++ )
	{
		// �`�悷��.
		Renderer::GetInstance()->DrawTexture( TEXTURE_GUI_LEVEL, pos+position, center, mAngle+angle );

		// �ʒu�����炷.
		pos += vec;
	}

}

/********** End of File ******************************************************/
