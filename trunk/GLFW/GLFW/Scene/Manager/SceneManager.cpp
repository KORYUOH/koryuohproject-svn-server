/**===File Commentary=======================================*/
/**
 *	@file	SceneManager.cpp
 *
 *	@brief	�V�[���Ǘ���
 *
 *	@author	KORYUOH
 *
 *	@date	2013/09/14
 */
/**===File Include=========================================*/
#include	<Scene/Manager/SceneManager.h>
#include	<Scene/Base/SceneBase.h>
#include	<memory>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 */
/**========================================================*/
SceneManager::SceneManager()
	:mFirstScene(nullptr)
	,mNextScene(nullptr)
{}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�V�[��
 */
/**========================================================*/
SceneManager::SceneManager(SceneBase* scene)
	:mFirstScene(scene)
	,mNextScene(nullptr)
{}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�V�[��
 */
/**========================================================*/
SceneManager::SceneManager(std::shared_ptr<SceneBase> scene)
	:mFirstScene(scene)
	,mNextScene(nullptr)
{}
/**========================================================*/
/**
 *	@brief	������
 */
/**========================================================*/
void SceneManager::initialize(){
	if(mFirstScene == nullptr)
		return;
	mFirstScene->setMediator(*this);
	mFirstScene->initialize();
}
/**========================================================*/
/**
 *	@brief	�X�V
 *	@param[in]	�t���[��
 */
/**========================================================*/
void SceneManager::update(float f){
	if(mFirstScene == nullptr)
		return;
	if(mNextScene != nullptr){
		mFirstScene->finish();
		mFirstScene = mNextScene;
		mNextScene = nullptr;
		mFirstScene->initialize();
	}
	mFirstScene->update(f);
}
/**========================================================*/
/**
 *	@brief	�`��
 */
/**========================================================*/
void SceneManager::draw(){
	if(mFirstScene == nullptr)
		return;
	mFirstScene->draw();
}
/**========================================================*/
/**
 *	@brief	�I��
 */
/**========================================================*/
void SceneManager::finish(){
	if(mNextScene != nullptr)
		mNextScene = nullptr;
	if(mFirstScene != nullptr){
		mFirstScene->finish();
		mFirstScene = nullptr;
	}
}
/**========================================================*/
/**
 *	@brief	�V�[���ύX
 *	@param[in]	�V�[��
 */
/**========================================================*/
void SceneManager::SceneChange(SceneBase* scene){
	SceneChange(std::shared_ptr<SceneBase>(scene));
}
/**========================================================*/
/**
 *	@brief	�V�[���ύX
 *	@param[in]	�V�[��
 */
/**========================================================*/
void SceneManager::SceneChange(std::shared_ptr<SceneBase> scene){
	mNextScene = scene;
}

/**===End Of File==========================================*/