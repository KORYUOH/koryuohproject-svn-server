/**===File Commentary=======================================*/
/**
 *	@file	DebugUtility.cpp
 *
 *	@brief	�f�o�b�O�p�R���\�[���o��
 *
 *	@attention	�f�o�b�O�̂ݗL��
 *
 *	@author	KORYUOH
 *
 *	@date	2012/11/19
 */
/**===File Include=========================================*/
#include	<Utility/DebugUtility/DebugUtility.h>
#ifdef _DEBUG
#include	<sstream>
#include	<Windows.h>
/**===Class Implementation=================================*/
/**========================================================*/
/**
 *	@brief	�f�o�b�O�o��
 *	@param[in]	�ϒ�
 *	@note	������printf�ɏ�����
 *	@author	KORYUOH
 */
/**========================================================*/
void DebugUtility::print(const char* format,...){
	char tmp[1024];
	va_list argptr;
	va_start(argptr,format);
	vsprintf(tmp,format,argptr);
	va_end(argptr);
	OutputDebugString(tmp);
}
void DebugUtility::println(const char* format,...){
	char tmp[1024];
	va_list argptr;
	va_start(argptr,format);
	vsprintf(tmp,format,argptr);
	va_end(argptr);
	OutputDebugString(tmp);
	OutputDebugString("\n");
}
#else //_DEBUG is no defined
/**========================================================*/
/**
 *	@brief	�f�o�b�O�o��
 *	@param[in]	�ϒ�
 *	@attention	�U����
 *	@note	������printf�ɏ�����
 *	@author	KORYUOH
 */
/**========================================================*/

void DebugUtility::print(const char* format,...){
}
void DebugUtility::println(const char* format,...){
}
#endif//_DEBUG
/**===End Of File==========================================*/