#include "Hymmnos.h"

///// Class hymmnos /////////////
hymmnos::hymmnos(){
	mMapItr = mMap.begin();
}
void hymmnos::Split(){
	mMap[mCSVBuff.substr(0,mCSVBuff.find(",")-1)] = mCSVBuff.substr(mCSVBuff.find(",")+1,mCSVBuff.length());
}
///// Class Load ////////////////
void Load::open(string FileName){
	if(FileName.find(".txt") != FileName.length())
		miftx.open(FileName,ios::in);
	else if(FileName.find(".csv") != FileName.length())
		mifcs.open(FileName,ios::in);
	else
		moftx.open(FileName,ios::out);
}

void Load::csv(){
	getline(mifcs,mCSVBuff);
	hymmnos::Split();
}
void Load::text(){
	getline(miftx,);
	splitter();
}

void Load::splitter(){
	int x = 0,y=0;
	for(int i=0;mChkStr.length();i++){
		word[i] = mChkStr.substr(x,(y+=mChkStr.find(" "))-1);
		x = y;
	}
}


void Load::close(){
	miftx.close();
	mifcs.close();
	moftx.close();
}