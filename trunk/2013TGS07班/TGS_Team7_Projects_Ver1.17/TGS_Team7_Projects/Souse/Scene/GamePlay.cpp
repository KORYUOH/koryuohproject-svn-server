/******************************************************************************
* File Name : GamePlay.cpp                       Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�Q�[���v���C�V�[���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include	"GamePlay.h"
#include<gslib.h>
#include	"../Scene\Scene.h"
#include"../Unit/Player.h"
#include"../Unit/Space.h"
#include"../Draw/Renderer.h"
#include"../Input/InputState.h"


/// <summary>
/// �R���X�g���N�^.
/// </summary>
GamePlay::GamePlay():
	mWorld(),
	mFlagManager()
{		 
}

/// <summary>
/// ������.
/// </summary>
void GamePlay::Initialize()
{	
	// �V�[���I���t���O��������.
	mIsEnd = false;

	// ���[���h�̏�����.
	mWorld.Clear();
	// �t���O�Ǘ��҂̏�����.
	mFlagManager.Initialize();

	/*---- �L�����N�^�[�摜ID -----------------------------------------------*/

	// �摜�̓ǂݍ���.
	// �v���C���[�摜�̓ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_UNIT_PLAYER , "Resouse/Player.bmp" , true );
	Renderer::GetInstance()->LoadTexture( TEXTURE_UNIT_PLAYER2 , "Resouse/Player2.bmp" , true );

	/*---- �{�݉摜�̓ǂݍ��� -----------------------------------------------*/

	// �F���摜�̓ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_UNIT_SPACE , "Resouse/Space.bmp" , true );
	// �F���摜�̓ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_UNIT_STAR , "Resouse/Star.bmp" , true );
	// �_��{�݉摜�̓ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_UNIT_FARM , "Resouse/Farm.bmp" , true );
	// �Z��{�݉摜�̓ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_UNIT_HOUSE , "Resouse/House.bmp" , true );
	// �H��{�݉摜�̓ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_UNIT_FACTORY, "Resouse/Factory.bmp" , true );

	/*---- UI�n�摜�̓ǂݍ��� -----------------------------------------------*/

	// �^�C�}�[�摜�̓ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_TIMER, "Resouse/Timer.bmp" ,true );
	// �����摜�̓ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_MONEY, "Resouse/Money.bmp" ,true );
	// �l�މ摜�̓ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_HUMAN, "Resouse/Human.bmp" ,true );
	// �l�ލő�摜�̓ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_HUMAN_MAX, "Resouse/HumanMax.bmp", true );
	// �H���摜�̓ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_FOOD, "Resouse/Food.bmp" ,true );
	// ���x���摜�̓ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_LEVEL, "Resouse/Level.bmp" ,true );
	// �����摜�̓ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_NUMBER, "Resouse/Number.bmp" , true );

	// GUI�̃t���[���摜��ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_FRAME, "Resouse/UIFrame.bmp" );
	// GUI�̃{�^���摜��ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_BUTTON, "Resouse/Button.bmp", true );
	// GUI�̕���{�^���摜��ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_BOTTON_CLOSE, "Resouse/ButtonClose.bmp", true );
	// GUI�̃��x���A�b�v�{�^���摜��ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_BOTTON_LEVEL_UP, "Resouse/ButtonLevelUp.bmp", true );
	// GUI�̏Z��쐬�{�^���摜��ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_BOTTON_HOUSING, "Resouse/ButtonHouse.bmp", true );
	// GUI�̍H��쐬�{�^���摜��ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_BOTTON_FACTORY, "Resouse/ButtonFactory.bmp", true );
	// GUI�̔_��쐬�{�^���摜��ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_BOTTON_FRAM, "Resouse/ButtonFarm.bmp", true );
	// GUI�_�O���t�摜�̓ǂݍ���
	Renderer::GetInstance()->LoadTexture( TEXTURE_GUI_BAR_CHART, "Resouse/BarChart.bmp" );

	/*---- ���̑��摜�̓ǂݍ��� ---------------------------------------------*/

	// �f�o�b�O�摜�̓ǂݍ���.
	Renderer::GetInstance()->LoadTexture( TEXTURE_DEBUG , "Resouse/Debug.bmp" , true ); 

	/*---- �ǂݍ��݂̏I��ID -------------------------------------------------*/



	// Player��ǉ�����
	mWorld.AddPlayer( std::make_shared<Player>( mWorld, mFlagManager, GSvector2(500.0f,100.0f) ) );
	mWorld.Add( UNIT_SPACE, std::make_shared<Space>( mWorld, mFlagManager, GSvector2(0.0f,0.0f), 0.0f ) );
}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void GamePlay::Update( float frameTimer )
{
	// ���E���X�V.
	mWorld.Update( frameTimer );

	if( InputState::GetInstance()->IsReStart() )
	{
		mIsEnd = true;
	}
}

/// <summary>
/// �`��.
/// </summary>
void GamePlay::Draw()
{
	// ���E��`��.
	mWorld.Draw();

	// ���E��UI��`��.
	mWorld.DrawUI();
}

/// <summary>
/// �V�[���̏I������.
/// </summary>
bool GamePlay::IsEnd() const
{
	// �V�[�����I�����Ȃ�
	return mIsEnd;
}

/// <summary>
/// ���̃V�[���Ɉڍs.
/// </summary>
Scene GamePlay::Next() const
{
	// �_�~�[�̃V�[����Ԃ�
	return Scene::SCENE_TITLE;
}

/// <summary>
/// �I��.
/// </summary>
void GamePlay::Shutdown()
{
	mWorld.Clear();

	// �摜�̊J��.
	// �v���C���[�摜�̓ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_UNIT_PLAYER );
	Renderer::GetInstance()->DeleteTexture( TEXTURE_UNIT_PLAYER2 );

	/*---- �{�݉摜�̓ǂݍ��� -----------------------------------------------*/

	// �F���摜�̓ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_UNIT_SPACE );
	// �F���摜�̓ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_UNIT_STAR );
	// �_��{�݉摜�̓ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_UNIT_FARM );
	// �Z��{�݉摜�̓ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_UNIT_HOUSE );
	// �H��{�݉摜�̓ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_UNIT_FACTORY );

	/*---- UI�n�摜�̓ǂݍ��� -----------------------------------------------*/

	// �^�C�}�[�摜�̓ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_TIMER );
	// �����摜�̓ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_MONEY );
	// �l�މ摜�̓ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_HUMAN );
	// �l�ލő�摜�̓ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_HUMAN_MAX );
	// �H���摜�̓ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_FOOD );
	// ���x���摜�̓ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_LEVEL );
	// �����摜�̓ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_NUMBER );

	// GUI�̃t���[���摜��ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_FRAME );
	// GUI�̃{�^���摜��ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_BUTTON );
	// GUI�̕���{�^���摜��ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_BOTTON_CLOSE );
	// GUI�̃��x���A�b�v�{�^���摜��ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_BOTTON_LEVEL_UP );
	// GUI�̏Z��쐬�{�^���摜��ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_BOTTON_HOUSING );
	// GUI�̍H��쐬�{�^���摜��ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_BOTTON_FACTORY );
	// GUI�̔_��쐬�{�^���摜��ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_BOTTON_FRAM );
	// GUI�_�O���t�摜�̓ǂݍ���
	Renderer::GetInstance()->DeleteTexture( TEXTURE_GUI_BAR_CHART );

	/*---- ���̑��摜�̓ǂݍ��� ---------------------------------------------*/

	// �f�o�b�O�摜�̓ǂݍ���.
	Renderer::GetInstance()->DeleteTexture( TEXTURE_DEBUG ); 

}

/********** End of File ******************************************************/
