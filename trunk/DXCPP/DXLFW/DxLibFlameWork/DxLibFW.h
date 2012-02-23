/**===File Commentary=======================================*/
/**
 *	@file	DxLibFW.h
 *
 *	@brief	�t���[�����[�N�{��
 *
 *	@attention	�p�����Ďg�p
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
 * @brief	�R���X�g���N�^
 *			
 * @note	�e�萔�ŏ�����
 *
 *	@author	KORYUOH
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
 *	@author	KORYUOH
 *			
 * @date	2011/12/15	KORYUOH	�V�K�쐬
 */

	virtual void run();

	/**
	 * @brief	�f�[�^�ݒ�
	 *			
	 *	@author	KORYUOH
	 *			
	 * @date	2011/12/15	KORYUOH	�V�K�쐬
	 */
	void Pushed(const IPShare& Share);
public:
/**
 * @brief	���z�f�X�g���N�^
 *			
 *	@author	KORYUOH
 *			
 * @date	2011/12/15	KORYUOH	�V�K�쐬
 */
	virtual ~DXFW(){};
private:
	/**
	 *	@brief	������
	 *	@author	KORYUOH
	 */
	virtual void	initialize();
	/**
	 *	@brief	�X�V
	 *	@author	KORYUOH
	 */
	virtual void	update();
	/**
	 *	@brief	�`��
	 *	@author	KORYUOH
	 */
	virtual void	draw();
	/**
	 *	@brief	�I��
	 *	@author	KORYUOH
	 */
	virtual void	finish();
private:
	int	 init();
	int ProcessLoop();
	void MessegeBox();
};
#endif
