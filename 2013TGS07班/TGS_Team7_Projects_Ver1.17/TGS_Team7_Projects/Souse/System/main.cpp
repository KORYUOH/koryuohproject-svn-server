/******************************************************************************
* File Name : main.cpp                           Ver : 1.00  Date : 2013-02-05
*
* Description :
*
*		メイン処理．
*
******************************************************************************/
#include"ShootingApplication.h"

// リンカオプション
#pragma comment( linker, "/entry:mainCRTStartup" )
#pragma comment( linker, "/SUBSYSTEM:WINDOWS" )


/// <summary>
//  メイン関数．
/// </summary>
/// <param name="argc">コマンドラインオプションの数のポインタ</param>
/// <param name="argv">コマンドラインオプションを表す文字列の配列</param>
void main( int argc, char* argv[] )
{
	/* アプリケーションの作成. */
	ShootingApplication application( argc, argv );

	/* アプリケーションを実行する. */
	application.Run();

}

/********** End of File ******************************************************/
