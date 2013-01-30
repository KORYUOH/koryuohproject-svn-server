/**===File Commentary=======================================*/
/**
 *	@file	Quaternion.h
 *
 *	@brief	クォータニオン
 *
 *	@author	KORYUOH
 *
 *	@date	2013/01/30
 */
/**===Include Guard========================================*/
#ifndef	_QUATERNION_H_
#define	_QUATERNION_H_
/**===File Include=========================================*/
struct Vector3;
/**===Class Definition=====================================*/
struct Quaternion{
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	x成分
	 *	@param[in]	y成分
	 *	@param[in]	z成分
	 *	@param[in]	虚数
	 */
	Quaternion(float x = 0.0f,float y= 0.0f,float z= 0.0f,float w= 1.0f);
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	成分
	 *	@param[in]	角度
	 */
	Quaternion(const Vector3& v, float angle);

	/**
	 *	@brief	内積
	 *	@param[in]	クォータニオン
	 *	@return	内積値
	 */
	float InnerProduct(const Quaternion& q)const;
	/**
	 *	@brief	長さ取得
	 *	@return	長さ
	 */
	float length()const;
	/**
	 *	@brief	正規化
	 */
	Quaternion& normalize();
	/**
	 *	@brief	球面線形補間
	 *	@param[in]	クォータニオン
	 *	@param[in]	パーセンテージ
	 *	@return 現在位置
	 */
	Quaternion slerp(const Quaternion& q, float t)const;
	/**
	 *	@brief	演算子オーバーロード
	 */
	//===== 単項
	Quaternion operator +() const;
	Quaternion operator -() const;

	//===== 代入
	Quaternion& operator +=(const Quaternion& q);
	Quaternion& operator -= (const  Quaternion& q);
	Quaternion& operator *= (float s);
	Quaternion& operator *= (const Quaternion& q);
	Quaternion& operator /= (float s);

	float x_;
	float y_;
	float z_;
	float w_;

};
const Quaternion operator +	(const Quaternion& q1 , const Quaternion& q2);
const Quaternion operator -	(const Quaternion& q1 , const Quaternion& q2);
const Quaternion operator *	(const Quaternion& q1 , const Quaternion& q2);
const Quaternion operator *	(float s, const Quaternion& q);
const Quaternion operator *	(const Quaternion& q , float s);
const Quaternion operator /	(const Quaternion& q , float s);

/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/