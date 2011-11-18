#include "Conbine.h"



void Conbine::Exec(){
	IFS in1,in2;
	in1.q_in();
	in2.q_in();
	string s;
	int i=1;
	SetFile(in1.get(),in2.get());

	ifs1.open(mFile1+".txt",ios::in);
	ifs2.open(mFile2+".txt",ios::in);
	ofs.open(mFile1+mFile2+".txt",ios::out);
	cout << "Now Line No Draw: " << mLineNoFrag<<endl;
	cout << "Change? y/n" <<endl;
	cin >> s;
	if(s=="y"||s=="Y")
		mLineNoFrag = true;

	while(!(ifs1.fail()&&ifs2.fail())){
		if(!ifs1.fail()){
			if(mLineNoFrag)
				ofs << i << "\t";
		getline(ifs1,mBuf);
		ofs << mBuf<<endl;
		}
		else{
			ofs << endl;
		}
		if(!ifs2.fail()){
			if(mLineNoFrag)
				ofs << i << "\t";
		getline(ifs2,mBuf);
		ofs << mBuf<<endl;
		}
		else{
			ofs << endl;
		}
		i++;
	}

}