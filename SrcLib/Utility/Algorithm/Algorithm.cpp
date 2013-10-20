/**===File Commentary=======================================*/
/**
 *	@file	Algorithm.cpp
 *
 *	@brief	省略アルゴリズム実装
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
 *	@brief	省略ForEach
 *	@param[in]	コンテナ
 *	@param[in]	関数
 *	@return	実行結果
 */
/**========================================================*/
template <typename CONTAINER,typename FUNCTION>
FUNCTION Algorithm<CONTAINER,FUNCTION>::ForEach(CONTAINER& container,FUNCTION function){
	return std::for_each(container.begin(),container.end(),function);
}

/**===End Of File==========================================*/