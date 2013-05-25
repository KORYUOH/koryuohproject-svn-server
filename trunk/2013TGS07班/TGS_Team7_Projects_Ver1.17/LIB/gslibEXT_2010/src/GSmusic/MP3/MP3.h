#ifndef _MP3_H_
#define _MP3_H_

// �l�o�R�����N���X
class MP3Impl;

// �l�o�R�N���X
class MP3
{
public:

	// �R���X�g���N�^
	MP3();

	// �f�X�g���N�^
	~MP3();

	// �N���[���A�b�v
	void cleanup();
	
	// �t�@�C���̓ǂݍ���
	bool load( const char* fileName );

	// �Đ�
	void play();

	// ��~
	void stop();

	// �ꎞ��~
	void pause();

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
	void setVolume( float volume );

	// �o�����X�̐ݒ�
	void setBalance( float balance );

	// �{�����[���̎擾
	float getVolume() const;

	// �o�����X�̎擾
	float getBalance() const;
	
	// ���[�v�̎w��
	void loop(bool isLoop=true);

	// ���[�v�Đ������H
	bool isLoop() const;

	// �Đ������H
	bool isPlay() const;

	// ��~�����H
	bool isStop() const;
	
	// �ꎞ��~�����H
	bool isPause() const;

	// �I�����Ă��邩�H
	bool isEnd() const;

private:

	// �R�s�[�֎~
	MP3( const MP3& other );
	MP3& operator= ( const MP3& other );

private:

	// �����N���X
	MP3Impl*	mImpl;
	// �{�����[�� (�ŏ�0.0�`�ő�1.0)
	float		mVolume;
	// �o�����X(-1.0�`1.0);
	float		mBalance;
	// �v���C���t���O
	bool		mIsPlay;
	// �ꎞ��~���t���O
	bool		mIsPause;
	// ���[�v���t���O
	bool		mIsLoop;
};

#endif

// end of file
