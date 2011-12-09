#ifndef __KeyManager
#define __KeyManager
#include "Key.h"
//*
class KeyManager{
private:
	KeyManager(){};
	KeyManager(const KeyManager& kmg);
	KeyManager& operator=(const KeyManager& kmg);

public:
	static KeyManager& getInstance(void){
		static KeyManager Instance;
		return Instance;
	}

	static Key& getKeyInstance(){
		static Key keyInstance;
		return keyInstance;
	}

	virtual ~KeyManager(){};
};
//*/
/*
namespace KeyManager{
	static Key Instance;
};
//*/
#endif