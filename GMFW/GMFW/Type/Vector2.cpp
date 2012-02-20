/******************************************************************************
* File Name : Vector2.cpp                        Ver : 1.00  Date : 2005-04-27
*
* Description :
*
*       �Q�c�x�N�g���v�Z �\�[�X�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"Vector2.h"
#include	"Math.h"

// �R���X�g���N�^
Vector2::Vector2()
{
}

Vector2::Vector2( float X, float Y ) :
	x( X ), y( Y )
{
}

// ���������߂�
float Vector2::length() const
{
	return	Math::sqrt( x * x + y * y );
}

// ���K��
Vector2& Vector2::normalize()
{
	float len = length();
	if ( len != 0 ) {
		return *this /= length();
	}
	return *this;
}

// ���ς����߂�
float Vector2::dot( const Vector2& v ) const
{
	return	x * v.x + y * v.y;
}

// �P�����Z�q�I�[�o�[���[�h
Vector2 Vector2::operator + () const
{
	return	*this;
}

Vector2 Vector2::operator - () const
{
	return	Vector2( -x, -y );
}

// ������Z�q�I�[�o�[���[�h
Vector2& Vector2::operator += ( const Vector2& v )
{
	x += v.x;
	y += v.y;
	return	*this;
}

Vector2& Vector2::operator -= ( const Vector2& v )
{
	x -= v.x;
	y -= v.y;
	return	*this;
}

Vector2& Vector2::operator *= ( float s )
{
	x *= s;
	y *= s;
	return	*this;
}

Vector2& Vector2::operator /= ( float s )
{
	x /= s;
	y /= s;
	return	*this;
}

// �Q�����Z�q�I�[�o�[���[�h
const Vector2 operator + ( const Vector2& v1, const Vector2& v2 )
{
	Vector2	temp(v1);
	return	temp += v2;
}

const Vector2 operator - ( const Vector2& v1, const Vector2& v2 )
{
	Vector2	temp(v1);
	return	temp -= v2;
}

const Vector2 operator * ( const Vector2& v, float s )
{
	Vector2	temp(v);
	return	temp *= s;
}

const Vector2 operator * ( float s, const Vector2& v )
{
	return	v * s;
}

const Vector2 operator / ( const Vector2& v, float s )
{
	Vector2	temp(v);
	return	temp /= s;
}

/********** End of File ******************************************************/
