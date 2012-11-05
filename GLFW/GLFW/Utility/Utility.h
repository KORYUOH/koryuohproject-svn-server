/**===File Commentary=======================================*/
/**
 *	@file	Utility.h
 *
 *	@brief	ゲーム用ユーティリティー
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/23
 */
/**===Include Guard========================================*/
#ifndef	_UTILITY_H_
#define	_UTILITY_H_
/**===File Include=========================================*/
#include	<Type/Vector3/Vector3.h>
#include	<Type/Rect/Rect.h>
#include	<algorithm>
/**===Class Definition=====================================*/
namespace KORYUOH{
	/**
	 *	@brief	衝突判定
	 *	@param[in]	円情報1
	 *	@param[in]	円情報2
	 *	@author	KORYUOH
	 *	@return	あたっていれば真
	 */
	const bool isCollision(const Vector3& t1,const Vector3& t2);
	/**
	 *	@brief	衝突判定
	 *	@param[in]	球情報1
	 *	@param[in]	半径
	 *	@param[in]	球情報2
	 *	@param[in]	半径
	 *	@author	KORYUOH
	 *	@return	あたっていれば真
	 */
	const bool isCollision(const Vector3& t1,float r1,const Vector3& t2,float r2);
	/**
	 *	@brief	衝突判定
	 *	@param[in]	円情報1
	 *	@param[in]	円情報2
	 *	@author	KORYUOH
	 *	@return	あたっていれば真
	 */
	const bool isCollision(const Rect& t1,const Rect& t2);

	template<typename Container,typename Function>
	Function for_each(Container& container,Function function){
		return std::for_each(container.begin(),container.end(),function);
	}



};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/