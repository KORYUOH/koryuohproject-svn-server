/******************************************************************************
* File Name : Math.cpp                            Ver : 1.00  Date : 2013-05-05
*
* Description :
*
*		���w�N���X�D
*
******************************************************************************/
#include"Math.h"


/// <summary>
/// �~����.
/// </summary>
const float Math::PI = 3.1415926535897932f;


/// <summary>
/// �ő�l�����߂�.
/// </summary>
/// <param name="a">�lA</param>
/// <param name="b">�lB</param>
/// <returns>�ő�l��Ԃ�.</returns>
float Math::Max( float a, float b )
{
	return ( ( (a) > (b) ) ? (a) : (b) );
}

/// <summary>
/// �ŏ��l�����߂�.
/// </summary>
/// <param name="a">�lA</param>
/// <param name="b">�lB</param>
/// <returns>�ŏ��l��Ԃ�.</returns>
float Math::Min( float a, float b )
{
	return ( ( (a) < (b) ) ? (a) : (b) );
}

/// <summary>
/// �l���������l�̊ԂɎ��߂�.
/// </summary>
/// <param name="value">�l</param>
/// <param name="low">�ŏ��l</param>
/// <param name="height">�ő�l</param>
/// <returns>�ő�l��Ԃ�.</returns>
float Math::Clamp( float value, float low, float height )
{
	return Max( low, Min( value, height ) );
}

/// <summary>
/// �T�C��.
/// </summary>
/// <param name="degree">�p�x</param>
/// <returns>�T�C���l��Ԃ�</returns>
float Math::Sin( float degree )
{
	return std::sin( Radian( degree ) );
}

/// <summary>
/// �R�T�C��.
/// </summary>
/// <param name="degree">�p�x</param>
/// <returns>�R�T�C���l��Ԃ�</returns>
float Math::Cos( float degree )
{
	return std::cos( Radian( degree ) );
}

/// <summary>
/// �^���W�F���g.
/// </summary>
/// <param name="degree">�p�x</param>
/// <returns>�^���W�F���g�l��Ԃ�</returns>
float Math::Tan( float degree )
{
	return std::tan( Radian( degree ) );
}

/// <summary>
/// �t�T�C��.
/// </summary>
/// <param name="x">X�l</param>
/// <returns>�t�T�C���l��Ԃ�</returns>
float Math::Asin( float x )
{
	return Degree( std::asin( x ) );
}

/// <summary>
/// �t�R�T�C��.
/// </summary>
/// <param name="x">X�l</param>
/// <returns>�t�R�T�C���l��Ԃ�</returns>
float Math::Acos( float x )
{
	return Degree( std::acos( x ) );
}

/// <summary>
/// �t�^���W�F���g.
/// </summary>
/// <param name="y">Y�l</param>
/// <param name="x">X�l</param>
/// <returns>�t�^���W�F���g�l��Ԃ�</returns>
float Math::Atan( float y, float x )
{
	return Degree( std::atan2( y, x ) );
}

/// <summary>
/// �p�x�����W�A���ɕϊ�.
/// </summary>
/// <param name="degree">�p�x</param>
/// <returns>���W�A���l��Ԃ�</returns>
float Math::Radian( float degree )
{
	return degree * ( PI / 180.0f );
}

/// <summary>
/// ���W�A�����p�x�ɕϊ�.
/// </summary>
/// <param name="radian">���W�A��</param>
/// <returns>�p�x�l</returns>
float Math::Degree( float radian )
{
	return radian * ( 180.0f / PI );
}

/********** End of File ******************************************************/