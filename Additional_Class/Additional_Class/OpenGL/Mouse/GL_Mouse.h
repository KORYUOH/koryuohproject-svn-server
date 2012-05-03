/**===File Commentary=======================================*/
/**
 *	@file	GL_Mouse.h
 *
 *	@brief	OpenGLマウスクラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/29
 */
/**===Include Guard========================================*/
#ifndef	_GL_MOUSE_H_
#define	_GL_MOUSE_H_
/**===File Include=========================================*/
#include	<glut.h>
/**===Class Definition=====================================*/
class GLMouse{
public:
	/**
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	<作者名>
	 *	@return	<戻り値>
	 */
	virtual void update();
private:
	/**
	 *	@brief	コールバック関数
	 *	@param[in]	ボタン
	 *	@param[in]	状態
	 *	@param[in]	x座標
	 *	@param[in]	y座標
	 *	@note	
	 *	 [ button ]
   *	GLUT_LEFT_BUTTON：「左ボタン」
   *	GLUT_MIDDLE_BUTTON：「中央ボタン」
   *	GLUT_RIGHT_BUTTON：「右ボタン」
	 *	
	 *	[ state ]
   *	GLUT_DOWN：「ボタン」が「押された」
   *	GLUT_UP：「ボタン」が「離れた」
	 *	
	 *	@author	<作者名>
	 */
	static void callBack(int button,int state,int x,int y);
private:
	/**	メンバー変数*/
	/**
	[ button ]
  GLUT_LEFT_BUTTON：「左ボタン」
  GLUT_MIDDLE_BUTTON：「中央ボタン」
  GLUT_RIGHT_BUTTON：「右ボタン」
 
	[ state ]
  GLUT_DOWN：「ボタン」が「押された」
  GLUT_UP：「ボタン」が「離れた」
 */
	//座標
	int	mX,mY;
	//ボタンの種類
	int mButton;
	//状態
	int mState;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/