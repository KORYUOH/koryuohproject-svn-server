/**===File Commentary=======================================*/
/**
 *	@file	XmlReader.cpp
 *
 *	@brief	Xmlì«Ç›çûÇ›
 *
 *	@author	KORYUOH
 *
 *	@date	2012/01/26
 */
/**===File Include=========================================*/
#include	<XML/XmlReader.h>
#include	<boost/property_tree/ptree.hpp>
#include	<boost/property_tree/xml_parser.hpp>
#include	<boost/property_tree/detail/xml_parser_error.hpp>
#include	<memory>
#include	<string>
#include	<vector>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	<óvñÒ>
 *	@param[in]	<à¯êî>
 *	@attention	<íçà”èëÇ´>
 *	@note	<ÉÅÉÇèëÇ´>
 *	@author	KORYUOH
 *	@return	<ñﬂÇËíl>
 */
/**========================================================*/
void XmlReader::read(std::string name){

	//using boost::property_tree::ptree;
	//	vector<Struct>
 //   std::vector<Book> books;

 //   ptree pt;
 //   read_xml(filename, pt);
	//	tree.get<Type> return Type
	//	tree.get<>()	return exception xml_parser_error
	////foreach defined BOOST_FOREACH
 //   foreach (const ptree::value_type& child_, pt.get_child("bookList")) {
 //       const ptree& child = child_.second;
 //       const std::string title     = child.get<std::string>("<xmlattr>.title");
 //       const std::string author    = child.get<std::string>("<xmlattr>.author");

 //       books.push_back(Book(title, author));
 //   }

 //   std::for_each(books.begin(), books.end(), boost::mem_fn(&Book::print));

}

/**===End Of File==========================================*/