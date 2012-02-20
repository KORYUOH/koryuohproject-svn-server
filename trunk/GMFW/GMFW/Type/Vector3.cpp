/******************************************************************************
* File Name : Vector3.cpp                        Ver : 1.00  Date : 2005-04-27
*
* Description :
*
*       �R�c�x�N�g���v�Z �\�[�X�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"Vector3.h"
#include	"Math.h"

// �R���X�g���N�^
Vector3::Vector3()
{
}

Vector3::Vector3( float X, float Y, float Z ) :
	x( X ), y( Y ), z( Z )
{
}

// ���������߂�
float Vector3::length() const
{
	return	Math::sqrt( x * x + y * y + z * z );
}

// ���K��
Vector3& Vector3::normalize()
{
	float len = length();
	if ( len != 0 ) {
		return *this /= length();
	}
	return *this;
}

// ���ς����߂�
float Vector3::dot( const Vector3& v ) const
{
	return	x * v.x + y * v.y + z * v.z;
}

// �O�ς����߂�
Vector3 Vector3::cross( const Vector3& v ) const
{
	Vector3	tmp;
	
	tmp.x = y * v.z - z * v.y;
	tmp.y = z * v.x - x * v.z;
	tmp.z = x * v.y - y * v.x;

	return	tmp;
}

// �P�����Z�q�I�[�o�[���[�h
Vector3 Vector3::operator + () const
{
	return	*this;
}

Vector3 Vector3::operator - () const
{
	return	Vector3( -x, -y, -z );
}

// ������Z�q�I�[�o�[���[�h
Vector3& Vector3::operator += ( const Vector3& v )
{
	x += v.x;
	y += v.y;
	z += v.z;

	return	*this;
}

Vector3& Vector3::operator -= ( const Vector3& v )
{
	x -= v.x;
	y -= v.y;
	z -= v.z;

	return	*this;
}

Vector3& Vector3::operator *= ( float s )
{
	x *= s;
	y *= s;
	z *= s;

	return	*this;
}

Vector3& Vector3::operator /= ( float s )
{
	x /= s;
	y /= s;
	z /= s;

	return	*this;
}

// �Q�����Z�q�I�[�o�[���[�h
const Vector3 operator + ( const Vector3& v1, const Vector3& v2 )
{
	Vector3	temp(v1);
	return	temp += v2;
}

const Vector3 operator - ( const Vector3& v1, const Vector3& v2 )
{
	Vector3	temp(v1);
	return	temp -= v2;
}

const Vector3 operator * ( const Vector3& v, float s )
{
	Vector3	temp(v);
	return	temp *= s;
}

const Vector3 operator * ( float s, const Vector3& v )
{
	return	v * s;
}

const Vector3 operator / ( const Vector3& v, float s )
{
	Vector3	temp(v);
	return	temp /= s;
}

/********** End of File ******************************************************/
