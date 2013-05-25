/******************************************************************************
* File Name : UIFrame.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		���[�U�[�C���^�[�t�F�[�X�t���[���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"GUIManager.h"
#include"GUIFrame.h"
#include<algorithm>

/// <summary>
/// �R���X�g���N�^.
/// </summary>
GUIManager::GUIManager() : 
	mPlayerGUI( NULL )
{
	// ����������.
	mGUIColliderContainer.clear();
}

/// <summary>
/// �`��.
/// </summary>
void GUIManager::Draw() const
{
	// ���ׂĂ�UI��`�悷��.
	std::for_each( mGUIColliderContainer.begin(), mGUIColliderContainer.end(), []( GUIFramePtr gui )
	{
		// GUI��`�悷��.
		gui->Draw();
	});

	// �Փ˂��s��Ȃ�GUI��`�悷��.
	std::for_each( mGUIContainer.begin(), mGUIContainer.end(), []( GUIFramePtr frame )
	{
		frame->Draw();
	});

	// �v���C���[���ݒ肳��Ă��鎞.
	if( mPlayerGUI != NULL )
	{
		//�v���C���[��GUI��`��.
		mPlayerGUI->Draw();
	}
}

/// <summary>
/// �R�}���h���擾.
/// </summary>
/// <returns>�R�}���h��Ԃ�.</returns>
GUICommand GUIManager::GetCommand() const
{
	// �R�}���h���擾.
	GUICommand command = GUI_COMMAND_FALSE;

	//for( GUIFrameContainer::iterator gui = mGUIs.begin() ; gui != mGUIs.end() ; gui++ )
	//{
	//	command = gui->get()->GetCommand();

	//	// �R�}���h���U�łȂ���,
	//	if( command != GUI_COMMAND_FALSE )
	//	{
	//		return command;
	//	}
	//}

	// �R�}���h��Ԃ�.
	return GUI_COMMAND_FALSE;
}

/// <summary>
/// GUI��ǉ�����.
/// </summary>
/// <param name="gui">�ǉ�����GUI</param>
void GUIManager::Add( GUIFramePtr gui )
{
	// UI��ǉ�����.
	mGUIColliderContainer.push_back( gui );
}

/// <summary>
/// �v���C���[GUI��ǉ�����.
/// </summary>
/// <param name="gui">�ǉ�����GUI</param>
void GUIManager::AddPlayer( GUIFramePtr gui )
{
	mPlayerGUI = gui;
}

/// <summary>
/// UI���폜����.
/// </summary>
/// <param name="addUI">�폜����UI</param>
void GUIManager::Delete( GUIFramePtr gui )
{
	// GUI���폜����.
	mGUIColliderContainer.remove( gui );
}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[�����[�g</param>
void GUIManager::Update( float frameTimer )
{
	// ���ׂĂ�UI��`�悷��.
	std::for_each( mGUIColliderContainer.begin(), mGUIColliderContainer.end(), [&]( GUIFramePtr gui )
	{
		// GUI���X�V����.
		gui->Update( frameTimer );
	});

	// �v���C���[GUI�����݂��Ă��鎞.
	if( mPlayerGUI != NULL )
	{
		// �v���C���[GUI���X�V����.
		mPlayerGUI->Update( frameTimer );

		// �v���C���[�Ƒ���GUI���Փ˂�����.
		Collision( mPlayerGUI );

	}

}

/// <summary>
/// �Փ˔���.
/// </summary>
/// <param name="other">�Փˏ��</param>
void GUIManager::Collision( GUIFramePtr other )
{
	for( GUIFrameContainer::iterator gui = mGUIColliderContainer.begin() ; gui != mGUIColliderContainer.end() ; gui++ )
	{
		// �Փˏ������s��.
		gui->get()->CollisionUpdate( *other );
	}
}

/// <summary>
/// ����.
/// </summary>
void GUIManager::Clear()
{
	mGUIColliderContainer.clear();
	mGUIContainer.clear();
	mPlayerGUI = NULL;
}

/********** End of File ******************************************************/
