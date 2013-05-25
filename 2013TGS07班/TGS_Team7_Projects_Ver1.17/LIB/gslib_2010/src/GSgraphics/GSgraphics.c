/******************************************************************************
* File Name : GSgraphics.c                       Ver : 1.00  Date : 2002-07-31
*
* Description :
*
*       ゲームシステム用 グラフィックス処理．
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GSgraphics.h"
#include	"GSvector3.h"
#include	"GSmatrix4.h"
#include	"GSquaternion.h"
#include	"GScolor.h"
#include	<stddef.h>
#include	<GL/glu.h>

/****** 定数宣言 *************************************************************/

#define	GS_MESH_MAX			1024	/* メッシュデータの最大数		*/
#define	GS_SKELETON_MAX		1024	/* スケルトンデータの最大数		*/
#define	GS_ANIMATION_MAX	1024	/* アニメーションデータの最大数	*/
#define	GS_TEXTURE_MAX		1024	/* テクスチャデータの最大数		*/
#define	GS_OCTREE_MAX		1024	/* オクツリーデータの最大数		*/

#define	GS_MATRIX_MAX		256		/* 変換行列の最大数				*/

/****** 関数プロトタイプ宣言 *************************************************/

/* メッシュ，スケルトン，アニメーション,テクスチャデータ */
static GSmesh*		s_pMeshs[ GS_MESH_MAX ];
static GSskeleton*	s_pSkeletons[ GS_SKELETON_MAX ];
static GSanimation*	s_pAnimations[ GS_ANIMATION_MAX ];
static GStexture*	s_pTextures[ GS_TEXTURE_MAX ];
static GSoctree*	s_pOctrees[ GS_OCTREE_MAX ];

/* セルシェーディング用パラメータ */
static GSvector3	s_CelShadeLightPosition = { 1.0f, 1.0f, 1.0f };
static GSfloat		s_CelShadeLineWidth     = 1.5f;
static GSuint		s_CelShadeTexture       = 0;
static GScolor		s_CelShadeLineColor		= { 0.0f, 0.0f, 0.0f, 1.0f };

/* テクスチャのカラーキーのモード */
static GSenum		s_TexColorKeyMode = GS_TEXCOLOR_KEY_DISABLE;
static GSbyte		s_TexColorKeyR = 0;
static GSbyte		s_TexColorKeyG = 0;
static GSbyte		s_TexColorKeyB = 0;

/* バインド中のスケルトンナンバ */
static GSuint		s_BindSkeleton = 0;

/* アニメーション変換行列 */
static GSmatrix4	s_AnimationMatrices[ GS_MATRIX_MAX ];

/* 姿勢変換行列 */
static GSmatrix4	s_OrientationMatrices[ GS_MATRIX_MAX ];

/* 座標変換行列 */
static GSmatrix4	s_TransformMatrices[ GS_MATRIX_MAX ];

/* 各種状態フラグ */
static GSboolean	s_bSkinMesh          = GS_TRUE;
static GSboolean	s_bCalculateSkeleton = GS_TRUE;
static GSboolean	s_bCelShade          = GS_FALSE;

/* 文字フォント情報 */
static GSbitfield	s_FontCode     = GS_FONT_NORMAL;
static GSuint		s_FontPoint    = 10;
static char			s_FontName[32] = "ＭＳ ゴシック";

/* テキストの表示位置 */
static GSvector2	s_TextPosition = { 0.0f, 0.0f };

/*=============================================================================
*
* Purpose : グラフィックシステムの初期化．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsInitGraphics
(
	void
)
{
	GSuint		i;

	/* 各種リソースの初期化 */
	for ( i = 0; i < GS_MESH_MAX; i++ )
	{
		gsDeleteMesh( i );
	}
	for ( i = 0; i < GS_SKELETON_MAX; i++ )
	{
		gsDeleteSkeleton( i );
	}
	for ( i = 0; i < GS_ANIMATION_MAX; i++ )
	{
		gsDeleteAnimation( i );
	}
	for ( i = 0; i < GS_TEXTURE_MAX; i++ )
	{
		gsDeleteTexture( i );
	}
	for ( i = 0; i < GS_OCTREE_MAX; i++ )
	{
		gsDeleteOctree( i );
	}

	/* セルシェードパラメータの初期化 */
	gsVector3Init( &s_CelShadeLightPosition, 1.0f, 1.0f, 1.0f );
	s_CelShadeLineWidth = 1.5f;
	s_CelShadeTexture   = 0;
	gsColorInit( &s_CelShadeLineColor, 0.0f, 0.0f, 0.0f, 1.0f );

	/* テクスチャのカラーキーの初期化 */
	s_TexColorKeyMode = GS_TEXCOLOR_KEY_DISABLE;
	s_TexColorKeyR    = 0;
	s_TexColorKeyG    = 0;
	s_TexColorKeyB    = 0;

	/* バインド中のスケルトンの初期化 */
	s_BindSkeleton = 0;

	/* アニメーション変換行列の初期化 */
	for ( i = 0; i < GS_MATRIX_MAX; i++ )
	{
		gsMatrix4Identity( &s_AnimationMatrices[i] );
	}

	/* 姿勢変換行列の初期化 */
	for ( i = 0; i < GS_MATRIX_MAX; i++ )
	{
		gsMatrix4Identity( &s_OrientationMatrices[i] );
	}

	/* 座標変換行列の初期化 */
	for ( i = 0; i < GS_MATRIX_MAX; i++ )
	{
		gsMatrix4Identity( &s_TransformMatrices[i] );
	}

	/* 文字フォント情報の初期化 */
	s_FontCode  = GS_FONT_NORMAL;
	s_FontPoint = 10;
	strcpy( s_FontName, "ＭＳ ゴシック" );

	/* テキストの表示位置を初期化 */
	s_TextPosition.x = 0.0f;
	s_TextPosition.y = 0.0f;

	/* 各種状態フラグの初期化 */
	s_bSkinMesh          = GS_TRUE;
	s_bCalculateSkeleton = GS_TRUE;
	s_bCelShade          = GS_FALSE;
}

/*=============================================================================
*
* Purpose : グラフィックシステムの終了処理．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsFinishGraphics
(
	void
)
{
	GSuint		i;

	/* 各種リソースの解放を行う */
	for ( i = 0; i < GS_MESH_MAX; i++ )
	{
		gsDeleteMesh( i );
	}
	for ( i = 0; i < GS_SKELETON_MAX; i++ )
	{
		gsDeleteSkeleton( i );
	}
	for ( i = 0; i < GS_ANIMATION_MAX; i++ )
	{
		gsDeleteAnimation( i );
	}
	for ( i = 0; i < GS_TEXTURE_MAX; i++ )
	{
		gsDeleteTexture( i );
	}
	for ( i = 0; i < GS_OCTREE_MAX; i++ )
	{
		gsDeleteOctree( i );
	}
}

/*=============================================================================
*
* Purpose : メッシュデータの読み込み．
*
* Return  : 読み込みに成功すれば真，失敗すれば偽を返す．
*
*============================================================================*/
extern GSboolean
gsLoadMesh
(
	GSuint			MeshID,				/* メッシュＩＤ				*/
	const char*		pszMshFileName		/* メッシュファイル名		*/
)
{
	GSboolean		Result;

	/* メッシュデータが既に存在するか？ */
	if ( s_pMeshs[ MeshID ] == NULL )
	{
		/* メッシュデータの生成 */
		s_pMeshs[ MeshID ] = gsMeshNew();
	}

	/* メッシュデータの読み込み */
	Result = gsMeshLoadFile( s_pMeshs[ MeshID ], pszMshFileName );

	/* 読み込みに失敗した場合は生成したメッシュデータを削除する */
	if ( Result == GS_FALSE )
	{
		gsDeleteMesh( MeshID );
	}

	return	Result;
}

/*=============================================================================
*
* Purpose : スケルトンデータファイルの読み込み．
*
* Return  : 読み込みに成功すれば真，失敗すれば偽を返す．
*
*============================================================================*/
extern GSboolean
gsLoadSkeleton
(
	GSuint			SkeletonID,			/* スケルトンＩＤ			*/
	const char*		pszSklFileName		/* スケルトンファイル名		*/
)
{
	GSboolean		Result;

	/* スケルトンデータが既に存在するか？ */
	if ( s_pSkeletons[ SkeletonID ] == NULL )
	{
		/* スケルトンデータの生成 */
		s_pSkeletons[ SkeletonID ] = gsSkeletonNew();
	}

	/* スケルトンデータの読み込み */
	Result = gsSkeletonLoadFile( s_pSkeletons[ SkeletonID ], pszSklFileName );

	/* 読み込みに失敗した場合は生成したスケルトンデータを削除する */
	if ( Result == GS_FALSE )
	{
		gsDeleteSkeleton( SkeletonID );
	}

	return	Result;
}

/*=============================================================================
*
* Purpose : アニメーションデータファイルの読み込み．
*
* Return  : 読み込みに成功すれば真，失敗すれば偽を返す．
*
*============================================================================*/
extern GSboolean
gsLoadAnimation
(
	GSuint			AnimationID,		/* アニメーションＩＤ		*/
	const char*		pszAnmFileName		/* アニメーションファイル名	*/
)
{
	GSboolean		Result;

	/* アニメーションデータが既に存在するか？ */
	if ( s_pAnimations[ AnimationID ] == NULL )
	{
		/* アニメーションデータの生成 */
		s_pAnimations[ AnimationID ] = gsAnimationNew();
	}

	/* アニメーションデータの読み込み */
	Result = gsAnimationLoadFile( s_pAnimations[ AnimationID ], pszAnmFileName );

	/* 読み込みに失敗した場合は生成したアニメーションデータを削除する */
	if ( Result == GS_FALSE )
	{
		gsDeleteAnimation( AnimationID );
	}

	return	Result;
}

/*=============================================================================
*
* Purpose : テクスチャデータの読み込み．
*
* Return  : 読み込みに成功すれば真，失敗すれば偽を返す．
*
*============================================================================*/
extern GSboolean
gsLoadTexture
(
	GSuint			TextureID,			/* テクスチャＩＤ			*/
	const char*		pszTexFileName		/* テクスチャファイル名		*/
)
{
	GSubyte*		pTexcel;
	GSboolean		Result;

	if ( s_pTextures[ TextureID ] == NULL )
	{
		/* テクスチャデータの生成 */
		s_pTextures[ TextureID ] = gsTextureNew();
	}

	/* テクスチャデータの読み込み */
	Result = gsTextureLoadBmpFile( s_pTextures[ TextureID ], pszTexFileName );

	/* 読み込みに失敗した場合は生成したテクスチャデータを削除する */
	if ( Result == GS_FALSE )
	{
		gsDeleteTexture( TextureID );

		return	GS_FALSE;
	}

	/* カラーキーを設定する */
	switch ( s_TexColorKeyMode )
	{
	case GS_TEXCOLOR_KEY:
		/* カラーキーの設定 */
		gsTextureSetColorKey
		(
			s_pTextures[ TextureID ],
			s_TexColorKeyR,
			s_TexColorKeyG,
			s_TexColorKeyB
		);
		break;

	case GS_TEXCOLOR_KEY_AUTO:
		/* 左上のテクセルを取得する */
		pTexcel = gsTextureLock( s_pTextures[ TextureID ] );

		/* 左上のテクセルをカラーキーとして設定する */
		gsTextureSetColorKey
		(
			s_pTextures[ TextureID ],
			pTexcel[0], pTexcel[1], pTexcel[2]
		);
		break;

	case GS_TEXCOLOR_KEY_BLACK:
		/* 黒をカラーキーとして設定する */
		gsTextureSetColorKey( s_pTextures[ TextureID ], 0, 0, 0 );
		break;

	case GS_TEXCOLOR_KEY_WHITE:
		/* 白をカラーキーとして設定する */
		gsTextureSetColorKey( s_pTextures[ TextureID ], 0xff, 0xff, 0xff );
		break;
	}

	return	Result;
}

/*=============================================================================
*
* Purpose : オクツリーデータの読み込み．
*
* Return  : 読み込みに成功すれば真，失敗すれば偽を返す．
*
*============================================================================*/
extern GSboolean
gsLoadOctree
(
	GSuint			OctreeID,			/* オクツリーＩＤ			*/
	const char*		pszOctFileName		/* オクツリーファイル名		*/
)
{
	GSboolean		Result;

	/* オクツリーデータが既に存在するか？ */
	if ( s_pOctrees[ OctreeID ] == NULL )
	{
		/* オクツリーデータの生成 */
		s_pOctrees[ OctreeID ] = gsOctreeNew();
	}

	/* オクツリーデータの読み込み */
	Result = gsOctreeLoadFile( s_pOctrees[ OctreeID ], pszOctFileName );

	/* 読み込みに失敗した場合は生成したオクツリーデータを削除する */
	if ( Result == GS_FALSE )
	{
		gsDeleteOctree( OctreeID );
	}

	return	Result;
}

/*=============================================================================
*
* Purpose : テクスチャデータの透明色の指定．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsTextureColorKey
(
	GSubyte			ColorKeyR,			/* 赤成分					*/
	GSubyte			ColorKeyG,			/* 青成分					*/
	GSubyte			ColorKeyB			/* 緑成分					*/
)
{
	/* 透明色の設定をする */
	s_TexColorKeyR = ColorKeyR;
	s_TexColorKeyG = ColorKeyG;
	s_TexColorKeyB = ColorKeyB;
}

/*=============================================================================
*
* Purpose : テクスチャデータの透明色モードの指定．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsTextureColorKeyMode
(
	GSenum			ColorKeyMode		/* カラーキーモード			*/
)
{
	/* 透明色の選択方法の設定 */
	s_TexColorKeyMode = ColorKeyMode;
}

/*=============================================================================
*
* Purpose : メッシュデータの削除．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsDeleteMesh
(
	GSuint			MeshID				/* メッシュＩＤ				*/
)
{
	if ( s_pMeshs[ MeshID ] != NULL )
	{
		/* メッシュデータを消滅させる */
		gsMeshDelete( s_pMeshs[ MeshID ] );

		s_pMeshs[ MeshID ] = NULL;
	}
}

/*=============================================================================
*
* Purpose : スケルトンデータの削除．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsDeleteSkeleton
(
	GSuint			SkeletonID			/* スケルトンＩＤ			*/
)
{
	if ( s_pSkeletons[ SkeletonID ] != NULL )
	{
		/* スケルトンデータを消滅させる */
		gsSkeletonDelete( s_pSkeletons[ SkeletonID ] );

		s_pSkeletons[ SkeletonID ] = NULL;
	}
}

/*=============================================================================
*
* Purpose : アニメーションデータファイルの削除．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsDeleteAnimation
(
	GSuint			AnimationID			/* アニメーションＩＤ		*/
)
{
	if ( s_pAnimations[ AnimationID ] != NULL )
	{
		/* アニメーションデータを消滅させる */
		gsAnimationDelete( s_pAnimations[ AnimationID ] );

		s_pAnimations[ AnimationID ] = NULL;
	}
}

/*=============================================================================
*
* Purpose : テクスチャデータファイルの削除．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsDeleteTexture
(
	GSuint			TextureID			/* テクスチャＩＤ		*/
)
{
	if ( s_pTextures[ TextureID ] != NULL )
	{
		/* アニメーションデータを消滅させる */
		gsTextureDelete( s_pTextures[ TextureID ] );

		s_pTextures[ TextureID ] = NULL;
	}
}

/*=============================================================================
*
* Purpose : オクツリーデータの削除．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsDeleteOctree
(
	GSuint			OctreeID				/* オクツリーＩＤ		*/
)
{
	if ( s_pOctrees[ OctreeID ] != NULL )
	{
		/* オクツリーデータを消滅させる */
		gsOctreeDelete( s_pOctrees[ OctreeID ] );

		s_pOctrees[ OctreeID ] = NULL;
	}
}

/*=============================================================================
*
* Purpose : メッシュの描画．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsDrawMesh
(
	GSuint			MeshID				/* メッシュＩＤ				*/
)
{
	GSskeleton*		pSkeleton;
	GSmesh*			pMesh;

	/* メッシュデータを取得する */
	if ( ( pMesh = s_pMeshs[ MeshID ] ) == NULL )
	{
		return;
	}

	/* バインド中のスケルトンの取得 */
	pSkeleton = s_pSkeletons[ s_BindSkeleton ];

	/* スキニングメッシュを描画するか？ */
	if ( s_bSkinMesh == GS_TRUE && pSkeleton != NULL )
	{
		/* スケルトンの自動計算が設定されているか？ */
		if ( s_bCalculateSkeleton == TRUE )
		{
			/* 姿勢変換行列の計算を行う */
			gsCalculateSkeleton( NULL, s_OrientationMatrices );
		}

		/* 最終的な座標変換行列を計算する */
		gsSkeletonCalculateTransform
		(
			pSkeleton,
			s_TransformMatrices,
			s_OrientationMatrices
		);

		/* セルシェーディングを行うか？ */
		if ( s_bCelShade == GS_TRUE )
		{
			/* セルシェーディングを使って描画する */
			gsMeshDrawSkinCelShade
			(
				pMesh,
				s_TransformMatrices,
				s_pTextures[ s_CelShadeTexture ],
				&s_CelShadeLightPosition,
				&s_CelShadeLineColor,
				s_CelShadeLineWidth
			);
		}
		else
		{
			/* メッシュを描画する */
			gsMeshDrawSkin( pMesh, s_TransformMatrices );
		}
	}
	else
	{
		/* セルシェーディングを行うか？ */
		if ( s_bCelShade == GS_TRUE )
		{
			/* セルシェーディングを使ってメッシュを描画する */
			gsMeshDrawCelShade
			(
				pMesh,
				s_pTextures[ s_CelShadeTexture ],
				&s_CelShadeLightPosition,
				&s_CelShadeLineColor,
				s_CelShadeLineWidth
			);
		}
		else
		{
			/* メッシュを描画する */
			gsMeshDraw( pMesh );
		}
	}
}

/*=============================================================================
*
* Purpose : オクツリーの描画．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsDrawOctree
(
	GSuint			OctreeID				/* オクツリーＩＤ				*/
)
{
	GSoctree*		pOctree;

	/* オクツリーデータを取得する */
	if ( ( pOctree = s_pOctrees[ OctreeID ] ) == NULL )
	{
		return;
	}

	/* オクツリーの描画 */
	gsOctreeDraw( pOctree );
}

/*=============================================================================
*
* Purpose : テクスチャをバインドする．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsBindTexture
(
	GSuint			TextureID			/* テクスチャＩＤ			*/
)
{
	GStexture*		pTexture;

	if ( ( pTexture = s_pTextures[ TextureID ] ) == NULL )
	{
		return;
	}

	/* テクスチャをバインドする */
	gsTextureBind( s_pTextures[ TextureID ] );

	/* テクスチャを有効にする */
	glEnable( GL_TEXTURE_2D );
}

/*=============================================================================
*
* Purpose : スケルトンをバインドする．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsBindSkeleton
(
	GSuint			SkeletonID			/* スケルトンＩＤ			*/
)
{
	/* スケルトンをバインドする */
	s_BindSkeleton = SkeletonID;
}

/*=============================================================================
*
* Purpose : アニメーションをバインドする．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsBindAnimation
(
	GSuint			AnimationID,		/* アニメーションＩＤ		*/
	GSuint			AnimationNo,		/* アニメーションナンバ		*/
	GSfloat			fTimer				/* アニメーションタイマ		*/
)
{
	GSanimation*	pAnimation;
	GSuint			numBones;
	GSuint			BoneNo;
	GSvector3		Scale;
	GSquaternion	Rotate;
	GSvector3		Position;
	GSmatrix4		matScale;
	GSmatrix4		matRotate;

	/* アニメーションデータが存在するか？ */
	if ( ( pAnimation = s_pAnimations[ AnimationID ] ) == NULL )
	{
		/* アニメーションが取得できなかった場合は全て単位行列を設定する */
		for ( BoneNo = 0; BoneNo < GS_MATRIX_MAX; BoneNo++ )
		{
			gsMatrix4Identity( &s_AnimationMatrices[ BoneNo ] );

		}
		return;
	}

	/* ボーンデータ数を取得する */
	numBones = gsAnimationGetNumBones( pAnimation, AnimationNo );

	/* アニメーション変換行列に設定する */
	for ( BoneNo = 0; BoneNo < numBones; BoneNo++ )
	{
		/* キーフレームデータを取得する */
		gsAnimationGetKeyFrame
		(
			pAnimation,
			AnimationNo, BoneNo, fTimer,
			&Scale, &Rotate, &Position
		);

		/* 各キーを行列に変換する */
		gsMatrix4Scale( &matScale, Scale.x, Scale.y, Scale.z );
		gsMatrix4Quaternion( &matRotate, &Rotate );
		gsMatrix4Multiply
		(
			&s_AnimationMatrices[ BoneNo ], &matScale, &matRotate
		);
		s_AnimationMatrices[ BoneNo ].m[3][0] = Position.x;
		s_AnimationMatrices[ BoneNo ].m[3][1] = Position.y;
		s_AnimationMatrices[ BoneNo ].m[3][2] = Position.z;
	}
}

/*=============================================================================
*
* Purpose : アニメーションをバインドする．（ 線形補間 ）
*
* Return  : なし．
*
*============================================================================*/
extern void
gsBindAnimationLerp
(
	GSuint			AnimationID1,		/* アニメーションＩＤ		*/
	GSuint			AnimationNo1,		/* アニメーションナンバ		*/
	GSfloat			fTimer1,			/* アニメーションタイマ		*/
	GSuint			AnimationID2,		/* アニメーションＩＤ		*/
	GSuint			AnimationNo2,		/* アニメーションナンバ		*/
	GSfloat			fTimer2,			/* アニメーションタイマ		*/
	GSfloat			fLerp				/* 補間値					*/
)
{
	GSanimation*	pAnimation1;
	GSanimation*	pAnimation2;
	GSuint			numBones;
	GSuint			BoneNo;
	GSvector3		Scale;
	GSquaternion	Rotate;
	GSvector3		Position;
	GSvector3		Scale1;
	GSquaternion	Rotate1;
	GSvector3		Position1;
	GSvector3		Scale2;
	GSquaternion	Rotate2;
	GSvector3		Position2;
	GSmatrix4		matScale;
	GSmatrix4		matRotate;

	/* ２つのアニメーションデータを取得する */
	if ( ( pAnimation1 = s_pAnimations[ AnimationID1 ] ) == NULL )
	{
		return;
	}
	if ( ( pAnimation2 = s_pAnimations[ AnimationID2 ] ) == NULL )
	{
		/* 補間先がない場合はアニメーション１のみバインド */
		gsBindAnimation( AnimationID1, AnimationNo1, fTimer1 );

		return;
	}

	/* ボーンデータ数を取得する */
	numBones = gsAnimationGetNumBones( pAnimation1, AnimationNo1 );

	/* アニメーション変換行列に設定する */
	for ( BoneNo = 0; BoneNo < numBones; BoneNo++ )
	{
		/* キーフレームデータを取得する */
		gsAnimationGetKeyFrame
		(
			pAnimation1,
			AnimationNo1, BoneNo, fTimer1,
			&Scale1, &Rotate1, &Position1
		);
		/* キーフレームデータを取得する */
		gsAnimationGetKeyFrame
		(
			pAnimation2,
			AnimationNo2, BoneNo, fTimer2,
			&Scale2, &Rotate2, &Position2
		);

		/* 各キーを線形補間する */
		gsVector3Lerp( &Scale, &Scale1, &Scale2, fLerp );
		gsQuaternionSlerp( &Rotate, &Rotate1, &Rotate2, fLerp );
		gsVector3Lerp( &Position, &Position1, &Position2, fLerp );

		/* 各キーを行列に変換する */
		gsMatrix4Scale( &matScale, Scale.x, Scale.y, Scale.z );
		gsMatrix4Quaternion( &matRotate, &Rotate );
		gsMatrix4Multiply
		(
			&s_AnimationMatrices[ BoneNo ], &matScale, &matRotate
		);
		s_AnimationMatrices[ BoneNo ].m[3][0] = Position.x;
		s_AnimationMatrices[ BoneNo ].m[3][1] = Position.y;
		s_AnimationMatrices[ BoneNo ].m[3][2] = Position.z;
	}
}

/*=============================================================================
*
* Purpose : セルシェーディング用テクスチャをバインドする．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsBindCelShadeTexture
(
	GSuint			TextureID			/* テクチャＩＤ				*/
)
{
	/* セルシェーディング用テクスチャのバインド */
	s_CelShadeTexture = TextureID;
}

/*=============================================================================
*
* Purpose : セルシェーディング用ライトの設定をする．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsLightPositionCelShade
(
	GSfloat			LightPositionX,		/* ライトｘ座標 			*/
	GSfloat			LightPositionY,		/* ライトｙ座標 			*/
	GSfloat			LightPositionZ		/* ライトｚ座標 			*/
)
{
	s_CelShadeLightPosition.x = LightPositionX;
	s_CelShadeLightPosition.y = LightPositionY;
	s_CelShadeLightPosition.z = LightPositionZ;
}

/*=============================================================================
*
* Purpose : セルシェーディングの輪郭線の太さを設定する．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsLineWidthCelShade
(
	GSfloat			LineWidth			/* 輪郭線の太さ				*/
)
{
	s_CelShadeLineWidth = LineWidth;
}

/*=============================================================================
*
* Purpose : セルシェーディングの輪郭線のカラーを設定する．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsLineColorCelShade
(
	GSfloat			LineColorR,			/* 輪郭線の色の赤成分		*/
	GSfloat			LineColorG,			/* 輪郭線の色の緑成分		*/
	GSfloat			LineColorB,			/* 輪郭線の色の青成分		*/
	GSfloat			LineColorA			/* 輪郭線のアルファ成分		*/
)
{
	s_CelShadeLineColor.r = LineColorR;
	s_CelShadeLineColor.g = LineColorG;
	s_CelShadeLineColor.b = LineColorB;
	s_CelShadeLineColor.a = LineColorA;
}

/*=============================================================================
*
* Purpose : スケルトンデータの姿勢変換行列を計算する．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsCalculateSkeleton
(
	GSmatrix4*		pParentMatrix,		/* 親のモデリング変換行列	*/
	GSmatrix4*		pOrientMatrices		/*-> 姿勢変換行列配列		*/
)
{
	GSskeleton*		pSkeleton;

	/* スケルトンデータを取得する*/
	if ( ( pSkeleton = s_pSkeletons[ s_BindSkeleton ] ) != NULL )
	{
		/* スケルトンデータから姿勢変換行列を計算する */
		gsSkeletonCalculateOrientation
		(
			pSkeleton,
			pOrientMatrices,
			pParentMatrix,
			s_AnimationMatrices
		);
	}
}

/*=============================================================================
*
* Purpose : スケルトンの姿勢変換行列を設定する．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsSetMatrixOrientation
(
	GSuint			numMatrices,		/* 座標変換行列数			*/
	GSmatrix4*		pOrientMatrices		/* 座標変換行列配列			*/
)
{
	GSuint			i;

	/* 変換行列の設定をする */
	for ( i = 0; i < numMatrices; i++ )
	{
		s_OrientationMatrices[i] = pOrientMatrices[i];
	}
}

/*=============================================================================
*
* Purpose : スケルトンデータのボーン数を取得する．
*
* Return  : なし．
*
*============================================================================*/
extern GSuint
gsGetSkeletonNumBones
(
	GSuint		SkeletonID				/* スケルトンのＩＤ 		*/
)
{
	GSskeleton*	pSkeleton;

	if ( ( pSkeleton = s_pSkeletons[ SkeletonID ] ) == NULL )
	{
		return	0;
	}

	/* スケルトンデータからボーン数を取得する */
	return	gsSkeletonGetNumBones( pSkeleton );
}

/*=============================================================================
*
* Purpose : アニメーションの終了タイマを取得する．
*
* Return  : なし．
*
*============================================================================*/
extern GSuint
gsGetEndAnimationTimer
(
	GSuint		AnimationID,			/* アニメーションのＩＤ		*/
	GSuint		AnimationNo				/* アニメーションナンバ		*/
)
{
	GSanimation*	pAnimation;

	if ( ( pAnimation = s_pAnimations[ AnimationID ] ) == NULL )
	{
		return	0;
	}

	/* アニメーションデータからアニメーションの終了タイマを取得 */
	return	gsAnimationGetEndTimer( pAnimation, AnimationNo );
}

/*=============================================================================
*
* Purpose : 文字フォントのパラメータを設定する．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsTextPos
(
	GSfloat		PositoinX,		/* ｘ座標					*/
	GSfloat		PositoinY		/* ｙ座標					*/
)
{
	s_TextPosition.x = PositoinX;
	s_TextPosition.y = PositoinY;
}

/*=============================================================================
*
* Purpose : 文字フォントのパラメータを設定する．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsFontParameter
(
	GSbitfield	FontCode,		/* 文字フォントの属性		*/
	GSuint		FontPoint,		/* 文字フォントのポイント数	*/
	const char*	pszFontName		/* 文字フォント名			*/
)
{
	/* 文字フォントの属性を設定 */
	s_FontCode = FontCode;

	/* 文字フォントのポイント数を設定 */
	s_FontPoint = FontPoint;

	/* 文字フォント名の設定 */
	strcpy( s_FontName, pszFontName );
}

/*=============================================================================
*
* Purpose : テキスト描画．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsDrawText
(
	const char*	pString,			/* 表示する文字列		*/
	...								/* オプションの引数		*/
)
{
	char		String[512];		/* 表示文字列バッファ	*/
	GLint		ViewPort[4];
	va_list		ArgList;

	/* 可変長引数の使用開始 */
	va_start( ArgList, pString );

	/* 文字列のフォーマット変換を行う */
	vsprintf( String, pString, ArgList );

	/* 可変数引数の使用終了 */
	va_end( ArgList );

	/* 各種設定フラグの退避 */
	glPushAttrib( GL_ENABLE_BIT );

	/* ライティングを無効にする */
	glDisable( GL_LIGHTING );

	/* ｚバッファを無効にする */
	glDisable( GL_DEPTH_TEST );

	/* 面カリングを無効にする */
	glDisable( GL_CULL_FACE );

	/* 透視変換行列の退避 */
	glMatrixMode( GL_PROJECTION );
	glPushMatrix();

	/* ビューポートの取得 */
	glGetIntegerv( GL_VIEWPORT, ViewPort );

	/* 透視変換行列の設定 */
	glLoadIdentity();
	gluOrtho2D( 0, ViewPort[2], ViewPort[3], 0 );

	/* モデルビュー変換行列の退避 */
	glMatrixMode( GL_MODELVIEW );
	glPushMatrix();

	/* 変換行列の初期化 */
	glLoadIdentity();

	/* テキストの位置を設定する */
	glRasterPos2f( s_TextPosition.x, s_TextPosition.y );

	/* テキストを描画する */
	gsTextDraw
	(
		s_FontCode,			/* フォントコード		*/
		s_FontPoint,		/* フォントのポイント数	*/
		s_FontName,			/* フォント名			*/
		String				/* 文字列				*/
	);

	/* モデルビュー変換行列を復帰 */
	glPopMatrix();

	/* 透視変換行列を復帰 */
	glMatrixMode( GL_PROJECTION );
	glPopMatrix();

	/* モデルビュー変換行列に設定 */
	glMatrixMode( GL_MODELVIEW );

	/* 各種設定フラグの復帰 */
	glPopAttrib();
}

/*=============================================================================
*
* Purpose : スクリーン座標からレイを計算する．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsCalculateRay
(
	GSint		ScreenX,				/* スクリーンｘ座標		*/
	GSint		ScreenY,				/* スクリーンｙ座標		*/
	GSfloat*	pRayPosX,				/*-> レイのｘ座標		*/
	GSfloat*	pRayPosY,				/*-> レイのｙ座標		*/
	GSfloat*	pRayPosZ,				/*-> レイのｙ座標		*/
	GSfloat*	pRayDirX,				/*-> レイのベクトル		*/
	GSfloat*	pRayDirY,				/*-> レイのベクトル		*/
	GSfloat*	pRayDirZ				/*-> レイのベクトル		*/
)
{
	GSvector3	Pos;
	GSvector3	Dir;
	GSvector2	Window;
	GSmatrix4	matProj;
	GSmatrix4	matView;
	GLint		ViewPort[4];

	/* ビューポートの取得 */
	glGetIntegerv( GL_VIEWPORT, ViewPort );

	/* 透視変換行列の取得 */
	glGetFloatv( GL_PROJECTION_MATRIX, (GLfloat*)&matProj );

	/* 視点変換行列の取得 */
	glGetFloatv( GL_MODELVIEW_MATRIX, (GLfloat*)&matView );

	/* マウスカーソルの座標をウィンドウ座標に変換 */
	Window.x = (GSfloat)ScreenX;
	Window.y = ViewPort[3] - (GSfloat)ScreenY;

	/* ビューポート変換の逆変換を行う */
	Pos.x = ( ( ( Window.x - ViewPort[0] ) * 2.0f / ViewPort[2] ) - 1.0f );
	Pos.y = ( ( ( Window.y - ViewPort[1] ) * 2.0f / ViewPort[3] ) - 1.0f );

	/* 透視変換の逆変換を行う */
	Pos.x /= matProj.m[0][0];
	Pos.y /= matProj.m[1][1];
	Pos.z = -1.0f;

	/* 視野変換行列の逆行列を求める */
	gsMatrix4InverseFast( &matView, &matView );

	/* 視野変換の逆変換を行う */
	gsVector3TransformNormal( &Dir, &Pos, &matView );

	/* レイの位置を設定 */
	*pRayPosX = matView.m[3][0];
	*pRayPosY = matView.m[3][1];
	*pRayPosZ = matView.m[3][2];

	/* レイの方向を正規化する */
	gsVector3Normalize( &Dir, &Dir );

	/* レイの方向を設定する */
	*pRayDirX = Dir.x;
	*pRayDirY = Dir.y;
	*pRayDirZ = Dir.z;
}

/*=============================================================================
*
* Purpose : メッシュデータの取得．
*
* Return  : メッシュデータのポインタを返す．
*
*============================================================================*/
extern GSmesh*
gsGetMesh
(
	GSuint			MeshID				/* メッシュＩＤ				*/
)
{
	return	s_pMeshs[ MeshID ];
}

/*=============================================================================
*
* Purpose : スケルトンデータの取得．
*
* Return  : スケルトンデータのポインタを返す．
*
*============================================================================*/
extern GSskeleton*
gsGetSkeleton
(
	GSuint			SkeletonID			/* スケルトンＩＤ			*/
)
{
	return	s_pSkeletons[ SkeletonID ];
}

/*=============================================================================
*
* Purpose : アニメショーンデータの取得．
*
* Return  : アニメーションデータのポインタを返す．
*
*============================================================================*/
extern GSanimation*
gsGetAnimation
(
	GSuint			AnimationID			/* アニメーションＩＤ		*/
)
{
	return	s_pAnimations[ AnimationID ];
}

/*=============================================================================
*
* Purpose : オクツリーデータの取得．
*
* Return  : オクツリーデータのポインタを返す．
*
*============================================================================*/
extern GSoctree*
gsGetOctree
(
	GSuint			OctreeID			/* オクツリーＩＤ		*/
)
{
	return	s_pOctrees[ OctreeID ];
}

/*=============================================================================
*
* Purpose : テクスチャデータの取得．
*
* Return  : テクスチャデータのポインタを返す．
*
*============================================================================*/
extern GStexture*
gsGetTexture
(
	GSuint			TextureID			/* テクスチャＩＤ		*/
)
{
	return	s_pTextures[ TextureID ];
}

/*=============================================================================
*
* Purpose : 特定機能の有効化．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsEnable
(
	GSenum		Cap					/* 特定機能を示すシンボル定数 */
)
{
	switch( Cap )
	{
	case GS_SKIN_MESH:
		s_bSkinMesh = GS_TRUE;
		break;

	case GS_CALC_SKELETON:
		s_bCalculateSkeleton = GS_TRUE;
		break;

	case GS_CEL_SHADE:
		s_bCelShade = GS_TRUE;
		break;
	}
}

/*=============================================================================
*
* Purpose : 特定機能の無効化．
*
* Return  : なし．
*
*============================================================================*/
extern void
gsDisable
(
	GSenum		Cap					/* 特定機能を示すシンボル定数 */
)
{
	switch( Cap )
	{
	case GS_SKIN_MESH:
		s_bSkinMesh = GS_FALSE;
		break;

	case GS_CALC_SKELETON:
		s_bCalculateSkeleton = GS_FALSE;
		break;

	case GS_CEL_SHADE:
		s_bCelShade = GS_FALSE;
		break;
	}
}

/********** End of File ******************************************************/
