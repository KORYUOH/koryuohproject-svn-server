#ifndef _MOVIE_IMPL_H_
#define _MOVIE_IMPL_H_

#pragma warning(push)
#pragma warning(disable:4995)
#pragma warning(disable:4996)
#pragma warning(disable:4819)
#include <atlbase.h>
#include <dshow.h>
#include "VideoRenderer.h"
#pragma warning(pop)

// ���[�r�[�����N���X
class MovieImpl
{
public:
	
	//�R���X�g���N�^
	MovieImpl();	

	//�f�X�g���N�^
	~MovieImpl();	

	// �t�@�C���ǂݍ���
	bool load( const char* fileName, bool sound );

	// ���[�r�[�̍������擾
	int getImageHeight() const;

	// ���[�r�[�̕����擾
	int getImageWidth() const;

	// ���[�r�[�̃C���[�W�����b�N����
	void* lockImage();

	// ���[�r�[�̃A�����b�N����
	void unlockImage();

	// ���[�r�[�̍Đ�
	void play();

	// ���[�r�[�̒�~
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

	// �{�����[���̎擾
	int getVolume() const;

	// �N���[���A�b�v
	void cleanup();

private:

	// �R�s�[�֎~
	MovieImpl( const MovieImpl& other );
	MovieImpl& operator = ( const MovieImpl& other );

private:

	CComPtr<IGraphBuilder>  mGraphBuilder;
	CComPtr<IMediaControl>  mMediaControl;
	CComPtr<IMediaPosition> mMediaPosition;
	CComPtr<IMediaEvent>    mMediaEvent;
	CComPtr<IBasicAudio>    mAudio;
	VideoRenderer*		    mVideoRenderer;
};


#endif

// end of file
