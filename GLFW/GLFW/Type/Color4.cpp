/******************************************************************************
* File Name : Color4.cpp                         Ver : 1.00  Date : 2005-04-27
*
* Description :
*
*       ＲＧＢＡカラー計算．
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"Color4.h"
#include	<algorithm>

// コンストラクタ
Color4::Color4()
{
}

Color4::Color4( float R, float G, float B, float A ) :
	r( R ), g( G ), b( B ), a( A )
{
}


// 0.0～1.0の範囲にクランプ
Color4& Color4::saturate()
{
	r = std::max( 0.0f, std::min( 1.0f, r ) );
	g = std::max( 0.0f, std::min( 1.0f, g ) );
	b = std::max( 0.0f, std::min( 1.0f, b ) );
	a = std::max( 0.0f, std::min( 1.0f, a ) );

	return	*this;
}

// 単項演算子オーバーロード
Color4  Color4::operator + () const
{
	return *this;
}

// 補色を求める
Color4  Color4::operator - () const
{
	return	Color4( 1.0f - r, 1.0f - g, 1.0f - b, a );
}

// 代入演算子オーバーロード
Color4&  Color4::operator += ( const Color4& c2 )
{
	r += c2.r;
	g += c2.g;
	b += c2.b;
	a += c2.a;
	return *this;
}

Color4&  Color4::operator -= ( const Color4& c2 )
{
	r -= c2.r;
	g -= c2.g;
	b -= c2.b;
	a -= c2.a;
	return *this;
}

Color4&  Color4::operator *= ( const Color4& c2 )
{
	r *= c2.r;
	g *= c2.g;
	b *= c2.b;
	a *= c2.a;
	return *this;;
}

Color4&  Color4::operator *= ( float s )
{
	r *= s;
	g *= s;
	b *= s;
	a *= s;
	return *this;
}

Color4&  Color4::operator /= ( float s )
{
	r /= s;
	g /= s;
	b /= s;
	a /= s;
	return *this;
}

// ２項演算子オーバーロード
const Color4 operator + ( const Color4& c1, const Color4& c2 )
{
	Color4	temp(c1);
	return	temp += c2;
}

const Color4 operator - ( const Color4& c1, const Color4& c2 )
{
	Color4	temp(c1);
	return	temp -= c2;
}

const Color4 operator * ( const Color4& c1, const Color4& c2 )
{
	Color4	temp(c1);
	return	temp *= c2;
}

const Color4 operator * ( const Color4& c, const float s )
{
	Color4	temp(c);
	return	temp *= s;
}

const Color4 operator * ( const float s, const Color4& c )
{
	return c * s;
}

const Color4 operator / ( const Color4& c, const float s )
{
	Color4	temp(c);
	return	temp /= s;
}

/********** End of File ******************************************************/
