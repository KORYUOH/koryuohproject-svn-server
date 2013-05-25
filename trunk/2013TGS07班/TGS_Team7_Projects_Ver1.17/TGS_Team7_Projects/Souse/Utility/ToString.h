/******************************************************************************
* File Name : ToString.h                         Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		������̕ϊ��N���X�D
*
******************************************************************************/
#ifndef _TO_STRING_H_
#define _TO_STRING_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<string>

/// <summary>
/// �����^�𕶎���ɕϊ�.
/// </summary>
/// <param name="number">�ϊ����鐔�l</param>
/// <returns>�ϊ������������Ԃ�.</returns>
std::string IntToString(int number);

/// <summary>
/// �����^�𕶎���ɕϊ�.
/// </summary>
/// <param name="number">�ϊ����鐔�l</param>
/// <returns>�ϊ������������Ԃ�.</returns>
std::string FloatToString(float number);

/// <summary>
/// �{���x�����𕶎���ɕϊ�.
/// </summary>
/// <param name="number">�ϊ����鐔�l</param>
/// <returns>�ϊ������������Ԃ�.</returns>
std::string DoubleToString(double number);

/// <summary>
/// �u�[���^�𕶎���ɕϊ�.
/// </summary>
/// <param name="flag">�ϊ�����t���O</param>
/// <returns>�ϊ������������Ԃ�.</returns>
std::string BoolToString( bool flag );

/// <summary>
/// ������𐮐��^�ɕϊ�.
/// </summary>
/// <param name="s">�ϊ����镶����</param>
/// <returns>�ϊ����������l��Ԃ�.</returns>
int IntParse( std::string s );

/// <summary>
/// ������������^�ɕϊ�.
/// </summary>
/// <param name="s">�ϊ����镶����</param>
/// <returns>�ϊ����������^�l��Ԃ�.</returns>
float FloatParse( std::string s );

/// <summary>
/// �������{���x�����ɕϊ�.
/// </summary>
/// <param name="s">�ϊ����镶����</param>
/// <returns>�ϊ������{���x�����l��Ԃ�.</returns>
double DoubleParse( std::string s );


#endif
/********** End of File ******************************************************/