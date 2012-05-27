/**===File Commentary=======================================*/
/**
 *	@file	CSVLoader.h
 *
 *	@brief	CSV読み込みクラスヘッダファイル
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
	/** データコンテナ型の定義 */
	typedef std::vector<std::string> DataContainer;
	/**
	 *	@brief	コンストラクタ
	 */
	CSVLoader();
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	ファイル名
	 */
	CSVLoader(const std::string& fileName);
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	ファイル名
	 */
	CSVLoader(const char* fileName);
	/**
	 *	@brief	デストラクタ
	 */
	virtual ~CSVLoader();
	/**
	 *	@brief	読み込み
	 *	@param[in]	読み込みファイル
	 */
	void load(const std::string& fileName);
	/**
	 *	@brief	無視文字行列設定
	 *	@param[in]	無視文字
	 */
	void addIgnoreString(const std::string& string);
	/**
	 *	@brief	読み込み
	 */
	void load();
	/**
	 *	@brief	データコンテナ取得
	 *	@return	コンテナ
	 */
	DataContainer getDataContainer();

private:
	/**
	 *	@brief	無視文字列判定
	 */
	bool ignoreCheck(std::string str)const;
	/**
	 *	@brief	押し込むか判定する
	 */
	void pushCheck(const std::string& str,std::basic_ifstream<char>& fst);

private:
	/**	メンバー変数*/
	std::string mFileName;
	DataContainer mDataContainer;
	DataContainer mIgnroeString;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/