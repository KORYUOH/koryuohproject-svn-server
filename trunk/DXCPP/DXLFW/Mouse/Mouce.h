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
	Mouse():m_Dispflag(false),m_pos_x(0),m_pos_y(0){};
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
public:
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
	 *	@brief	マウスの位置の更新
	 *	@author	KORYUOH
	 */
	void MousePositionUpdate();
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
	bool onClickInRect(Rect accept);
	/**
	 *	@brief	円内に入っているか
	 *	@param[in]	accept:Circle	円情報
	 *	@author	KORYUOH
	 *	@return	入っていればtrue
	 */
	bool onClickInCircle(Circle accept);
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
