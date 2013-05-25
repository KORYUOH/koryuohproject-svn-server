/******************************************************************************
* File Name : Timer.h                             Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�^�C�}�[�����D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _TIMER_H_
#define _TIMER_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include"../Draw/TextureNumber.h"

/*---- ��s�錾 -------------------------------------------------------------*/

class IRenderer;

/// <summary>
/// �^�C�}�[�N���X.
/// </summary>
class Timer
{
public:
	/// <summary>
	//�R���X�g���N�^
	/// </summary>
	Timer();
	/// <summary>
	//������
	/// </summary>
	/// <param name="limitTime">��������</param>
	void Initialize( float limitTime );
	/// <summary>
	//�X�V.
	/// </summary>
	/// <param name="frameTimer">�t���[�����[�g</param>
	void Update( float frameTimer);
	/// <summary>
	/// ���Ԃ��擾(�t���[�����ԂŎ擾)
	/// </summary>
	/// <returns>����(fps)��Ԃ�.</returns>
	float GetTimerF() const;
	/// <summary>
	/// ���Ԃ��擾(�b���Ŏ擾)
	/// </summary>
	/// <returns>����(s)��Ԃ�.</returns>
	float GetTimerS() const;
	/// <summary>
	/// ���Ԑ؂ꔻ��
	/// </summary>
	/// <returns>���Ԑ؂�̎��ɐ^�A�����łȂ���΋U��Ԃ�.</returns>
	bool isTimeOver() const;
	/// <summary>
	/// �`��.
	/// </summary>
	void Draw();

private:
	/// <summary>
	/// ����.
	/// </summary>
	float mTime;
	/// <summary>
	/// �������Ԓ萔.
	/// </summary>
	static const int TIME_LIMIT;
	/// <summary>
	/// �t���[�����[�g.
	/// </summary>
	static const int FRAME_RATE;
	/// <summary>
	/// ����`��Ǘ���.
	/// </summary>
	TextureNumber	mNumber;
};

#endif

/********** End of File ******************************************************/
