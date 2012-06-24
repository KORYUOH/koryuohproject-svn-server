/**===File Commentary=======================================*/
/**
 *	@file	Singleton.h
 *
 *	@brief	�V���O���g���p�^�[��
 *
 *	@note	C++ Style
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/21
 */
/**===Include Guard========================================*/
#ifndef	_SINGLETON_H_
#define	_SINGLETON_H_
/**===File Include=========================================*/
/**===Class Definition=====================================*/
class Singleton{
private:
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
	 Singleton(const Singleton& other);
	 Singleton& operator = (const Singleton& other);
	 
public:
	/**
	 *	@brief	���̎擾
	 *	@return	����
	 */
	 static Singleton& getInstance(){
	 	static Singleton Instance();
	 	return Instance;
	 }
	 /**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	<��Җ�>
	 *	@return	<�߂�l>
	 */

private:
	/**	�����o�[�ϐ�*/

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/