/**===File Commentary=======================================*/
/**
 *	@file	GameTest.h
 *
 *	@brief	�e�X�g�p�Q�[���w�b�_
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/30
 */
/**===Include Guard========================================*/
#ifndef	_GAMETEST_H_
#define	_GAMETEST_H_
/**===File Include=========================================*/
#include	<GameLogic/Interface/IGameSystem.h>
#include	<Device/Impl/Mouse.h>
#include	<memory>
/**===Class Definition=====================================*/
class GameTest:public IGameSystem{
public:
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
	GLMouse mMouse;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/