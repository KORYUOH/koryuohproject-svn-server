/**===File Commentary=======================================*/
/**
 *	@file	GameMain.cpp
 *
 *	@brief	ゲームメインクラス実装
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
 *	@brief	<要約>
 *	@param[in]	<引数>
 *	@attention	<注意書き>
 *	@note	<メモ書き>
 *	@author	<作者名>
 *	@return	<戻り値>
 */
/**========================================================*/
void GameMain::initialize(void){
	gsLoadTexture(TITLE	,"res/img/title.bmp");
	gsLoadTexture(BALL	,"res/img/ball.bmp");
	gsLoadTexture(BAR	,"res/img/bar.bmp");
}
/**========================================================*/
/**
 *	@brief	<要約>
 *	@param[in]	<引数>
 *	@attention	<注意書き>
 *	@note	<メモ書き>
 *	@author	<作者名>
 *	@return	<戻り値>
 */
/**========================================================*/
void GameMain::update(float f){
	Sprite3D titele(TITLE);
	titele.setPosition(Vector3(0.0,0.0,0.0));
	titele.draw();
}
/**========================================================*/
/**
 *	@brief	<要約>
 *	@param[in]	<引数>
 *	@attention	<注意書き>
 *	@note	<メモ書き>
 *	@author	<作者名>
 *	@return	<戻り値>
 */
/**========================================================*/
void GameMain::draw(){
	
}
/**========================================================*/
/**
 *	@brief	<要約>
 *	@param[in]	<引数>
 *	@attention	<注意書き>
 *	@note	<メモ書き>
 *	@author	<作者名>
 *	@return	<戻り値>
 */
/**========================================================*/
void GameMain::finish(){
	gsDeleteTexture(TITLE);
	gsDeleteTexture(BALL);
	gsDeleteTexture(BAR);
}
/**===End Of File==========================================*/