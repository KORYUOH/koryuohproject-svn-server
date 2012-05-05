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
#include	<list>
#include	<GameLogic/Interface/IGameSystem.h>
#include	<GameApplication/GameApplication.h>
#include	<Define/ClassDefine.h>
/**===Class Definition=====================================*/
class GameRunner:public IGameSystem,public GameApplication{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@author	KORYUOH
	 */
	GameRunner(int argc,char* argv[]);
	/**
	 *	@brief	���z�f�X�g���N�^
	 *	@author	KORYUOH
	 */
	virtual ~GameRunner(){};
	/**
	 *	@brief	���ǉ�
	 *	@param[in]	GameSystem_ptr_t;
	 *	@author	KORYUOH
	 */
	void push_back(GameSystem_ptr_t& ptr);
	/**
	 *	@brief	��������
	 *	@param[in]	GameSystem_ptr_t;
	 *	@param[in]	position;
	 *	@author	KORYUOH
	 */
	void insert(GameSystem_ptr_t& ptr,unsigned int num);


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
	std::list<GameSystem_ptr_t> m_system;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/