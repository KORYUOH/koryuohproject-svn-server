//#include "../Define/Define.h"
#include "DxLibFW.h"
#include "../Key/KeyManager.h"

int DXFW::init(){
	if(WINDOW_MODE)
	MessegeBox();
	return (DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0)? -1:0;
}

void DXFW::update(){

}

void DXFW::draw(){

}

void DXFW::finish(){
	DxLib_End();
}

void DXFW::run(){
	init();
	while(ProcessLoop() == 0){
		update();
		draw();
//		if(Key::getInstance().getState().CheckStateKey( KEY_INPUT_ESCAPE) == 1) break;
//		if(m_Key.CheckStateKey( KEY_INPUT_ESCAPE ) == 1) break;
		if(KeyManager::getInstance().getKeyInstance().CheckStateKey( KEY_INPUT_ESCAPE ) == 1)break;
//		if(KeyManager::Instance.CheckStateKey(KEY_INPUT_ESCAPE) == 1)break;
		ScreenFlip();
	}
	finish();
}

int DXFW::ProcessLoop(){
	if(ProcessMessage() != 0) return -1;
	if(ClearDrawScreen() != 0) return -1;
//	Key::getInstance().getState().GetHitKeyStateAll_2();
//	m_Key.GetHitKeyStateAll_2();
	KeyManager::getInstance().getKeyInstance().GetHitKeyStateAll_2();
	return 0; 
}

void DXFW::MessegeBox(){
        int flag;
        flag=MessageBox(
                NULL ,
                TEXT("フルスクリーンモードで起動しますか？") ,
                TEXT("スクリーン設定") , 
                MB_YESNO | MB_ICONQUESTION );
        if(flag==IDNO)
                ChangeWindowMode( TRUE );
}
