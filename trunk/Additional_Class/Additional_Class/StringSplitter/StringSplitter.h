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
 *										コンストラクタ
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
 *											仮想デストラクタ
 */
/*==============================================*/
	virtual ~StringSplitter(){};
/*==============================================*/
private:
/*==============================================*/
/**
 *									Ban the copy constructor
 *									コピーコンストラクタの禁止
 */
/*==============================================*/
	StringSplitter(const StringSplitter& are);
/*==============================================*/
/**
 *									Ban Assignment
 *									代入の禁止
 */
/*==============================================*/
	StringSplitter& operator=(const StringSplitter& are);
/*==============================================*/
private:
/*==============================================*/
/**
 *									Member Variables
 *										メンバー変数
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
 *										分割実行メソッド
 */
/*==============================================*/
	void split();
/*==============================================*/
public:
/*==============================================*/
/**
 *										Operator Overloading		
 *										演算子オーバーロード
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
 *										追加メソッド
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