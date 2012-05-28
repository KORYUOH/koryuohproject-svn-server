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
#include	<list>
#include	<GameLogic/Interface/IGameSystem.h>
#include	<GameApplication/GameApplication.h>
#include	<Define/ClassDefine.h>
/**===Class Definition=====================================*/
class GameRunner:public IGameSystem,public GameApplication{
public:
	/**
	 *	@brief	コンストラクタ
	 *	@author	KORYUOH
	 */
	GameRunner(int argc,char* argv[]);
	/**
	 *	@brief	仮想デストラクタ
	 *	@author	KORYUOH
	 */
	virtual ~GameRunner(){};
	/**
	 *	@brief	後ろ追加
	 *	@param[in]	GameSystem_ptr_t;
	 *	@author	KORYUOH
	 */
	void push_back(GameSystem_ptr_t& ptr);
	/**
	 *	@brief	押し込む
	 *	@param[in]	GameSystem_ptr_t;
	 *	@param[in]	position;
	 *	@author	KORYUOH
	 */
	void insert(GameSystem_ptr_t& ptr,unsigned int num);


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
	std::list<GameSystem_ptr_t> m_system;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/