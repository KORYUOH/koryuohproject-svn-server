/**===File Commentary=======================================*/
/**
 *	@file	Color4.h
 *
 *	@brief	RGBA�F
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
	 *	@brief	�R���X�g���N�^
	 */
	Color4();
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	��
	 *	@param[in]	��
	 *	@param[in]	��
	 *	@param[in]	����
	 */
	Color4(float r,float g,float b,float a);
	/**
	 *	@brief	�N�����v
	 *	@return	�N�����v�ꂽ�l
	 */
	Color4& saturate();
//x	Color4 toGrayScale()const;
	/**
	 *	@brief	�P�����Z�q�I�[�o�[���[�h
	 */
	Color4 operator +	()const;
	Color4 operator -	()const;

	/**
	 *	@brief	������Z�q�I�[�o�[���[�h
	 */
	Color4& operator += (const Color4& c2);
	Color4& operator -= (const Color4& c2);
	Color4& operator *= (const Color4& c2);
	Color4& operator /= (const Color4& c2);
	Color4& operator *= (float s);
	Color4& operator /= (float s);
};
/**
	 *	@brief	2�����Z�q�I�[�o�[���[�h
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