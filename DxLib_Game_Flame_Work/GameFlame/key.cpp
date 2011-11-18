#include "GV.h"

unsigned int stateKey[256];

int GetHitKeyStateAll_2(){
	char GetHitKeyStateAll_Key[256];
	GetHitKeyStateAll( GetHitKeyStateAll_Key );
	for(int i=0;i<256;i++){
		if(GetHitKeyStateAll_Key[i]==1) stateKey[i]++;
		else							stateKey[i]=0;
	}
	return 0;
}

int CheckStateKey(unsigned char Handle){
	return stateKey[Handle];
}

//パッドの入力状態を格納する変数
pad_t pad;

//引数１と引数２のうち大きい方を引数１に代入する
void input_pad_or_key(int *p, int k){
	*p = *p>k ? *p : k;
}
#ifdef CPAD_STG
//パッドとキーボードの両方の入力をチェックする関数
void GetHitPadStateAll(){
	int i,PadInput,mul=1;
	PadInput = GetJoypadInputState( DX_INPUT_PAD1 );//パッドの入力状態を取得
	for(i=0;i<16;i++){
		if(PadInput & mul)	pad.key[i]++;
		else				pad.key[i]=0;
		mul*=2;
	}
	input_pad_or_key(&pad.key[configpad.left]	,CheckStateKey(KEY_INPUT_LEFT	 ));
	input_pad_or_key(&pad.key[configpad.up]		,CheckStateKey(KEY_INPUT_UP		 ));
	input_pad_or_key(&pad.key[configpad.right]  ,CheckStateKey(KEY_INPUT_RIGHT	 ));
	input_pad_or_key(&pad.key[configpad.down]	,CheckStateKey(KEY_INPUT_DOWN	 ));
	input_pad_or_key(&pad.key[configpad.shot]	,CheckStateKey(KEY_INPUT_Z		 ));
	input_pad_or_key(&pad.key[configpad.bom]	,CheckStateKey(KEY_INPUT_X		 ));
	input_pad_or_key(&pad.key[configpad.slow]	,CheckStateKey(KEY_INPUT_LSHIFT	 ));
	input_pad_or_key(&pad.key[configpad.start]  ,CheckStateKey(KEY_INPUT_ESCAPE	 ));
	input_pad_or_key(&pad.key[configpad.change] ,CheckStateKey(KEY_INPUT_LCONTROL));
}
#else
#ifdef CPAD_ACT
//パッドとキーボードの両方の入力をチェックする関数
void GetHitPadStateAll(){
	int i,PadInput,mul=1;
	PadInput = GetJoypadInputState( DX_INPUT_PAD1 );//パッドの入力状態を取得
	for(i=0;i<16;i++){
		if(PadInput & mul)	pad.key[i]++;
		else				pad.key[i]=0;
		mul*=2;
	}
	input_pad_or_key(&pad.key[configpad.left]	,CheckStateKey(KEY_INPUT_LEFT	 ));
	input_pad_or_key(&pad.key[configpad.up]		,CheckStateKey(KEY_INPUT_UP		 ));
	input_pad_or_key(&pad.key[configpad.right]  ,CheckStateKey(KEY_INPUT_RIGHT	 ));
	input_pad_or_key(&pad.key[configpad.down]	,CheckStateKey(KEY_INPUT_DOWN	 ));
	input_pad_or_key(&pad.key[configpad.a]		,CheckStateKey(KEY_INPUT_Z		 ));
	input_pad_or_key(&pad.key[configpad.b]		,CheckStateKey(KEY_INPUT_X		 ));
	input_pad_or_key(&pad.key[configpad.select]	,CheckStateKey(KEY_INPUT_LSHIFT	 ));
	input_pad_or_key(&pad.key[configpad.start]  ,CheckStateKey(KEY_INPUT_ESCAPE	 ));
}
#else
#ifdef CPAD_ARROW
//パッドとキーボードの両方の入力をチェックする関数
void GetHitPadStateAll(){
	int i,PadInput,mul=1;
	PadInput = GetJoypadInputState( DX_INPUT_PAD1 );//パッドの入力状態を取得
	for(i=0;i<16;i++){
		if(PadInput & mul)	pad.key[i]++;
		else				pad.key[i]=0;
		mul*=2;
	}
	input_pad_or_key(&pad.key[configpad.left]	,CheckStateKey(KEY_INPUT_LEFT	 ));
	input_pad_or_key(&pad.key[configpad.up]		,CheckStateKey(KEY_INPUT_UP		 ));
	input_pad_or_key(&pad.key[configpad.right]  ,CheckStateKey(KEY_INPUT_RIGHT	 ));
	input_pad_or_key(&pad.key[configpad.down]	,CheckStateKey(KEY_INPUT_DOWN	 ));
}
#else
#ifdef CPAD_PS2
//パッドとキーボードの両方の入力をチェックする関数
void GetHitPadStateAll(){
	int i,PadInput,mul=1;
	PadInput = GetJoypadInputState( DX_INPUT_PAD1 );//パッドの入力状態を取得
	for(i=0;i<16;i++){
		if(PadInput & mul)	pad.key[i]++;
		else				pad.key[i]=0;
		mul*=2;
	}
	input_pad_or_key(&pad.key[configpad.left]		,CheckStateKey(KEY_INPUT_LEFT	 ));
	input_pad_or_key(&pad.key[configpad.up]			,CheckStateKey(KEY_INPUT_UP		 ));
	input_pad_or_key(&pad.key[configpad.right]		,CheckStateKey(KEY_INPUT_RIGHT	 ));
	input_pad_or_key(&pad.key[configpad.down]		,CheckStateKey(KEY_INPUT_DOWN	 ));
	input_pad_or_key(&pad.key[configpad.cercle]		,CheckStateKey(KEY_INPUT_Z		 ));
	input_pad_or_key(&pad.key[configpad.cross]		,CheckStateKey(KEY_INPUT_X		 ));
	input_pad_or_key(&pad.key[configpad.triangle]	,CheckStateKey(KEY_INPUT_A		 ));//triangle
	input_pad_or_key(&pad.key[configpad.square]		,CheckStateKey(KEY_INPUT_S		 ));//square
	input_pad_or_key(&pad.key[configpad.select]	,CheckStateKey(KEY_INPUT_LSHIFT	 ));
	input_pad_or_key(&pad.key[configpad.start]  ,CheckStateKey(KEY_INPUT_ESCAPE	 ));
	input_pad_or_key(&pad.key[configpad.r1]		,CheckStateKey(KEY_INPUT_E		 ));//R1
	input_pad_or_key(&pad.key[configpad.r2]		,CheckStateKey(KEY_INPUT_R		 ));//R2
	input_pad_or_key(&pad.key[configpad.l1]		,CheckStateKey(KEY_INPUT_W		 ));//L1
	input_pad_or_key(&pad.key[configpad.l2]		,CheckStateKey(KEY_INPUT_Q		 ));//L2
}
#else
#ifdef CPAD_DS
//パッドとキーボードの両方の入力をチェックする関数
void GetHitPadStateAll(){
	int i,PadInput,mul=1;
	PadInput = GetJoypadInputState( DX_INPUT_PAD1 );//パッドの入力状態を取得
	for(i=0;i<16;i++){
		if(PadInput & mul)	pad.key[i]++;
		else				pad.key[i]=0;
		mul*=2;
	}
	input_pad_or_key(&pad.key[configpad.left]	,CheckStateKey(KEY_INPUT_LEFT	 ));
	input_pad_or_key(&pad.key[configpad.up]		,CheckStateKey(KEY_INPUT_UP		 ));
	input_pad_or_key(&pad.key[configpad.right]  ,CheckStateKey(KEY_INPUT_RIGHT	 ));
	input_pad_or_key(&pad.key[configpad.down]	,CheckStateKey(KEY_INPUT_DOWN	 ));
	input_pad_or_key(&pad.key[configpad.a]		,CheckStateKey(KEY_INPUT_Z		 ));
	input_pad_or_key(&pad.key[configpad.b]		,CheckStateKey(KEY_INPUT_X		 ));
	input_pad_or_key(&pad.key[configpad.x]		,CheckStateKey(KEY_INPUT_A		 ));
	input_pad_or_key(&pad.key[configpad.y]		,CheckStateKey(KEY_INPUT_S		 ));
	input_pad_or_key(&pad.key[configpad.select]	,CheckStateKey(KEY_INPUT_LSHIFT	 ));
	input_pad_or_key(&pad.key[configpad.start]  ,CheckStateKey(KEY_INPUT_ESCAPE	 ));
}
#else
#ifdef CPAD_SIMPLE
//パッドとキーボードの両方の入力をチェックする関数
void GetHitPadStateAll(){
	int i,PadInput,mul=1;
	PadInput = GetJoypadInputState( DX_INPUT_PAD1 );//パッドの入力状態を取得
	for(i=0;i<16;i++){
		if(PadInput & mul)	pad.key[i]++;
		else				pad.key[i]=0;
		mul*=2;
	}
	input_pad_or_key(&pad.key[configpad.left]	,CheckStateKey(KEY_INPUT_LEFT	 ));
	input_pad_or_key(&pad.key[configpad.up]		,CheckStateKey(KEY_INPUT_UP		 ));
	input_pad_or_key(&pad.key[configpad.right]  ,CheckStateKey(KEY_INPUT_RIGHT	 ));
	input_pad_or_key(&pad.key[configpad.down]	,CheckStateKey(KEY_INPUT_DOWN	 ));
	input_pad_or_key(&pad.key[configpad.ok]		,CheckStateKey(KEY_INPUT_Z		 ));
	input_pad_or_key(&pad.key[configpad.no]		,CheckStateKey(KEY_INPUT_X		 ));
}
#endif	//CPAD_SIMPLE
#endif	//CPAD_DS
#endif	//CPAD_PS2
#endif	//CPAD_ARROW
#endif	//CPAD_ACT
#endif	//CPAD_STG
//渡されたパッドキー番号の入力状態を返す。返り値が-1なら不正
int CheckStatePad(unsigned int Handle){
	if(0<=Handle && Handle<PAD_MAX){
		return pad.key[Handle];
	}
	else{
		printfDx("CheckStatePadに渡した値が不正です\n");
		return -1;
	}
}


//渡されたキーのトリガー入力を返す　返り値が-1なら不正
int CheckStateTrigger(unsigned int Handle){
	if(0<=Handle && Handle<PAD_MAX){//ハンドルが正規範囲内
		if(pad.trigger[Handle]==TRUE){//トリガ入力準備状態
			if(CheckStatePad(Handle)>0){//入力されている
				return 0;
			}
			else{//離された
				pad.trigger[Handle]=FALSE;//トリガ入力完了
				return 1;
			}
		}
		else{
			if(CheckStatePad(Handle)>0){//入力あり
				pad.trigger[Handle]=TRUE;//トリガ入力準備
				return 0;
				}
			else{//入力なし
				return 0;
			}
		}
	}
	else{
		printfDx("CheckStateTriggerに渡した値が不正です\n");
		return -1;
	}
}
//トグル操作
int CheckStateToggle(unsigned int Handle){
	if(0<=Handle&&Handle<PAD_MAX){
		if(pad.toggle[Handle]==TRUE){
			if(CheckStateTrigger(Handle)>0){
				pad.toggle[Handle]=FALSE;
				return 0;
			}
			else{
				return pad.key[Handle];
			}
		}
		else{
			if(CheckStateTrigger(Handle)>0){
				pad.toggle[Handle]=TRUE;
				return pad.key[Handle];
			}
			else{
				return 0;
			}

		}
	}
	else{
		printfDx("CheckStateToggleに渡した値が不正です\n");
		return -1;
	}
}

int CheckHitState(unsigned int Handle,int PadMode){
	switch(PadMode){
	case PUSH:
		return CheckStatePad(Handle); break;
	case TRIGGER:
		return CheckStateTrigger(Handle); break;
	case TOGGLE:
		return CheckStateToggle(Handle); break;
	default :
		return 0;
	}
	return 0;
}