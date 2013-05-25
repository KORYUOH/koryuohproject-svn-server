#include "Thread.h"
#include <windows.h>
#include <process.h>

/**
 * �R���X�g���N�^�D
 *
 * @param runnable �X���b�h�R�[���o�b�N�C���^�[�t�F�[�X�D
 */
Thread::Thread( IRunnable* runnable ) :
	mHandle(0),
	mRunnable( runnable )
{
	if ( mRunnable == 0 ) {
		mRunnable = this;
	}
}

/**
 * �f�X�g�g���N�^�D
 */
Thread::~Thread()
{
}

/**
 * �X���b�h�̊J�n
 */
void Thread::start()
{
	// �X���b�h���J�n
    mHandle = reinterpret_cast<void*>(::_beginthread( callback, 0, this ));
}

/**
 * �X���b�h�̊J�n�D
 *
 * @param runnable �X���b�h�R�[���o�b�N�C���^�[�t�F�[�X�D
 */
void Thread::start( IRunnable* runnable )
{
	mRunnable = runnable;

	start();
}

/**
 * �X���b�h�̏I����҂D
 */
void Thread::join()
{
	if ( mHandle != 0 ) {
		::WaitForSingleObject( mHandle, INFINITE ); 
	}
}

/**
 * �X���[�v����
 *
 * @param millsecond �X���[�v���鎞�ԁD�i�~���b�P�ʁj
 */
void Thread::sleep( unsigned int millsecond )
{
	::Sleep( millsecond );
}

/**
 * ���̃X���b�h�ɐ����n��
 */
void Thread::yield()
{
	::Sleep(0);
}

/**
 * �X���b�h�̎��s�D
 */
void Thread::run()
{
}

/**
 * �R�[���o�b�N�֐��D
 *
 * @param arglist �X���b�h�N���X�̃|�C���^�D
 */
void Thread::callback( void* runnable )
{
    Thread* thread = reinterpret_cast<Thread*>(runnable);

    // �X���b�h�̏��������s����
    thread->mRunnable->run();

    // �X���b�h�n���h��������������
    thread->mHandle = 0;
}
