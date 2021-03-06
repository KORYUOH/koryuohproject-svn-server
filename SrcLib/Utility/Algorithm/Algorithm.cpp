/**===File Commentary=======================================*/
/**
 *	@file	Algorithm.cpp
 *
 *	@brief	ΘͺASYΐ
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
 *	@brief	ΘͺForEach
 *	@param[in]	Rei
 *	@param[in]	Φ
 *	@return	ΐsΚ
 */
/**========================================================*/
template <typename CONTAINER,typename FUNCTION>
FUNCTION Algorithm<CONTAINER,FUNCTION>::ForEach(CONTAINER& container,FUNCTION function){
	return std::for_each(container.begin(),container.end(),function);
}

/**===End Of File==========================================*/