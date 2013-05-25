/******************************************************************************
* File Name : CSVReader.h                        Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		CSVリーダークラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _CSV_READER_H_
#define _CSV_READER_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<string>
#include<vector>

/*---- 先行宣言 -------------------------------------------------------------*/

/// <summary>
/// 行数文字列用配列宣言.
/// </summary>
typedef std::vector<std::string>	Row;
/// <summary>
/// 文字列データ型.
/// </summary>
typedef std::vector<Row>			Data;
/// <summary>
/// 行数実数用配列宣言.
/// </summary>
typedef std::vector<float>			RowFloat;
/// <summary>
/// 実数データ型.
/// </summary>
typedef	std::vector<RowFloat>		DataFloat;
/// <summary>
/// 行数整数用配列宣言.
/// </summary>
typedef std::vector<int>			RowInt;
/// <summary>
/// 整数データ型.
/// </summary>
typedef	std::vector<RowInt>			DataInt;

/*---- クラスの実装 ---------------------------------------------------------*/

/// <summary>
/// CSV読み取りクラス.
/// </summary>
class CSVReader
{

public:

public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	CSVReader();
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="fileName">ファイル名</param>
	CSVReader(const std::string& fileName);
	/// <summary>
	/// デストラクタ.
	/// </summary>
	~CSVReader();
	/// <summary>
	/// データの読み込み.
	/// </summary>
	/// <param name="fileName">ファイル名</param>
	bool Load(const std::string& fileName);
	/// <summary>
	/// 行数を取得.
	/// </summary>
	int Rows()const;
	/// <summary>
	/// 列数を取得.
	/// </summary>
	/// <param name="row">行数</param>
	int Columns(int row = 0)const;
	/// <summary>
	/// データを文字列で取得.
	/// </summary>
	/// <param name="row">行数</param>
	/// <param name="col">列数</param>
	const std::string& Get(int row,int col) const;
	/// <summary>
	/// データを整数型で取得.
	/// </summary>
	/// <param name="row">行数</param>
	/// <param name="col">列数</param>
	/// <returns>データ</returns>
	int Geti(int row,int col) const;
	/// <summary>
	/// データを実数型で取得.
	/// </summary>
	/// <param name="row">行数</param>
	/// <param name="col">列数</param>
	/// <returns>データ</returns>
	float Getf(int row,int col) const;
	/// <summary>
	/// データを倍数実数型で取得.
	/// </summary>
	/// <param name="row">行数</param>
	/// <param name="col">列数</param>
	/// <returns>データ</returns>
	double Getd(int row,int col) const;
	/// <summary>
	/// 実数データを取得する.
	/// </summary>
	/// <returns>実数データ</returns>
	const DataFloat& GetFloatData();

	/// <summary>
	/// 保存.
	/// </summary>
	/// <returns>保存できた時真、できなければ偽を返す</returns>
	bool Save(const std::string& fileName);
	/// <summary>
	/// データを２次元配列を取得.
	/// </summary>
	std::vector<std::vector<std::string>> GetData()const;

private:
	/// <summary>
	/// データの消去.
	/// </summary>
	void Clear();

public:
	/// <summary>
	//データ保存用
	/// </summary>
	Data		mData;
	/// <summary>
	/// 実数データ保存用.
	/// </summary>
	DataFloat	mDataFloat;
};


#endif

/********** End of File ******************************************************/
