#include "GV.h"

#ifdef CPAD_STG
void key_init(){
	configpad.down	=0;
	configpad.left=1;
	configpad.right=2;
	configpad.up=3;
	configpad.bom=4;
	configpad.shot=5;
	configpad.slow=11;
	configpad.start=13;
	configpad.change=6;
}
#else
#ifdef CPAD_ACT
void key_init(){
	configpad.down	=0;
	configpad.left=1;
	configpad.right=2;
	configpad.up=3;
	configpad.a=4;
	configpad.b=5;
	configpad.start=13;
	configpad.select=14;
}
#else
#ifdef CPAD_ARROW
void key_init(){
	configpad.down=0;
	configpad.left=1;
	configpad.right=2;
	configpad.up=3;
}
#else
#ifdef CPAD_PS2
void key_init(){
	configpad.down	=0;
	configpad.left=1;
	configpad.right=2;
	configpad.up=3;
	configpad.cross=4;
	configpad.cercle=5;
	configpad.triangle=6;
	configpad.square=7;
	configpad.l2=8;
	configpad.r2=9;
	configpad.l1=10;
	configpad.r1=11;
	configpad.start=13;
	configpad.select=14;
}
#else
#ifdef CPAD_DS
void key_init(){
	configpad.down	=0;
	configpad.left	=1;
	configpad.right	=2;
	configpad.up	=3;
	configpad.a		=4;
	configpad.b		=5;
	configpad.x		=6;
	configpad.y		=7;
	configpad.l		=10;
	configpad.r		=11;
	configpad.start	=13;
	configpad.select=14;
}
#else
#ifdef CPAD_SIMPLE
void key_init(){
	configpad.down	=0;
	configpad.left	=1;
	configpad.right	=2;
	configpad.up	=3;
	configpad.ok	=4;
	configpad.no	=5;
}
#endif	//CPAD_SIMPLE
#endif	//CPAD_DS
#endif	//CPAD_PS2
#endif	//CPAD_ARROW
#endif	//CPAD_ACT
#endif	//CPAD_STG


void other_Init(){
	color[0] = GetColor(255,255,255);//îí
	color[1] = GetColor(  0,  0,  0);//çï
	color[2] = GetColor(255,  0,  0);//ê‘
	color[3] = GetColor(  0,255,  0);//óŒ
	color[4] = GetColor(  0,  0,255);//ê¬
	color[5] = GetColor(255,255,  0);//â©êF
	color[6] = GetColor(  0,255,255);//ê¬óŒ
	color[7] = GetColor(255,  0,255);//éá
}

void Init_main(){
	key_init();
	other_Init();
	game_Init();
}