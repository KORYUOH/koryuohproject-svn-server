/**===File Commentary=======================================*/
/**
 *	@file	Quaternion.h
 *
 *	@brief	�N�H�[�^�j�I��
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
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	x����
	 *	@param[in]	y����
	 *	@param[in]	z����
	 *	@param[in]	����
	 */
	Quaternion(float x = 0.0f,float y= 0.0f,float z= 0.0f,float w= 1.0f);
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	����
	 *	@param[in]	�p�x
	 */
	Quaternion(const Vector3& v, float angle);

	/**
	 *	@brief	����
	 *	@param[in]	�N�H�[�^�j�I��
	 *	@return	���ϒl
	 */
	float InnerProduct(const Quaternion& q)const;
	/**
	 *	@brief	�����擾
	 *	@return	����
	 */
	float length()const;
	/**
	 *	@brief	���K��
	 */
	Quaternion& normalize();
	/**
	 *	@brief	���ʐ��`���
	 *	@param[in]	�N�H�[�^�j�I��
	 *	@param[in]	�p�[�Z���e�[�W
	 *	@return ���݈ʒu
	 */
	Quaternion slerp(const Quaternion& q, float t)const;
	/**
	 *	@brief	���Z�q�I�[�o�[���[�h
	 */
	//===== �P��
	Quaternion operator +() const;
	Quaternion operator -() const;

	//===== ���
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