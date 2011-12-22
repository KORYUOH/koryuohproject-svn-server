#ifndef _XMLWRITER_H_INCLUDED_
#define _XMLWRITER_H_INCLUDED_
#include	<boost/property_tree/xml_parser.hpp>
//#include	<boost/property_tree/detail/xml_parser_error.hpp>
#include	<string>

class XmlWriter{
private:
	XmlWriter(){};
	XmlWriter(const XmlWriter& xml);
	XmlWriter& operator = (const XmlWriter& xml);

public:
	static XmlWriter& getInstance(){
		static XmlWriter Instance;
		return Instance;
	}

	virtual ~XmlWriter(){};

public:
	/*
	 *	@brief	書き込み
	 *	@param[in]	xmlName	string	書き込みファイル名
	 *	@note	基本的にオーバーライドして使う
	 */
	void write(std::string xmlName);
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
