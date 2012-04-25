/**===File Commentary=======================================*/
/**
 *	@file	Device.h
 *
 *	@brief	デバイスインターフェース
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
	 *	@brief	コンストラクタ
	 *	@author	KORYUOH
	 */
	Device():mouse(Mouse::getInstance()),pad(Pad::getInstance()){};
	/**
	 *	@brief	マウス
	 *	@author	KORYUOH
	 */
	const Mouse& getMouse()const;
	/**
	 *	@brief	パッド
	 *	@author	KORYUOH
	 */
	const Pad& getPad()const;

private:
	/**	メンバー変数*/
	Mouse&	mouse;
	Pad&	pad;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/