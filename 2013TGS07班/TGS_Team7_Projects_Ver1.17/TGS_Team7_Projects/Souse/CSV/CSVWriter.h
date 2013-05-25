/******************************************************************************
* File Name : CsvReader.h                         Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		CSVファイルの書き込みクラス．
*
******************************************************************************/
#ifndef _CSV_WRITER_H_
#define _CSV_WRITER_H_


/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<string>
#include<vector>

/*---- CSV書き込みクラスの宣言 ----------------------------------------------*/

class CSVWriter
{

private:
	//行数用の配列宣言
	typedef std::vector<std::string>	Row;
	typedef std::vector<Row>			Rows;


public:
	/** コンストラクタ **/
	CSVWriter();
	/** デストラクタ **/
	~CSVWriter();

public:
	//保存(fileName:ファイル名)
	bool save(const std::string& fileName, Rows data);
	//データの保存(fileName:ファイル名,row:行数値,col:列数値)
	bool dataSave(const std::string& fileName,int row,int col,std::string data);
	//データの保存(fileName:ファイル名,row:行数値,col:列数値)
	bool dataSave(const std::string& fileName,int row,int col,int data);
	//データの保存(fileName:ファイル名,row:行数値,col:列数値)
	bool dataSave(const std::string& fileName,int row,int col,float data);

};

#endif

/********** End of File ******************************************************/