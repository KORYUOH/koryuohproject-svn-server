/*==============================================*/
/**
 *		@FileName				StringSplitter.h
 *		@author					KORYUOH
 *		@CreateDate			2011/12/06	
 *		@LastUpdate			2011/12/07	KORYUOH
 *		@Note					This class is divided by the specified character string
 */
/*==============================================*/
#ifndef __StringSplitter
#define __StringSpritter
#include <vector>
#include <string>
/*==============================================*/
class StringSplitter{
public:
/*==============================================*/
/**
 *										constructor
 *										�R���X�g���N�^
 _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
 *		@param[in]	aLine			string			//split source
 *		@param[in]	aCalam		string			//split charctor
 */
/*==============================================*/
	StringSplitter(std::string aLine,std::string aCalam):m_Line(aLine),m_calam(aCalam),m_pos(0){
		split();
	};
/*==============================================*/
/**
 *											Virtual destructor
 *											���z�f�X�g���N�^
 */
/*==============================================*/
	virtual ~StringSplitter(){};
/*==============================================*/
private:
/*==============================================*/
/**
 *									Ban the copy constructor
 *									�R�s�[�R���X�g���N�^�̋֎~
 */
/*==============================================*/
	StringSplitter(const StringSplitter& are);
/*==============================================*/
/**
 *									Ban Assignment
 *									����̋֎~
 */
/*==============================================*/
	StringSplitter& operator=(const StringSplitter& are);
/*==============================================*/
private:
/*==============================================*/
/**
 *									Member Variables
 *										�����o�[�ϐ�
 */
/*==============================================*/
	std::string m_Line;
	std::string m_calam;
	int m_pos;
	std::vector<std::string> m_VectorString;
	std::vector<std::string>::iterator m_VSitor;
/*==============================================*/
private:
/*==============================================*/
/**
 *									Execute Split Method
 *										�������s���\�b�h
 */
/*==============================================*/
	void split();
/*==============================================*/
public:
/*==============================================*/
/**
 *										Operator Overloading		
 *										���Z�q�I�[�o�[���[�h
 */
/*==============================================*/
	StringSplitter& operator >> (std::string& target){
		target = (*this).m_VectorString.at(this->m_pos) ;
		return *this;
	}
	StringSplitter& operator << (const std::string& target){
		m_Line = target;
		m_VectorString.clear();
		split();
		return *this;
	}
	StringSplitter& operator++(int){
		m_pos++;
		return *this;
	}
	StringSplitter& operator++(){
		m_pos++;
		return *this;
	}
	StringSplitter& operator --(int){
		if(m_pos>0)
			m_pos--;
		return *this;
	}
	StringSplitter& operator--(){
		if(m_pos>0)
			--m_pos;
		return *this;
	}
	std::string operator[] (int num){
		return m_VectorString[num];
	}
/*==============================================*/
public:
/*==============================================*/
/**
 *									Additional Methods
 *										�ǉ����\�b�h
 */
/*==============================================*/

	int toInteger();
	float toFloat();

	void CHG_Calam(std::string aCalam){
		m_calam = aCalam;
	}

};
#endif
/*******		End Of File		******************************************/