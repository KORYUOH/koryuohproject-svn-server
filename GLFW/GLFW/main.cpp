/**===File Commentary=======================================*/
/**
 *	@file	main.cpp
 *
 *	@brief	メイン関数
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/23
 */
/**===File Include=========================================*/
#include	<GameLogic/impl/GameRunner.h>
/**===Linker Options=======================================*/
#pragma comment ( linker,"/entry:mainCRTStartup")
#pragma comment ( linker,"/SUBSYSTEM:WINDOWS")
#pragma comment ( lib,"WSock32.lib")
/**===Functions============================================*/
int main(int argc,char* argv[]){
	GameRunner runner(argc,argv);
	runner.run();
	return 0;
}
/**===End Of Files=========================================*/