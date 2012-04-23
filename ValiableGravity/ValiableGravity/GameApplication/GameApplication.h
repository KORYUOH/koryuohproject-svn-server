/**===File Commentary=======================================*/
/**
 *	@file	GameApplication.h
 *
 *	@brief	ゲームアプリケーション
 *
 *	@note	OpenGL
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/23
 */
/**===Include Guard========================================*/
#ifndef	_GAMEAPPLICATION_H_
#define	_GAMEAPPLICATION_H_
/**===File Include=========================================*/
#include	<GameLogic/Interface/IGameSystem.h>
#include	<memory>
#include	<string>
/**===Class Definition=====================================*/
class GameApplication:public IGameSystem{
public:
	/**
	 *	@brief	実行
	 *	@author	KORYUOH
	 */
	void run();
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	引数の数
	 *	@param[in]	コマンドラインオプション
	 *	@author	KORYUOH
	 */
	GameApplication(int argc,char* argv[]);
	/**
	 *	@brief	仮想デストラクタ
	 *	@author	KORYUOH
	 */
	virtual ~GameApplication(){};
protected:
		/**
	 *	@brief	初期化
	 *	@author	KORYUOH
	 */
	virtual void initialize();
	/**
	 *	@brief	ゲームメイン
	 *	@author	KORYUOH
	 */
	virtual void update(float f);
	/**
	 *	@brief	描画
	 *	@author	KORYUOH
	 */
	virtual void draw();
	/**
	 *	@brief	終了
	 *	@author	KORYUOH
	 */
	virtual void finish();
	/**
	 *	@brief	ウィンドウタイトルの取得
	 *	@author	KORYUOH
	 *	@return	ウィンドウタイトル
	 */
	const std::string& getWindowTitle()const;
	/**
	 *	@brief	X位置の取得
	 *	@author	KORYUOH
	 *	@return	X位置
	 */
	int getWindowPositionX()const;
	/**
	 *	@brief	Y位置の取得
	 *	@author	KORYUOH
	 *	@return	Y位置
	 */
	int getWindowPositionY()const;
	/**
	 *	@brief	幅の取得
	 *	@author	KORYUOH
	 *	@return	幅
	 */
	int getWindowWidth()const;
	/**
	 *	@brief	高さ取得
	 *	@author	KORYUOH
	 *	@return	高さ
	 */
	int getWindowHeight()const;
	/**
	 *	@brief	Fovの値の取得
	 *	@author	KORYUOH
	 *	@return	Fovの値
	 */
	float getPerspectiveFov()const;
	/**
	 *	@brief	Nearの値の取得
	 *	@author	KORYUOH
	 *	@return	Nearの値
	 */
	float getPerspectiveNear()const;
	/**
	 *	@brief	Farの値の取得
	 *	@author	KORYUOH
	 *	@return	Farの値
	 */
	float getPerspectiveFar()const;
	/**
	 *	@brief	ウィンドウタイトルの設定
	 *	@param[in]	ウィンドウタイトル
	 *	@author	KORYUOH
	 */
	void setWindowTitle(std::string& title);
	/**
	 *	@brief	ウィンドウ位置の設定
	 *	@param[in]	X位置
	 *	@author	KORYUOH
	 */
	void setWindowPositionX(int x);
	/**
	 *	@brief	ウィンドウ位置の設定
	 *	@param[in]	Y位置
	 *	@author	KORYUOH
	 */
	void setWindowPositionY(int y);
	/**
	 *	@brief	幅の設定
	 *	@param[in]	幅
	 *	@author	KORYUOH
	 */
	void setWindowWidth(int width);
	/**
	 *	@brief	高さの設定
	 *	@param[in]	高さ
	 *	@author	KORYUOH
	 */
	void setWindowHeight(int height);
	/**
	 *	@brief	Fovの設定
	 *	@param[in]	Fov
	 *	@author	KORYUOH
	 */
	void setPerspectiveFov(float fov);
	/**
	 *	@brief	Nearの設定
	 *	@param[in]	Near
	 *	@author	KORYUOH
	 */
	void setPerspectiveNear(float near);
	/**
	 *	@brief	Farの設定
	 *	@param[in]	Far
	 *	@author	KORYUOH
	 */
	void setPerspectiveFar(float far);
	/**
	 *	@brief	フルスクリーンモード
	 *	@param[in]	フラグ
	 *	@note	True:FullScreen
	 *	@author	KORYUOH
	 */
	void setFullScreenMode(bool mode);
	/**
	 *	@brief	フルスクリーンモードか？
	 *	@author	KORYUOH
	 *	@return	フラグ
	 */
	bool isFullScreenMode()const;
private:
	/**
	 *	@brief	OpenGL初期化
	 *	@author	KORYUOH
	 */
	void initializeGL( void );
	/**
	 *	@brief	インターバル設定
	 *	@param[in]	インターバル
	 *	@author	KORYUOH
	 */
	void setSwapInterval(int interval);

	/**
	 *	@brief	アクティベート
	 *	@param[in]	状態
	 *	@author	KORYUOH
	 */
	static void activate(int state);
	/**
	 *	@brief	ディスプレイ
	 *	@author	KORYUOH
	 */
	static void display(void);
	/**
	 *	@brief	アイドル
	 *	@author	KORYUOH
	 */
	static void idle(void);
	/**
	 *	@brief	リシャープ
	 *	@author	KORYUOH
	 */
	static void reshape(int width,int height);
	/**
	 *	@brief	デストロイ
	 *	@author	KORYUOH
	 */
	static void destroy(void);
private:
	/**	メンバー変数*/
	std::string	mWindowTitle;
	int	mWindowPositionX;
	int	mWindowPositionY;
	int	mWindowWidth;
	int	mWindowHeight;
	bool	mIsFullScreenMode;
	float	mPerspectiveFov;
	float	mPerspectiveNear;
	float	mPerspectiveFar;

	static GameApplication*	mInstance;


};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/