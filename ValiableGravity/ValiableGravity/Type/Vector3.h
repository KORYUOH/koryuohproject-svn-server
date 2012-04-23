/******************************************************************************
* File Name : Vector3.h                          Ver : 1.00  Date : 2005-04-27
*
* Description :
*
*       �R�c�x�N�g���v�Z �w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_Vector3_H_
#define		_Vector3_H_

struct Vector3
{
	float		x;								// x����
	float		y;								// y����
	float		z;								// z����

	// �R���X�g���N�^
	Vector3();
	Vector3( float X, float Y, float Z );

	// �����o�֐�
	float    length() const;					// �m���������߂�
	Vector3& normalize();						// ���K������
	float    dot( const Vector3& v ) const; 	// ���ς����߂�
	Vector3  cross( const Vector3& v ) const;	// �O�ς����߂�

	// �P�����Z�q�I�[�o�[���[�h
	Vector3  operator + () const;
	Vector3  operator - () const;

	// ������Z�q�I�[�o�[���[�h
	Vector3&  operator += ( const Vector3& v );
	Vector3&  operator -= ( const Vector3& v );
	Vector3&  operator *= ( float s );
	Vector3&  operator /= ( float s );
};

// �Q�����Z�q�I�[�o�[���[�h
const Vector3 operator + ( const Vector3& v1, const Vector3& v2 );
const Vector3 operator - ( const Vector3& v1, const Vector3& v2 );
const Vector3 operator * ( const Vector3& v, float s );
const Vector3 operator * ( float s, const Vector3& v );
const Vector3 operator / ( const Vector3& v, float s );

#endif

/********** End of File ******************************************************/
