/**===File Commentary=======================================*/
/**
 *	@file	Rect.h
 *
 *	@brief	矩形情報
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
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	KORYUOH
	 *	@return	<戻り値>
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