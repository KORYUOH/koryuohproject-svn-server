/**===File Commentary=======================================*/
/**
 *	@file	CSVWriter.h
 *
 *	@brief	CSV書き込み
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
	 *	@brief	コンストラクタ
	 *	@param[in]	ファイル名
	 */
	CSVWriter(const std::string& fileName);
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	ファイル名
	 *	@param[in]	出力フラグ
	 */
	CSVWriter(const std::string& filename,int outputFlag); 
	/**
	 *	@brief	コンストラクタ
	 */
	CSVWriter();
	/**
	 *	@brief	文字列追加
	 *	@param[in]	文字列
	 */
	void addString(const std::string& str);
	/**
	 *	@brief	書き出し
	 */
	void write();
	/**
	 *	@brief	書き出し
	 *	@param[in]	ファイル名
	 */
	void write(const std::string& fileName);
	/**
	 *	@brief	書き出し
	 *	@param[in]	出力フラグ
	 */
	void write(int out);
	/**
	 *	@brief	書き出し
	 *	@param[in]	ファイル名
	 *	@param[in]	出力フラグ
	 */
	void write(const std::string& fileName,int out);
	/**
	 *	@brief	ファイル名設定
	 *	@param[in]	ファイル名
	 */
	void setFileName(const std::string& fileName);
	/**
	 *	@brief	書き出しデータ設定
	 *	@param[in]	書き出しデータ
	 */
	void setDataContainer(const WriteDataContainer& dataContainer);
	/**
	 *	@brief	出力モード設定
	 *	@param[in]	出力モード
	 */
	void setOutMode(int OutMode);
	/**
	 *	@brief	文字スキップ
	 *	@param[in]	スキップ文字数
	 */
	void setSkipCharactors(int counter);
	/**
	 *	@brief	出力フラグ
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
	/**	メンバー変数*/
	WriteDataContainer mContainer;
	std::string mFileName;
	int mOutMode;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/