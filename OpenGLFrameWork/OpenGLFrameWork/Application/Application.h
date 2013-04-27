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
private:
	/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	KORYUOH
	 *	@return	<�߂�l>
	 */
	void initialize();
	/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	KORYUOH
	 *	@return	<�߂�l>
	 */
	void update(float f);
	/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	KORYUOH
	 *	@return	<�߂�l>
	 */
	void draw();
/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	KORYUOH
	 *	@return	<�߂�l>
	 */
	void finish();

private:
	/**	�����o�[�ϐ�*/
	static Application* mInstance;
private:
	AppParam param;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/