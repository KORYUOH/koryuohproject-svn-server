/**===File Commentary=======================================*/
/**
 *	@file	GameMain.h
 *
 *	@brief	ゲームメインクラス
 *
 *	@author	<作者名>
 *
 *	@date	2012/05/01
 */
/**===Include Guard========================================*/
#ifndef	_GAMEMAIN_H_
#define	_GAMEMAIN_H_
/**===File Include=========================================*/
#include	<GameLogic/Interface/IGameSystem.h>
/**===Class Definition=====================================*/
class GameMain:public IGameSystem{
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
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/