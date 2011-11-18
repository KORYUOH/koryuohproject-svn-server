#ifndef __ENCORDER_H_
#define __ENCORDER_H_ //2重インクルード防止措置
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>

namespace Encorder{
using namespace std;

class CEncorder{
	private:
		basic_ifstream<char> ifs;
		basic_ofstream<char> ofs;
		int GetRandom(int min,int max);
		string mInputFileName,mOutputFileName;
		string mKey;
private:
		void OpenFile();
		void CloseFile();
		string engine();
		void setRandSeed();


	public:
		CEncorder(string InputFileName,string OutputFileName,string Keyword);
		CEncorder(char InputFileName[],char OutputFileName[],char Keyword[]);
		CEncorder();
		void Execute();
		void setFileNameInput(string Str);
		void setFileNameOutput(string Str);
		void setKey(string Str);
	};
};

#endif