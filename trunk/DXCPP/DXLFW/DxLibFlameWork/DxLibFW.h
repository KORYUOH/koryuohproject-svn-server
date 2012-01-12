#ifndef __DxLibFW
#define __DxLibFW
#pragma comment (linker,"/LIBPATH:../Include")
#include	 "../../Include/DxLib.h"
#include	 "DxLibInterFace.h"
#include	<string>
class DXFW:public DxLibInterFace{
private:
	bool m_isWindowMode;
	std::string m_WindowTitle;
	bool m_isOutLog;
public:
/**
 * @brief	コンストラクタ
 *			
 * @param	なし
 *			
 * @return		なし
 *			
 * @note	各定数で初期化
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
 * @param	なし
 *			
 * @return	なし
 *			
 * @note	なし
 *			
 * @date	2011/12/15	KORYUOH	新規作成
 */

	void run();
/**
 * @brief	仮想デストラクタ
 *			
 * @param	なし
 *			
 * @return	なし
 *			
 * @note	なし
 *			
 * @date	2011/12/15	KORYUOH	新規作成
 */

	virtual ~DXFW(){};
protected:
	void	Initialize();
	void	update();
	void	draw();
	void	finish();
private:
	int	 init();
	int ProcessLoop();
	void MessegeBox();
};
#endif
