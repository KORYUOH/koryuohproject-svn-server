/******************************************************************************
* File Name : Math.h                           Ver : 1.00  Date : 2005-04-27
*
* Description :
*
*       �v�Z�N���X �w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_MATH_H_
#define		_MATH_H_

class Math
{
public:
	static const float PI;					// �~����

	static float sqrt( float x );			// ������

	static float sin( float degree );		// �T�C��
	static float cos( float degree );		// �R�T�C��
	static float tan( float degree );		// �^���W�F���g

	static float toRadian( float degree );	// �p�x�����W�A���ɕϊ�
	static float toDegree( float radian );	// ���W�A�����p�x�ɕϊ�
};

#endif

/********** End of File ******************************************************/
