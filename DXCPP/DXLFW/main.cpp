#define USE_WINDOW_MODE
#define __Debug
#include "DxLibFlameWork/DxLibFW.h"

int WINAPI WinMain( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmdLine ,int nCmdShow ){
	DXFW systems;
	systems.run();
	return 0;
}