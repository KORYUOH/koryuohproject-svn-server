/**===File Commentary=======================================*/
/**
 *	@file	Rect.h
 *
 *	@brief	��`���
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/23
 */
/**===Include Guard========================================*/
#ifndef	_RECT_H_
#define	_RECT_H_
/**===File Include=========================================*/
#include	<Type/Vector2.h>
/**===Class Definition=====================================*/
struct Rect{
	
	Vector2	mPos;
	Vector2	mSize;
	/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	KORYUOH
	 *	@return	<�߂�l>
	 */
	Rect():mPos(0,0),mSize(0,0){
	}
	Rect(float x,float y,float w,float h):
	mPos(x,y),mSize(w,h){
	}
	Rect(const Vector2& pos,const Vector2& size):
	mPos(pos),mSize(size){};
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/