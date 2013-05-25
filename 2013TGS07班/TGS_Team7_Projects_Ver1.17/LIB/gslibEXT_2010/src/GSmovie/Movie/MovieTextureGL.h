#ifndef _MOVIE_TEXTURE_GL_H_
#define _MOVIE_TEXTURE_GL_H_

#include "Movie.h"

// ���[�r�[�e�N�X�`���N���X
class MovieTextureGL
{
public:

	// �R���X�g���N�^
	MovieTextureGL();

	// �f�X�g���N�^
	~MovieTextureGL();

	// ���[�r�[�̍������擾
	int getHeight() const;

	// ���[�r�[�̕����擾
	int getWidth() const;

	// ���[�r�[�t�@�C���̓ǂݍ���
	bool load( const char* fileName );

	// ���[�r�[�̍X�V
	void update();

	// ���[�r�[�̕`��
	void draw();

	// ���[�r�[�̍Đ�
	void play();

	// ���[�r�[�̒�~
	void stop();
	
	// �Đ����Ԃ̐ݒ�
	void setTime( float time );

	// �Đ����Ԃ̎擾
	float getTime() const;

	// �I�����Ԃ̎擾
	float getEndTime() const;

	// �{�����[���̐ݒ�
	void setVolume( float volume );

	// �{�����[���̎擾
	float getVolume() const;

	// �N���[���A�b�v
	void cleanup();

	// �e�N�X�`����Ԃ�
	unsigned int getTexture();

private:

	// �e�N�X�`���̐���
	void genTexture();

	// �e�N�X�`���̍X�V
	void updateTexture();	

	// �e�N�X�`���̕`��
	void drawTexture();	

	// �e�N�X�`���̍폜
	void deleteTexture();	

private:

	// ���[�r�[�N���X
	Movie			mMovie;

	// ���[�r�[�p�̃e�N�X�`��
	unsigned int	mTexture;
	
	// ���[�r�[�p�̃e�N�X�`���̕�
	unsigned int	mTextureWidth;

	// ���[�r�[�p�̃e�N�X�`���̍���
	unsigned int	mTextureHeight;
};

#endif

// end of file
