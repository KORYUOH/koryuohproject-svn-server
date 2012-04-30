/**===File Commentary=======================================*/
/**
 *	@file	GameTest.h
 *
 *	@brief	テスト用ゲームヘッダ
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/30
 */
/**===Include Guard========================================*/
#ifndef	_GAMETEST_H_
#define	_GAMETEST_H_
/**===File Include=========================================*/
#include	<GameLogic/Interface/IGameSystem.h>
#include	<Device/Impl/Mouse.h>
#include	<memory>
/**===Class Definition=====================================*/
class GameTest:public IGameSystem{
public:
	/**
	 *	@brief	初期化
	 *	@author	KORYUOH
	 */
	virtual void initialize();
	/**
	 *	@brief	ゲームメイン
	 *	@author	KORYUOH
	 */
	virtual void update(float f);
	/**
	 *	@brief	描画
	 *	@author	KORYUOH
	 */
	virtual void draw();
	/**
	 *	@brief	終了
	 *	@author	KORYUOH
	 */
	virtual void finish();

private:
	/**	メンバー変数*/
	GLMouse mMouse;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/