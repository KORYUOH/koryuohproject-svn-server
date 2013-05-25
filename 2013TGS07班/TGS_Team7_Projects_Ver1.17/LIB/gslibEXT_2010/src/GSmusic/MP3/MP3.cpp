#include "MP3.h"
#include "MP3Impl.h"

// �R���X�g���N�^
MP3::MP3() :
	mImpl( new MP3Impl() ),
	mVolume(1.0f),
	mBalance(0.0f),
	mIsPlay(false),
	mIsPause(false),
	mIsLoop(false)
{}

// �f�X�g���N�^
MP3::~MP3()
{
	delete mImpl;
}

// �N���[���A�b�v
void MP3::cleanup()
{
	mImpl->cleanup();
}

// ������
bool MP3::load( const char* fileName )
{
	if ( mImpl->initialize( fileName ) ) {
		setVolume(1.0f);
		setBalance(0.0f);
		return true;
	}
	return false;
}

// �Đ�
void MP3::play()
{
	mImpl->play();
	mIsPlay = true;
	mIsPause = false;
}

// ��~
void MP3::stop()
{
	mImpl->stop();
	setTime(0.0);
	mIsPlay = false;
}

// �ꎞ��~
void MP3::pause()
{
	mImpl->stop();
	mIsPause = true;
}

// �Đ��X�s�[�h�̕ύX
void MP3::setSpeed( float time )
{
	mImpl->setSpeed( time );
}
	
// ���݂̍Đ��ʒu���w��ʒu�ɃZ�b�g
void MP3::setTime( float time )
{
	mImpl->setTime( time );
}

// �I�����Ԃ̎擾
float MP3::getStopTime() const
{
	return mImpl->getStopTime();
}

// �X�g���[���̎��ԕ��̎擾
float MP3::getDuration() const
{
	return mImpl->getDuration();
}

// ���݂̍Đ��ʒu�̎擾
float MP3::getCurrentPosition() const
{
	return mImpl->getCurrentPosition();
}

// �{�����[���̐ݒ�
void MP3::setVolume( float volume )
{
	// 0.0 �` 1.0�̃{�����[����-10000�`0�ɕϊ�����
	mVolume = max(0.0f, min(1.0f, volume));
	int v = (int)(mVolume * 10000.0f - 10000.0f);
	mImpl->setVolume( v );
}

// �o�����X�̐ݒ�
void MP3::setBalance( float balance )
{
	// -1.0 �` 1.0�̃o�����X��-10000�`10000�ɕϊ�����
	mBalance = max(-1.0f, min(1.0f, balance ));
	int b = (int)(mBalance * 10000.0f);
	mImpl->setBalance( b );
}

// �{�����[���̎擾
float MP3::getVolume() const {
	return mVolume;
}

// �o�����X�̎擾
float MP3::getBalance() const {
	return mBalance;
}

// ���[�v�̎w��
void MP3::loop(bool isLoop) {
	mIsLoop = isLoop;
	mImpl->loop( mIsLoop );
}

// ���[�v�Đ������H
bool MP3::isLoop() const {
	return mIsLoop;
}

// �Đ������H
bool MP3::isPlay() const {
	return mIsPlay;
}

// �ꎞ��~�����H
bool MP3::isPause() const {
	return mIsPause;
}

// �I�����Ă��邩�H
bool MP3::isEnd() const {
	return !isLoop() && mImpl->isEnd();
}

// end of file
