/******************************************************************************
* File Name : Cursor.cpp                            Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�J�[�\��GUI�N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Cursor.h"
#include"../Draw/Renderer.h"
#include"../Draw/TextureID.h"
#include"GUICommand.h"
#include"../Utility/ToString.h"
#include"../Flag/FlagID.h"

	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="collider">�Փˏ��</param>
	/// <param name="flagManager">�t���O�Ǘ���</param>
	/// <param name="position">�ʒu���</param>
CursorGUI::CursorGUI( Collider& collider, IFlagManager& flagManager, const GSvector2* position ) :
	GUI( collider, flagManager, FLAG_NONE ),
	mAnimation( TEXTURE_UNIT_PLAYER ),
	mPosition( position )
{
	mAnimation.AddCell( "1", 0, 1,32, 32 );
	mAnimation.Initialize();
}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[�����[�g</param>
void CursorGUI::Update( float frameTimer )
{
	// �ʒu���X�V����.
	mCollider.mPosition = *mPosition;

	// �A�j���[�V�������X�V����.
	mAnimation.Update( frameTimer, "1" );
}

/// <summary>
/// �`��.
/// </summary>
/// <param name="position">�t���[���̈ʒu</param>
/// <param name="angle">�p�x</param>
void CursorGUI::Draw( const GSvector2& position, float angle ) const
{
	// �摜�̒��S.
	GSvector2 center( mCollider.mRadius, mCollider.mRadius );

	// �{�^����`��.
	mAnimation.Draw( mCollider.mPosition+position, center, angle );
}

/********** End of File ******************************************************/
