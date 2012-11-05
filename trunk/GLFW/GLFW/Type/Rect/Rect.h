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
#include	<Type/Vector2/Vector2.h>
/**===Class Definition=====================================*/
struct Rect{
	
	Vector2	mPos;
	Vector2	mSize;
	/**
	 *	@brief	デフォルトコンストラクタ
	 *	@author	KORYUOH
	 */
	Rect():mPos(0,0),mSize(0,0){
	}
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	x座標
	 *	@param[in]	y座標
	 *	@param[in]	横幅
	 *	@param[in]	縦幅
	 *	@author	KORYUOH
	 */
	Rect(float x,float y,float w,float h):
	mPos(x,y),mSize(w,h){
	}
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	座標
	 *	@param[in]	サイズ
	 *	@author	KORYUOH
	 */
	Rect(const Vector2& pos,const Vector2& size):
	mPos(pos),mSize(size){};
	/**
	 *	@brief	上
	 *	@author	KORYUOH
	 *	@return	上端
	 */
	float top()const{
		return mPos.y_;
	}
	/**
	 *	@brief	左
	 *	@author	KORYUOH
	 *	@return	左端
	 */
	float left()const{
		return mPos.x_;
	}
	/**
	 *	@brief	右端
	 *	@author	KORYUOH
	 *	@return	右端
	 */
	float right()const{
		return (mSize.x_);
	}
	/**
	 *	@brief	下端
	 *	@author	KORYUOH
	 *	@return	下端
	 */
	float bottom()const{
		return (mSize.y_);
	}

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/