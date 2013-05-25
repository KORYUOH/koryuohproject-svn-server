/******************************************************************************
* File Name : game.c                             Ver : 1.00  Date : 2009-12-04
*
* Description :
*
*		ムービーファイル再生のサンプル。
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"game.h"
#include	<GSmovie.h>	// movie用のヘッダファイル

/****** グローバル変数宣言 ***************************************************/

static float volume = 1.0f;

/*=============================================================================
*
* Purpose : ゲーム初期化．
*
* Return  : なし
*
*============================================================================*/
void gameInit( void )
{
	// ムービーの読み込み
	gsLoadMovie( "kouchou_last.wmv" );

	// ムービーの再生
	gsPlayMovie();
}

/*=============================================================================
*
* Purpose : ゲームメイン処理．
*
* Return  : なし．
*
*============================================================================*/
void gameMain( void )
{
	// 停止テスト
	if ( gsGetKeyTrigger( GKEY_P ) == GS_TRUE ) {
		gsStopMovie();
	}
	// 再生テスト
	if ( gsGetKeyTrigger( GKEY_R ) == GS_TRUE ) {
		gsPlayMovie();
	}

	// ボリュームテスト
	if ( gsGetKeyState( GKEY_UP ) == GS_TRUE ) {
		volume += 0.01f;
	}
	if ( gsGetKeyState( GKEY_DOWN ) == GS_TRUE ) {
		volume -= 0.01f;
	}
	// ボリュームの設定 (０（ミュート）～1.0（最大））
	gsSetMovieVolume( volume );

	// ループ再生のテスト
	if ( gsGetMovieTime() >= gsGetMovieEndTime() ) {
		gsStopMovie();
		gsSetMovieTime(0);
		gsPlayMovie();
	}
}

/*=============================================================================
*
* Purpose : ゲーム描画処理．
*
* Return  : なし．
*
*============================================================================*/
void gameDraw( void )
{
	// ムービーの更新
	gsUpdateMovie();

	// ムービーの再生
	gsDrawMovie();

	// ボリュームの描画
	gsDrawText( "Volume = %f", gsGetMovieVolume() );
}

/*=============================================================================
*
* Purpose : ゲーム終了処理．
*
* Return  : なし．
*
*============================================================================*/
void gameFinish( void )
{
	// ムービーの削除
	gsDeleteMovie();
}

/********** End of File ******************************************************/
