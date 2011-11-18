#ifndef __CPP
#define __CPP
#include <map>
#include <string>
typedef std::map<std::string,std::string> MapStr;
typedef MapStr::iterator MapStrItr;
namespace NS_CPP{
	using namespace std;

	class CPP{
	private:
		MapStr m_name;
		MapStrItr m_MSI;
	public:
		CPP();
		CPP(string familyname,string uniquename);
		void add(string familyname,string uniquename);
		void output();
		void output(MapStrItr itr);
		void setItratorBegin();
		string Getdata_first();
		string Getdata_second();
		MapStrItr getMapStrItr();
		CPP operator ++ (int){
			CPP CppOld = *this;
			*this->m_MSI++;
			return CppOld;
		}
		CPP operator --(int){
			CPP CppOld = *this;
			*this->m_MSI--;
			return CppOld;
		}
	};
};
#endif