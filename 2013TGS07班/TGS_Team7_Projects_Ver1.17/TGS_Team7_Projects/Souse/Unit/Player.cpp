/******************************************************************************
* File Name : Player.cpp                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�v���C���[�N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Player.h"
#include"../Utility/Screen.h"
#include"../World/IWorld.h"
#include"../Draw/Renderer.h"
#include"../Input/InputState.h"
#include"../Utility/ToString.h"
#include"../GUI/Cursor.h"
#include"../Flag/FlagID.h"
#include"../Flag/IFlagManager.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="world">���[���h</param>
/// <param name="flag">�t���O�Ǘ���</param>
///	 <param name="position">�������W</param>
Player::Player( IWorld& world, IFlagManager& flag, const GSvector2& position ):
	Unit( world, flag, NULL, UNIT_PLAYER, position, gsGetTexture(TEXTURE_UNIT_PLAYER)->dwWidth / 2 ),
	mSelectUnit( NULL ),
	mNumber( TEXTURE_GUI_NUMBER, 16, 32 )
{
	// �A�j���[�V�����̏�����.
	mAnimation.SetTextureID( TEXTURE_UNIT_PLAYER );
	mAnimation.AddCell( "1", 0, 1,32, 32 );
	mAnimation.Initialize();

	// �J�[�\����ǉ�����.
	mElement.mGUIframe->AddGUI( std::make_shared<CursorGUI>( Collider( mCollder.mPosition,mCollder.mRadius ), mFlags, &mCollder.mPosition ) );
	// �}�l�[�W���[��GUI��o�^����.
	mWorld.AddPlayerGUI( mElement.mGUIframe );
}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void Player::Update( float frameTimer ) 
{
	static const float SPEED = 5.0F;

	// �}�E�X���g�����ړ�.
	//mCollder.mPosition = InputState::GetInstance()->GetMousePosition();
	mCollder.mPosition += InputState::GetInstance()->GetVelocity() * SPEED;

	mCollder.mPosition.x = CLAMP( mCollder.mPosition.x, mCollder.mRadius, Screen::WIDTH-mCollder.mRadius ); 
	mCollder.mPosition.y = CLAMP( mCollder.mPosition.y, mCollder.mRadius, Screen::HEIGHT-mCollder.mRadius ); 

	// �A�j���[�V�������X�V����.
	mAnimation.Update( frameTimer, "1" );

	// GUI�̑�����s��.
	GUIOperation();

}

/// <summary>
/// GUI����.
/// </summary>
void Player::GUIOperation()
{
	// �I������Ă��Ȃ���.
	if( !IsSelectUnit() )
	{
		// �����I��.
		return;
	}

	// �Ώۂ̃��x�����グ��.
	GUILevelUp();
	// ���݂̑I������������.
	GUIDeselect();
}

/// <summary>
/// GUI�̑I������.
/// </summary>
void Player::GUIDeselect()
{
	// �I��������Ă��Ȃ���.
	if( !IsSelectUnit() )
	{
		// �����I��.
		return;
	}

	// �E�C���h�E�N���[�Y�R�}���h�̎�.
	if( mFlags.IsFlag( FLAG_WINDOW_CLOSE ) || InputState::GetInstance()->IsCancelButton() )
	{
		// �E�C���h�E�����.
		WindowClose();
		return;
	}

}

/// <summary>
/// �Ώۂ̃��x�����グ��.
/// </summary>
void Player::GUILevelUp()
{
	// �I��������Ă��Ȃ���.
	if( !IsSelectUnit() )
	{
		// �����I��.
		return;
	}

	// ���x����������.
	if( mFlags.IsFlag( FLAG_FACILITY_LEVEL_UP ) )
	{
		// ���x�����グ��.
		mSelectUnit->LevelUp();
		// �t���O�𖳌��ɂ���.
		mFlags.FlagDisable( FLAG_FACILITY_LEVEL_UP );
	}

}

/// <summary>
/// ���݂̑I�������邩����.
/// </summary>
/// <returns>�I�������鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
bool Player::IsSelectUnit() const
{
	return mSelectUnit != NULL;
}

/// <summary>
/// �l�ނ̈ړ�.
/// </summary>
/// <param name="target">�ڕW���j�b�g</param>
void Player::PersonnelChange( Unit& target )
{
	// �ڕW�ƑI�����������܂��͑I��������Ă��Ȃ���.
	if( !IsSelectUnit() || &target == mSelectUnit )
	{
		// �����I��.
		return;
	}

	// ���N���b�N��������Ă��Ȃ���.
	if( !mFlags.IsFlag( FLAG_HUMAN_MUVEMENT ) || !InputState::GetInstance()->IsEnterButton() )
	{
		// �����I��.
		return;
	}

	float human = 100;
	mFlags.FlagDisable( FLAG_HUMAN_MUVEMENT );

	// �I�𒆂̃��j�b�g���ړ��ł�����.
	if( mSelectUnit->AccessHuman( -human ) )
	{
		// �ڕW�̃��j�b�g���ړ����s������.
		if( !target.AccessHuman( human ) )
		{
			// ���ɖ߂�.
			mSelectUnit->AccessHuman( human );
		}
	}
}

/// <summary>
/// �E�C���h�E�����.
/// </summary>
void Player::WindowClose()
{
	// ���݂̑I�����J������.
	mSelectUnit->GUILeave();
	mSelectUnit = NULL;
	mFlags.FlagDisable( FLAG_WINDOW_CLOSE );
}

/// <summary>
/// UI�̕`��.
/// </summary>
void Player::DrawUI()
{
	mNumber.Draw( GSvector2( 0.0f, 200.0f ), mCollder.mPosition.x );
	mNumber.Draw( GSvector2( 0.0f, 250.0f ), mCollder.mPosition.y );
}

/// <summary>
/// �Փ˂����u�Ԃ̏���.
/// </summary>
/// <param name="other">���胆�j�b�g</param>
void Player::OnCollideEnter( Unit& other )
{
	(void)other;

	mCollder.mIsCollision = true;
}

/// <summary>
/// �Փ˂��Ă���Ԃ̏���.
/// </summary>
/// <param name="other">���胆�j�b�g</param>
void Player::OnCollideStay( Unit& other )
{

	// ���N���b�N��������.
	if( InputState::GetInstance()->IsEnterButton() && mSelectUnit == NULL )
	{
		// �Փ˒��̃��j�b�g�̃p�X���擾.
		mSelectUnit = &other;
		// GUI��o�^������.
		other.GUIEntry();
	}

	// �l���ٓ�����
	PersonnelChange( other );

}

/// <summary>
/// �Փ˂����I�u�W�F�N�g�����ꂽ���̏���.
/// </summary>
/// <param name="other">���胆�j�b�g</param>
void Player::OnCollideExit( Unit& other )
{
	(void)other;

	mCollder.mIsCollision = false;
}

/********** End of File ******************************************************/
