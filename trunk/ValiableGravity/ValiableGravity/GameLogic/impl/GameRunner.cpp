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
#include	<algorithm>
/**===Class Implementation=================================*/
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	ゲームシステムポインタ
 *	@note	IGameSystemを継承したもの
 *	@author	KORYUOH
 */
/**========================================================*/
GameRunner::GameRunner(GameSystem_ptr_t& ptr){
	m_system.push_back(ptr);
}
/**========================================================*/
/**
 *	@brief	初期化
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::initialize(){
	std::for_each(m_system.begin(),m_system.end(),[&](GameSystem_ptr_t &p){p->initialize();});
}
/**========================================================*/
/**
 *	@brief	メイン処理
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::update(float f){
	std::for_each(m_system.begin(),m_system.end(),[&](GameSystem_ptr_t &p){p->update(f);});
}
/**========================================================*/
/**
 *	@brief	描画処理
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::draw(){
	std::for_each(m_system.begin(),m_system.end(),[&](GameSystem_ptr_t &p){p->draw();});
}
/**========================================================*/
/**
 *	@brief	終了処理
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::finish(){
	std::for_each(m_system.begin(),m_system.end(),[&](GameSystem_ptr_t &p){p->finish();});
}
/**========================================================*/
/**
 *	@brief	後ろ追加
 *	@param[in]	ゲームロジックptr
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::push_back(GameSystem_ptr_t& ptr){
	m_system.push_back(ptr);
}

/**===End Of File==========================================*/