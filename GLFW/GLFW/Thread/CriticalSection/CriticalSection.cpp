/**===File Commentary=======================================*/
/**
 *	@file	CriticalSection.cpp
 *
 *	@brief	クリティカルセクションクラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/22
 */
/**===File Include=========================================*/
#include	<Thread/CriticalSection/CriticalSection.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	コンストラクタ
 */
/**========================================================*/
CriticalSection::CriticalSection(){
	::InitializeCriticalSection(&mCriticalSection);
}
/**========================================================*/
/**
 *	@brief	デストラクタ
 */
/**========================================================*/
CriticalSection::~CriticalSection(){
	::DeleteCriticalSection(&mCriticalSection);
}
/**========================================================*/
/**
 *	@brief	クリティカルセクション開始
 */
/**========================================================*/
void CriticalSection::enter(){
	::EnterCriticalSection(&mCriticalSection);
}
/**========================================================*/
/**
 *	@brief	クリティカルセクション終了
 */
/**========================================================*/
void CriticalSection::leave(){
	::LeaveCriticalSection(&mCriticalSection);
}

/**========================================================*/
/**
 *	@brief	ロックコンストラクタ
 *	@param[in]	クリティカルセクション
 */
/**========================================================*/
CriticalSection::Lock::Lock(CriticalSection& cs)
	:mCriticalSection(cs){
		mCriticalSection.enter();
}
/**========================================================*/
/**
 *	@brief	デストラクタ
 */
/**========================================================*/
CriticalSection::Lock::~Lock(){
	mCriticalSection.leave();
}


/**===End Of File==========================================*/