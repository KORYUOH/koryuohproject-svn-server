/**===File Commentary=======================================*/
/**
 *	@file	SceneBase.h
 *
 *	@brief	�V�[�����t�@�C��
 *
 *	@author	KORYUOH
 *
 *	@date	2013/09/14
 */
/**===Include Guard========================================*/
#ifndef	_SCENEBASE_H_
#define	_SCENEBASE_H_
/**===File Include=========================================*/
#include	<memory>
#include	<Scene/IMediator/ISceneMediator.h>
/**===Class Definition=====================================*/
class SceneBase{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 */
	SceneBase();
	/**
	 *	@brief	������
	 */
	void initialize();
	/**
	 *	@brief	�X�V
	 *	@param[in]	�t���[��
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
	void SceneChange(SceneBase* scene);
	/**
	 *	@brief	�V�[���ύX
	 *	@param[in]	�V�[��
	 */
	void SceneChange(std::shared_ptr<SceneBase> scene);
	/**
	 *	@brief	�ʒm�Ґݒ�
	 *	@param[in]	�ʒm��
	 */
	void setMediator(ISceneMediator& mediator);
	/**
	 *	@brief	���z�f�X�g���N�^
	 */
	virtual ~SceneBase(){}
private:
	/**	�����o�[�ϐ�*/
	ISceneMediator* mMediator;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/