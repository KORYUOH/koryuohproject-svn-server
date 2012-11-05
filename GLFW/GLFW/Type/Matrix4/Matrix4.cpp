/**===File Commentary=======================================*/
/**
 *	@file	Matrix4.cpp
 *
 *	@brief	4�s4��̍s��
 *
 *	@author	KORYUOH
 *
 *	@date	2012/07/03
 */
/**===File Include=========================================*/
#include	<Type/Matrix4/Matrix4.h>
#include	<Type/Vector3/Vector3.h>
#include	<Utility/Math_Utility.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 */
/**========================================================*/
Matrix4::Matrix4(){
	setIdentity();
}
/**========================================================*/
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
/**========================================================*/
Matrix4::Matrix4(
	float m11,float m12,float m13,float m14,
	float m21,float m22,float m23,float m24,
	float m31,float m32,float m33,float m34,
	float m41,float m42,float m43,float m44){
		m[0][0] = m11;m[0][1] = m12;m[2][0] = m13;m[3][0] = m14;
		m[1][0] = m21;m[1][1] = m22;m[2][1] = m23;m[3][1] = m24;
		m[2][0] = m31;m[2][1] = m32;m[2][2] = m33;m[3][2] = m34;
		m[3][0] = m41;m[3][1] = m42;m[2][3] = m43;m[3][3] = m44;
}
/**========================================================*/
/**
 *	@brief	�P�ʍs���ݒ�
 *	@return	�P�ʍs��
 */
/**========================================================*/
Matrix4& Matrix4::setIdentity(){
	return *this = Matrix4(
		1.0f,	0.0f,	0.0f,	0.0f,
		0.0f,	1.0f,	0.0f,	0.0f,
		0.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f
		);
}
/**========================================================*/
/**
 *	@brief	�g�k�s��
 *	@param[in]	�g�k
 *	@return	���g
 */
/**========================================================*/
Matrix4& Matrix4::setScale(const Vector3& v){
	m[0][0] = v.x_;	m[0][1] = 0.0f;	m[0][2] = 0.0f;m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = v.y_;	m[1][2] = 0.0f;m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = v.z_;m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;	m[3][2] = 0.0f;m[3][3] = 1.0f;
	return *this;
}
/**========================================================*/
/**
 *	@brief	��]�s��
 *	@param[in]	�p�x�i�x���@�j
 *	@return	��]�s��
 */
/**========================================================*/
Matrix4& Matrix4::setRotateX(float angle){
	float Sin = Math::sin(angle);
	float Cos = Math::cos(angle);
	m[0][0] = 1.0f;	m[0][1] = 0.0f;		m[0][2] = 0.0f;		m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = Cos;		m[1][2] = Sin;		m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = -Sin;		m[2][2] = Cos;		m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;		m[3][2] = 0.0f;		m[3][3] = 1.0f;
	return *this;
}
/**========================================================*/
/**
 *	@brief	��]�s��
 *	@param[in]	�p�x�i�x���@�j
 *	@return	��]�s��
 */
/**========================================================*/
Matrix4& Matrix4::setRotateY(float angle){
	float Sin = Math::sin(angle);
	float Cos = Math::cos(angle);
	m[0][0] = Cos;	m[0][1] = 0.0f;		m[0][2] = -Sin;	m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = 1.0f;		m[1][2] = 0.0f;	m[1][3] = 0.0f;
	m[2][0] = Sin;	m[2][1] = 0.0f	;	m[2][2] = Cos;	m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;		m[3][2] = 0.0f;	m[3][3] = 1.0f;
	return *this;
}
/**========================================================*/
/**
 *	@brief	��]�s��
 *	@param[in]	�p�x�i�x���@�j
 *	@return	��]�s��
 */
/**========================================================*/
Matrix4& Matrix4::setRotateZ(float angle){
	float Sin = Math::sin(angle);
	float Cos = Math::cos(angle);
	m[0][0] = Cos;	m[0][1] = Sin;	m[0][2] = 0.0f;	m[0][3] = 0.0f;
	m[1][0] = -Sin;	m[1][1] = Cos;	m[1][2] = 0.0f;	m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = 1.0f;	m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;	m[3][2] = 0.0f;	m[3][3] = 1.0f;
	return *this;
}

/**========================================================*/
/**
 *	@brief	���s�ړ��s��
 *	@param[in]	�ړ��x�N�g��
 *	@return	���g
 */
/**========================================================*/
Matrix4& Matrix4::setTranslate(const Vector3& v){
//	this->setIdentity();
	m[0][0] = 1.0f;	m[0][1] = 0.0f;	m[0][2] = 0.0f;m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = 1.0f;	m[1][2] = 0.0f;m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = 1.0f;m[2][3] = 0.0f;
	m[3][0] = v.x_;	m[3][1] = v.y_;	m[3][2] = v.z_;m[3][3] = 1.0f;
	return *this;
}
/**========================================================*/
/**
 *	@brief	�����ϊ��s��
 *	@param[in]	����p
 *	@param[in]	�A�X�y�N�g��
 *	@param[in]	�߃N���b�v��
 *	@param[in]	���N���b�v��
 *	@return	�����ϊ��s��
 */
/**========================================================*/
Matrix4& Matrix4::setPerspective(float fov,float aspect,float near,float far){
	float f = 1.0f/Math::tan(fov/2.0f);
	m[0][0] = f/aspect;		m[0][1] = 0.0f;		m[0][2] =0.0f;									m[0][3] =0.0f;
	m[1][0] = 0.0f;				m[1][1] =f;		  	m[1][2] =0.0f;									m[1][3] =0.0f;
	m[2][0] = 0.0f;				m[2][1] =0.0f;		m[2][2] =(far+near)/(near-far);			m[2][3] =-1.0f;
	m[3][0] = 0.0f;				m[3][1] =0.0f;		m[3][2] =(2*far*near)/(near-far);  		m[3][3] =0.0f;
	return *this;
}
/**========================================================*/
/**
 *	@brief	���_�ϊ��s��
 *	@param[in]	���_���W
 *	@param[in]	�����_
 *	@param[in]	������x�N�g��
 *	@return	���_�ϊ��s��
 */
/**========================================================*/
Matrix4& Matrix4::setLookAt(const Vector3& eye,const Vector3& at ,const Vector3& up){
	Vector3 e  ((eye-at));
	e=e.normalize();
	Vector3 v ( up.OuterProduct(e));
	v=v.normalize();
	Vector3 u ( e.OuterProduct(v));
	u=u.normalize();
	m[0][0] = v.x_;								m[0][1] = u.x_;							m[0][2] = e.x_;								m[0][3] = 0.0f;
	m[1][0] = v.y_;								m[1][1] = u.y_;							m[1][2] = e.y_;								m[1][3] = 0.0f;
	m[2][0] = v.z_;								m[2][1] = u.z_;							m[2][2] = e.z_;								m[2][3] = 0.0f;
	m[3][0] = -eye.InnerProduct(v);		m[3][1] = -eye.InnerProduct(u);	m[3][2] = -eye.InnerProduct(e);		m[3][3] = 1.0f;

	return * this;
}
/**========================================================*/
/**
 *	@brief	���W�ϊ�
 *	@param[in]	�R�����x�N�g��
 *	@return	�ϊ��������W
 */
/**========================================================*/
Vector3 Matrix4::transForm(const Vector3& v)const{
	float x	= v.x_	*	 m[0][0] + v.y_ * m[1][0] + v.z_ * m[2][0] + m[3][0];
	float y	= v.x_	*	 m[0][1] + v.y_ * m[1][1] + v.z_ * m[2][1] + m[3][1];
	float z	= v.x_	*	 m[0][2] + v.y_ * m[1][2] + v.z_ * m[2][2] + m[3][2];
	float w	= v.x_	*	 m[0][3] + v.y_ * m[1][3] + v.z_ * m[2][3] + m[3][3];

	return	Vector3( x / w, y / w, z / w );
}

/**========================================================*/
/**
 *	@brief	<�v��>
 *	@param[in]	<����>
 *	@attention	<���ӏ���>
 *	@note	<��������>
 *	@author	KORYUOH
 *	@return	<�߂�l>
 */
/**========================================================*/
Vector3 Matrix4::transformNomal(const Vector3& v)const{
	float x = v.x_ * m[0][0] + v.y_ * m[1][0] + v.z_ * m[2][0];
	float y = v.x_ * m[0][1] + v.y_ * m[1][1] + v.z_ * m[2][1];
	float z = v.x_ * m[0][2] + v.y_ * m[1][2] + v.z_ * m[2][2];

	return	Vector3( x, y, z );

}

/**========================================================*/
/**
 *	@brief	������Z�q�I�[�o�[���[�h
 *	@param[in]	��
 *	@return	���g
 */
/**========================================================*/
Matrix4& Matrix4::operator *= ( const Matrix4& other )
{
	Matrix4	temp;

	for ( int i = 0; i < 4; i++ ) {
		for ( int j = 0; j < 4; j++ ) {
			temp.m[i][j] = 0;
			for ( int k = 0; k < 4; k++ ) {
				 temp.m[i][j] += m[i][k] * other.m[k][j];
			}
		}
	}
	*this = temp;

	return	*this;
}

/**========================================================*/
/**
 *	@brief	�Q�����Z�q�I�[�o�[���[�h
 *	@param[in]	�}�g���b�N�X
 *	@param[in]	�}�g���b�N�X
 *	@return	���g
 */
/**========================================================*/
const Matrix4 operator * ( const Matrix4& m1, const Matrix4& m2 )
{
	Matrix4	temp(m1);

	return	temp *= m2;
}
/**========================================================*/
/**
 *	@brief	�Q�����Z�q�I�[�o�[���[�h
 *	@param[in]	�x�N�g��
 *	@param[in]	�}�g���b�N�X
 *	@return	���g
 */
/**========================================================*/

const Vector3 operator * ( const Vector3& v, const Matrix4& m )
{
	return	m.transForm( v );
}



/**===End Of File==========================================*/