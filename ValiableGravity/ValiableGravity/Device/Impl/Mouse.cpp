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
#include	<cassert>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	�X�V
 *	@author	KORYUOH
 */
/**========================================================*/
void GLMouse::update(void){
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
	mX = x;
	mY = y;
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
		if(rectCheck(rect,GSrect(mX,mY)))
			return true;
		return false;
	}
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
	mX = x;
	mY = y;
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
		if(MouseClick(button,state))
			glutMotionFunc(drug);
		break;
	default:
		assert(false);
	}
}




/**===End Of File==========================================*/