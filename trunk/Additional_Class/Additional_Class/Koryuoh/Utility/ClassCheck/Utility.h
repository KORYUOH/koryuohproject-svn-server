/**===File Commentary=======================================*/
/**
 *	@file	Utility.h
 *
 *	@brief	ユーリティーヘッダ
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/10
 */
/**===Include Guard========================================*/
#ifndef	_UTILITY_H_
#define	_UTILITY_H_
/**===File Include=========================================*/

namespace KORYUOH{
	/**========================================================*/
	/**
	 *	@brief	指定されたクラスかチェックする
	 *	@param[in]	チェックするポインタ	書式:typeid(*pointer)
	 *	@note	チェックしたいクラスを指定すること
	 *	@note	書式:isClass<チェックしたいクラス>(typeid(*pointer))
	 *	@return	指定されたクラスなら真
	 */
	/**========================================================*/
	template<class _Ty>
	bool isClass(const type_info& info);
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/