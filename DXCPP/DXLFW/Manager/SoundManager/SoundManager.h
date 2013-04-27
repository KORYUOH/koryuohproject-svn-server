/**===File Commentary=======================================*/
/**
 *	@file	SoundManager.h
 *
 *	@brief	�T�E���h�}�l�[�W��
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
	 *	@brief	�R���X�g���N�^
	 */
	SoundManager();
	/**
	 *	@brief	���z�f�X�g���N�^
	 */
	virtual ~SoundManager(){}
	/**
	 *	@brief	�A�N�Z�X����
	 **/
	friend SoundManager::Singleton<SoundManager>;
public:
	/**
	 *	@brief	�Đ�����
	 */
	const static int PLAYTYPE_ONESHOT;
	const static int PLAYTYPE_LOOP;
	const static int PLAYTYPE_BG;
	/**
	 *	@brief	�ǂݍ���
	 *	@param[in]	���ʃL�[
	 *	@param[in]	�ǂݍ��݃p�X
	 */
	void load(const std::string& Key,const std::string& Path);
	/**
	 *	@brief	�Đ�
	 *	@param[in]	���ʃL�[
	 *	@param[in]	�Đ��^�C�v
	 */
	void play(const std::string& Key,int SoundPlayType = PLAYTYPE_BG);
	/**
	 *	@brief	�Đ������H
	 *	@param[in]	���ʃL�[
	 *	@return	�Đ����Ȃ�^
	 */
	bool isPlaying(const std::string& Key);
	/**
	 *	@brief	��~
	 *	@param[in]	���ʃL�[
	 */
	void stop(const std::string& Key);
	
	/**
	 *	@brief	���
	 *	@param[in]	���ʃL�[
	 */
	void unload(const std::string& Key);
	/**
	 *	@brief	�{�����[���ύX
	 *	@param[in]	���ʃL�[
	 *	@param[in]	�{�����[��(%)
	 */
	void changeVolume(const std::string& Key,float volume);
	
	/**
	 *	@brief	���[�v�ʒu�ݒ�
	 *	@param[in]	���ʃL�[
	 *	@param[in]	���[�v�ʒu(�~���b)
	 */
	void setLoopPosition(const std::string& Key,int milsec);
	
	/**
	 *	@brief	�S���
	 */
	void freeAll();
	
	/**
	 *	@brief	�o�^����Ă��邩�H
	 *	@param[in]	���ʃL�[
	 *	@return	�o�^����Ă���ΐ^
	 */
	bool isRegisted(const std::string& Key);
private:
	/**	�����o�[�ϐ�*/
	std::map<std::string,int> mContainer;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/