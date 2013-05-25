/******************************************************************************
* File Name : ToString.h                         Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		文字列への変換クラス．
*
******************************************************************************/
#include"ToString.h"
#include<algorithm>
#include<sstream>

/// <summary>
/// 整数型を文字列に変換.
/// </summary>
/// <param name="number">変換する数値</param>
/// <returns>変換した文字列を返す.</returns>
std::string IntToString(int number)
{
	std::stringstream s;
	s << number;
	return s.str();
}

/// <summary>
/// 実数型を文字列に変換.
/// </summary>
/// <param name="number">変換する数値</param>
/// <returns>変換した文字列を返す.</returns>
std::string FloatToString(float number)
{
	std::stringstream s;
	s << number;
	return s.str();
}

/// <summary>
/// 倍精度実数を文字列に変換.
/// </summary>
/// <param name="number">変換する数値</param>
/// <returns>変換した文字列を返す.</returns>
std::string DoubleToString(double number)
{	
	std::stringstream s;
	s << number;
	return s.str();
}

/// <summary>
/// ブール型を文字列に変換.
/// </summary>
/// <param name="flag">変換するフラグ</param>
/// <returns>変換した文字列を返す.</returns>
std::string BoolToString( bool flag )
{
	if( flag )
	{
		return "TRUE";
	}
	return "FALSE";
}

/// <summary>
/// 文字列を整数型に変換.
/// </summary>
/// <param name="s">変換する文字列</param>
/// <returns>変換した整数値を返す.</returns>
int IntParse( std::string s )
{
	//文字列を整数値に変換して返す
	return std::atoi( s.c_str() );
}

/// <summary>
/// 文字列を実数型に変換.
/// </summary>
/// <param name="s">変換する文字列</param>
/// <returns>変換した実数型値を返す.</returns>
float FloatParse( std::string s )
{
	//文字列を実数型に変換して返す
	return (float)DoubleParse(s);
}

/// <summary>
/// 文字列を倍精度実数に変換.
/// </summary>
/// <param name="s">変換する文字列</param>
/// <returns>変換した倍精度実数値を返す.</returns>
double DoubleParse( std::string s )
{
	//文字列を倍精度実数に変換して返す
	return std::atof( s.c_str() );
}

/********** End of File ******************************************************/