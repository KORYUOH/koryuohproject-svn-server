/**===File Commentary=======================================*/
/**
 *	@file	AppParam.h
 *
 *	@brief	�A�v���P�[�V�����f�[�^
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
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�E�B���h�E�̈ʒu�A�T�C�Y���
	 *	@param[in]	�E�B���h�E�̃^�C�g��
	 *	@param[in]	�X�N���[�����[�h
	 */
	AppParam();
	/**
	 *	@brief	���z�f�X�g���N�^
	 */
	virtual ~AppParam();
	/**
	 *	@brief	�E�B���h�E�f�[�^�擾
	 *	@return	�E�B���h�E���
	 */
	const Rect& getWindowParam()const;
	/**
	 *	@brief	�E�B���h�E�^�C�g���擾
	 *	@return	�E�B���h�E�^�C�g��
	 */
	const std::string& getWindowTitle()const;
	/**
	 *	@brief	�t���X�N���[�����[�h��?
	 *	@return	�����Ȃ�ΐ^
	 */
	bool isFullscreenMode()const;
	/**
	 *	@brief	�t���X�N���[�����[�h��
	 */
	void FullscreenModeActivate();
	/**
	 *	@brief	�E�B���h�E�p�����[�^�ݒ�
	 *	@param[in]	�E�B���h�E�p�����[�^
	 */
	void setWindowParam(const Rect& WindowParam);
	/**
	 *	@brief	�E�B���h�E�^�C�g���ݒ�
	 *	@param[in]	�E�B���h�E�^�C�g��
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