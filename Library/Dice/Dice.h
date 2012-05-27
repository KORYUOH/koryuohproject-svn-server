/**===File Commentary=======================================*/
/**
 *	@file	Dice.h
 *
 *	@brief	�T�C�R���N���X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/18
 */
/**===Include Guard========================================*/
#ifndef	_DICE_H_
#define	_DICE_H_
/**===File Include=========================================*/

/**===Class Definition=====================================*/
class Dice{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 */
	Dice();
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	��
	 */
	Dice(unsigned int seed);	
	/**
	 *	@brief	6�ʃ_�C�X��U��
	 *	@return	�o��
	 */
	int Six();
	/**
	 *	@brief	�R�C���g�X����
	 *	@return	��
	 */
	bool coin();
	/**
	 *	@brief	nDn�T�C�R����U��
	 *	@param[in]	��
	 *	@param[in]	��
	 *	@param[in]	�ŏ��ǉ��l
	 *	@param[in]	�\���t���O
	 *	@return	���v�l
	 */
	int XdY_S(int x,int y,int s,bool dispFlag);
	/**
	 *	@brief	nDn�T�C�R����U��
	 *	@param[in]	��
	 *	@param[in]	��
	 *	@param[in]	�ŏ��ǉ��l
	 *	@param[in]	�\���t���O
	 *	@return	���v�l
	 */
	int XdY_S(int x,int y,int s=0);
	/**
	 *	@brief	�����_���Ȓl���擾
	 *	@param[in]	�ŏ��l
	 *	@param[in]	�ő�l
	 *	@return	�����_���l
	 */
	int getRandom(int min,int max);
	/**
	 *	@brief	��̎擾
	 *	@return	��
	 */
	unsigned int getSeed()const;
private:
	/**	�����o�[�ϐ�*/
	unsigned int mSeed;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/