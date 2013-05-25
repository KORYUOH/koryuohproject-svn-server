/******************************************************************************
* File Name : Space.cpp                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�F���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Space.h"
#include"../World/IWorld.h"
#include"../Draw/Renderer.h"
#include"../Input/InputState.h"
#include"../Unit/Star.h"
#include"../Utility/Screen.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="world">���[���h</param>
/// <param name="flag">�t���O�Ǘ���</param>
///	 <param name="position">�������W</param>
/// <param name="radius">�Փ˔���p�̔��a</param>
Space::Space( IWorld& world, IFlagManager& flag, const GSvector2& position, float radius ):
	Unit( world, flag, NULL , UNIT_SPACE, position, radius ),
	mManey( 0.0f ),
	mNumber( TEXTURE_GUI_NUMBER, 16, 32 ) 
{
	/// �����̎�����ݒ�.
	mManey = 10000;

	// ����ǉ�.
	AddUnit( UNIT_STAR , std::make_shared<Star>( mWorld, mFlags, &*this, GSvector2(Screen::WIDTH*0.5f,Screen::HEIGHT*0.5f) ) );
}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void Space::Update( float frameTimer ) 
{
	(void)frameTimer;
}

/// <summary>
/// ���Y����.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void Space::Production( float frameTimer )
{
	(void)frameTimer;
}

/// <summary>
/// �ێ��R�X�g�x��������.
/// </summary>
/// <param name="frameTimer">�t���[���^�C�}�[</param>
void Space::Maintenance( float frameTimer )
{
	(void)frameTimer;
}

/// <summary>
/// �`��.
/// </summary>
void Space::Draw()
{
	Renderer::GetInstance()->DrawTexture( TEXTURE_UNIT_SPACE );
}

/// <summary>
/// UI�̕`��.
/// </summary>
void Space::DrawUI()
{
	const GSvector2 center( 256.0f , 0.0f );

	Renderer::GetInstance()->DrawTexture( TEXTURE_GUI_MONEY, center  );
	mNumber.Draw( center+GSvector2(64.0f,0.0f), (int)mManey );
}

/// <summary>
/// �����ւ̃A�N�Z�X.
/// </summary>
/// <param name="money">�����̑�����</param>
/// <returns>����ɃA�N�Z�X�ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
bool Space::AccessMoney( float money )
{
	// �������v�Z����.
	float rezultMoney = mManey + money;

	// �������[���ȉ��ɂȂ�����.
	if( rezultMoney < 0.0f )
	{
		return false;
	}
	// �[���łȂ����A���ʂ𔽉f����.
	mManey = rezultMoney;

	return true;
}



/********** End of File ******************************************************/
