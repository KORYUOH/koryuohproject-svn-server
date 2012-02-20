/******************************************************************************
* File Name : Color4.cpp                         Ver : 1.00  Date : 2005-04-27
*
* Description :
*
*       �q�f�a�`�J���[�v�Z�D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"Color4.h"
#include	<algorithm>

// �R���X�g���N�^
Color4::Color4()
{
}

Color4::Color4( float R, float G, float B, float A ) :
	r( R ), g( G ), b( B ), a( A )
{
}


// 0.0�`1.0�͈̔͂ɃN�����v
Color4& Color4::saturate()
{
	r = std::max( 0.0f, std::min( 1.0f, r ) );
	g = std::max( 0.0f, std::min( 1.0f, g ) );
	b = std::max( 0.0f, std::min( 1.0f, b ) );
	a = std::max( 0.0f, std::min( 1.0f, a ) );

	return	*this;
}

// �P�����Z�q�I�[�o�[���[�h
Color4  Color4::operator + () const
{
	return *this;
}

// ��F�����߂�
Color4  Color4::operator - () const
{
	return	Color4( 1.0f - r, 1.0f - g, 1.0f - b, a );
}

// ������Z�q�I�[�o�[���[�h
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

// �Q�����Z�q�I�[�o�[���[�h
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
