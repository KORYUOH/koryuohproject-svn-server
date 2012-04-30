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
#include	<gslib.h>
#include	<Device/IDevice.h>
/**===Class Definition=====================================*/
class GLMouse:public IDevice{
public
	/**
	 *	@brief	コンストラクタ
	 *	@author	KORYUOH
	 */:
	GLMouse();
	/**
	 *	@brief	デストラクタ
	 *	@author	KORYUOH
	 */
	virtual ~GLMouse(){};
	/**
	 *	@brief	更新処理
	 *	@author	KORYUOH
	 */
	virtual void update(void);
	/**
	 *	test
	 */
	virtual GLMouse& getInstance(){
		return *this;
	}
	/**
	 *	@brief	クリックされているか？
	 *	@param[in]	ボタン
	 *	@param[in]	状態
	 *	@author	KORYUOH
	 *	@return	buttonがstateならば真
	 */
	bool MouseClick(int button,int state)const;
	/**
	 *	@brief	衝突判定
	 *	@param[in]	判定範囲
	 *	@param[in]	ボタン
	 *	@param[in]	状態
	 *	@author	KORYUOH
	 *	@return	判定内でボタンが判定状態なら真
	 */
	bool MouseCollision(GSrect& rect,int button,int state)const;
	/**
	 *	@brief	マウス位置の取得
	 *	@author	KORYUOH
	 *	@return	マウスの位置
	 */
	GSvector2 getMousePosition()const;
private:
	/**
	 *	@brief	コールバック関数
	 *	@param[in]	ボタン
	 *	@param[in]	状態
	 *	@param[in]	x座標
	 *	@param[in]	y座標
	 *	@note	
	 *	[ button ]
	 *	GLUT_LEFT_BUTTON：「左ボタン」
	 *	GLUT_MIDDLE_BUTTON：「中央ボタン」
	 *	GLUT_RIGHT_BUTTON：「右ボタン」
	 *	
	 *	[ state ]
	 *	GLUT_DOWN：「ボタン」が「押された」
	 *	GLUT_UP：「ボタン」が「離れた」
	 *	
	 *	@author	KORYUOH
	 */
	static void callBack(int button,int state,int x,int y);
	/**
	 *	@brief	ドラッグ時コールバック関数
	 *	@param[in]	x座標
	 *	@param[in]	y座標
	 *	@author	KORYUOH
	 */
	static void drug(int x,int y);
public:
	/**
	 *	@brief	ドラッグ状態
	 *	@param[in]	ボタン
	 *	@param[in]	状態
	 *	@author	KORYUOH
	 *	@return	状態
	 */
	void toDrag(int button,int state);
	/**
	 *	@brief	X座標取得
	 *	@author	KORYUOH
	 *	@return	X座標
	 */
	int getMousePositionX()const{return mX;};
	/**
	 *	@brief	Y座標取得
	 *	@author	KORYUOH
	 *	@return	Y座標
	 */
	int getMousePositionY()const{return mY;};

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
	static int	mX,mY;
	//ボタンの種類
	static int mButton;
	//状態
	static int mState;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/