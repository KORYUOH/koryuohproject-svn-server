/**===File Commentary=======================================*/
/**
 *	@file	DxLibFW.h
 *
 *	@brief	フレームワーク本体
 *
 *	@attention	継承して使用
 *
 *	@author	KORYUOH
 *
 *	@date	2011/12/01
 */
/**===Include Guard========================================*/
#ifndef __DxLibFW
#define __DxLibFW
/**===File Include=========================================*/
#pragma comment (linker,"/LIBPATH:../Include")
#include	<../Include/DxLib.h>
#include	<DxLibFlameWork/DxLibInterFace.h>
#include	<string>
/**===Class Definition=====================================*/
class DXFW:public DxLibInterFace{
private:
	bool m_isWindowMode;
	std::string m_WindowTitle;
	bool m_isOutLog;
public:
/**
 * @brief	コンストラクタ
 *			
 * @note	各定数で初期化
 *
 *	@author	KORYUOH
 *			
 * @date	2011/12/15	KORYUOH	新規作成
 */

	DXFW():
		m_isWindowMode(WINDOW_MODE),
		m_WindowTitle(APPLICATIONTITLE),
		m_isOutLog(OUTLOGFILE){};
public:
/**
 * @brief	実行
 *			
 *	@author	KORYUOH
 *			
 * @date	2011/12/15	KORYUOH	新規作成
 */

	void run();
/**
 * @brief	仮想デストラクタ
 *			
 *	@author	KORYUOH
 *			
 * @date	2011/12/15	KORYUOH	新規作成
 */
	virtual ~DXFW(){};
protected:
	/**
	 *	@brief	初期化
	 *	@author	KORYUOH
	 */
	void	Initialize();
	/**
	 *	@brief	更新
	 *	@author	KORYUOH
	 */
	void	update();
	/**
	 *	@brief	描画
	 *	@author	KORYUOH
	 */
	void	draw();
	/**
	 *	@brief	終了
	 *	@author	KORYUOH
	 */
	void	finish();
private:
	int	 init();
	int ProcessLoop();
	void MessegeBox();
};
#endif
