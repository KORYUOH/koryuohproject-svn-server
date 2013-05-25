/******************************************************************************
* File Name : AnimationTimer.h                   Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�A�j���[�V�����^�C�}�[�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _ANIMATION_TIMER_H_
#define _ANIMATION_TIMER_H_


/// <summary>
/// �A�j���[�V�����^�C�}�[�N���X.
/// </summary>
class AnimationTimer
{
	/*---- �R���X�g���N�^�E�f�X�g���N�^�̐錾 -------------------------------*/
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	AnimationTimer();
	/// <summary>
	/// ������.
	/// </summary>
	void Initialize();

	/*---- �����o�֐��̐錾 -------------------------------------------------*/
public:
	/// <summary>
	/// �X�V.
	/// </summary>
	/// <param name="frameTimer">�t���[�����[�g</param>
	void Update( float frameTimer );
	/// <summary>
	/// �^�C�}�[�������Ă��邩����.
	/// </summary>
	/// <returns>�����Ă���ΐ^�A�����łȂ���΋U��Ԃ�.</returns>
	bool IsStop();
	/// <summary>
	/// �ő厞�ԂŃ��Z�b�g����.
	/// </summary>
	void Reset();
	/// <summary>
	/// �^�C�}�[���[������.
	/// </summary>
	/// <returns>�^�C�}�[���[���̎��^�A�����łȂ���΋U��Ԃ�.</returns>
	bool IsZero();
	/// <summary>
	/// �^�C�}�[�J�n����.
	/// </summary>
	void Start();
	/// <summary>
	/// �}�b�N�X�^�C���ŕb��ݒ�.
	/// </summary>
	/// <param name="time">�ő厞��</param>
	void SetMaxTime(float time);

	/*---- �����o�ϐ��̒�` -------------------------------------------------*/
private:
	/// <summary>
	/// �ő厞��.
	/// </summary>
	int mMaxTime;
	/// <summary>
	/// ����.
	/// </summary>
	float mTimer;
	/// <summary>
	/// �X�^�[�g�t���O.
	/// </summary>
	bool mIsStart;

}; // AnimationTimer end


#endif // _ANIMATION_TIMER_H_ end

/********** End of File ******************************************************/
