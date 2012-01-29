#ifndef _XMLWRITER_H_INCLUDED_
#define _XMLWRITER_H_INCLUDED_
#include	<boost/property_tree/xml_parser.hpp>
#include	<string>

class XmlWriter{
private:
	/**
	 *	@brief	コンストラクタ
	 *	@brief	コピーコンストラクタ
	 *	@brief	代入演算子オーバーロード
	 *	@note	各種外部呼出しの禁止
	 *	@author	KORYUOH
	 *	@return	<戻り値>
	 */
	XmlWriter(){};
	XmlWriter(const XmlWriter& xml);
	XmlWriter& operator = (const XmlWriter& xml);

private:
	/**
	 *	@brief	書き出し
	 *	@param[in]	ファイル名
	 *	@param[in]	書き出しツリー
	 *	@author	KORYUOH
	 */
	void writer(const std::string xmlName,boost::property_tree::ptree& ptree);

public:
	/**
	 *	@brief	実体を取得
	 *	@author	KORYUOH
	 *	@return	XmlWriterの実体 ドットアクセス可能
	 */
	static XmlWriter& getInstance(){
		static XmlWriter Instance;
		return Instance;
	}

	/**
	 *	@brief	仮想デストラクタ
	 *	@author	KORYUOH
	 */
	virtual ~XmlWriter(){};

public:
	/*
	 *	@brief	書き込み
	 *	@param[in]	xmlName	string	書き込みファイル名
	 *	@note	基本的にオーバーライドして使う
	 */
	virtual void write(std::string xmlName);
	/*===============================================
	 *				この先オーバーライド
	 *===============================================
	 *	ここから
	 */



	/*===============================================
	 *	ここまで
	 *===============================================
	 */
};
#endif // _XMLWRITER_H_INCLUDED_
