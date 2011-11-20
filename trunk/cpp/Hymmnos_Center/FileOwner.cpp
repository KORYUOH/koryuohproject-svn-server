#include "FileOwner.h"

using namespace CSV;

FileOwner::FileOwner(){
};

FileOwner::FileOwner(string ReadFileName,string WriteFileName):
Reader(ReadFileName),
Writer(WriteFileName)
{}

FileOwner::~FileOwner(){
}

void FileOwner::FileIO(){
	for(int i=0;i<Reader.length();i++)
		Writer.push_Back( Reader.getWord() );
	Writer.Write_Line_Flush();
}

void FileOwner::OpenReadFile(string acceptFileName){
	Reader.open(acceptFileName);
}

void FileOwner::OpenWriteFile(string acceptFileName){
	Writer.open(acceptFileName);
}

void FileOwner::CloseReadFile(){
	Reader.close();
}

void FileOwner::CloseWriteFile(){
	Writer.close();
}

string FileOwner::getReaderWord(unsigned int index){
	return Reader.getWord(index);
}

bool FileOwner::ReadFileFail()const{
	return Reader.fail();
}