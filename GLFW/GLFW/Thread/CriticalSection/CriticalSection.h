/**===File Commentary=======================================*/
/**
 *	@file	CriticalSection.h
 *
 *	@brief	クリティカルセクションクラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/22
 */
/**===Include Guard========================================*/
#ifndef	_CRITICALSECTION_H_
#define	_CRITICALSECTION_H_
/**===File Include=========================================*/
#include	<Windows.h>
/**===Class Definition=====================================*/
class CriticalSection{
public:
	/**
	 *	@brief	コンストラクタ
	 */
	CriticalSection();
	/**
	 *	@brief	デストラクタ
	 */
	~CriticalSection();
	/**
	 *	@brief	開始
	 */
	void enter();
	/**
	 *	@brief	終了
	 */
	void leave();
	
/**===Inner Class Definition===============================*/
	class Lock{
	public:
		/**
		 *	@brief	コンストラクタ
		 */
		Lock(CriticalSection& cs);
		/**
		 *	@brief	デストラクタ
		 */
		~Lock();
	private:
		CriticalSection& mCriticalSection;
	};
/**===End Class Definition==================================*/
private:
	/**	メンバー変数*/
	CRITICAL_SECTION mCriticalSection;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/