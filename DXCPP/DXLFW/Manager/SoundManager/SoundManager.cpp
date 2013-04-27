/**===File Commentary=======================================*/
/**
 *	@file	SoundManager.cpp
 *
 *	@brief	サウンドマネージャ
 *
 *	@author	KORYUOH
 *
 *	@date	2013/02/19
 */
/**===File Include=========================================*/
#include	<Manager/SoundManager/SoundManager.h>
#include	<../Include/DxLib.h>
#include	<algorithm>
/**===Class Implementation=================================*/
const int SoundManager::PLAYTYPE_ONESHOT = DX_PLAYTYPE_NORMAL;
const int SoundManager::PLAYTYPE_BG = DX_PLAYTYPE_BACK;
const int SoundManager::PLAYTYPE_LOOP = DX_PLAYTYPE_LOOP;
/**========================================================*/
/**
 *	@brief	コンストラクタ
 */
/**========================================================*/
SoundManager::SoundManager()
{}
/**========================================================*/
/**
 *	@brief	読み込み
 *	@param[in]	識別キー
 *	@param[in]	読み込みパス
 */
/**========================================================*/
void SoundManager::load(const std::string& Key,const std::string& Path){
	if(isRegisted(Key))
		return;
	int tmp = LoadSoundMem(Path.c_str());
	if(tmp==-1)
		return;
	mContainer[Key] = tmp;
}
/**========================================================*/
/**
 *	@brief	再生
 *	@param[in]	識別キー
 *	@param[in]	再生タイプ　初期値:BGモード
 */
/**========================================================*/
void SoundManager::play(const std::string& Key,int SoundPlayType){
	if(!isRegisted(Key))
		return;
	PlaySoundMem(mContainer[Key],SoundPlayType);
}

/**========================================================*/
/**
 *	@brief	登録されているか？
 *	@param[in]	識別キー
 *	@return	登録されていれば真
 */
/**========================================================*/
bool SoundManager::isRegisted(const std::string& Key){
	return (mContainer.find(Key) != mContainer.end());
}

/**========================================================*/
/**
 *	@brief	再生停止
 *	@param[in]	識別キー
*/
/**========================================================*/
void SoundManager::stop(const std::string& Key){
	if(isPlaying(Key))
		StopSoundMem(mContainer[Key]);
}

/**========================================================*/
/**
 *	@brief	解放
 *	@param[in]	識別キー
 */
/**========================================================*/
void SoundManager::unload(const std::string& Key){
	if(!isRegisted(Key))
		return;
	DeleteSoundMem(mContainer[Key]);
}

/**========================================================*/
/**
 *	@brief	再生中か？
 *	@param[in]	識別キー
 *	@return	再生されていれば真
 */
/**========================================================*/
bool SoundManager::isPlaying(const std::string&Key){
	if(!isRegisted(Key))
		return false;
	return (bool)CheckSoundMem(mContainer[Key]);
}
/**========================================================*/
/**
 *	@brief	全解放
 */
/**========================================================*/
void SoundManager::freeAll(){
	std::for_each(
		mContainer.begin(),
		mContainer.end(),
		[&](std::map<std::string,int>::value_type& Handle){DeleteSoundMem(Handle.second);}
	);
}

/**========================================================*/
/**
 *	@brief	音量設定
 *	@param[in]	識別キー
 *	@param[in]	再生ボリューム(%)
 */
/**========================================================*/
void SoundManager::changeVolume(const std::string& Key,float volume){
	if(!isRegisted(Key))
		return;
	ChangeVolumeSoundMem((int)(255.0f*volume),mContainer[Key]);
}

/**========================================================*/
/**
 *	@brief	ループ位置設定
 *	@param[in]	識別キー
 *	@param[in]	ループ位置（ミリ秒）
 */
/**========================================================*/
void SoundManager::setLoopPosition(const std::string& Key,int millsec){
	if(!isRegisted(Key))
		return;
	SetLoopPosSoundMem(millsec,mContainer[Key]);
}
/**===End Of File==========================================*/