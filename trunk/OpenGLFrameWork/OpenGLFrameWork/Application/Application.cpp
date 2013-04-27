/**===File Commentary=======================================*/
/**
 *	@file	Application.cpp
 *
 *	@brief	�A�v���P�[�V����
 *
 *	@author	KORYUOH
 *
 *	@date	2013/04/28
 */
/**===File Include=========================================*/
#include	<Application/Application.h>
#include	<GL/glut.h>
#include	<sstream>
#include	<Windows.h>
/**===Class Implementation=================================*/
Application* Application::mInstance = nullptr;
/**========================================================*/
/**
 *	@brief	<�v��>
 *	@param[in]	<����>
 *	@attention	<���ӏ���>
 *	@note	<��������>
 *	@author	KORYUOH
 *	@return	<�߂�l>
 */
/**========================================================*/
Application::Application(int argc,char* argv[])
{
	mInstance = this;
	glutInit(&argc,argv);
}
/**========================================================*/
/**
 *	@brief	<�v��>
 *	@param[in]	<����>
 *	@attention	<���ӏ���>
 *	@note	<��������>
 *	@author	KORYUOH
 *	@return	<�߂�l>
 */
/**========================================================*/
void Application::run(){
	glutInitialize();



}

int Application::getWindowPositionX()const{
	return static_cast<int>(mParam.getWindowParam().left());
}
int Application::getWindowPositionY()const{
	return static_cast<int>(mParam.getWindowParam().top());
}
int Application::getWindowWidth()const{
	return static_cast<int>(mParam.getWindowParam().right());
}
int Application::getWindowHeight()const{
	return static_cast<int> (mParam.getWindowParam().bottom());
}
void Application::glutInitialize(){
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(getWindowPositionX(),getWindowPositionY());
	glutInitWindowSize(getWindowWidth(),getWindowHeight());
	checkFullScreenMode();
//	setSwapInterval(1);
}

void Application::checkFullScreenMode(){
	if(!mParam.isFullscreenMode()){
		glutCreateWindow(mParam.getWindowTitle().c_str());
		return;
	}
	std::ostringstream mode;
	mode << getWindowWidth() << "x"<<getWindowHeight()<<"@60";
	glutGameModeString(mode.str().c_str());
	glutEnterGameMode();
	glutSetCursor(GLUT_CURSOR_NONE);
}
/*
void Applciation::setSwapInterval(int interval){
	typedef BOOL (WINAPI * LPFNWGLSWAPINTERVALEXTPROC)(int interval);
	LPFNWGLSWAPINTERVALEXTPROC wglSwapIntervalExt = NULL;

}
//*/


/**===End Of File==========================================*/