#include "encorder.h"
#include <iostream>
using namespace Encorder;
//	�����_���擾
int CEncorder::GetRandom(int min,int max){
	return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

CEncorder::CEncorder(){
}

CEncorder::CEncorder(string InputFileName,string OutputFileName,string Keyword):
mInputFileName(InputFileName),mOutputFileName(OutputFileName),
mKey(Keyword){
}

CEncorder::CEncorder(char InputFileName[],char OutputFileName[],char Keyword[]):
mInputFileName(InputFileName),mOutputFileName(OutputFileName),
mKey(Keyword){
}
//	���͌���ݒ�
void CEncorder::setFileNameInput(string Str){
	mInputFileName = Str;
}
//	�o�͐��ݒ�
void CEncorder::setFileNameOutput(string Str){
	mOutputFileName = Str;
}

void CEncorder::setKey(string Str){
	mKey = Str;
}

void CEncorder::OpenFile(){
	ifs.open(mInputFileName,ios_base::in);
	ofs.open(mOutputFileName,ios_base::out);
}

void CEncorder::CloseFile(){
	ifs.close();
	ofs.close();
}

string CEncorder::engine(){
	string tmpstr;
	getline(ifs,tmpstr);
	for (unsigned int i=0;i < tmpstr.length();i++){
		tmpstr[i] ^= GetRandom(0,255);
	}
	return tmpstr;
}
//	�����_���ݒ�
void CEncorder::setRandSeed(){
	int early = 0;
	for (int i = 0;i!=mKey.length();i++) {
		early += mKey[i];
	}
	
	srand(early);
}

//���s��
void CEncorder::Execute(){
	if(mInputFileName.empty()){
		cout << "Input FileName:?";
		cin >> mInputFileName;
	}

	if(mOutputFileName.empty()){
		cout << "Output FileName:?";
		cin >> mOutputFileName;
	}

	if(mKey.empty()){
		cout << "Coding Keyword:?";
		cin >> mKey;
	}
	setRandSeed();
	OpenFile();
	while(!ifs.fail()){
		ofs << engine() << endl;
	}
	CloseFile();
}