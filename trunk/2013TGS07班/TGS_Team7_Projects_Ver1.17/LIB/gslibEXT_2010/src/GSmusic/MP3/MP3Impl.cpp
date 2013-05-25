#define _WIN32_WINNT 0x0403
#define _WIN32_DCOM
#include "MP3Impl.h"

// DirectShow�̃��C�u�����w��
#pragma comment( lib, "strmiids.lib" )

// �R���X�g���N�^
MP3Impl::MP3Impl() :
	mGraphBuilder( NULL ),
	mMediaControl( NULL ), 
	mMediaPosition( NULL ),
	mAudio( NULL )
{
	// COM�̏�����
	CoInitializeEx( NULL, COINIT_MULTITHREADED );
}

// �f�X�g���N�^
MP3Impl::~MP3Impl()
{
	cleanup();
	// COM�̏I������
	CoUninitialize();
}

// �N���[���A�b�v
void MP3Impl::cleanup()
{
	// ���[�v�X���b�h�̏I��
	mLoopThread.entry(0);
	mLoopThread.end();

	if( mAudio != NULL ) {
		mAudio->Release();
		mAudio = NULL;
	}
	if( mMediaPosition != NULL ) {
		mMediaPosition->Release();
		mMediaPosition = NULL;
	}
	if( mMediaControl != NULL ) {
		mMediaControl->Release();
		mMediaControl = NULL;
	}
	if( mGraphBuilder != NULL ) {
		mGraphBuilder->Release();
		mGraphBuilder = NULL;
	}
}

// ������
bool MP3Impl::initialize( const char* fileName )
{
	// �N���[���A�b�v
	cleanup();

	// Create the Filter Graph Manager
	CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC,
	 		         IID_IGraphBuilder, (void**)&mGraphBuilder);

	mGraphBuilder->QueryInterface( IID_IMediaControl,  (void**)&mMediaControl  );
	mGraphBuilder->QueryInterface( IID_IMediaPosition, (void**)&mMediaPosition );
	mGraphBuilder->QueryInterface( IID_IBasicAudio,    (void**)&mAudio         );

	// WCHAR�ɕϊ�����
    WCHAR wFileName[MAX_PATH];
    wFileName[MAX_PATH-1] = 0;    
    USES_CONVERSION;
    StringCchCopyW( wFileName, NUMELMS(wFileName), T2W(fileName) );

	// Create standard graph
	if ( FAILED(mGraphBuilder->RenderFile(wFileName, NULL) ) ) {
		cleanup();
		return false;
	}
	return true;
}

// �Đ�
void MP3Impl::play()
{
	if ( mMediaControl == NULL ) {
		return;
	}
	mMediaControl->Run();
}

// ��~
void MP3Impl::stop()
{
	if ( mMediaControl == NULL ) {
		return;
	}
	mMediaControl->Stop();
}

// �Đ��X�s�[�h�̕ύX
void MP3Impl::setSpeed( float time )
{
	if ( mMediaPosition == NULL ) {
		return;
	}
	mMediaPosition->put_Rate( time );
}
	
// ���݂̍Đ��ʒu���w��ʒu�ɃZ�b�g
void MP3Impl::setTime( float time )
{
	if ( mMediaPosition == NULL ) {
		return;
	}
	mMediaPosition->put_CurrentPosition( time );
}

// �I�����Ԃ̎擾
float MP3Impl::getStopTime() const
{
	if ( mMediaPosition == NULL ) {
		return 0.0f;
	}
	REFTIME time;
	mMediaPosition->get_StopTime( &time );
	return (float)time;
}

// �X�g���[���̎��ԕ��̎擾
float MP3Impl::getDuration() const
{
	if ( mMediaPosition == NULL ) {
		return 0.0f;
	}
	REFTIME time;
	mMediaPosition->get_Duration( &time );
	return (float)time;
}

// ���݂̍Đ��ʒu�̎擾
float MP3Impl::getCurrentPosition() const
{
	if ( mMediaPosition == NULL ) {
		return 0.0f;
	}
	REFTIME time;
	mMediaPosition->get_CurrentPosition( &time );
	return (float)time;
}

// �{�����[���̐ݒ�
void MP3Impl::setVolume( int volume )
{
	if ( mAudio == NULL ) {
		return;
	}
	mAudio->put_Volume( (long)volume );
}

// �{�����[���̎擾
int MP3Impl::getVolume() const
{
	if ( mAudio == NULL ) {
		return 0;
	}
	long volume;
	mAudio->get_Volume( &volume );
	return (int)volume;
}

// �o�����X�̐ݒ�
void MP3Impl::setBalance( int balance )
{
	if ( mAudio == NULL ) {
		return;
	}
    mAudio->put_Balance( (long)balance );
}

// �o�����X�̎擾
int MP3Impl::getBalance() const
{
	if ( mAudio == NULL ) {
		return 0;
	}
	long balance;
	mAudio->get_Balance( &balance );
	return (int)balance;
}

// ���[�v�̎w��
void MP3Impl::loop(bool isLoop) {
	mIsLoop = isLoop;
	if ( mIsLoop ) {
		mLoopThread.entry(this);
		if ( mLoopThread.isEnd() ) {
			mLoopThread.start();
		}
	} else {
		mLoopThread.entry(0);
		mLoopThread.end();
	}
}

// �I�����Ă��邩�H
bool MP3Impl::isEnd() const {
	return getCurrentPosition() >= getDuration();
}

// ���X�^�[�g
void MP3Impl::restart() {
	setTime(0.0f);
}

// end of file
