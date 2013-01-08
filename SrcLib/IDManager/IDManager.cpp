/**===File Commentary=======================================*/
/**
 *	@file	IDManager.cpp
 *
 *	@brief	ID管理者
 *
 *	@author	KORYUOH
 *
 *	@date	2012/11/06
 */
/**===File Include=========================================*/
#include	<Manager/IDManager/IDManager.h>
#include	<list>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	コンストラクタ
 */
/**========================================================*/
IdManager::IdManager()
	:mUsed(0)
	,mReleseID()
{}
/**========================================================*/
/**
 *	@brief	ID取得
 *	@return	ID
 */
/**========================================================*/
unsigned int IdManager::getID(){
	if(!mReleseID.empty()){
		mReleseID.sort();
		mReleseID.unique();

		if(mReleseID.front() <mUsed)
			return mReleseID.front();
	}
	return mUsed;
}
/**========================================================*/
/**
 *	@brief	ID更新
 */
/**========================================================*/
void IdManager::nextID(){
	if(!mReleseID.empty()){
		mReleseID.sort();
		mReleseID.unique();
		if(mReleseID.front() < mUsed){
			mReleseID.pop_front();
			return;
		}
	}
	
	mUsed++;
}
/**========================================================*/
/**
 *	@brief	ID返却
 *	@param[in]	返却するID
 */
/**========================================================*/
void IdManager::unUseID(unsigned int elm){
	mReleseID.push_back(elm);
	mReleseID.sort();
	mReleseID.unique();
}
/**========================================================*/
/**
 *	@brief	初期化
 */
/**========================================================*/
void IdManager::ResetID(){
	mUsed = 0;
	mReleseID.clear();
}
/**===End Of File==========================================*/