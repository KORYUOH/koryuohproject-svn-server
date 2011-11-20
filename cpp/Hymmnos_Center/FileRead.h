#ifndef __FILEREAD
#define __FILEREAD
#include <vector>
#include <string>
#include <fstream>

#ifndef __UseStringVector
#define __UseStringVector
typedef std::vector<std::string> StrVector;
typedef StrVector::iterator StrVectItor;
#endif

#ifndef	__UseFileReadStream
#define	__UseFileReadStream
typedef std::basic_ifstream<char> FileReadStream;
#endif

namespace CSV{
	using namespace std;
	class FileRead{
		FileReadStream m_FileStream;
		string m_ReadLine,m_calam;
		StrVector m_Word;
		StrVectItor m_WordItor;
	public:
		FileRead();
		FileRead(string FileName);
		FileRead(string FileName,string caram);
		~FileRead();
		void open(string FileName);
		void close();
		void setCaram(string caram);
		string getStrLine()const;
		string getWord();
		string getWord(unsigned int index);
		string getWord2(unsigned int index)const;
		int length()const;
		bool fail()const;
		void readline();
		void clear();
	private:
		void Split(string split_caram);
	};
};

#endif