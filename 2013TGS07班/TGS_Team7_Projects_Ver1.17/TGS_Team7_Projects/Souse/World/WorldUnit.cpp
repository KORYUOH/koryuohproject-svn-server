/******************************************************************************
* File Name : WorldActor.cpp                     Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		���[���h���j�b�g�N���X�D
*
******************************************************************************/
#include	"WorldUnit.h"
#include	"UnitManager.h"
#include	"../Unit/UnitID.h"
#include	"../Unit/UnitPtr.h"
#include	<algorithm>


/// <summary>
/// �R���X�g���N�^.
/// </summary>
WorldUnit::WorldUnit():
	mColliderManager()
{
	// �A�N�^�[�}�l�[�W���[�̏�����.
	Clear();

	// �A�N�^�[�}�l�[�W���[�𐶐�.
	AddManager( UNIT_PLAYER );
	AddManager( UNIT_CAMERA );
	AddManager( UNIT_SPACE );
	AddManager( UNIT_STAR );
	AddManager( UNIT_HOUSING );
	AddManager( UNIT_FARM );
	AddManager( UNIT_FACTORY );


}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
WorldUnit::~WorldUnit()
{
}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void WorldUnit::Update( float frameTimer )
{
	// ���ׂẴ}�l�[�W���[���X�V.
	each( [&]( UnitManagerPtr manager )
	{
		manager->Update( frameTimer ); 
	});

	mManagers[UNIT_PLAYER]->Collide( *mManagers[UNIT_STAR] );
	mManagers[UNIT_PLAYER]->Collide( *mManagers[UNIT_HOUSING] );
	mManagers[UNIT_PLAYER]->Collide( *mManagers[UNIT_FACTORY] );
	mManagers[UNIT_PLAYER]->Collide( *mManagers[UNIT_FARM] );


	// ���ׂẴ}�l�[�W���[�̃A�N�^�[�폜
	each([&](UnitManagerPtr manager)
	{ 
		// ���S���Ă���A�N�^�[���폜
		manager->Remove(); 
	});

	// �y�A���\�[�g����.
	mColliderManager.SortPair();
	// �Փ˃y�A�̏Փˉ����������s��.
	mColliderManager.CollisionResponse();
}

/// <summary>
/// ���Y����.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void WorldUnit::Production( float frameTimer )
{
	// ���ׂẴ��j�b�g�}�l�[�W���[�ɐ����������s�킹��.
	each( [&]( UnitManagerPtr manager )
	{
		manager->Production( frameTimer );
	});
}

/// <summary>
/// �ێ��R�X�g�x��������.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void WorldUnit::Maintenance( float frameTimer )
{
		// ���ׂẴ��j�b�g�}�l�[�W���[�Ɉێ��R�X�g�������s�킹��.
	each( [&]( UnitManagerPtr manager )
	{
		manager->Maintenance( frameTimer );
	});
}

/// <summary>
/// �`��.
/// </summary>
void WorldUnit::Draw()
{
	// ���ׂẴ}�l�[�W���[�̕`��
	each([&](UnitManagerPtr manager) 
	{ 
		manager->Draw(); 
	});
}

/// <summary>
/// UI�̕`��.
/// </summary>
void WorldUnit::DrawUI()
{
	// ���ׂẴ}�l�[�W���[��UI�̕`��.
	each( [&](UnitManagerPtr manager)
	{
		manager->DrawUI();
	});
}

/// <summary>
/// �A�N�^�[�̒ǉ�.
/// </summary>
/// <param name="id">�A�N�^�[�}�l�[�W��ID</param>
/// <param name="unit">�ǉ�����A�N�^�[</param>
void WorldUnit::Add( UnitID id, UnitPtr unit )
{
	// �w�肵���}�l�[�W���[�Ɉ����̃A�N�^�[��ǉ�
	mManagers[id]->Add(unit);
}

/// <summary>
/// �}�l�[�W���[�̒ǉ�.
/// </summary>
/// <param name="id">�ǉ�����A�N�^�[�}�l�[�W��ID</param>
void WorldUnit::AddManager( UnitID id )
{
	// �}�l�[�W���[��ǉ�.
	mManagers[id] = std::make_shared<UnitManager>(mColliderManager);
}

/// <summary>
/// ����.
/// </summary>
void WorldUnit::Clear()
{
	// ���ׂẴ}�l�[�W���[�̃A�N�^�[�폜���s��.
	each([](UnitManagerPtr manager) 
	{ 
		// �A�N�^�[�̍폜.
		manager->Clear(); 
	});

	// �ՓˊǗ��҂�����.
	mColliderManager.Clear();
}

/// <summary>
/// foreach�̏ȗ��錾.
/// </summary>
void WorldUnit::each(UnitManagerFunction f)
{
	std::for_each(mManagers.begin(), mManagers.end(),[&](UnitManagerPair pair) 
	{
		f(pair.second); 
	});
}

/********** End of File ******************************************************/