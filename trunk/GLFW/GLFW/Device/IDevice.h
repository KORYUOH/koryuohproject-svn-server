/**===File Commentary=======================================*/
/**
 *	@file	IDevice.h
 *
 *	@brief	�f�o�C�X�C���^�[�t�F�[�X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/30
 */
/**===Include Guard========================================*/
#ifndef	_IDEVICE_H_
#define	_IDEVICE_H_
/**===File Include=========================================*/
/**===Class Definition=====================================*/
class IDevice{
public:
	/**
	 *	@brief	�X�V
	 *	@author	KORYUOH
	 */
	virtual void update() = 0;
	/**
	 *	@brief	���g�̃C���X�^���X�̎擾
	 *	@author	KORYUOH
	 *	@return	���g
	 */
	virtual IDevice& getInstance() = 0; 
private:
	/**	�����o�[�ϐ�*/

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/