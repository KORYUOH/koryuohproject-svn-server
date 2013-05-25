/******************************************************************************
* File Name : AnimationTimer.cpp                 Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�A�j���[�V�����^�C�}�[�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"AnimationTimer.h"
#include<gslib.h>

/// <summary>
/// �R���X�g���N�^.
/// </summary>
AnimationTimer::AnimationTimer():
	mMaxTime(0),
	mTimer(0),
	mIsStart(true)
{
}

/// <summary>
/// ������.
/// </summary>
void AnimationTimer::Initialize()
{
	// �ő厞�Ԃ�0.3�b�ɐݒ�.
	mMaxTime = (int)(60 * 0.3f);
	// �^�C����������.
	mTimer = mMaxTime;
	// �X�^�[�g�t���O��������.
	mIsStart = true;
}

/// <summary>
/// �X�V.
/// </summary>
	/// <param name="frameTimer">�t���[�����[�g</param>
void AnimationTimer::Update( float frameTimer )
{
	// �I�����Ă��鎞.
	if( IsStop() )
	{
		// �����I��.
		return;
	}

	//���Ԃ��X�V
	mTimer -= frameTimer;
	mTimer = MAX( 0.0f, mTimer );
}

/// <summary>
/// �^�C�}�[�������Ă��邩����.
/// </summary>
/// <returns>�����Ă���ΐ^�A�����łȂ���΋U��Ԃ�.</returns>
bool AnimationTimer::IsStop()
{
	// �X�^�[�g�t���O�������Ȃ̂��H.
	return ( mIsStart == false );
}

/// <summary>
/// �ő厞�ԂŃ��Z�b�g����.
/// </summary>
void AnimationTimer::Reset()
{
	// ���Ԃ����Z�b�g.
	mTimer = mMaxTime;
}

/// <summary>
/// �^�C�}�[���[������.
/// </summary>
/// <returns>�^�C�}�[���[���̎��^�A�����łȂ���΋U��Ԃ�.</returns>
bool AnimationTimer::IsZero()
{
	return mTimer <= 0.0f;
}

/// <summary>
/// �^�C�}�[�J�n����.
/// </summary>
void AnimationTimer::Start()
{
	// �X�^�[�g�t���O��L���ɂ���.
	mIsStart = true;
}

/// <summary>
/// �}�b�N�X�^�C���ŕb��ݒ�.
/// </summary>
/// <param name="time">�ő厞��</param>
void AnimationTimer::SetMaxTime(float time)
{
	mMaxTime = (int)(60 * time);
}

/********** End of File ******************************************************/