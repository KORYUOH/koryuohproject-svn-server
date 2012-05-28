/**===File Commentary=======================================*/
/**
 *	@file	IRunnable.h
 *
 *	@brief	�X���b�h���s�C���^�[�t�F�[�X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/22
 */
/**===Include Guard========================================*/
#ifndef	_IRUNNABLE_H_
#define	_IRUNNABLE_H_
/**===File Include=========================================*/
/**===Class Definition=====================================*/
class IRunnable{
public:
	/**
	 *	@brief	�f�X�g���N�^
	 */
	virtual ~IRunnable(){};
	/**
	 *	@brief	���s
	 */
	virtual void run() = 0;
private:
	/**	�����o�[�ϐ�*/

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/