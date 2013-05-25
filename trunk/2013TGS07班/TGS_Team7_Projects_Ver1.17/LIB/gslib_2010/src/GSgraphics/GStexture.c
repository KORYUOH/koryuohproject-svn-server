/******************************************************************************
* File Name : gtexture.c                         Ver : 1.00  Date : 2002-08-13
*
* Description :
*
*       テクスチャ管理．
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GStexture.h"
#include	"heap.h"
#include	<memory.h>

/*=============================================================================
*
* Purpose : テクスチャの生成．
*
* Return  : テクスチャを返す．
*
*============================================================================*/
extern GStexture*
gsTextureNew
(
	void
)
{
	GStexture*	pTexture;

	pTexture = new_object( sizeof(GStexture) );

	pTexture->Format    = GS_TEX_RGBA;
	pTexture->dwWidth   = 0;
	pTexture->dwHeight  = 0;
	pTexture->pImage    = NULL;
	pTexture->dwTexName = 0;

	return	pTexture;
}

/*=============================================================================
*
* Purpose : テクスチャの消滅．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsTextureDelete
(
	GStexture*		pTexture			/* テクスチャ 			*/
)
{
	gsTextureCleanUP( pTexture );

	/* テクスチャの消滅 */
	del_object( pTexture );
}

/*=============================================================================
*
* Purpose : テクスチャのクリーンアップ．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsTextureCleanUP
(
	GStexture*		pTexture			/* テクスチャ 			*/
)
{
	/* テクチャイメージの削除 */
	if ( pTexture->pImage != NULL )
	{
		del_object( pTexture->pImage );

		/* テクスチャオブジェクトの削除 */
		glDeleteTextures( 1, &pTexture->dwTexName );
	}
	pTexture->Format    = GS_TEX_RGBA;
	pTexture->dwWidth   = 0;
	pTexture->dwHeight  = 0;
	pTexture->pImage    = NULL;
	pTexture->dwTexName = 0;
}

/*=============================================================================
*
* Purpose : テクスチャの初期化．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsTextureInitialize
(
	GStexture*		pTexture,			/* テクスチャ 				*/
	GStexformat		Format,				/* テクスチャフォーマット	*/
	GSuint			dwWidth,			/* テクスチャの幅			*/
	GSuint			dwHeight			/* テクスチャの高さ			*/
)
{
	size_t			size;

	/* テクチャのクリーンアップ */
	gsTextureCleanUP( pTexture );

	/* テクスチャフォーマットの設定 */
	pTexture->Format = Format;

	/* イメージサイズを求める */
	if ( ( size = sizeof(GSuint) * dwWidth * dwHeight ) == 0 )
	{
		return;
	}

	/* テクスチャの幅と高さを設定 */
	pTexture->dwWidth  = dwWidth;
	pTexture->dwHeight = dwHeight;

	/* テクスチャイメージの生成*/
	pTexture->pImage = new_object( sizeof(GSuint) * dwWidth * dwHeight );

	/* 初期設定では白 */
	memset( pTexture->pImage, 0xff, size );

	/* テクスチャ名を生成 */
	glGenTextures( 1, &pTexture->dwTexName );

	glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );

	/* テクチャオブジェクトをバインドする */
	glBindTexture( GL_TEXTURE_2D, pTexture->dwTexName );

	/* テクスチャイメージを設定 */
	glTexImage2D
	(
		GL_TEXTURE_2D,
		0,
		GL_RGBA,
		pTexture->dwWidth,
		pTexture->dwHeight,
		0,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		pTexture->pImage
	);

	/* テクチャパラメータの設定 */
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
}

/*=============================================================================
*
* Purpose : テクスチャフォーマットの取得．
*
* Return  : なし．
*
*============================================================================*/
extern GStexformat
gsTextureGetFormat
(
	GStexture*		pTexture			/* テクスチャ 				*/
)
{
	return	pTexture->Format;
}

/*=============================================================================
*
* Purpose : テクスチャの幅の取得．
*
* Return  : なし．
*
*============================================================================*/
extern GSuint
gsTextureGetWidth
(
	GStexture*		pTexture			/* テクスチャ 				*/
)
{
	return	pTexture->dwWidth;
}

/*=============================================================================
*
* Purpose : テクスチャの高さの取得．
*
* Return  : なし．
*
*============================================================================*/
extern GSuint
gsTextureGetHeight
(
	GStexture*		pTexture			/* テクスチャ 				*/
)
{
	return	pTexture->dwHeight;
}

/*=============================================================================
*
* Purpose : テクスチャ名の取得．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsTextureBind
(
	GStexture*		pTexture			/* テクスチャ 				*/
)
{
	/* テクチャオブジェクトをバインドする */
	glBindTexture( GL_TEXTURE_2D, pTexture->dwTexName );
}

/*=============================================================================
*
* Purpose : テクスチャイメージのロック．
*
* Return  : なし．
*
*============================================================================*/
extern void*
gsTextureLock
(
	GStexture*		pTexture			/* テクスチャ 				*/
)
{
	return	pTexture->pImage;
}

/*=============================================================================
*
* Purpose : テクスチャイメージのアンロック．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsTextureUnLock
(
	GStexture*		pTexture			/* テクスチャ 				*/
)
{
	if ( pTexture->pImage != NULL )
	{
		/* テクスチャイメージの更新 */
		glBindTexture( GL_TEXTURE_2D, pTexture->dwTexName );

		glTexImage2D
		(
			GL_TEXTURE_2D,
			0,
			GL_RGBA,
			pTexture->dwWidth,
			pTexture->dwHeight,
			0,
			GL_RGBA,
			GL_UNSIGNED_BYTE,
			pTexture->pImage
		);
	}
}

/*=============================================================================
*
* Purpose : テクスチャのカラーキーを設定．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsTextureSetColorKey
(
	GStexture*		pTexture,			/* テクスチャ 				*/
	GSubyte			Red,				/* カラーキー赤成分			*/
	GSubyte			Green,				/* カラーキー緑成分			*/
	GSubyte			Blue				/* カラーキー青成分			*/
)
{
	GSubyte*		pImage;
	GSuint			i;

	if ( pTexture->pImage == NULL || pTexture->Format != GS_TEX_RGBA )
	{
		return;
	}

	/* テクスチャイメージをロックする */
	pImage = (GSubyte*)gsTextureLock( pTexture );

	for ( i = 0; i < ( pTexture->dwWidth * pTexture->dwHeight ); i++ )
	{
		/* カラーキーとイメージのピクセルが等しいか？ */
		pImage[3] = 0xff;
		if ( Red   == pImage[0]
		  && Green == pImage[1]
		  && Blue  == pImage[2] )
		{
			/* カラーキーと等しい場合は透明にする */
			pImage[3] = 0;
		}
		pImage += 4;
	}

	/* テクスチャイメージをアンロックする */
	gsTextureUnLock( pTexture );
}

/********** End of File ******************************************************/
