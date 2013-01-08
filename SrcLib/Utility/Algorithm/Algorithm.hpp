/**===File Commentary=======================================*/
/**
 *	@file	For_each.h
 *
 *	@brief	For_each関数
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
	 *	@brief	省略形For_each
	 *	@param[in]	コンテナ
	 *	@param[in]	関数
	 *	@return	関数の戻り値
	 */
	template<typename Container,typename Function>
	static Function for_each(Container& container,Function function){
		return std::for_each(container.begin(),container.end(),function);
	}
	/**
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	KORYUOH
	 *	@return	<戻り値>
	 */

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/