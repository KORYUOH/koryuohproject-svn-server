/******************************************************************************
* File Name : GSmesh.c                           Ver : 1.00  Date : 2003-01-31
*
* Description :
*
*       メッシュデータ．
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GSmesh.h"
#include	"GSmath.h"
#include	"GSvector3.h"	
#include	"GScolor.h"
#include	"GSplane.h"	
#include	"heap.h"
#include	"gfile.h"
#include	<stdio.h>
#include	<string.h>
#include	<memory.h>
#include	<GL/glext.h>

/****** 関数プロトタイプ宣言 *************************************************/

static void	DrawMesh( GSmaterial*, GSuint, GSfacegroup*, GSushort*, GSvector3*, GSvector3*, GScolor*, GSuint, GSvector2** );
static void	DrawMeshCelShade( GSmaterial*, GSuint, GSfacegroup*, GSuint, GSushort*, GSuint, GSvector3*, GSvector3*, GScolor*, GSuint, GSvector2**, GStexture*,  GSvector3*, GScolor*, GSfloat );
static void	SetMaterial( GSmaterial* );
static void	LoadMaterial( GSmaterial*, GFILE );
static void	TransformPoints( GSvector3*, GSuint, GSvector3*, GSuint, GSfloat**, GSuint*, const GSmatrix4* );
static void	TransformNormals( GSvector3*, GSuint, GSvector3*, GSuint, GSfloat**, GSuint*, const GSmatrix4* );
static void CalculatePlanes( GSmesh* );

/*=============================================================================
*
* Purpose : メッシュの生成．
*
* Return  : メッシュを返す．
*
*============================================================================*/
extern GSmesh*
gsMeshNew
(
	void
)
{
	GSmesh*		pMesh;

	/* メッシュの生成 */
	pMesh = new_object( sizeof( GSmesh ) );

	/* 全てのメンバをゼロクリアする */
	memset( pMesh, 0, sizeof( GSmesh ) );

	return	pMesh;
}

/*=============================================================================
*
* Purpose : メッシュの消滅．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsMeshDelete
(
	GSmesh*			pMesh				/* メッシュデータ		*/
)
{
	/* メッシュをクリーンアップする */
	gsMeshCleanUp( pMesh );

	/* メッシュの消滅 */
	del_object( pMesh );
}

/*=============================================================================
*
* Purpose : メッシュのクリーンアップ．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsMeshCleanUp
(
	GSmesh*			pMesh				/* メッシュデータ		*/
)
{
	GSuint		i;

	/* ボーンインデックス配列の消滅 */
	if ( pMesh->pBoneIndices != NULL )
	{
		del_object( pMesh->pBoneIndices );
	}

	/* 頂点ウェイト配列の消滅 */
	if ( pMesh->ppWeights != NULL )
	{
		for ( i = 0; i < pMesh->numWeights; i++ )
		{
			if ( pMesh->ppWeights[i] != NULL )
			{
				del_object( pMesh->ppWeights[i] );
			}
		}
		del_object( pMesh->ppWeights );
	}

	/* テクスチャ座標配列の消滅 */
	if ( pMesh->ppTexCoords != NULL )
	{
		for ( i = 0; i < pMesh->numTexCoords; i++ )
		{
			if ( pMesh->ppTexCoords[i] != NULL )
			{
				del_object( pMesh->ppTexCoords[i] );
			}
		}
		del_object( pMesh->ppTexCoords );
	}

	/* 反射光カラー配列の消滅 */
	if ( pMesh->pSpecularColors != NULL )
	{
		del_object( pMesh->pSpecularColors );
	}

	/* 拡散光カラー配列の消滅 */
	if ( pMesh->pDiffuseColors != NULL )
	{
		del_object( pMesh->pDiffuseColors );
	}

	/* 法線ベクトル配列の消滅 */
	if ( pMesh->pNormals != NULL )
	{
		del_object( pMesh->pNormals );
	}

	/* 頂点座標配列の消滅 */
	if ( pMesh->pPoints != NULL )
	{
		del_object( pMesh->pPoints );
	}

	/* マテリアルデータの消滅 */
	if ( pMesh->pMaterials != NULL )
	{
		for ( i = 0; i < pMesh->numMaterials; i++ )
		{
			/* テクスチャの消滅 */
			if ( pMesh->pMaterials[i].pTexture != NULL )
			{
				gsTextureDelete( pMesh->pMaterials[i].pTexture );
			}
		}
		del_object( pMesh->pMaterials );
	}

	/* 頂点インデックス配列の消滅 */
	if ( pMesh->pIndices != NULL )
	{
		del_object( pMesh->pIndices );
	}

	/* 面データ配列の消滅 */
	if ( pMesh->pFaceGroups != NULL )
	{
		del_object( pMesh->pFaceGroups );
	}

	/* 平面データ配列の消滅 */
	if ( pMesh->pPlanes != NULL )
	{
		del_object( pMesh->pPlanes );
	}

	/* 全てのメンバをゼロクリアする */
	memset( pMesh, 0, sizeof( GSmesh ) );
}

/*=============================================================================
*
* Purpose : メッシュファイルの読み込み．
*
* Return  : なし．
*
*============================================================================*/
extern GSboolean
gsMeshLoadFile
(
	GSmesh*			pMesh,				/* メッシュデータ		*/
	const char*		pszFileName			/* ファイル名			*/
)
{
	GFILE			file;
	GSuint			bPoints;
	GSuint			bNormals;
	GSuint			bDiffuseColors;
	GSuint			bSpecularColors;
	GSuint			bBoneIndices;
	GSuint			i;

	/* メッシュファイルをオープンする */
	if ( ( file = GFileOpen( pszFileName, "r" ) ) == NULL )
	{
		/* ファイルがオープンできなかった */
		return	GS_FALSE;
	}

	/* メッシュのクリーンアップ */
	gsMeshCleanUp( pMesh );

	/* メッシュ情報フラグを読み込む */
	GFileReadDwordHex( file, &pMesh->MeshInfo );

	/* 頂点データ情報数の読み込み ( 現時点では使用していない ）*/
	GFileReadDword( file, &bPoints );

	/* 頂点データフラグの読み込み */
	GFileReadDword( file, &bPoints );

	/* 法線ベクトルデータフラグの読み込み */
	GFileReadDword( file, &bNormals );

	/* 拡散光カラーデータフラグの読み込み */
	GFileReadDword( file, &bDiffuseColors );

	/* 鏡面反射光カラーデータフラグの読み込み */
	GFileReadDword( file, &bSpecularColors );

	/* テクスチャ座標データ数の読み込み */
	GFileReadDword( file, &pMesh->numTexCoords );

	/* 頂点ウェイトデータ数の読み込み */
	GFileReadDword( file, &pMesh->numWeights );

	/* ボーンインデックスデータフラグの読み込み */
	GFileReadDword( file, &bBoneIndices );

	/* マテリアルデータ数の読み込み */
	GFileReadDword( file, &pMesh->numMaterials );

	/* 面データグループ数の読み込み */
	GFileReadDword( file, &pMesh->numFaceGroups );

	/* 頂点インデックスデータ数の読み込み */
	GFileReadDword( file, &pMesh->numIndices );

	/* 頂点データ数の読み込み */
	GFileReadDword( file, &pMesh->numVertices );

	/* マテリアルデータ配列の生成 */
	pMesh->pMaterials = new_object( sizeof( GSmaterial ) * pMesh->numMaterials );

	/* マテリアルデータ配列の読み込み */
	for ( i = 0; i < pMesh->numMaterials; i++ )
	{
		LoadMaterial( &pMesh->pMaterials[i], file );
	}

	/* 面グループ配列の生成 */
	pMesh->pFaceGroups = new_object( sizeof( GSfacegroup ) * pMesh->numFaceGroups );

	/* 面グループの配列の読み込み */
	for ( i = 0; i < pMesh->numFaceGroups; i++ )
	{
		/* 面情報フラグの読み込み */
		GFileReadDwordHex( file, &pMesh->pFaceGroups[i].FaceInfo );

		/* マテリアルインデックスの読み込み	*/
		GFileReadDword( file, &pMesh->pFaceGroups[i].MaterialNo );

		/* 頂点インデックスの開始位置の読み込み */
		GFileReadDword( file, &pMesh->pFaceGroups[i].StartIndices );

		/* 頂点インデックス数の読み込み */
		GFileReadDword( file, &pMesh->pFaceGroups[i].numIndices );
	}

	/* 頂点インデックス配列の読み込み */
	if ( pMesh->numIndices != 0 )
	{
		pMesh->pIndices = new_object( sizeof( GSushort ) * pMesh->numIndices );

		GFileReadWordArray( file, pMesh->numIndices, pMesh->pIndices );
	}

	/* 頂点データ配列の読み込み */
	if ( bPoints == GS_TRUE )
	{
		pMesh->pPoints = new_object( sizeof( GSvector3 ) * pMesh->numVertices );

		GFileReadVector3Array( file, pMesh->numVertices, pMesh->pPoints );
	}

	/* 法線ベクトル配列の読み込み */
	if ( bNormals == GS_TRUE )
	{
		pMesh->pNormals = new_object( sizeof( GSvector3 ) * pMesh->numVertices );

		GFileReadVector3Array( file, pMesh->numVertices, pMesh->pNormals );
	}

	/* 拡散光カラー配列の読み込み */
	if ( bDiffuseColors == GS_TRUE )
	{
		pMesh->pDiffuseColors = new_object( sizeof( GScolor ) * pMesh->numVertices );

		GFileReadColorArray( file, pMesh->numVertices, pMesh->pDiffuseColors );
	}

	/* 鏡面反射光カラー配列の読み込み */
	if ( bSpecularColors == GS_TRUE )
	{
		pMesh->pSpecularColors = new_object( sizeof( GScolor ) * pMesh->numVertices );

		GFileReadColorArray( file, pMesh->numVertices, pMesh->pSpecularColors );
	}

	/* テクスチャ座標配列の読み込み */
	if ( pMesh->numTexCoords != 0 )
	{
		pMesh->ppTexCoords = new_object( sizeof( GSvector2* ) * pMesh->numTexCoords );

		for ( i = 0; i < pMesh->numTexCoords; i++ )
		{
			pMesh->ppTexCoords[i] = new_object( sizeof( GSvector2 ) * pMesh->numVertices );

			GFileReadTexCoordArray( file, pMesh->numVertices, pMesh->ppTexCoords[i] );
		}
	}

	/* 頂点ウェイト配列の読み込み */
	if ( pMesh->numWeights != 0 )
	{
		pMesh->ppWeights = new_object( sizeof( GSfloat* ) * pMesh->numWeights );

		for ( i = 0; i < pMesh->numWeights; i++ )
		{
			pMesh->ppWeights[i] = new_object( sizeof( GSfloat ) * pMesh->numVertices );

			GFileReadFloatArray( file, pMesh->numVertices, pMesh->ppWeights[i] );
		}
	}

	/* ボーンインデックス配列の読み込み */
	if ( bBoneIndices == TRUE )
	{
		pMesh->pBoneIndices = new_object( sizeof( GSuint ) * pMesh->numVertices );

		GFileReadDwordHexArray( file, pMesh->numVertices, pMesh->pBoneIndices );
	}

	/* メッシュファイルのクローズ */
	GFileClose( file );

	/* メッシュの平面データ配列を計算する */
	CalculatePlanes( pMesh );

	return	GS_TRUE;
}

/*=============================================================================
*
* Purpose : メッシュの描画．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsMeshDraw
(
	GSmesh*			pMesh				/* メッシュデータ		*/
)
{
	/* メッシュを描画する */
	DrawMesh
	(
		pMesh->pMaterials,
		pMesh->numFaceGroups,
		pMesh->pFaceGroups,
		pMesh->pIndices,
		pMesh->pPoints,
		pMesh->pNormals,
		pMesh->pDiffuseColors,
		pMesh->numTexCoords,
		pMesh->ppTexCoords
	);
}

/*=============================================================================
*
* Purpose : メッシュの描画．（ セルシェーディング ）
*
* Return  : なし．
*
*============================================================================*/
extern void
gsMeshDrawCelShade
(
	GSmesh*			pMesh,				/* メッシュデータ				*/
	GStexture*		pShadeTexture,		/* シェーディング用テクスチャ	*/
	GSvector3*		pShadeLight,		/* ライトの位置					*/
	GScolor*		pLineColor,			/* 輪郭線の色					*/
	GSfloat			fLineWidth			/* 輪郭線の太さ					*/
)
{
	/* セルシェーディングを行いメッシュを描画する */
	DrawMeshCelShade
	(
		pMesh->pMaterials,
		pMesh->numFaceGroups,
		pMesh->pFaceGroups,
		pMesh->numIndices,
		pMesh->pIndices,
		pMesh->numVertices,
		pMesh->pPoints,
		pMesh->pNormals,
		pMesh->pDiffuseColors,
		pMesh->numTexCoords,
		pMesh->ppTexCoords,
		pShadeTexture,
		pShadeLight,
		pLineColor,
		fLineWidth
	);
}

/*=============================================================================
*
* Purpose : スキニングメッシュの描画．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsMeshDrawSkin
(
	GSmesh*				pMesh,			/* メッシュデータ		*/
	const GSmatrix4*	pMatrices		/* 変換行列配列			*/
)
{
	GSvector3*			pPoints;
	GSvector3*			pNormals;

	/* ボーンインデックスを持っているか？ */
	if ( pMesh->pBoneIndices == NULL )
	{
		/* ボーンインデックスがない場合はスキニングの計算はしない */
		gsMeshDraw( pMesh );

		return;
	}

	/* 頂点データ配列を生成する */
	pPoints = new_object( sizeof( GSvector3 ) * pMesh->numVertices );

	/* 法線ベクトル配列を生成する	*/
	pNormals = new_object( sizeof( GSvector3 ) * pMesh->numVertices );

	/* 頂点データ配列を座標変換する */
	TransformPoints
	(
		pPoints,
		pMesh->numVertices,
		pMesh->pPoints,
		pMesh->numWeights,
		pMesh->ppWeights,
		pMesh->pBoneIndices,
		pMatrices
	);

	/* 法線データ配列を座標変換する */
	TransformNormals
	(
		pNormals,
		pMesh->numVertices,
		pMesh->pNormals,
		pMesh->numWeights,
		pMesh->ppWeights,
		pMesh->pBoneIndices,
		pMatrices
	);

	/* メッシュを描画する */
	DrawMesh
	(
		pMesh->pMaterials,
		pMesh->numFaceGroups,
		pMesh->pFaceGroups,
		pMesh->pIndices,
		pPoints,
		pNormals,
		pMesh->pDiffuseColors,
		pMesh->numTexCoords,
		pMesh->ppTexCoords
	);

	/* 法線ベクトル配列を消滅させる */
	del_object( pNormals );

	/* 頂点データ配列を消滅させる */
	del_object( pPoints );
}

/*=============================================================================
*
* Purpose : スキニングメッシュの描画．（ セルシェーディング ）
*
* Return  : なし．
*
*============================================================================*/
extern void
gsMeshDrawSkinCelShade
(
	GSmesh*				pMesh,			/* メッシュデータ				*/
	const GSmatrix4*	pMatrices,		/* 変換行列配列					*/
	GStexture*			pShadeTexture,	/* シェーディング用テクスチャ	*/
	GSvector3*			pShadeLight,	/* ライトの位置					*/
	GScolor*			pLineColor,		/* 輪郭線の色					*/
	GSfloat				fLineWidth		/* 輪郭線の太さ					*/
)
{
	GSvector3*			pPoints;
	GSvector3*			pNormals;

	/* ボーンインデックスを持っているか？ */
	if ( pMesh->pBoneIndices == NULL )
	{
		/* ボーンインデックスがない場合はスキニングの計算はしない */
		gsMeshDrawCelShade
		(
			pMesh,
			pShadeTexture,
			pShadeLight,
			pLineColor,
			fLineWidth
		);

		return;
	}

	/* 頂点データ配列を生成する */
	pPoints = new_object( sizeof( GSvector3 ) * pMesh->numVertices );

	/* 法線ベクトル配列を生成する	*/
	pNormals = new_object( sizeof( GSvector3 ) * pMesh->numVertices );

	/* 頂点データ配列を座標変換する */
	TransformPoints
	(
		pPoints,
		pMesh->numVertices,
		pMesh->pPoints,
		pMesh->numWeights,
		pMesh->ppWeights,
		pMesh->pBoneIndices,
		pMatrices
	);

	/* 法線データ配列を座標変換する */
	TransformNormals
	(
		pNormals,
		pMesh->numVertices,
		pMesh->pNormals,
		pMesh->numWeights,
		pMesh->ppWeights,
		pMesh->pBoneIndices,
		pMatrices
	);

	/* セルシェーディングを行いメッシュを描画する */
	DrawMeshCelShade
	(
		pMesh->pMaterials,
		pMesh->numFaceGroups,
		pMesh->pFaceGroups,
		pMesh->numIndices,
		pMesh->pIndices,
		pMesh->numVertices,
		pPoints,
		pNormals,
		pMesh->pDiffuseColors,
		pMesh->numTexCoords,
		pMesh->ppTexCoords,
		pShadeTexture,
		pShadeLight,
		pLineColor,
		fLineWidth
	);

	/* 法線ベクトル配列を消滅させる */
	del_object( pNormals );

	/* 頂点データ配列を消滅させる */
	del_object( pPoints );
}

/*-----------------------------------------------------------------------------
*
* Purpose : メッシュの描画．
*
* Return  : なし．
*
*----------------------------------------------------------------------------*/
static void
DrawMesh
(
	GSmaterial*		pMaterials,			/* マテリアルデータ配列	*/
	GSuint			numFaceGroups,		/* 面データグループ数	*/
	GSfacegroup*	pFaceGroups,		/* 面データグループ		*/
	GSushort*		pIndices,			/* 頂点インデックス		*/
	GSvector3*		pPoints,			/* 頂点データ配列		*/
	GSvector3*		pNormals,			/* 法線ベクトル配列		*/
	GScolor*		pDiffuseColors,		/* 拡散光配列			*/
	GSuint			numTexCoords,		/* テクスチャ座標配列数	*/
	GSvector2**	ppTexCoords			/* テクスチャ座標配列	*/
)
{
	GScolor			CurrentColor;
	GSuint			i;

	/* 各種レンダリングモードの退避 */
	glPushAttrib( GL_ENABLE_BIT );

	/* 現在のカラーを取得する */
	glGetFloatv( GL_CURRENT_COLOR, (GLfloat*)&CurrentColor );

	/* 頂点データ配列の設定 */
	glDisableClientState( GL_NORMAL_ARRAY );
	if ( pPoints != NULL )
	{
		glEnableClientState( GL_VERTEX_ARRAY );
		glVertexPointer( 3, GL_FLOAT, 0, pPoints );
	}

	/* 法線ベクトル配列の設定 */
	glDisableClientState( GL_NORMAL_ARRAY );
	if ( pNormals != NULL )
	{
		glEnableClientState( GL_NORMAL_ARRAY );
		glNormalPointer( GL_FLOAT, 0, pNormals );
	}

	/* カラーデータ配列の設定 */
	glDisableClientState( GL_COLOR_ARRAY );
	if ( pDiffuseColors != NULL )
	{
		glEnableClientState( GL_COLOR_ARRAY );
		glColorPointer( 4, GL_FLOAT, 0, pDiffuseColors );
	}

	/* テクスチャ座標配列の設定 */
	glDisableClientState( GL_TEXTURE_COORD_ARRAY );
	if ( numTexCoords != 0 )
	{
		glEnableClientState( GL_TEXTURE_COORD_ARRAY );
		glTexCoordPointer( 2, GL_FLOAT, 0, ppTexCoords[0] );
	}

	for ( i = 0; i < numFaceGroups; i++ )
	{
		/* マテリアル情報の設定をする */
		SetMaterial( &pMaterials[ pFaceGroups[i].MaterialNo ] );

		/* 三角形を描画する */
		glDrawElements
		(
			GL_TRIANGLES,
			pFaceGroups[i].numIndices,
			GL_UNSIGNED_SHORT, 
			&pIndices[ pFaceGroups[i].StartIndices ]
		);

		/* カレントカラーを設定する */
		glColor4fv( (GLfloat*)&CurrentColor );
	}

	/* レンダリングモードの復帰 */
	glPopAttrib();
}

/*-----------------------------------------------------------------------------
*
* Purpose : メッシュの描画．（ セルシェーディング ）
*
* Return  : なし．
*
*----------------------------------------------------------------------------*/
static void
DrawMeshCelShade
(
	GSmaterial*		pMaterials,			/* マテリアルデータ配列			*/
	GSuint			numFaceGroups,		/* 面データグループ数			*/
	GSfacegroup*	pFaceGroups,		/* 面データグループ				*/
	GSuint			numIndices,			/* 頂点インデックス数			*/
	GSushort*		pIndices,			/* 頂点インデックス				*/
	GSuint			numVertices,		/* 頂点データ数					*/
	GSvector3*		pPoints,			/* 頂点データ配列				*/
	GSvector3*		pNormals,			/* 法線ベクトル配列				*/
	GScolor*		pDiffuseColors,		/* 拡散光配列					*/
	GSuint			numTexCoords,		/* テクスチャ座標配列数			*/
	GSvector2**	ppTexCoords,		/* テクスチャ座標配列			*/
	GStexture*		pShadeTexture,		/* シェーディング用テクスチャ	*/
	GSvector3*		pShadeLight,		/* ライトの位置					*/
	GScolor*		pLineColor,			/* 輪郭線の色					*/
	GSfloat			fLineWidth			/* 輪郭線の太さ					*/
)
{
	GSmaterial*		pMaterial;
	GSvector2*		pTexCoords;
	GScolor			CurrentColor;
	GSmatrix4		tmpMat;
	GSvector3		tmpLight;
	GScolor			tmpColor;
	GSuint			i;

	/* 現在のカラーを取得する */
	glGetFloatv( GL_CURRENT_COLOR, (GLfloat*)&CurrentColor );

	/* トゥーンシェーディング用のテクスチャ座標配列を生成 */
	pTexCoords = new_object( sizeof( GSvector2 ) * numVertices );

	/* モデルビュー変換マトリクスを取得する */
	glGetFloatv( GL_MODELVIEW_MATRIX, (GLfloat*)&tmpMat );

	/* ライトの方向にモデルビュー変換行列の逆行列を掛け算する */
	tmpLight.x = pShadeLight->x * tmpMat.m[0][0]
			   + pShadeLight->y * tmpMat.m[0][1]
			   + pShadeLight->z * tmpMat.m[0][2];
	tmpLight.y = pShadeLight->x * tmpMat.m[1][0]
			   + pShadeLight->y * tmpMat.m[1][1]
			   + pShadeLight->z * tmpMat.m[1][2];
	tmpLight.z = pShadeLight->x * tmpMat.m[2][0]
			   + pShadeLight->y * tmpMat.m[2][1]
			   + pShadeLight->z * tmpMat.m[2][2];

	/* ライトのベクトルを正規化する */
	gsVector3Normalize( &tmpLight, &tmpLight );

	if ( pNormals != NULL )
	{
		/* トゥーンシェーディングのテクスチャ座標の計算を行う */
		for ( i = 0; i < numVertices; i++ )
		{
			/* ライトの方向と法線ベクトルからテクスチャ座標を求める */
			pTexCoords[i].s = MAX( 0.0f, gsVector3Dot( &pNormals[i], &tmpLight ) );
			pTexCoords[i].t = 0.0f;
		}
	}
	else
	{
		/* 法線ベクトルが存在しない場合はシェーディングできない */
		for ( i = 0; i < numVertices; i++ )
		{
			pTexCoords[i].s = 1.0f;
			pTexCoords[i].t = 0.0f;
		}
	}

	/* 各種レンダリングモードの退避 */
	glPushAttrib
	(
		GL_ENABLE_BIT 		|
		GL_DEPTH_BUFFER_BIT |
		GL_COLOR_BUFFER_BIT |
		GL_POLYGON_BIT
	);

	/* ライティングをオフにする */
	glDisable( GL_LIGHTING );
	glDepthFunc( GL_LEQUAL );
	glEnable( GL_BLEND );

	/* 頂点データ配列の設定 */
	glDisableClientState( GL_VERTEX_ARRAY );
	if ( pPoints != NULL )
	{
		glEnableClientState( GL_VERTEX_ARRAY );
		glVertexPointer( 3, GL_FLOAT, 0, pPoints );
	}

	/* カラーデータ配列の設定 */
	glDisableClientState( GL_COLOR_ARRAY );
	if ( pDiffuseColors != NULL )
	{
		glEnableClientState( GL_COLOR_ARRAY );
		glColorPointer( 4, GL_FLOAT, 0, pDiffuseColors );
	}

	/* 法線ベクトル配列の設定 */
	glDisableClientState( GL_NORMAL_ARRAY );
	if ( pNormals != NULL )
	{
		glEnableClientState( GL_NORMAL_ARRAY );
		glNormalPointer( GL_FLOAT, 0, pNormals );
	}

	for ( i = 0; i < numFaceGroups; i++ )
	{
		/* マテリアルデータの取得 */
		pMaterial = &pMaterials[ pFaceGroups[i].MaterialNo ];

		/* マテリアルの設定 */
		gsColorModulate( &tmpColor, &pMaterial->Diffuse, &CurrentColor );
		glColor4fv( (GLfloat*)&tmpColor );

		/* 法線ベクトル配列を無効にする */
		glDisableClientState( GL_NORMAL_ARRAY );

		/* テクスチャ座標を有効にする */
		glEnableClientState( GL_TEXTURE_COORD_ARRAY );

		/* セルシェーディング用のテクスチャをバインドする */
		if ( pShadeTexture != NULL )
		{
			gsTextureBind( pShadeTexture );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP );
			glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
			glEnable( GL_TEXTURE_2D );
		}
		else
		{
			glDisable( GL_TEXTURE_2D );
		}

		/* セルシェーディング用のテクスチャ座標を設定する */
		glTexCoordPointer( 2, GL_FLOAT, 0, pTexCoords );

		/* セルシェーディング用ポリゴンを描画する */
		glDrawElements
		(
			GL_TRIANGLES,
			pFaceGroups[i].numIndices,
			GL_UNSIGNED_SHORT, 
			&pIndices[ pFaceGroups[i].StartIndices ]
		);

		if ( pMaterial->pTexture != NULL )
		{
			/* テクスチャマッピングの設定 */
			gsTextureBind( pMaterial->pTexture );
			glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
			glBlendFunc( GL_DST_COLOR, GL_ZERO );
			glEnable( GL_TEXTURE_2D );

			/* テクスチャをクランプするか？*/
			if ( ( pMaterial->MaterialInfo & GS_MATERIAL_TEX_CLAMP ) != 0 )
			{
				/* テクスチャをクランプに設定する */
				glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP );
				glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP );

				/* EDGEクランプが有効であれば使用する */
				glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
				glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
			}
			else
			{
				/* テクスチャをラップさせる */
				glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
				glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
			}

			/* 球形環境マッピングを行うか？ */
			if ( ( pMaterial->MaterialInfo & GS_MATERIAL_SPHERE_MAP ) != 0 )
			{
				/* 球形環境マッピングを有効にする */
				glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP );
				glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP );
				glEnable( GL_TEXTURE_GEN_S );
				glEnable( GL_TEXTURE_GEN_T );
				glDisableClientState( GL_TEXTURE_COORD_ARRAY );

				/* 法線ベクトル配列を有効にする */
				glEnableClientState( GL_NORMAL_ARRAY );
			}
			else
			{
				/* 通常のテクスチャ座標配列の設定 */
				glTexCoordPointer( 2, GL_FLOAT, 0, ppTexCoords[0] );
			}

			/* 通常のテクスチャを描画する */
			glDrawElements
			(
				GL_TRIANGLES,
				pFaceGroups[i].numIndices,
				GL_UNSIGNED_SHORT, 
				&pIndices[ pFaceGroups[i].StartIndices ]
			);

			/* 球形環境マッピングを無効にする */
			glDisable( GL_TEXTURE_GEN_S );
			glDisable( GL_TEXTURE_GEN_T );
		}

		/* カレントカラーを復帰する */
		glColor4fv( (GLfloat*)&CurrentColor );
	}

	/* 輪郭線の描画を行う */
	if ( fLineWidth > 0 )
	{
		float scale = fLineWidth * 0.01f;
	
		/* 法線方向に頂点データを拡大する */
		for ( i = 0; i < numVertices; i++ )
		{
			pPoints[i].x += pNormals[i].x * scale;
			pPoints[i].y += pNormals[i].y * scale;
			pPoints[i].z += pNormals[i].z * scale;
		}

		/* テクスチャを無効にする */
		glDisableClientState( GL_TEXTURE_COORD_ARRAY );
		glDisable( GL_TEXTURE_2D );

		/* 輪郭線の色を設定する */
		gsColorModulate( &tmpColor, pLineColor, &CurrentColor );
		glColor4fv( (GLfloat*)&tmpColor );

		/* レンダリングモードの設定 */
		glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
		glCullFace( GL_FRONT );

		/* 輪郭線を描画する */
		glDrawElements
		(
			GL_TRIANGLES,
			numIndices,
			GL_UNSIGNED_SHORT,
			pIndices
		);

		/* カレントカラーを復帰する */
		glColor4fv( (GLfloat*)&CurrentColor );
	}

	/* 各種レンダリングモードの復帰 */
	glPopAttrib();

	/* トゥーンシェーディング用のテクスチャ座標を消滅させる */
	del_object( pTexCoords );
}

/*-----------------------------------------------------------------------------
*
* Purpose : マテリアルの設定．
*
* Return  : なし．
*
*----------------------------------------------------------------------------*/
static void
SetMaterial
(
	GSmaterial*		pMaterial			/* マテリアルデータ	*/
)
{
	GScolor			Diffuse;
	GScolor			Ambient;
	GScolor			CurrentColor;

	/* 現在のカラーを取得する */
	glGetFloatv( GL_CURRENT_COLOR, (GLfloat*)&CurrentColor );

	/* 環境光と拡散光カラーを現在のカラーと変調する */
	gsColorModulate( &Diffuse, &pMaterial->Diffuse, &CurrentColor );
	gsColorModulate( &Ambient, &pMaterial->Ambient, &CurrentColor );

	/* マテリアル情報の設定 */
	glMaterialfv( GL_FRONT, GL_DIFFUSE,   (GLfloat*)&Diffuse );
	glMaterialfv( GL_FRONT, GL_AMBIENT,   (GLfloat*)&Ambient );
	glMaterialfv( GL_FRONT, GL_SPECULAR,  (GLfloat*)&pMaterial->Specular );
	glMaterialfv( GL_FRONT, GL_EMISSION,  (GLfloat*)&pMaterial->Emissive );
	glMaterialf(  GL_FRONT, GL_SHININESS, (GLfloat)pMaterial->Power      );

	/* ライティングがオフの場合のマテリアル設定 */
	glColor4fv( (GLfloat*)&Diffuse );

	if ( pMaterial->pTexture == NULL )
	{
		/* テクスチャマッピングの設定解除 */
		glDisableClientState( GL_TEXTURE_COORD_ARRAY );
		glDisable( GL_TEXTURE_2D );
		glDisable( GL_TEXTURE_1D );
	}
	else
	{
		/* テクスチャマッピングの設定 */
		gsTextureBind( pMaterial->pTexture );
		glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
		glEnable( GL_TEXTURE_2D );
		glEnableClientState( GL_TEXTURE_COORD_ARRAY );

		/* テクスチャをクランプするか？*/
		if ( ( pMaterial->MaterialInfo & GS_MATERIAL_TEX_CLAMP ) != 0 )
		{
			/* テクスチャをクランプに設定する */
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP );

			/* EDGEクランプが有効であれば使用する */
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
		}
		else
		{
			/* テクスチャをラップさせる */
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
		}
	}

	if ( ( pMaterial->MaterialInfo & GS_MATERIAL_SPHERE_MAP ) != 0 )
	{
		/* 球形環境マッピングを有効にする */
		glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP );
		glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP );
		glEnable( GL_TEXTURE_GEN_S );
		glEnable( GL_TEXTURE_GEN_T );
		glDisableClientState( GL_TEXTURE_COORD_ARRAY );
	}
	else
	{
		/* 球形環境マッピングを無効にする */
		glDisable( GL_TEXTURE_GEN_S );
		glDisable( GL_TEXTURE_GEN_T );
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : マテリアルの読み込み．
*
* Return  : なし．
*
*----------------------------------------------------------------------------*/
static void
LoadMaterial
(
	GSmaterial*	pMaterial,				/* マテリアル		*/
	GFILE		file					/* ファイル			*/
)
{
	/* マテリアル情報フラグの読み込み */
	GFileReadDwordHex( file, &pMaterial->MaterialInfo );

	/* 拡散光カラーの読み込み */
	GFileReadColor( file, &pMaterial->Diffuse );

	/* 環境光カラーの読み込み */
	GFileReadColor( file, &pMaterial->Ambient );

	/* 鏡面反射光カラーの読み込み */
	GFileReadColor( file, &pMaterial->Specular );

	/* 放射光カラーの読み込み */
	GFileReadColor( file, &pMaterial->Emissive );

	/* ハイライトの鮮明度の読み込み */
	GFileReadFloat( file, &pMaterial->Power );

	/* テクスチャを持っているか？ */
	pMaterial->pTexture = NULL;
	if ( ( pMaterial->MaterialInfo & GS_MATERIAL_TEXTURE ) != 0 )
	{
		char	TexFileName[_MAX_PATH];
		char	Drive[_MAX_DRIVE];
		char	Dir[_MAX_DIR];

		/* オープンしているメッシュファイルのパスを取得する */
		_splitpath( GFileGetFileName( file ), Drive, Dir, NULL, NULL );
		strcpy( TexFileName, Drive );
		strcat( TexFileName, Dir );

		/* テクスチャファイル名の読み込み */
		GFileReadString( file, TexFileName + strlen( TexFileName ) );

		/* テクスチャを生成 */
		pMaterial->pTexture = gsTextureNew();

		/* テクスチャデータを読み込む */
		gsTextureLoadBmpFile( pMaterial->pTexture, TexFileName );
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : 頂点データの座標変換．
*
* Return  : なし．
*
*----------------------------------------------------------------------------*/
static void
TransformPoints
(
	GSvector3*		pOutPoints,			/*-> 計算後頂点データ配列	*/
	GSuint			numPoints,			/* 頂点データ数				*/
	GSvector3*		pPoints,			/* 頂点データ配列			*/
	GSuint			numWeights,			/* 頂点ウェイト数			*/
	GSfloat**		ppWeights,			/* 頂点ウェイト				*/
	GSuint*			pBoneIndices,		/* ボーンインデックス		*/
	const GSmatrix4* pMatrices			/* 変換行列					*/
)
{
	GSvector3		tmpPoint;
	GSfloat			fWeight;
	GSuint			m;
	GSuint			i;
	GSuint			j;

	for ( i = 0; i < numPoints; i++ )
	{
		/* 計算結果用頂点データを初期化 */
		gsVector3Init( &pOutPoints[i], 0.0f, 0.0f, 0.0f );

		/* ウェイト値の初期化*/
		fWeight = 0.0f;

		/* 頂点座標の座標変換を行う */
		for ( j = 0; j < numWeights; j++ )
		{
			/* マトリクスインデックスを取り出す */
			m = ( pBoneIndices[i] >> ( j * 8 ) ) & 0xff;

			/* 頂点座標を座標変換 */
			gsVector3Transform( &tmpPoint, &pPoints[i], &pMatrices[m] );

			/* 頂点座標にウェイトの計算をする */
			gsVector3Scale( &tmpPoint, &tmpPoint, ppWeights[j][i] );
			gsVector3Add( &pOutPoints[i], &pOutPoints[i], &tmpPoint );

			fWeight += ppWeights[j][i];
		}

		/* マトリクスインデックスを取り出す */
		m = ( pBoneIndices[i] >> ( j * 8 ) ) & 0xff;

		/* 頂点座標を座標変換 */
		gsVector3Transform( &tmpPoint, &pPoints[i], &pMatrices[m] );

		/* 頂点座標にウェイトの計算をする */
		gsVector3Scale( &tmpPoint, &tmpPoint, ( 1.0f - fWeight ) );
		gsVector3Add( &pOutPoints[i], &pOutPoints[i], &tmpPoint );
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : 法線ベクトルの座標変換．
*
* Return  : なし．
*
*----------------------------------------------------------------------------*/
static void
TransformNormals
(
	GSvector3*		pOutNormals,		/*-> 計算後法線ベクトル配列	*/
	GSuint			numNormals,			/* 法線ベクトルデータ数		*/
	GSvector3*		pNormals,			/* 法線ベクトル配列			*/
	GSuint			numWeights,			/* 頂点ウェイト数			*/
	GSfloat**		ppWeights,			/* 頂点ウェイト				*/
	GSuint*			pBoneIndices,		/* ボーンインデックス		*/
	const GSmatrix4* pMatrices			/* 変換行列					*/
)
{
	GSvector3		tmpNormal;
	GSfloat			fWeight;
	GSuint			m;
	GSuint			i;
	GSuint			j;

	for ( i = 0; i < numNormals; i++ )
	{
		/* 計算結果用法線ベクトルデータを初期化 */
		gsVector3Init( &pOutNormals[i], 0.0f, 0.0f, 0.0f );

		/* ウェイト値の初期化*/
		fWeight = 0.0f;

		/* 法線ベクトルの座標変換を行う */
		for ( j = 0; j < numWeights; j++ )
		{
			/* マトリクスインデックスを取り出す */
			m = ( pBoneIndices[i] >> ( j * 8 ) ) & 0xff;

			/* 法線ベクトルを座標変換 */
			gsVector3TransformNormal( &tmpNormal, &pNormals[i], &pMatrices[m] );

			/* 法線ベクトルにウェイトの計算をする */
			gsVector3Scale( &tmpNormal, &tmpNormal, ppWeights[j][i] );
			gsVector3Add( &pOutNormals[i], &pOutNormals[i], &tmpNormal );

			fWeight += ppWeights[j][i];
		}

		/* マトリクスインデックスを取り出す */
		m = ( pBoneIndices[i] >> ( j * 8 ) ) & 0xff;

		/* 法線ベクトルを座標変換 */
		gsVector3TransformNormal( &tmpNormal, &pNormals[i], &pMatrices[m] );

		/* 法線ベクトルにウェイトの計算をする */
		gsVector3Scale( &tmpNormal, &tmpNormal, ( 1.0f - fWeight ) );
		gsVector3Add( &pOutNormals[i], &pOutNormals[i], &tmpNormal );

		/* 法線ベクトルを正規化する */
		gsVector3Normalize( &pOutNormals[i], &pOutNormals[i] );
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : メッシュの平面パラメータの計算をする．
*
* Return  : なし．
*
*----------------------------------------------------------------------------*/
static void
CalculatePlanes
(
	GSmesh*			pMesh				/* メッシュ					*/
)
{
	GSuint			i;

	/* 既にプレーンが生成されている場合は消滅させる */
	if ( pMesh->pPlanes != NULL )
	{
		del_object( pMesh->pPlanes );
	}

	/* 平面パラメータの配列を生成する */
	pMesh->pPlanes = new_object( sizeof(GSplane) * ( pMesh->numIndices / 3 ) );

	/* 全ポリゴンとレイの衝突判定を行う */
	for ( i = 0; i < ( pMesh->numIndices / 3 ); i++ )
	{
		/* ポリゴンの３頂点を取得する */
		gsPlaneFromPoints(
			&pMesh->pPlanes[i],
			&pMesh->pPoints[ pMesh->pIndices[i*3+0] ],
			&pMesh->pPoints[ pMesh->pIndices[i*3+1] ],
			&pMesh->pPoints[ pMesh->pIndices[i*3+2] ]
		);
	}
}

/********** End of File ******************************************************/
