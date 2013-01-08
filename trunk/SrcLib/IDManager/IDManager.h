/**===File Commentary=======================================*/
/**
 *	@file	IDManager.h
 *
 *	@brief	ID�Ǘ���
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
	 *	@brief	�R���X�g���N�^
	 *	@return	<�߂�l>
	 */
	IdManager();
	/**
	 *	@brief	���z�f�X�g���N�^
	 */
	virtual ~IdManager(){};
	/**
	 *	@brief	ID�擾
	 *	@return	ID
	 */
	unsigned int getID();
	/**
	 *	@brief	ID������
	 */
	void ResetID();
	/**
	 *	@brief	ID�ԋp
	 *	@param[in]	�ԋp����ID
	 */
	void unUseID(unsigned int elm);
		/**
	 *	@brief	ID�X�V
	 */
	void nextID();
private:
	/**	�����o�[�ϐ�*/
	unsigned int mUsed;
	std::list<unsigned int> mReleseID;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/