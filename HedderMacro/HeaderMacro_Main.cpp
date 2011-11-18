#include <cstdlib>
#include "HeadderMacro.h"

void main(int argc,char *argv[]){

	if(1<argc){
		Macro Tmp(argv[1]);
	}
	if(2<argc){
		string cmp = argv[2];
		string arg = argv[1];
		if(cmp== "-r"){
			string sys ="ren r_"+arg+".h "+arg+".h";
			system(sys.c_str());
		}
	}
	else{
	Macro Tmp;
	Tmp.exec();
	}
}
