#include "FileWrite.h"

using namespace CSV;

FileWrite::FileWrite(){
}

FileWrite::FileWrite(string acceptFileName):m_FileStream(acceptFileName,ios::out){
}

void FileWrite::setWriteLine(string acceptWriteString){
	m_WriteLine = acceptWriteString;
}

FileWrite::~FileWrite(){
	m_FileStream.close();
}

void FileWrite::Write_Line(){
	m_FileStream << m_WriteLine;
}

void FileWrite::Write_Word(){
	m_FileStream << *m_WordItor;
	m_WordItor++;
}
void FileWrite::Write_Line_Flush(){
	m_FileStream << m_WriteLine << endl;
}
void FileWrite::Write_Word_Flush(){
	m_FileStream << *m_WordItor << endl;
	m_WordItor++;
}

void FileWrite::open(string acceptFileName){
	m_FileStream.open(acceptFileName,ios::out);
}
void FileWrite::close(){
	m_FileStream.close();
}
void FileWrite::Itor_begin(){
	m_WordItor = m_Word.begin();
}

void FileWrite::push_Back(string str){
	m_Word.push_back(str);
	Itor_begin();
}

int FileWrite::length()const{
	return m_Word.size();
}

void FileWrite::Write_Word_Line_Flush(){
	for(int i=0;i<length();i++){
	m_FileStream << *m_WordItor << " ";
	m_WordItor++;
	}
	m_FileStream << endl;
	m_Word.clear();
	Itor_begin();
}