/******************************************************************************
* File Name : UnitParameter.h                    Ver : 1.00  Date : 2013-04-29
*
* Description :
*
*		���j�b�g�p�����[�^�N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_PARAMETER_H_
#define _UNIT_PARAMETER_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include"UnitID.h"
#include"../CSV/CSVReader.h"
#include<map>

/*---- ��s�錾 -------------------------------------------------------------*/

/// <summary>
/// ���j�b�g���x���̍ő�l.
/// </summary>
static const int UNIT_LEVEL_MAX = 5;
/// <summary>
/// ���j�b�g���x���̍ŏ��l.
/// </summary>
static const int UNIT_LEVEL_MIN = 1;
/// <summary>
/// ���j�b�g�v�f�\����.
/// </summary>
struct UnitElement;



/// <summary>
/// ���j�b�g�p�����[�^�N���X.
/// </summary>
class UnitParameter
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	UnitParameter();
	/// <summary>
	/// ������.
	/// </summary>
	void Initialize();
	/// <summary>
	/// �l�ނ̍ő�l���擾.
	/// </summary>
	/// <param name="element">���j�b�g�̑���</param>
	/// <returns>�l�ނ̍ő�l��Ԃ�.</returns>
	float GetHumanMax( const UnitElement& element ) const;
	/// <summary>
	/// ���Y���̍ő�l���擾.
	/// </summary>
	/// <param name="element">���j�b�g�̑���</param>
	/// <returns>���Y���̍ő�l��Ԃ�.</returns>
	float GetProduction( const UnitElement& element ) const;
	/// <summary>
	/// ����R�X�g�̍ő�l���擾.
	/// </summary>
	/// <param name="element">���j�b�g�̑���</param>
	/// <returns>����R�X�g�l��Ԃ�.</returns>
	float GetCost( const UnitElement& element ) const;
	/// <summary>
	/// ���x���A�b�v����R�X�g�̍ő�l���擾.
	/// </summary>
	/// <param name="element">���j�b�g�̑���</param>
	/// <returns>���x���A�b�v����R�X�g�l��Ԃ�.</returns>
	float GetLevelUpCost( const UnitElement& element ) const;
private:
	/// <summary>
	/// ������.
	/// </summary>
	/// <param name="id">���j�b�g�h�c</param>
	/// <param name="unitLevel">�������f�[�^</param>
	void Initialize( UnitID id ,const DataFloat& data );

	typedef std::map<int,float> UnitLevel;
	typedef std::map<UnitID,UnitLevel>	ParameterContener;
	/// <summary>
	/// �ő�l�l�ޒl.
	/// </summary>
	ParameterContener	mHumanMax;
	/// <summary>
	/// ���Y��.
	/// </summary>
	ParameterContener	mProduction;
	/// <summary>
	/// ����R�X�g.
	/// </summary>
	ParameterContener	mCost;
	/// <summary>
	/// ���x���A�b�v�R�X�g.
	/// </summary>
	ParameterContener	mLevelUpCost;
};

#endif // _UNIT_PARAMETER_H_ end

/********** End of File ******************************************************/
