#include "CSV.h"

void main(){
	string Fname;
	cout << "FileName?" ;
	cin>>Fname;
	CSVReader cr(Fname);
	cr.Load();

}