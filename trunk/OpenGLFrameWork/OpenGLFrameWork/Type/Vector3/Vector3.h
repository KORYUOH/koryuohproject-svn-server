/**===File Commentary=======================================*/
/**
 *	@file	Vector3.h
 *
 *	@brief	三次元ベクトル
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/26
 *
 *	@version	1.00
 */
/**===Include Guard========================================*/
#ifndef	_VECTOR3_H_
#define	_VECTOR3_H_
/**===File Include=========================================*/

/**===Class Definition=====================================*/
struct Vector3{
	/**
	 *	@brief	コンストラクタ
	 */
	Vector3();
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	X座標
	 *	@param[in]	Y座標
	 *	@param[in]	Z座標
	 */
	Vector3(float x,float y,float z);
	/**
	 *	@brief	ノルムを求める
	 *	@return	ノルム
	 */
	float length()const;
	/**
	 *	@brief	正規化する
	 *	@return	正規化されたベクトル
	 */
	Vector3& normalize();
	/**
	 *	@brief	内積
	 *	@param[in]	他のベクトル
	 *	@return	内積値
	 */
	float InnerProduct(const Vector3& v)const;
	/**
	 *	@brief	外積
	 *	@param[in]	他のベクトル
	 *	@return	外積値
	 */
	Vector3 OuterProduct(const Vector3& v)const;

/**===Operator Overload====================================*/
	/* 単項演算子 */
	Vector3 operator + () const;
	Vector3 operator - () const;

	/* 代入演算子 */
	Vector3& operator += (const Vector3& v);
	Vector3& operator -= (const Vector3& v);
	Vector3& operator *= (float s);
	Vector3& operator /= (float s);
/**========================================================*/

	/**	メンバー変数*/
	float x_,y_,z_;
};
/**===Operator Overload====================================*/
	/* 2項演算子 */
const Vector3 operator + (const Vector3& v1 , const Vector3& v2);
const Vector3 operator - (const Vector3& v1 , const Vector3& v2);
const Vector3 operator * (const Vector3& v , float s);
const Vector3 operator * (float s , const Vector3& v);
const Vector3 operator / (const Vector3& v , float s);
/**========================================================*/
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/