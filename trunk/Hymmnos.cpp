#include "Hymmnos.h"
using namespace Ar_Tonelico;

//Default constractor
EOLIA::EOLIA(){
	m_hymmItr = m_hymm.begin();
}
//Destructor
EOLIA::~EOLIA(){
}
//Constractor
EOLIA::EOLIA(string str){
	m_hymm[str.substr(0,str.find(","))] = str.substr(str.find(",")+1); 
}
//Constractor
EOLIA::EOLIA(string str1,string str2){
	m_hymm[str1] = str2;
}
//Constractor
EOLIA::EOLIA(char str[]){
	string tmp(str);
	m_hymm[tmp.substr(0,tmp.find(","))] = tmp.substr(tmp.find(",")+1);
}
//Constractor
EOLIA::EOLIA(char str1[],char str2[]){
	m_hymm[str1] = str2;
}

//Add Function
// throw string
//return Nothing
void EOLIA::add(string str){
	m_hymm[str.substr(0,str.find(","))] = str.substr(str.find(",")+1);
}
//Add Function
// throw string string
// return Nothing
void EOLIA::add(string str1,string str2){
	m_hymm[str1] = str2;
}
// Get Iterator data
// throw Nothing
// return string
string EOLIA::getIteratorData_First() const {
	return m_hymmItr->first;
}
// Get Iterator data
// throw Nothing
// return string
string EOLIA::getIteratorData_Second() const {
	return m_hymmItr->second;
}
/************* OverLoad *************/
EOLIA EOLIA::operator ++( int ){
	EOLIA ClassOld = *this;
	*this->m_hymmItr++;
	return ClassOld;
}
EOLIA EOLIA::operator --( int ){
	EOLIA ClassOld = *this;
	*this->m_hymmItr--;
	return ClassOld;
}
EOLIA& EOLIA::operator++ (){
	++m_hymmItr;
	return *this;
}EOLIA& EOLIA::operator-- (){
	--m_hymmItr;
	return *this;
}
/**********************************/
void EOLIA::SetItrBegin(){
	m_hymmItr = m_hymm.begin();
}

string EOLIA::Cmp_str(string str) {
	for(m_hymmItr = m_hymm.begin(); m_hymmItr != m_hymm.end();m_hymmItr++){
		if(m_hymmItr->first == str)
			return m_hymmItr->second;
	}
	return str;
}