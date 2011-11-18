#ifndef __FILEREAD
#define __FILEREAD
#include <vector>
#include <string>
#include <fstream>

typedef std::vector<std::string> StrVector;
typedef StrVector::iterator StrVectItor;
typedef std::basic_ifstream<char> FileReadStream;

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
	private:
		void readline();
		void Split(string split_caram);
	};
};

#endif