/**===File Commentary=======================================*/
/**
 *	@file	Math_Utility.h
 *
 *	@brief	数学補助クラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/26
 */
/**===Include Guard========================================*/
#ifndef	_MATH_H_
#define	_MATH_H_
/**===File Include=========================================*/
/**===Class Definition=====================================*/
class Math{
public:
	/* 円周率 */
	static const float PI;
	/**
	 *	@brief	平方根
	 *	@param[in]	根
	 *	@return	平方根
	 */
	static float sqrt(float x);
	/**
	 *	@brief	正弦
	 *	@param[in]	角度
	 *	@return	正弦
	 */
	static float sin	(float Degree);
	/**
	 *	@brief	余弦
	 *	@param[in]	角度
	 *	@return	余弦
	 */
	static float cos	(float Degree);
	/**
	 *	@brief	正接
	 *	@param[in]	角度
	 *	@return	正接
	 */
	static float tan	(float Degree);

	/**
	 *	@brief	弧度法変換
	 *	@param[in]	度数法
	 *	@return	弧度
	 */
	static float toRadians	(float Degree);
	/**
	 *	@brief	度数法変換
	 *	@param[in]	弧度法
	 *	@return	度数法
	 */
	static float toDegrees	(float Radian);



};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/