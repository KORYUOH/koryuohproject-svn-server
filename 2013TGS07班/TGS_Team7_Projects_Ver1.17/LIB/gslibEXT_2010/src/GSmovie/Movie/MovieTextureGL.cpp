#include "MovieTextureGL.h"
#include <windows.h>
#include <GL/gl.h>

static int power2( int num );

// �R���X�g���N�^
MovieTextureGL::MovieTextureGL() :
	mTexture( 0 ),
	mTextureWidth( 0 ),
	mTextureHeight( 0 )
{}

// �f�X�g���N�^
MovieTextureGL::~MovieTextureGL()
{
	cleanup();
}

// ���[�r�[�̍������擾
int MovieTextureGL::getHeight() const
{
	return mMovie.getImageHeight();
}

// ���[�r�[�̕����擾
int MovieTextureGL::getWidth() const
{
	return mMovie.getImageWidth();
}

// ���[�r�[�t�@�C���̓ǂݍ���
bool MovieTextureGL::load( const char* fileName )
{
	// ���[�r�[�t�@�C���̓ǂݍ���
	if ( mMovie.load( fileName ) == false ) {
		return false;
	}

	// ���[�r�[�p�̃e�N�X�`�����쐬����
	genTexture();

	return true;
}

// ���[�r�[�̍X�V
void MovieTextureGL::update()
{
	updateTexture();
}

// ���[�r�[�̕`��
void MovieTextureGL::draw()
{
	drawTexture();
}

// ���[�r�[�̍Đ�
void MovieTextureGL::play()
{
	mMovie.play();
}

// ���[�r�[�̒�~
void MovieTextureGL::stop()
{
	mMovie.stop();
}

// �Đ����Ԃ̐ݒ�
void MovieTextureGL::setTime( float time )
{
	mMovie.setTime( time );
}

// �Đ����Ԃ̎擾
float MovieTextureGL::getTime() const
{
	return mMovie.getCurrentPosition();
}

// �I�����Ԃ̎擾
float MovieTextureGL::getEndTime() const
{
	return mMovie.getStopTime();
}

// �{�����[���̐ݒ�
void MovieTextureGL::setVolume( float volume )
{
	mMovie.setVolume( volume );
}

// �{�����[���̎擾
float MovieTextureGL::getVolume() const
{
	return mMovie.getVolume();
}

// �N���[���A�b�v
void MovieTextureGL::cleanup()
{
	// ���[�r�[���N���[���A�b�v
	mMovie.cleanup();

	// ���[�r�[�p�̃e�N�X�`�����폜
	deleteTexture();
}

// ���[�r�[�p�̃e�N�X�`�����擾
unsigned int MovieTextureGL::getTexture()
{
	return mTexture;
}

// ���[�r�[�p�̃e�N�X�`�����쐬�D
void MovieTextureGL::genTexture()
{
	// ���[�r�[�p�̃e�N�X�`�����폜
	deleteTexture();

	glEnable( GL_TEXTURE_2D );

	// ���[�r�[�p�̃e�N�X�`�����쐬
	glGenTextures( 1, &mTexture );
	glBindTexture( GL_TEXTURE_2D, mTexture );
	
	// �e�N�X�`���̕��ƍ������v�Z����
	mTextureWidth  = power2( mMovie.getImageWidth()  );
	mTextureHeight = power2( mMovie.getImageHeight() );

	// �e�N�X�`���C���[�W��ݒ�
	glTexImage2D(
		GL_TEXTURE_2D,
		0, GL_RGB, mTextureWidth, mTextureHeight,
		0, GL_RGB, GL_UNSIGNED_BYTE , 0
	);

	// �e�N�X�`���t�B���^�̐ݒ�
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

	glBindTexture( GL_TEXTURE_2D , 0 );
}

// ���[�r�[�p�̃e�N�X�`�����X�V�D
void MovieTextureGL::updateTexture()
{
	if ( mTexture == 0  ) {
		return;
	}

	glBindTexture( GL_TEXTURE_2D , mTexture );

	// �C���[�W���X�V����
	void* movieImage = mMovie.lockImage();
	glTexSubImage2D(
		GL_TEXTURE_2D,
		0,
		0, 0,
		mMovie.getImageWidth(), mMovie.getImageHeight(),
		GL_RGB,
		GL_UNSIGNED_BYTE,
		movieImage
	);
	mMovie.unlockImage();

	glBindTexture( GL_TEXTURE_2D , 0 );
}

// ���[�r�[�p�̃e�N�X�`����`��D
void MovieTextureGL::drawTexture()
{
	if ( mTexture == 0  ) {
		return;
	}

	// �e�N�X�`�����o�C���h
	glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D , mTexture );

	// ���[�r�[��\��t�����l�p�|���S����`��
	float right  = (float)mMovie.getImageWidth()  / mTextureWidth;
	float bottom = (float)mMovie.getImageHeight() / mTextureHeight;
	glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex2f(-1.0f,1.0f);
		glTexCoord2f(0,bottom);
		glVertex2f(-1.0f,-1.0f);
		glTexCoord2f(right, bottom);
		glVertex2f(1.0f,-1.0f);
		glTexCoord2f(right,0);
		glVertex2f(1.0f,1.0f);
	glEnd();
	
	glBindTexture( GL_TEXTURE_2D , 0 );
}

// ���[�r�[�p�̃e�N�X�`�����폜
void MovieTextureGL::deleteTexture()
{
	if ( mTexture != 0 ) {
		glDeleteTextures( 1, &mTexture );
		mTexture = 0;
	}
}

// �ł��Q�̗ݏ�ɋ߂����������߂�
static int power2( int num )
{
	int result = 1;
	while ( result < num ) {
		result <<= 1;
	}
	return result;
}

// end of file
