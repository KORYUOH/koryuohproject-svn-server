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
#include	<Type/Math.h>
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
	mMouse.toDrag(MOUSE_LEFT,MOUSE_STATE_DOWN);

	
}
/**========================================================*/
/**
 *	@brief	�`��
 *	@author	<��Җ�>
 */
/**========================================================*/
void GameTest::draw(){
	gsDrawText("MPos[%3d,%3d] DPos[%3d,%3d] length[%.2f] angle[%.2f]"
		,mMouse.getMousePositionX()
		,mMouse.getMousePositionY()
		,mMouse.getDragMousePositionX()
		,mMouse.getDragMousePositionY()
		,mMouse.length(),
		Math::toDegree(mMouse.angle())
		);

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