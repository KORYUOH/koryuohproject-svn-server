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
#include	<GameLogic/Interface/IGameSystem.h>
#include	<memory>
#include	<string>
/**===Class Definition=====================================*/
class GameApplication:public IGameSystem{
public:
	/**
	 *	@brief	���s
	 *	@author	KORYUOH
	 */
	void run();
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
protected:
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
	/**
	 *	@brief	�E�B���h�E�^�C�g���̎擾
	 *	@author	KORYUOH
	 *	@return	�E�B���h�E�^�C�g��
	 */
	const std::string& getWindowTitle()const;
	/**
	 *	@brief	X�ʒu�̎擾
	 *	@author	KORYUOH
	 *	@return	X�ʒu
	 */
	int getWindowPositionX()const;
	/**
	 *	@brief	Y�ʒu�̎擾
	 *	@author	KORYUOH
	 *	@return	Y�ʒu
	 */
	int getWindowPositionY()const;
	/**
	 *	@brief	���̎擾
	 *	@author	KORYUOH
	 *	@return	��
	 */
	int getWindowWidth()const;
	/**
	 *	@brief	�����擾
	 *	@author	KORYUOH
	 *	@return	����
	 */
	int getWindowHeight()const;
	/**
	 *	@brief	Fov�̒l�̎擾
	 *	@author	KORYUOH
	 *	@return	Fov�̒l
	 */
	float getPerspectiveFov()const;
	/**
	 *	@brief	Near�̒l�̎擾
	 *	@author	KORYUOH
	 *	@return	Near�̒l
	 */
	float getPerspectiveNear()const;
	/**
	 *	@brief	Far�̒l�̎擾
	 *	@author	KORYUOH
	 *	@return	Far�̒l
	 */
	float getPerspectiveFar()const;
	/**
	 *	@brief	�E�B���h�E�^�C�g���̐ݒ�
	 *	@param[in]	�E�B���h�E�^�C�g��
	 *	@author	KORYUOH
	 */
	void setWindowTitle(std::string& title);
	/**
	 *	@brief	�E�B���h�E�ʒu�̐ݒ�
	 *	@param[in]	X�ʒu
	 *	@author	KORYUOH
	 */
	void setWindowPositionX(int x);
	/**
	 *	@brief	�E�B���h�E�ʒu�̐ݒ�
	 *	@param[in]	Y�ʒu
	 *	@author	KORYUOH
	 */
	void setWindowPositionY(int y);
	/**
	 *	@brief	���̐ݒ�
	 *	@param[in]	��
	 *	@author	KORYUOH
	 */
	void setWindowWidth(int width);
	/**
	 *	@brief	�����̐ݒ�
	 *	@param[in]	����
	 *	@author	KORYUOH
	 */
	void setWindowHeight(int height);
	/**
	 *	@brief	Fov�̐ݒ�
	 *	@param[in]	Fov
	 *	@author	KORYUOH
	 */
	void setPerspectiveFov(float fov);
	/**
	 *	@brief	Near�̐ݒ�
	 *	@param[in]	Near
	 *	@author	KORYUOH
	 */
	void setPerspectiveNear(float near);
	/**
	 *	@brief	Far�̐ݒ�
	 *	@param[in]	Far
	 *	@author	KORYUOH
	 */
	void setPerspectiveFar(float far);
	/**
	 *	@brief	�t���X�N���[�����[�h
	 *	@param[in]	�t���O
	 *	@note	True:FullScreen
	 *	@author	KORYUOH
	 */
	void setFullScreenMode(bool mode);
	/**
	 *	@brief	�t���X�N���[�����[�h���H
	 *	@author	KORYUOH
	 *	@return	�t���O
	 */
	bool isFullScreenMode()const;
private:
	/**
	 *	@brief	OpenGL������
	 *	@author	KORYUOH
	 */
	void initializeGL( void );
	/**
	 *	@brief	�C���^�[�o���ݒ�
	 *	@param[in]	�C���^�[�o��
	 *	@author	KORYUOH
	 */
	void setSwapInterval(int interval);

	/**
	 *	@brief	�A�N�e�B�x�[�g
	 *	@param[in]	���
	 *	@author	KORYUOH
	 */
	static void activate(int state);
	/**
	 *	@brief	�f�B�X�v���C
	 *	@author	KORYUOH
	 */
	static void display(void);
	/**
	 *	@brief	�A�C�h��
	 *	@author	KORYUOH
	 */
	static void idle(void);
	/**
	 *	@brief	���V���[�v
	 *	@author	KORYUOH
	 */
	static void reshape(int width,int height);
	/**
	 *	@brief	�f�X�g���C
	 *	@author	KORYUOH
	 */
	static void destroy(void);
private:
	/**	�����o�[�ϐ�*/
	std::string	mWindowTitle;
	int	mWindowPositionX;
	int	mWindowPositionY;
	int	mWindowWidth;
	int	mWindowHeight;
	bool	mIsFullScreenMode;
	float	mPerspectiveFov;
	float	mPerspectiveNear;
	float	mPerspectiveFar;

	static GameApplication*	mInstance;


};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/