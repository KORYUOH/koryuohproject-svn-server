#define USE_WINDOW_MODE
#define __Debug
#include	<DxLibFlameWork/DxLibFW.h>

int WINAPI WinMain( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmdLine ,int nCmdShow ){
	DXFW system;
	system.run();
	return 0;
}