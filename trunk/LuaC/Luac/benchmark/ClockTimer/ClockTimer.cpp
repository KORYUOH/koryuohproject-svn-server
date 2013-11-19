/**===File Commentary=======================================*/
/**
 *	@file	ClockTimer.cpp
 *
 *	@brief	タイマー
 *
 *	@author	KORYUOH
 *
 *	@date	2013/01/08
 */
/**===File Include=========================================*/
#include	<ClockTimer/ClockTimer.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	コンストラクタ
 */
/**========================================================*/
ClockTimer::ClockTimer()
	:mOldTime(clock())
	,mNewTime(clock())
{
}
/**========================================================*/
/**
 *	@brief	開始
 */
/**========================================================*/
void ClockTimer::start(){
	mOldTime = clock();
}
/**========================================================*/
/**
 *	@brief	停止・更新
 */
/**========================================================*/
void ClockTimer::stop(){
	while (mOldTime == (mNewTime = clock())) ;
}
/**========================================================*/
/**
 *	@brief	経過秒取得
 *	@return	経過時間
 */
/**========================================================*/
float ClockTimer::getTimerSec()const{
	return (float)(mNewTime - mOldTime) / (float)CLOCKS_PER_SEC;
}
/**========================================================*/
/**
 *	@brief	指定時間経過したか
 *	@param[in]	時間
 *	@return	経過していれば真
 */
/**========================================================*/
bool ClockTimer::isOverSec(float sec){
	return sec<getTimerSec();
}
/**========================================================*/
/**
 *	@brief	指定時間待機
 *	@param[in]	時間
 */
/**========================================================*/
void ClockTimer::WaitOverSec(float sec){
	while(!isOverSec(sec))
		stop();
}

/**===End Of File==========================================*/