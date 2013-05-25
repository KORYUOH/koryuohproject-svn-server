/******************************************************************************
* File Name : UnitStateManager.h                  Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		���j�b�g��ԊǗ��҃N���X�D
*
******************************************************************************/
#ifndef _HUMAN_MANAGER_H_
#define _HUMAN_MANAGER_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<map>

/*---- ��s�錾 -------------------------------------------------------------*/

class Unit;
class UnitParameter;
class UnitHierarchy;
typedef std::map<Unit*, float>	HumanContainer;


/// <summary>
/// ���j�b�g��ԊǗ���.
/// </summary>
class UnitStateManager
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="parameter">�p�����[�^</param>
	UnitStateManager( UnitParameter& parameter );
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
	/// �t���O�̒ǉ�.
	/// </summary>
	/// <param name="unit">���j�b�g</param>
	void Add( Unit* unit );
	/// <summary>
	/// �����ł���Ƃ����肷��.
	/// </summary>
	/// <param name="unit">���j�b�g</param>
	/// <param name="human">������</param>
	/// <returns>�����ł��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
	bool IsAccess( Unit* unit, float human ) const;
	/// <summary>
	/// �l�ނ𑝌�������.
	/// </summary>
	/// <param name="target">���j�b�g</param>
	/// <param name="human">������</param>
	/// <returns>�ړ��ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
	bool PersonnelChange( Unit* my, float human );
	/// <summary>
	/// �l�ނ��ړ�������.
	/// </summary>
	/// <param name="target">�ړ������j�b�g</param>
	/// <param name="human">�ړ��惆�j�b�g</param>
	/// <param name="human">������</param>
	/// <returns>�ړ��ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
	bool PersonnelChange( Unit* my, Unit* target, float human );
	/// <summary>
	/// ����.
	/// </summary>
	void Clear();
private:
	/// <summary>
	/// ���j�b�g�p�����[�^.
	/// </summary>
	UnitParameter&	mParameter;
	/// <summary>
	/// �t���O�R���e�i.
	/// </summary>
	HumanContainer	mHumanContainer;
	/// <summary>
	/// �t���O�R���e�i.
	/// </summary>
	HumanContainer	mHumanMaxContainer;

};


#endif // !_HUMAN_MANAGER_H_

/********** End of File ******************************************************/