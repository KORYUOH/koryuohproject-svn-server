/**===File Commentary=======================================*/
/**
 *	@file	GameApplication.cpp
 *
 *	@brief	�Q�[���A�v���P�[�V�����N���X����
 *
 *	@author	<��Җ�>
 *
 *	@date	2012/04/23
 */
/**===File Include=========================================*/
#include	<GameApplication/Gameapplication.h>
#include	<gslib.h>
#include	<sstream>
/**===Class Implementation=================================*/
/**========================================================*/
/**
 *	@brief	�R�[���o�b�N�֐��p�̐ÓI�����o�ϐ�
 *	@note	<��������>
 *	@author	<��Җ�>
 */
/**========================================================*/
GameApplication* GameApplication::mInstance = 0;
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�����̐�
 *	@param[in]	�R�}���h���C������
 *	@author	<��Җ�>
 */
/**========================================================*/
GameApplication::GameApplication(int argc, char* argv[]):
	mWindowTitle("GameWindow"),
	mWindowPositionX( 0 ),
	mWindowPositionY( 0 ),
	mWindowWidth( 640 ),
	mWindowHeight( 480 ),
	mIsFullScreenMode( false ),
	mPerspectiveFov(50.0f),
	mPerspectiveNear(0.5f),
	mPerspectiveFar(100.0f)
{
	//���g�̃C���X�^���X��ݒ�
	mInstance = this;
	//GLUT������
	glutInit(&argc,argv);
}
/**========================================================*/
/**
 *	@brief	���s
 *	@author	<��Җ�>
 */
/**========================================================*/
void GameApplication::run(){
	//�E�B���h�E�̐ݒ�
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(getWindowPositionX(),getWindowPositionY());
	glutInitWindowSize(getWindowWidth(),getWindowHeight());
	//�t���X�N���[�����[�h���H
	if(isFullScreenMode()==true){
		std::ostringstream mode;
		//�t���X�N���[���ݒ蕶����쐬
		mode << getWindowWidth() << "x"<<getWindowHeight()<<"@60";
		//�t���X�N���[�����[�h�ɐݒ�
		glutGameModeString(mode.str().c_str());
		glutEnterGameMode();
		//�}�E�X�J�[�\���͏���
		glutSetCursor(GLUT_CURSOR_NONE);
	}else{
		//�E�B���h�E���[�h
		glutCreateWindow(getWindowTitle().c_str());
	}
	
	//�O���t�B�b�N�V�X�e��������
	gsInitGraphics();
	//�T�E���h�V�X�e��������
	gsInitSound((HWND)_glutGetHWND());
	//���̓f�o�C�X�V�X�e��������
	gsInitInput((HWND)_glutGetHWND());
	
	//Vsync�L����
	setSwapInterval(1);
	//����������
	gsRandamize();
	
	//OpenGL������
	initializeGL();
	//�A�v���P�[�V����������
	initialize();

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

	//�t���[���^�C�}�[���Z�b�g
	gsFrameTimerReset();
	//���C�����[�v
	glutMainLoop();
}
/**========================================================*/
/**
 *	@brief	OpenGL�������֐�
 *	@author	<��Җ�>
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
 *	@author	<��Җ�>
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
 *	@author	<��Җ�>
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
 *	@author	<��Җ�>
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
			if(mInstance->isFullScreenMode())
				glutLeaveGameMode();
			
			else
				//�I�������Ăяo��
				mInstance->destroy();

			std::exit(0);
		}
	}while(gsFrameTimerIsSkip() == GS_TRUE);
	//�`�揈�����Ăяo��
	glutPostRedisplay();
}
/**========================================================*/
/**
 *	@brief	�`�掞�R�[���o�b�N�֐�
 *	@author	<��Җ�>
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
 *	@author	<��Җ�>
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
 *	@author	<��Җ�>
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
 *	@author	<��Җ�>
 *	@return	�E�B���h�E�^�C�g��
 */
/**========================================================*/
const std::string& GameApplication::getWindowTitle()const{
	return mWindowTitle;
}
/**========================================================*/
/**
 *	@brief	�E�B���h�E��X���W�擾
 *	@author	<��Җ�>
 *	@return	x���W
 */
/**========================================================*/
int GameApplication::getWindowPositionX()const{
	return mWindowPositionX;
}
/**========================================================*/
/**
 *	@brief	�E�B���h�E��Y���W�擾
 *	@author	<��Җ�>
 *	@return	Y���W
 */
/**========================================================*/
int GameApplication::getWindowPositionY()const{
	return mWindowPositionY;
}
/**========================================================*/
/**
 *	@brief	�E�B���h�E�̕��擾
 *	@author	<��Җ�>
 *	@return	��
 */
/**========================================================*/
int GameApplication::getWindowWidth()const{
	return mWindowWidth;
}
/**========================================================*/
/**
 *	@brief	�E�B���h�E�̍����擾
 *	@author	<��Җ�>
 *	@return	����
 */
/**========================================================*/
int GameApplication::getWindowHeight()const{
	return mWindowHwight;
}
/**========================================================*/
/**
 *	@brief	����p�擾
 *	@author	<��Җ�>
 *	@return	����p
 */
/**========================================================*/
float GameApplication::getPerspectiveFov()const{
	return mPerspectiveFov;
}
/**========================================================*/
/**
 *	@brief	�߃N���b�v�ʎ擾
 *	@author	<��Җ�>
 *	@return	�߃N���b�v��
 */
/**========================================================*/
float GameApplication::getPerspectiveNear()const{
	return mPerspectiveNear;
}
/**========================================================*/
/**
 *	@brief	���N���b�v�ʎ擾
 *	@author	<��Җ�>
 *	@return	���N���b�v��
 */
/**========================================================*/
float GameApplication::getPerspectiveFar()const{
	return mPerspectiveFar;
}








/**===End Of File==========================================*/