/**===File Commentary=======================================*/
/**
 *	@file	Application.cpp
 *
 *	@brief	アプリケーション
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
 *	@brief	<要約>
 *	@param[in]	<引数>
 *	@attention	<注意書き>
 *	@note	<メモ書き>
 *	@author	KORYUOH
 *	@return	<戻り値>
 */
/**========================================================*/
Application::Application(int argc,char* argv[])
{
	mInstance = this;
	glutInit(&argc,argv);
}
/**========================================================*/
/**
 *	@brief	<要約>
 *	@param[in]	<引数>
 *	@attention	<注意書き>
 *	@note	<メモ書き>
 *	@author	KORYUOH
 *	@return	<戻り値>
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