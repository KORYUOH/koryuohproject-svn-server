/******************************************************************************
* File Name : Title.h                           Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�^�C�g���V�[���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include	"Title.h"
#include	"../Utility\Screen.h"
#include	"../Scene\Scene.h"
#include<gslib.h>
#include"../Input/InputState.h"
#include"../Draw/Renderer.h"


/// <summary>
/// �R���X�g���N�^.
/// </summary>
Title::Title()
{		 
}

/// <summary>
/// ������.
/// </summary>
void Title::Initialize()
{	
	mIsEnd = false;

	// �^�C�g���摜�̓ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_SCENE_TITLE, "Resouse/Title.bmp" );
}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void Title::Update(float frameTimer)
{
	(void)frameTimer;

	if( InputState::GetInstance()->IsReStart() )
	{
		mIsEnd = true;
	}
}

/// <summary>
/// �`��.
/// </summary>
void Title::Draw()
{
	Renderer::GetInstance()->DrawTexture( TEXTURE_SCENE_TITLE );
}

/// <summary>
/// �V�[���̏I������.
/// </summary>
bool Title::IsEnd() const
{
	// �V�[�����I�����Ȃ�
	return mIsEnd;
}

/// <summary>
/// ���̃V�[���Ɉڍs.
/// </summary>
Scene Title::Next() const
{
	// �_�~�[�̃V�[����Ԃ�
	return Scene::SCENE_GAMEPLAY;
}

/// <summary>
/// �I��.
/// </summary>
void Title::Shutdown()
{
	// �^�C�g���摜�̓ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_SCENE_TITLE );
}

/********** End of File ******************************************************/
