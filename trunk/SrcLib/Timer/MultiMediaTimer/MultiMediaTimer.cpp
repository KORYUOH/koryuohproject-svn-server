/**===File Commentary=======================================*/
/**
 *	@file	MultiMediaTimer.cpp
 *
 *	@brief	マルチメディアタイマー
 *
 *	@author	KORYUOH
 *
 *	@date	2013/01/08
 */
/**===File Include=========================================*/
#include	<Timer/MultiMediaTimer/MultiMediaTimer.h>
#include	<Windows.h>
#include	<MMSystem.h>
#pragma comment(lib,"winmm.lib")
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	コンストラクタ
 */
/**========================================================*/
MultiMediaTimer::MultiMediaTimer()
	:mOldTime(timeGetTime())
	,mNewTime(timeGetTime())
{}
/**========================================================*/
/**
 *	@brief	開始
 */
/**========================================================*/
void MultiMediaTimer::start(){
	mOldTime = timeGetTime();
}
/**========================================================*/
/**
 *	@brief	停止・更新
 */
/**========================================================*/
void MultiMediaTimer::stop(){
	while (mOldTime == (mNewTime = timeGetTime())) ;
}
/**========================================================*/
/**
 *	@brief	経過時間取得
 *	@return	経過時間[ms]
 */
/**========================================================*/
unsigned long MultiMediaTimer::getTimeMills()const{
	return mNewTime - mOldTime;
}
/**========================================================*/
/**
 *	@brief	システム経過時間取得
 *	@return	システム経過時間
 */
/**========================================================*/
unsigned long MultiMediaTimer::getSystemMills()const{
	return mOldTime;
}
/**========================================================*/
/**
 *	@brief	指定時間経過したか?
 *	@param[in]	指定時間
 *	@return	経過していれば真
 */
/**========================================================*/
bool MultiMediaTimer::isOverMills(unsigned long ms)const{
	return ms<getTimeMills();
}

/**===End Of File==========================================*/