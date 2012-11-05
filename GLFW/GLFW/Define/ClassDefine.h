/**===File Commentary=======================================*/
/**
 *	@file	ClassDefine.h
 *
 *	@brief	クラス型設定ファイル
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/22
 */
/**===Include Guard========================================*/
#ifndef	_CLASSDEFINE_H_
#define	_CLASSDEFINE_H_
/**===File Include=========================================*/
#include	<memory>
#include	<Type/Vector3/Vector3.h>
class	IGameSystem;
/**===Class Definition=====================================*/

typedef	std::shared_ptr<IGameSystem>	GameSystem_ptr_t;
typedef	Vector3 Circle_t;

/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/