/******************************************************************************
* File Name : Unit.cpp                           Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		���j�b�g���ۃN���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Unit.h"
#include"../Utility/Screen.h"
#include"../World/IWorld.h"
#include"../Draw/TextureID.h"
#include"../Utility/Math.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="world">���[���h</param>
/// <param name="flag">�t���O�Ǘ���</param>
/// <param name="parent">�e���j�b�g</param>
/// <param name="id">���j�b�gID</param>
///	 <param name="position">�������W</param>
/// <param name="radius">�Փ˔���p�̔��a</param>
Unit::Unit( IWorld& world, IFlagManager& flag, Unit* parent, UnitID id, const GSvector2& position, float radius ):
	Actor( world, flag, position, radius ),
	mElement( id, *this ),
	mHierarchy( parent )
{
}

/// <summary>
/// ���x���A�b�v.
/// </summary>
/// <returns>����������ɏI���ΐ^�A�����łȂ���΋U��Ԃ�.</returns>
bool Unit::LevelUp()
{
	// �e�K�w���Ȃ����A�������̓��x�����ő�l�ɂȂ��Ă��鎞.
	if( mHierarchy.mParent == NULL || mElement.mLevel == UNIT_LEVEL_MAX )
	{
		// �����I��.
		return false;
	}


	// ���x���A�b�v����R�X�g���x�����Ȃ�������.
	if( mHierarchy.mParent->AccessMoney( -mWorld.GetParameter().GetLevelUpCost(mElement) ) )
	{
		// ���x�����グ��.
		mElement.mLevel++;
		// �ő僌�x���𒴂��Ȃ��悤�ɂ���.
		mElement.mLevel = MIN( mElement.mLevel , UNIT_LEVEL_MAX );
		// �l�ނ̍ő�l���X�V����.
		mElement.mHuman.SetHumanMax( mWorld.GetParameter().GetHumanMax( mElement ) );
		// ���x�����グ�ꂽ�̂Ő^��Ԃ�.
		return true;
	}

	// �R�X�g���x�����Ȃ��̂ŋU��Ԃ�.
	return false;

}

/// <summary>
/// ���x���_�E��.
/// </summary>
/// <returns>����������ɏI���ΐ^�A�����łȂ���΋U��Ԃ�.</returns>
bool Unit::LevelDown()
{
	// �e�K�w���Ȃ����A�������̓��x�����Œ�l�̎�.
	if( mHierarchy.mParent == NULL || mElement.mLevel == UNIT_LEVEL_MIN )
	{
		// �����I��.
		return false;
	}

	// ���x���A�b�v�R�X�g�̔����𕥂��߂�.
	if( !mHierarchy.mParent->AccessMoney( mWorld.GetParameter().GetLevelUpCost(mElement)*0.5f ) )
	{
		// �����߂������s�����̂ŋU��Ԃ�.
		return false;
	}

	// ���x����������.
	mElement.mLevel--;
	// ���x�����[���ɂȂ�Ȃ��悤�ɂ���.
	mElement.mLevel = Math::Max( mElement.mLevel, UNIT_LEVEL_MIN );
	// �l�ނ̍ő�l���X�V����.
	mElement.mHuman.SetHumanMax( mWorld.GetParameter().GetHumanMax( mElement ) );

	// �l�ނ̃I�[�o�[���Ă���ʂ𒲂ׂ�.
	float rezultHuman = mElement.mHuman.GetHuman() - mElement.mHuman.GetHumanMax();;

	// �ő�l���傫����.
	if( rezultHuman > 0.0f )
	{
		// �e�K�w�ɐl�ނ����.
		mHierarchy.mParent->AccessHuman( rezultHuman );
		AccessHuman( -rezultHuman );
	}

	return true;
}

/// <summary>
/// �Փˏ���.
/// </summary>
/// <param name="unit">�Փˑ��胆�j�b�g</param>
/// <returns>�Փ˂��Ă�ΐ^�A���Ă��Ȃ���΋U��Ԃ�</returns>
bool Unit::IsCollide( Unit& unit )
{
	return mCollder.IsCollide( unit.mCollder );
}

/// <summary>
/// �Փ˂����u�Ԃ̏���.
/// </summary>
/// <param name="other">���胆�j�b�g</param>
void Unit::OnCollideEnter( Unit& other )
{
	(void)other;
	mCollder.mIsCollision = true;
}

/// <summary>
/// �Փ˂��Ă���Ԃ̏���.
/// </summary>
/// <param name="other">���胆�j�b�g</param>
void Unit::OnCollideStay( Unit& other )
{
	(void)other;
}

/// <summary>
/// �Փ˂����I�u�W�F�N�g�����ꂽ���̏���.
/// </summary>
/// <param name="other">���胆�j�b�g</param>
void Unit::OnCollideExit( Unit& other )
{
	(void)other;
	mCollder.mIsCollision = false;
}

/// <summary>
/// ���j�b�g�̒ǉ�.
/// </summary>
/// <param name="id">�ǉ�������</param>
/// <param name="frameTimer">���j�b�g</param>
void Unit::AddUnit( UnitID id, UnitPtr unit )
{
	// ���[���h�ɒǉ�.
	mWorld.Add( id, unit );
	// �q�K�w�ɒǉ�.
	mHierarchy.mChild.push_back( unit.get() );
}

/// <summary>
/// ���j�b�g�̍폜.
/// </summary>
/// <param name="frameTimer">���j�b�g</param>
void Unit::DeletUnit( Unit* unit )
{
	mHierarchy.mChild.remove( unit );
}

/// <summary>
/// �H���ւ̃A�N�Z�X.
/// </summary>
/// <param name="food">�H���̑�����</param>
/// <returns>����ɃA�N�Z�X�ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
bool Unit::AccessFood( float food )
{
	(void)food;
	return false;
}

/// <summary>
/// �����ւ̃A�N�Z�X.
/// </summary>
/// <param name="money">�����̑�����</param>
/// <returns>����ɃA�N�Z�X�ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
bool Unit::AccessMoney( float money )
{
	(void)money;
	return false;
}

/// <summary>
/// �l�ނւ̃A�N�Z�X.
/// </summary>
/// <param name="human">�l�̑�����</param>
/// <returns>����ɃA�N�Z�X�ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
bool Unit::AccessHuman( float human )
{
	// �l�ނ̐l���ٓ����\�̎�.
	if( !mElement.mHuman.IsPersonnelChange( human ) )
	{
		return false;
	}

	// �l���ٓ�������.
	mElement.mHuman.PersonnelChange( human );

	return true;
}


/// <summary>
/// �v�f�̎擾.
/// </summary>
/// <returns>���j�b�g�̗v�f��Ԃ�</returns>
const UnitElement& Unit::GetElement() const
{
	return mElement;
}

/// <summary>
/// GUI�̓o�^.
/// </summary>
void Unit::GUIEntry()
{
	mElement.mGUIframe->FlagDisable();
	// GUI��ǉ�����.
	mWorld.AddGUI( mElement.mGUIframe );
}

/// <summary>
/// GUI�̓o�^����.
/// </summary>
void Unit::GUILeave()
{
	mElement.mGUIframe->FlagDisable();
	// GUI��ǉ�����.
	mWorld.DeleteGUI( mElement.mGUIframe );
}

/// <summary>
/// �e�K�w������������.
/// </summary>
/// <param name="other">��r���j�b�g</param>
/// <returns>��������ΐ^�A�����łȂ���΋U��Ԃ�.</returns>
bool Unit::IsParent( const Unit& other ) const
{
	return mHierarchy.mParent == other.mHierarchy.mParent;
}

/********** End of File ******************************************************/