/**===File Commentary=======================================*/
/**
 *	@file	Mouse.cpp
 *
 *	@brief	OpenGLマウスクラス実装
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/29
 */
/**===File Include=========================================*/
#include	<Define/ClassDefine.h>
#include	<Device/Impl/Mouse.h>
#include	<cassert>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	更新
 *	@author	KORYUOH
 */
/**========================================================*/
void GLMouse::update(void){
	glutMouseFunc(callBack);	
}
/**========================================================*/
/**
 *	@brief	コールバック関数
 *	@param[in]	マウスボタン
 *	@param[in]	ボタン状態
 *	@author	KORYUOH
 */
/**========================================================*/
void GLMouse::callBack(int button,int state, int x, int y){
	mButton = button;
	mState = state;
	mX = x;
	mY = y;
}
/**========================================================*/
/**
 *	@brief	クリックされているか？
 *	@param[in]	ボタン
 *	@param[in]	状態
 *	@author	KORYUOH
 */
/**========================================================*/
bool GLMouse::MouseClick(int button,int state)const{
	if(mButton == button && mState == state)
		return true;
	return false;
}
/**========================================================*/
/**
 *	@brief	矩形内チェック
 *	@param[in]	比較範囲
 *	@param[in]	マウス位置
 *	@author	KORYUOH
 *	@return	入っていれば真
 */
/**========================================================*/
namespace{
	bool rectCheck(GSrect& rect,GSrect& mou){
		if(rect.top<mou.top&&mou.top<rect.bottom)
			if(rect.left<mou.left&& mou.left <rect.right)
				return true;
		return false;
	}
}
/**========================================================*/
/**
 *	@brief	衝突判定
 *	@param[in]	衝突範囲
 *	@param[in]	マウスボタン
 *	@param[in]	状態
 *	@author	KORYUOH
 *	@return	入っている状態でstateなら真
 */
/**========================================================*/
bool GLMouse::MouseCollision(GSrect& rect,int button,int state)const{
	if(MouseClick(button,state)){
		if(rectCheck(rect,GSrect(mX,mY)))
			return true;
		return false;
	}
}
/**========================================================*/
/**
 *	@brief	ドラッグ状態コールバック関数
 *	@param[in]	x座標
 *	@param[in]	y座標
 *	@author	KORYUOH
 */
/**========================================================*/
void GLMouse::drug(int x,int y){
	mX = x;
	mY = y;
}
/**========================================================*/
/**
 *	@brief	ドラッグ状態コールバック関数
 *	@param[in]	x座標
 *	@param[in]	y座標
 *	@author	KORYUOH
 */
/**========================================================*/
void GLMouse::toDrag(int button,int state){
	switch(state){
	case MOUSE_STATE_UP:
		glutPassiveMotionFunc(drug);
		break;
	case MOUSE_STATE_DOWN:
		if(MouseClick(button,state))
			glutMotionFunc(drug);
		break;
	default:
		assert(false);
	}
}




/**===End Of File==========================================*/