/******************************************************************************
* File Name : Matrix4.h                          Ver : 1.00  Date : 2005-04-27
*
* Description :
*
*       �O�������W�ϊ��s��v�Z �w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_MATRIX4_H_
#define		_MATRIX4_H_

struct Vector3;

struct Matrix4
{
	float			m[4][4];			// �s�񐬕�

	// �R���X�g���N�^
	Matrix4();
	Matrix4( float m11, float m12, float m13, float m14,
			 float m21, float m22, float m23, float m24,
			 float m31, float m32, float m33, float m34,
			 float m41, float m42, float m43, float m44 );

	// �P�ʍs��̐ݒ�
	Matrix4& setIdentity();

	// �g��k���s��̐ݒ�
	Matrix4& setScale( const Vector3& v );

	// ��]�s��̐ݒ�
	Matrix4& setRotateX( float angle );	// x������̉�]
	Matrix4& setRotateY( float angle );	// y������̉�]
	Matrix4& setRotateZ( float angle );	// z������̉�]

	// ���s�ړ��s��̐ݒ�
	Matrix4& setTranslate( const Vector3& v );

	// �����ϊ��s��̐ݒ�
	Matrix4& setPerspective( float fov, float aspect, float near, float far );

	// ����ϊ��s��̐ݒ�
	Matrix4& setLookAt( const Vector3& eye, const Vector3& at, const Vector3& up );

	// ���W�ϊ��i�x�N�g���ƍs��̊|���Z������j
	Vector3 transform( const Vector3& v ) const;

	// ���W�ϊ��i�@���x�N�g���p�ŉ�]�݂̂ŕ��s�ړ��͂����Ȃ��j
	Vector3 transformNormal( const Vector3& v ) const;

	// ������Z�q�I�[�o�[���[�h
	Matrix4& operator *= ( const Matrix4& other );
};

// �Q�����Z�q�I�[�o�[���[�h
const Matrix4 operator * ( const Matrix4& m1, const Matrix4& m2 );
const Vector3 operator * ( const Vector3& v , const Matrix4& m  );

#endif

/********** End of File ******************************************************/
