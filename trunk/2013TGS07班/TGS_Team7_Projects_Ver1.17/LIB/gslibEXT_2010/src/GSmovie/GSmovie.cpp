/******************************************************************************
* File Name : GSmovie.cpp 　                     Ver : 1.00  Date : 2007-10-04
*
* Description :
*
*       ムービー再生．
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include "GSmovie.h"
#include "./Movie/MovieTextureGL.h"
#include <windows.h>
#include <GL/gl.h>

/****** 変数宣言 *************************************************************/

// ムービークラス
static MovieTextureGL s_movie;

/*=============================================================================
*
* Purpose : ムービーのファイルの読み込み．
*
* Return  : 読み込みが成功すれば真，失敗すれば偽を返す．
*
*============================================================================*/
extern GSboolean
gsLoadMovie
(
	const char* fileName		/* ファイル名 */
)
{
	return s_movie.load( fileName );
}

/*=============================================================================
*
* Purpose : ムービーの再生．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsPlayMovie
(
	void
)
{
	s_movie.play();
}

/*=============================================================================
*
* Purpose : ムービーの更新．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsUpdateMovie
(
	void
)
{
	s_movie.update();
}

/*=============================================================================
*
* Purpose : ムービーの描画．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsDrawMovie
(
	void
)
{
	glPushAttrib( GL_ENABLE_BIT );

	// ライティングを無効
	glDisable( GL_LIGHTING );

	// カリングをしない
	glDisable( GL_CULL_FACE );

	// デプステストを無効にする
	glDisable( GL_DEPTH_TEST );

	// 透視変換の行列を単位行列にする
	glMatrixMode( GL_PROJECTION );
	glPushMatrix();
	glLoadIdentity();
	
	// 視野の行列を単位行列にする
	glMatrixMode( GL_MODELVIEW );
	glPushMatrix();
	glLoadIdentity();
	
	// ムービーの再生　（ビューポート全体に描画される）
	s_movie.draw();
	
	glPopMatrix();
	glMatrixMode( GL_PROJECTION );

	glPopMatrix();
	glMatrixMode( GL_MODELVIEW );
	
	glPopAttrib();
}

/*=============================================================================
*
* Purpose : ムービーの停止．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsStopMovie
(
	void
)
{
	s_movie.stop();
}

/*=============================================================================
*
* Purpose : ボリュームの設定．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsSetMovieVolume
(
	float volume		/* ボリューム (0.0（ミュート）〜1.0 （最大）) */
)
{
	s_movie.setVolume( volume );
}

/*=============================================================================
*
* Purpose : ボリュームの取得．
*
* Return  : ボリュームを返す． (0.0（ミュート）〜1.0 （最大）)
*
*============================================================================*/
extern GSfloat
gsGetMovieVolume
(
	void
)
{
	return s_movie.getVolume();
}

/*=============================================================================
*
* Purpose : ムービーの高さを取得．
*
* Return  : ムービーの高さを返す．
*
*============================================================================*/
extern GSuint
gsGetMovieHeight
(
	void
)
{
	return (GSuint)s_movie.getHeight();
}

/*=============================================================================
*
* Purpose : ムービーの幅を取得．
*
* Return  : ムービーの幅を返す．
*
*============================================================================*/
extern GSuint
gsGetMovieWidth
(
	void
)
{
	return (GSuint)s_movie.getWidth();
}

/*=============================================================================
*
* Purpose : ムービーの再生位置を設定．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsSetMovieTime
(
	GSfloat time			/* 再生位置 */
)
{
	s_movie.setTime( time );
}

/*=============================================================================
*
* Purpose : ムービーの再生位置を取得．
*
* Return  : 現在の再生位置を取得．
*
*============================================================================*/
extern GSfloat
gsGetMovieTime
(
	void 
)
{
	return s_movie.getTime();
}

/*=============================================================================
*
* Purpose : ムービーの終了時間を取得．
*
* Return  : なし．
*
*============================================================================*/
extern GSfloat
gsGetMovieEndTime
(
	void
)
{
	return s_movie.getEndTime();
}

/*=============================================================================
*
* Purpose : ムービーの削除．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsDeleteMovie
(
	void
)
{
	// ムービーをクリーンアップ
	s_movie.cleanup();
}

/********** End of File ******************************************************/
