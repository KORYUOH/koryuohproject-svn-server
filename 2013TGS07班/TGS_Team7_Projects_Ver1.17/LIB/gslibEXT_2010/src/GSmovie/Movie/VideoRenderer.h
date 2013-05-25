#ifndef _VIDEO_RENDERER_H_
#define _VIDEO_RENDERER_H_

#pragma warning(push)
#pragma warning(disable:4995)
#pragma warning(disable:4996)
#pragma warning(disable:4819)
#include <Streams.h>
#include <vector>
#pragma warning(pop)

struct __declspec(uuid("{AD040BD2-C8BE-467b-A478-1DECB14CD938}")) CLSID_MyVideoRenderer;

// �r�f�I�����_���N���X
class VideoRenderer : public CBaseVideoRenderer
{
public:

	// �R���X�g���N�^
    VideoRenderer( LPUNKNOWN pUnk, HRESULT *phr );

	// �f�X�g���N�^
	~VideoRenderer();

	// ���̎擾
	int getWidth() const;

	// �����̎擾
	int getHeight() const;

	// �C���[�W�̃��b�N
	void* lock();

	// �C���[�W�̃A�����b�N
	void unlock();

private:

	// ���f�B�A�^�C�v�𒲂ׂ�
    HRESULT CheckMediaType( const CMediaType* pmt );

	// ���f�B�A�^�C�v��ݒ肷��
	HRESULT SetMediaType( const CMediaType* pmt );

	// �����_�����O���s��
	HRESULT DoRenderSample( IMediaSample* pMediaSample );

private:

	// �C���[�W�f�[�^�^
	typedef std::vector<unsigned char> ImageBuffer;

	// �C���[�W�o�b�t�@
	ImageBuffer	mBuffer[2];

	// �����_�����O�ς݂̃o�b�t�@
	int		mFrontBuffer;

	// �����_�����O���̃o�b�t�@
	int		mBackBuffer;

	// ���b�N���̃o�b�t�@
	int		mLockBuffer;

	// ��
    int		mVideoWidth;

	// ����
	int		mVideoHeight;

	// �s�b�`
	int		mVideoPitch;
};

#endif

// end of file


