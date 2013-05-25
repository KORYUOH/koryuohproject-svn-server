#define _WIN32_WINNT 0x0403
#define _WIN32_DCOM
#include "MovieImpl.h"

//�R���X�g���N�^
MovieImpl::MovieImpl() :
	mGraphBuilder( NULL ),
	mMediaControl( NULL ),
	mMediaPosition( NULL ),
	mMediaEvent( NULL ),
	mAudio( NULL ),
	mVideoRenderer( 0 )
{
	// COM�̏�����
	CoInitializeEx( NULL, COINIT_MULTITHREADED );
}

//�f�X�g���N�^
MovieImpl::~MovieImpl()
{
	// �N���[���A�b�v
	cleanup();
	// COM�̏I������
	CoUninitialize();
}

// �N���[���A�b�v
void MovieImpl::cleanup()
{
	// ��~����
	stop();
	// �I�u�W�F�N�g�̉��
	if ( !(!mAudio) ) {
		mAudio.Release();
		mAudio = NULL;
	}
	if ( !(!mMediaControl) ) {
		mMediaControl.Release();
		mMediaControl = NULL;
	}
	if ( !(!mMediaEvent) ) {
		mMediaEvent.Release();
		mMediaEvent = NULL;
	}
	if ( !(!mMediaPosition) ) {
		mMediaPosition.Release();
		mMediaPosition = NULL;
	}
	if ( !(!mGraphBuilder) ) {
		mGraphBuilder.Release();
		mGraphBuilder = NULL;
	}
	mVideoRenderer = 0;
}

// �t�@�C���ǂݍ���
bool MovieImpl::load( const char* fileName, bool sound ) {
	// �N���[���A�b�v����
	cleanup();
	
	// �t�B���^�O���t�̍쐬
	if ( FAILED( mGraphBuilder.CoCreateInstance( CLSID_FilterGraph, NULL, CLSCTX_INPROC)) ) {
        return false;
	}

    // Create the Texture Renderer object
	HRESULT hr = S_OK;
	mVideoRenderer = new VideoRenderer( NULL, &hr );
    if ( FAILED(hr) ) {
		delete mVideoRenderer;
		mVideoRenderer = 0;
        return false;
    }
    
    // Get a pointer to the IBaseFilter on the TextureRenderer, add it to graph
    if ( FAILED( mGraphBuilder->AddFilter( mVideoRenderer, L"VideoRenderer" ) ) ) {
        return false;
    }
   
	// WCHAR�ɕϊ�����
    WCHAR wFileName[MAX_PATH];
    wFileName[MAX_PATH-1] = 0;    
    USES_CONVERSION;
    StringCchCopyW( wFileName, NUMELMS(wFileName), T2W(fileName) );

    // Add the source filter to the graph.
    CComPtr<IBaseFilter> srcFilter;          // Source Filter
    hr = mGraphBuilder->AddSourceFilter( wFileName, L"SOURCE", &srcFilter );
    
    // If the media file was not found, inform the user.
    if ( hr == VFW_E_NOT_FOUND || FAILED(hr) ) {
        return false;
    }

    CComPtr<IPin> srcFilterPinOut;    // Source Filter Output Pin   
    if ( SUCCEEDED( srcFilter->FindPin( L"Output", &srcFilterPinOut ) ) ) {
		if( sound == false ) {
			// �T�E���h������
			CComPtr<IPin> filterPinIn;      // Texture Renderer Input Pin
			// Find the source's output pin and the renderer's input pin
			if ( FAILED(hr = mVideoRenderer->FindPin( L"In", &filterPinIn )) ) {
				return false;
			}
			// Connect these two filters
			if ( FAILED(hr = mGraphBuilder->Connect( srcFilterPinOut, filterPinIn ))) {
				return false;
			}
		} else {
			// �T�E���h���L��
			if ( FAILED(hr = mGraphBuilder->Render( srcFilterPinOut ))) {
				return false;
			}
		}
	} else {
		// WMV,MPEG2�̏ꍇ
		if ( FAILED(mGraphBuilder->RenderFile( wFileName, NULL )) ) {
			return false;
		}
	}

	// ���[�r�[����C���^�[�t�F�[�X���擾
	mGraphBuilder.QueryInterface( &mAudio         );
    mGraphBuilder.QueryInterface( &mMediaControl  );
    mGraphBuilder.QueryInterface( &mMediaPosition );
    mGraphBuilder.QueryInterface( &mMediaEvent    );

	// ���ʂ̐ݒ�
	if ( sound == false ) {
		// �~���[�g
		setVolume( -10000 );
	} else {
		// �ő�{�����[��
		setVolume( 0 );
	}
    return true;
}

// ���[�r�[�̍������擾
int MovieImpl::getImageHeight() const
{
	if ( mVideoRenderer == 0 ) {
		return 0;
	}
	return mVideoRenderer->getHeight();
}

// ���[�r�[�̕����擾
int MovieImpl::getImageWidth() const
{
	if ( mVideoRenderer == 0 ) {
		return 0;
	}
	return mVideoRenderer->getWidth();
}

// ���[�r�[�̃C���[�W�����b�N����
void* MovieImpl::lockImage()
{
	if ( mVideoRenderer == 0 ) {
		return 0;
	}
	return mVideoRenderer->lock();
}

// ���[�r�[�̃A�����b�N����
void MovieImpl::unlockImage()
{
	if ( mVideoRenderer == 0 ) {
		return;
	}
	mVideoRenderer->unlock();
}

// ���[�r�[�̍Đ�
void MovieImpl::play()
{
	if ( mMediaControl == NULL ) {
		return;
	}
	mMediaControl->Run();
}

// ���[�r�[�̒�~
void MovieImpl::stop()
{
	if ( mMediaControl == NULL ) {
		return;
	}
	mMediaControl->Stop();
}

// �Đ��X�s�[�h�̕ύX
void MovieImpl::setSpeed( float time )
{
	if ( mMediaPosition == NULL ) {
		return;
	}
	mMediaPosition->put_Rate( time );
}
	
// ���݂̍Đ��ʒu���w��ʒu�ɃZ�b�g
void MovieImpl::setTime( float time )
{
	if ( mMediaPosition == NULL ) {
		return;
	}
	mMediaPosition->put_CurrentPosition( time );
}

// �I�����Ԃ̎擾
float MovieImpl::getStopTime() const
{
	if ( mMediaPosition == NULL ) {
		return 0;
	}
	REFTIME time;
	mMediaPosition->get_StopTime( &time );
	return (float)time;
}

// �X�g���[���̎��ԕ��̎擾
float MovieImpl::getDuration() const
{
	if ( mMediaPosition == NULL ) {
		return 0;
	}
	REFTIME time;
	mMediaPosition->get_Duration( &time );
	return (float)time;
}

// ���݂̍Đ��ʒu�̎擾
float MovieImpl::getCurrentPosition() const
{
	if ( mMediaPosition == NULL ) {
		return 0;
	}
	REFTIME time;
	mMediaPosition->get_CurrentPosition( &time );
	return (float)time;
}

// �{�����[���̐ݒ�
void MovieImpl::setVolume( int volume )
{
	if ( mAudio == NULL ) {
		return;
	}
	mAudio->put_Volume( (long)volume );
}

// �{�����[���̎擾
int MovieImpl::getVolume() const {
	if ( mAudio == NULL ) {
		return 0;
	}
	long volume;
	mAudio->get_Volume( &volume );
	return (int)volume;
}

// end of file
