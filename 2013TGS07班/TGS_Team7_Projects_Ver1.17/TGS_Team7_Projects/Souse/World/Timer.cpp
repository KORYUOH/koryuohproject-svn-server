/******************************************************************************
* File Name : Timer.cpp                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		タイマー処理．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Timer.h"
#include<gslib.h>
#include"../Draw/TextureID.h"
#include"../Draw/Renderer.h"
#include"../Utility/Screen.h"

/// <summary>
/// 制限時間定数.
/// </summary>
const int Timer::TIME_LIMIT = 180;

/// <summary>
/// フレームレート.
/// </summary>
const int Timer::FRAME_RATE = 60;


/// <summary>
//コンストラクタ
/// <summary>
Timer::Timer():
	mTime( 0.0f ),
	mNumber( TEXTURE_GUI_NUMBER, 16, 32 )
{
	// 表示桁数を設定.
	mNumber.SetField( 4 );
}

/// <summary>
//初期化
/// </summary>
/// <param name="limitTime">制限時間</param>
void Timer::Initialize( float limitTime )
{
	mTime = limitTime * FRAME_RATE;
}

/// <summary>
//更新.
/// </summary>
/// <param name="frameTimer">フレームレート</param>
void Timer::Update( float frameTimer)
{
	mTime -= 1.0f * frameTimer;
	mTime = MAX( mTime , 0.0f ); 
}

/// <summary>
/// 時間を取得(フレーム時間で取得)
/// </summary>
/// <returns>時間(fps)を返す.</returns>
float Timer::GetTimerF() const
{
	return mTime;
}

/// <summary>
/// 時間を取得(秒数で取得)
/// </summary>
/// <returns>時間(s)を返す.</returns>
float Timer::GetTimerS() const
{
	return mTime / FRAME_RATE;
}

/// <summary>
/// 時間切れ判定
/// </summary>
/// <returns>時間切れの時に真、そうでなければ偽を返す.</returns>
bool Timer::isTimeOver() const
{
	return mTime <= 0.0f;
}

/// <summary>
/// 描画.
/// </summary>
void Timer::Draw()
{
	Renderer::GetInstance()->DrawTexture( TEXTURE_GUI_TIMER, GSvector2(Screen::WIDTH,0.0f) );
	mNumber.Draw( GSvector2(Screen::WIDTH*0.5f,15.0f), (int)GetTimerS() );
}

/********** End of File ******************************************************/