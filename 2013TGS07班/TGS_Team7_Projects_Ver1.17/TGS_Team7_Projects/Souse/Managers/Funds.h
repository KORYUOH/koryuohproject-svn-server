/******************************************************************************
* File Name : FundsManager.h                      Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		�����Ǘ��҃N���X�D
*
******************************************************************************/
#ifndef _FUNDS_MANAGER_H_
#define _FUNDS_MANAGER_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<map>

/*---- ��s�錾 -------------------------------------------------------------*/

class Unit;
class UnitParameter;


/// <summary>
/// �l�ފǗ���.
/// </summary>
class FundsManager
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="parameter">�p�����[�^</param>
	FundsManager( UnitParameter& parameter );
	/// <summary>
	/// ������.
	/// </summary>
	void Initialize();
	/// <summary>
	/// �����ł���Ƃ����肷��.
	/// </summary>
	/// <param name="funds">������</param>
	/// <returns>�����ł��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
	bool IsAccess( float funds ) const;
	/// <summary>
	/// �l�ނ𑝌�������.
	/// </summary>
	/// <param name="target">���j�b�g</param>
	/// <param name="human">������</param>
	/// <returns>�ړ��ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
	bool PersonnelChange( Unit* my, float funds );
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
	/// ����.
	/// </summary>
	float			mFunds;
	/// <summary>
	/// ���܂ł̎����̍��v.
	/// </summary>
	float			mFundsAll;

};


#endif // !_HUMAN_MANAGER_H_

/********** End of File ******************************************************/