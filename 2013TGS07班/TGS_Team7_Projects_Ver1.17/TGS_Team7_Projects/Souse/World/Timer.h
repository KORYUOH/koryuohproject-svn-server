/******************************************************************************
* File Name : Timer.h                             Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		タイマー処理．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _TIMER_H_
#define _TIMER_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include"../Draw/TextureNumber.h"

/*---- 先行宣言 -------------------------------------------------------------*/

class IRenderer;

/// <summary>
/// タイマークラス.
/// </summary>
class Timer
{
public:
	/// <summary>
	//コンストラクタ
	/// </summary>
	Timer();
	/// <summary>
	//初期化
	/// </summary>
	/// <param name="limitTime">制限時間</param>
	void Initialize( float limitTime );
	/// <summary>
	//更新.
	/// </summary>
	/// <param name="frameTimer">フレームレート</param>
	void Update( float frameTimer);
	/// <summary>
	/// 時間を取得(フレーム時間で取得)
	/// </summary>
	/// <returns>時間(fps)を返す.</returns>
	float GetTimerF() const;
	/// <summary>
	/// 時間を取得(秒数で取得)
	/// </summary>
	/// <returns>時間(s)を返す.</returns>
	float GetTimerS() const;
	/// <summary>
	/// 時間切れ判定
	/// </summary>
	/// <returns>時間切れの時に真、そうでなければ偽を返す.</returns>
	bool isTimeOver() const;
	/// <summary>
	/// 描画.
	/// </summary>
	void Draw();

private:
	/// <summary>
	/// 時間.
	/// </summary>
	float mTime;
	/// <summary>
	/// 制限時間定数.
	/// </summary>
	static const int TIME_LIMIT;
	/// <summary>
	/// フレームレート.
	/// </summary>
	static const int FRAME_RATE;
	/// <summary>
	/// 数列描画管理者.
	/// </summary>
	TextureNumber	mNumber;
};

#endif

/********** End of File ******************************************************/
