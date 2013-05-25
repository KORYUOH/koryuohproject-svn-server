/******************************************************************************
* File Name : SceneManager.h                     Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�V�[���Ǘ��N���X�D
*
******************************************************************************/
#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<map>
#include<memory>

/*---- ��s�錾 -------------------------------------------------------------*/

enum Scene;
class IScene;

/*---- �N���X�錾 -----------------------------------------------------------*/

/// <summary>
/// �V�[���Ǘ��҃N���X.
/// </summary>
class SceneManager
{
private:
	// �^�̒u������.
	typedef std::shared_ptr<IScene> IScenePtr;
	typedef std::map<Scene,IScenePtr> SceneContainer;


public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	SceneManager();
	/// <summary>
	/// ������.
	/// </summary>
	void Initialize();
	/// <summary>
	/// �X�V.
	/// </summary>
	/// <param name="frameTimer">�t���[���^�C�}�[</param>
	void Update(float frameTimer);
	/// <summary>
	/// �`��.
	/// </summary>
	void Draw(); 
	/// <summary>
	/// �I��.
	/// </summary>
	void Shutdown();
	/// <summary>
	/// �V�[���̒ǉ�.
	/// </summary>
	/// <param name="name">�o�^����̃V�[����</param>
	/// <param name="scene">�o�^����̃V�[�����</param>
	void Add ( Scene name, IScene* scene);
	/// <summary>
	/// �V�[���̒ǉ�.
	/// </summary>
	/// <param name="name">�o�^����̃V�[����</param>
	/// <param name="scene">�o�^����̃V�[�����</param>
	void Add ( Scene name, IScenePtr scene);
	/// <summary>
	/// �V�[���̕ύX.
	/// </summary>
	/// <param name="name">���̃V�[����</param>
	void Change(Scene name);

private:
	SceneManager(const SceneManager& other);
	SceneManager& operator = (const SceneManager& other);

private:
	/// <summary>
	/// �V�[���R���e�i.
	/// </summary>
	SceneContainer scenes;
	/// <summary>
	/// ���݂̃V�[��.
	/// </summary>
	IScenePtr currentScene;
};

#endif

/********** End of File ******************************************************/
