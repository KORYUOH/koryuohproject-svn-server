/******************************************************************************
* File Name : CsvReader.h                         Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		CSVファイルの読み込みクラス．
*
******************************************************************************/
#include"CSVReader.h"
//ファイルストリーム
#include<fstream>
#include<iostream>
#include<sstream>


/// <summary>
/// コンストラクタ.
/// </summary>
CSVReader::CSVReader()
{
	//データの消去
	mData.clear();
	mDataFloat.clear();
}

/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="fileName">ファイル名</param>
CSVReader::CSVReader(const std::string& fileName)
{
	//ファイルの読み込み
	Load(fileName);
}

/// <summary>
/// デストラクタ.
/// </summary>
CSVReader::~CSVReader()
{
}

/// <summary>
/// データの読み込み.
/// </summary>
/// <param name="fileName">ファイル名</param>
bool CSVReader::Load(const std::string& fileName)
{
	//データの消去
	mData.clear();
	mDataFloat.clear();

	//ファイルの読み込み
	std::fstream file(fileName);

	//ファイルオープンのエラーチェック
	//ファイルが読み込まれていない時
	if( file == 0 )
	{
		//Falseを返す
		return false;
	}

	std::string line;

	//getlineは1行を読み込む

	//すべての行を読み込むまでループ
	while(std::getline(file,line))
	{
		//行を読み込む
		std::stringstream stream(line);

		//データ一時保存用の変数を作成
		Row row;

		//一時保存用の文字列変数
		std::string val;

		//カンマ区切りで1行分を読み込む
		while( std::getline(stream,val,','))
		{
			//配列の最後尾に追加する
			row.push_back(val);
		}

		//データ保存用配列の最後尾に追加する
		mData.push_back(row);
	}

	//読み込めたのでTrueを返す
	return true;
}

/// <summary>
/// 保存.
/// </summary>
/// <returns>保存できた時真、できなければ偽を返す</returns>
bool CSVReader::Save(const std::string& fileName)
{
	//ファイルの書き込み用にオープンする
	std::ofstream file(fileName);

	//ファイルオープンチェック
	if( file == 0 )
	{
		return false;
	}

	for( int row = 0 ; row < Rows() ; ++row )
	{
		int col;

		for( col = 0 ; col < Columns() - 1 ; ++col )
		{
			//データを書き込み後にカンマを付ける
			file << Get(row,col) << ",";
		}

		//最後の行のみカンマを付けず改行を行う
		file << Get(row,col) << "\n";

	}

	return true;

}

/// <summary>
/// 行数を取得.
/// </summary>
int CSVReader::Rows()const
{
	return mData.size();
}

/// <summary>
/// 列数を取得.
/// </summary>
/// <param name="row">行数</param>
int CSVReader::Columns(int row)const
{
	if( Rows() == 0 )
	{
		return 0;
	}

	//指定した行の列数を返す
	return mData[row].size();
}

/// <summary>
/// データを文字列で取得.
/// </summary>
/// <param name="row">行数</param>
/// <param name="col">列数</param>
const std::string& CSVReader::Get(int row,int col) const
{
	return mData[row][col];
}

/// <summary>
/// データを整数型で取得.
/// </summary>
/// <param name="row">行数</param>
/// <param name="col">列数</param>
/// <returns>データ</returns>
int CSVReader::Geti(int row,int col) const
{
	//整数型に変更
	return std::atoi(Get(row,col).c_str());
}

/// <summary>
/// データを実数型で取得.
/// </summary>
/// <param name="row">行数</param>
/// <param name="col">列数</param>
/// <returns>データ</returns>
float CSVReader::Getf(int row,int col) const
{
	//文字列を変換して実数型で返す
	return (float)Getd(row,col);
}

/// <summary>
/// データを倍数実数型で取得.
/// </summary>
/// <param name="row">行数</param>
/// <param name="col">列数</param>
/// <returns>データ</returns>
double CSVReader::Getd(int row,int col) const
{
	//文字列を変換して倍精度実数型で返す
	return std::atof(Get(row,col).c_str());
}

/// <summary>
/// データの消去.
/// </summary>
void CSVReader::Clear()
{
	mData.clear();
}

/// <summary>
/// データを２次元配列を取得.
/// </summary>
std::vector<std::vector<std::string>> CSVReader::GetData()const
{
	return mData;
}

/// <summary>
/// 実数データを取得する.
/// </summary>
const DataFloat& CSVReader::GetFloatData()
{
	// データを初期化する.
	mDataFloat.clear();

	for( int row = 0 ; row < Rows() ; ++row )
	{
		RowFloat rowData;
		rowData.clear();

		for( int col = 0 ; col < Columns() ; ++col )
		{
			std::string s = Get( row , col );
			if( s[0] < '0' || s[0] > '9' )
			{
				continue;
			}
			rowData.push_back( Getf(row,col) );
		}

		if( rowData.size() != 0 )
		{
			mDataFloat.push_back( rowData );
		}
	}

	return mDataFloat;
}

/********** End of File ******************************************************/