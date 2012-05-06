/**===File Commentary=======================================*/
/**
 *	@file	IGameSystem.h
 *
 *	@brief	ゲームシステムインターフェース
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/22
 */
/**===Include Guard========================================*/
#ifndef	_IGAMESYSTEM_H_
#define	_IGAMESYSTEM_H_
/**===File Include=========================================*/
/**===Class Definition=====================================*/
class IGameSystem{

public:
	/**
	 *	@brief	初期化
	 *	@author	KORYUOH
	 */
	virtual void initialize() = 0;
	/**
	 *	@brief	ゲームメイン
	 *	@author	KORYUOH
	 */
	virtual void update(float f) =0;
	/**
	 *	@brief	描画
	 *	@author	KORYUOH
	 */
	virtual void draw() = 0;
	/**
	 *	@brief	終了
	 *	@author	KORYUOH
	 */
	virtual void finish() =0;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/