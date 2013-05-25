#include "GSmusic.h"
#include "./MP3/MP3.h"

// 音楽の最大数
static const int MUSIC_MAX = 512;

// 音楽データ配列
static MP3* musics[MUSIC_MAX];

// ポーズ中フラグ
static float pauseMusicFlags[MUSIC_MAX];

// バインド中の音楽ID
static GLuint bindMusic = 0;

// バインド中の音楽を取得
static MP3* gsGetBindMusic() {
	return musics[bindMusic];
}

// 全音楽の一時停止
static void pauseAllMusic() {
	for (int i = 0; i < MUSIC_MAX; ++i) {
		if (musics[i] != 0 && !musics[i]->isPause()) {
			musics[i]->pause();
			pauseMusicFlags[i] = true;
		}
	}
}

// 全音楽のリスタート
static void restartAllMusic() {
	for (int i = 0; i < MUSIC_MAX; ++i) {
		if (musics[i] != 0 && pauseMusicFlags[i]) {
			musics[i]->play();
			pauseMusicFlags[i] = false;
		}
	}
}

// 音楽の初期化
void gsInitMusic(void) {
	gsCleanupMusic();
}

// ウィンドがアクティブの場合の処理
void gsActivateMusic(GSboolean active) {
	if (active==GS_TRUE) {
		restartAllMusic();
	} else {
		pauseAllMusic();
	}
}

// 音楽の終了処理
void gsFinishMusic(void) {
	gsCleanupMusic();
}

// クリーンアップ
void gsCleanupMusic(void) {
	for (int i = 0; i < MUSIC_MAX; ++i) {
		gsDeleteMusic(i);
	}
	bindMusic = 0;
}

// 読み込み
GSboolean gsLoadMusic(GSuint musicID, const char* fileName, GSboolean loop) {
	// IDがオーバーしているか？
	if (musicID >= MUSIC_MAX) {
		return GS_FALSE;
	}
	// 登録済み音楽の削除をする
	gsDeleteMusic(musicID);
	// MP3クラスを作成
	MP3* mp3 = new MP3();
	if (mp3->load(fileName) == false) {
		delete mp3;
		return GS_FALSE;
	}
	// ループの指定をする
	mp3->loop(loop == GS_TRUE);
	// 新規登録
	musics[musicID] = mp3;
	return GS_TRUE;
}

// 音楽のバインド
void gsBindMusic(GSuint musicID) {
	if (musicID >= MUSIC_MAX) {
		return;
	}
	bindMusic = musicID;
}

// 削除
void gsDeleteMusic(GSuint musicID) {
	delete musics[musicID];
	musics[musicID] = 0;
}

// 再生
void gsPlayMusic(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return;
	}
	if (!currentMusic->isPlay()) {
		currentMusic->play();
	}
}

// 一時停止
void gsPauseMusic(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return;
	}
	currentMusic->pause();
}

// リスタート
void gsRestartMusic(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return;
	}
	currentMusic->play();
}

// 停止
void gsStopMusic(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return;
	}
	currentMusic->stop();
}

// 再生中か？
GSboolean gsIsPlayMusic(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return GS_FALSE;
	}
	return currentMusic->isPlay();
}

// ポーズ中か？
GSboolean gsIsPauseMusic(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return GS_FALSE;
	}
	return currentMusic->isPause();
}

// 再生終了しているか？
GSboolean gsIsEndMusic(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return GS_TRUE;
	}
	return currentMusic->isEnd();
}

// ループ再生しているか
GSboolean gsIsLoopMusic(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return GS_TRUE;
	}
	return currentMusic->isLoop();
}

// 再生タイマの設定
void gsSetMusicTime(float time) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return;
	}
	return currentMusic->setTime(time);
}

// 現在の再生時間の取得
GSfloat gsGetMusicTime(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return 0.0f;
	}
	return currentMusic->getCurrentPosition();
}

// 終了時間の取得
GSfloat gsGetMusicEndTime(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return 0.0f;
	}
	return currentMusic->getDuration();
}

// ボリュームの設定
void gsSetMusicVolume(GSfloat volume) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return;
	}
	currentMusic->setVolume(volume);
}

// バランスの設定
void gsSetMusicBalance(GSfloat balance) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return;
	}
	currentMusic->setBalance(balance);
}

// ボリュームの取得
GSfloat gsGetMusicVolume(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return 0.0f;
	}
	return currentMusic->getVolume();
}

// バランスの取得
GSfloat gsGetMusicBalance(void) {
	MP3* currentMusic = gsGetBindMusic();
	if (currentMusic == 0) {
		return 0.0f;
	}
	return currentMusic->getBalance();
}
