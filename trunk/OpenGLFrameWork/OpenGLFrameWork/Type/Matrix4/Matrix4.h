/**===File Commentary=======================================*/
/**
 *	@file	Matrix4.h
 *
 *	@brief	4�s4��̍s��
 *
 *	@author	KORYUOH
 *
 *	@date	2012/07/03
 */
/**===Include Guard========================================*/
#ifndef	_MATRIX4_H_
#define	_MATRIX4_H_
/**===File Include=========================================*/
struct Vector3;
/**===Class Definition=====================================*/
struct Matrix4{
	//�s�񐬕�
	float m[4][4];
	/**
	 *	@brief	�R���X�g���N�^
	 */
	Matrix4();
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	m11
	 *	@param[in]	m12
	 *	@param[in]	m13
	 *	@param[in]	m14
	 *	@param[in]	m21
	 *	@param[in]	m22
	 *	@param[in]	m23
	 *	@param[in]	m24
	 *	@param[in]	m31
	 *	@param[in]	m32
	 *	@param[in]	m33
	 *	@param[in]	m34
	 *	@param[in]	m41
	 *	@param[in]	m42
	 *	@param[in]	m43
	 *	@param[in]	m44
	 */
	Matrix4(	float m11,	float m12,	float m13,	float m14,
					float m21,	float m22,	float m23,	float m24,
					float m31,	float m32,	float m33,	float m34,
					float m41,	float m42,	float m43,	float m44
					);
	/**
	 *	@brief	�P�ʍs��̐ݒ�
	 *	@return	�P�ʍs��
	 */
	Matrix4& setIdentity();
	/**
	 *	@brief	�g�k�̐ݒ�
	 *	 @param[in]	�g��k����
	 *	@return	�s��
	 */
	Matrix4& setScale(const Vector3& v);
	/**
	 *	@brief	��]�s��̐ݒ�
	 *	@param[in]	��]�p
	 *	@return	�s��
	 */
	Matrix4& setRotateX	(float angle);
	/**
	 *	@brief	��]�s��̐ݒ�
	 *	@param[in]	��]�p
	 *	@return	�s��
	 */
	Matrix4& setRotateY	(float angle);
	/**
	 *	@brief	��]�s��̐ݒ�
	 *	@param[in]	��]�p
	 *	@return	�s��
	 */
	Matrix4& setRotateZ	(float angle);
	
	/**
	 *	@brief	���s�ړ��s��̐ݒ�
	 *	@param[in]	���s�ړ���
	 *	@return	�s��
	 */
	Matrix4& setTranslate(const Vector3& v);
	/**
	 *	@brief	�����ϊ��s��̐ݒ�
	 *	@param[in]	fov
	  *	@param[in]	�A�X�y�N�g
	 *	@param[in]	�ߌi
	 *	@param[in]	���i
	 *	@return	�����ϊ��s��
	 */
	Matrix4& setPerspective(float fov,float aspect,float near, float far);

	/**
	 *	@brief	����ϊ��s��ݒ�
	 *	@param[in]	���_���W
	 *	@param[in]	�����_���W
	 *	@param[in]	���_�̏����
	 *	@return	����ϊ��s��
	 */
	Matrix4& setLookAt(const Vector3& eye,const Vector3& at ,const Vector3& up);
	/**
	 *	@brief	���W�ϊ�
	 *	@param[in]	�x�N�g��
	 *	@note	�s��ƃx�N�g���̊|���Z
	 *	@return	�x�N�g��
	 */
	Vector3 transForm(const Vector3& v)const;
	/**
	 *	@brief	���W�ϊ�
	 *	@param[in]	�x�N�g��
	 *	@note	�@���x�N�g���̌v�Z
	 *	@return	�@���x�N�g��
	 */
	Vector3 transformNomal(const Vector3& v)const;
	/**
	 *	@brief	������Z�q�I�[�o�[���[�h
	 *	@param[in]	�}�g���b�N�X
	 *	@return	���g
	 */
	Matrix4& operator *= (const Matrix4& matrix);
};
/*�񍀉��Z�q�I�[�o�[���[�h*/
const Matrix4 operator * (const Matrix4& m1 ,const Matrix4& m2);
const Vector3 operator * (const Vector3& v ,	const Matrix4& m);
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/