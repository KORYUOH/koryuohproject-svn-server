/**===File Commentary=======================================*/
/**
 *	@file	SceneManager.cpp
 *
 *	@brief	シーン管理者
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
 *	@brief	コンストラクタ
 */
/**========================================================*/
SceneManager::SceneManager()
	:mFirstScene(nullptr)
	,mNextScene(nullptr)
{}
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	シーン
 */
/**========================================================*/
SceneManager::SceneManager(SceneBase* scene)
	:mFirstScene(scene)
	,mNextScene(nullptr)
{}
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	シーン
 */
/**========================================================*/
SceneManager::SceneManager(std::shared_ptr<SceneBase> scene)
	:mFirstScene(scene)
	,mNextScene(nullptr)
{}
/**========================================================*/
/**
 *	@brief	初期化
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
 *	@brief	更新
 *	@param[in]	フレーム
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
 *	@brief	描画
 */
/**========================================================*/
void SceneManager::draw(){
	if(mFirstScene == nullptr)
		return;
	mFirstScene->draw();
}
/**========================================================*/
/**
 *	@brief	終了
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
 *	@brief	シーン変更
 *	@param[in]	シーン
 */
/**========================================================*/
void SceneManager::SceneChange(SceneBase* scene){
	SceneChange(std::shared_ptr<SceneBase>(scene));
}
/**========================================================*/
/**
 *	@brief	シーン変更
 *	@param[in]	シーン
 */
/**========================================================*/
void SceneManager::SceneChange(std::shared_ptr<SceneBase> scene){
	mNextScene = scene;
}

/**===End Of File==========================================*/