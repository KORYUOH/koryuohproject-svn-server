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
/**===Class Implementation=================================*/
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�Q�[���V�X�e���|�C���^
 *	@note	IGameSystem���p����������
 *	@author	KORYUOH
 */
/**========================================================*/
GameRunner::GameRunner(int argc,char* argv[]):GameApplication(argc,argv),mSManager(){
}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�Q�[���V�X�e���|�C���^
 *	@note	IGameSystem���p����������
 *	@author	KORYUOH
 */
/**========================================================*/
GameRunner::GameRunner(int argc,char* argv[],SceneBase* scene):GameApplication(argc,argv),mSManager(scene){
}
/**========================================================*/
/**
 *	@brief	������
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::initialize(){
	mSManager.initialize();
}
/**========================================================*/
/**
 *	@brief	���C������
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::update(float f){
	mSManager.update(f);
}
/**========================================================*/
/**
 *	@brief	�`�揈��
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::draw(){
	mSManager.draw();
}
/**========================================================*/
/**
 *	@brief	�I������
 *	@author	KORYUOH
 */
/**========================================================*/
void GameRunner::finish(){
	mSManager.finish();
}
/**===End Of File==========================================*/