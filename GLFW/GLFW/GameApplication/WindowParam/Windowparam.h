/**===File Commentary=======================================*/
/**
 *	@file	WindowParam.h
 *
 *	@brief	WindowÉpÉâÉÅÅ[É^
 *
 *	@author	KORYUOH
 *
 *	@date	2013/09/14
 */
/**===Include Guard========================================*/
#ifndef	_WINDOWPARAM_H_
#define	_WINDOWPARAM_H_
/**===File Include=========================================*/
#include	<Type/Rect/Rect.h>
#include	<GameApplication/Perspective/Perspective.h>
/**===Class Definition=====================================*/
struct WindowParam{
	WindwParam(int x,int y,int width,int height,float fov,float near, float far)
		:mWindow((float)x,(float)y,(float)width,(float)height)
		,mPerspective(fov,near,far)
	{}
	WindowParam(Rect window,Perspective perspectives)
		:mWindow(window)
		,mPerspective(perspectives)
	{}
	Rect mWindow;
	Perspective mPerspective;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/