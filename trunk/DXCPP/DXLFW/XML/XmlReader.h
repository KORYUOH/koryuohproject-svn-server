#ifndef _XMLREADER_H_INCLUDED_
#define _XMLREADER_H_INCLUDED_
#include	<string>
#include	<vector>

class XmlReader{
private:
	/*
	 *		@brief	コンストラクタ
	 *		@brief	コピーコンストラクタ
	 *		@brief	代入演算子オーバーロード
	 *		@note	XmlReaderのコンストラクタ、コピーコンストラクタ、代入演算子オーバーロードの外部呼び出し禁止
	 */

	XmlReader(){};
	XmlReader(const XmlReader& xml){};
	XmlReader& operator= (const XmlReader& xml){};

public:
	/*
	 *	シングルトンデザインパターン
	 *	実体を得る
	 */
	static XmlReader& getInstance(){
		static XmlReader Instance;
		return Instance;
	}

	/*
	 *	@brief	仮想デストラクタ
	 */
	virtual ~XmlReader(){};
public:
	/*
	 *	@brief	読み込み
	 *	@param[in]	xmlName	string	読み込みファイル名
	 *	@note	基本的にオーバーライドして使う
	 */
	virtual void read(std::string xmlName);
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



#endif // _XMLREADER_H_INCLUDED_
