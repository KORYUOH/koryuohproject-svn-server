/**===File Commentary=======================================*/
/**
 *	@file	main.cpp
 *
 *	@brief	ÉÅÉCÉìä÷êî
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/23
 */
/**===File Include=========================================*/
#include	<GameLogic/impl/GameRunner.h>
#include	<GameLogic/impl/GameTest.h>
/**===Linker Options=======================================*/
#pragma comment ( linker,"/entry:mainCRTStartup")
#pragma comment ( linker,"/SUBSYSTEM:WINDOWS")
/**===Functions============================================*/
int main(int argc,char* argv[]){
	GameRunner runner(argc,argv);
	runner.push_back( (GameSystem_ptr_t) new GameTest);
	runner.run();
	return 0;
}
/**===End Of Files=========================================*/