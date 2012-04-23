/******************************************************************************
* File Name : Color4.h                           Ver : 1.00  Date : 2005-04-27
*
* Description :
*
*       �q�f�a�`�J���[ �w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_COLOR4_H_
#define		_COLOR4_H_

struct Color4
{
	float		r;					// ������
	float		g;					// ������
	float		b;					// ������
	float		a;					// ������

	// �R���X�g���N�^
	Color4();
	Color4( float R, float G, float B, float A );

	// �����o�֐�
	Color4& saturate();				// 0.0�`1.0�͈̔͂ɃN�����v

	// �P�����Z�q�I�[�o�[���[�h
	Color4  operator + () const;
	Color4  operator - () const;	// ��F�����߂�

	// ������Z�q�I�[�o�[���[�h
	Color4&  operator += ( const Color4& c2 );
	Color4&  operator -= ( const Color4& c2 );
	Color4&  operator *= ( const Color4& c2 );
	Color4&  operator /= ( const Color4& c2 );
	Color4&  operator *= ( float s );
	Color4&  operator /= ( float s );

};

// �Q�����Z�q�I�[�o�[���[�h
const Color4 operator + ( const Color4& c1, const Color4& c2 );
const Color4 operator - ( const Color4& c1, const Color4& c2 );
const Color4 operator * ( const Color4& c1, const Color4& c2 );
const Color4 operator * ( float s, const Color4& c );
const Color4 operator * ( const Color4& c, float s );
const Color4 operator / ( const Color4& c, float s );

#endif

/********** End of File ******************************************************/
