#ifndef _THREAD_H_
#define _THREAD_H_

#include "IRunnable.h"

/**
 * �X���b�h�N���X�D
 */
class Thread : public IRunnable
{
public:

	/**
	 * �R���X�g���N�^�D
	 *
	 * @param runnable �X���b�h�R�[���o�b�N�C���^�[�t�F�[�X�D
	 */
	Thread( IRunnable* runnable=0 );

	/**
	 * �f�X�g�g���N�^�D
	 */
	virtual ~Thread();

	/**
	 * �X���b�h�̊J�n�D
	 */
	virtual void start();

	/**
	 * �X���b�h�̊J�n�D
	 *
	 * @param runnable �X���b�h�R�[���o�b�N�C���^�[�t�F�[�X�D
	 */
	virtual void start( IRunnable* runnable );

	/**
	 * �X���b�h�̏I����҂D
	 */
	void join();

	/**
	 * �X���[�v����D
	 *
	 * @param millsecond �X���[�v���鎞�ԁD�i�~���b�P�ʁj
	 */
	static void sleep( unsigned int millsecond );

	/**
	 * ���̃X���b�h�ɐ����n��
	 */
	static void yield();

	/**
	 * �X���b�h�̎��s�D
	 */
	virtual void run();

private:

	/**
	 * �R�[���o�b�N�֐��D
	 */
	static void callback( void* arglist );

private:

    /** �X���b�h�̃n���h�� */
    void*       mHandle;

    /** ���s����X���b�h */
    IRunnable*  mRunnable;
};

#endif
