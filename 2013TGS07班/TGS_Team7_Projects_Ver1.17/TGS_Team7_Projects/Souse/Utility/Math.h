/******************************************************************************
* File Name : Math.h                             Ver : 1.00  Date : 2013-05-05
*
* Description :
*
*		���w�N���X�D
*
******************************************************************************/
#ifndef _MATH_UTILITY_H_
#define _MATH_UTILITY_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<cmath>


/// <summary>
/// ���w�N���X.
/// </summary>
class Math
{
public:
	/// <summary>
	/// �~����.
	/// </summary>
	static const float PI;

public:
	/// <summary>
	/// �ő�l�����߂�.
	/// </summary>
	/// <param name="a">�lA</param>
	/// <param name="b">�lB</param>
	/// <returns>�ő�l��Ԃ�.</returns>
	static float Max( float a, float b );
	/// <summary>
	/// �ŏ��l�����߂�.
	/// </summary>
	/// <param name="a">�lA</param>
	/// <param name="b">�lB</param>
	/// <returns>�ŏ��l��Ԃ�.</returns>
	static float Min( float a, float b );
	/// <summary>
	/// �l���������l�̊ԂɎ��߂�.
	/// </summary>
	/// <param name="value">�l</param>
	/// <param name="low">�ŏ��l</param>
	/// <param name="height">�ő�l</param>
	/// <returns>�ő�l��Ԃ�.</returns>
	static float Clamp( float value, float low, float height );

public:
	/// <summary>
	/// �T�C��.
	/// </summary>
	/// <param name="degree">�p�x</param>
	/// <returns>�T�C���l��Ԃ�</returns>
	static float Sin( float degree );
	/// <summary>
	/// �R�T�C��.
	/// </summary>
	/// <param name="degree">�p�x</param>
	/// <returns>�R�T�C���l��Ԃ�</returns>
	static float Cos( float degree );
	/// <summary>
	/// �^���W�F���g.
	/// </summary>
	/// <param name="degree">�p�x</param>
	/// <returns>�^���W�F���g�l��Ԃ�</returns>
	static float Tan( float degree );
	/// <summary>
	/// �t�T�C��.
	/// </summary>
	/// <param name="x">X�l</param>
	/// <returns>�t�T�C���l��Ԃ�</returns>
	static float Asin( float x );
	/// <summary>
	/// �t�R�T�C��.
	/// </summary>
	/// <param name="x">X�l</param>
	/// <returns>�t�R�T�C���l��Ԃ�</returns>
	static float Acos( float x );
	/// <summary>
	/// �t�^���W�F���g.
	/// </summary>
	/// <param name="y">Y�l</param>
	/// <param name="x">X�l</param>
	/// <returns>�t�^���W�F���g�l��Ԃ�</returns>
	static float Atan( float y, float x );
	/// <summary>
	/// �p�x�����W�A���ɕϊ�.
	/// </summary>
	/// <param name="degree">�p�x</param>
	/// <returns>���W�A���l��Ԃ�</returns>
	static float Radian( float degree );
	/// <summary>
	/// ���W�A�����p�x�ɕϊ�.
	/// </summary>
	/// <param name="radian">���W�A��</param>
	/// <returns>�p�x�l</returns>
	static float Degree( float radian );


};


#endif // _MATH_UTILITY_H_ end

/********** End of File ******************************************************/