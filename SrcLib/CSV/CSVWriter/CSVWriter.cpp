/**===File Commentary=======================================*/
/**
 *	@file	CSVWriter.cpp
 *
 *	@brief	CSV�����o��
 *
 *	@author	KORYUOH
 *
 *	@date	2012/11/27
 */
/**===File Include=========================================*/
#include	<fstream>
#include	<algorithm>
#include	"CSVWriter.h"
/**===Class Implementation=================================*/
const int CSVWriter::DEFAULT	=	std::ios::out;
const int CSVWriter::ADD	=	std::ios::app;
const int CSVWriter::RENEW	=	std::ios::trunc;
const int CSVWriter::ADD2END	=	std::ios::ate;
const int CSVWriter::BINARY	=	std::ios::binary;
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�t�@�C����
 */
/**========================================================*/
CSVWriter::CSVWriter(const std::string& fileName)
	:mFileName(fileName)
	,mOutMode(std::ios::out)
{}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�t�@�C����
 *	@param[in]	�o�̓t���O
 */
/**========================================================*/
CSVWriter::CSVWriter(const std::string& filename,int outputFlag)
	:mFileName(filename)
	,mOutMode(outputFlag)
{}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 */
/**========================================================*/
CSVWriter::CSVWriter()
	:mFileName("anonymous.csv")
		,mOutMode(std::ios::out)
{}
/**========================================================*/
/**
 *	@brief	������ǉ�
 *	@param[in]	������
 */
/**========================================================*/
void CSVWriter::addString(const std::string& str){
	mContainer.push_back(str);
}
/**========================================================*/
/**
 *	@brief	�t�@�C�����ݒ�
 *	@param[in]	�t�@�C����
 */
/**========================================================*/
void CSVWriter::setFileName(const std::string& fileName){
	mFileName = fileName;
}
/**========================================================*/
/**
 *	@brief	�o�̓t���O�ݒ�
 *	@param[in]	�o�̓t���O
 */
/**========================================================*/
void CSVWriter::setOutMode(int out){
	mOutMode = out;
}
/**========================================================*/
/**
 *	@brief	�������݃f�[�^�R���e�i�擾
 *	@param[in]	�f�[�^�R���e�i
 */
/**========================================================*/
void CSVWriter::setDataContainer(const CSVWriter::WriteDataContainer& container){
	mContainer = container;
}
/**========================================================*/
/**
 *	@brief	�����o��
 */
/**========================================================*/

void CSVWriter::write(){
	std::basic_ofstream<char> ofs(mFileName,mOutMode);

	std::for_each(
		mContainer.begin(),
		mContainer.end(),
		[&](const std::string& str){
			ofs << str << ",";
	}
	);

	ofs.close();
}

/**========================================================*/
/**
 *	@brief	�����o��
 *	@param[in]	�t�@�C����
 */
/**========================================================*/
void CSVWriter::write(const std::string& fileName){
	setFileName(fileName);
	write();
}
/**========================================================*/
/**
 *	@brief	�����o��
 *	@param[in]	�o�̓t���O
 */
/**========================================================*/
void CSVWriter::write(int out){
	setOutMode(out);
	write();
}
/**========================================================*/
/**
 *	@brief	�����o��
 *	@param[in]	�t�@�C����
 *	@param[in]	�o�̓t���O
 */
/**========================================================*/
void CSVWriter::write(const std::string& fileName,int out){
	setFileName(fileName);
	setOutMode(out);
	write();
}




/**===End Of File==========================================*/