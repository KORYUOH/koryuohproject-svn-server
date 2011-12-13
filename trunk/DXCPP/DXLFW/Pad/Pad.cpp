#include "Pad.h"
#include "../Key/Key.h"

//パッドとキーボードの両方の入力をチェックする関数
void Pad::GetHitPadStateAll(){
	int PadInput,mul=1;
	PadInput = GetJoypadInputState( DX_INPUT_PAD1 );//パッドの入力状態を取得
	for(int i=0;i<16;i++){
		if(PadInput & mul)	Key[i]++;
		else				Key[i]=0;
		mul*=2;
	}
	input_pad_or_key(&Key[configpad.left]			,Key::getInstance().CheckStateKey(KEY_INPUT_LEFT	 ));
	input_pad_or_key(&Key[configpad.up]			,Key::getInstance().CheckStateKey(KEY_INPUT_UP		 ));
	input_pad_or_key(&Key[configpad.right]		,Key::getInstance().CheckStateKey(KEY_INPUT_RIGHT	 ));
	input_pad_or_key(&Key[configpad.down]		,Key::getInstance().CheckStateKey(KEY_INPUT_DOWN	 ));
	input_pad_or_key(&Key[configpad.circle]		,Key::getInstance().CheckStateKey(KEY_INPUT_Z		 ));
	input_pad_or_key(&Key[configpad.cross]		,Key::getInstance().CheckStateKey(KEY_INPUT_X		 ));
	input_pad_or_key(&Key[configpad.triangle]		,Key::getInstance().CheckStateKey(KEY_INPUT_A		 ));//triangle
	input_pad_or_key(&Key[configpad.square]		,Key::getInstance().CheckStateKey(KEY_INPUT_S		 ));//square
	input_pad_or_key(&Key[configpad.select]		,Key::getInstance().CheckStateKey(KEY_INPUT_LSHIFT	 ));
	input_pad_or_key(&Key[configpad.start]			,Key::getInstance().CheckStateKey(KEY_INPUT_ESCAPE	 ));
	input_pad_or_key(&Key[configpad.r1]			,Key::getInstance().CheckStateKey(KEY_INPUT_E		 ));//R1
	input_pad_or_key(&Key[configpad.r2]			,Key::getInstance().CheckStateKey(KEY_INPUT_R		 ));//R2
	input_pad_or_key(&Key[configpad.l1]			,Key::getInstance().CheckStateKey(KEY_INPUT_W		 ));//L1
	input_pad_or_key(&Key[configpad.l2]			,Key::getInstance().CheckStateKey(KEY_INPUT_Q		 ));//L2
}

//渡されたパッドキー番号の入力状態を返す。返り値が-1なら不正
int Pad::CheckStatePad(unsigned int Handle){
	if(0<=Handle && Handle<PAD_MAX){
		return Key[Handle];
	}
	else{
		printfDx("CheckStatePadに渡した値が不正です\n");
		return -1;
	}
}

int Pad::CheckStateTrigger(unsigned int Handle){
	if(TriggerHandle[Handle] == true){
		if(CheckStatePad(Handle) == 0){
			TriggerHandle[Handle] = false;
			return 1;
		}
	}else{
		if(CheckStatePad(Handle)>0)
			TriggerHandle[Handle] = true;
		else
			TriggerHandle[Handle] = false;
	}
	return 0;
}

int Pad::CheckStateToggle(unsigned int Handle){
	if(ToggleHandle[Handle] == true){
		if(CheckStatePad(Handle)>0)
		{	ToggleHandle[Handle]=false; return 0; 	}
		return 1;
	}else{
		if(CheckStatePad(Handle)>0)
			ToggleHandle[Handle] = true;
		else
			ToggleHandle[Handle] = false;
	}
	return 0 ;
}

void Pad::KeyInit(){
	configpad.down	=0;
	configpad.left=1;
	configpad.right=2;
	configpad.up=3;
	configpad.cross=4;
	configpad.circle=5;
	configpad.triangle=6;
	configpad.square=7;
	configpad.l2=8;
	configpad.r2=9;
	configpad.l1=10;
	configpad.r1=11;
	configpad.start=13;
	configpad.select=14;
}