#include "CSV.h"

CSVReader::CSVReader(string str)
	:mFileName(str)
{
}
void CSVReader::split(string spstr){
	int s=mBuf.find(spstr);
	mBuf = mBuf.substr(0,s);
}

void CSVReader::Load(){
	ifs.open(mFileName+".csv",ios::in);
	ofs.open(mFileName+".txt");
	while(! ifs.fail()){
		getline(ifs,mBuf);
		split(",");
		ofs << mBuf << endl;
	}
}