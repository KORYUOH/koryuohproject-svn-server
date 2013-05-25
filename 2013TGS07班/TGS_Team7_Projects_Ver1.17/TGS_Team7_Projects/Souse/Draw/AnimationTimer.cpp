/******************************************************************************
* File Name : AnimationTimer.cpp                 Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		アニメーションタイマー．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"AnimationTimer.h"
#include<gslib.h>

/// <summary>
/// コンストラクタ.
/// </summary>
AnimationTimer::AnimationTimer():
	mMaxTime(0),
	mTimer(0),
	mIsStart(true)
{
}

/// <summary>
/// 初期化.
/// </summary>
void AnimationTimer::Initialize()
{
	// 最大時間を0.3秒に設定.
	mMaxTime = (int)(60 * 0.3f);
	// タイムを初期化.
	mTimer = mMaxTime;
	// スタートフラグを初期化.
	mIsStart = true;
}

/// <summary>
/// 更新.
/// </summary>
	/// <param name="frameTimer">フレームレート</param>
void AnimationTimer::Update( float frameTimer )
{
	// 終了している時.
	if( IsStop() )
	{
		// 早期終了.
		return;
	}

	//時間を更新
	mTimer -= frameTimer;
	mTimer = MAX( 0.0f, mTimer );
}

/// <summary>
/// タイマーが動いているか判定.
/// </summary>
/// <returns>動いていれば真、そうでなければ偽を返す.</returns>
bool AnimationTimer::IsStop()
{
	// スタートフラグが無効なのか？.
	return ( mIsStart == false );
}

/// <summary>
/// 最大時間でリセットする.
/// </summary>
void AnimationTimer::Reset()
{
	// 時間をリセット.
	mTimer = mMaxTime;
}

/// <summary>
/// タイマーがゼロ判定.
/// </summary>
/// <returns>タイマーがゼロの時真、そうでなければ偽を返す.</returns>
bool AnimationTimer::IsZero()
{
	return mTimer <= 0.0f;
}

/// <summary>
/// タイマー開始処理.
/// </summary>
void AnimationTimer::Start()
{
	// スタートフラグを有効にする.
	mIsStart = true;
}

/// <summary>
/// マックスタイムで秒を設定.
/// </summary>
/// <param name="time">最大時間</param>
void AnimationTimer::SetMaxTime(float time)
{
	mMaxTime = (int)(60 * time);
}

/********** End of File ******************************************************/