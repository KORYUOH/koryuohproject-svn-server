#define GLOBAL_INSTANCE
//#define DEVELOP_MODE
#include "GV.h"

//���[�v�ŕK���s���R�又��
int ProcessLoop(){
	if(ProcessMessage()!=0)return -1;//�v���Z�X�������G���[�Ȃ�-1��Ԃ�
	if(ClearDrawScreen()!=0)return -1;//��ʃN���A�������G���[�Ȃ�-1��Ԃ�
	GetHitKeyStateAll_2();//���݂̃L�[���͏������s��
	GetHitPadStateAll();  //���݂̃p�b�h���͏������s��
	return 0;
}
void message_box(){
		int flag;
		if(DEVELOP)
			ChangeWindowMode(TRUE);
		else{
		flag=MessageBox(
				NULL ,
				TEXT("�t���X�N���[�����[�h�ŋN�����܂����H") ,
				TEXT("�X�N���[���ݒ�") , 
				MB_YESNO | MB_ICONQUESTION );
		if(flag==IDNO)
				ChangeWindowMode( TRUE );
		}
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
	message_box();//�E�B���h�E���[�h?
	SetWindowText(GT);//�^�C�g���ς����[
	if(SYSTEM_LOG)
		SetOutApplicationLogValidFlag(FALSE);
	if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;//�������Ɨ���ʉ�
	//key_init();
	//other_Init();
	//game_Init();
	Init_main();
	while(ProcessLoop()==0){//���C�����[�v
		game_Main();
		game_Draw();
		if(FPS_SHOW)
			draw_fps(0,465);
		fps_wait();
		if(CheckStateKey(KEY_INPUT_ESCAPE)==1)break;//�G�X�P�[�v�����͂��ꂽ��u���C�N
		ScreenFlip();//����ʔ��f
	}
	game_End();
	DxLib_End();//�c�w���C�u�����I������
	return 0;
}