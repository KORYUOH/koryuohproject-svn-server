/**===File Commentary=======================================*/
/**
 *	@file	GameRunner.h
 *
 *	@brief	�Q�[�����s�w�b�_�[�t�@�C��
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/22
 */
/**===Include Guard========================================*/
#ifndef	_GAMERUNNER_H_
#define	_GAMERUNNER_H_
/**===File Include=========================================*/
#include	<GameApplication/GameApplication.h>
#include	<Define/ClassDefine.h>
#include	<Scene/Manager/SceneManager.h>
class SceneBase;
/**===Class Definition=====================================*/
class GameRunner:public GameApplication{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@author	KORYUOH
	 */
	GameRunner(int argc,char* argv[]);
	/**
	 *	@brief	�R���X�g���N�^
	 *	@author	KORYUOH
	 */
	GameRunner(int argc,char* argv[],SceneBase* scene);
	/**
	 *	@brief	���z�f�X�g���N�^
	 *	@author	KORYUOH
	 */
	virtual ~GameRunner(){};
private:
	/**
	 *	@brief	������
	 *	@author	KORYUOH
	 */
	virtual void initialize();
	/**
	 *	@brief	�Q�[�����C��
	 *	@author	KORYUOH
	 */
	virtual void update(float f);
	/**
	 *	@brief	�`��
	 *	@author	KORYUOH
	 */
	virtual void draw();
	/**
	 *	@brief	�I��
	 *	@author	KORYUOH
	 */
	virtual void finish();

private:
	/**	�����o�[�ϐ�*/
	SceneManager mSManager;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/