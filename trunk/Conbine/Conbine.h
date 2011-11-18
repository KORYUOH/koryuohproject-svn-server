#ifndef _CONBINE_H_
#define _CONBINE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Conbine{
private:
	bool mLineNoFrag;
	string mFile1,mFile2;
	basic_ofstream<char> ofs;
	basic_ifstream<char> ifs1,ifs2;
	string mBuf;
public:
	Conbine(string str1,string str2){
		mFile1 = str1;
		mFile2 = str2;
		mLineNoFrag = false;
	};
	Conbine(){mLineNoFrag = false;};
	~Conbine(){};
	void SetFile(string str1,string str2){
		mFile1 = str1;
		mFile2 = str2;
	}
	void Exec();
};
class IFS{
private:
	string s1;
public:
	IFS(string str){
		s1 = str;
	};

	IFS(){};

	void set(string str){
		s1 = str;
	}
	string get(){
		return s1;
	}
	void q_in(){
		string str;
		cout << "INPUT (File Type txt) :";
		cin >> str;
		s1 = str;
	}
};


#endif