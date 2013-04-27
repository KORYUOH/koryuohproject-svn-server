/**===File Commentary=======================================*/
/**
 *	@file	InputManager.h
 *
 *	@brief	入力マネージャ
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
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	KORYUOH
	 *	@return	<戻り値>
	 */
	explicit InputManager();
private:

private:
	/**	メンバー変数*/
	LPDIRECTINPUT pInput;
	LPDIRECTINPUTDEVICE pDIinputDevice;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/