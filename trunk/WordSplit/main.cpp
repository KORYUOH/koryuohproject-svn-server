#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

typedef std::vector<std::string> StrVector;
typedef StrVector::iterator StrVectItor;

class StringUtil{
		string m_ReadLine;
		StrVector m_Word;
		StrVectItor m_WordItor;
	public:
		StringUtil(){};
		~StringUtil(){};
		void setString(string str);
		string getStrLine()const;
		string getWord();
		void Split();
	};
void StringUtil::Split(){
	string tmp = m_ReadLine;//tmpにm_ReadLineをコピーしておく
	string temporary = tmp.substr(0,tmp.find_first_of(" "));
	tmp = tmp.substr(tmp.find(" ")+1,tmp.size());
	m_WordItor = m_Word.begin();
	do{
		m_Word.push_back(temporary);
		
		temporary = tmp.substr(0,tmp.find_first_of(" "));
		tmp = tmp.substr(tmp.find(" ")+1,tmp.size());
		m_WordItor = m_Word.end()-1;
			}while(tmp.compare(*m_WordItor));
	m_WordItor = m_Word.begin();	//使ったら元に戻してね
}
void StringUtil::setString(string str){
	m_ReadLine = str;
}
string StringUtil::getStrLine() const{
	return m_ReadLine;
}

string StringUtil::getWord(){
	StrVectItor temp = m_WordItor;
	if(m_WordItor != m_Word.end())
		m_WordItor++;
	return	(temp != m_Word.end())? *temp:"END OF Vector";
}

void main(){
	StringUtil utility;
	string temp="Wee ki ra exec hymm VIENA >>> SOL=FAGE 1x10 enter FRELIA";

	cout << "input string " <<endl;
	cout << temp;
	utility.setString(temp);
	utility.Split();

	cout << "GetStrLine Test" <<endl;
	cout << utility.getStrLine() <<endl;
	cout << "word Test" <<endl;
	for(int i=0;i<15;i++)
		cout << utility.getWord() <<endl;

	system("pause");
}