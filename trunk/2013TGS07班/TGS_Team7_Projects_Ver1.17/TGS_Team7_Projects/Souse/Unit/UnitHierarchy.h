/******************************************************************************
* File Name : UnitHierarchy.h                     Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		���j�b�g�K�w�N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_HIERARCHY_H_
#define _UNIT_HIERARCHY_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<list>

/*---- ��s�錾 -------------------------------------------------------------*/

/// <summary>���[���h���ۃN���X.</summary>
class IWorld;
/// <summary>���j�b�gID.</summary>
enum UnitID;
/// <summary>���j�b�g.</summary>
class Unit;

/// <summary>
/// ���j�b�g�K�w.
/// </summary>
struct UnitHierarchy
{
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	UnitHierarchy() :
		mParent( NULL )
	{
		mChild.clear();
	}
	/// <summary>
	/// �R���X�g���N�^.
	/// <param name="parent">�e���j�b�g</param>
	/// </summary>
	UnitHierarchy( Unit* parent ) :
		mParent( parent )
	{
		mChild.clear();
	}
	/// <summary>
	/// ��̊K�w�̃��j�b�g.
	/// </summary>
	Unit*				mParent;
	/// <summary>
	/// ���̊K�w�̃��j�b�g.
	/// </summary>
	std::list<Unit*>	mChild;


}; // UnitHierarchy end

#endif // _UNIT_HIERARCHY_H_ end

/********** End of File ******************************************************/
