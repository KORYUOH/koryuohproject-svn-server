#ifndef __DEFINED
#define __DEFINED
#define	PAD_MAX						16
#ifndef WINDOW_MODE
	#ifdef USE_WINDOW_MODE
		#define WINDOW_MODE		true
	#else
		#define WINDOW_MODE		false
	#endif
#endif

#ifdef SETWINDOWTITLE
#define APPLICATIONTITLE SETWINDOWTITLE
#else
#define APPLICATIONTITLE "Dxlib"
#endif
#ifdef __Debug
#define OUTLOGFILE true
#else
#define OUTLOGFILE false
#endif
#ifndef __FIELDSTATE
	#define __FIELDSTATE
	#define FIELD_MAX_X				384
	#define FIELD_MAX_Y				448
	#define FMX							FIELD_MAX_X
	#define FMY							FIELD_MAX_Y
	#define FIELD_X						 32
	#define FIELD_Y						 16
#endif
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

#define PAD_KEY_UP							3
#define PAD_KEY_DOWN						0
#define PAD_KEY_LEFT						1
#define PAD_KEY_RIGHT						2
#define PAD_KEY_CIRCLE						5
#define PAD_KEY_CROSS						4
#define PAD_KEY_TRIANGLE					6
#define PAD_KEY_SQUARE					7
#define PAD_KEY_L1							10
#define PAD_KEY_L2							8
#define PAD_KEY_R1							11
#define PAD_KEY_R2							9
#define PAD_KEY_START						13 
#define PAD_KEY_SELECT						14

//#else
//extern PAD_MAX
//extern FIELD_MAX_X
//extern FIELD_MAX_Y
//extern FMX
//extern FMY
//extern FIELD_X
//extern FIELD_Y
//extern WINDOW_MODE
//extern PAD_KEY_UP	
//extern PAD_KEY_DOWN
//extern PAD_KEY_LEFT
//extern PAD_KEY_RIGHT
//extern PAD_KEY_CIRCLE
//extern PAD_KEY_CROSS
//extern PAD_KEY_TRIANGLE
//extern PAD_KEY_SQUARE
//extern PAD_KEY_L1	
//extern PAD_KEY_L2	
//extern PAD_KEY_R1	
//extern PAD_KEY_R2	
//extern PAD_KEY_START
//extern PAD_KEY_SELECT
#endif
