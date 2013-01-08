/**===File Commentary=======================================*/
/**
 *	@file	For_each.h
 *
 *	@brief	For_each�֐�
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/26
 *
 *	@virsion	ver.1.00
 */
/**===Include Guard========================================*/
#ifndef	_UTILITY_ALGORITHM_H_
#define	_UTILITY_ALGORITHM_H_
/**===File Include=========================================*/
#include	<algorithm>
/**===Class Definition=====================================*/
class Algorithm{
public:
	/**
	 *	@brief	�ȗ��`For_each
	 *	@param[in]	�R���e�i
	 *	@param[in]	�֐�
	 *	@return	�֐��̖߂�l
	 */
	template<typename Container,typename Function>
	static Function for_each(Container& container,Function function){
		return std::for_each(container.begin(),container.end(),function);
	}
	/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	KORYUOH
	 *	@return	<�߂�l>
	 */

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/