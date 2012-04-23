/******************************************************************************
* File Name : Vector2.h                          Ver : 1.00  Date : 2005-04-27
*
* Description :
*
*       �Q�c�x�N�g���v�Z �w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_VECTOR2_H_
#define		_VECTOR2_H_

struct Vector2
{
	float		x;								// x����
	float		y;								// y����

	// �R���X�g���N�^
	Vector2();
	Vector2( float X, float Y );

	// �����o�֐�
	float    length() const;					// �m���������߂�
	Vector2& normalize();						// ���K������
	float    dot( const Vector2& v ) const; 	// ���ς����߂�

	// �P�����Z�q�I�[�o�[���[�h
	Vector2  operator + () const;
	Vector2  operator - () const;

	// ������Z�q�I�[�o�[���[�h
	Vector2&  operator += ( const Vector2& v );
	Vector2&  operator -= ( const Vector2& v );
	Vector2&  operator *= ( float s );
	Vector2&  operator /= ( float s );
};

// �Q�����Z�q�I�[�o�[���[�h
const Vector2 operator + ( const Vector2& v1, const Vector2& v2 );
const Vector2 operator - ( const Vector2& v1, const Vector2& v2 );
const Vector2 operator * ( const Vector2& v, float s );
const Vector2 operator * ( float s, const Vector2& v );
const Vector2 operator / ( const Vector2& v, float s );

#endif

/********** End of File ******************************************************/
