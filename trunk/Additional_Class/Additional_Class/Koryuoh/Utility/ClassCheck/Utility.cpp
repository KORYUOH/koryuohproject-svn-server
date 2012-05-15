/**===File Commentary=======================================*/
/**
 *	@file	Utility.cpp
 *
 *	@brief	ユーリティクラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/10
 */
/**===File Include=========================================*/
#include	<Koryuoh/Utility/ClassCheck/Utility.h>
/**===Class Implementation=================================*/
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
	bool isClass(const type_info& info){
		return info == typeid(_Ty);
	}
};
/**===End Of File==========================================*/