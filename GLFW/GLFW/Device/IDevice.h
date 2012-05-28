/**===File Commentary=======================================*/
/**
 *	@file	IDevice.h
 *
 *	@brief	デバイスインターフェース
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
	 *	@brief	更新
	 *	@author	KORYUOH
	 */
	virtual void update() = 0;
	/**
	 *	@brief	自身のインスタンスの取得
	 *	@author	KORYUOH
	 *	@return	自身
	 */
	virtual IDevice& getInstance() = 0; 
private:
	/**	メンバー変数*/

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/