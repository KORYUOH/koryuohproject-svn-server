/******************************************************************************
* File Name : ActorManager.cpp                          Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�A�N�^�[�}�l�[�W���[�N���X�D
*
******************************************************************************/
#include	"UnitManager.h"
#include	"../Unit/Unit.h"
#include	<algorithm>
#include	<functional>

/// <summary>
/// �R���X�g���N�^.
/// </summary>
UnitManager::UnitManager( ColliderPairManager& collder ) :
	mColliderManager( collder )
{
	// �A�N�^�[�}�l�[�W���[����������.
	Clear();
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
UnitManager:: ~UnitManager()
{
	// �A�N�^�[�}�l�[�W���[����������.
	Clear();
}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void UnitManager::Update( float frameTimer )
{
	// �����_���őS�Ă��J��Ԃ�
	each( [&](UnitPtr unit)
	{
		//�A�N�^�[���X�V������
		unit->Update(frameTimer); 
	});
}

/// <summary>
/// ���Y����.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void UnitManager::Production( float frameTimer )
{
	// �����_���őS�Ă��J��Ԃ�
	each( [&](UnitPtr unit)
	{
		//�A�N�^�[���X�V������
		unit->Production(frameTimer); 
	});
}

/// <summary>
/// �ێ��R�X�g�x��������.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void UnitManager::Maintenance( float frameTimer )
{
	// �����_���őS�Ă��J��Ԃ�
	each( [&](UnitPtr unit)
	{
		//�A�N�^�[���X�V������
		unit->Maintenance(frameTimer); 
	});
}

/// <summary>
/// �`��.
/// </summary>
void UnitManager::Draw()
{
	// �����_����
	each( [&](UnitPtr unit)
	{
		//�A�N�^�[��`�悷��
		unit->Draw();
	});
}

/// <summary>
/// UI�̕`��.
/// </summary>
void UnitManager::DrawUI()
{
	// �S���j�b�g�Ɏ��s����.
	each( [&](UnitPtr unit)
	{
		unit->DrawUI();
	});
}

/// <summary>
/// �A�N�^�[�̒ǉ�.
/// </summary>
/// <param name="actor">�ǉ�����A�N�^�[</param>
void UnitManager::Add( UnitPtr unit )
{
	//�A�N�^�[���X�g�̑O�ɒǉ�����
	mUnits.push_front( unit );
}


/// <summary>
/// ����.
/// </summary>
void UnitManager::Clear()
{
	// ���ׂĂ̗v�f���폜����
	mUnits.clear();
}


/// <summary>
/// ���S���Ă���A�N�^�[�̍폜.
/// </summary>
void UnitManager::Remove()
{
	// ���S���Ă��鎞�A�N�^�[���폜.
	mUnits.remove_if( [](UnitPtr unit)
	{
		// ���S���Ă��邩����.
		return unit->IsDead();
	});
}

/// <summary>
/// �A�N�^�[�Ԃ̏Փ˔���.
/// </summary>
/// <param name="other">����A�N�^�[</param>
void UnitManager::Collide( Unit& other )
{
	each([&]( UnitPtr unit ) 
	{
		// �A�N�^�[���Փ˂��Ă��鎞.
		if( unit->IsCollide(other) )
		{
			PairPtr addPair = std::make_shared<ColliderPair>( *unit,other );
			// �y�A��o�^����.
			mColliderManager.AddPair( addPair );
		}
	});

}

/// <summary>
/// ���̃}�l�[�W���[���Փ˔���.
/// </summary>
/// <param name="other">����}�l�[�W���[</param>
void UnitManager::Collide( UnitManager& other )
{
	// ���g�̃}�l�[�W���[��S�ČJ��Ԃ�.
	each([&]( UnitPtr unit ) 
	{
		// ����̃A�N�^�[�}�l�[�W���[�ɂ�����̃A�N�^�[�𑗂�.
		// �Փˏ������s�킹��.
		other.Collide( *unit ); 
	});

}

/*=============================================================================
*
* Purpose : foreach���ȗ�����֐��D
*
* Return  : �Ȃ�
*
*============================================================================*/
void UnitManager:: each(ActorFunction f)
{
	// foreach�֐�
	std::for_each(mUnits.begin(), mUnits.end(), f);
}

/********** End of File ******************************************************/