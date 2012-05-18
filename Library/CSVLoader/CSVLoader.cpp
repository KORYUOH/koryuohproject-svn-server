/**===File Commentary=======================================*/
/**
 *	@file	CSVLoader.cpp
 *
 *	@brief	CSV読み込みクラス
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
 *	@brief	コンストラクタ
 */
/**========================================================*/
CSVLoader::CSVLoader(){

}
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	ファイル名
 */
/**========================================================*/
CSVLoader::CSVLoader(const std::string& fileName):mFileName(fileName){
	
}
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	ファイル名
 */
/**========================================================*/
CSVLoader::CSVLoader(const char* fileName):mFileName(fileName){

}
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	ファイル名
 */
/**========================================================*/
CSVLoader::~CSVLoader(){
}
/**========================================================*/
/**
 *	@brief	無視文字列設定
 *	@param[in]	無視文字列
 */
/**========================================================*/
void CSVLoader::addIgnoreString(const std::string& string){
	mIgnroeString.push_back(string);
}
/**========================================================*/
/**
 *	@brief	読み込み
 *	@param[in]	ファイル名
 */
/**========================================================*/
void CSVLoader::load(const std::string& fileName){
	mFileName = fileName;
	load();
}
/**========================================================*/
/**
 *	@brief	読み込み
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
 *	@brief	データコンテナ取得
 *	@return	データコンテナ
 */
/**========================================================*/
CSVLoader::DataContainer CSVLoader::getDataContainer(){
	return mDataContainer;
}
/**========================================================*/
/**
 *	@brief	無視判定
 *	@param[in]	文字列
 *	@return	無視判定文字でなければ真
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
 *	@brief	コンテナに追加するか判定
 *	@param[in]	追加する文字列
 *	@param[in]	ファイルストリーム
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