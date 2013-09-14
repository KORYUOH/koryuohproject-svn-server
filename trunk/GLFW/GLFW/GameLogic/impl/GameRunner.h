/**===File Commentary=======================================*/
/**
 *	@file	GameRunner.h
 *
 *	@brief	ゲーム実行ヘッダーファイル
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/22
 */
/**===Include Guard========================================*/
#ifndef	_GAMERUNNER_H_
#define	_GAMERUNNER_H_
/**===File Include=========================================*/
#include	<GameApplication/GameApplication.h>
#include	<Define/ClassDefine.h>
#include	<Scene/Manager/SceneManager.h>
class SceneBase;
/**===Class Definition=====================================*/
class GameRunner:public GameApplication{
public:
	/**
	 *	@brief	コンストラクタ
	 *	@author	KORYUOH
	 */
	GameRunner(int argc,char* argv[]);
	/**
	 *	@brief	コンストラクタ
	 *	@author	KORYUOH
	 */
	GameRunner(int argc,char* argv[],SceneBase* scene);
	/**
	 *	@brief	仮想デストラクタ
	 *	@author	KORYUOH
	 */
	virtual ~GameRunner(){};
private:
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
	SceneManager mSManager;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/