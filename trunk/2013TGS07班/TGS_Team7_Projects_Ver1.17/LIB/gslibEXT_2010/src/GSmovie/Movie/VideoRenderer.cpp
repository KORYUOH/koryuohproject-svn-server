#include "VideoRenderer.h"
#include <cassert>

// ���C�u�����̐ݒ�
#ifdef	NDEBUG
# ifdef _MT
#  ifdef _DLL
#   pragma comment( lib, "strmbase_md.lib" )
#  else
#   pragma comment( lib, "strmbase_mt.lib" )
#  endif
# else
#  pragma comment( lib, "strmbase_ml.lib" )
# endif
#else
# ifdef _MT
#  ifdef _DLL
#   pragma comment( lib, "strmbase_mdd.lib" )
#  else
#   pragma comment( lib, "strmbase_mtd.lib" )
#  endif
# else
#  pragma comment( lib, "strmbase_mld.lib" )
# endif
#endif
#pragma comment( lib, "strmiids.lib" )

// �A�����b�N�t���O
const static int UNLOCK_IMAGE = -1;

// �R���X�g���N�^
VideoRenderer::VideoRenderer( LPUNKNOWN pUnk, HRESULT *phr ) :
	CBaseVideoRenderer( __uuidof(CLSID_MyVideoRenderer), NAME("MyVideo Renderer"), pUnk, phr ),
	mFrontBuffer(0),
	mBackBuffer(1),
	mLockBuffer(UNLOCK_IMAGE),
    mVideoWidth(0),
	mVideoHeight(0),
	mVideoPitch(0)
{
    ASSERT( phr!=0 );
	if (phr) {
        *phr = S_OK;
	}
}

// �f�X�g���N�^
VideoRenderer::~VideoRenderer()
{}

// ���̎擾
int VideoRenderer::getWidth() const
{
	return mVideoWidth;
}

// �����̎擾
int VideoRenderer::getHeight() const
{
	return mVideoHeight;
}

// �C���[�W�̃��b�N
void* VideoRenderer::lock()
{
	// �����_�����O�ς݂̃o�b�t�@�����b�N����
	mLockBuffer = mFrontBuffer;
	return (void*)&mBuffer[mLockBuffer][0];
}

// �C���[�W�̃A�����b�N
void VideoRenderer::unlock()
{
	mLockBuffer = UNLOCK_IMAGE;
}

// ���f�B�A�^�C�v�𒲂ׂ�
HRESULT VideoRenderer::CheckMediaType( const CMediaType* pmt )
{
    CheckPointer( pmt, E_POINTER );

    // �r�f�I�^�C�v�̂ݑΉ�����
    if( *pmt->FormatType() != FORMAT_VideoInfo ) {
		return E_INVALIDARG;
    }
	
    // RGB24�̃t�H�[�}�b�g�̂ݑΉ�����
    if( IsEqualGUID( *pmt->Type(),    MEDIATYPE_Video )  &&
        IsEqualGUID( *pmt->Subtype(), MEDIASUBTYPE_RGB24 ) ) {
        return S_OK;
    }
    
    return E_FAIL;
}

// ���f�B�A�^�C�v��ݒ肷��
HRESULT VideoRenderer::SetMediaType( const CMediaType* pmt )
{
    CheckPointer( pmt, E_POINTER );

	// �r�f�I�C���[�W�̃t�H�[�}�b�g���擾
    VIDEOINFO* pviBmp = (VIDEOINFO*)pmt->Format();
    mVideoWidth  = pviBmp->bmiHeader.biWidth;
    mVideoHeight = abs(pviBmp->bmiHeader.biHeight);
    mVideoPitch  = (mVideoWidth * 3 + 3) & ~(3);

	// �r�f�I�C���[�W�̃o�C�g�����v�Z
	int videoSize = mVideoWidth * mVideoHeight * 3;

	// �r�f�I�C���[�W�̏�����
	for ( int i = 0; i < 2; ++i ) {
		mBuffer[i].resize( videoSize );
		std::fill( mBuffer[i].begin(), mBuffer[i].end(), 0 );
	}

    return S_OK;
}

// �����_�����O���s��
HRESULT VideoRenderer::DoRenderSample( IMediaSample* pMediaSample )
{
	// �]�����̃o�b�t�@�̃|�C���^���擾
	BYTE* bmpImage = 0;
    pMediaSample->GetPointer( &bmpImage );

	// ���b�N�����Ă��Ȃ��o�b�t�@��I������
	if ( mLockBuffer == mBackBuffer ) {
		std::swap( mFrontBuffer, mBackBuffer );
	}

	// �]����̃o�b�t�@�̃|�C���^���擾
	unsigned char* buffer = &mBuffer[mBackBuffer][0];

	// �r�b�g�}�b�v�C���[�W���R�s�[����
	for ( int y = mVideoHeight-1; y >= 0; --y ) {
		BYTE* bmp = bmpImage + mVideoPitch * y;
		for ( int x = 0; x < mVideoWidth; ++x ) {
			buffer[0] = bmp[2];
			buffer[1] = bmp[1];
			buffer[2] = bmp[0];
			buffer += 3;
			bmp += 3;
		}
	}

	// �o�b�t�@���X���b�v����
	std::swap( mFrontBuffer, mBackBuffer );

	return S_OK;
}

// end of file
