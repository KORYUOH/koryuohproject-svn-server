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
 * @brief	�R���X�g���N�^
 *			
 * @param	�Ȃ�
 *			
 * @return		�Ȃ�
 *			
 * @note	�e�萔�ŏ�����
 *			
 * @date	2011/12/15	KORYUOH	�V�K�쐬
 */

	DXFW():
		m_isWindowMode(WINDOW_MODE),
		m_WindowTitle(APPLICATIONTITLE),
		m_isOutLog(OUTLOGFILE){};
public:
/**
 * @brief	���s
 *			
 * @param	�Ȃ�
 *			
 * @return	�Ȃ�
 *			
 * @note	�Ȃ�
 *			
 * @date	2011/12/15	KORYUOH	�V�K�쐬
 */

	void run();
/**
 * @brief	���z�f�X�g���N�^
 *			
 * @param	�Ȃ�
 *			
 * @return	�Ȃ�
 *			
 * @note	�Ȃ�
 *			
 * @date	2011/12/15	KORYUOH	�V�K�쐬
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
