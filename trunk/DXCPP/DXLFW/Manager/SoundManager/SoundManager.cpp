/**===File Commentary=======================================*/
/**
 *	@file	SoundManager.cpp
 *
 *	@brief	�T�E���h�}�l�[�W��
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
 *	@brief	�R���X�g���N�^
 */
/**========================================================*/
SoundManager::SoundManager()
{}
/**========================================================*/
/**
 *	@brief	�ǂݍ���
 *	@param[in]	���ʃL�[
 *	@param[in]	�ǂݍ��݃p�X
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
 *	@brief	�Đ�
 *	@param[in]	���ʃL�[
 *	@param[in]	�Đ��^�C�v�@�����l:BG���[�h
 */
/**========================================================*/
void SoundManager::play(const std::string& Key,int SoundPlayType){
	if(!isRegisted(Key))
		return;
	PlaySoundMem(mContainer[Key],SoundPlayType);
}

/**========================================================*/
/**
 *	@brief	�o�^����Ă��邩�H
 *	@param[in]	���ʃL�[
 *	@return	�o�^����Ă���ΐ^
 */
/**========================================================*/
bool SoundManager::isRegisted(const std::string& Key){
	return (mContainer.find(Key) != mContainer.end());
}

/**========================================================*/
/**
 *	@brief	�Đ���~
 *	@param[in]	���ʃL�[
*/
/**========================================================*/
void SoundManager::stop(const std::string& Key){
	if(isPlaying(Key))
		StopSoundMem(mContainer[Key]);
}

/**========================================================*/
/**
 *	@brief	���
 *	@param[in]	���ʃL�[
 */
/**========================================================*/
void SoundManager::unload(const std::string& Key){
	if(!isRegisted(Key))
		return;
	DeleteSoundMem(mContainer[Key]);
}

/**========================================================*/
/**
 *	@brief	�Đ������H
 *	@param[in]	���ʃL�[
 *	@return	�Đ�����Ă���ΐ^
 */
/**========================================================*/
bool SoundManager::isPlaying(const std::string&Key){
	if(!isRegisted(Key))
		return false;
	return (bool)CheckSoundMem(mContainer[Key]);
}
/**========================================================*/
/**
 *	@brief	�S���
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
 *	@brief	���ʐݒ�
 *	@param[in]	���ʃL�[
 *	@param[in]	�Đ��{�����[��(%)
 */
/**========================================================*/
void SoundManager::changeVolume(const std::string& Key,float volume){
	if(!isRegisted(Key))
		return;
	ChangeVolumeSoundMem((int)(255.0f*volume),mContainer[Key]);
}

/**========================================================*/
/**
 *	@brief	���[�v�ʒu�ݒ�
 *	@param[in]	���ʃL�[
 *	@param[in]	���[�v�ʒu�i�~���b�j
 */
/**========================================================*/
void SoundManager::setLoopPosition(const std::string& Key,int millsec){
	if(!isRegisted(Key))
		return;
	SetLoopPosSoundMem(millsec,mContainer[Key]);
}
/**===End Of File==========================================*/