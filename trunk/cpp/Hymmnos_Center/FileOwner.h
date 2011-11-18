#ifndef __FILEOWNER
#define __FILEOWNER
#include "FileRead.h"
#include "FileWrite.h"
namespace CSV{
	class FileOwner{
		FileRead m_Reader;
		FileWrite m_Writer;
	public:
		FileOwner();
		FileOwner(std::string ReadFileName,std::string WriteFileName);
		~FileOwner();
	};
};

#endif