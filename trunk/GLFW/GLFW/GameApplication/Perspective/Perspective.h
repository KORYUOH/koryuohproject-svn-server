/**===File Commentary=======================================*/
/**
 *	@file	Perspective.h
 *
 *	@brief	パースペクティブ
 *
 *	@author	KORYUOH
 *
 *	@date	2013/09/14
 */
/**===Include Guard========================================*/
#ifndef	_PERSPECTIVE_H_
#define	_PERSPECTIVE_H_
/**===File Include=========================================*/
/**===Class Definition=====================================*/
struct Perspective{
	Perspective(float fov,float near,float far)
		:fov_(fov)
		,near_(near)
		,far_(far)
	{}
	float fov_;
	float near_;
	float far_;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/