/**===File Commentary=======================================*/
/**
 *	@file	GameMain.h
 *
 *	@brief	�Q�[�����C���N���X
 *
 *	@author	<��Җ�>
 *
 *	@date	2012/05/01
 */
/**===Include Guard========================================*/
#ifndef	_GAMEMAIN_H_
#define	_GAMEMAIN_H_
/**===File Include=========================================*/
#include	<GameLogic/Interface/IGameSystem.h>
/**===Class Definition=====================================*/
class GameMain:public IGameSystem{
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
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/