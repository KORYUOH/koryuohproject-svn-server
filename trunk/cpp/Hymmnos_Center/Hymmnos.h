#ifndef __HYMMNOS
#define __HYMMNOS
#include <string>
#include <map>
#include <vector>

typedef std::map<std::string,std::string> StrMap;
typedef StrMap::iterator StrMapItr;
typedef std::vector<std::string> StrVector;
typedef StrVector::iterator StrVectItor;

namespace Ar_Tonelico{
	using namespace std;
	class EOLIA{
	private:
		StrMap m_hymm;
		StrMapItr m_hymmItr;
	public://Constractor And Deathtructors
		EOLIA();
		EOLIA(string str);
		EOLIA(string str1,string str2);
		EOLIA(char str[]);
		EOLIA(char str1[],char str2[]);
		~EOLIA();
	public:// Menber Function
		void add(string str);
		void add(string str1,string str2);
		string getIteratorData_First() const ;
		string getIteratorData_Second() const ;
		void SetItrBegin();
		string Cmp_str(string str);
	public://OverLoad
		EOLIA operator ++ (int);
		EOLIA& operator ++();
		EOLIA operator -- (int);
		EOLIA& operator --();

	};
};

#endif	//__HYMMNOS