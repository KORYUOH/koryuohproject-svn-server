/**===File Commentary=======================================*/
/**
 *	@file	Utility.h
 *
 *	@brief	�Q�[���p���[�e�B���e�B�[
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
	 *	@brief	�Փ˔���
	 *	@param[in]	�~���1
	 *	@param[in]	�~���2
	 *	@author	KORYUOH
	 *	@return	�������Ă���ΐ^
	 */
	const bool isCollision(const Vector3& t1,const Vector3& t2);
	/**
	 *	@brief	�Փ˔���
	 *	@param[in]	�����1
	 *	@param[in]	���a
	 *	@param[in]	�����2
	 *	@param[in]	���a
	 *	@author	KORYUOH
	 *	@return	�������Ă���ΐ^
	 */
	const bool isCollision(const Vector3& t1,float r1,const Vector3& t2,float r2);
	/**
	 *	@brief	�Փ˔���
	 *	@param[in]	�~���1
	 *	@param[in]	�~���2
	 *	@author	KORYUOH
	 *	@return	�������Ă���ΐ^
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