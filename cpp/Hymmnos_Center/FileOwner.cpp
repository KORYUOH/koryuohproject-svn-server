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

void FileOwner::SetReadFileName(string acceptFileName){
	Reader.open(acceptFileName);
}