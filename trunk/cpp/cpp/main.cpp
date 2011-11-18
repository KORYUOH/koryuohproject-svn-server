#include "cpp.h"
#include <iostream>
using namespace NS_CPP;

void main(){
	CPP A("¬R","Ë•");
	A.setItratorBegin();
	A.output(A.getMapStrItr());
	A.output();
	A.add("—³‹{","ƒŒƒi");
	A.output(A.getMapStrItr());
	A.output();
	cout << endl;
	A.output(A.getMapStrItr());
	A.output();
	A++;
	A.output();
	cout << endl;
	cout << A.Getdata_first() << endl;
	cout << A.Getdata_second() << endl;
	A--;
	cout << endl;
	cout << A.Getdata_first() << endl;
	cout << A.Getdata_second() << endl;
	system("pause");
}