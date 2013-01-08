/**===File Commentary=======================================*/
/**
 *	@file	CSVLoader.h
 *
 *	@brief	CSV�ǂݍ��݃N���X�w�b�_�t�@�C��
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/18
 */
/**===Include Guard========================================*/
#ifndef	_CSVLOADER_H_
#define	_CSVLOADER_H_
/**===File Include=========================================*/
#include	<string>
#include	<vector>
/**===Class Definition=====================================*/
class CSVLoader{
public:
	/** �f�[�^�R���e�i�^�̒�` */
	typedef std::vector<std::string> DataContainer;
	/**
	 *	@brief	�R���X�g���N�^
	 */
	CSVLoader();
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�t�@�C����
	 */
	CSVLoader(const std::string& fileName);
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�t�@�C����
	 */
	CSVLoader(const char* fileName);
	/**
	 *	@brief	�f�X�g���N�^
	 */
	virtual ~CSVLoader();
	/**
	 *	@brief	�ǂݍ���
	 *	@param[in]	�ǂݍ��݃t�@�C��
	 */
	void load(const std::string& fileName);
	/**
	 *	@brief	���������s��ݒ�
	 *	@param[in]	��������
	 */
	void addIgnoreString(const std::string& string);
	/**
	 *	@brief	�ǂݍ���
	 */
	void load();
	/**
	 *	@brief	�f�[�^�R���e�i�擾
	 *	@return	�R���e�i
	 */
	DataContainer getDataContainer();

private:
	/**
	 *	@brief	���������񔻒�
	 */
	bool ignoreCheck(std::string str)const;
	/**
	 *	@brief	�������ނ����肷��
	 */
	void pushCheck(const std::string& str,std::basic_ifstream<char>& fst);

private:
	/**	�����o�[�ϐ�*/
	std::string mFileName;
	DataContainer mDataContainer;
	DataContainer mIgnroeString;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/