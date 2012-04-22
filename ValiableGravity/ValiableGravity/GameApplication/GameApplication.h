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
#include	<string>
/**===Class Definition=====================================*/
class GameApplication{
public:
	/**
	 *	@brief	実行
	 *	@author	KORYUOH
	 */
	void run();

protected:
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

private:
	/**	メンバー変数*/

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/