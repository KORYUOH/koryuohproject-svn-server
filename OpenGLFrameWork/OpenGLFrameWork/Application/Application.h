/**===File Commentary=======================================*/
/**
 *	@file	Application.h
 *
 *	@brief	アプリケーションメインクラス
 *
 *	@author	KORYUOH
 *
 *	@date	2013/04/28
 */
/**===Include Guard========================================*/
#ifndef	_APPLICATOIN_H_
#define	_APPLICATOIN_H_
/**===File Include=========================================*/
#include	<Application/AppParam/AppParam.h>
/**===Class Definition=====================================*/
class Application{
public:
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	引数の数
	 *	@param[in]	引数の文字列
	 */
	Application(int argc,char* argv[]);
	/**
	 *	@brief	実行
	 */
	void run();
protected:
	/**
	 *	@brief	初期化
	 */
	virtual void initialize() = 0;
	/**
	 *	@brief	更新
	 *	@param[in]	フレームタイマ
	 */
	virtual void update(float f) = 0;
	/**
	 *	@brief	描画
	 */
	virtual void draw() = 0;
	/**
	 *	@brief	終了
	 */
	virtual void finish() = 0;
private:
	void glutInitialize();
	void initializeGL();

	void checkFullScreenMode();
private:
	int getWindowPositionX()const;
	int getWindowPositionY()const;
	int getWindowWidth()const;
	int getWindowHeight()const;
//	void setSwapInterval(int interval);
private:
	/**	メンバー変数*/
	static Application* mInstance;
private:
	AppParam mParam;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/