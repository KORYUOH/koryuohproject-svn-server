/**===File Commentary=======================================*/
/**
 *	@file	CriticalSection.h
 *
 *	@brief	�N���e�B�J���Z�N�V�����N���X
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
	 *	@brief	�R���X�g���N�^
	 */
	CriticalSection();
	/**
	 *	@brief	�f�X�g���N�^
	 */
	~CriticalSection();
	/**
	 *	@brief	�J�n
	 */
	void enter();
	/**
	 *	@brief	�I��
	 */
	void leave();
	
/**===Inner Class Definition===============================*/
	class Lock{
	public:
		/**
		 *	@brief	�R���X�g���N�^
		 */
		Lock(CriticalSection& cs);
		/**
		 *	@brief	�f�X�g���N�^
		 */
		~Lock();
	private:
		CriticalSection& mCriticalSection;
	};
/**===End Class Definition==================================*/
private:
	/**	�����o�[�ϐ�*/
	CRITICAL_SECTION mCriticalSection;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/