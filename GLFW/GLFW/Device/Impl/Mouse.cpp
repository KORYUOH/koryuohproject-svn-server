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
#include	<cmath>
#include	<cassert>
/**===Class Implementation=================================*/
/**========================================================*/
/**
 *	@brief	静的メンバ変数の初期化
 *	@author	KORYUOH
 */
/**========================================================*/
int GLMouse::mButton = -1;
int GLMouse::mState = 0;
GLMouse::Position GLMouse::mPos	=	GLMouse::Position();
GLMouse::Position GLMouse::mDrag	=	GLMouse::Position();
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@author	KORYUOH
 */
/**========================================================*/
GLMouse::GLMouse(){};
/**========================================================*/
/**
 *	@brief	更新
 *	@author	KORYUOH
 */
/**========================================================*/
void GLMouse::update(void){
	glutPassiveMotionFunc(positionUpdate);
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
	mPos.x_ = x;
	mPos.y_ = y;
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
 *	@attention 無記名名前空間内
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
		if(rectCheck(rect,GSrect(mPos.x_,mPos.y_)))
			return true;
	}
	return false;
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
	mDrag.x_ = x;
	mDrag.y_ = y;
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
		motionCall(button,state);
		break;
	default:
		assert(false);
	}
}
/**========================================================*/
/**
 *	@brief	マウス位置の取得
 *	@author	KORYUOH
 *	@return	マウス座標
 */
/**========================================================*/
GLMouse::Position GLMouse::getMousePosition()const{
	return mPos;
}
/**========================================================*/
/**
 *	@brief	マウス位置の更新コールバック
 *	@author	KORYUOH
 */
/**========================================================*/
void GLMouse::positionUpdate(int x,int y){
	mPos.x_ = x;
	mPos.y_ = y;
}
/**========================================================*/
/**
 *	@brief	長さの取得
 *	@author	KORYUOH
 *	@return	長さ
 */
/**========================================================*/
float GLMouse::length(){
	Position tmp = mPos - mDrag;
	return std::sqrt((float)(tmp.x_*tmp.x_+tmp.y_*tmp.y_));
}
/**========================================================*/
/**
 *	@brief	長さの取得
 *	@author	KORYUOH
 *	@return	長さ
 */
/**========================================================*/
float GLMouse::angle(){
	Position tmp = mPos - mDrag;
	return std::atan2f(tmp.y_,tmp.x_);
}
void GLMouse::motionCall(int button,int state){
	if(MouseClick(button,state))
		glutMotionFunc(drug);
	else
		glutMotionFunc(NULL);
}


/**===End Of File==========================================*/