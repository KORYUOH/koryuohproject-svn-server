/**===File Commentary=======================================*/
/**
 *	@file	CriticalSection.cpp
 *
 *	@brief	�N���e�B�J���Z�N�V�����N���X
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
 *	@brief	�R���X�g���N�^
 */
/**========================================================*/
CriticalSection::CriticalSection(){
	::InitializeCriticalSection(&mCriticalSection);
}
/**========================================================*/
/**
 *	@brief	�f�X�g���N�^
 */
/**========================================================*/
CriticalSection::~CriticalSection(){
	::DeleteCriticalSection(&mCriticalSection);
}
/**========================================================*/
/**
 *	@brief	�N���e�B�J���Z�N�V�����J�n
 */
/**========================================================*/
void CriticalSection::enter(){
	::EnterCriticalSection(&mCriticalSection);
}
/**========================================================*/
/**
 *	@brief	�N���e�B�J���Z�N�V�����I��
 */
/**========================================================*/
void CriticalSection::leave(){
	::LeaveCriticalSection(&mCriticalSection);
}

/**========================================================*/
/**
 *	@brief	���b�N�R���X�g���N�^
 *	@param[in]	�N���e�B�J���Z�N�V����
 */
/**========================================================*/
CriticalSection::Lock::Lock(CriticalSection& cs)
	:mCriticalSection(cs){
		mCriticalSection.enter();
}
/**========================================================*/
/**
 *	@brief	�f�X�g���N�^
 */
/**========================================================*/
CriticalSection::Lock::~Lock(){
	mCriticalSection.leave();
}


/**===End Of File==========================================*/