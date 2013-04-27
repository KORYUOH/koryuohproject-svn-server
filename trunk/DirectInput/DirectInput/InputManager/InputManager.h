/**===File Commentary=======================================*/
/**
 *	@file	InputManager.h
 *
 *	@brief	���̓}�l�[�W��
 *
 *	@author	KORYUOH
 *
 *	@date	2013/04/27
 */
/**===Include Guard========================================*/
#ifndef	_INPUTMANAGER_H_
#define	_INPUTMANAGER_H_
/**===File Include=========================================*/
// Use DInput version 8
#define		DIRECTINPUT_VERSION 0x0800
#include	<dinput.h>
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")
/**===Class Definition=====================================*/
class InputManager{
public:
	/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	KORYUOH
	 *	@return	<�߂�l>
	 */
	explicit InputManager();
private:

private:
	/**	�����o�[�ϐ�*/
	LPDIRECTINPUT pInput;
	LPDIRECTINPUTDEVICE pDIinputDevice;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/