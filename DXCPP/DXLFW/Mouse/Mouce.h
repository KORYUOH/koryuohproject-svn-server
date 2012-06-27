/**===File Commentary=======================================*/
/**
 *	@file	Mouse.h
 *
 *	@brief	マウス入力
 *
 *	@author	KORYUOH
 *
 *	@date	2012/01/13
 */
/**===Include Guard========================================*/
#ifndef _MOUCE_H_INCLUDED_
#define _MOUCE_H_INCLUDED_
/**===File Include=========================================*/
#include	<../Include/DxLib.h>
#include	<Define/DefineManager.h>
/**===Class Definition=====================================*/
class Mouse{
private:
	Mouse():m_Dispflag(false),m_pos_x(0),m_pos_y(0),m_input(0),m_beforeInput(0){};
	Mouse(const Mouse& it);
	Mouse&  operator = (const Mouse& are);
public:
	/**
	 *	@brief	仮想デストラクタ
	 *	@author	KORYUOH
	 */
	virtual ~Mouse(){};
private:
	bool m_Dispflag;
	int m_pos_x,m_pos_y;
	int m_input,m_beforeInput;
public:
	//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/test code

	const static int MOUSE_BUTTON_LEFT;
	const static int MOUSE_BUTTON_RIGHT;
	const static int MOUSE_BUTTON_MIDDLE;

	//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
	/**
	 *	@brief	実体を得る
	 *	@author	KORYUOH
	 *	@return	実体
	 */
	static Mouse& getInstance(){
		static Mouse Instance;
		return Instance;
	}

public:
	/**
	 *	@brief	カーソル表示モードの変更
	 *	@param[in]	flag:bool	表示でtrue
	 *	@author	KORYUOH
	 */
	void setMouseCursolDispFlag(bool flag);
	/**
	 *	@brief	マウスの情報の更新
	 *	@author	KORYUOH
	 */
	void MouseUpdate();
	/**
	 *	@brief	クリックされたかのチェック
	 *	@author	KORYUOH
	 *	@return	クリックされたときtrue
	 */
	bool onClick();
	/**
	 *	@brief	右クリックされたかのチェック
	 *	@author	KORYUOH
	 *	@return	クリックされたときtrue
	 */
	bool onClickR();
	/**
	 *	@brief	ホイールクリックされたかのチェック
	 *	@author	KORYUOH
	 *	@return	クリックされたときtrue
	 */
	bool onClickM();
	/**
	 *	@brief	矩形内に入っているか
	 *	@param[in]	accept:Rect	矩形情報
	 *	@author	KORYUOH
	 *	@return	入っていればtrue
	 */
	bool onClick(Rect accept);
	/**
	 *	@brief	円内に入っているか
	 *	@param[in]	accept:Circle	円情報
	 *	@author	KORYUOH
	 *	@return	入っていればtrue
	 */
	bool onClick(Circle accept);
	/**
	 *	@brief	矩形内に入っているか
	 *	@param[in]	accept:Rect	矩形情報
	 *	@author	KORYUOH
	 *	@return	入っていればtrue
	 */
	bool onClickR(Rect accept);
	/**
	 *	@brief	円内に入っているか
	 *	@param[in]	accept:Circle	円情報
	 *	@author	KORYUOH
	 *	@return	入っていればtrue
	 */
	bool onClickR(Circle accept);
	/**
	 *	@brief	矩形内に入っているか
	 *	@param[in]	accept:Rect	矩形情報
	 *	@author	KORYUOH
	 *	@return	入っていればtrue
	 */
	bool onClickM(Rect accept);
	/**
	 *	@brief	円内に入っているか
	 *	@param[in]	accept:Circle	円情報
	 *	@author	KORYUOH
	 *	@return	入っていればtrue
	 */
	bool onClickM(Circle accept);
	/**
	 *	@brief	マウスのX座標を得る
	 *	@author	KORYUOH
	 *	@return	X座標
	 */
	int getMousePositionX()const{
		return m_pos_x;
	}
		/**
	 *	@brief	マウスのY座標を得る
	 *	@author	KORYUOH
	 *	@return	Y座標
	 */
	int getMousePositionY()const{
		return m_pos_y;
	}

	//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/test code
	bool getMouseStateTrigger();



	//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

private:
	/**
	 *	@brief	矩形チェック
	 *	@param[in]	accept:Rect	矩形情報
	 *	@author	KORYUOH
	 *	@return	正しいならtrue
	 */
	bool CheckRect(Rect accept);
};
#endif // _MOUCE_H_INCLUDED_
