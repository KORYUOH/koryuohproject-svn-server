/**===File Commentary=======================================*/
/**
 *	@file	instanceof.hpp
 *
 *	@brief	Run Time Type Idenfication
 *
 *	@author	KORYUOH
 *
 *	@date	2013/01/08
 */
/**===Include Guard========================================*/
#ifndef	__INSTANCEOF_HPP_
#define	__INSTANCEOF_HPP_
/**===File Include=========================================*/
/**===Class Definition=====================================*/
class Instanceof{
public:
	/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	KORYUOH
	 *	@return	<�߂�l>
	 */
	template <typename T,typename Ty>
	bool Instanceof (T &typeOne,Ty TypeTow){
		return typeid(typeOne) == typeid(TypeTow);
	}	
private:
	/**	�����o�[�ϐ�*/

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/