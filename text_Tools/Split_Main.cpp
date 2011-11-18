#include "Split.h"

void main(){
	IFS in;
	in.q_in();
	Split SPL(in.get());

	SPL.SplitFile();
	
}