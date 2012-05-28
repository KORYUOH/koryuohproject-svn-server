/**===File Commentary=======================================*/
/**
 *	@file	IRunnable.h
 *
 *	@brief	スレッド実行インターフェース
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/22
 */
/**===Include Guard========================================*/
#ifndef	_IRUNNABLE_H_
#define	_IRUNNABLE_H_
/**===File Include=========================================*/
/**===Class Definition=====================================*/
class IRunnable{
public:
	/**
	 *	@brief	デストラクタ
	 */
	virtual ~IRunnable(){};
	/**
	 *	@brief	実行
	 */
	virtual void run() = 0;
private:
	/**	メンバー変数*/

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/