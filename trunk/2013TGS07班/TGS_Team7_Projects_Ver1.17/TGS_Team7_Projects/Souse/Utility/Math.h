/******************************************************************************
* File Name : Math.h                             Ver : 1.00  Date : 2013-05-05
*
* Description :
*
*		数学クラス．
*
******************************************************************************/
#ifndef _MATH_UTILITY_H_
#define _MATH_UTILITY_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<cmath>


/// <summary>
/// 数学クラス.
/// </summary>
class Math
{
public:
	/// <summary>
	/// 円周率.
	/// </summary>
	static const float PI;

public:
	/// <summary>
	/// 最大値を求める.
	/// </summary>
	/// <param name="a">値A</param>
	/// <param name="b">値B</param>
	/// <returns>最大値を返す.</returns>
	static float Max( float a, float b );
	/// <summary>
	/// 最小値を求める.
	/// </summary>
	/// <param name="a">値A</param>
	/// <param name="b">値B</param>
	/// <returns>最小値を返す.</returns>
	static float Min( float a, float b );
	/// <summary>
	/// 値をしきい値の間に収める.
	/// </summary>
	/// <param name="value">値</param>
	/// <param name="low">最小値</param>
	/// <param name="height">最大値</param>
	/// <returns>最大値を返す.</returns>
	static float Clamp( float value, float low, float height );

public:
	/// <summary>
	/// サイン.
	/// </summary>
	/// <param name="degree">角度</param>
	/// <returns>サイン値を返す</returns>
	static float Sin( float degree );
	/// <summary>
	/// コサイン.
	/// </summary>
	/// <param name="degree">角度</param>
	/// <returns>コサイン値を返す</returns>
	static float Cos( float degree );
	/// <summary>
	/// タンジェント.
	/// </summary>
	/// <param name="degree">角度</param>
	/// <returns>タンジェント値を返す</returns>
	static float Tan( float degree );
	/// <summary>
	/// 逆サイン.
	/// </summary>
	/// <param name="x">X値</param>
	/// <returns>逆サイン値を返す</returns>
	static float Asin( float x );
	/// <summary>
	/// 逆コサイン.
	/// </summary>
	/// <param name="x">X値</param>
	/// <returns>逆コサイン値を返す</returns>
	static float Acos( float x );
	/// <summary>
	/// 逆タンジェント.
	/// </summary>
	/// <param name="y">Y値</param>
	/// <param name="x">X値</param>
	/// <returns>逆タンジェント値を返す</returns>
	static float Atan( float y, float x );
	/// <summary>
	/// 角度をラジアンに変換.
	/// </summary>
	/// <param name="degree">角度</param>
	/// <returns>ラジアン値を返す</returns>
	static float Radian( float degree );
	/// <summary>
	/// ラジアンを角度に変換.
	/// </summary>
	/// <param name="radian">ラジアン</param>
	/// <returns>角度値</returns>
	static float Degree( float radian );


};


#endif // _MATH_UTILITY_H_ end

/********** End of File ******************************************************/