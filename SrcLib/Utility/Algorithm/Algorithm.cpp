/**===File Commentary=======================================*/
/**
 *	@file	Algorithm.cpp
 *
 *	@brief	�ȗ��A���S���Y������
 *
 *	@author	KORYUOH
 *
 *	@date	2013/10/20
 */
/**===File Include=========================================*/
#include	"Algorithm.h"
#include	<algorithm>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	�ȗ�ForEach
 *	@param[in]	�R���e�i
 *	@param[in]	�֐�
 *	@return	���s����
 */
/**========================================================*/
template <typename CONTAINER,typename FUNCTION>
FUNCTION Algorithm<CONTAINER,FUNCTION>::ForEach(CONTAINER& container,FUNCTION function){
	return std::for_each(container.begin(),container.end(),function);
}

/**===End Of File==========================================*/