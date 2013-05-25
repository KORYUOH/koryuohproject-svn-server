/******************************************************************************
* File Name : World.cpp                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		���[���h�N���X�D
*
******************************************************************************/
#include	"World.h"
#include	<cassert>
#include	"../Unit/UnitID.h"
#include	"../Unit/UnitPtr.h"
#include	"../GUI/GUIFrame.h"
#include	"../Input/InputState.h"

#pragma region "�R���X�g���N�^."


/// <summary>
/// �R���X�g���N�^.
/// </summary>
World ::World():
	mUnits(),
	mPlayer(),
	mGUIManager(),
	mCamera(),
	mTimer(),
	mParameter()
{
	// ���[���h�A�N�^�[�̏�����.
	Clear();

	// �^�C�}�[�̏�����.
	mTimer.Initialize( 60.0f );
	// �p�����[�^�̓ǂݍ���.
	mParameter.Initialize();
}


/// <summary>
/// �f�X�g���N�^.
/// </summary>
World ::~World()
{
	// ���[���h�A�N�^�[�̏���.
	Clear();
}

#pragma endregion


#pragma region "���ۂł��Ăяo���鏈��."



/// <summary>
/// �A�N�^�[�̒ǉ�.
/// </summary>
/// <param name="id">�A�N�^�[�}�l�[�W��ID</param>
/// <param name="actor">�ǉ�����A�N�^�[</param>
void World::Add( UnitID id,UnitPtr actor )
{
	mUnits.Add(id,actor);
}

/// <summary>
/// �v���C���[�̐���.
/// </summary>
/// <param name="actor">�ǉ�����v���C���[�A�N�^�[</param>
void World::AddPlayer( UnitPtr actor )
{
	assert( mPlayer == nullptr );
	mPlayer = actor;
	Add( UNIT_PLAYER, mPlayer );
}

/// <summary>
/// �I�u�W�F�N�g�̒ǉ�.
/// </summary>
/// <param name="object">�ǉ�����A�N�^�[�I�u�W�F�N�g</param>
void World::AddObject( UnitPtr object )
{
	// �I�u�W�F�N�g��ǉ�.
	Add( UNIT_NONE, object );
}

/// <summary>
/// �v���C���[�̎擾.
/// </summary>
/// <returns>�v���C���[�A�N�^�[���擾</returns>
UnitPtr World::GetPlayer()const
{
	//�v���C���[��Ԃ�
	return mPlayer;
}

/// <summary>
/// �J�������擾.
/// </summary>
/// <returns>�J������Ԃ�</returns>
const Camera& World::GetCamera() const
{
	return mCamera;
}

/// <summary>
/// �^�C�}�[���擾.
/// </summary>
/// <returns>�^�C�}�[��Ԃ�</returns>
const Timer& World::GetTimer() const
{
	return mTimer;
}

/// <summary>
/// �p�����[�^���擾.
/// </summary>
/// <returns>�p�����[�^��Ԃ�.</returns>
const UnitParameter& World::GetParameter() const
{
	return mParameter;
}

/// <summary>
/// GUI��o�^����.
/// </summary>
/// <param name="gui">�ǉ�����GUI</param>
void World::AddGUI( GUIFramePtr gui )
{
	mGUIManager.Add( gui );
}

/// <summary>
/// �v���C���[��GUI��o�^����.
/// </summary>
/// <param name="gui">�ǉ�����GUI</param>
void World::AddPlayerGUI( GUIFramePtr gui )
{
	mGUIManager.AddPlayer( gui );
}

/// <summary>
/// GUI��o�^����͂���.
/// </summary>
/// <param name="gui">�폜����GUI</param>
void World::DeleteGUI( GUIFramePtr gui )
{
	mGUIManager.Delete( gui );
}

/// <summary>
/// GUI�R�}���h���擾����.
/// <para>�}�E�X�̍��N���b�N��������Ă��鎞���s����܂�.</para>
/// </summary>
/// <returns>�R�}���h��Ԃ�.</returns>
GUICommand World::GetGUICommand() const
{
	// �}�E�X��������Ă��鎞���s.
	if( InputState::GetInstance()->IsEnterButton() )
	{
		// GUI�Ǘ��҂���R�}���h���擾.
		return mGUIManager.GetCommand();
	}

	// �擾�ł��Ȃ��̂ŁAFALSE�R�}���h��Ԃ�.
	return GUI_COMMAND_FALSE;
}

#pragma endregion


#pragma region "���ۂł͌Ăяo���Ȃ�����."

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[�����[�g</param>
void World::Update( float frameTimer )
{

	// �^�C�}�[���X�V.
	mTimer.Update( frameTimer );

	// �A�N�^�[���X�V.
	mUnits.Update( frameTimer );


	// ���Y����.
	mUnits.Production( frameTimer );
	// ����R�X�g����.
	mUnits.Maintenance( frameTimer );


	// GUI���X�V����.
	mGUIManager.Update( frameTimer );

}

/// <summary>
/// �`��.
/// </summary>
void World::Draw()
{
	// ���j�b�g�̕`��.
	mUnits.Draw();
}

/// <summary>
/// UI�̕`��.
/// </summary>
void World::DrawUI()
{
	// �^�C�}�[�̕`��.
	mTimer.Draw();

	// ���j�b�g��UI��`��.
	mUnits.DrawUI();

	mGUIManager.Draw();
}

/// <summary>
/// ����.
/// </summary>
void World::Clear()
{
	// ���ׂẴA�N�^�[�}�l�[�W���[������.
	mUnits.Clear();
	// �v���C���[��null�ɐݒ�.
	mPlayer = nullptr;
	// GUI�̏���.
	mGUIManager.Clear();
	// �^�C�}�[��������.
	mTimer.Initialize( 60.0f );

}


#pragma endregion


/********** End of File ******************************************************/