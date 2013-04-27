/**===File Commentary=======================================*/
/**
 *	@file	Application.h
 *
 *	@brief	�A�v���P�[�V�������C���N���X
 *
 *	@author	KORYUOH
 *
 *	@date	2013/04/28
 */
/**===Include Guard========================================*/
#ifndef	_APPLICATOIN_H_
#define	_APPLICATOIN_H_
/**===File Include=========================================*/
#include	<Application/AppParam/AppParam.h>
/**===Class Definition=====================================*/
class Application{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�����̐�
	 *	@param[in]	�����̕�����
	 */
	Application(int argc,char* argv[]);
	/**
	 *	@brief	���s
	 */
	void run();
protected:
	/**
	 *	@brief	������
	 */
	virtual void initialize() = 0;
	/**
	 *	@brief	�X�V
	 *	@param[in]	�t���[���^�C�}
	 */
	virtual void update(float f) = 0;
	/**
	 *	@brief	�`��
	 */
	virtual void draw() = 0;
	/**
	 *	@brief	�I��
	 */
	virtual void finish() = 0;
private:
	void glutInitialize();
	void initializeGL();

	void checkFullScreenMode();
private:
	int getWindowPositionX()const;
	int getWindowPositionY()const;
	int getWindowWidth()const;
	int getWindowHeight()const;
//	void setSwapInterval(int interval);
private:
	/**	�����o�[�ϐ�*/
	static Application* mInstance;
private:
	AppParam mParam;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/