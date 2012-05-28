/**===File Commentary=======================================*/
/**
 *	@file	GameTest.cpp
 *
 *	@brief	テスト用ゲームヘッダ実装ファイル
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
 *	@brief	初期化
 *	@author	<作者名>
 */
/**========================================================*/
void GameTest::initialize(void){
}
/**========================================================*/
/**
 *	@brief	更新
 *	@param[in]	フレーム
 *	@author	<作者名>
 */
/**========================================================*/
void GameTest::update(float f){
	mMouse.update();
	mMouse.toDrag(MOUSE_LEFT,MOUSE_STATE_DOWN);

	
}
/**========================================================*/
/**
 *	@brief	描画
 *	@author	<作者名>
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
 *	@brief	終了
 *	@author	<作者名>
 */
/**========================================================*/
void GameTest::finish(){

}
/**===End Of File==========================================*/