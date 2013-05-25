/******************************************************************************
* File Name : game.c                             Ver : 1.00  Date : 2010-12-03
*
* Description :
*
*		音楽再生のサンプル．
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include "game.h"
#include <GSmusic.h> // 音楽再生のためのヘッダファイル

/****** グローバル変数宣言 ***************************************************/

// ボリューム
static float volume = 1.0f;

// 左右バランス
static float balance = 0.0f;

/*=============================================================================
*
* Purpose : ゲーム初期化．
*
* Return  : なし
*
*============================================================================*/
void gameInit( void )
{
	// 音楽ファイルの読み込み (mp3, wma, wav, midなど使用可)
	gsLoadMusic( 0, "hyperbeat_01.mp3", GS_TRUE ); // GS_TRUEでループ再生する
	// 操作したい音楽IDをバインド
	gsBindMusic( 0 );
	// バインド中の音楽を再生
	gsPlayMusic();
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
	// 操作したい音楽IDをバインド
	gsBindMusic(0);

	// 一時停止
	if ( gsGetKeyTrigger( GKEY_P ) == GS_TRUE ) {
		gsPauseMusic();
	}
	// 一時停止からの復帰
	if ( gsGetKeyTrigger( GKEY_R ) == GS_TRUE ) {
		gsRestartMusic();
	}

	// 再生
	if ( gsGetKeyTrigger( GKEY_Z ) == GS_TRUE ) {
		gsPlayMusic();
	}
	// 停止
	if ( gsGetKeyTrigger( GKEY_S ) == GS_TRUE ) {
		gsStopMusic();
	}

	// ボリュームの調整 ( 0.0(ミュート）～1.0(最大) )
	if ( gsGetKeyState( GKEY_UP )== GS_TRUE ) {
		volume += 0.01f;
	}
	if ( gsGetKeyState( GKEY_DOWN ) == GS_TRUE ) {
		volume -= 0.01f;
	}
	gsSetMusicVolume(volume);
	
	// 左右バランス ( -1.0f ～ 1.0f )
	if ( gsGetKeyState( GKEY_LEFT ) == GS_TRUE ) {
		balance += 0.01f;
	}
	if ( gsGetKeyState( GKEY_RIGHT ) == GS_TRUE ) {
		balance -= 0.01f;
	}
	gsSetMusicBalance(balance);
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
	// 操作したい音楽IDをバインド
	gsBindMusic(0);

	// 終了時間を描画
	gsTextPos(0,0);
	gsDrawText( "EndTime = %f", gsGetMusicEndTime() );

	// 現在の再生時間の描画
	gsTextPos(0,16);
	gsDrawText( "Time = %f", gsGetMusicTime() );

	// ボリュームの描画
	gsTextPos(0,32);
	gsDrawText( "Volume = %f", gsGetMusicVolume() );

	// 左右バランスの描画
	gsTextPos(0,48);
	gsDrawText( "Balance = %f", gsGetMusicBalance() );
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
	// 音楽の削除
	gsDeleteMusic(0);
}

/********** End of File ******************************************************/
