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
#include	<Type/Vector2/Vector2.h>
/**===Class Definition=====================================*/
struct Rect{
	
	Vector2	mPos;
	Vector2	mSize;
	/**
	 *	@brief	�f�t�H���g�R���X�g���N�^
	 *	@author	KORYUOH
	 */
	Rect():mPos(0,0),mSize(0,0){
	}
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	x���W
	 *	@param[in]	y���W
	 *	@param[in]	����
	 *	@param[in]	�c��
	 *	@author	KORYUOH
	 */
	Rect(float x,float y,float w,float h):
	mPos(x,y),mSize(w,h){
	}
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	���W
	 *	@param[in]	�T�C�Y
	 *	@author	KORYUOH
	 */
	Rect(const Vector2& pos,const Vector2& size):
	mPos(pos),mSize(size){};
	/**
	 *	@brief	��
	 *	@author	KORYUOH
	 *	@return	��[
	 */
	float top()const{
		return mPos.y_;
	}
	/**
	 *	@brief	��
	 *	@author	KORYUOH
	 *	@return	���[
	 */
	float left()const{
		return mPos.x_;
	}
	/**
	 *	@brief	�E�[
	 *	@author	KORYUOH
	 *	@return	�E�[
	 */
	float right()const{
		return (mSize.x_);
	}
	/**
	 *	@brief	���[
	 *	@author	KORYUOH
	 *	@return	���[
	 */
	float bottom()const{
		return (mSize.y_);
	}

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/