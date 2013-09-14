/**===File Commentary=======================================*/
/**
 *	@file	GameApplication.cpp
 *
 *	@brief	�Q�[���A�v���P�[�V�����N���X����
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/23
 */
/**===File Include=========================================*/
#include	<GameApplication/Gameapplication.h>
#include	<Define/Define.h>
#include	<gslib.h>
#include	<sstream>
/**===Class Implementation=================================*/
/**========================================================*/
/**
 *	@brief	�R�[���o�b�N�֐��p�̐ÓI�����o�ϐ�
 *	@note	<��������>
 *	@author	KORYUOH
 */
/**========================================================*/
GameApplication* GameApplication::mInstance = 0;
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�����̐�
 *	@param[in]	�R�}���h���C������
 *	@author	KORYUOH
 */
/**========================================================*/
GameApplication::GameApplication(int argc, char* argv[]):
	mWindowTitle(APPLICATION_TITLE),
	mParam(Rect(
		WINDOW_CREATE_POSITION_X,
		WINDOW_CREATE_POSITION_Y,
		WINDOW_SIZE_X,
		WINDOW_SIZE_Y
		),
		Perspective(
		50.0f,
		0.5f,
		100.0f))
	mIsFullScreenMode( SCREENMODE ),
{
	//���g�̃C���X�^���X��ݒ�
	mInstance = this;
	//GLUT������
	glutInit(&argc,argv);
}
/**========================================================*/
/**
 *	@brief	���s
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::run(){
	//�E�B���h�E�̐ݒ�
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(getWindowPositionX(),getWindowPositionY());
	glutInitWindowSize(getWindowWidth(),getWindowHeight());
	//�t���X�N���[�����[�h���H
	FullScreenCheck();
	gsSystemInitialize();
	//Vsync�L����
	setSwapInterval(1);
	//����������
	gsRandamize();
	
	//OpenGL������
	initializeGL();
	//�A�v���P�[�V����������
	initialize();

	setCallBacks();

	//�t���[���^�C�}�[���Z�b�g
	gsFrameTimerReset();
	//���C�����[�v
	glutMainLoop();
}
/**========================================================*/
/**
 *	@brief	OpenGL�������֐�
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::initializeGL(void){
	//�f�t�H���C�g�p�����[�^
	const static float LightAmbient[]	=	{ 0.2f, 0.2f , 0.2f , 1.0f};
	const static float LightDiffuse[]	=	{ 1.0f, 1.0f , 1.0f , 1.0f};
	const static float LightSpeclar[]	=	{ 1.0f, 1.0f , 1.0f , 1.0f};
	const static float LightPosition[]	=	{ 1.0f, 1.0f , 1.0f , 0.0f};

	//��ʃN���A���̃J���[�ݒ�
	glClearColor(0.0f, 0.0f,0.0f,1.0f);
	//�ʃJ�����O�����̗L����
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	//�f�v�X�o�b�t�@��1.0�ŃN���A
	glClearDepth(1.0f);
	//�f�v�X�e�X�g�L����
	glEnable(GL_DEPTH_TEST);
	//�p�[�X�y�N�e�B�u�␳
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
	//�u�����h�L����
	glEnable(GL_BLEND);
	//�f�t�H�u�����h���ݒ�
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	//�f�t�H���_�ϊ��s��ݒ�
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		0.0f, 0.0f ,10.0f,
		0.0f, 0.0f ,0.0f,
		0.0f, 1.0f ,0.0f
		);
	//�f�t�H���C�g�ݒ�
	glLightfv(GL_LIGHT0,	GL_AMBIENT	,LightAmbient);
	glLightfv(GL_LIGHT0,	GL_DIFFUSE	,LightDiffuse);
	glLightfv(GL_LIGHT0,	GL_SPECULAR	,LightSpeclar);
	glLightfv(GL_LIGHT0,	GL_POSITION	,LightPosition);
	glEnable(GL_LIGHT0);
	//���C�e�B���O�L����
	glEnable(GL_LIGHTING);
}
/**========================================================*/
/**
 *	@brief	�R�[���o�b�N�֐�Destroy
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::destroy( void ){
	//�Q�[���I������
	mInstance->finish();

	//���̓f�o�C�X�V�X�e���I��
	gsFinishInput();
	//�T�E���h�V�X�e���I��
	gsFinishSound();
	//�O���t�B�b�N�V�X�e���I��
	gsFinishGraphics();
}
/**========================================================*/
/**
 *	@brief	�E�B���h�E�T�C�Y�ύX���ɌĂ΂��R�[���o�b�N�֐�
 *	@param[in]	��
 *	@param[in]	����
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::reshape(int width,int height){
	//������0�ɂȂ�Ȃ��悤��
	height = (height == 0) ? 1:height;
	//����0�ɂȂ�Ȃ��悤��
	width = (width == 0) ? 1:width;
	//Viewport�ݒ�
	glViewport(0,0,width,height);
	//�����ˉe�ϊ��s��
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(
		mInstance->getPerspectiveFov(),
		(float)width/(float)height,
		mInstance->getPerspectiveNear(),
		mInstance->getPerspectiveFar()
		);
	//���f���r���[���[�h�w
	glMatrixMode(GL_MODELVIEW);
	//�E�B���h�E�̕��ƍ������X�V
	mInstance->setWindowWidth(width);
	mInstance->setWindowHeight(height);
}
/**========================================================*/
/**
 *	@brief	�����C�x���g���Ȃ��Ƃ��ɌĂяo�����֐�
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::idle(void){
	//�t���[���^�C�}�[�X�V
	gsFrameTimerUpdate();
	do{
		//���̓f�o�C�X�ǂݍ���
		gsReadInput();

		//�Q�[���X�V����
		mInstance->update(gsFrameTimerGetTime());

		//Esc�������ꂽ�H
		if(GetAsyncKeyState(VK_ESCAPE)!=0){
			
			mInstance->finishCheck();

			std::exit(0);
		}
	}while(gsFrameTimerIsSkip() == GS_TRUE);
	//�`�揈�����Ăяo��
	glutPostRedisplay();
}
/**========================================================*/
/**
 *	@brief	�`�掞�R�[���o�b�N�֐�
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::display(void){
	//��ʃN���A
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	//�Q�[���`�揈��
	mInstance->draw();

	//�_�u���o�b�t�@�؂�ւ�
	glutSwapBuffers();
	//�^�C�}�[�E�F�C�g
	gsFrameTimerWait();

}
/**========================================================*/
/**
 *	@brief	�E�B���h�E���A�N�e�B�u�ɂȂ����Ƃ��ɌĂяo�����R�[���o�b�N
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::activate(int state){
	//���̓f�o�C�X�ɃA�N�e�B����`����
	gsActivateInput(state);
	//�T�E���h�V�X�e���ɃA�N�e�B�u��`����
	gsActivateSound(state);
}
/**========================================================*/
/**
 *	@brief	�_�u���o�b�t�@�؂�ւ��C���^�[�o��
 *	@param[in]	�C���^�[�o��
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::setSwapInterval(int interval){
	//wglSwapIntervalEXT�g���֐��|�C���^�֐��^
	typedef	BOOL	(WINAPI * LPFNWGLSWAPINTERVALEXTPROC)(int interval);
	LPFNWGLSWAPINTERVALEXTPROC	wglSwapIntervalExt = NULL;
	//SwapIntervalEXT�̊֐��|�C���^���擾
	wglSwapIntervalExt = (LPFNWGLSWAPINTERVALEXTPROC)
		wglGetProcAddress("wglSwapIntervalEXT");
	//�擾�ł����H
	if(wglSwapIntervalExt != NULL)
		wglSwapIntervalExt(interval);
}
/**========================================================*/
/**
 *	@brief	�E�B���h�E�^�C�g���擾
 *	@author	KORYUOH
 *	@return	�E�B���h�E�^�C�g��
 */
/**========================================================*/
const std::string& GameApplication::getWindowTitle()const{
	return mWindowTitle;
}
/**========================================================*/
/**
 *	@brief	�E�B���h�E��X���W�擾
 *	@author	KORYUOH
 *	@return	x���W
 */
/**========================================================*/
int GameApplication::getWindowPositionX()const{
	return (int)mParam.mWindow.mPos.x_;
}
/**========================================================*/
/**
 *	@brief	�E�B���h�E��Y���W�擾
 *	@author	KORYUOH
 *	@return	Y���W
 */
/**========================================================*/
int GameApplication::getWindowPositionY()const{
	return (int)mParam.mWindow.mPos.y_;
}
/**========================================================*/
/**
 *	@brief	�E�B���h�E�̕��擾
 *	@author	KORYUOH
 *	@return	��
 */
/**========================================================*/
int GameApplication::getWindowWidth()const{
	return (int)mParam.mWindow.mSize.x_;
}
/**========================================================*/
/**
 *	@brief	�E�B���h�E�̍����擾
 *	@author	KORYUOH
 *	@return	����
 */
/**========================================================*/
int GameApplication::getWindowHeight()const{
	return (int)mParam.mWindow.mSize.y_;
}
/**========================================================*/
/**
 *	@brief	����p�擾
 *	@author	KORYUOH
 *	@return	����p
 */
/**========================================================*/
float GameApplication::getPerspectiveFov()const{
	return mParam.mPerspective.fov_;
}
/**========================================================*/
/**
 *	@brief	�߃N���b�v�ʎ擾
 *	@author	KORYUOH
 *	@return	�߃N���b�v��
 */
/**========================================================*/
float GameApplication::getPerspectiveNear()const{
	return mParam.mPerspective.near_;
}
/**========================================================*/
/**
 *	@brief	���N���b�v�ʎ擾
 *	@author	KORYUOH
 *	@return	���N���b�v��
 */
/**========================================================*/
float GameApplication::getPerspectiveFar()const{
	return mParam.mPerspective.far_;
}
/**========================================================*/
/**
 *	@brief	�E�B���h�E�^�C�g���ݒ�
 *	@param[in]	�^�C�g��
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::setWindowTitle(const std::string& title){
	mWindowTitle = title;
}
/**========================================================*/
/**
 *	@brief	X���W�ݒ�
 *	@param[in]	X���W
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::setWindowPositionX(int x){
	mParam.mWindow.mPos.x_ = (float)x;
}
/**========================================================*/
/**
 *	@brief	Y���W�ݒ�
 *	@param[in]	Y���W
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::setWindowPositionY(int y){
	mParam.mWindow.mPos.y_ = (float)y;
}
/**========================================================*/
/**
 *	@brief	���ݒ�
 *	@param[in]	��
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::setWindowWidth(int width){
	mParam.mWindow.mSize.x_ = (float)width;
}
/**========================================================*/
/**
 *	@brief	�����ݒ�
 *	@param[in]	����
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::setWindowHeight(int height){
	mParam.mWindow.mSize.y_ = (float)height;
}
/**========================================================*/
/**
 *	@brief	����p�ݒ�
 *	@param[in]	����p
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::setPerspectiveFov(float fov){
	mParam.mPerspective.fov_ = fov;
}
/**========================================================*/
/**
 *	@brief	�߃N���b�v�ʐݒ�
 *	@param[in]	�߃N���b�v��
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::setPerspectiveNear(float znear){
	mParam.mPerspective.near_ = znear;
}
/**========================================================*/
/**
 *	@brief	���N���b�v�ʐݒ�
 *	@param[in]	���N���b�v��
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::setPerspectiveFar(float zfar){
	mParam.mPerspective.far_ = zfar;
}
/**========================================================*/
/**
 *	@brief	�t���X�N���[�����[�h�ݒ�ݒ�
 *	@param[in]	���[�h
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::setFullScreenMode(bool mode){
	mIsFullScreenMode = mode;
}
/**========================================================*/
/**
 *	@brief	�t���X�N���[�����[�h�����ׂ�
 *	@author	KORYUOH
 *	@return	FullScreenMode
 */
/**========================================================*/
bool GameApplication::isFullScreenMode()const{
	return mIsFullScreenMode;
}
/**========================================================*/
/**
 *	@brief	�I����������`�F�b�N
 *	@author	KORYUOH
 */
/**========================================================*/

void GameApplication::finishCheck(){
	if(mInstance->isFullScreenMode())
		glutLeaveGameMode();

	else
		//�I�������Ăяo��
		mInstance->destroy();
}
/**========================================================*/
/**
 *	@brief	�t���X�N���[���N���`�F�b�N
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::FullScreenCheck(){
	if(!isFullScreenMode()){
		//�E�B���h�E���[�h
		glutCreateWindow(getWindowTitle().c_str());
		return;
	}
	std::ostringstream mode;
	//�t���X�N���[���ݒ蕶����쐬
	mode << getWindowWidth() << "x"<<getWindowHeight()<<"@60";
	//�t���X�N���[�����[�h�ɐݒ�
	glutGameModeString(mode.str().c_str());
	glutEnterGameMode();
	//�}�E�X�J�[�\���͏���
	glutSetCursor(GLUT_CURSOR_NONE);
}
/**========================================================*/
/**
 *	@brief	gs�V�X�e��������
 */
/**========================================================*/
void GameApplication::gsSystemInitialize(){
	//�O���t�B�b�N�V�X�e��������
	gsInitGraphics();
	//�T�E���h�V�X�e��������
	gsInitSound((HWND)_glutGetHWND());
	//���̓f�o�C�X�V�X�e��������
	gsInitInput((HWND)_glutGetHWND());
}
/**========================================================*/
/**
 *	@brief	�R�[���o�b�N�֐��̐ݒ�
 */
/**========================================================*/
void GameApplication::setCallBacks(){
	//�I�������֐��ݒ�
	_glutDestroyFunc(destroy);
	//�E�B���h�E�T�C�Y�ύX���̊֐���ݒ�
	glutReshapeFunc(reshape);
	//�\�������֐���ݒ�
	glutDisplayFunc(display);
	//�C�x���g�̂Ȃ��Ƃ��̊֐���ݒ�
	glutIdleFunc(idle);
	//�E�B���h�E���A�N�e�B�u�ɂȂ����Ƃ��̊֐���ݒ�
	_glutActivateFunc(activate);
}




/**===End Of File==========================================*/