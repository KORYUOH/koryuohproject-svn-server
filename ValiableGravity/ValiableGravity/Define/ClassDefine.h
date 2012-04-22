/**===File Commentary=======================================*/
/**
 *	@file	ClassDefine.h
 *
 *	@brief	�N���X�^�ݒ�t�@�C��
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
class	IGameSystem;
/**===Class Definition=====================================*/

typedef	std::shared_ptr<IGameSystem>	GameSystem_ptr_t;



/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/