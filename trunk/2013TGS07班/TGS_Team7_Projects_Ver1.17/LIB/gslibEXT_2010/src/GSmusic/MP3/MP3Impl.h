#ifndef _MP3_IMPL_H_
#define _MP3_IMPL_H_

#include "LoopPlayThread.h"

#pragma warning(push)
#pragma warning(disable:4995)
#pragma warning(disable:4996)
#pragma warning(disable:4819)
#include <atlbase.h>
#include <dshow.h>
#pragma warning(pop)

// �l�o�R�����N���X
class MP3Impl : public LoopPlayTarget
{
public:

	// �R���X�g���N�^
	MP3Impl();

	// �f�X�g���N�^
	~MP3Impl();

	// �N���[���A�b�v
	void cleanup();
	
	// ������
	bool initialize( const char* fileName );

	// �Đ�
	void play();

	// ��~
	void stop();

	// �Đ��X�s�[�h�̕ύX
	void setSpeed( float time );
	
	// ���݂̍Đ��ʒu���w��ʒu�ɃZ�b�g
	void setTime( float time );

	// �I�����Ԃ̎擾
	float getStopTime() const;

	// �X�g���[���̎��ԕ��̎擾
	float getDuration() const;

	// ���݂̍Đ��ʒu�̎擾
	float getCurrentPosition() const;

	// �{�����[���̐ݒ�
	void setVolume( int volume );

	// �o�����X�̐ݒ�
	void setBalance( int balance );

	// �{�����[���̎擾
	int getVolume() const;

	// �o�����X�̎擾
	int getBalance() const;
	
	// ���[�v�̎w��
	void loop(bool isLoop=true);

	// �I�����Ă��邩�H
	virtual bool isEnd() const;
	
	// ���X�^�[�g
	virtual void restart(); 

private:

	// �R�s�[�֎~
	MP3Impl( const MP3Impl& other );
	MP3Impl& operator= ( const MP3Impl& other );

private:
	// Direct Show�֌W
	IGraphBuilder*  mGraphBuilder;
	IMediaControl*  mMediaControl;
	IMediaPosition* mMediaPosition;
	IMediaEvent*    mMediaEvent;
	IBasicAudio*    mAudio;

	// ���[�v�t���O
	bool			mIsLoop;
	// ���[�v����X���b�h
	LoopPlayThread	mLoopThread;
};

#endif

// end of file
