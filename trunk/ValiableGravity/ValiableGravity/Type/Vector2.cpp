/******************************************************************************
* File Name : Vector2.cpp                        Ver : 1.00  Date : 2005-04-27
*
* Description :
*
*       ２Ｄベクトル計算 ソースファイル．
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"Vector2.h"
#include	"Math.h"

// コンストラクタ
Vector2::Vector2()
{
}

Vector2::Vector2( float X, float Y ) :
	x( X ), y( Y )
{
}

// 長さを求める
float Vector2::length() const
{
	return	Math::sqrt( x * x + y * y );
}

// 正規化
Vector2& Vector2::normalize()
{
	float len = length();
	if ( len != 0 ) {
		return *this /= length();
	}
	return *this;
}

// 内積を求める
float Vector2::dot( const Vector2& v ) const
{
	return	x * v.x + y * v.y;
}

// 単項演算子オーバーロード
Vector2 Vector2::operator + () const
{
	return	*this;
}

Vector2 Vector2::operator - () const
{
	return	Vector2( -x, -y );
}

// 代入演算子オーバーロード
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

// ２項演算子オーバーロード
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
