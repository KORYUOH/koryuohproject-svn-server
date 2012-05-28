/**===File Commentary=======================================*/
/**
 *	@file	Thread.h
 *
 *	@brief	�X���b�h�N���X
 *
 *	@author	<��Җ�>
 *
 *	@date	2012/05/22
 */
/**===Include Guard========================================*/
#ifndef	_THREAD_H_
#define	_THREAD_H_
/**===File Include=========================================*/
#include	<Thread/IRunnable.h>
/**===Class Definition=====================================*/
class Thread:public IRunnable{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�����i�u���|�C���^
	 */
	Thread (IRunnable * runnable = 0);
	/**
	 *	@brief	�f�X�g���N�^
	 */
	virtual ~Thread();
	/**
	 *	@brief	�J�n
	 */
	virtual void start();
	/**
	 *	@brief	�J�n
	 *	@param[in]	���s
	 */
	virtual void start(IRunnable* runnable);
	/**
	 *	@brief	�X���b�h�I���ҋ@
	 */
	void join();
	/**
	 *	@brief	�X���[�v
	 *	@param[in]	ms
	 */
	static void sleep(unsigned int millsecond);
	/**
	 *	@brief	���s
	 */
	virtual void run();
private:
	/**
	 *	@brief	�R�[���o�b�N�֐�
	 *	@param[in]	���s�n���h��
	 */
	static void callback(void* runnable);

private:
	/**	�����o�[�ϐ�*/
	void* mHandle;
	IRunnable* mRunnable;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/