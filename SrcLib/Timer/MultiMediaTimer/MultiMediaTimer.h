/**===File Commentary=======================================*/
/**
 *	@file	MultiMediaTimer.h
 *
 *	@brief	�}���`���f�B�A�^�C�}�[
 *
 *	@note	Win�p
 *
 *	@author	KORYUOH
 *
 *	@date	2013/01/08
 */
/**===Include Guard========================================*/
#ifndef	_MULTIMEDIATIMER_H_
#define	_MULTIMEDIATIMER_H_
/**===File Include=========================================*/

/**===Class Definition=====================================*/
class MultiMediaTimer{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 */
	MultiMediaTimer();
	/**
	 *	@brief	���z�f�X�g���N�^
	 */
	virtual ~MultiMediaTimer(){};
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
	unsigned long getTimeMills()const;
	/**
	 *	@brief	�V�X�e���o�ߎ��Ԏ擾
	 *	@return	�V�X�e���N��������̌o�ߎ���
	 */
	unsigned long getSystemMills()const;
	/**
	 *	@brief	�w�莞�Ԍo�߂������H
	 *	@param[in]	�w�莞��
	 *	@return	�o�߂��Ă���ΐ^
	 */
	bool isOverMills(unsigned long ms)const;
private:
	/**	�����o�[�ϐ�*/
	unsigned long mOldTime;
	unsigned long mNewTime;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/