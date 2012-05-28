/******************************************************************************
* File Name : Math.h                           Ver : 1.00  Date : 2005-04-27
*
* Description :
*
*       計算クラス ヘッダファイル．
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_MATH_H_
#define		_MATH_H_

class Math
{
public:
	static const float PI;					// 円周率

	static float sqrt( float x );			// 平方根

	static float sin( float degree );		// サイン
	static float cos( float degree );		// コサイン
	static float tan( float degree );		// タンジェント

	static float toRadian( float degree );	// 角度をラジアンに変換
	static float toDegree( float radian );	// ラジアンを角度に変換
};

#endif

/********** End of File ******************************************************/
