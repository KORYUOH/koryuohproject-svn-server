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
	 *	@brief	��������
	 *	@param[in]	xmlName	string	�������݃t�@�C����
	 *	@note	��{�I�ɃI�[�o�[���C�h���Ďg��
	 */
	void write(std::string xmlName);
	/*===============================================
	 *				���̐�I�[�o�[���C�h
	 *===============================================
	 *	��������
	 */



	/*===============================================
	 *	�����܂�
	 *===============================================
	 */
};
#endif // _XMLWRITER_H_INCLUDED_
