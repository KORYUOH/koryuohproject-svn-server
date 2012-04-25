/**===File Commentary=======================================*/
/**
 *	@file	Device.h
 *
 *	@brief	�f�o�C�X�C���^�[�t�F�[�X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/23
 */
/**===Include Guard========================================*/
#ifndef	_DEVICE_H_
#define	_DEVICE_H_
/**===File Include=========================================*/
#include	<Mouse/Mouce.h>
#include	<Pad/Pad.h>
/**===Class Definition=====================================*/
class Device{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@author	KORYUOH
	 */
	Device():mouse(Mouse::getInstance()),pad(Pad::getInstance()){};
	/**
	 *	@brief	�}�E�X
	 *	@author	KORYUOH
	 */
	const Mouse& getMouse()const;
	/**
	 *	@brief	�p�b�h
	 *	@author	KORYUOH
	 */
	const Pad& getPad()const;

private:
	/**	�����o�[�ϐ�*/
	Mouse&	mouse;
	Pad&	pad;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/