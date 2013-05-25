/******************************************************************************
* File Name : GSmesh.h                           Ver : 1.00  Date : 2002-08-03
*
* Description :
*
*		メッシュデータ ヘッダファイル．．
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSMESH_H_
#define		_GSMESH_H_

#include	"GStype.h"
#include	"GStexture.h"

/****** 定数宣言 *************************************************************/

#define	GS_MATERIAL_TEXTURE		( 1	<< 0  )	/* テクスチャフラグ			*/
#define	GS_MATERIAL_SPHERE_MAP	( 1	<< 31 )	/* 球形環境マッピング		*/
#define	GS_MATERIAL_TEX_CLAMP	( 1	<< 30 )	/* テクスチャをクランプ		*/

/****** データ型宣言 *********************************************************/

/*----- マテリアル情報構造体 ------------------------------------------------*/

typedef	struct							/* マテリアル構造体			*/
{
	GSbitfield		MaterialInfo;		/* マテリアル情報フラグ		*/
	GScolor			Diffuse;			/* 拡散光カラー				*/
	GScolor			Ambient;			/* 環境光カラー				*/
	GScolor			Specular;			/* 鏡面反射光カラー			*/
	GScolor			Emissive;			/* 放射光カラー				*/
	GSfloat			Power;				/* ハイライトの鮮明度		*/
	GStexture*		pTexture;			/* テクスチャ				*/

} GSmaterial;

/*----- 面データグループ構造体 ---------------------------------------------*/

typedef	struct							/* 面データグループ型		*/
{
	GSbitfield		FaceInfo;			/* 面情報フラグ				*/
	GSuint			MaterialNo;			/* マテリアルナンバ			*/
	GSuint			numIndices;			/* 頂点インデックス数		*/
	GSuint			StartIndices;		/* 頂点インデックス開始位置	*/

} GSfacegroup;

/*----- メッシュ構造体 -----------------------------------------------------*/

typedef	struct							/* メッシュ型				*/
{
	GSbitfield		MeshInfo;			/* メッシュ情報				*/
	GSuint			numMaterials;		/* マテリアルデータ数		*/
	GSuint			numFaceGroups;		/* レンダリング面情報数		*/
	GSuint			numIndices;			/* 頂点インデックス数		*/
	GSuint			numVertices;		/* 頂点データ数 			*/
	GSuint			numTexCoords;		/* テクスチャ座標数			*/
	GSuint			numWeights;			/* 頂点ウェイト数			*/
	GSmaterial*		pMaterials;			/* マテリアルデータ配列		*/
	GSfacegroup*	pFaceGroups;		/* レンダリング面情報		*/
	GSushort*		pIndices;			/* 頂点インデックス			*/
	GSvector3*		pPoints;			/* 頂点座標配列				*/
	GSvector3*		pNormals;			/* 法線ベクトル配列			*/
	GScolor*		pDiffuseColors;		/* 拡散光カラー配列			*/
	GScolor*		pSpecularColors;	/* 鏡面反射光カラー配列		*/
	GSvector2**		ppTexCoords;		/* テクスチャ座標配列		*/
	GSfloat**		ppWeights;			/* 頂点ウェイト配列			*/
	GSuint*			pBoneIndices;		/* ボーンインデックス配列	*/
	GSplane*		pPlanes;			/* 平面データ配列			*/
	GSvector3		Center;				/* メッシュの境界球の中心	*/
	GSfloat			fRadius;			/* メッシュの境界球の半径	*/

} GSmesh;

/****** 関数プロトタイプ宣言 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/****** 関数プロトタイプ宣言 *************************************************/

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
);

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
);

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
);

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
);

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
);

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
);

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
);

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
);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
