/******************************************************************************
* File Name : ShootingApplication.cpp.cpp         Ver : 1.00  Date : 2012-12-13
*
* Description :
*
*		�V���[�e�B���O�A�v���P�[�V���������D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"ShootingApplication.h"
#include"../Utility/Screen.h"
#include"../Scene\Scene.h"
#include"../Scene\GamePlay.h"
#include"../Scene/Title.h"
// �V�F�A�[�h�|�C���^�p�̃C���N���[�h.
#include<algorithm>

/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="argc">�R�}���h���C���I�v�V�����̐��̃|�C���^</param>
/// <param name="argv">�R�}���h���C���I�v�V������\��������̔z��</param>
ShootingApplication::ShootingApplication(int argc,char *argv[]):
	GameApplication( argc, argv )
{
	//��ʂ̃T�C�Y�ݒ�.
	SetWindowWidth( Screen::WIDTH );
	SetWindowHeight( Screen::HEIGHT );

	// �t���X�N���[���ɐݒ肷��.
	//SetFullScreenMode( true );
}

/// <summary>
/// ������.
/// </summary>
void ShootingApplication::Initialize( void )
{
	// �V�[���Ǘ��҂̏�����
	mSceneManager.Initialize();
	mSceneManager.Add( SCENE_TITLE, std::make_shared<Title>() );
	// �Q�[���v���C�V�[����ǉ�����.
	mSceneManager.Add( SCENE_GAMEPLAY, std::make_shared<GamePlay>() );
	// ���݂̃V�[�����^�C�g���V�[���ɕύX����.
	mSceneManager.Change( SCENE_TITLE );
}

/// <summary>
// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void ShootingApplication::Update( float frameTimer )
{
	// �V�[�����X�V����.
	mSceneManager.Update( frameTimer );
}

/// <summary>
// �`��.
/// </summary>
void ShootingApplication::Draw( void )
{
	// �V�[����`�悷��.
	mSceneManager.Draw();
}

/// <summary>
// �I��.
/// </summary>
void ShootingApplication::Finish( void )
{
	mSceneManager.Shutdown();
}

/********** End of File ******************************************************/
