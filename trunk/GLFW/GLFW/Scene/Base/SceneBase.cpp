/**===File Commentary=======================================*/
/**
 *	@file	SceneBase.cpp
 *
 *	@brief	�V�[�����N���X
 *
 *	@author	KORYUOH
 *
 *	@date	2013/09/14
 */
/**===File Include=========================================*/
#include	<Scene/Base/SceneBase.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 */
/**========================================================*/
SceneBase::SceneBase():mMediator(nullptr)
{
}
/**========================================================*/
/**
 *	@brief	������
 */
/**========================================================*/
void SceneBase::initialize(){
}
/**========================================================*/
/**
 *	@brief	�X�V
 *	@param[in]	�t���[���^�C��
 */
/**========================================================*/
void SceneBase::update(float f){
}
/**========================================================*/
/**
 *	@brief	�`��
 */
/**========================================================*/
void SceneBase::draw(){
}
/**========================================================*/
/**
 *	@brief	�I��
 */
/**========================================================*/
void SceneBase::finish(){
}
/**========================================================*/
/**
 *	@brief	�V�[���ύX
 *	@param[in]	���̃V�[��
 */
/**========================================================*/
void SceneBase::SceneChange(SceneBase* scene){
	mMediator->SceneChange(scene);
}
/**========================================================*/
/**
 *	@brief	�V�[���ύX
 *	@param[in]	���̃V�[��
 */
/**========================================================*/
void SceneBase::SceneChange(std::shared_ptr<SceneBase> scene){
	mMediator->SceneChange(scene);
}
/**========================================================*/
/**
 *	@brief	�ʒm�Ґݒ�
 *	@param[in]	�ʒm��
 */
/**========================================================*/
void SceneBase::setMediator(ISceneMediator& mediator){
	mMediator = &mediator;
}


/**===End Of File==========================================*/