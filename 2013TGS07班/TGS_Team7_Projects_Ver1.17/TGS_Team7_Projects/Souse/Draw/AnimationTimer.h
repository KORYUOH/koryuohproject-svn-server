/******************************************************************************
* File Name : AnimationTimer.h                   Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		アニメーションタイマー．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _ANIMATION_TIMER_H_
#define _ANIMATION_TIMER_H_


/// <summary>
/// アニメーションタイマークラス.
/// </summary>
class AnimationTimer
{
	/*---- コンストラクタ・デストラクタの宣言 -------------------------------*/
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	AnimationTimer();
	/// <summary>
	/// 初期化.
	/// </summary>
	void Initialize();

	/*---- メンバ関数の宣言 -------------------------------------------------*/
public:
	/// <summary>
	/// 更新.
	/// </summary>
	/// <param name="frameTimer">フレームレート</param>
	void Update( float frameTimer );
	/// <summary>
	/// タイマーが動いているか判定.
	/// </summary>
	/// <returns>動いていれば真、そうでなければ偽を返す.</returns>
	bool IsStop();
	/// <summary>
	/// 最大時間でリセットする.
	/// </summary>
	void Reset();
	/// <summary>
	/// タイマーがゼロ判定.
	/// </summary>
	/// <returns>タイマーがゼロの時真、そうでなければ偽を返す.</returns>
	bool IsZero();
	/// <summary>
	/// タイマー開始処理.
	/// </summary>
	void Start();
	/// <summary>
	/// マックスタイムで秒を設定.
	/// </summary>
	/// <param name="time">最大時間</param>
	void SetMaxTime(float time);

	/*---- メンバ変数の定義 -------------------------------------------------*/
private:
	/// <summary>
	/// 最大時間.
	/// </summary>
	int mMaxTime;
	/// <summary>
	/// 時間.
	/// </summary>
	float mTimer;
	/// <summary>
	/// スタートフラグ.
	/// </summary>
	bool mIsStart;

}; // AnimationTimer end


#endif // _ANIMATION_TIMER_H_ end

/********** End of File ******************************************************/
