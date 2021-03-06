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
//x#include	<algorithm>
#include	<Utility/Utility.h>
/**===Class Implementation=================================*/
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	ゲームシステムポインタ
 *	@note	IGameSystemを継承したもの
 *	@author	KORYUOH
 */
/**========================================================*/
GameRunner::GameRunner(int argc,char* argv[]):GameApplication(argc,argv){
}
/**========================================================*/
/**
 *	@brief	初期化
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::initialize(){
	//xstd::for_each(m_system.begin(),m_system.end(),[&](GameSystem_ptr_t &p){p->initialize();});
	KORYUOH::for_each(m_system,[&](GameSystem_ptr_t &p){p->initialize();});
}
/**========================================================*/
/**
 *	@brief	メイン処理
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::update(float f){
	//xstd::for_each(m_system.begin(),m_system.end(),[&](GameSystem_ptr_t &p){p->update(f);});
	KORYUOH::for_each(m_system,[&](GameSystem_ptr_t &p){p->update(f);});
}
/**========================================================*/
/**
 *	@brief	描画処理
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::draw(){
	//xstd::for_each(m_system.begin(),m_system.end(),[&](GameSystem_ptr_t &p){p->draw();});
	KORYUOH::for_each(m_system,[&](GameSystem_ptr_t &p){p->draw();});
}
/**========================================================*/
/**
 *	@brief	終了処理
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::finish(){
	//xstd::for_each(m_system.begin(),m_system.end(),[&](GameSystem_ptr_t &p){p->finish();});
	KORYUOH::for_each(m_system,[&](GameSystem_ptr_t &p){p->finish();});
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
/**========================================================*/
/**
 *	@brief	場所追加
 *	@param[in]	ゲームロジックptr
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::insert(GameSystem_ptr_t& ptr,unsigned int pos){
	if(m_system.size()<pos){
		m_system.push_back(ptr);
		return ;
	}
	if(pos == 0){
		m_system.push_front(ptr);
		return;
	}
	auto x = m_system.begin();
	for(unsigned int i=0;i<pos;i++)
		x++;

	m_system.insert(x,ptr);
}
/**===End Of File==========================================*/