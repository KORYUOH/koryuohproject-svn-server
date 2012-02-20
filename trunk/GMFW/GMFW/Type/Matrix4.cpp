/******************************************************************************
* File Name : Matrix4.cpp                        Ver : 1.00  Date : 2005-04-27
*
* Description :
*
*       �O�������W�ϊ��s��v�Z�D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"Matrix4.h"
#include	"Vector3.h"
#include	"Math.h"

// �R���X�g���N�^
Matrix4::Matrix4()
{
}

Matrix4::Matrix4(
	float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34,
	float m41, float m42, float m43, float m44  )
{
	m[0][0] = m11; m[0][1] = m12; m[0][2] = m13; m[0][3] = m14;
	m[1][0] = m21; m[1][1] = m22; m[1][2] = m23; m[1][3] = m24;
	m[2][0] = m31; m[2][1] = m32; m[2][2] = m33; m[2][3] = m34;
	m[3][0] = m41; m[3][1] = m42; m[3][2] = m43; m[3][3] = m44;
}

// �P�ʍs���ݒ�
Matrix4& Matrix4::setIdentity()
{
	m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;

	return	*this;
}

// ��]�s��̐ݒ�
Matrix4& Matrix4::setRotateX( float angle )
{
	float	Sin = Math::sin( angle );
	float	Cos = Math::cos( angle );

	m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = Cos;  m[1][2] = -Sin; m[1][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = Sin;  m[2][2] = Cos;  m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;

	return	*this;
}

Matrix4& Matrix4::setRotateY( float angle )
{
	float	Sin = Math::sin( angle );
	float	Cos = Math::cos( angle );

	m[0][0] = Cos;  m[0][1] = 0.0f; m[0][2] = -Sin; m[0][3] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
	m[2][0] = Sin;  m[2][1] = 0.0f; m[2][2] = Cos;  m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;

	return	*this;
}

Matrix4& Matrix4::setRotateZ( float angle )
{
	float	Sin = Math::sin( angle );
	float	Cos = Math::cos( angle );

	m[0][0] = Cos;  m[0][1] = Sin;  m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = -Sin; m[1][1] = Cos;  m[1][2] = 0.0f; m[1][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;

	return	*this;
}

// ���s�ړ��s��̐ݒ�
Matrix4& Matrix4::setTranslate( const Vector3& v )
{
	m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
	m[3][0] = v.x;  m[3][1] = v.y;  m[3][2] = v.z;  m[3][3] = 1.0f;

	return	*this;
}

// ���s�ړ��s��̐ݒ�
Matrix4& Matrix4::setScale( const Vector3& v )
{
	m[0][0] = v.x;  m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = v.y;  m[1][2] = 0.0f; m[1][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = v.z;  m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;

	return	*this;
}

// �����ϊ��s��̐ݒ�
Matrix4& Matrix4::setPerspective( float fov, float aspect, float near, float far )
{
	float f = 1.0f / Math::tan( fov / 2.0f );

	m[0][0] = f / aspect;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;

	m[1][0] = 0.0f;
	m[1][1] = f;
	m[1][2] = 0.0f;
	m[1][3] = 0.0f;

	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = ( far + near ) / ( near - far );
	m[2][3] = -1.0f;

	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = ( 2.0f * far * near ) / ( near - far );
	m[3][3] = 0.0f;

	return	*this;
}

// ����ϊ��s���ݒ�
Matrix4& Matrix4::setLookAt( const Vector3& eye, const Vector3& at, const Vector3& up )
{
	// �������̃x�N�g�������߂�
	Vector3 e( eye - at );
	e.normalize();
	// �������̃x�N�g�������߂�
	Vector3 v( up.cross( e ) );
	v.normalize();
	// �������̃x�N�g�������߂�
	Vector3 u( e.cross( v ) );

	// ��]�s��Ɋe�x�N�g����ݒ肷��
	m[0][0] = v.x;
	m[0][1] = u.x;
	m[0][2] = e.x;
	m[0][3] = 0.0f;

	m[1][0] = v.y;
	m[1][1] = u.y;
	m[1][2] = e.y;
	m[1][3] = 0.0f;

	m[2][0] = v.z;
	m[2][1] = u.z;
	m[2][2] = e.z;
	m[2][3] = 0.0f;

	// ���_�̈ʒu��ݒ肷��
	m[3][0] = -eye.dot( v );
	m[3][1] = -eye.dot( u );
	m[3][2] = -eye.dot( e );
	m[3][3] = 1.0f;

	return	*this;
}

// ���W�ϊ��i�x�N�g���ƍs��̊|���Z������j
Vector3 Matrix4::transform( const Vector3& v ) const
{
	float x = v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0] + m[3][0];
	float y = v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1] + m[3][1];
	float z = v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2] + m[3][2];
	float w = v.x * m[0][3] + v.y * m[1][3] + v.z * m[2][3] + m[3][3];

	return	Vector3( x / w, y / w, z / w );
}

// ���W�ϊ��i�@���x�N�g���p�ŉ�]�݂̂ŕ��s�ړ��͂����Ȃ��j
Vector3 Matrix4::transformNormal( const Vector3& v ) const
{
	float x = v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0];
	float y = v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1];
	float z = v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2];

	return	Vector3( x, y, z );
}

// ������Z�q�I�[�o�[���[�h
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

// �Q�����Z�q�I�[�o�[���[�h
const Matrix4 operator * ( const Matrix4& m1, const Matrix4& m2 )
{
	Matrix4	temp(m1);

	return	temp *= m2;
}

const Vector3 operator * ( const Vector3& v, const Matrix4& m )
{
	return	m.transform( v );
}

/********** End of File ******************************************************/
