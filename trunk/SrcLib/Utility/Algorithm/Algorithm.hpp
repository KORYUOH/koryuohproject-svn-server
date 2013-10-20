/**===File Commentary=======================================*/
/**
 *	@file	Algorithm.h
 *
 *	@brief	省略アルゴリズム表現
 *
 *	@author	KORYUOH
 *
 *	@date	2013/10/20
 *
 *	@virsion	ver.1.20
 */
/**===Include Guard========================================*/
#ifndef	_UTILITY_ALGORITHM_H_
#define	_UTILITY_ALGORITHM_H_
/**===File Include=========================================*/
/**===Class Definition=====================================*/
template<typename CONTAINER,typename FUNCTION>
class Algorithm{
public:
	/**
	 *	@brief	省略形For_each
	 *	@param[in]	コンテナ
	 *	@param[in]	関数
	 *	@return	実行結果
	 */
	static FUNCTION ForEach(CONTAINER& container,FUNCTION function);

};
/**===End Class Definition=================================*/
#include <Utility/Argorithm/Algorithm.h>
#endif
/**===End Of File==========================================*/