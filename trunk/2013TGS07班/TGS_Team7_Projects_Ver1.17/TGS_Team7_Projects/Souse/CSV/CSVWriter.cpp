/******************************************************************************
* File Name : CSVWriter.h                         Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		CSVファイルの書き込みクラス．
*
******************************************************************************/
#include"CSVWriter.h"
#include<fstream>
#include<iostream>
#include<sstream>


/*=============================================================================
*
* Purpose : コンストラクタ．
*
* Return  : なし
*
*============================================================================*/
CSVWriter::CSVWriter()
{
}

/*=============================================================================
*
* Purpose : デストラクタ．
*
* Return  : なし
*
*============================================================================*/
CSVWriter::~CSVWriter()
{
}

/*=============================================================================
*
* Purpose : 保存(fileName:ファイル名)．
*
* Return  : なし
*
*============================================================================*/
bool CSVWriter::save(const std::string& fileName,Rows data)
{
	//ファイルの書き込み用にオープンする
	std::ofstream file(fileName);

	//ファイルオープンチェック
	if( file == 0 )
	{
		return false;
	}

	for( unsigned int row = 0 ; row < data.size() ; ++row )
	{
		unsigned int col;
		
		for( col = 0 ; col < data[row].size() - 1 ; ++col )
		{
			//データを書き込み後にカンマを付ける
			file << data[row][col] << ",";
		}

		//最後の行のみカンマを付けず改行を行う
		file << data[row][col] << "\n";

	}

	return true;

}

/*=============================================================================
*
* Purpose : データの保存(fileName:ファイル名,row:行数値,col:列数値)．
*
* Return  : なし
*
*============================================================================*/
bool CSVWriter::dataSave(const std::string& fileName,int row,int col,std::string data)
{
	//ファイルの書き込み用にオープンする
	std::ofstream file(fileName);

	//ファイルオープンチェック
	if( file == 0 )
	{
		return false;
	}

	return true;
}

/*=============================================================================
*
* Purpose : データの保存(fileName:ファイル名,row:行数値,col:列数値)．
*
* Return  : なし
*
*============================================================================*/
bool CSVWriter::dataSave(const std::string& fileName,int row,int col,int data)
{
	return false;
}

/*=============================================================================
*
* Purpose : データの保存(fileName:ファイル名,row:行数値,col:列数値)．
*
* Return  : なし
*
*============================================================================*/
bool CSVWriter::dataSave(const std::string& fileName,int row,int col,float data)
{
	return false;
}

/********** End of File ******************************************************/