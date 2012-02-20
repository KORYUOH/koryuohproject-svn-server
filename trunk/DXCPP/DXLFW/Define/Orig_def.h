/**===File Commentary=======================================*/
/**
 *	@file	Orig_def.h
 *
 *	@brief	’è‹`
 *
 *	@note	‚¨‚à‚ÉŽg‚¢‚â‚·‚­‚·‚é‚½‚ß
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/20
 */
/**===Include Guard========================================*/
#ifndef	_ORIG_DEF_H_
#define	_ORIG_DEF_H_
/**===File Include=========================================*/
#include	<memory>
#include	<DxLibFlameWork/IProcess.h>
/**===Type Defines====================================*/
typedef	std::auto_ptr<IProcess> IPAuto;
typedef	std::shared_ptr<IProcess>IPShare;

#endif
/**===End Of File==========================================*/