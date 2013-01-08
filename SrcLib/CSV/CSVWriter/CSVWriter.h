/**===File Commentary=======================================*/
/**
 *	@file	CSVWriter.h
 *
 *	@brief	CSV��������
 *
 *	@author	KORYUOH
 *
 *	@date	2012/11/27
 */
/**===Include Guard========================================*/
#ifndef	_CSVWRITER_H_
#define	_CSVWRITER_H_
/**===File Include=========================================*/
#include	<vector>
#include	<string>
#include	<sstream>
/**===Class Definition=====================================*/
class CSVWriter{
public:
	typedef	std::vector<std::string> WriteDataContainer;
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�t�@�C����
	 */
	CSVWriter(const std::string& fileName);
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�t�@�C����
	 *	@param[in]	�o�̓t���O
	 */
	CSVWriter(const std::string& filename,int outputFlag); 
	/**
	 *	@brief	�R���X�g���N�^
	 */
	CSVWriter();
	/**
	 *	@brief	������ǉ�
	 *	@param[in]	������
	 */
	void addString(const std::string& str);
	/**
	 *	@brief	�����o��
	 */
	void write();
	/**
	 *	@brief	�����o��
	 *	@param[in]	�t�@�C����
	 */
	void write(const std::string& fileName);
	/**
	 *	@brief	�����o��
	 *	@param[in]	�o�̓t���O
	 */
	void write(int out);
	/**
	 *	@brief	�����o��
	 *	@param[in]	�t�@�C����
	 *	@param[in]	�o�̓t���O
	 */
	void write(const std::string& fileName,int out);
	/**
	 *	@brief	�t�@�C�����ݒ�
	 *	@param[in]	�t�@�C����
	 */
	void setFileName(const std::string& fileName);
	/**
	 *	@brief	�����o���f�[�^�ݒ�
	 *	@param[in]	�����o���f�[�^
	 */
	void setDataContainer(const WriteDataContainer& dataContainer);
	/**
	 *	@brief	�o�̓��[�h�ݒ�
	 *	@param[in]	�o�̓��[�h
	 */
	void setOutMode(int OutMode);
	/**
	 *	@brief	�����X�L�b�v
	 *	@param[in]	�X�L�b�v������
	 */
	void setSkipCharactors(int counter);
	/**
	 *	@brief	�o�̓t���O
	 */
	const static int DEFAULT;
	const static int ADD;
	const static int RENEW;
	const static int ADD2END;
	const static int BINARY;

	template<typename T>
	CSVWriter& operator << (const T& type){
		std::ostringstream stream;
		stream << type;
		addString(stream.str());
		return *this;
	};
	template<>
	CSVWriter& operator << (const std::string& str){
		addString(str);
		return *this;
	};

private:
	/**	�����o�[�ϐ�*/
	WriteDataContainer mContainer;
	std::string mFileName;
	int mOutMode;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/