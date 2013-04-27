/**===File Commentary=======================================*/
/**
 *	@file	Vector2.h
 *
 *	@brief	�񎟌��x�N�g��
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
	 *	@brief	�R���X�g���N�^
	 */
	Vector2();
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	x���W
	 *	@param[in]	y���W
	 */
	Vector2(float x,float y);
	/**
	 *	@brief	�m�������擾
	 *	@return	�m����
	 */
	float length()const;
	/**
	 *	@brief	���K�����s��
	 *	@return	���K�������񎟌��x�N�g��
	 */
	Vector2& normalize();
	/**
	 *	@brief	���ς����߂�
	 *	@param[in]	���̃x�N�g��
	 *	@return	����
	 */
	float InnerProduct(const Vector2& v)const;

/**===Operator Overload====================================*/
	
	/* �P�����Z�q */
	Vector2 operator + ();
	Vector2 operator - ();
	
	/* ������Z�q */
	Vector2& operator	+=	(const Vector2& v);
	Vector2& operator	-=		(const Vector2& v);
	Vector2& operator  *= (float s);
	Vector2& operator /= (float s);

/**========================================================*/

	/**	�����o�[�ϐ�*/
	float x_,y_;
};
/**===Operator Overload====================================*/
	/* 2�����Z�q */
	const Vector2 operator + (const Vector2& v1,const Vector2& v2);
	const Vector2 operator - (const Vector2& v1,const Vector2& v2);
	const Vector2 operator * (const Vector2& v,float s);
	const Vector2 operator * (float s,const Vector2& v);
	const Vector2 operator / (const Vector2& v,float s);
/**========================================================*/
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/