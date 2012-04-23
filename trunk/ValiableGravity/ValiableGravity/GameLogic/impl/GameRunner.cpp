/**===File Commentary=======================================*/
/**
 *	@file	GameRunner.cpp
 *
 *	@brief	�Q�[�����s��b�N���X
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
 *	@brief	�R���X�g���N�^
 *	@param[in]	�Q�[���V�X�e���|�C���^
 *	@note	IGameSystem���p����������
 *	@author	KORYUOH
 */
/**========================================================*/
GameRunner::GameRunner(GameSystem_ptr_t& ptr){
	m_system.push_back(ptr);
}
/**========================================================*/
/**
 *	@brief	������
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::initialize(){
	std::for_each(m_system.begin(),m_system.end(),[&](GameSystem_ptr_t &p){p->initialize();});
}
/**========================================================*/
/**
 *	@brief	���C������
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::update(float f){
	std::for_each(m_system.begin(),m_system.end(),[&](GameSystem_ptr_t &p){p->update(f);});
}
/**========================================================*/
/**
 *	@brief	�`�揈��
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::draw(){
	std::for_each(m_system.begin(),m_system.end(),[&](GameSystem_ptr_t &p){p->draw();});
}
/**========================================================*/
/**
 *	@brief	�I������
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::finish(){
	std::for_each(m_system.begin(),m_system.end(),[&](GameSystem_ptr_t &p){p->finish();});
}
/**========================================================*/
/**
 *	@brief	���ǉ�
 *	@param[in]	�Q�[�����W�b�Nptr
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::push_back(GameSystem_ptr_t& ptr){
	m_system.push_back(ptr);
}

/**===End Of File==========================================*/