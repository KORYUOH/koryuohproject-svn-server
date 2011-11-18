//////////////////////////////////
#ifndef _HYMMNOS_H_
#define _HYMMNOS_H_
//////////////////////////////////
#include <iostream>
#include <string>
#include <map>
#include <fstream>
//////////////////////////////////
//typedef basic_ofstream<char> 
//typedef basic_ifstream<char> 
//////////////////////////////////
using namespace std;
typedef map<string,string> StrMap;
typedef StrMap::iterator StrMapItr;
//////////////////////////////////
class hymmnos{
protected:   //検索、CSVバッファ
	string mKeyStr,mCSVBuff;
	StrMap mMap;
	StrMapItr mMapItr;
//////////////////////////////////
public:
	hymmnos();
	void Split();
};
//////////////////////////////////
class Load: public hymmnos{
private:
	basic_ifstream<char> miftx;
	basic_ifstream<char> mifcs;
	basic_ofstream<char> moftx;
protected:
	string word;
public:
	void open(string FileName);
	void close();
	void csv();
	void splitter();
	void text();
};
#endif
//////////////////////////////////