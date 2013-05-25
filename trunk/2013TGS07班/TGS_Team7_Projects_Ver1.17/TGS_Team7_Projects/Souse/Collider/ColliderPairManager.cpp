/******************************************************************************
* File Name : ColliderPair.h                      Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�Փ˃y�A�Ǘ��҃N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"ColliderPairManager.h"
#include<algorithm>

/// <summary>
/// �R���X�g���N�^.
/// </summary>
ColliderPairManager::ColliderPairManager()
{
	Clear();
}

/// <summary>
/// �y�A�̒ǉ�.
/// </summary>
void ColliderPairManager::AddPair( PairPtr& pair )
{
	mPairEntry.push_back( pair );
}

/// <summary>
/// �y�A�̃\�[�g.
/// </summary>
void ColliderPairManager::SortPair()
{

	// �\�[�g����.
	//mPairEntry.sort();
	//mPairsRun.sort();

	// ���s�y�A���Ȃ���.
	if( mPairsRun.size() == 0 )
	{
		return;
	}


	// ���s�y�A�����[�v������.
	for( PairConter::iterator run = mPairsRun.begin(); run != mPairsRun.end() ; run++ )
	{
		// �p���I�ȃy�A��T��.
		SortEntryPair( run );

		// ����̏Փ˂ɔ�������Ă��Ȃ���.
		if( run->get()->mType == PAIR_DELLETE )
		{
			PairConter::iterator delPair = run;
			mPairsDel.push_back( *delPair );
			//mPairsRun.erase( delPair );
			//run--;
		}
	}

	// �j�������v�f���폜����.
	mPairsRun.remove_if( [](PairPtr Pair)
	{
		// ���S���Ă��邩����.
		return Pair->mType == PAIR_DELLETE;
	});
}

/// <summary>
/// �V�K�y�A�̃\�[�g.
/// </summary>
/// <param name="run">���s�y�A</param>
void ColliderPairManager::SortEntryPair( PairConter::iterator& run )
{
	ColliderPair& runPair = *run->get();

	// �V�K�y�A�����[�v������.
	for( PairConter::iterator entry = mPairEntry.begin() ; entry != mPairEntry.end() ; entry++ )
	{

		ColliderPair& entryPair = *entry->get();

		// �V�K�y�A�̒��Ɍp���I�ȏՓ˂����鎞.
		if( runPair == entryPair )
		{
			run->get()->mType = PAIR_KEEP;
			mPairEntry.erase( entry );
			// �����I��.
			return;
		}
	}
}

/// <summary>
/// �Փˉ�������.
/// </summary>
void ColliderPairManager::CollisionResponse()
{
	// �p���y�A�̏Փˉ����������s��.
	CollideStay();
	// �V�K�y�A�̏Փˉ����������s��.
	CollideEnter();
	// �������ꂽ�y�A�̏Փˉ����������s��.
	CollideExit();
}

/// <summary>
/// �V�K�Փˏ���.
/// </summary>
void ColliderPairManager::CollideEnter()
{
	if( mPairEntry.size() == 0 )
	{
		return;
	}
	// �Փ˃y�A���J��Ԃ�.
	std::for_each( mPairEntry.begin(), mPairEntry.end(), []( PairPtr pair )
	{
		pair->CollisionResponse();
		pair->mType = PAIR_DELLETE;
	});

	// ���s�y�A�ɐV�K�y�A�𕹍�����.
	mPairsRun.merge( mPairEntry );
	// �V�K�y�A������������.
	mPairEntry.clear();
}

/// <summary>
/// �p���Փˏ���.
/// </summary>
void ColliderPairManager::CollideStay()
{
	if( mPairsRun.size() == 0 )
	{
		return;
	}
	// �Փ˃y�A���J��Ԃ�.
	std::for_each( mPairsRun.begin(), mPairsRun.end(), []( PairPtr pair )
	{
		pair->CollisionResponse();
		pair->mType = PAIR_DELLETE;
	});
}

/// <summary>
/// �Փˉ����㏈��.
/// </summary>
void ColliderPairManager::CollideExit()
{
	if( mPairsDel.size() == 0 )
	{
		return;
	}
	// �Փ˃y�A���J��Ԃ�.
	std::for_each( mPairsDel.begin(), mPairsDel.end(), []( PairPtr pair )
	{
		pair->CollisionResponse();
	});
	// �폜�y�A����������.
	mPairsDel.clear();
}

/// <summary>
/// ����.
/// </summary>
void ColliderPairManager::Clear()
{
	mPairEntry.clear();
	mPairsRun.clear();
	mPairsDel.clear();
}

/********** End of File ******************************************************/
