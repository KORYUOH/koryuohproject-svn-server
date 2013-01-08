/**===File Commentary=======================================*/
/**
 *	@file	Math_Utility.cpp
 *
 *	@brief	数学補助ユーティリティー
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/26
 */
/**===File Include=========================================*/
#include	<Utility/Math_Utility.h>
#include	<cmath>
/**===Class Implementation=================================*/
const float Math::PI = 3.1415926535897932384;
/**========================================================*/
/**
 *	@brief	正弦
 *	@param[in]	角度
 *	@return	度数
 */
/**========================================================*/
float Math::sin(float theta){
	return std::sinf(toRadians(theta));
}
/**========================================================*/
/**
 *	@brief	余弦
 *	@param[in]	角度
 *	@return	度数
 */
/**========================================================*/
float Math::cos(float theta){
	return std::cosf(toRadians(theta));
}
/**========================================================*/
/**
 *	@brief	正接
 *	@param[in]	角度
 *	@return	度数法
 */
/**========================================================*/
float Math::tan(float theta){
	return std::tanf(toRadians(theta));
}
/**========================================================*/
/**
 *	@brief	平方根
 *	@param[in]	根
 *	@return	値
 */
/**========================================================*/
float Math::sqrt(float root){
	return std::sqrtf(root);
}
/**========================================================*/
/**
 *	@brief	度数法に変換
 *	@param[in]	弧度法
 *	@return	度数
 */
/**========================================================*/
float Math::toDegrees(float radian){
	return radian*(180.0f/PI);
}
/**========================================================*/
/**
 *	@brief	弧度法に変換
 *	@param[in]	度数法
 *	@return	弧度法
 */
/**========================================================*/
float Math::toRadians(float degree){
	return degree *(PI/180.0f);
}



/**===End Of File==========================================*/