/**===File Commentary=======================================*/
/**
 *	@file	Vector2.h
 *
 *	@brief	二次元ベクトル
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/26
 *
 *	@version	1.00
 */
/**===Include Guard========================================*/
#ifndef	_VECTOR2_H_
#define	_VECTOR2_H_
/**===File Include=========================================*/
/**===Class Definition=====================================*/
struct Vector2{

	/**
	 *	@brief	コンストラクタ
	 */
	Vector2();
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	x座標
	 *	@param[in]	y座標
	 */
	Vector2(float x,float y);
	/**
	 *	@brief	ノルムを取得
	 *	@return	ノルム
	 */
	float length()const;
	/**
	 *	@brief	正規化を行う
	 *	@return	正規化した二次元ベクトル
	 */
	Vector2& normalize();
	/**
	 *	@brief	内積を求める
	 *	@param[in]	他のベクトル
	 *	@return	内積
	 */
	float InnerProduct(const Vector2& v)const;

/**===Operator Overload====================================*/
	
	/* 単項演算子 */
	Vector2 operator + ();
	Vector2 operator - ();
	
	/* 代入演算子 */
	Vector2& operator	+=	(const Vector2& v);
	Vector2& operator	-=		(const Vector2& v);
	Vector2& operator  *= (float s);
	Vector2& operator /= (float s);

/**========================================================*/

	/**	メンバー変数*/
	float x_,y_;
};
/**===Operator Overload====================================*/
	/* 2項演算子 */
	const Vector2 operator + (const Vector2& v1,const Vector2& v2);
	const Vector2 operator - (const Vector2& v1,const Vector2& v2);
	const Vector2 operator * (const Vector2& v,float s);
	const Vector2 operator * (float s,const Vector2& v);
	const Vector2 operator / (const Vector2& v,float s);
/**========================================================*/
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/