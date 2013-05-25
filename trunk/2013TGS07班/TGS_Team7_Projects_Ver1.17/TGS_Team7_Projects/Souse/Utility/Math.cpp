/******************************************************************************
* File Name : Math.cpp                            Ver : 1.00  Date : 2013-05-05
*
* Description :
*
*		数学クラス．
*
******************************************************************************/
#include"Math.h"


/// <summary>
/// 円周率.
/// </summary>
const float Math::PI = 3.1415926535897932f;


/// <summary>
/// 最大値を求める.
/// </summary>
/// <param name="a">値A</param>
/// <param name="b">値B</param>
/// <returns>最大値を返す.</returns>
float Math::Max( float a, float b )
{
	return ( ( (a) > (b) ) ? (a) : (b) );
}

/// <summary>
/// 最小値を求める.
/// </summary>
/// <param name="a">値A</param>
/// <param name="b">値B</param>
/// <returns>最小値を返す.</returns>
float Math::Min( float a, float b )
{
	return ( ( (a) < (b) ) ? (a) : (b) );
}

/// <summary>
/// 値をしきい値の間に収める.
/// </summary>
/// <param name="value">値</param>
/// <param name="low">最小値</param>
/// <param name="height">最大値</param>
/// <returns>最大値を返す.</returns>
float Math::Clamp( float value, float low, float height )
{
	return Max( low, Min( value, height ) );
}

/// <summary>
/// サイン.
/// </summary>
/// <param name="degree">角度</param>
/// <returns>サイン値を返す</returns>
float Math::Sin( float degree )
{
	return std::sin( Radian( degree ) );
}

/// <summary>
/// コサイン.
/// </summary>
/// <param name="degree">角度</param>
/// <returns>コサイン値を返す</returns>
float Math::Cos( float degree )
{
	return std::cos( Radian( degree ) );
}

/// <summary>
/// タンジェント.
/// </summary>
/// <param name="degree">角度</param>
/// <returns>タンジェント値を返す</returns>
float Math::Tan( float degree )
{
	return std::tan( Radian( degree ) );
}

/// <summary>
/// 逆サイン.
/// </summary>
/// <param name="x">X値</param>
/// <returns>逆サイン値を返す</returns>
float Math::Asin( float x )
{
	return Degree( std::asin( x ) );
}

/// <summary>
/// 逆コサイン.
/// </summary>
/// <param name="x">X値</param>
/// <returns>逆コサイン値を返す</returns>
float Math::Acos( float x )
{
	return Degree( std::acos( x ) );
}

/// <summary>
/// 逆タンジェント.
/// </summary>
/// <param name="y">Y値</param>
/// <param name="x">X値</param>
/// <returns>逆タンジェント値を返す</returns>
float Math::Atan( float y, float x )
{
	return Degree( std::atan2( y, x ) );
}

/// <summary>
/// 角度をラジアンに変換.
/// </summary>
/// <param name="degree">角度</param>
/// <returns>ラジアン値を返す</returns>
float Math::Radian( float degree )
{
	return degree * ( PI / 180.0f );
}

/// <summary>
/// ラジアンを角度に変換.
/// </summary>
/// <param name="radian">ラジアン</param>
/// <returns>角度値</returns>
float Math::Degree( float radian )
{
	return radian * ( 180.0f / PI );
}

/********** End of File ******************************************************/