#define _WIN32_WINNT 0x0403
#define _WIN32_DCOM
#include "MP3Impl.h"

// DirectShowのライブラリ指定
#pragma comment( lib, "strmiids.lib" )

// コンストラクタ
MP3Impl::MP3Impl() :
	mGraphBuilder( NULL ),
	mMediaControl( NULL ), 
	mMediaPosition( NULL ),
	mAudio( NULL )
{
	// COMの初期化
	CoInitializeEx( NULL, COINIT_MULTITHREADED );
}

// デストラクタ
MP3Impl::~MP3Impl()
{
	cleanup();
	// COMの終了処理
	CoUninitialize();
}

// クリーンアップ
void MP3Impl::cleanup()
{
	// ループスレッドの終了
	mLoopThread.entry(0);
	mLoopThread.end();

	if( mAudio != NULL ) {
		mAudio->Release();
		mAudio = NULL;
	}
	if( mMediaPosition != NULL ) {
		mMediaPosition->Release();
		mMediaPosition = NULL;
	}
	if( mMediaControl != NULL ) {
		mMediaControl->Release();
		mMediaControl = NULL;
	}
	if( mGraphBuilder != NULL ) {
		mGraphBuilder->Release();
		mGraphBuilder = NULL;
	}
}

// 初期化
bool MP3Impl::initialize( const char* fileName )
{
	// クリーンアップ
	cleanup();

	// Create the Filter Graph Manager
	CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC,
	 		         IID_IGraphBuilder, (void**)&mGraphBuilder);

	mGraphBuilder->QueryInterface( IID_IMediaControl,  (void**)&mMediaControl  );
	mGraphBuilder->QueryInterface( IID_IMediaPosition, (void**)&mMediaPosition );
	mGraphBuilder->QueryInterface( IID_IBasicAudio,    (void**)&mAudio         );

	// WCHARに変換する
    WCHAR wFileName[MAX_PATH];
    wFileName[MAX_PATH-1] = 0;    
    USES_CONVERSION;
    StringCchCopyW( wFileName, NUMELMS(wFileName), T2W(fileName) );

	// Create standard graph
	if ( FAILED(mGraphBuilder->RenderFile(wFileName, NULL) ) ) {
		cleanup();
		return false;
	}
	return true;
}

// 再生
void MP3Impl::play()
{
	if ( mMediaControl == NULL ) {
		return;
	}
	mMediaControl->Run();
}

// 停止
void MP3Impl::stop()
{
	if ( mMediaControl == NULL ) {
		return;
	}
	mMediaControl->Stop();
}

// 再生スピードの変更
void MP3Impl::setSpeed( float time )
{
	if ( mMediaPosition == NULL ) {
		return;
	}
	mMediaPosition->put_Rate( time );
}
	
// 現在の再生位置を指定位置にセット
void MP3Impl::setTime( float time )
{
	if ( mMediaPosition == NULL ) {
		return;
	}
	mMediaPosition->put_CurrentPosition( time );
}

// 終了時間の取得
float MP3Impl::getStopTime() const
{
	if ( mMediaPosition == NULL ) {
		return 0.0f;
	}
	REFTIME time;
	mMediaPosition->get_StopTime( &time );
	return (float)time;
}

// ストリームの時間幅の取得
float MP3Impl::getDuration() const
{
	if ( mMediaPosition == NULL ) {
		return 0.0f;
	}
	REFTIME time;
	mMediaPosition->get_Duration( &time );
	return (float)time;
}

// 現在の再生位置の取得
float MP3Impl::getCurrentPosition() const
{
	if ( mMediaPosition == NULL ) {
		return 0.0f;
	}
	REFTIME time;
	mMediaPosition->get_CurrentPosition( &time );
	return (float)time;
}

// ボリュームの設定
void MP3Impl::setVolume( int volume )
{
	if ( mAudio == NULL ) {
		return;
	}
	mAudio->put_Volume( (long)volume );
}

// ボリュームの取得
int MP3Impl::getVolume() const
{
	if ( mAudio == NULL ) {
		return 0;
	}
	long volume;
	mAudio->get_Volume( &volume );
	return (int)volume;
}

// バランスの設定
void MP3Impl::setBalance( int balance )
{
	if ( mAudio == NULL ) {
		return;
	}
    mAudio->put_Balance( (long)balance );
}

// バランスの取得
int MP3Impl::getBalance() const
{
	if ( mAudio == NULL ) {
		return 0;
	}
	long balance;
	mAudio->get_Balance( &balance );
	return (int)balance;
}

// ループの指定
void MP3Impl::loop(bool isLoop) {
	mIsLoop = isLoop;
	if ( mIsLoop ) {
		mLoopThread.entry(this);
		if ( mLoopThread.isEnd() ) {
			mLoopThread.start();
		}
	} else {
		mLoopThread.entry(0);
		mLoopThread.end();
	}
}

// 終了しているか？
bool MP3Impl::isEnd() const {
	return getCurrentPosition() >= getDuration();
}

// リスタート
void MP3Impl::restart() {
	setTime(0.0f);
}

// end of file
