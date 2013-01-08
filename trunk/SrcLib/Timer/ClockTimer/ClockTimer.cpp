/**===File Commentary=======================================*/
/**
 *	@file	ClockTimer.cpp
 *
 *	@brief	�^�C�}�[
 *
 *	@author	KORYUOH
 *
 *	@date	2013/01/08
 */
/**===File Include=========================================*/
#include	<Timer/ClockTimer/ClockTimer.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 */
/**========================================================*/
ClockTimer::ClockTimer()
	:mOldTime(clock())
	,mNewTime(clock())
{
}
/**========================================================*/
/**
 *	@brief	�J�n
 */
/**========================================================*/
void ClockTimer::start(){
	mOldTime = clock();
}
/**========================================================*/
/**
 *	@brief	��~�E�X�V
 */
/**========================================================*/
void ClockTimer::stop(){
	while (mOldTime == (mNewTime = clock())) ;
}
/**========================================================*/
/**
 *	@brief	�o�ߕb�擾
 *	@return	�o�ߎ���
 */
/**========================================================*/
float ClockTimer::getTimerSec()const{
	return (float)(mNewTime - mOldTime) / (float)CLOCKS_PER_SEC;
}
/**========================================================*/
/**
 *	@brief	�w�莞�Ԍo�߂�����
 *	@param[in]	����
 *	@return	�o�߂��Ă���ΐ^
 */
/**========================================================*/
bool ClockTimer::isOverSec(float sec){
	return sec<getTimerSec();
}
/**========================================================*/
/**
 *	@brief	�w�莞�ԑҋ@
 *	@param[in]	����
 */
/**========================================================*/
void ClockTimer::WaitOverSec(float sec){
	while(!isOverSec(sec))
		stop();
}

/**===End Of File==========================================*/