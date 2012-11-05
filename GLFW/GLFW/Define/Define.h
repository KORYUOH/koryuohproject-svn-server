/**===File Commentary=======================================*/
/**
 *	@file	Define.h
 *
 *	@brief	定義ファイル
 *
 *	@author	KORYUOH
 *
 *	@date	2012/11/05
 */
/**===Include Guard========================================*/
#ifndef	_DEFINE_H_
#define	_DEFINE_H_
/**===Definition=====================================*/

#define WINDW_SIZE_X		640 
#define WINDW_SIZE_Y		480

#define WINDOW_CREATE_POSITION_X			0
#define WINDOW_CREATE_POSITION_Y			0

#ifndef APPLICATION_TITLE
#ifdef WINDOWTITLE
#define APPLICATION_TITLE WINDOWTITLE
#else
#define WINDOWTITLE
#define APPLICATION_TITLE			"GameWindow"
#endif
#endif

#ifdef _FULLSCREEN
#define SCREENMODE true
#else
#define SCREENMODE false
#endif



/**===End Definition=================================*/
#endif
/**===End Of File==========================================*/