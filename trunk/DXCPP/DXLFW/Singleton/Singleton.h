/**===File Commentary=======================================*/
/**
 *	@file	Singleton.h
 *
 *	@brief	�V���O���g���p�^�[���e���v���[�g
 *
 *	@note	C++ Style
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/21  -2013/02/19
 */
/**===Include Guard========================================*/
#ifndef	_SINGLETON_H_
#define	_SINGLETON_H_
/**===File Include=========================================*/
template<typename _Ty>
/**===Class Definition=====================================*/
class Singleton{
protected:
	/**
	 *	Singleton Pattern Constructor
	 */
	/**
	 *	@brief	�R���X�g���N�^
	 */ 
	 Singleton(){}
	 /**
	 *	@brief	�R�s�[�R���X�g���N�^
	 */
	 Singleton(const Singleton& other){};
	 Singleton& operator = (const Singleton& other){};
	 virtual ~Singleton(){}
public:
	/**
	 *	@brief	���̎擾
	 *	@return	����
	 */
	 static _Ty& getInstance(){
	 	static _Ty Instance;
	 	return Instance;
	 }
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/