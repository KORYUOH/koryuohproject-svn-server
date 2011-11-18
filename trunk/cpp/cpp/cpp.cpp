#include "cpp.h"
#include <iostream>
using namespace NS_CPP;

CPP::CPP(){
}

CPP::CPP (string familyname , string uniquename){
	m_name[familyname] = uniquename;
}

MapStrItr CPP::getMapStrItr(){
	return m_MSI;
}
void CPP::setItratorBegin(){
	m_MSI = m_name.begin();
}

void CPP::output(){
	output(getMapStrItr());
}

void CPP::output(MapStrItr itr){
	cout <<itr->first << itr->second <<endl;
}

void CPP::add (string familyname , string uniquename){
	m_name[familyname] = uniquename;
}

string CPP::Getdata_first(){
	return m_MSI->first;
}

string CPP::Getdata_second(){
	return m_MSI->second;
}