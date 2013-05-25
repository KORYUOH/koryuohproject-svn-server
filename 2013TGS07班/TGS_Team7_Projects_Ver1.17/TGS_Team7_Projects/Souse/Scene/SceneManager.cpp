/******************************************************************************
* File Name : SceneManager.cpp                   Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�V�[���Ǘ��N���X�D
*
******************************************************************************/
#include"SceneManager.h"
#include"IScene.h"
#include"SceneNull.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
SceneManager::SceneManager():
	currentScene( std::make_shared<SceneNull>() )
{
}

/// <summary>
/// �V�[���̒ǉ�.
/// </summary>
/// <param name="name">�o�^����̃V�[����</param>
/// <param name="scene">�o�^����̃V�[�����</param>
void SceneManager::Add( Scene name, IScene* scene)
{
	//�����ł�������V�[����ǉ�����
	scenes[name] = IScenePtr(scene);

}

/// <summary>
/// �V�[���̒ǉ�.
/// </summary>
/// <param name="name">�o�^����̃V�[����</param>
/// <param name="scene">�o�^����̃V�[�����</param>
void SceneManager::Add( Scene name, IScenePtr scene)
{
	scenes[name] = scene;
}

/// <summary>
/// ������.
/// </summary>
void SceneManager::Initialize()
{
	Shutdown();
	// �V�[���̗v�f����ɂ���
	scenes.clear();
}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void SceneManager::Update(float frameTimer)
{

	// ���݂̃V�[�����X�V����
	currentScene->Update(frameTimer);

	// ���݂̃V�[�����I�����Ă��邩�H
	if( currentScene->IsEnd() == true )
	{
		// ���̃V�[���ɕύX����
		Change( currentScene->Next() );
	}

}

/// <summary>
/// �`��.
/// </summary>
void SceneManager::Draw()
{

	// ���݂̃V�[����`�悷��
	currentScene->Draw();

}

/// <summary>
/// �V�[���̕ύX
/// </summary>
/// <param name="name">���̃V�[����</param>
void SceneManager::Change(Scene name)
{
	// ���݂̃V�[�����I������
	Shutdown();
	// ���݂̃V�[���������̃V�[���ɕύX����
	currentScene = scenes[name];
	// ���݂̃V�[��������������
	currentScene->Initialize();

}

/// <summary>
/// �I��.
/// </summary>
void SceneManager::Shutdown()
{
	// ���݂̃V�[�����I������
	currentScene->Shutdown();
	// ���݂̃V�[�����k���|�C���^������
	currentScene = std::make_shared<SceneNull>();
}

/********** End of File ******************************************************/
