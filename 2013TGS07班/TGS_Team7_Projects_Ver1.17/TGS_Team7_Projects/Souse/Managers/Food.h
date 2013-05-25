/******************************************************************************
* File Name : FoodManager.h                       Ver : 1.00  Date : 2013-05-13
*
* Description :
*
*		�H���Ǘ��҃N���X�D
*
******************************************************************************/
#ifndef _FOOD_MANAGER_H_
#define _FOOD_MANAGER_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<map>

/*---- ��s�錾 -------------------------------------------------------------*/

class Unit;
class UnitParameter;
class UnitHierarchy;
typedef std::map<Unit*, float>	FoodContainer;


/// <summary>
/// �l�ފǗ���.
/// </summary>
class FoodManager
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="parameter">�p�����[�^</param>
	FoodManager();
	/// <summary>
	/// ������.
	/// </summary>
	void Initialize();
	/// <summary>
	/// �l�ނ̍ő�l���X�V����.
	/// </summary>
	/// <param name="unit">���j�b�g</param>
	void HumanUpdate( Unit* unit );
	/// <summary>
	/// �l�ނ̍ő�l���X�V����.
	/// </summary>
	/// <param name="unit">���j�b�g</param>
	/// <param name="hierarchy">�K�w</param>
	void HumanUpdate( Unit* unit, UnitHierarchy& hierarchy );
	/// <summary>
	/// �H���̒ǉ�.
	/// </summary>
	/// <param name="unit">���j�b�g</param>
	void Add( Unit* unit );
	/// <summary>
	/// �����ł���Ƃ����肷��.
	/// </summary>
	/// <param name="unit">���j�b�g</param>
	/// <param name="food">������</param>
	/// <returns>�����ł��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
	bool IsAccess( Unit* unit, float food ) const;
	/// <summary>
	/// �l�ނ𑝌�������.
	/// </summary>
	/// <param name="my">���j�b�g</param>
	/// <param food="food">������</param>
	/// <returns>�ړ��ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
	bool Fluctuation( Unit* my, float food );
	/// <summary>
	/// �l�ނ��ړ�������.
	/// </summary>
	/// <param name="my">�ړ������j�b�g</param>
	/// <param name="target">�ړ��惆�j�b�g</param>
	/// <param name="food">������</param>
	/// <returns>�ړ��ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
	bool Fluctuation( Unit* my, Unit* target, float food );
	/// <summary>
	/// ����.
	/// </summary>
	void Clear();
private:
	/// <summary>
	/// �H���R���e�i.
	/// </summary>
	FoodContainer	mFoodContainer;

};


#endif // !_HUMAN_MANAGER_H_

/********** End of File ******************************************************/