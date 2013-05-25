/******************************************************************************
* File Name : FoodManager.cpp                     Ver : 1.00  Date : 2013-05-13
*
* Description :
*
*		�H���Ǘ��҃N���X�D
*
******************************************************************************/
#include"Food.h"
#include"../Unit/Unit.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
FoodManager::FoodManager()
{
	Clear();
}

/// <summary>
/// ������.
/// </summary>
void FoodManager::Initialize()
{
	// ����������.
	Clear();
}

/// <summary>
/// �t���O�̒ǉ�.
/// </summary>
/// <param name="unit">���j�b�g</param>
void FoodManager::Add( Unit* unit )
{
	mFoodContainer.insert( FoodContainer::value_type( unit, 0.0f ) );
}



/// <summary>
/// �����ł���Ƃ����肷��.
/// </summary>
/// <param name="unit">���j�b�g</param>
/// <param name="food">������</param>
/// <returns>�����ł��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
bool FoodManager::IsAccess( Unit* unit, float food ) const
{
	return ( food + mFoodContainer.find(unit)->second ) > 0.0f;
}

/// <summary>
/// �l�ނ𑝌�������.
/// </summary>
/// <param name="my">���j�b�g</param>
/// <param food="food">������</param>
/// <returns>�ړ��ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
bool FoodManager::Fluctuation( Unit* my, float food )
{
	if( !IsAccess( my, food ) )
	{
		return false;
	}
	mFoodContainer.find(my)->second += food;
	return true;
}

/// <summary>
/// �l�ނ��ړ�������.
/// </summary>
/// <param name="my">�ړ������j�b�g</param>
/// <param name="target">�ړ��惆�j�b�g</param>
/// <param name="food">������</param>
/// <returns>�ړ��ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
bool FoodManager::Fluctuation( Unit* my, Unit* target, float food )

{
	// �l�ނ��ǂ��炩�ړ��ł��Ȃ���.
	if( !IsAccess( my, -food ) || !IsAccess( target, food ) )
	{
		// �����I��.
		return false;
	}

	// �l�ނ𑝌�������.
	Fluctuation( my, -food );
	Fluctuation( target, food );
	return true;
}


/// <summary>
/// ����.
/// </summary>
void FoodManager::Clear()
{
	mFoodContainer.clear();
}

/********** End of File ******************************************************/