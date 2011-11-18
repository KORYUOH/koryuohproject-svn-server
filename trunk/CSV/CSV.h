#ifndef _CSV_H_
#define _CSV_H_
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class CSVReader{
private:
	string mFileName,mBuf;
	basic_ifstream<char> ifs;
	basic_ofstream<char> ofs;
	void split(string spstr);
public:
	CSVReader(string str);
	void Load();
//	void out(string FileName);
};
#endif