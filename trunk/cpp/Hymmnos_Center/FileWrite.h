#ifndef	__FILEWRITE
#define	__FILEWRITE

#include <vector>
#include <string>
#include <fstream>

#ifndef __UseStringVector
#define __UseStringVector
typedef std::vector<std::string> StrVector;
typedef StrVector::iterator StrVectItor;
#endif

#ifndef	__UseFileWrireStream
#define	__UseFileWrireStream
typedef std::basic_ofstream<char> FileWriteStream;
#endif

namespace CSV{
	using namespace std;
	class FileWrite{
		FileWriteStream m_FileStream;
		string m_WriteLine,m_calam;
		StrVector m_Word;
		StrVectItor m_WordItor;
	public:
		FileWrite();
		FileWrite(string acceptFileName);
		~FileWrite();
		void open(string acceptFileName);
		void close();
		void setWriteLine(string acceptString);
		void Write_Line();
		void Write_Word();
		void Write_Line_Flush();
		void Write_Word_Flush();
		void Itor_begin();
		void push_Back(string str);
		//// Operator

	};
};
#endif