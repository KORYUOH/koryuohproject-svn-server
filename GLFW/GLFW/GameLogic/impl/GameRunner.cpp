/**===File Commentary=======================================*/
/**
 *	@file	GameRunner.cpp
 *
 *	@brief	ゲーム実行基礎クラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/22
 */
/**===File Include=========================================*/
#include	<GameLogic/impl/GameRunner.h>
/**===Class Implementation=================================*/
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	ゲームシステムポインタ
 *	@note	IGameSystemを継承したもの
 *	@author	KORYUOH
 */
/**========================================================*/
GameRunner::GameRunner(int argc,char* argv[]):GameApplication(argc,argv),mSManager(){
}
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	ゲームシステムポインタ
 *	@note	IGameSystemを継承したもの
 *	@author	KORYUOH
 */
/**========================================================*/
GameRunner::GameRunner(int argc,char* argv[],SceneBase* scene):GameApplication(argc,argv),mSManager(scene){
}
/**========================================================*/
/**
 *	@brief	初期化
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::initialize(){
	mSManager.initialize();
}
/**========================================================*/
/**
 *	@brief	メイン処理
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::update(float f){
	mSManager.update(f);
}
/**========================================================*/
/**
 *	@brief	描画処理
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::draw(){
	mSManager.draw();
}
/**========================================================*/
/**
 *	@brief	終了処理
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::finish(){
	mSManager.finish();
}
/**===End Of File==========================================*/