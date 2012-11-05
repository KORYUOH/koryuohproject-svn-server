/**===File Commentary=======================================*/
/**
 *	@file	Color4.h
 *
 *	@brief	RGBA色
 *
 *	@author	KORYUOH
 *
 *	@date	2012/07/03
 */
/**===Include Guard========================================*/
#ifndef	_COLOR4_H_
#define	_COLOR4_H_
/**===File Include=========================================*/
/**===Class Definition=====================================*/
struct Color4{
	float r_;
	float g_;
	float b_;
	float a_;
	/**
	 *	@brief	コンストラクタ
	 */
	Color4();
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	赤
	 *	@param[in]	緑
	 *	@param[in]	青
	 *	@param[in]	透過
	 */
	Color4(float r,float g,float b,float a);
	/**
	 *	@brief	クランプ
	 *	@return	クランプれた値
	 */
	Color4& saturate();
//x	Color4 toGrayScale()const;
	/**
	 *	@brief	単項演算子オーバーロード
	 */
	Color4 operator +	()const;
	Color4 operator -	()const;

	/**
	 *	@brief	代入演算子オーバーロード
	 */
	Color4& operator += (const Color4& c2);
	Color4& operator -= (const Color4& c2);
	Color4& operator *= (const Color4& c2);
	Color4& operator /= (const Color4& c2);
	Color4& operator *= (float s);
	Color4& operator /= (float s);
};
/**
	 *	@brief	2項演算子オーバーロード
	 */
	const Color4 operator +(const Color4& c1,const Color4& c2);
	const Color4 operator -(const Color4& c1,const Color4& c2);
	const Color4 operator *(const Color4& c1,const Color4& c2);
	const Color4 operator *(float s,const Color4& c);
	const Color4 operator *(const Color4& c, float s);
	const Color4 operator /(const Color4& c,float s);

/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/