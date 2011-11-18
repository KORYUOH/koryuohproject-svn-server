#include "HeadderMacro.h"

void Macro::FileCmd(string FileName){
	basic_ifstream<char> ifs(FileName+".h");
	basic_ofstream<char> ofs("r_"+FileName+".h");
	ofs << "#ifndef _" << FileName<<"_H_"<<endl;
	ofs << "#define _" << FileName<<"_H_"<<endl;
	string buff;
	while(!ifs.fail()){
		getline(ifs,buff);
		ofs << buff << endl;
	}
	ofs << "#endif"<<endl;
}
void Macro::SetFileName(){
	cout << "ヘッダファイル名を入力してください" <<endl;
	cin >> FileName;
}

void Macro::exec(){
	SetFileName();
	FileCmd(FileName);
}