/**===File Commentary=======================================*/
/**
 *	@file	Thread.h
 *
 *	@brief	スレッドクラス
 *
 *	@author	<作者名>
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
	 *	@brief	コンストラクタ
	 *	@param[in]	ランナブルポインタ
	 */
	Thread (IRunnable * runnable = 0);
	/**
	 *	@brief	デストラクタ
	 */
	virtual ~Thread();
	/**
	 *	@brief	開始
	 */
	virtual void start();
	/**
	 *	@brief	開始
	 *	@param[in]	実行
	 */
	virtual void start(IRunnable* runnable);
	/**
	 *	@brief	スレッド終了待機
	 */
	void join();
	/**
	 *	@brief	スリープ
	 *	@param[in]	ms
	 */
	static void sleep(unsigned int millsecond);
	/**
	 *	@brief	実行
	 */
	virtual void run();
private:
	/**
	 *	@brief	コールバック関数
	 *	@param[in]	実行ハンドル
	 */
	static void callback(void* runnable);

private:
	/**	メンバー変数*/
	void* mHandle;
	IRunnable* mRunnable;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/