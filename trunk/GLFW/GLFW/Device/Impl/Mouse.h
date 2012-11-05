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
#include	<Device/IDevice.h>
#include	<Type/Vector2/Vector2.h>
#include	<Type/Rect/Rect.h>
/**===Class Definition=====================================*/
class GLMouse:public IDevice{
public:
	/**
	 *	@brief	コンストラクタ
	 *	@author	KORYUOH
	 */
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
	bool MouseCollision(Rect& rect,int button,int state)const;
	/**
	 *	@brief	マウス位置の取得
	 *	@author	KORYUOH
	 *	@return	マウスの位置
	 */
	Vector2 getMousePosition()const;
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
	/**
	 *	@brief	ドラッグ時コールバック関数
	 *	@param[in]	x座標
	 *	@param[in]	y座標
	 *	@author	KORYUOH
	 */
	static void positionUpdate(int x,int y);

	/**
	 *	@brief	MotionCall
	 *	@param[in]	ボタン
	 *	@param[in]	状態
	 *	@author	KORYUOH
	 */
	void motionCall(int button,int state);


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
	int getMousePositionX()const{return mPos.x_;};
	/**
	 *	@brief	Y座標取得
	 *	@author	KORYUOH
	 *	@return	Y座標
	 */
	int getMousePositionY()const{return mPos.y_;};
	/**
	 *	@brief	X座標取得
	 *	@author	KORYUOH
	 *	@return	X座標
	 */
	int getDragMousePositionX()const{return mDrag.x_;};
	/**
	 *	@brief	Y座標取得
	 *	@author	KORYUOH
	 *	@return	Y座標
	 */
	int getDragMousePositionY()const{return mDrag.y_;};
	/**
	 *	@brief	ドラッグ線の長さ取得
	 *	@author	KORYUOH
	 *	@return	長さ
	 */
	float length();
	/**
	 *	@brief	ドラッグ線の角度取得
	 *	@author	KORYUOH
	 *	@return	角度
	 */
	float angle();
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
	static Vector2 mPos;
	static Vector2 mDrag;
	//ボタンの種類
	static int mButton;
	//状態
	static int mState;

	public:
		const static int UP;
		const static int DOWN;

		const static int LEFT;
		const static int RIGHT;
		const static int MIDDLE;



};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/