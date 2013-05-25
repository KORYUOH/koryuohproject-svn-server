#ifndef _MOVIE_H_
#define _MOVIE_H_

// ���[�r�[�����N���X
class MovieImpl;

// ���[�r�[�N���X
class Movie
{
public:
	
	//�R���X�g���N�^
	Movie();	

	//�f�X�g���N�^
	~Movie();	

	// �t�@�C���̓ǂݍ���
	bool load( const char* fileName, bool sound=true );

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

	// �{�����[���̐ݒ�@( 0.0(�~���[�g�j�` 1.0(�ő�j�j
	void setVolume( float volume );

	// �{�����[���̎擾�@( 0.0(�~���[�g�j�` 1.0(�ő�j�j
	float getVolume() const;

	// �N���[���A�b�v
	void cleanup();

private:

	// �R�s�[�֎~
	Movie( const Movie& other );
	Movie& operator = ( const Movie& other );

private:

	// ���[�r�[�����N���X
	MovieImpl*	mImpl;

	// �{�����[��
	float mVolume;
};

#endif

// end of file
