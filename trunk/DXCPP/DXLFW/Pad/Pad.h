#ifndef __Pad
#define __Pad
#include "../Define/Define.h"
#include "../Define/Structure.h"
#include "../../Include/DxLib.h"
#include "../Key/KeyManager.h"
struct PS2{
	int left,up,right,down,circle,triangle,square,cross,l1,l2,r1,r2,start,select;
	
	PS2():
	left(1),up(3),right(2),down(0),
	circle(5),triangle(6),square(7),cross(4),
	l1(10),l2(8),r1(11),r2(9),start(13),select(14){};
	
	/*
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
	*/
};
class Pad{
private:
	int Key[PAD_MAX];
	PS2 configpad;
	void input_pad_or_key(int *p, int k){
		*p = *p>k ? *p : k;
	}
	void KeyInit();
public:
	void	GetHitPadStateAll();
	int CheckStatePad(unsigned int Handle);
	int CheckStateTrigger(unsigned int Handle);
	int CheckStateToggle(unsigned int Handle);
private:
	bool TriggerHandle[PAD_MAX];
	bool ToggleHandle[PAD_MAX];
};
#endif