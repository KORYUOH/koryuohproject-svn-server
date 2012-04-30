/**===File Commentary=======================================*/
/**
 *	@file	GameTest.cpp
 *
 *	@brief	�e�X�g�p�Q�[���w�b�_�����t�@�C��
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/30
 */
/**===File Include=========================================*/
#include	<GameLogic/impl/GameTest.h>
#include	<Define/ClassDefine.h>
#include	<Device/Impl/Mouse.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	������
 *	@author	<��Җ�>
 */
/**========================================================*/
void GameTest::initialize(void){
}
/**========================================================*/
/**
 *	@brief	�X�V
 *	@param[in]	�t���[��
 *	@author	<��Җ�>
 */
/**========================================================*/
void GameTest::update(float f){
	mMouse.update();
	mMouse.toDrag(MOUSE_LEFT,MOUSE_STATE_UP);
}
/**========================================================*/
/**
 *	@brief	�`��
 *	@author	<��Җ�>
 */
/**========================================================*/
void GameTest::draw(){
	gsDrawText("%d,%d",mMouse.getMousePositionX(),mMouse.getMousePositionY());
}
/**========================================================*/
/**
 *	@brief	�I��
 *	@author	<��Җ�>
 */
/**========================================================*/
void GameTest::finish(){

}
/**===End Of File==========================================*/