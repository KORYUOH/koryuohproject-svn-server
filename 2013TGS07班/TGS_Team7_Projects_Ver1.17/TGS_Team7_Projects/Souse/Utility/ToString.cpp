/******************************************************************************
* File Name : ToString.h                         Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		������ւ̕ϊ��N���X�D
*
******************************************************************************/
#include"ToString.h"
#include<algorithm>
#include<sstream>

/// <summary>
/// �����^�𕶎���ɕϊ�.
/// </summary>
/// <param name="number">�ϊ����鐔�l</param>
/// <returns>�ϊ������������Ԃ�.</returns>
std::string IntToString(int number)
{
	std::stringstream s;
	s << number;
	return s.str();
}

/// <summary>
/// �����^�𕶎���ɕϊ�.
/// </summary>
/// <param name="number">�ϊ����鐔�l</param>
/// <returns>�ϊ������������Ԃ�.</returns>
std::string FloatToString(float number)
{
	std::stringstream s;
	s << number;
	return s.str();
}

/// <summary>
/// �{���x�����𕶎���ɕϊ�.
/// </summary>
/// <param name="number">�ϊ����鐔�l</param>
/// <returns>�ϊ������������Ԃ�.</returns>
std::string DoubleToString(double number)
{	
	std::stringstream s;
	s << number;
	return s.str();
}

/// <summary>
/// �u�[���^�𕶎���ɕϊ�.
/// </summary>
/// <param name="flag">�ϊ�����t���O</param>
/// <returns>�ϊ������������Ԃ�.</returns>
std::string BoolToString( bool flag )
{
	if( flag )
	{
		return "TRUE";
	}
	return "FALSE";
}

/// <summary>
/// ������𐮐��^�ɕϊ�.
/// </summary>
/// <param name="s">�ϊ����镶����</param>
/// <returns>�ϊ����������l��Ԃ�.</returns>
int IntParse( std::string s )
{
	//������𐮐��l�ɕϊ����ĕԂ�
	return std::atoi( s.c_str() );
}

/// <summary>
/// ������������^�ɕϊ�.
/// </summary>
/// <param name="s">�ϊ����镶����</param>
/// <returns>�ϊ����������^�l��Ԃ�.</returns>
float FloatParse( std::string s )
{
	//������������^�ɕϊ����ĕԂ�
	return (float)DoubleParse(s);
}

/// <summary>
/// �������{���x�����ɕϊ�.
/// </summary>
/// <param name="s">�ϊ����镶����</param>
/// <returns>�ϊ������{���x�����l��Ԃ�.</returns>
double DoubleParse( std::string s )
{
	//�������{���x�����ɕϊ����ĕԂ�
	return std::atof( s.c_str() );
}

/********** End of File ******************************************************/