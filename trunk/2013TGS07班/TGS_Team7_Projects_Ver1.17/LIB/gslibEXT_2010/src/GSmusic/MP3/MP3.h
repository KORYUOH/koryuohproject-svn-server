#ifndef _MP3_H_
#define _MP3_H_

// ＭＰ３実装クラス
class MP3Impl;

// ＭＰ３クラス
class MP3
{
public:

	// コンストラクタ
	MP3();

	// デストラクタ
	~MP3();

	// クリーンアップ
	void cleanup();
	
	// ファイルの読み込み
	bool load( const char* fileName );

	// 再生
	void play();

	// 停止
	void stop();

	// 一時停止
	void pause();

	// 再生スピードの変更
	void setSpeed( float time );
	
	// 現在の再生位置を指定位置にセット
	void setTime( float time );

	// 終了時間の取得
	float getStopTime() const;

	// ストリームの時間幅の取得
	float getDuration() const;

	// 現在の再生位置の取得
	float getCurrentPosition() const;

	// ボリュームの設定
	void setVolume( float volume );

	// バランスの設定
	void setBalance( float balance );

	// ボリュームの取得
	float getVolume() const;

	// バランスの取得
	float getBalance() const;
	
	// ループの指定
	void loop(bool isLoop=true);

	// ループ再生中か？
	bool isLoop() const;

	// 再生中か？
	bool isPlay() const;

	// 停止中か？
	bool isStop() const;
	
	// 一時停止中か？
	bool isPause() const;

	// 終了しているか？
	bool isEnd() const;

private:

	// コピー禁止
	MP3( const MP3& other );
	MP3& operator= ( const MP3& other );

private:

	// 実装クラス
	MP3Impl*	mImpl;
	// ボリューム (最小0.0～最大1.0)
	float		mVolume;
	// バランス(-1.0～1.0);
	float		mBalance;
	// プレイ中フラグ
	bool		mIsPlay;
	// 一時停止中フラグ
	bool		mIsPause;
	// ループ中フラグ
	bool		mIsLoop;
};

#endif

// end of file
