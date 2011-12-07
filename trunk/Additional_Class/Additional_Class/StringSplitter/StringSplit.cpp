/*==============================================*/
/**
 *		@FileName				StringSplitter.cpp
 *		@author					KORYUOH
 *		@CreateDate			2011/12/06	
 *		@LastUpdate			2011/12/07	KORYUOH
 *		@Note					This class is divided by the specified character string
 */
/*==============================================*/
/*==============================================*/
/**
 *										Include Headder Files
 *										ヘッダーファイル読み込み
 */
/*==============================================*/
#include "StringSplitter.h"
/*==============================================*/
/**
 *									Execute Split Method
 *										分割実行メソッド
 */
/*==============================================*/
void StringSplitter::split(){
	std::string tmp(m_Line);
	std::string temporary = tmp.substr(0,tmp.find_first_of(m_calam));
	tmp = tmp.substr(tmp.find(" ")+1,tmp.size());
	m_VSitor = m_VectorString.begin();
	do{
		m_VectorString.push_back(temporary);

		temporary = tmp.substr(0,tmp.find_first_of(" "));
		tmp = tmp.substr(tmp.find(" ")+1,tmp.size());
		m_VSitor = m_VectorString.end()-1;
	}while(tmp.compare(*m_VSitor));
	m_VSitor = m_VectorString.begin();	//使ったら元に戻してね
	m_pos = 0;
}
/*==============================================*/
/**
 *									Integer transform
 *											整数変換
 */
/*==============================================*/
inline int StringSplitter::toInteger(){
	return std::atoi(m_VectorString.at(m_pos).c_str());
}
/*==============================================*/
/**
 *										Float transform
 *										浮動小数点変換
 */
/*==============================================*/
inline float StringSplitter::toFloat(){
	return (float)(std::atof(m_VectorString.at(m_pos).c_str()));
}
/*******		End Of File		******************************************/