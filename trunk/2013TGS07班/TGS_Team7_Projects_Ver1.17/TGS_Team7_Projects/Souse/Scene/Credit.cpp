/******************************************************************************
* File Name : Credit.h                           Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�N���W�b�g�V�[���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include	"Credit.h"
#include	"../Utility\Screen.h"
#include	"../Scene\Scene.h"
#include<gslib.h>


/// <summary>
/// �R���X�g���N�^.
/// </summary>
Credit::Credit()
{		 
}

/// <summary>
/// ������.
/// </summary>
void Credit::Initialize()
{	
}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void Credit::Update(float frameTimer)
{
	(void)frameTimer;
}

/// <summary>
/// �`��.
/// </summary>
void Credit::Draw()
{
}

/// <summary>
/// �V�[���̏I������.
/// </summary>
bool Credit::IsEnd() const
{
	// �V�[�����I�����Ȃ�
	return false;
}

/// <summary>
/// ���̃V�[���Ɉڍs.
/// </summary>
Scene Credit::Next() const
{
	// �_�~�[�̃V�[����Ԃ�
	return Scene::SCENE_TITLE;
}

/// <summary>
/// �I��.
/// </summary>
void Credit::Shutdown()
{
}

/********** End of File ******************************************************/
