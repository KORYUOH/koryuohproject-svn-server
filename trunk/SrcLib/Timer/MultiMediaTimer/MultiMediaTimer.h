/**===File Commentary=======================================*/
/**
 *	@file	MultiMediaTimer.h
 *
 *	@brief	マルチメディアタイマー
 *
 *	@note	Win用
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
	 *	@brief	コンストラクタ
	 */
	MultiMediaTimer();
	/**
	 *	@brief	仮想デストラクタ
	 */
	virtual ~MultiMediaTimer(){};
	/**
	 *	@brief	開始
	 */
	void start();
	/**
	 *	@brief	停止・更新
	 */
	void stop();
	/**
	 *	@brief	経過時間取得
	 *	@return	経過時間
	 */
	unsigned long getTimeMills()const;
	/**
	 *	@brief	システム経過時間取得
	 *	@return	システム起動時からの経過時間
	 */
	unsigned long getSystemMills()const;
	/**
	 *	@brief	指定時間経過したか？
	 *	@param[in]	指定時間
	 *	@return	経過していれば真
	 */
	bool isOverMills(unsigned long ms)const;
private:
	/**	メンバー変数*/
	unsigned long mOldTime;
	unsigned long mNewTime;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/