/******************************************************************************
* File Name : SceneNull.cpp                      Ver : 1.00  Date : 2013-02-06
*
* Description :
*
*		��̃V�[���N���X�D
*
******************************************************************************/
#include	"SceneNull.h"
#include	"Scene.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
SceneNull::SceneNull()
{
}

/// <summary>
/// ������.
/// </summary>
void SceneNull::Initialize()
{
}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void SceneNull::Update(float frameTimer)
{
	//�����𖳌�������
	(void)frameTimer;
}

/// <summary>
/// �`��.
/// </summary>
void SceneNull::Draw()
{
}

/// <summary>
/// �V�[���̏I������.
/// </summary>
bool SceneNull::IsEnd() const
{
	//�V�[�����I�����Ȃ�
	return false;
}

/// <summary>
/// ���̃V�[���Ɉڍs.
/// </summary>
Scene SceneNull::Next() const
{
	//�_�~�[�̃V�[����Ԃ�
	return SCENE_NONE;
}

/// <summary>
/// �I��.
/// </summary>
void SceneNull::Shutdown()
{
}

/********** End of File ******************************************************/
