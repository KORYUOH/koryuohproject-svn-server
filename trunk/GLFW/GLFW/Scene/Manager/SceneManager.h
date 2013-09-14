/**===File Commentary=======================================*/
/**
 *	@file	SceneManager.h
 *
 *	@brief	�V�[���Ǘ���
 *
 *	@author	KORYUOH
 *
 *	@date	2013/09/14
 */
/**===Include Guard========================================*/
#ifndef	_SCENEMANAGER_H_
#define	_SCENEMANAGER_H_
/**===File Include=========================================*/
#include	<Scene/IMediator/ISceneMediator.h>
#include	<Scene/Base/SceneBase.h>
#include	<memory>
/**===Class Definition=====================================*/
class SceneManager:public ISceneMediator{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	[�V�[��]
	 */
	SceneManager();
	SceneManager(SceneBase* scene);
	SceneManager(std::shared_ptr<SceneBase> scene);
	/**
	 *	@brief	������
	 */
	void initialize();
	/**
	 *	@brief	�X�V
	 *	@param[in]	�t���[���^�C��
	 */
	void update(float f);
	/**
	 *	@brief	�`��
	 */
	void draw();
	/**
	 *	@brief	�I��
	 */
	void finish();
	/**
	 *	@brief	�V�[���ύX
	 *	@param[in]	�V�[��
	 */
	virtual void SceneChange(SceneBase* scene);
	/**
	 *	@brief	�V�[���ύX
	 *	@param[in]	�V�[��
	 */
	virtual void SceneChange(std::shared_ptr<SceneBase> scene);
private:
	/**	�����o�[�ϐ�*/
	std::shared_ptr<SceneBase> mFirstScene;
	std::shared_ptr<SceneBase> mNextScene;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/