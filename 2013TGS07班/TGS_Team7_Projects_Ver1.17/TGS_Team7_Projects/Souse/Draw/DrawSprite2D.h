/******************************************************************************
* File Name : DrawSprite2D.h                     Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		スプライト2D描画．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _DRAW_SPRITE2D_H_
#define _DRAW_SPRITE2D_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include <gslib.h>

/// <summary>
/// ２Ｄスプライトの描画.
/// </summary>
/// <param name="uTextureID">テクスチャＩＤ</param>
/// <param name="pSrcRect">テクチャ内の位置</param>
/// <param name="pCenter">スプライトの中心位置</param>
/// <param name="pScaling">スケール値1.0が標準(１倍だから)</param>
/// <param name="fRotation">回転角度(角度)</param>
/// <param name="pTranslation">平行移動量</param>
/// <param name="pColor">カラー (1.0,1.0,10,1.0) = 変化なし</param>
void DrawSprite2D(
	/* テクスチャＩＤ 　　  */
	GSuint uTextureID,		
	/* テクチャ内の位置		*/
	const GSrect* pSrcRect,		
	/* スプライトの中心位置 */
	const GSvector2* pCenter,	
	/* スケール値			*/
	const GSvector2* pScaling,	
	/* 回転角度				*/
	GSfloat fRotation,				
	/* 平行移動量			*/
	const GSvector2* pTranslation,
	/* カラー 　				*/
	const GScolor* pColor			
);


#endif

/********** End of File ******************************************************/