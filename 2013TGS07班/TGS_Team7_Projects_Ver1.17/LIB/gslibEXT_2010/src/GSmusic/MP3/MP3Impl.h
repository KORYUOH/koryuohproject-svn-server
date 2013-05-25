#ifndef _MP3_IMPL_H_
#define _MP3_IMPL_H_

#include "LoopPlayThread.h"

#pragma warning(push)
#pragma warning(disable:4995)
#pragma warning(disable:4996)
#pragma warning(disable:4819)
#include <atlbase.h>
#include <dshow.h>
#pragma warning(pop)

// ＭＰ３実装クラス
class MP3Impl : public LoopPlayTarget
{
public:

	// コンストラクタ
	MP3Impl();

	// デストラクタ
	~MP3Impl();

	// クリーンアップ
	void cleanup();
	
	// 初期化
	bool initialize( const char* fileName );

	// 再生
	void play();

	// 停止
	void stop();

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
	void setVolume( int volume );

	// バランスの設定
	void setBalance( int balance );

	// ボリュームの取得
	int getVolume() const;

	// バランスの取得
	int getBalance() const;
	
	// ループの指定
	void loop(bool isLoop=true);

	// 終了しているか？
	virtual bool isEnd() const;
	
	// リスタート
	virtual void restart(); 

private:

	// コピー禁止
	MP3Impl( const MP3Impl& other );
	MP3Impl& operator= ( const MP3Impl& other );

private:
	// Direct Show関係
	IGraphBuilder*  mGraphBuilder;
	IMediaControl*  mMediaControl;
	IMediaPosition* mMediaPosition;
	IMediaEvent*    mMediaEvent;
	IBasicAudio*    mAudio;

	// ループフラグ
	bool			mIsLoop;
	// ループ制御スレッド
	LoopPlayThread	mLoopThread;
};

#endif

// end of file
