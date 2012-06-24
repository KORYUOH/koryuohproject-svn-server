/**===File Commentary=======================================*/
/**
 *	@file	Singleton.h
 *
 *	@brief	�V���O���g���p�^�[��
 *
 *	@note	Java Style
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/21
 */
/**===Include Guard========================================*/
#ifndef	_SINGLETON_H_
#define	_SINGLETON_H_
/**===File Include=========================================*/
#include	<memory>
typedef std::unique_ptr<Singleton> Singleton_ptr;
/**===Class Definition=====================================*/
class Singleton{
//_/_/_/_/Singleton Block _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
private:
	Singleton_ptr Instance;
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
	static Singleton_ptr& getInstance(){
		if(Instance.enpty())
			Instance.reset(new Singleton());
		return Instance;
	}
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
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