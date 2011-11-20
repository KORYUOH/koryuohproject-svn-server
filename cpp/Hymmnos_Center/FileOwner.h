#ifndef __FILEOWNER
#define __FILEOWNER
#include "FileRead.h"
#include "FileWrite.h"
namespace CSV{
	class FileOwner{
	public:
		FileRead Reader;
		FileWrite Writer;
	public:
		FileOwner();
		FileOwner(std::string ReadFileName,std::string WriteFileName);
		void OpenReadFile(string acceptFileName);
		void OpenWriteFile(string acceptFileName);
		void CloseReadFile();
		void CloseWriteFile();
		void FileIO();
		string getReaderWord();
		string getReaderWord(unsigned int index);
		bool ReadFileFail()const;
		~FileOwner();
	};
};

#endif