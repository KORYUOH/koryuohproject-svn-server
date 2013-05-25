#include "MP3.h"
#include "MP3Impl.h"

// コンストラクタ
MP3::MP3() :
	mImpl( new MP3Impl() ),
	mVolume(1.0f),
	mBalance(0.0f),
	mIsPlay(false),
	mIsPause(false),
	mIsLoop(false)
{}

// デストラクタ
MP3::~MP3()
{
	delete mImpl;
}

// クリーンアップ
void MP3::cleanup()
{
	mImpl->cleanup();
}

// 初期化
bool MP3::load( const char* fileName )
{
	if ( mImpl->initialize( fileName ) ) {
		setVolume(1.0f);
		setBalance(0.0f);
		return true;
	}
	return false;
}

// 再生
void MP3::play()
{
	mImpl->play();
	mIsPlay = true;
	mIsPause = false;
}

// 停止
void MP3::stop()
{
	mImpl->stop();
	setTime(0.0);
	mIsPlay = false;
}

// 一時停止
void MP3::pause()
{
	mImpl->stop();
	mIsPause = true;
}

// 再生スピードの変更
void MP3::setSpeed( float time )
{
	mImpl->setSpeed( time );
}
	
// 現在の再生位置を指定位置にセット
void MP3::setTime( float time )
{
	mImpl->setTime( time );
}

// 終了時間の取得
float MP3::getStopTime() const
{
	return mImpl->getStopTime();
}

// ストリームの時間幅の取得
float MP3::getDuration() const
{
	return mImpl->getDuration();
}

// 現在の再生位置の取得
float MP3::getCurrentPosition() const
{
	return mImpl->getCurrentPosition();
}

// ボリュームの設定
void MP3::setVolume( float volume )
{
	// 0.0 ～ 1.0のボリュームを-10000～0に変換する
	mVolume = max(0.0f, min(1.0f, volume));
	int v = (int)(mVolume * 10000.0f - 10000.0f);
	mImpl->setVolume( v );
}

// バランスの設定
void MP3::setBalance( float balance )
{
	// -1.0 ～ 1.0のバランスを-10000～10000に変換する
	mBalance = max(-1.0f, min(1.0f, balance ));
	int b = (int)(mBalance * 10000.0f);
	mImpl->setBalance( b );
}

// ボリュームの取得
float MP3::getVolume() const {
	return mVolume;
}

// バランスの取得
float MP3::getBalance() const {
	return mBalance;
}

// ループの指定
void MP3::loop(bool isLoop) {
	mIsLoop = isLoop;
	mImpl->loop( mIsLoop );
}

// ループ再生中か？
bool MP3::isLoop() const {
	return mIsLoop;
}

// 再生中か？
bool MP3::isPlay() const {
	return mIsPlay;
}

// 一時停止中か？
bool MP3::isPause() const {
	return mIsPause;
}

// 終了しているか？
bool MP3::isEnd() const {
	return !isLoop() && mImpl->isEnd();
}

// end of file
