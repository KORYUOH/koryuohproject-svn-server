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
#ifndef	__DxLibFW
#define	__DxLibFW
/**===File Include=========================================*/
#pragma comment (linker,"/LIBPATH:../Include")
#include	<../Include/DxLib.h>
#include	<DxLibFlameWork/DxLibInterFace.h>
#include	<DxLibFlameWork/IProcess.h>
#include	<Define/Orig_def.h>
#include	<string>
#include	<memory>
#include	<vector>
/**===Class Definition=====================================*/
class DXFW:public DxLibInterFace,public IProcess{
private:
	bool m_isWindowMode;
	std::string m_WindowTitle;
	bool m_isOutLog;
	std::vector<IPShare> m_Process;

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

	virtual void run();

	/**
	 * @brief	データ設定
	 *			
	 *	@author	KORYUOH
	 *			
	 * @date	2011/12/15	KORYUOH	新規作成
	 */
	void Pushed(const IPShare& Share);
public:
/**
 * @brief	仮想デストラクタ
 *			
 *	@author	KORYUOH
 *			
 * @date	2011/12/15	KORYUOH	新規作成
 */
	virtual ~DXFW(){};
private:
	/**
	 *	@brief	初期化
	 *	@author	KORYUOH
	 */
	virtual void	initialize();
	/**
	 *	@brief	更新
	 *	@author	KORYUOH
	 */
	virtual void	update();
	/**
	 *	@brief	描画
	 *	@author	KORYUOH
	 */
	virtual void	draw();
	/**
	 *	@brief	終了
	 *	@author	KORYUOH
	 */
	virtual void	finish();
private:
	int	 init();
	int ProcessLoop();
	void MessegeBox();
};
#endif
