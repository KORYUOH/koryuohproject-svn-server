#include "GSmusic.h"
#include "./MP3/MP3.h"

// ���y�̍ő吔
static const int MUSIC_MAX = 512;

// ���y�f�[�^�z��
static MP3* musics[MUSIC_MAX];

// �|�[�Y���t���O
static float pauseMusicFlags[MUSIC_MAX];

// �o�C���h���̉��yID
static GLuint bindMusic = 0;

// �o�C���h���̉��y���擾
static MP3* gsGetBindMusic() {
	return musics[bindMusic];
}

// �S���y�̈ꎞ��~
static void pauseAllMusic() {
	for (int i = 0; i < MUSIC_MAX; ++i) {
		if (musics[i] != 0 && !musics[i]->isPause()) {
			musics[i]->pause();
			pauseMusicFlags[i] = true;
		}
	}
}

// �S���y�̃��X�^�[�g
static void restartAllMusic() {
	for (int i = 0; i < MUSIC_MAX; ++i) {
		if (musics[i] != 0 && pauseMusicFlags[i]) {
			musics[i]->play();
			pauseMusicFlags[i] = false;
		}
	}
}

// ���y�̏�����
void gsInitMusic(void) {
	gsCleanupMusic();
}

// �E�B���h���A�N�e�B�u�̏ꍇ�̏���
void gsActivateMusic(GSboolean active) {
	if (active==GS_TRUE) {
		restartAllMusic();
	} else {
		pauseAllMusic();
	}
}

// ���y�̏I������
void gsFinishMusic(void) {
	gsCleanupMusic();
}

// �N���[���A�b�v
void gsCleanupMusic(void) {
	for (int i = 0; i < MUSIC_MAX; ++i) {
		gsDeleteMusic(i);
	}
	bindMusic = 0;
}

// �ǂݍ���
GSboolean gsLoadMusic(GSuint musicID, const char* fileName, GSboolean loop) {
	// ID���I�[�o�[���Ă��邩�H
	if (musicID >= MUSIC_MAX) {
		return GS_FALSE;
	}
	// �o�^�ς݉��y�̍폜������
	gsDeleteMusic(musicID);
	// MP3�N���X���쐬
	MP3* mp3 = new MP3();
	if (mp3->load(fileName) == false) {
		delete mp3;
		return GS_FALSE;
	}
	// ���[�v�̎w�������
	mp3->loop(loop == GS_TRUE);
	// �V�K�o�^
	musics[musicID] = mp3;
	return GS_TRUE;
}

// ���y�̃o�C���h
void gsBindMusic(GSuint musicID) {
	if (musicID >= MUSIC_MAX) {
		return;
	}
	bindMusic = musicID;
}

// �폜
void gsDeleteMusic(GSuint musicID) {
	delete musics[musicID];
	musics[musicID] = 0;
}

// �Đ�
void gsPlayMusic(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return;
	}
	if (!currentMusic->isPlay()) {
		currentMusic->play();
	}
}

// �ꎞ��~
void gsPauseMusic(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return;
	}
	currentMusic->pause();
}

// ���X�^�[�g
void gsRestartMusic(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return;
	}
	currentMusic->play();
}

// ��~
void gsStopMusic(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return;
	}
	currentMusic->stop();
}

// �Đ������H
GSboolean gsIsPlayMusic(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return GS_FALSE;
	}
	return currentMusic->isPlay();
}

// �|�[�Y�����H
GSboolean gsIsPauseMusic(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return GS_FALSE;
	}
	return currentMusic->isPause();
}

// �Đ��I�����Ă��邩�H
GSboolean gsIsEndMusic(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return GS_TRUE;
	}
	return currentMusic->isEnd();
}

// ���[�v�Đ����Ă��邩
GSboolean gsIsLoopMusic(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return GS_TRUE;
	}
	return currentMusic->isLoop();
}

// �Đ��^�C�}�̐ݒ�
void gsSetMusicTime(float time) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return;
	}
	return currentMusic->setTime(time);
}

// ���݂̍Đ����Ԃ̎擾
GSfloat gsGetMusicTime(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return 0.0f;
	}
	return currentMusic->getCurrentPosition();
}

// �I�����Ԃ̎擾
GSfloat gsGetMusicEndTime(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return 0.0f;
	}
	return currentMusic->getDuration();
}

// �{�����[���̐ݒ�
void gsSetMusicVolume(GSfloat volume) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return;
	}
	currentMusic->setVolume(volume);
}

// �o�����X�̐ݒ�
void gsSetMusicBalance(GSfloat balance) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return;
	}
	currentMusic->setBalance(balance);
}

// �{�����[���̎擾
GSfloat gsGetMusicVolume(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return 0.0f;
	}
	return currentMusic->getVolume();
}

// �o�����X�̎擾
GSfloat gsGetMusicBalance(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return 0.0f;
	}
	return currentMusic->getBalance();
}
