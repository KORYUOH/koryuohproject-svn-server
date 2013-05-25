/******************************************************************************
* File Name : HumanManager.h                      Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		人材管理者クラス．
*
******************************************************************************/
#include"Human.h"
#include"../Utility/Math.h"
#include<algorithm>

/// <summary>
/// コンストラクタ.
/// </summary>
Human::Human():
	mHumanMax( 0.0f ),
	mHuman( 0.0f )
{
}

/// <summary>
/// 初期化.
/// </summary>
void Human::Initialize()
{
	mHuman = 0.0f;
	mHumanMax = 0.0f;
}

/// <summary>
/// 人材の最大値を設定する.
/// </summary>
/// <param name="humanMax">人材の最大値</param>
void Human::SetHumanMax( float humanMax )
{
	mHumanMax = humanMax;
	mHuman = Math::Clamp( mHuman, 0.0f, mHumanMax );
}

/// <summary>
/// 人材の取得する.
/// </summary>
/// <returns>人材を返す.</returns>
float Human::GetHuman() const
{
	return mHuman;
}

/// <summary>
/// 人材の最大値を取得する.
/// </summary>
/// <returns>人材を返す.</returns>
float Human::GetHumanMax() const
{
	return mHumanMax;
}

/// <summary>
/// 人材がゼロ人判定.
/// </summary>
/// <returns>人材がいるか判定.</returns>
bool Human::IsHumanZero() const
{
	return mHuman == 0.0f;
}

/// <summary>
/// 人材が定員か判定.
/// </summary>
/// <returns>定員の時真、そうでなければ偽を返す.</returns>
bool Human::IsHumanCapacity() const
{
	return mHuman >= mHumanMax;
}

/// <summary>
/// 人事異動できるか判定する.
/// </summary>
/// <param name="unit">ユニット</param>
/// <param name="human">増減量</param>
/// <returns>増減できる時真、そうでなければ偽を返す.</returns>
bool Human::IsPersonnelChange( float human ) const
{
	float resultHuman = human + mHuman;
	return 0.0f < resultHuman || resultHuman < mHumanMax;
}

/// <summary>
/// 移動先に人事異動できるか判定する.
/// </summary>
/// <param name="target">移動先</param>
/// <param name="human">増減量</param>
/// <returns>増減できる時真、そうでなければ偽を返す.</returns>
bool Human::IsPersonnelChange( const Human& target, float human ) const
{
	return IsPersonnelChange( -human ) && target.IsPersonnelChange( human );
}

/// <summary>
/// 人材を増減させる.
/// </summary>
/// <param name="human">増減量</param>
void Human::PersonnelChange( float human )
{
	mHuman = Math::Clamp( mHuman + human, 0.0f, mHumanMax );
}

/// <summary>
/// 自身から対象に人材を移動させる.
/// </summary>
/// <param name="target">移動先ユニット</param>
/// <param name="human">増減量</param>
void Human::PersonnelChange( Human& target, float human )
{
	PersonnelChange( -human );
	target.PersonnelChange( human );
}

/********** End of File ******************************************************/