/**===File Commentary=======================================*/
/**
 *	@file	AppParam.h
 *
 *	@brief	アプリケーションデータ
 *
 *	@author	KORYUOH
 *
 *	@date	2013/04/28
 */
/**===Include Guard========================================*/
#ifndef	_APPPARAM_H_
#define	_APPPARAM_H_
/**===File Include=========================================*/
#include	<Type/Rect/Rect.h>
#include	<string>
/**===Class Definition=====================================*/
class AppParam{
public:
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	ウィンドウの位置、サイズ情報
	 *	@param[in]	ウィンドウのタイトル
	 *	@param[in]	スクリーンモード
	 */
	AppParam();
	/**
	 *	@brief	仮想デストラクタ
	 */
	virtual ~AppParam();
	/**
	 *	@brief	ウィンドウデータ取得
	 *	@return	ウィンドウ情報
	 */
	const Rect& getWindowParam()const;
	/**
	 *	@brief	ウィンドウタイトル取得
	 *	@return	ウィンドウタイトル
	 */
	const std::string& getWindowTitle()const;
	/**
	 *	@brief	フルスクリーンモードか?
	 *	@return	そうならば真
	 */
	bool isFullscreenMode()const;
	/**
	 *	@brief	フルスクリーンモード化
	 */
	void FullscreenModeActivate();
	/**
	 *	@brief	ウィンドウパラメータ設定
	 *	@param[in]	ウィンドウパラメータ
	 */
	void setWindowParam(const Rect& WindowParam);
	/**
	 *	@brief	ウィンドウタイトル設定
	 *	@param[in]	ウィンドウタイトル
	 */
	void setWindowTitle(const std::string& title);
private:
	Rect mWindowParam;
	std::string mWindowTitle;
	bool mFullScreen;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/