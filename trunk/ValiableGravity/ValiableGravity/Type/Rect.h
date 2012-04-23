/**===File Commentary=======================================*/
/**
 *	@file	Rect.h
 *
 *	@brief	矩形情報
 *
 *	@author	<作者名>
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
	 *	@brief	デフォルトコンストラクタ
	 *	@author	<作者名>
	 */
	Rect():mPos(0,0),mSize(0,0){
	}
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	x座標
	 *	@param[in]	y座標
	 *	@param[in]	幅
	 *	@param[in]	高さ
	 *	@author	<作者名>
	 */
	Rect(float x,float y,float w,float h):
	mPos(x,y),mSize(w,h){
	}
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	座標
	 *	@param[in]	サイズ
	 *	@author	<作者名>
	 */
	Rect(const Vector2& pos,const Vector2& size):
	mPos(pos),mSize(size){};

	float getLeft()const{
		return mPos.x;
	}
	float getTop()const{
		return mPos.y;
	}
	float getRight()const{
		return mPos.x+mSize.x;
	}
	float getBottom()const{
		return mPos.y+mSize.y;
	}
	
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/