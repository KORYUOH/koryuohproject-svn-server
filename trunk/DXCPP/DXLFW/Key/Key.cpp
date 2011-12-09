#include "Key.h"
/**
Key& Key::getInstance(){
	static Key instance;
	return instance;
}
*/
//**
int Key::GetHitKeyStateAll_2(){
	char GetHitKeyStateAll_Key[256];
    GetHitKeyStateAll( GetHitKeyStateAll_Key );
    for(int i=0;i<256;i++){
        if(GetHitKeyStateAll_Key[i]==1)	stateKey[i]++;
		else										stateKey[i]=0;
    }
    return 0;
}

int Key::CheckStateKey(unsigned char Handle){
        return stateKey[Handle];
}

//*/
/**
int Keystate::GetHitKeyStateAll_2(){
	char GetHitKeyStateAll_Key[256];
    GetHitKeyStateAll( GetHitKeyStateAll_Key );
    for(int i=0;i<256;i++){
        if(GetHitKeyStateAll_Key[i]==1)	stateKey[i]++;
		else										stateKey[i]=0;
    }
    return 0;
}

int Keystate::CheckStateKey(unsigned char Handle){
        return stateKey[Handle];
}
*/