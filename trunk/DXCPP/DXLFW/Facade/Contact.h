#ifndef	__Contact
#define	__Contact
#include "../Key/Key.h"
#include "../Pad/Pad.h"

namespace CONTACT{
	int inputPad(unsigned int Handle){
		return Pad::getInstance().CheckStatePad(Handle);
	}

	int inputKey(unsigned int Handle){
		return Key::getInstance().CheckStateKey(Handle)
	}
}


#endif	//__Contact