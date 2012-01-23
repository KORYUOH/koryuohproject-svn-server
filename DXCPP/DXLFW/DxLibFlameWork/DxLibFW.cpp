#include	<DxLibFlameWork/DxLibFW.h>
#include	<Key/Key.h>
#include	<Pad/Pad.h>
#include	<Fps/Fps.h>

int DXFW::init(){
	if(m_isWindowMode)
		ChangeWindowMode(m_isWindowMode);
	else
	MessegeBox();

	SetMainWindowText(m_WindowTitle.c_str());

	SetOutApplicationLogValidFlag(m_isOutLog);
	return (DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0)? -1:0;
}

void DXFW::Initialize(){

}

void DXFW::update(){

}

void DXFW::draw(){

}

void DXFW::finish(){
	DxLib_End();
}
/**
*	@brief	run
*	@work	execute program
*	@warning	Do not override
*/
void DXFW::run(){
	init();
	Initialize();
	while(ProcessLoop() == 0){
		update();
		draw();
		FPS_Ctrl::getInstance().draw_fps(0,465);
		FPS_Ctrl::getInstance().fps_wait();
		if(Key::getInstance().CheckStateKey(KEY_INPUT_ESCAPE) == 1)break;
		ScreenFlip();
	}
	finish();
}

int DXFW::ProcessLoop(){
	if(ProcessMessage() != 0) return -1;
	if(ClearDrawScreen() != 0) return -1;
	Key::getInstance().GetHitKeyStateAll_2();
	Pad::getInstance().GetHitPadStateAll();
	return 0; 
}

void DXFW::MessegeBox(){
	if( MessageBox(
		NULL ,
		TEXT("フルスクリーンモードで起動しますか？") ,
		TEXT("スクリーン設定") , 
		MB_YESNO | MB_ICONQUESTION 
		)
		==IDNO)
		ChangeWindowMode( TRUE );
}
