/**===File Commentary=======================================*/
/**
 *	@file	MultiMediaTimer.cpp
 *
 *	@brief	�}���`���f�B�A�^�C�}�[
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
 *	@brief	�R���X�g���N�^
 */
/**========================================================*/
MultiMediaTimer::MultiMediaTimer()
	:mOldTime(timeGetTime())
	,mNewTime(timeGetTime())
{}
/**========================================================*/
/**
 *	@brief	�J�n
 */
/**========================================================*/
void MultiMediaTimer::start(){
	mOldTime = timeGetTime();
}
/**========================================================*/
/**
 *	@brief	��~�E�X�V
 */
/**========================================================*/
void MultiMediaTimer::stop(){
	while (mOldTime == (mNewTime = timeGetTime())) ;
}
/**========================================================*/
/**
 *	@brief	�o�ߎ��Ԏ擾
 *	@return	�o�ߎ���[ms]
 */
/**========================================================*/
unsigned long MultiMediaTimer::getTimeMills()const{
	return mNewTime - mOldTime;
}
/**========================================================*/
/**
 *	@brief	�V�X�e���o�ߎ��Ԏ擾
 *	@return	�V�X�e���o�ߎ���
 */
/**========================================================*/
unsigned long MultiMediaTimer::getSystemMills()const{
	return mOldTime;
}
/**========================================================*/
/**
 *	@brief	�w�莞�Ԍo�߂�����?
 *	@param[in]	�w�莞��
 *	@return	�o�߂��Ă���ΐ^
 */
/**========================================================*/
bool MultiMediaTimer::isOverMills(unsigned long ms)const{
	return ms<getTimeMills();
}

/**===End Of File==========================================*/