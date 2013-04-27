/**===File Commentary=======================================*/
/**
 *	@file	AppParam.cpp
 *
 *	@brief	�A�v���P�[�V�����f�[�^
 *
 *	@author	KORYUOH
 *
 *	@date	2013/04/28
 */
/**===File Include=========================================*/
#include	<Application/AppParam/AppParam.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 */
/**========================================================*/
AppParam::AppParam()
	:mWindowParam(0.0f,0.0f,640.0f,480.0f)
	,mWindowTitle("GameWindow")
	,mFullScreen(false)
{
}
/**========================================================*/
/**
 *	@brief	���z�f�X�g���N�^
 */
/**========================================================*/
AppParam::~AppParam(){
}
/**========================================================*/
/**
 *	@brief	�E�B���h�E�p�����[�^�擾
 *	@return	�E�B���h�E�p�����[�^
 */
/**========================================================*/
const Rect& AppParam::getWindowParam()const{
	return mWindowParam;
}
/**========================================================*/
/**
 *	@brief	�E�B���h�E�^�C�g���擾
 *	@return	�E�B���h�E�^�C�g��
 */
/**========================================================*/
const std::string& AppParam::getWindowTitle()const{
	return mWindowTitle;
}
/**========================================================*/
/**
 *	@brief	�t���X�N���[�����H
 *	@return	�t���X�N���[���Ő^
 */
/**========================================================*/
bool AppParam::isFullscreenMode()const{
	return mFullScreen;
}
/**========================================================*/
/**
 *	@brief	�t���X�N���[�����[�h�L��
 */
/**========================================================*/
void AppParam::FullscreenModeActivate(){
	mFullScreen = true;
}
/**========================================================*/
/**
 *	@brief	�E�B���h�E�p�����[�^�ݒ�
 *	@param[in]	�p�����[�^
 */
/**========================================================*/
void AppParam::setWindowParam(const Rect& param){
	mWindowParam = param;
}
/**========================================================*/
/**
 *	@brief	�E�B���h�E�^�C�g���ݒ�
 *	@param[in]	�E�B���h�E�^�C�g��
 */
/**========================================================*/
void AppParam::setWindowTitle(const std::string& title){
	mWindowTitle = title;
}

/**===End Of File==========================================*/