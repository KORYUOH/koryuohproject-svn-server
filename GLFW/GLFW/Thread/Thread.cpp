/**===File Commentary=======================================*/
/**
 *	@file	Thread.cpp
 *
 *	@brief	スレッドクラス
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
 *	@brief	コンストラクタ
 *	@param[in]	ランナブルインターフェース
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
 *	@brief	デストラクタ
 */
/**========================================================*/
Thread::~Thread(){
	
}
/**========================================================*/
/**
 *	@brief	スレッド開始
 */
/**========================================================*/
void Thread::start(){
	mHandle = reinterpret_cast<void*>(::_beginthread(callback,0,this));
}
/**========================================================*/
/**
 *	@brief	スレッド開始
 *	@param[in]	ランナブル
 */
/**========================================================*/
void Thread::start(IRunnable* runnable){
	mRunnable = runnable;

	start();
}
/**========================================================*/
/**
 *	@brief	終了待機
 */
/**========================================================*/
void Thread::join(){
	if( mHandle != 0)
		::WaitForSingleObject(mHandle ,INFINITE);
}
/**========================================================*/
/**
 *	@brief	スリープ
 *	@param[in]	待機秒数
 */
/**========================================================*/
void Thread::sleep(unsigned int millsecond){
	::Sleep(millsecond);
}
/**========================================================*/
/**
 *	@brief	実行
 */
/**========================================================*/
void Thread::run(){

}
/**========================================================*/
/**
 *	@brief	コールバック関数
 *	@param[in]	ランナブル
 */
/**========================================================*/
void Thread::callback(void* runnable){
	Thread* thread = reinterpret_cast<Thread*>(runnable);

	//処理実行
	thread ->mRunnable->run();

	//ハンドル無効化
	thread ->mHandle =0;
}


/**===End Of File==========================================*/