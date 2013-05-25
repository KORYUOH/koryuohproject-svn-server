/******************************************************************************
* File Name : GameApplication.cpp                Ver : 1.00  Date : 2012-12-13
*
* Description :
*
*		�Q�[���A�v���P�[�V���������D
*
******************************************************************************/
#include"GameApplication.h"
#include<gslib.h>
#include<sstream>

// �R�[���o�b�N�֐��̂��߂̐ÓI�����o�ϐ�.
GameApplication* GameApplication::mInstance = 0;


/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="argc">�R�}���h���C���I�v�V�����̐��̃|�C���^</param>
/// <param name="argv">�R�}���h���C���I�v�V������\��������̔z��</param>
GameApplication::GameApplication(int argc,char* argv[] ):
	mWindowTitle("GameWindow"),
	mWindowPositionX(0),
	mWindowPositionY(0),
	mWindowWidth(1024),
	mWindowHeight(768),
	mIsFullScreenMode(false),
	mPerspectiveFov(50.0f),
	mPerspectiveNear(0.0f),
	mPerspectiveFar(100.0f)
{
	// �������g�̃C���X�^���X��ݒ�.
	mInstance = this;

	// GLUT�̏�����.
	glutInit( &argc,argv);

}

/// <summary>
/// �A�v���P�[�V�����̎��s.
/// </summary>
void GameApplication::Run()
{
	// �E�C���h�E�̐ݒ���s��.
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
	glutInitWindowPosition(GetWindowPositionX(),GetWindowPositionY() );
	glutInitWindowSize( GetWindowWidth(),GetWindowHeight() );

	// �t���X�N���[�����[�h���H.
	if(IsFullScreenMode() == true)
	{
		std::ostringstream mode;

		// �t���X�N���[�����[�h�ݒ蕶������쐬.
		mode << GetWindowWidth() << "X" << GetWindowHeight() << "@60";

		// �t���X�N���[�����[�h�ɐݒ�.
		glutGameModeString( mode.str().c_str() );
		glutEnterGameMode();

		// �t���X�N���[���̏ꍇ�̓}�E�X�J�[�\��������.
		glutSetCursor( GLUT_CURSOR_NONE );

	}
	else
	{
		// �E�C���h�E���[�h.
		glutCreateWindow( GetWindowTitle().c_str() );
	}
	// �O���t�B�b�N�V�X�e���̏�����.
	gsInitGraphics();

	// �T�E���h�V�X�e���̏�����.
	gsInitSound( (HWND)_glutGetHWND() );

	// ���̓f�o�C�X�V�X�e���̏�����.
	gsInitInput( (HWND)_glutGetHWND() );

	// Vsync��L���ɂ���.
	SetSwapInterval( 1 );

	// �����̏�����.
	gsRandamize();

	// OpenGL�̏�����.
	InitilaizeGL();

	// �A�v���P�[�V�����̏���������.
	Initialize();

	// �I�������̊֐���ݒ肷��.
	_glutDestroyFunc( Destroy );

	// �E�B���h�E�T�C�Y�ύX���̊֐���ݒ�.
	glutReshapeFunc( Reshape );

	// �\�������̊֐���ݒ�.
	glutDisplayFunc( Display );

	// �C�x���g�̂Ȃ����̊֐���ݒ�.
	glutIdleFunc( Idle );

	// �E�B���h�E���A�N�e�B�u�ɂȂ������̊֐���ݒ�.
	_glutActivateFunc( Activate );

	// �t���[���^�C�}�̃��Z�b�g.
	gsFrameTimerReset();

	// ���C�����[�v�������s��.
	glutMainLoop();

}

/// <summary>
/// OpenGL�̏�����.
/// </summary>
void GameApplication::InitilaizeGL( void )
{
	// �f�t�H���g�̃��C�g�p�����[�^.
	const static float LightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	const static float LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const static float LightSpeclar[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const static float LightPosition[] = { 1.0f, 1.0f, 1.0f, 0.0f };

	// ��ʃN���A���̃J���[�̐ݒ�.
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

	// �ʃJ�����O�̏�����L���ɂ���.
	glEnable( GL_CULL_FACE );
	glCullFace( GL_BACK );

	// �f�v�X�o�b�t�@��1.0�ŃN���A����.
	glClearDepth( 1.0 );

	// �e�v�X�e�X�g��L���ɂ���.
	glEnable( GL_DEPTH_TEST );

	// �p�[�X�y�N�e�B�u�␳���s��.
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

	// �u�����h��L��.
	glEnable( GL_BLEND );

	// �f�t�H���g�̃u�����h����ݒ�.
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	// �f�t�H���g�̎��_�ϊ��̕ϊ��s���ݒ肷��.
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	gluLookAt(
		0.0f, 0.0f, 10.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f
		);

	// �f�t�H���g�̃��C�g�̐ݒ�.
	glLightfv( GL_LIGHT0, GL_AMBIENT, LightAmbient );
	glLightfv( GL_LIGHT0, GL_DIFFUSE, LightDiffuse );
	glLightfv( GL_LIGHT0, GL_SPECULAR, LightSpeclar );
	glLightfv( GL_LIGHT0, GL_POSITION, LightPosition );
	glEnable( GL_LIGHT0 );

	// ���C�e�B���O��L���ɂ���.
	glEnable( GL_LIGHTING );

}

/// <summary>
//�A�v���P�[�V�����I�����R�[���o�b�N�֐�.
/// </summary>
void GameApplication::Destroy( void )
{

	// �Q�[���I������.
	mInstance->Finish();

	// ���̓f�o�C�X�V�X�e���̏I������.
	gsFinishInput();

	// �T�E���h�V�X�e���̏I������.
	gsFinishSound();

	// �O���t�B�b�N�X�V�X�e���̏I������.
	gsFinishGraphics();

}

/// <summary>
//�E�C���h�E�T�C�Y�R�[���o�b�N�֐�.
/// </summary>
/// <param name="width">�c��</param>
/// <param name="height">����</param>
void GameApplication::Reshape( int width, int height )
{
	// �������O�ɂȂ�Ȃ��悤�ɒ���.
	height = ( height == 0 ) ? 1: height;

	// �r���[�|�[�g�̐ݒ�.
	glViewport( 0, 0, width, height );

	// �����ˉe�̕ϊ��s���ݒ肷��.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective(
		mInstance->GetPerspectiveFov(),
		(float)width / (float)height,
		mInstance->GetPerspectiveNear(),
		mInstance->GetPerspectiveFar()
		);

	// ���f���r���[���[�h�ɂ���.
	glMatrixMode( GL_MODELVIEW );

	// �E�B���h�E�̕��ƍ������X�V����.
	mInstance->SetWindowWidth( width );
	mInstance->SetWindowHeight( height );

}

/// <summary>
//�C�x���g�������̃R�[���o�b�N�֐�.
/// </summary>
void GameApplication::Idle( void )
{
	// �t���[���^�C�}�̍X�V.
	gsFrameTimerUpdate();
	do {
		// ���̓f�o�C�X�̓ǂݍ���.
		gsReadInput();

		// �Q�[���X�V����.
		mInstance->Update( gsFrameTimerGetTime() );

		// �G�X�P�[�v�L�[�������ꂽ���H.
		if ( GetAsyncKeyState( VK_ESCAPE ) != 0 ) 
		{
			if ( mInstance->IsFullScreenMode() == true )
			{

				// �Q�[�����[�h���I������.
				glutLeaveGameMode();
			}
			else 
			{

				// �I���������Ăяo��.
				mInstance->Destroy();
			}

			// �����I������.
			std::exit( 0 );
		}
	} while ( gsFrameTimerIsSkip() == GS_TRUE );

	// �`�揈�����Ăяo��.
	glutPostRedisplay();
}

/// <summary>
/// �E�C���h�E�`�掞�̃R�[���o�b�N�֐�.
/// </summary>
void GameApplication::Display( void )
{

	// ��ʃN���A.
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	// �Q�[���`�揈��.
	mInstance->Draw();

	// �_�u���o�b�t�@�̐؂�ւ�.
	glutSwapBuffers();

	// �^�C�}�E�F�C�g���s��.
	gsFrameTimerWait();

}

/// <summary>
/// �E�C���h�E���A�N�e�B�u���̃R�[���o�b�N�֐�.
/// </summary>
void GameApplication::Activate( int state )
{

	// ���̓f�o�C�X�V�X�e���ɃA�N�e�B�u��Ԃ�`����.
	gsActivateInput(state);

	// �T�E���h�V�X�e���ɃA�N�e�B�u��Ԃ�`����.
	gsActivateSound(state);

}

/// <summary>
/// �_�u���o�b�t�@�ؑ֎��̃C���^�[�o���^�C�}�̐ݒ�.
/// </summary>
/// <param name="interval">�C���^�[�o��</param>
void GameApplication::SetSwapInterval( int interval )
{
	// wglSwapIntervalEXT�g���֐��̃|�C���^�֐��^.
	typedef BOOL (WINAPI * LPFNWGLSWAPINTERVALEXTPROC)( int interval );
	LPFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = NULL;

	// SwapIntervalEXT�̊֐��|�C���^���擾.
	wglSwapIntervalEXT = (LPFNWGLSWAPINTERVALEXTPROC)
		wglGetProcAddress( "wglSwapIntervalEXT" );

	// SwapIntervalEXT�֐����擾�ł������H.
	if ( wglSwapIntervalEXT != NULL )
	{

		// �X���b�v�̃C���^�[�o����ݒ�.
		wglSwapIntervalEXT( interval );

	}
}

/// <summary>
/// �E�C���h�E�^�C�g���擾.
/// </summary>
/// <returns>�E�C���h�E������</returns>
const std::string& GameApplication::GetWindowTitle() const
{
	return mWindowTitle;
}

/// <summary>
/// �E�C���h�EX���W���擾.
/// </summary>
/// <returns>�E�C���h�E��X���W</returns>
int GameApplication::GetWindowPositionX() const
{
	return mWindowPositionX;
}

/// <summary>
/// �E�C���h�EY���W���擾.
/// </summary>
/// <returns>�E�C���h�E��X���W</returns>
int GameApplication::GetWindowPositionY() const
{
	return mWindowPositionY;
}

/// <summary>
/// �E�C���h�E�����擾.
/// </summary>
/// <returns>�E�C���h�E��X���W</returns>
int GameApplication::GetWindowWidth() const
{
	return mWindowWidth;
}

/// <summary>
/// �E�C���h�E�������擾.
/// </summary>
/// <returns>�E�C���h�E��X���W</returns>
int GameApplication::GetWindowHeight() const
{
	return mWindowHeight;
}

/// <summary>
/// ����p���擾.
/// </summary>
/// <returns>����p�l</returns>
float GameApplication::GetPerspectiveFov() const
{
	return mPerspectiveFov;
}

/// <summary>
/// �߃N���b�v�ʂ��擾.
/// </summary>
/// <returns>�߃N���b�v�l</returns>
float GameApplication::GetPerspectiveNear() const
{
	return mPerspectiveNear;
}

/// <summary>
/// ���N���b�v�ʂ��擾.
/// </summary>
/// <returns>���N���b�v�l</returns>
float GameApplication::GetPerspectiveFar() const
{
	return mPerspectiveFar;
}

/// <summary>
/// �E�C���h�E�^�C�g���ݒ�.
/// </summary>
/// <param name="title">�E�C���h�E������</param>
void GameApplication::SetWindowTitle( const std::string& title )
{
	mWindowTitle = title;
}

/// <summary>
/// �E�C���h�EX���W��ݒ�.
/// </summary>
/// <param name="x">X���W</param>
void GameApplication::SetWindowPositionX( int x )
{
	mWindowPositionX = x;
}

/// <summary>
/// �E�C���h�EY���W��ݒ�.
/// </summary>
/// <param name="y">Y���W</param>
void GameApplication::SetWindowPositionY( int y )
{
	mWindowPositionY = y;
}

/// <summary>
/// �E�C���h�E�����ݒ�.
/// </summary>
/// <param name="width">����</param>
void GameApplication::SetWindowWidth( int width )
{
	mWindowWidth = width;

}

/// <summary>
/// �E�C���h�E�c���ݒ�.
/// </summary>
/// <param name="height">�c��</param>
void GameApplication::SetWindowHeight( int height )
{
	mWindowHeight = height;
}

/// <summary>
/// ����p�ݒ�.
/// </summary>
/// <param name="fov">����p�l</param>
void GameApplication::SetPerspectiveFov( float fov )
{
	mPerspectiveFov = fov;
}

/// <summary>
/// �߃N���b�v�ʂ�ݒ�.
/// </summary>
/// <param name="znear">�߃N���b�v�l</param>
void GameApplication::SetPerspectiveNear( float znear )
{
	mPerspectiveNear = znear;
}

/// <summary>
/// ���N���b�v�ʂ�ݒ�.
/// </summary>
/// <param name="zfar">���N���b�v�l</param>
void GameApplication::SetPerspectiveFar( float zfar )
{
	mPerspectiveFar = zfar;
}

/// <summary>
/// �t���X�N���[�����[�h�ݒ�.
/// </summary>
/// <param name="mode">���[�h</param>
void GameApplication::SetFullScreenMode( bool mode )
{
	mIsFullScreenMode = mode;
}

/// <summary>
/// �t���X�N���[�����[�h�����ׂ�.
/// </summary>
/// <returns>�t���X�N���[���̎��^�A�����łȂ����U��Ԃ�.</returns>
bool GameApplication::IsFullScreenMode( void )
{
	return mIsFullScreenMode;
}

/********** End of File ******************************************************/
