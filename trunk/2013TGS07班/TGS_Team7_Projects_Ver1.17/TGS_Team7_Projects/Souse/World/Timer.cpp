/******************************************************************************
* File Name : Timer.cpp                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�^�C�}�[�����D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Timer.h"
#include<gslib.h>
#include"../Draw/TextureID.h"
#include"../Draw/Renderer.h"
#include"../Utility/Screen.h"

/// <summary>
/// �������Ԓ萔.
/// </summary>
const int Timer::TIME_LIMIT = 180;

/// <summary>
/// �t���[�����[�g.
/// </summary>
const int Timer::FRAME_RATE = 60;


/// <summary>
//�R���X�g���N�^
/// <summary>
Timer::Timer():
	mTime( 0.0f ),
	mNumber( TEXTURE_GUI_NUMBER, 16, 32 )
{
	// �\��������ݒ�.
	mNumber.SetField( 4 );
}

/// <summary>
//������
/// </summary>
/// <param name="limitTime">��������</param>
void Timer::Initialize( float limitTime )
{
	mTime = limitTime * FRAME_RATE;
}

/// <summary>
//�X�V.
/// </summary>
/// <param name="frameTimer">�t���[�����[�g</param>
void Timer::Update( float frameTimer)
{
	mTime -= 1.0f * frameTimer;
	mTime = MAX( mTime , 0.0f ); 
}

/// <summary>
/// ���Ԃ��擾(�t���[�����ԂŎ擾)
/// </summary>
/// <returns>����(fps)��Ԃ�.</returns>
float Timer::GetTimerF() const
{
	return mTime;
}

/// <summary>
/// ���Ԃ��擾(�b���Ŏ擾)
/// </summary>
/// <returns>����(s)��Ԃ�.</returns>
float Timer::GetTimerS() const
{
	return mTime / FRAME_RATE;
}

/// <summary>
/// ���Ԑ؂ꔻ��
/// </summary>
/// <returns>���Ԑ؂�̎��ɐ^�A�����łȂ���΋U��Ԃ�.</returns>
bool Timer::isTimeOver() const
{
	return mTime <= 0.0f;
}

/// <summary>
/// �`��.
/// </summary>
void Timer::Draw()
{
	Renderer::GetInstance()->DrawTexture( TEXTURE_GUI_TIMER, GSvector2(Screen::WIDTH,0.0f) );
	mNumber.Draw( GSvector2(Screen::WIDTH*0.5f,15.0f), (int)GetTimerS() );
}

/********** End of File ******************************************************/