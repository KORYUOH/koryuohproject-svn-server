#ifndef _XMLWRITER_H_INCLUDED_
#define _XMLWRITER_H_INCLUDED_
#include	<boost/property_tree/xml_parser.hpp>
#include	<string>

class XmlWriter{
private:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@brief	�R�s�[�R���X�g���N�^
	 *	@brief	������Z�q�I�[�o�[���[�h
	 *	@note	�e��O���ďo���̋֎~
	 *	@author	KORYUOH
	 *	@return	<�߂�l>
	 */
	XmlWriter(){};
	XmlWriter(const XmlWriter& xml);
	XmlWriter& operator = (const XmlWriter& xml);

private:
	/**
	 *	@brief	�����o��
	 *	@param[in]	�t�@�C����
	 *	@param[in]	�����o���c���[
	 *	@author	KORYUOH
	 */
	void writer(const std::string xmlName,boost::property_tree::ptree& ptree);

public:
	/**
	 *	@brief	���̂��擾
	 *	@author	KORYUOH
	 *	@return	XmlWriter�̎��� �h�b�g�A�N�Z�X�\
	 */
	static XmlWriter& getInstance(){
		static XmlWriter Instance;
		return Instance;
	}

	/**
	 *	@brief	���z�f�X�g���N�^
	 *	@author	KORYUOH
	 */
	virtual ~XmlWriter(){};

public:
	/*
	 *	@brief	��������
	 *	@param[in]	xmlName	string	�������݃t�@�C����
	 *	@note	��{�I�ɃI�[�o�[���C�h���Ďg��
	 */
	virtual void write(std::string xmlName);
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
