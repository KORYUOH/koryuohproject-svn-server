/**===File Commentary=======================================*/
/**
 *	@file	ClockTimer.h
 *
 *	@brief	�^�C�}�[
 *
 *	@author	KORYUOH
 *
 *	@date	2013/01/08
 */
/**===Include Guard========================================*/
#ifndef	_CLOCKTIMER_H_
#define	_CLOCKTIMER_H_
/**===File Include=========================================*/
#include	<ctime>
/**===Class Definition=====================================*/
class ClockTimer{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 */
	ClockTimer();
	/**
	 *	@brief	�f�X�g���N�^
	 */
	virtual ~ClockTimer(){}
	/**
	 *	@brief	�J�n
	 */
	void start();
	/**
	 *	@brief	��~�E�X�V
	 */
	void stop();
	/**
	 *	@brief	�o�ߎ��Ԏ擾
	 *	@return	�o�ߎ���
	 */
	float getTimerSec()const;
	/**
	 *	@brief	�w�莞�Ԍo�߂������H
	 *	@param[in]	�w�莞��
	 *	@return	�o�߂��Ă���Ȃ�� true
	 */
	bool isOverSec(float sec);
	/**
	 *	@brief	�w�莞�ԑҋ@
	 *	@param[in]	�w�莞��
	 */
	void WaitOverSec(float sec);
private:
	/**	�����o�[�ϐ�*/
	clock_t mOldTime;
	clock_t mNewTime;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/