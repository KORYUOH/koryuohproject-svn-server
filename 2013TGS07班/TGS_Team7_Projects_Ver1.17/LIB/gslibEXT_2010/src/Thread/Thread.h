#ifndef _THREAD_H_
#define _THREAD_H_

#include "IRunnable.h"

/**
 * スレッドクラス．
 */
class Thread : public IRunnable
{
public:

	/**
	 * コンストラクタ．
	 *
	 * @param runnable スレッドコールバックインターフェース．
	 */
	Thread( IRunnable* runnable=0 );

	/**
	 * デストトラクタ．
	 */
	virtual ~Thread();

	/**
	 * スレッドの開始．
	 */
	virtual void start();

	/**
	 * スレッドの開始．
	 *
	 * @param runnable スレッドコールバックインターフェース．
	 */
	virtual void start( IRunnable* runnable );

	/**
	 * スレッドの終了を待つ．
	 */
	void join();

	/**
	 * スリープする．
	 *
	 * @param millsecond スリープする時間．（ミリ秒単位）
	 */
	static void sleep( unsigned int millsecond );

	/**
	 * 他のスレッドに制御を渡す
	 */
	static void yield();

	/**
	 * スレッドの実行．
	 */
	virtual void run();

private:

	/**
	 * コールバック関数．
	 */
	static void callback( void* arglist );

private:

    /** スレッドのハンドル */
    void*       mHandle;

    /** 実行するスレッド */
    IRunnable*  mRunnable;
};

#endif
