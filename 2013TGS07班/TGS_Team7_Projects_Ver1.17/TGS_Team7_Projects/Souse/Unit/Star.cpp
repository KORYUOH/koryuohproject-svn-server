/******************************************************************************
* File Name : Star.cpp                           Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�f���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Star.h"
#include"../World/IWorld.h"
#include"../Draw/Renderer.h"
#include"../Input/InputState.h"
#include"Housing.h"
#include"Farm.h"
#include"Factory.h"
#include<algorithm>
#include"../GUI/Button.h"
#include"../GUI/GUICommand.h"
#include"../Utility/SubVector.h"
#include"../Flag/IFlagManager.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="world">���[���h</param>
/// <param name="flag">�t���O�Ǘ���</param>
/// <param name="parent">�e���j�b�g</param>
///	 <param name="position">�������W</param>
Star::Star( IWorld& world, IFlagManager& flag, Unit* parent, const GSvector2& position ):
	Unit( world, flag, parent, UNIT_STAR, position, gsGetTexture(TEXTURE_UNIT_STAR)->dwWidth/2 ),
	mHumanResources( 0 ),
	mFood( 0 ),
	mNumber( TEXTURE_GUI_NUMBER, 16, 32 )
{
	// �����̕\��������ݒ�.
	mNumber.SetField( 6 );

	// �A�j���[�V������ݒ�.
	mAnimation.SetTextureID( TEXTURE_UNIT_STAR );
	mAnimation.AddCell( "1", 0, 1, mCollder.mRadius*2, mCollder.mRadius*2 );
	mAnimation.Initialize();

	mElement.mGUIframe->AddWindow( mFlags );
	// �Z��{�݃{�^����ǉ�����.
	mElement.mGUIframe->AddGUI( std::make_shared<Button>( Collider( GSvector2(20.0f,20.0f),16.0f ), mFlags, FLAG_CREATE_HOUSING, TEXTURE_GUI_BOTTON_HOUSING ) );
	// �H��{�݃{�^����ǉ�����.
	mElement.mGUIframe->AddGUI( std::make_shared<Button>( Collider( GSvector2(80.0f,20.0f),16.0f ), mFlags, FLAG_CREATE_FACTORY, TEXTURE_GUI_BOTTON_FACTORY ) );
	// �_��{�݃{�^����ǉ�����.
	mElement.mGUIframe->AddGUI( std::make_shared<Button>( Collider( GSvector2(140.0f,20.0f),16.0f ), mFlags, FLAG_CREATE_FARM, TEXTURE_GUI_BOTTON_FRAM ) );

}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void Star::Update( float frameTimer ) 
{
	// �A�j���[�V�������X�V����.
	mAnimation.Update( frameTimer, "1" );


	//mElement.mHuman = 0;
	// �l�ނ̏�����.
	mElement.mHuman.Initialize();

	float humanMax = 0;
	float human = 0;

	std::for_each( mHierarchy.mChild.begin(), mHierarchy.mChild.begin(), [&]( Unit* unit )
	{
		if( mElement.mID == UNIT_HOUSING )
		{
			humanMax += unit->GetElement().mHuman.GetHumanMax();
		}
		human += unit->GetElement().mHuman.GetHuman();
	});

	mElement.mHuman.SetHumanMax( humanMax );
	mElement.mHuman.PersonnelChange( human );

	// �R�}���h����V���Ȏ{�݂����.
	CreateFacility();

}

/// <summary>
/// ���Y����.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void Star::Production( float frameTimer )
{
	(void)frameTimer;
}

/// <summary>
/// �ێ��R�X�g�x��������.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void Star::Maintenance( float frameTimer )
{
	// �H�������炷.
	mFood -= mElement.mHuman.GetHuman() * frameTimer * 0.005f;
	// �}�C�i�X�ɂȂ�̂�h��.
	mFood = MAX( mFood , 0 );
}

/// <summary>
/// �`��.
/// </summary>
void Star::Draw()
{


	// ���S�ʒu.
	GSvector2 center( mCollder.mRadius, mCollder.mRadius );

	if( mCollder.mIsCollision )
	{
		// �_�ł��ĕ`�悷��.
		mAnimation.DrawBlink( mCollder.mPosition , center );
	}
	else
	{
		// ���ʂɕ`�悷��.
		mAnimation.Draw( mCollder.mPosition , center );
	}

}


/// <summary>
/// UI�̕`��.
/// </summary>
void Star::DrawUI()
{
	/*---- �l�ނ̍ő�l�̕`�� -----------------------------------------------*/

	// �l��.
	Renderer::GetInstance()->DrawTexture( TEXTURE_GUI_HUMAN_MAX , mCollder.mPosition+GSvector2(75.0f,0.0f) );
	// ������\��.
	mNumber.Draw( mCollder.mPosition+GSvector2(150.0f,10.0f) , (int)mElement.mHuman.GetHumanMax() );

	/*---- �l�ނ̌��ݒl�̕`�� -----------------------------------------------*/

	// �l��.
	Renderer::GetInstance()->DrawTexture( TEXTURE_GUI_HUMAN , mCollder.mPosition+GSvector2(75.0f,40.0f) );
	// ������\��.
	mNumber.Draw( mCollder.mPosition+GSvector2(150.0f,40.0f) , (int)mElement.mHuman.GetHuman() );

	/*---- �H���̌��ݒl�̕`�� -----------------------------------------------*/

	// �H��.
	Renderer::GetInstance()->DrawTexture( TEXTURE_GUI_FOOD, mCollder.mPosition+GSvector2(75.0f,80.0f) );
	// ������\��.
	mNumber.Draw( mCollder.mPosition+GSvector2(150.0f,80.0f), (int)mFood );
}

/// <summary>
/// �H���ւ̃A�N�Z�X.
/// </summary>
/// <param name="food">�H���̑�����</param>
/// <returns>����ɃA�N�Z�X�ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
bool Star::AccessFood( float food )
{
	float rezultFood = mFood + food;

	if( rezultFood < 0.0f )
	{
		return false;
	}

	// ���ʂ𔽉f����.
	mFood = rezultFood;

	return true;
}

/// <summary>
/// �����ւ̃A�N�Z�X.
/// </summary>
/// <param name="money">�����̑�����</param>
/// <returns>����ɃA�N�Z�X�ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
bool Star::AccessMoney( float money )
{
	// �������F���֑���.
	return mHierarchy.mParent->AccessMoney( money );
}

/// <summary>
/// �l�ނւ̃A�N�Z�X.
/// </summary>
/// <param name="human">�l�̑�����</param>
/// <returns>����ɃA�N�Z�X�ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
bool Star::AccessHuman( float human )
{
	for( std::list<Unit*>::iterator it = mHierarchy.mChild.begin() ; it != mHierarchy.mChild.end() ; it++  )
	{
		// �^�̒u���Ȃ���.
		Unit* unit = *it;

		// ���j�b�g���Z��{�݂̎�.
		if( unit->GetElement().mID == UNIT_HOUSING )
		{
			// �l�ނɃA�N�Z�X.
			if( unit->AccessHuman( human ) )
			{
				// �A�N�Z�X�ł����̂Ő^��Ԃ�.
				return true;
			}
		}
	}

	// �Z��{�݂��Ȃ����߃A�N�Z�X�Ɏ��s���܂���.
	return false;

}

/// <summary>
/// �{�݂̍쐬.
/// </summary>
void Star::CreateFacility()
{
	// �{�݂̍ő�l.
	const int FACILITY_MAX = 8;
	// �p�x�̍ő�l.
	const int ANGLE_MAX = 360;

	// �{�݂̍ő�l�𒴂��Ă�����.
	if( mHierarchy.mChild.size() >= FACILITY_MAX )
	{
		// �����I��.
		return;
	}

	// ���݌��ƍő�l���玟�̎{�݂̊p�x�����߂�.
	float angle = mHierarchy.mChild.size() * (ANGLE_MAX / FACILITY_MAX) - 90.0f;

	// �{�݂��쐬����.
	CreateHousing( angle );
	CreateFactory( angle );
	CreateFarm( angle );

}

/// <summary>
/// �Z��{�݂̍쐬.
/// </summary>
/// <param name="angle">�p�x</param>
void Star::CreateHousing( float angle )
{
	// �Z��{�݂��쐬.
	if( mFlags.IsFlag( FLAG_CREATE_HOUSING ) )
	{
		UnitPtr unit = std::make_shared<Housing>
			( mWorld, mFlags, &*this, mCollder, angle );
		// �Z��{�݂�ǉ�.
		AddUnit( UNIT_HOUSING, unit );
		// �t���O�𖳌��ɂ���.
		mFlags.FlagDisable( FLAG_CREATE_HOUSING );
	}
}

/// <summary>
/// �{�݂̍쐬.
/// </summary>
/// <param name="angle">�p�x</param>
void Star::CreateFactory( float angle )
{
	// �H��{�݂��쐬.
	if( mFlags.IsFlag( FLAG_CREATE_FACTORY ) )
	{
		UnitPtr unit = std::make_shared<Factory>
			( mWorld, mFlags, &*this, mCollder, angle );
		// �H��{�݂�ǉ�.
		AddUnit( UNIT_FACTORY, unit );
		// �t���O�𖳌��ɂ���.
		mFlags.FlagDisable( FLAG_CREATE_FACTORY );
	}
}

/// <summary>
/// �_��{�݂̍쐬.
/// </summary>
/// <param name="angle">�p�x</param>
void Star::CreateFarm( float angle )
{
	// �_��{�݂��쐬.
	if( mFlags.IsFlag( FLAG_CREATE_FARM ) )
	{
		UnitPtr unit = std::make_shared<Farm>
			( mWorld, mFlags, &*this, mCollder, angle);
		// �_��{�݂�ǉ�.
		AddUnit( UNIT_FARM, unit );
		// �t���O�𖳌��ɂ���.
		mFlags.FlagDisable( FLAG_CREATE_FARM );

	}
}

/********** End of File ******************************************************/
