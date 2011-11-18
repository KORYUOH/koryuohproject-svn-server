#ifndef _SPLIT_H_
#define _SPLIT_H_

//////INCLUDE////
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//typedef basic_ofstream<char> ofstream;
//typedef basic_ifstream<char> ifstream;

class Split{
private:
	string mFiname;
	string mBuf;
	basic_ofstream<char> ofs1,ofs2;
	basic_ifstream<char> ifs;
public:
	Split(string name);//Construst
	~Split();//destruct
	void SplitFile();
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