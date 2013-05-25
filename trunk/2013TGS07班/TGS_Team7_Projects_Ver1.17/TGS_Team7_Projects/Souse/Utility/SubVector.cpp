/******************************************************************************
* File Name : SubVector.cpp                       Ver : 1.00  Date : 2013-05-05
*
* Description :
*
*		ベクトル補助関数群．
*
******************************************************************************/
#include"SubVector.h"


/// <summary>
/// 2点間の距離を求める.
/// </summary>
/// <param name="my">自身のベクトル</param>
/// <param name="target">相手のベクトル</param>
/// <returns>距離をを返す</returns>
float Distance( const GSvector2& my, const GSvector2& target )
{
	return (target-my).length();
}

/// <summary>
/// ターゲット方向への移動距離を求める.
/// </summary>
/// <param name="my">自身のベクトル</param>
/// <param name="target">相手のベクトル</param>
/// <param name="speed">速度</param>
/// <returns>移動距離を返す</returns>
GSvector2 Velocity( const GSvector2& my, const GSvector2& target, float speed )
{
	return (target-my).getNormalized() * speed;
}

/// <summary>
/// 指定方向への移動量を求める.
/// <para>角度からベクトルを求める.</para>
/// </summary>
/// <param name="angle">角度</param>
/// <param name="speed">速度</param>
/// <returns>移動量を返す</returns>
GSvector2 Velocity( float angle, float speed )
{
	return GSvector2( Math::Cos( angle ), Math::Sin( angle ) ) * speed;
}


/// <summary>
/// ベクトルの向いている角度を求める.
/// <para>ベクトルから角度を求める.</para>
/// </summary>
/// <param name="v">ベクトル</param>
/// <returns>角度を返す</returns>
float Angle( const GSvector2& v )
{
	return Math::Atan( v.y, v.x );
}

/// <summary>
/// ターゲット方向への角度を求める.
/// </summary>
/// <param name="my">自身のベクトル</param>
/// <param name="target">相手のベクトル</param>
/// <returns>角度を返す</returns>
float Angle( const GSvector2& my, const GSvector2& target )
{
	return Angle( target - my );
}


/// <summary>
/// 2つのベクトルのなす角度を求める.
/// </summary>
/// <param name="a">ベクトルA</param>
/// <param name="b">ベクトルB</param>
/// <returns>角度を返す</returns>
float InnerAngle( const GSvector2& a, const GSvector2& b )
{
	return Math::Acos( a.getNormalized().dot( b.getNormalized() ) );
}


/// <summary>
/// ベクトルの線形補間.
/// </summary>
/// <param name="start">開始ベクトル</param>
/// <param name="end">終了ベクトル</param>
/// <param name="t">時間</param>
/// <returns>補間後のベクトルを返す</returns>
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
/// 角度の正規化.
/// <para>(-360.0f～360.0f)</para>
/// </summary>
/// <param name="angle">角度</param>
/// <returns>正規化後の角度を返す</returns>
float NormalizeAngle( float angle )
{
	return std::fmod( angle, 360.0f );
}

/// <summary>
/// 角度差を求める.
/// </summary>
/// <param name="my">自身の角度</param>
/// <param name="target">対象の角度</param>
/// <returns>角度を返す</returns>
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
/// 角度差を求める.
/// </summary>
/// <param name="my">自身のベクトル</param>
/// <param name="dir">角度</param>
/// <param name="target">対象のベクトル</param>
/// <returns>角度を返す</returns>
float SubtractAngle( const GSvector2& my, float dir, const GSvector2& target )
{
	return SubtractAngle( dir, Angle( my, target ) );
}

/********** End of File ******************************************************/