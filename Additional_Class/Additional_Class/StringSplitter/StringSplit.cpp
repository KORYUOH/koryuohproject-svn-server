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
 *										�w�b�_�[�t�@�C���ǂݍ���
 */
/*==============================================*/
#include "StringSplitter.h"
/*==============================================*/
/**
 *									Execute Split Method
 *										�������s���\�b�h
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
	m_VSitor = m_VectorString.begin();	//�g�����猳�ɖ߂��Ă�
	m_pos = 0;
}
/*==============================================*/
/**
 *									Integer transform
 *											�����ϊ�
 */
/*==============================================*/
inline int StringSplitter::toInteger(){
	return std::atoi(m_VectorString.at(m_pos).c_str());
}
/*==============================================*/
/**
 *										Float transform
 *										���������_�ϊ�
 */
/*==============================================*/
inline float StringSplitter::toFloat(){
	return (float)(std::atof(m_VectorString.at(m_pos).c_str()));
}
/*******		End Of File		******************************************/