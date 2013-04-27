/**===File Commentary=======================================*/
/**
 *	@file	Vector3.h
 *
 *	@brief	�O�����x�N�g��
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
	 *	@brief	�R���X�g���N�^
	 */
	Vector3();
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	X���W
	 *	@param[in]	Y���W
	 *	@param[in]	Z���W
	 */
	Vector3(float x,float y,float z);
	/**
	 *	@brief	�m���������߂�
	 *	@return	�m����
	 */
	float length()const;
	/**
	 *	@brief	���K������
	 *	@return	���K�����ꂽ�x�N�g��
	 */
	Vector3& normalize();
	/**
	 *	@brief	����
	 *	@param[in]	���̃x�N�g��
	 *	@return	���ϒl
	 */
	float InnerProduct(const Vector3& v)const;
	/**
	 *	@brief	�O��
	 *	@param[in]	���̃x�N�g��
	 *	@return	�O�ϒl
	 */
	Vector3 OuterProduct(const Vector3& v)const;

/**===Operator Overload====================================*/
	/* �P�����Z�q */
	Vector3 operator + () const;
	Vector3 operator - () const;

	/* ������Z�q */
	Vector3& operator += (const Vector3& v);
	Vector3& operator -= (const Vector3& v);
	Vector3& operator *= (float s);
	Vector3& operator /= (float s);
/**========================================================*/

	/**	�����o�[�ϐ�*/
	float x_,y_,z_;
};
/**===Operator Overload====================================*/
	/* 2�����Z�q */
const Vector3 operator + (const Vector3& v1 , const Vector3& v2);
const Vector3 operator - (const Vector3& v1 , const Vector3& v2);
const Vector3 operator * (const Vector3& v , float s);
const Vector3 operator * (float s , const Vector3& v);
const Vector3 operator / (const Vector3& v , float s);
/**========================================================*/
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/