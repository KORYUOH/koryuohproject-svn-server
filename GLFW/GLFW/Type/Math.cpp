/******************************************************************************
* File Name : Math.cpp                           Ver : 1.00  Date : 2005-04-27
*
* Description :
*
*       計算クラス ソースファイル．
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"Math.h"
#include	<cmath>		// namespace std付の新しいＣ＋＋ヘッダです！

const float Math::PI = 3.141592653589793238f;	// 円周率

float Math::sqrt( float x )
{
	return	(float)std::sqrt( x );
}

float Math::sin( float degree )
{
	return	(float)std::sin( toRadian( degree ) );
}

float Math::cos( float degree )
{
	return	(float)std::cos( toRadian( degree ) );
}

float Math::tan( float degree )
{
	return	(float)std::tan( toRadian( degree ) );
}

float Math::toRadian( float degree )
{
	return	degree * ( PI / 180.0f );
}

float Math::toDegree( float radian )
{
	return	radian * ( 180.0f / PI );
}

/********** End of File ******************************************************/
