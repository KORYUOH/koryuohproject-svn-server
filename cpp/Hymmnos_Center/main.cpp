#include <iostream>
#include "FileOwner.h"
#include "Hymmnos.h"

void main(){
	CSV::FileOwner File;
	CSV::FileRead txtfile;
	Ar_Tonelico::EOLIA Shrelia;
	File.Reader.setCaram(",");
	File.OpenReadFile("hymm_tbl_2.csv");
	for(unsigned int i=0;!File.ReadFileFail();i+=2){
		File.Reader.readline();
//		std::cout <<i<<" "<< "word1:"<<File.Reader.getWord(i)<<"\t"<<"word2:"<<File.Reader.getWord((i+1))<<std::endl;
		Shrelia.add(File.Reader.getWord(i),File.Reader.getWord((i+1)) );
	}
	File.Reader.close();
	txtfile.open("EXEC_FLIP_FUSIONSPHERE.txt");
	File.OpenWriteFile("HYMMNOS.txt");
	
	txtfile.setCaram(" ");
	while(!( txtfile.fail () ) ){
		txtfile.readline();
		std::cout << txtfile.length() << std::endl;
		for(int i=1,length=txtfile.length();i<length;i++){
			std::cout <<i<<" "<< Shrelia.Cmp_str(txtfile.getWord(i))<<std::endl;
			File.Writer.push_Back( Shrelia.Cmp_str(txtfile.getWord(i)));
		}
		File.Writer.Write_Word_Line_Flush();
		txtfile.clear();
	}

}