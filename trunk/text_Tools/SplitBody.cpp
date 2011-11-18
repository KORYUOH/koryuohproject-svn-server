#include "Split.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Split::Split(string name):mFiname(name){
};
Split::~Split(){};

void Split::SplitFile(){
	ofs1.open( mFiname+"_s1.txt" ,ios::out);
	ofs2.open( mFiname+"_s2.txt" ,ios::out);
	ifs.open( mFiname+".txt",ios::in);
	while(!ifs.fail()){
		getline(ifs,mBuf);
		ofs1 << mBuf << endl;
		getline(ifs,mBuf);
		ofs2 << mBuf << endl;
		
	}
}