/******************************************************************************
* File Name : Ranking.cpp                         Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�����L���O�V�[���D
*
******************************************************************************/
#include	"Ranking.h"
#include	"../Utility\Screen.h"
#include	"Scene.h"


/// <summary>
/// �R���X�g���N�^.
/// </summary>
Ranking::Ranking()
{	
}

/// <summary>
/// ������.
/// </summary>
void Ranking::Initialize()
{	
}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void Ranking::Update(float frameTimer)
{
	(void)frameTimer;
}

/// <summary>
/// �`��.
/// </summary>
void Ranking::Draw()
{
}

/// <summary>
/// �V�[���̏I������.
/// </summary>
bool Ranking::IsEnd() const
{
	// �V�[�����I�����Ȃ�
	return false;
}

/// <summary>
/// ���̃V�[���Ɉڍs.
/// </summary>
Scene Ranking::Next() const
{
	// �_�~�[�̃V�[����Ԃ�
	return Scene::SCENE_TITLE;
}

/// <summary>
/// �I��.
/// </summary>
void Ranking::Shutdown()
{
}

/********** End of File ******************************************************/
