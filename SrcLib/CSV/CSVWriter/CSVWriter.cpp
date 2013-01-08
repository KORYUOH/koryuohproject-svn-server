/**===File Commentary=======================================*/
/**
 *	@file	CSVWriter.cpp
 *
 *	@brief	CSV書き出し
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
 *	@brief	コンストラクタ
 *	@param[in]	ファイル名
 */
/**========================================================*/
CSVWriter::CSVWriter(const std::string& fileName)
	:mFileName(fileName)
	,mOutMode(std::ios::out)
{}
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	ファイル名
 *	@param[in]	出力フラグ
 */
/**========================================================*/
CSVWriter::CSVWriter(const std::string& filename,int outputFlag)
	:mFileName(filename)
	,mOutMode(outputFlag)
{}
/**========================================================*/
/**
 *	@brief	コンストラクタ
 */
/**========================================================*/
CSVWriter::CSVWriter()
	:mFileName("anonymous.csv")
		,mOutMode(std::ios::out)
{}
/**========================================================*/
/**
 *	@brief	文字列追加
 *	@param[in]	文字列
 */
/**========================================================*/
void CSVWriter::addString(const std::string& str){
	mContainer.push_back(str);
}
/**========================================================*/
/**
 *	@brief	ファイル名設定
 *	@param[in]	ファイル名
 */
/**========================================================*/
void CSVWriter::setFileName(const std::string& fileName){
	mFileName = fileName;
}
/**========================================================*/
/**
 *	@brief	出力フラグ設定
 *	@param[in]	出力フラグ
 */
/**========================================================*/
void CSVWriter::setOutMode(int out){
	mOutMode = out;
}
/**========================================================*/
/**
 *	@brief	書き込みデータコンテナ取得
 *	@param[in]	データコンテナ
 */
/**========================================================*/
void CSVWriter::setDataContainer(const CSVWriter::WriteDataContainer& container){
	mContainer = container;
}
/**========================================================*/
/**
 *	@brief	書き出し
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
 *	@brief	書き出し
 *	@param[in]	ファイル名
 */
/**========================================================*/
void CSVWriter::write(const std::string& fileName){
	setFileName(fileName);
	write();
}
/**========================================================*/
/**
 *	@brief	書き出し
 *	@param[in]	出力フラグ
 */
/**========================================================*/
void CSVWriter::write(int out){
	setOutMode(out);
	write();
}
/**========================================================*/
/**
 *	@brief	書き出し
 *	@param[in]	ファイル名
 *	@param[in]	出力フラグ
 */
/**========================================================*/
void CSVWriter::write(const std::string& fileName,int out){
	setFileName(fileName);
	setOutMode(out);
	write();
}




/**===End Of File==========================================*/