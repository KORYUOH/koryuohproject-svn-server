/**===File Commentary=======================================*/
/**
 *	@file	IDManager.cpp
 *
 *	@brief	ID�Ǘ���
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
 *	@brief	�R���X�g���N�^
 */
/**========================================================*/
IdManager::IdManager()
	:mUsed(0)
	,mReleseID()
{}
/**========================================================*/
/**
 *	@brief	ID�擾
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
 *	@brief	ID�X�V
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
 *	@brief	ID�ԋp
 *	@param[in]	�ԋp����ID
 */
/**========================================================*/
void IdManager::unUseID(unsigned int elm){
	mReleseID.push_back(elm);
	mReleseID.sort();
	mReleseID.unique();
}
/**========================================================*/
/**
 *	@brief	������
 */
/**========================================================*/
void IdManager::ResetID(){
	mUsed = 0;
	mReleseID.clear();
}
/**===End Of File==========================================*/