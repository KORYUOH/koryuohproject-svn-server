#ifndef	__FILEWRITE
#define	__FILEWRITE

#include <vector>
#include <string>
#include <fstream>

typedef std::vector<std::string> StrVector;
typedef typename StrVector::iterator StrVectItor;
typedef std::basic_ofstream<char> FileWriteStream;

namespace CSV{
	using namespace std;
	class FileWrite{
		FileWriteStream m_FileStream;
		string m_ReadLine,m_calam;
		StrVector m_Word;
		StrVectItor m_WordItor;
	};
};
#endif