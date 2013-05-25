/******************************************************************************
* File Name : HumanManager.h                      Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		�l�ފǗ��҃N���X�D
*
******************************************************************************/
#include"Human.h"
#include"../Utility/Math.h"
#include<algorithm>

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Human::Human():
	mHumanMax( 0.0f ),
	mHuman( 0.0f )
{
}

/// <summary>
/// ������.
/// </summary>
void Human::Initialize()
{
	mHuman = 0.0f;
	mHumanMax = 0.0f;
}

/// <summary>
/// �l�ނ̍ő�l��ݒ肷��.
/// </summary>
/// <param name="humanMax">�l�ނ̍ő�l</param>
void Human::SetHumanMax( float humanMax )
{
	mHumanMax = humanMax;
	mHuman = Math::Clamp( mHuman, 0.0f, mHumanMax );
}

/// <summary>
/// �l�ނ̎擾����.
/// </summary>
/// <returns>�l�ނ�Ԃ�.</returns>
float Human::GetHuman() const
{
	return mHuman;
}

/// <summary>
/// �l�ނ̍ő�l���擾����.
/// </summary>
/// <returns>�l�ނ�Ԃ�.</returns>
float Human::GetHumanMax() const
{
	return mHumanMax;
}

/// <summary>
/// �l�ނ��[���l����.
/// </summary>
/// <returns>�l�ނ����邩����.</returns>
bool Human::IsHumanZero() const
{
	return mHuman == 0.0f;
}

/// <summary>
/// �l�ނ����������.
/// </summary>
/// <returns>����̎��^�A�����łȂ���΋U��Ԃ�.</returns>
bool Human::IsHumanCapacity() const
{
	return mHuman >= mHumanMax;
}

/// <summary>
/// �l���ٓ��ł��邩���肷��.
/// </summary>
/// <param name="unit">���j�b�g</param>
/// <param name="human">������</param>
/// <returns>�����ł��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
bool Human::IsPersonnelChange( float human ) const
{
	float resultHuman = human + mHuman;
	return 0.0f < resultHuman || resultHuman < mHumanMax;
}

/// <summary>
/// �ړ���ɐl���ٓ��ł��邩���肷��.
/// </summary>
/// <param name="target">�ړ���</param>
/// <param name="human">������</param>
/// <returns>�����ł��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
bool Human::IsPersonnelChange( const Human& target, float human ) const
{
	return IsPersonnelChange( -human ) && target.IsPersonnelChange( human );
}

/// <summary>
/// �l�ނ𑝌�������.
/// </summary>
/// <param name="human">������</param>
void Human::PersonnelChange( float human )
{
	mHuman = Math::Clamp( mHuman + human, 0.0f, mHumanMax );
}

/// <summary>
/// ���g����Ώۂɐl�ނ��ړ�������.
/// </summary>
/// <param name="target">�ړ��惆�j�b�g</param>
/// <param name="human">������</param>
void Human::PersonnelChange( Human& target, float human )
{
	PersonnelChange( -human );
	target.PersonnelChange( human );
}

/********** End of File ******************************************************/