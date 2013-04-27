/**===File Commentary=======================================*/
/**
 *	@file	SoundManager.h
 *
 *	@brief	サウンドマネージャ
 *
 *	@author	KORYUOH
 *
 *	@date	2013/02/19
 */
/**===Include Guard========================================*/
#ifndef	_SOUNDMANAGER_H_
#define	_SOUNDMANAGER_H_
/**===File Include=========================================*/
#include	<Singleton/Singleton.h>
#include	<map>
#include	<string>
/**===Class Definition=====================================*/
class SoundManager:public Singleton<SoundManager>{
	/**
	 *	@brief	コンストラクタ
	 */
	SoundManager();
	/**
	 *	@brief	仮想デストラクタ
	 */
	virtual ~SoundManager(){}
	/**
	 *	@brief	アクセス許可
	 **/
	friend SoundManager::Singleton<SoundManager>;
public:
	/**
	 *	@brief	再生方式
	 */
	const static int PLAYTYPE_ONESHOT;
	const static int PLAYTYPE_LOOP;
	const static int PLAYTYPE_BG;
	/**
	 *	@brief	読み込み
	 *	@param[in]	識別キー
	 *	@param[in]	読み込みパス
	 */
	void load(const std::string& Key,const std::string& Path);
	/**
	 *	@brief	再生
	 *	@param[in]	識別キー
	 *	@param[in]	再生タイプ
	 */
	void play(const std::string& Key,int SoundPlayType = PLAYTYPE_BG);
	/**
	 *	@brief	再生中か？
	 *	@param[in]	識別キー
	 *	@return	再生中なら真
	 */
	bool isPlaying(const std::string& Key);
	/**
	 *	@brief	停止
	 *	@param[in]	識別キー
	 */
	void stop(const std::string& Key);
	
	/**
	 *	@brief	解放
	 *	@param[in]	識別キー
	 */
	void unload(const std::string& Key);
	/**
	 *	@brief	ボリューム変更
	 *	@param[in]	識別キー
	 *	@param[in]	ボリューム(%)
	 */
	void changeVolume(const std::string& Key,float volume);
	
	/**
	 *	@brief	ループ位置設定
	 *	@param[in]	識別キー
	 *	@param[in]	ループ位置(ミリ秒)
	 */
	void setLoopPosition(const std::string& Key,int milsec);
	
	/**
	 *	@brief	全解放
	 */
	void freeAll();
	
	/**
	 *	@brief	登録されているか？
	 *	@param[in]	識別キー
	 *	@return	登録されていれば真
	 */
	bool isRegisted(const std::string& Key);
private:
	/**	メンバー変数*/
	std::map<std::string,int> mContainer;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/