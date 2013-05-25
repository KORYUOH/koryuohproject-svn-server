/******************************************************************************
* File Name : Factory.cpp                        Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�H��{�݃N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Factory.h"
#include"../World/IWorld.h"
#include"../Draw/Renderer.h"
#include"../Utility/ToString.h"
#include"../GUI/Button.h"
#include"../Utility/SubVector.h"
#include"../GUI/GUILevel.h"
#include"../GUI/GUIBarChart.h"
#include"../Flag/FlagID.h"

	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="world">���[���h</param>
	/// <param name="flag">�t���O�Ǘ���</param>
	/// <param name="parent">�e���j�b�g</param>
	///	 <param name="collider">���̏Փˏ��</param>
	/// <param name="angle">�����猩���p�x</param>
Factory::Factory( IWorld& world, IFlagManager& flag, Unit* parent, const Collider& collider, float angle ):
	Unit( world, flag, parent, UNIT_FACTORY , collider.mPosition, collider.mRadius ),
	mNumber( TEXTURE_GUI_NUMBER , 10,16 ),
	mAngle( angle+90.0f )
{
	// �����̕\��������ݒ�.
	mNumber.SetField( 6 );

	// �l�ނ̍ő�l���擾����.
	mElement.mHuman.SetHumanMax( mWorld.GetParameter().GetHumanMax(mElement) );

	// �A�j���[�V������ݒ�.
	mAnimation.SetTextureID( TEXTURE_UNIT_FACTORY );
	mAnimation.AddCell( "1", 0, 1, 64, 64 );
	mAnimation.Initialize();

	// �ʒu��ݒ�.
	float radius = gsGetTexture( TEXTURE_UNIT_HOUSE )->dwHeight / 2;
	mCollder.mPosition = mCollder.mPosition + Velocity( angle, mCollder.mRadius+radius);
	mCollder.mRadius = radius;

	// ����Փ˂��Ȃ�GUI��ݒ�
	GSvector2 vec = Velocity( angle, mCollder.mRadius*2.0f );
	GUIFramePtr guiFrame = std::make_shared<GUIFrame>( vec+mCollder.mPosition, mAngle );
	guiFrame->AddGUI( std::make_shared<GUILevel>( Collider(GSvector2(-12.0f,0.0f),8.0f), mFlags, &mElement.mLevel, mAngle ) );
	//guiFrame->AddGUI( std::make_shared<GUIBarChart>( Collider(GSvector2(0.0f,0.0f), 8.0f), mFlags, &mElement.mHumanMax, 180.0f, GScolor(0.0f,1.0f,1.0f,1.0f) ) ); 
	//guiFrame->AddGUI( std::make_shared<GUIBarChart>( Collider(GSvector2(0.0f,0.0f), 8.0f), mFlags, &mElement.mHuman, 180.0f, GScolor(1.0f,0.0f,0.0f,1.0f) ) ); 
	mWorld.AddGUI( guiFrame );

	// GUI��ǉ�
	// �l�ވړ��{�^����ǉ�����.
	mElement.mGUIframe->AddGUI( std::make_shared<Button>( Collider( GSvector2(20.0f,20.0f),16.0f ), mFlags, FLAG_HUMAN_MUVEMENT, TEXTURE_GUI_BUTTON) );
	// ���x���A�b�v�{�^����ǉ�����.
	mElement.mGUIframe->AddGUI( std::make_shared<Button>( Collider( GSvector2(60.0f,20.0f),16.0f ), mFlags, FLAG_FACILITY_LEVEL_UP, TEXTURE_GUI_BOTTON_LEVEL_UP) );
	mElement.mGUIframe->AddWindow( mFlags );
}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void Factory::Update( float frameTimer )
{
	mAnimation.Update( frameTimer, "1" );
	//mAnimation.Update( frameTimer, IntToString( mElement.mLevel ) );

}

/// <summary>
/// ���Y����.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void Factory::Production( float frameTimer )
{
	// �����𐶎Y����.
	mHierarchy.mParent->AccessMoney( mWorld.GetParameter().GetProduction( mElement ) * frameTimer );
}

/// <summary>
/// �ێ��R�X�g�x��������.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void Factory::Maintenance( float frameTimer )
{
	// �ێ��R�X�g(�����𕥂�)
	if( !mHierarchy.mParent->AccessMoney( -mWorld.GetParameter().GetCost(mElement) * frameTimer ) )
	{
		// �������x�����Ȃ��̂Ń��x����������.
		LevelDown();
	}
}

/// <summary>
/// �`��.
/// </summary>
void Factory::Draw()
{
	// �摜�̒��S�_.
	const GSvector2 center( mCollder.mRadius,mCollder.mRadius );

	// �Փ˂��Ă��鎞.
	if( mCollder.mIsCollision )
	{
		// �_�ł��ĕ`�悷��.
		mAnimation.DrawBlink( mCollder.mPosition, center, mAngle );
	}
	else
	{
		// ���ʂɕ`�悷��.
		mAnimation.Draw( mCollder.mPosition, center, mAngle );
	}
}

/// <summary>
/// UI�̕`��.
/// </summary>
void Factory::DrawUI()
{
}


/********** End of File ******************************************************/
