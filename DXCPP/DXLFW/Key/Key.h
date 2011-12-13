#ifndef __Key
#define __Key
#include "../../Include/DxLib.h"
/*
class Keystate{
	unsigned int stateKey[256];
public:
	int GetHitKeyStateAll_2();
	int CheckStateKey(unsigned char Handle);
};
*/
class Key{
private:
	Key(){};
private:
	Key(const Key& rhs);
	Key& operator =(const Key& rhs);

	unsigned int stateKey[256];
public:
	//static Key& getInstance();
	static Key& getInstance(void){
		static Key instance;
		return instance;
	}
		int GetHitKeyStateAll_2();
		int CheckStateKey(unsigned char Handle);
	//Keystate& getState(){
	//	static Keystate State;
	//	return State;
	//}

	virtual ~Key(){};
};

#endif
