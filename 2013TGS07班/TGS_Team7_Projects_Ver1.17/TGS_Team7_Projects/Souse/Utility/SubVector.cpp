/******************************************************************************
* File Name : SubVector.cpp                       Ver : 1.00  Date : 2013-05-05
*
* Description :
*
*		�x�N�g���⏕�֐��Q�D
*
******************************************************************************/
#include"SubVector.h"


/// <summary>
/// 2�_�Ԃ̋��������߂�.
/// </summary>
/// <param name="my">���g�̃x�N�g��</param>
/// <param name="target">����̃x�N�g��</param>
/// <returns>��������Ԃ�</returns>
float Distance( const GSvector2& my, const GSvector2& target )
{
	return (target-my).length();
}

/// <summary>
/// �^�[�Q�b�g�����ւ̈ړ����������߂�.
/// </summary>
/// <param name="my">���g�̃x�N�g��</param>
/// <param name="target">����̃x�N�g��</param>
/// <param name="speed">���x</param>
/// <returns>�ړ�������Ԃ�</returns>
GSvector2 Velocity( const GSvector2& my, const GSvector2& target, float speed )
{
	return (target-my).getNormalized() * speed;
}

/// <summary>
/// �w������ւ̈ړ��ʂ����߂�.
/// <para>�p�x����x�N�g�������߂�.</para>
/// </summary>
/// <param name="angle">�p�x</param>
/// <param name="speed">���x</param>
/// <returns>�ړ��ʂ�Ԃ�</returns>
GSvector2 Velocity( float angle, float speed )
{
	return GSvector2( Math::Cos( angle ), Math::Sin( angle ) ) * speed;
}


/// <summary>
/// �x�N�g���̌����Ă���p�x�����߂�.
/// <para>�x�N�g������p�x�����߂�.</para>
/// </summary>
/// <param name="v">�x�N�g��</param>
/// <returns>�p�x��Ԃ�</returns>
float Angle( const GSvector2& v )
{
	return Math::Atan( v.y, v.x );
}

/// <summary>
/// �^�[�Q�b�g�����ւ̊p�x�����߂�.
/// </summary>
/// <param name="my">���g�̃x�N�g��</param>
/// <param name="target">����̃x�N�g��</param>
/// <returns>�p�x��Ԃ�</returns>
float Angle( const GSvector2& my, const GSvector2& target )
{
	return Angle( target - my );
}


/// <summary>
/// 2�̃x�N�g���̂Ȃ��p�x�����߂�.
/// </summary>
/// <param name="a">�x�N�g��A</param>
/// <param name="b">�x�N�g��B</param>
/// <returns>�p�x��Ԃ�</returns>
float InnerAngle( const GSvector2& a, const GSvector2& b )
{
	return Math::Acos( a.getNormalized().dot( b.getNormalized() ) );
}


/// <summary>
/// �x�N�g���̐��`���.
/// </summary>
/// <param name="start">�J�n�x�N�g��</param>
/// <param name="end">�I���x�N�g��</param>
/// <param name="t">����</param>
/// <returns>��Ԍ�̃x�N�g����Ԃ�</returns>
GSvector2 InnerAngle( const GSvector2& start, const GSvector2& end, float t )
{
	if( t < 0.0f )
	{
		t = 0.0f;
	}
	else if( t > 1.0f )
	{
		t = 1.0f;
	}

	return start * (1.0f-t) + end * t;
}

/// <summary>
/// �p�x�̐��K��.
/// <para>(-360.0f�`360.0f)</para>
/// </summary>
/// <param name="angle">�p�x</param>
/// <returns>���K����̊p�x��Ԃ�</returns>
float NormalizeAngle( float angle )
{
	return std::fmod( angle, 360.0f );
}

/// <summary>
/// �p�x�������߂�.
/// </summary>
/// <param name="my">���g�̊p�x</param>
/// <param name="target">�Ώۂ̊p�x</param>
/// <returns>�p�x��Ԃ�</returns>
float SubtractAngle( float my, float target )
{
	float d = NormalizeAngle( target - my );
	if( d > 180.0f )
	{
		d -= 360.0f;
	}
	else if( d < -180.0f )
	{
		d *= 360.0f;
	}
	return d;
}


/// <summary>
/// �p�x�������߂�.
/// </summary>
/// <param name="my">���g�̃x�N�g��</param>
/// <param name="dir">�p�x</param>
/// <param name="target">�Ώۂ̃x�N�g��</param>
/// <returns>�p�x��Ԃ�</returns>
float SubtractAngle( const GSvector2& my, float dir, const GSvector2& target )
{
	return SubtractAngle( dir, Angle( my, target ) );
}

/********** End of File ******************************************************/