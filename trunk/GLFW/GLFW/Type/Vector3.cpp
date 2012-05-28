/******************************************************************************
* File Name : Vector3.cpp                        Ver : 1.00  Date : 2005-04-27
*
* Description :
*
*       ３Ｄベクトル計算 ソースファイル．
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"Vector3.h"
#include	"Math.h"

// コンストラクタ
Vector3::Vector3()
{
}

Vector3::Vector3( float X, float Y, float Z ) :
	x( X ), y( Y ), z( Z )
{
}

// 長さを求める
float Vector3::length() const
{
	return	Math::sqrt( x * x + y * y + z * z );
}

// 正規化
Vector3& Vector3::normalize()
{
	float len = length();
	if ( len != 0 ) {
		return *this /= length();
	}
	return *this;
}

// 内積を求める
float Vector3::dot( const Vector3& v ) const
{
	return	x * v.x + y * v.y + z * v.z;
}

// 外積を求める
Vector3 Vector3::cross( const Vector3& v ) const
{
	Vector3	tmp;
	
	tmp.x = y * v.z - z * v.y;
	tmp.y = z * v.x - x * v.z;
	tmp.z = x * v.y - y * v.x;

	return	tmp;
}

// 単項演算子オーバーロード
Vector3 Vector3::operator + () const
{
	return	*this;
}

Vector3 Vector3::operator - () const
{
	return	Vector3( -x, -y, -z );
}

// 代入演算子オーバーロード
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

// ２項演算子オーバーロード
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
