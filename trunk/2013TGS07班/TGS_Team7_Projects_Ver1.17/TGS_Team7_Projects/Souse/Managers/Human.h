/******************************************************************************
* File Name : Human.h                            Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		�l�ރN���X�D
*
******************************************************************************/
#ifndef _HUMAN_H_
#define _HUMAN_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<map>

/*---- ��s�錾 -------------------------------------------------------------*/


/// <summary>
/// �l�ފǗ���.
/// </summary>
class Human
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	Human();
	/// <summary>
	/// ������.
	/// </summary>
	void Initialize();
	/// <summary>
	/// �l�ނ̍ő�l��ݒ肷��.
	/// </summary>
	/// <param name="humanMax">�l�ނ̍ő�l</param>
	void SetHumanMax( float humanMax );
	/// <summary>
	/// �l�ނ̎擾����.
	/// </summary>
	/// <returns>�l�ނ�Ԃ�.</returns>
	float GetHuman() const;
	/// <summary>
	/// �l�ނ̍ő�l���擾����.
	/// </summary>
	/// <returns>�l�ނ�Ԃ�.</returns>
	float GetHumanMax() const;
	/// <summary>
	/// �l�ނ��[���l����.
	/// </summary>
	/// <returns>�l�ނ����邩����.</returns>
	bool IsHumanZero() const;
	/// <summary>
	/// �l�ނ����������.
	/// </summary>
	/// <returns>����̎��^�A�����łȂ���΋U��Ԃ�.</returns>
	bool IsHumanCapacity() const;
	/// <summary>
	/// �ړ���ɐl���ٓ��ł��邩���肷��.
	/// </summary>
	/// <param name="target">�ړ���</param>
	/// <param name="human">������</param>
	/// <returns>�ړ��ł���ΐ^�A�����łȂ���΋U��Ԃ�.</returns>
	bool IsPersonnelChange( const Human& target, float human ) const;
	/// <summary>
	/// �l���ٓ��ł��邩���肷��.
	/// </summary>
	/// <param name="unit">���j�b�g</param>
	/// <param name="human">������</param>
	/// <returns>�����ł��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
	bool IsPersonnelChange( float human ) const;
	/// <summary>
	/// �l�ނ𑝌�������.
	/// </summary>
	/// <param name="human">������</param>
	/// <returns>�ړ��ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
	void PersonnelChange( float human );
	/// <summary>
	/// ���g����Ώۂɐl�ނ��ړ�������.
	/// </summary>
	/// <param name="target">�ړ��惆�j�b�g</param>
	/// <param name="human">������</param>
	/// <returns>�ړ��ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
	void PersonnelChange( Human& target, float human );

private:
	/// <summary>
	/// �l�ނ̍ő��.
	/// </summary>
	float	mHumanMax;
	/// <summary>
	/// �l�ނ̐�.
	/// </summary>
	float	mHuman;

};


#endif // !_HUMAN_MANAGER_H_

/********** End of File ******************************************************/