#include "Movie.h"
#include "MovieImpl.h"

//�R���X�g���N�^
Movie::Movie() :
	mImpl( new MovieImpl() ), mVolume(0.0)
{}

//�f�X�g���N�^
Movie::~Movie()
{
	delete mImpl;
}

// ������
bool Movie::load( const char* fileName, bool sound )
{
	if (sound) {
		mVolume = 1.0f;	// �f�t�H���g�͍ő�{�����[��
	} else {
		mVolume = 0.0f;	// ���y�̎w�肪�Ȃ��ꍇ�A�~���[�g�Ƃ���
	}
	if ( mImpl->load( fileName, sound ) ) {
		setVolume( mVolume );
		return true;
	}
	return false;
}

// ���[�r�[�̍������擾
int Movie::getImageHeight() const
{
	return mImpl->getImageHeight();
}

// ���[�r�[�̕����擾
int Movie::getImageWidth() const
{
	return mImpl->getImageWidth();
}

// ���[�r�[�̃C���[�W�����b�N����
void* Movie::lockImage()
{
	return mImpl->lockImage();
}

// ���[�r�[�̃A�����b�N����
void Movie::unlockImage()
{
	mImpl->unlockImage();
}

// ���[�r�[�̍Đ�
void Movie::play()
{
	mImpl->play();
}

// ���[�r�[�̒�~
void Movie::stop()
{
	mImpl->stop();
}

// �Đ��X�s�[�h�̕ύX
void Movie::setSpeed( float time )
{
	mImpl->setSpeed( time );
}
	
// ���݂̍Đ��ʒu���w��ʒu�ɃZ�b�g
void Movie::setTime( float time )
{
	mImpl->setTime( time );
}

// �I�����Ԃ̎擾
float Movie::getStopTime() const
{
	return mImpl->getStopTime();
}

// �X�g���[���̎��ԕ��̎擾
float Movie::getDuration() const
{
	return mImpl->getDuration();
}

// ���݂̍Đ��ʒu�̎擾
float Movie::getCurrentPosition() const
{
	return mImpl->getCurrentPosition();
}

// �{�����[���̐ݒ�@( 0.0(�~���[�g�j�` 1.0(�ő�j�j
void Movie::setVolume( float volume )
{
	// 0.0 �` 1.0�̃{�����[����-10000�`0�ɕϊ�����
	mVolume = max(0.0f, min(1.0f, volume));
	int v = (int)(mVolume * 10000.0f - 10000.0f);
	mImpl->setVolume( v );
}

// �{�����[���̎擾�@( 0.0(�~���[�g�j�` 1.0(�ő�j�j
float Movie::getVolume() const
{
	return mVolume;
}

// �N���[���A�b�v
void Movie::cleanup()
{
	mImpl->cleanup();
}

// end of file
