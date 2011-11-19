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
		void SetReadFileName(string acceptFileName);
		void SetWriteFileName(string acceptFileName);
		void FileIO();
		~FileOwner();
	};
};

#endif