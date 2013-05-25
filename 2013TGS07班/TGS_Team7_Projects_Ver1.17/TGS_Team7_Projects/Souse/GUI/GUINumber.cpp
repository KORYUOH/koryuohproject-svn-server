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
#include"GUINumber.h"
#include"../Draw/Renderer.h"
#include"../Draw/TextureID.h"
#include"../Utility/ToString.h"
#include"../Flag/FlagID.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="collider">�Փˏ��</param>
/// <param name="flagManager">�t���O�Ǘ���</param>
/// <param name="drawNumber">�`�悷�鐔���ւ̃p�X</param>
GUINumber::GUINumber( Collider& collider, IFlagManager& flagManager, float* drawNumber  ) :
	GUI( collider, flagManager, FLAG_NONE ),
	mNumber( drawNumber ),
	mDrawNumber( TEXTURE_GUI_NUMBER, 10, 16 )
{
}


/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[�����[�g</param>
void GUINumber::Update( float frameTimer )
{
}

/// <summary>
/// �`��.
/// </summary>
/// <param name="position">�t���[���̈ʒu</param>
/// <param name="angle">�p�x</param>
void GUINumber::Draw( const GSvector2& position, float angle ) const
{
	(void)position;
	(void)angle;

	// �摜�̒��S.
	const GSvector2 center( -mCollider.mRadius, -mCollider.mRadius );

	// �{�^����`��.
	//mNumber.Draw( 
}

/********** End of File ******************************************************/
