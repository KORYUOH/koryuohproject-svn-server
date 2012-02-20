#define GLOBAL_INSTANCE
//#define DEVELOP_MODE
#include "GV.h"

//ループで必ず行う３大処理
int ProcessLoop(){
	if(ProcessMessage()!=0)return -1;//プロセス処理がエラーなら-1を返す
	if(ClearDrawScreen()!=0)return -1;//画面クリア処理がエラーなら-1を返す
	GetHitKeyStateAll_2();//現在のキー入力処理を行う
	GetHitPadStateAll();  //現在のパッド入力処理を行う
	return 0;
}
void message_box(){
		int flag;
		if(DEVELOP)
			ChangeWindowMode(TRUE);
		else{
		flag=MessageBox(
				NULL ,
				TEXT("フルスクリーンモードで起動しますか？") ,
				TEXT("スクリーン設定") , 
				MB_YESNO | MB_ICONQUESTION );
		if(flag==IDNO)
				ChangeWindowMode( TRUE );
		}
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
	message_box();//ウィンドウモード?
	SetWindowText(GT);//タイトル変えるよー
	if(SYSTEM_LOG)
		SetOutApplicationLogValidFlag(FALSE);
	if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;//初期化と裏画面化
	//key_init();
	//other_Init();
	//game_Init();
	Init_main();
	while(ProcessLoop()==0){//メインループ
		game_Main();
		game_Draw();
		if(FPS_SHOW)
			draw_fps(0,465);
		fps_wait();
		if(CheckStateKey(KEY_INPUT_ESCAPE)==1)break;//エスケープが入力されたらブレイク
		ScreenFlip();//裏画面反映
	}
	game_End();
	DxLib_End();//ＤＸライブラリ終了処理
	return 0;
}