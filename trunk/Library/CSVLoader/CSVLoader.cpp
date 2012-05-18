/**===File Commentary=======================================*/
/**
 *	@file	CSVLoader.cpp
 *
 *	@brief	CSV�ǂݍ��݃N���X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/18
 */
/**===File Include=========================================*/
#include	<fstream>
#include	<algorithm>
#include	"CSVLoader.h"
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 */
/**========================================================*/
CSVLoader::CSVLoader(){

}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�t�@�C����
 */
/**========================================================*/
CSVLoader::CSVLoader(const std::string& fileName):mFileName(fileName){
	
}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�t�@�C����
 */
/**========================================================*/
CSVLoader::CSVLoader(const char* fileName):mFileName(fileName){

}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�t�@�C����
 */
/**========================================================*/
CSVLoader::~CSVLoader(){
}
/**========================================================*/
/**
 *	@brief	����������ݒ�
 *	@param[in]	����������
 */
/**========================================================*/
void CSVLoader::addIgnoreString(const std::string& string){
	mIgnroeString.push_back(string);
}
/**========================================================*/
/**
 *	@brief	�ǂݍ���
 *	@param[in]	�t�@�C����
 */
/**========================================================*/
void CSVLoader::load(const std::string& fileName){
	mFileName = fileName;
	load();
}
/**========================================================*/
/**
 *	@brief	�ǂݍ���
 */
/**========================================================*/
void CSVLoader::load(){
	std::basic_ifstream<char> ifs;
	if(mFileName.empty()){
		mDataContainer.push_back("FileName has not been set.");
		return;
	}
	try{
		ifs.open(mFileName,std::ios::in);
		if(ifs.fail())
			throw "FileNotFound";
		while(! ifs.fail()){
			std::string temp;
			getline(ifs,temp,',');
			pushCheck(temp,ifs);
		}
		ifs.close();
	}catch(...){
		mDataContainer.push_back("Load Error");
		ifs.close();
	}
}
/**========================================================*/
/**
 *	@brief	�f�[�^�R���e�i�擾
 *	@return	�f�[�^�R���e�i
 */
/**========================================================*/
CSVLoader::DataContainer CSVLoader::getDataContainer(){
	return mDataContainer;
}
/**========================================================*/
/**
 *	@brief	��������
 *	@param[in]	������
 *	@return	�������蕶���łȂ���ΐ^
 */
/**========================================================*/
bool CSVLoader::ignoreCheck(std::string str)const{
	int t = std::string::npos;
	std::for_each(
		mIgnroeString.begin(),
		mIgnroeString.end(),
		[&](const std::string& temp){t = str.find(temp);}
	);
	return t == std::string::npos;
}
/**========================================================*/
/**
 *	@brief	�R���e�i�ɒǉ����邩����
 *	@param[in]	�ǉ����镶����
 *	@param[in]	�t�@�C���X�g���[��
 */
/**========================================================*/
void CSVLoader::pushCheck(const std::string& temp,std::basic_ifstream<char>& ifs ){
	if(ignoreCheck(temp))
		mDataContainer.push_back(temp);
	else{
		std::string t;
		getline(ifs,t);
	}
}

/**===End Of File==========================================*/