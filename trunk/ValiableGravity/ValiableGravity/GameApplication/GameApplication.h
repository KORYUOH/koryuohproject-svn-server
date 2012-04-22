/**===File Commentary=======================================*/
/**
 *	@file	GameApplication.h
 *
 *	@brief	�Q�[���A�v���P�[�V����
 *
 *	@note	OpenGL
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/23
 */
/**===Include Guard========================================*/
#ifndef	_GAMEAPPLICATION_H_
#define	_GAMEAPPLICATION_H_
/**===File Include=========================================*/
#include	<string>
/**===Class Definition=====================================*/
class GameApplication{
public:
	/**
	 *	@brief	���s
	 *	@author	KORYUOH
	 */
	void run();

protected:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�����̐�
	 *	@param[in]	�R�}���h���C���I�v�V����
	 *	@author	KORYUOH
	 */
	GameApplication(int argc,char* argv[]);
	/**
	 *	@brief	���z�f�X�g���N�^
	 *	@author	KORYUOH
	 */
	virtual ~GameApplication(){};
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