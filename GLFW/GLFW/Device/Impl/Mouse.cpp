/**===File Commentary=======================================*/
/**
 *	@file	Mouse.cpp
 *
 *	@brief	OpenGL�}�E�X�N���X����
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
 *	@brief	�ÓI�����o�ϐ��̏�����
 *	@author	KORYUOH
 */
/**========================================================*/
int GLMouse::mButton = -1;
int GLMouse::mState = 0;
GLMouse::Position GLMouse::mPos	=	GLMouse::Position();
GLMouse::Position GLMouse::mDrag	=	GLMouse::Position();
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@author	KORYUOH
 */
/**========================================================*/
GLMouse::GLMouse(){};
/**========================================================*/
/**
 *	@brief	�X�V
 *	@author	KORYUOH
 */
/**========================================================*/
void GLMouse::update(void){
	glutPassiveMotionFunc(positionUpdate);
	glutMouseFunc(callBack);	
}
/**========================================================*/
/**
 *	@brief	�R�[���o�b�N�֐�
 *	@param[in]	�}�E�X�{�^��
 *	@param[in]	�{�^�����
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
 *	@brief	�N���b�N����Ă��邩�H
 *	@param[in]	�{�^��
 *	@param[in]	���
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
 *	@brief	��`���`�F�b�N
 *	@param[in]	��r�͈�
 *	@param[in]	�}�E�X�ʒu
 *	@attention ���L�����O��ԓ�
 *	@author	KORYUOH
 *	@return	�����Ă���ΐ^
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
 *	@brief	�Փ˔���
 *	@param[in]	�Փ˔͈�
 *	@param[in]	�}�E�X�{�^��
 *	@param[in]	���
 *	@author	KORYUOH
 *	@return	�����Ă����Ԃ�state�Ȃ�^
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
 *	@brief	�h���b�O��ԃR�[���o�b�N�֐�
 *	@param[in]	x���W
 *	@param[in]	y���W
 *	@author	KORYUOH
 */
/**========================================================*/
void GLMouse::drug(int x,int y){
	mDrag.x_ = x;
	mDrag.y_ = y;
}
/**========================================================*/
/**
 *	@brief	�h���b�O��ԃR�[���o�b�N�֐�
 *	@param[in]	x���W
 *	@param[in]	y���W
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
 *	@brief	�}�E�X�ʒu�̎擾
 *	@author	KORYUOH
 *	@return	�}�E�X���W
 */
/**========================================================*/
GLMouse::Position GLMouse::getMousePosition()const{
	return mPos;
}
/**========================================================*/
/**
 *	@brief	�}�E�X�ʒu�̍X�V�R�[���o�b�N
 *	@author	KORYUOH
 */
/**========================================================*/
void GLMouse::positionUpdate(int x,int y){
	mPos.x_ = x;
	mPos.y_ = y;
}
/**========================================================*/
/**
 *	@brief	�����̎擾
 *	@author	KORYUOH
 *	@return	����
 */
/**========================================================*/
float GLMouse::length(){
	Position tmp = mPos - mDrag;
	return std::sqrt((float)(tmp.x_*tmp.x_+tmp.y_*tmp.y_));
}
/**========================================================*/
/**
 *	@brief	�����̎擾
 *	@author	KORYUOH
 *	@return	����
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