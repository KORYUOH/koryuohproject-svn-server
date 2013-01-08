/**===File Commentary=======================================*/
/**
 *	@file	IDManager.h
 *
 *	@brief	ID管理者
 *
 *	@author	KORYUOH
 *
 *	@date	2012/11/06
 */
/**===Include Guard========================================*/
#ifndef	_IDMANAGER_H_
#define	_IDMANAGER_H_
/**===File Include=========================================*/
#include	<list>
/**===Class Definition=====================================*/
class IdManager{
public:
	/**
	 *	@brief	コンストラクタ
	 *	@return	<戻り値>
	 */
	IdManager();
	/**
	 *	@brief	仮想デストラクタ
	 */
	virtual ~IdManager(){};
	/**
	 *	@brief	ID取得
	 *	@return	ID
	 */
	unsigned int getID();
	/**
	 *	@brief	ID初期化
	 */
	void ResetID();
	/**
	 *	@brief	ID返却
	 *	@param[in]	返却するID
	 */
	void unUseID(unsigned int elm);
		/**
	 *	@brief	ID更新
	 */
	void nextID();
private:
	/**	メンバー変数*/
	unsigned int mUsed;
	std::list<unsigned int> mReleseID;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/