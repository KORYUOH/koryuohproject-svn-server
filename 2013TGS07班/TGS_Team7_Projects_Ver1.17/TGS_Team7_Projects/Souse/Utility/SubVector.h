/******************************************************************************
* File Name : SubVector.h                         Ver : 1.00  Date : 2013-05-05
*
* Description :
*
*		�x�N�g���⏕�֐��Q�D
*
******************************************************************************/
#ifndef _SUB_VECTOR_H_
#define _SUB_VECTOR_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include"Math.h"
#include<gslib.h>


/// <summary>
/// 2�_�Ԃ̋��������߂�.
/// </summary>
/// <param name="my">���g�̃x�N�g��</param>
/// <param name="target">����̃x�N�g��</param>
/// <returns>��������Ԃ�</returns>
float Distance( const GSvector2& my, const GSvector2& target );

/// <summary>
/// �^�[�Q�b�g�����ւ̈ړ����������߂�.
/// </summary>
/// <param name="my">���g�̃x�N�g��</param>
/// <param name="target">����̃x�N�g��</param>
/// <param name="speed">���x</param>
/// <returns>�ړ�������Ԃ�</returns>
GSvector2 Velocity( const GSvector2& my, const GSvector2& target, float speed = 1.0f );


/// <summary>
/// �w������ւ̈ړ��ʂ����߂�.
/// <para>�p�x����x�N�g�������߂�.</para>
/// </summary>
/// <param name="angle">�p�x</param>
/// <param name="speed">���x</param>
/// <returns>�ړ��ʂ�Ԃ�</returns>
GSvector2 Velocity( float angle, float speed = 1.0f );


/// <summary>
/// �x�N�g���̌����Ă���p�x�����߂�.
/// <para>�x�N�g������p�x�����߂�.</para>
/// </summary>
/// <param name="v">�x�N�g��</param>
/// <returns>�p�x��Ԃ�</returns>
float Angle( const GSvector2& v );


/// <summary>
/// �^�[�Q�b�g�����ւ̊p�x�����߂�.
/// </summary>
/// <param name="my">���g�̃x�N�g��</param>
/// <param name="target">����̃x�N�g��</param>
/// <returns>�p�x��Ԃ�</returns>
float Angle( const GSvector2& my, const GSvector2& target );


/// <summary>
/// 2�̃x�N�g���̂Ȃ��p�x�����߂�.
/// </summary>
/// <param name="a">�x�N�g��A</param>
/// <param name="b">�x�N�g��B</param>
/// <returns>�p�x��Ԃ�</returns>
float InnerAngle( const GSvector2& a, const GSvector2& b );


/// <summary>
/// �x�N�g���̐��`���.
/// </summary>
/// <param name="start">�J�n�x�N�g��</param>
/// <param name="end">�I���x�N�g��</param>
/// <param name="t">����</param>
/// <returns>��Ԍ�̃x�N�g����Ԃ�</returns>
GSvector2 InnerAngle( const GSvector2& start, const GSvector2& end, float t );


/// <summary>
/// �p�x�̐��K��.
/// <para>(-360.0f�`360.0f)</para>
/// </summary>
/// <param name="angle">�p�x</param>
/// <returns>���K����̊p�x��Ԃ�</returns>
float NormalizeAngle( float angle );


/// <summary>
/// �p�x�������߂�.
/// </summary>
/// <param name="my">���g�̊p�x</param>
/// <param name="target">�Ώۂ̊p�x</param>
/// <returns>�p�x��Ԃ�</returns>
float SubtractAngle( float my, float target );


/// <summary>
/// �p�x�������߂�.
/// </summary>
/// <param name="my">���g�̃x�N�g��</param>
/// <param name="dir">�p�x</param>
/// <param name="target">�Ώۂ̃x�N�g��</param>
/// <returns>�p�x��Ԃ�</returns>
float SubtractAngle( const GSvector2& my, float dir, const GSvector2& target );

#endif // _SUB_VECTOR_H_ end

/********** End of File ******************************************************/