/******************************************************************************
* File Name : GUIBarChart.cpp                    Ver : 1.00  Date : 2013-05-06
*
* Description :
*
*		�_�O���tGUI�N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"GUIBarChart.h"
#include"../Draw/Renderer.h"
#include"../Draw/TextureID.h"
#include"GUICommand.h"
#include"../Utility/SubVector.h"
#include"../Flag/FlagID.h"

/// <summary>
/// �X�P�[���{��.
/// </summary>
const float GUIBarChart::SCALE_RATE = 0.5F;

/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="collider">�Փˏ��</param>
/// <param name="flagManager">�t���O�Ǘ���</param>
/// <param name="maxValue">�l�ւ̃p�X</param>
/// <param name="angle">�p�x</param>
/// <param name="color">�F</param>
GUIBarChart::GUIBarChart( Collider& collider, IFlagManager& flagManager, float* value, float angle, const GScolor& color ) :
	GUI( collider, flagManager, FLAG_NONE ),
	mValue( value ),
	mAngle( angle ),
	mColor( color )
{
}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[�����[�g</param>
void GUIBarChart::Update( float frameTimer )
{
	(void)frameTimer;
}

/// <summary>
/// �`��.
/// </summary>
/// <param name="position">�t���[���̈ʒu</param>
/// <param name="angle">�p�x</param>
void GUIBarChart::Draw( const GSvector2& position, float angle ) const
{
	// �摜�̒��S.
	GSvector2 center( mCollider.mRadius, 0.0f );

	float value = *mValue * SCALE_RATE;

	// �`��ʒu.
	GSvector2 pos = GetFreamPositon( angle );

	// �O���t�̍���������`�悷��.
	Renderer::GetInstance()->DrawTexture( TEXTURE_GUI_BAR_CHART, pos+position, center, mAngle+angle, GSvector2(1.0f,value), mColor );

}

/********** End of File ******************************************************/
