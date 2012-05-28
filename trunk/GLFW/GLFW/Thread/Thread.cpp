/**===File Commentary=======================================*/
/**
 *	@file	Thread.cpp
 *
 *	@brief	�X���b�h�N���X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/22
 */
/**===File Include=========================================*/
#include	<Windows.h>
#include	<process.h>
#include	<Thread/Thread.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�����i�u���C���^�[�t�F�[�X
 */
/**========================================================*/
Thread::Thread( IRunnable* runnable)
	:mHandle(0)
	,mRunnable(runnable){
		if( mRunnable == 0)
			mRunnable = this;
}
/**========================================================*/
/**
 *	@brief	�f�X�g���N�^
 */
/**========================================================*/
Thread::~Thread(){
	
}
/**========================================================*/
/**
 *	@brief	�X���b�h�J�n
 */
/**========================================================*/
void Thread::start(){
	mHandle = reinterpret_cast<void*>(::_beginthread(callback,0,this));
}
/**========================================================*/
/**
 *	@brief	�X���b�h�J�n
 *	@param[in]	�����i�u��
 */
/**========================================================*/
void Thread::start(IRunnable* runnable){
	mRunnable = runnable;

	start();
}
/**========================================================*/
/**
 *	@brief	�I���ҋ@
 */
/**========================================================*/
void Thread::join(){
	if( mHandle != 0)
		::WaitForSingleObject(mHandle ,INFINITE);
}
/**========================================================*/
/**
 *	@brief	�X���[�v
 *	@param[in]	�ҋ@�b��
 */
/**========================================================*/
void Thread::sleep(unsigned int millsecond){
	::Sleep(millsecond);
}
/**========================================================*/
/**
 *	@brief	���s
 */
/**========================================================*/
void Thread::run(){

}
/**========================================================*/
/**
 *	@brief	�R�[���o�b�N�֐�
 *	@param[in]	�����i�u��
 */
/**========================================================*/
void Thread::callback(void* runnable){
	Thread* thread = reinterpret_cast<Thread*>(runnable);

	//�������s
	thread ->mRunnable->run();

	//�n���h��������
	thread ->mHandle =0;
}


/**===End Of File==========================================*/