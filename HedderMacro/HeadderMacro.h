#ifndef _HEADER_MACRO_H_
#define _HEADER_MACRO_H_
////////////////////////////
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
////////////////////////////
class Macro{
public:
	Macro(){};
	Macro(string str){
		FileCmd(str);
	};
	void exec();
private:
	void FileCmd(string FileName);
	string FileName;
	void SetFileName();
};
#endif