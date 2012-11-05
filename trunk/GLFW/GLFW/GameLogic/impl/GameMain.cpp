/**===File Commentary=======================================*/
/**
 *	@file	GameMain.cpp
 *
 *	@brief	�Q�[�����C���N���X����
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/01
 */
/**===File Include=========================================*/
#include	<GameLogic/impl/GameMain.h>
#include	<Sprite/Sprite3D/Sprite3D.h>
#include	<gslib.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	<�v��>
 *	@param[in]	<����>
 *	@attention	<���ӏ���>
 *	@note	<��������>
 *	@author	<��Җ�>
 *	@return	<�߂�l>
 */
/**========================================================*/
void GameMain::initialize(void){
	gsLoadTexture(TITLE	,"res/img/title.bmp");
	gsLoadTexture(BALL	,"res/img/ball.bmp");
	gsLoadTexture(BAR	,"res/img/bar.bmp");
}
/**========================================================*/
/**
 *	@brief	<�v��>
 *	@param[in]	<����>
 *	@attention	<���ӏ���>
 *	@note	<��������>
 *	@author	<��Җ�>
 *	@return	<�߂�l>
 */
/**========================================================*/
void GameMain::update(float f){
	Sprite3D titele(TITLE);
	titele.setPosition(Vector3(0.0,0.0,0.0));
	titele.draw();
}
/**========================================================*/
/**
 *	@brief	<�v��>
 *	@param[in]	<����>
 *	@attention	<���ӏ���>
 *	@note	<��������>
 *	@author	<��Җ�>
 *	@return	<�߂�l>
 */
/**========================================================*/
void GameMain::draw(){
	
}
/**========================================================*/
/**
 *	@brief	<�v��>
 *	@param[in]	<����>
 *	@attention	<���ӏ���>
 *	@note	<��������>
 *	@author	<��Җ�>
 *	@return	<�߂�l>
 */
/**========================================================*/
void GameMain::finish(){
	gsDeleteTexture(TITLE);
	gsDeleteTexture(BALL);
	gsDeleteTexture(BAR);
}
/**===End Of File==========================================*/