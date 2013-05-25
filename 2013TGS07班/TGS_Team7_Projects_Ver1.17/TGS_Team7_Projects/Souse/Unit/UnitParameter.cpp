/******************************************************************************
* File Name : UnitParameter.cpp                  Ver : 1.00  Date : 2013-04-29
*
* Description :
*
*		���j�b�g�p�����[�^�N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"UnitParameter.h"
#include"../CSV/CSVReader.h"
#include"Unit.h"
#include<algorithm>

/// <summary>
/// �R���X�g���N�^.
/// </summary>
UnitParameter::UnitParameter()
{
	mHumanMax.clear();
	mProduction.clear();
	mCost.clear();
}

/// <summary>
/// ������.
/// </summary>
void UnitParameter::Initialize()
{
	// �ǂݎ��@.
	CSVReader reader;

	reader.Load( "Resouse/Space.csv" );
	Initialize( UNIT_SPACE , reader.GetFloatData() );
	reader.Load( "Resouse/Star.csv" );
	Initialize( UNIT_STAR , reader.GetFloatData() );
	reader.Load( "Resouse/Farm.csv" );
	Initialize( UNIT_FARM , reader.GetFloatData() );
	reader.Load( "Resouse/Factory.csv" );
	Initialize( UNIT_FACTORY , reader.GetFloatData() );
	reader.Load( "Resouse/Housing.csv" );
	Initialize( UNIT_HOUSING , reader.GetFloatData() );
	reader.Load( "Resouse/Airfield.csv" );
	Initialize( UNIT_AIRFIELD , reader.GetFloatData() );
}

/// <summary>
/// ������.
/// </summary>
/// <param name="id">���j�b�g�h�c</param>
/// <param name="unitLevel">�������f�[�^</param>
void UnitParameter::Initialize( UnitID id ,const DataFloat& data )
{
	// �f�[�^����̎�.
	if( data.size() == 0 )
	{
		// �����I��.
		return;
	}

	// �ǉ��p�̕ϐ���錾����.
	UnitLevel human;
	human.clear();
	UnitLevel production;
	production.clear();
	UnitLevel cost;
	cost.clear();
	UnitLevel levelCost;
	levelCost.clear();

	// �f�[�^��ǉ�����.
	for( int level = 0 ; level < UNIT_LEVEL_MAX ; level++ )
	{
		human.insert( UnitLevel::value_type(level, data[0][level]) );
		production.insert( UnitLevel::value_type( level, data[1][level] ) );
		cost.insert( UnitLevel::value_type( level, data[2][level] ) );
		levelCost.insert( UnitLevel::value_type( level, data[3][level] ) );
	}

	mHumanMax.insert( ParameterContener::value_type(id,human) );
	mProduction.insert( ParameterContener::value_type(id,production) );
	mCost.insert( ParameterContener::value_type(id,cost) );
	mLevelUpCost.insert( ParameterContener::value_type(id,levelCost) );
}

/// <summary>
/// �l�ނ̍ő�l���擾.
/// </summary>
/// <param name="element">���j�b�g�̑���</param>
/// <returns>�l�ނ̍ő�l��Ԃ�.</returns>
float UnitParameter::GetHumanMax( const UnitElement& element ) const
{	
	return mHumanMax.find(element.mID)->second.find(element.mLevel-1)->second;
}

/// <summary>
/// ���Y���̍ő�l���擾.
/// </summary>
/// <param name="element">���j�b�g�̑���</param>
/// <returns>���Y���̍ő�l��Ԃ�.</returns>
float UnitParameter::GetProduction( const UnitElement& element ) const
{
	return mProduction.find(element.mID)->second.find(element.mLevel-1)->second;
}

/// <summary>
/// ����R�X�g�̍ő�l���擾.
/// </summary>
/// <param name="element">���j�b�g�̑���</param>
/// <returns>����R�X�g�l��Ԃ�.</returns>
float UnitParameter::GetCost( const UnitElement& element ) const
{
	return mCost.find(element.mID)->second.find(element.mLevel-1)->second;
}

/// <summary>
/// ���x���A�b�v����R�X�g�̍ő�l���擾.
/// </summary>
/// <param name="element">���j�b�g�̑���</param>
/// <returns>���x���A�b�v����R�X�g�l��Ԃ�.</returns>
float UnitParameter::GetLevelUpCost( const UnitElement& element ) const
{
	return mLevelUpCost.find(element.mID)->second.find(element.mLevel-1)->second;
}

/********** End of File ******************************************************/
