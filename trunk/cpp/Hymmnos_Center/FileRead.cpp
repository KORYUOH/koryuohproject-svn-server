#include "FileRead.h"
using namespace CSV;

FileRead::FileRead(){
}

FileRead::FileRead(string FileName):m_FileStream(FileName,ios::in),
	m_calam(",")
{
}
FileRead::FileRead(string FileName,string caram):m_FileStream(FileName,ios::in),
	m_calam(caram)
{
}

FileRead::~FileRead(){
	m_FileStream.close();
}

void FileRead::open(string FileName){
	m_FileStream.open(FileName,ios::in);
}

void FileRead::close(){
	m_FileStream.close();
}

void FileRead::readline(){
	getline(m_FileStream,m_ReadLine);
	Split(m_calam);
}
void FileRead::setCaram(string caram){
	m_calam = caram;
}


string FileRead::getStrLine() const{
	return m_ReadLine;
}

string FileRead::getWord(){
	StrVectItor temp = m_WordItor;
	if(m_WordItor != m_Word.end())
		m_WordItor++;
	return	(temp != m_Word.end())? *temp:" ";
}

string FileRead::getWord(unsigned int index){
	StrVectItor temp = m_Word.begin();
	for(unsigned int i=0;i<index && i<m_Word.size();i++)
	if(temp != m_Word.end())
		temp++;
	return	(temp != m_Word.end())? *temp:" getWord Index Error \n";
}

void FileRead::Split(string split_caram){
	string tmp = m_ReadLine;//tmpにm_ReadLineをコピーしておく
	string temporary = tmp.substr(0,tmp.find_first_of(split_caram));
	tmp = tmp.substr(tmp.find_first_of(split_caram)+1);
	m_WordItor = m_Word.begin();
	do{
		m_Word.push_back(temporary);

		temporary = tmp.substr(0,tmp.find_first_of(split_caram));
		tmp = tmp.substr(tmp.find(split_caram)+1,tmp.size());
		m_WordItor = m_Word.end()-1;//無効になったから書き直し
	}while(tmp.compare(*m_WordItor));
	m_WordItor = m_Word.begin();	//使ったら元に戻してね
}

int FileRead::length()const{
	return m_Word.size();
}