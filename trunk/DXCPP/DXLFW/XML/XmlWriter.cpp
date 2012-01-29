/**===File Commentary=======================================*/
/**
 *	@file	XmlWriter.cpp
 *
 *	@brief	XMLの書き出し
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
 *	@brief	書き出し処理
 *	@param[in]	書き出しファイル名
 *	@param[in]	書き出しツリー
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
 *	@brief	<要約>
 *	@param[in]	<引数>
 *	@attention	<注意書き>
 *	@note	<メモ書き>
 *	@author	<作者名>
 *	@return	<戻り値>
 */
/**========================================================*/
void XmlWriter::write(std::string FileName){
	////Sample
	//std::vector<std::string> books;
	//books.push_back("ジョジョの奇妙な冒険1部「ファントムブラッド」");
	//books.push_back("ジョジョの奇妙な冒険2部「戦闘潮流」");
	//books.push_back("ジョジョの奇妙な冒険3部「スターダストクルセイダーズ」");
	//books.push_back("ジョジョの奇妙な冒険4部「ダイアモンドは砕けない」");
	//books.push_back("ジョジョの奇妙な冒険5部「黄金の風」");
	//books.push_back("ジョジョの奇妙な冒険6部「ストーンオーシャン」");
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