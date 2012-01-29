/**===File Commentary=======================================*/
/**
 *	@file	XmlWriter.cpp
 *
 *	@brief	XML�̏����o��
 *
 *	@author	KORYUOH
 *
 *	@date	2012/01/26
 */
/**===File Include=========================================*/
#include	<XML/XmlWriter.h>
#include	<boost/property_tree/ptree.hpp>
#include	<boost/property_tree/xml_parser.hpp>
#include	<memory>
#include	<string>
#include	<vector>
/**===Class Implementation=================================*/
/**========================================================*/
/**
 *	@brief	�����o������
 *	@param[in]	�����o���t�@�C����
 *	@param[in]	�����o���c���[
 *	@author	KORYUOH
 */
/**========================================================*/
void XmlWriter::writer(const std::string xmlName,boost::property_tree::ptree& ptree){
			boost::property_tree::xml_parser::write_xml(
			xmlName,
			ptree,
			std::locale(),
			boost::property_tree::xml_parser::xml_writer_make_settings(
				'	',
				1,
				boost::property_tree::xml_parser::widen<char>("utf-8")
			)
		);
}
/**========================================================*/
/**
 *	@brief	<�v��>
 *	@param[in]	<����>
 *	@attention	<���ӏ���>
 *	@note	<��������>
 *	@author	<��Җ�>
 *	@return	<�߂�l>
 */
/**========================================================*/
void XmlWriter::write(std::string FileName){
	////Sample
	//std::vector<std::string> books;
	//books.push_back("�W���W���̊�Ȗ`��1���u�t�@���g���u���b�h�v");
	//books.push_back("�W���W���̊�Ȗ`��2���u�퓬�����v");
	//books.push_back("�W���W���̊�Ȗ`��3���u�X�^�[�_�X�g�N���Z�C�_�[�Y�v");
	//books.push_back("�W���W���̊�Ȗ`��4���u�_�C�A�����h�͍ӂ��Ȃ��v");
	//books.push_back("�W���W���̊�Ȗ`��5���u�����̕��v");
	//books.push_back("�W���W���̊�Ȗ`��6���u�X�g�[���I�[�V�����v");
	//books.push_back("STEEL BALL RUN");
	//using namespace boost::property_tree;
	//ptree tree;
	//try{
	//	std::for_each(books.begin(),books.end(),[&](std::string str){tree.add("Hirohico.JoJo.part",str);});

	//	tree.add("Hirohiko.Other","Baoh");
	//	ptree& child = tree.add("Hirohiko.Other","");
	//	child.put("<xmlattr>.foo","fool");

	//	boost::property_tree::xml_parser::write_xml(
	//		FileName,
	//		tree,
	//		std::locale(),
	//		boost::property_tree::xml_parser::xml_writer_make_settings(
	//			'	',
	//			1,
	//			boost::property_tree::xml_parser::widen<char>("utf-8")
	//		)
	//	);
	//}catch(xml_parser_error e){

	//}
}

/**===End Of File==========================================*/