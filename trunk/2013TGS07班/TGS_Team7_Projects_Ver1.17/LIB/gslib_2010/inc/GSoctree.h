/******************************************************************************
* File Name : GSoctree.h                         Ver : 1.00  Date : 2003-08-18
*
* Description :
*
*		オクツリー ヘッダファイル．．
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSOCTREE_H_
#define		_GSOCTREE_H_

#include	"GSmesh.h"

/****** データ型宣言 *********************************************************/

/*----- オクツリーノード構造体 -----------------------------------------------*/

/// <summary>
/// オクツリーノード型.
/// </summary>
typedef	struct gsoctnode
{
	/// <summary>リーフノードフラグ.</summary>
	GSboolean			bLeafNode;
	/// <summary>ノードの幅.</summary>
	GSvector3			PosMin;
	/// <summary>ノードの中心点.</summary>
	GSvector3			PosMax;
	/// <summary>ノードのメッシュデータ.</summary>
	GSmesh*				pMesh;	
	/// <summary>メッシュのディスプレイリスト.</summary>
	GSuint				DisplayList;
	/// <summary>子ノードへのポインタ.</summary>
	struct gsoctnode*	pNodes[8];

} GSoctnode;

/*----- オクツリー構造体 -----------------------------------------------------*/

typedef	struct							/* オクツリー型					*/
{
	GSmesh*				pMesh;			/* メッシュデータ				*/
	GSuint				numNodes;		/* ノードの数					*/
	GSoctnode*			pNodes;			/* オクツリーのノード			*/

} GSoctree;

/****** 関数プロトタイプ宣言 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

	/*=============================================================================
	*
	* Purpose : オクツリーの生成．
	*
	* Return  : オクツリーを返す．
	*
	*============================================================================*/
	extern GSoctree*
		gsOctreeNew
		(
		void
		);

	/*=============================================================================
	*
	* Purpose : オクツリーの消滅．
	*
	* Return  : なし．
	*
	*============================================================================*/
	extern void
		gsOctreeDelete
		(
		GSoctree*		pOctree				/* オクツリーデータ		*/
		);

	/*=============================================================================
	*
	* Purpose : オクツリーのクリーンアップ．
	*
	* Return  : なし．
	*
	*============================================================================*/
	extern void
		gsOctreeCleanUp
		(
		GSoctree*		pOctree				/* オクツリーデータ		*/
		);

	/*=============================================================================
	*
	* Purpose : オクツリーファイルの読み込み．
	*
	* Return  : なし．
	*
	*============================================================================*/
	extern GSboolean
		gsOctreeLoadFile
		(
		GSoctree*		pOctree,			/* オクツリーデータ		*/
		const char*		pszFileName			/* ファイル名			*/
		);

	/*=============================================================================
	*
	* Purpose : オクツリーの描画．
	*
	* Return  : なし．
	*
	*============================================================================*/
	extern void
		gsOctreeDraw
		(
		GSoctree*		pOctree				/* オクツリーデータ		*/
		);

	/*=============================================================================
	*
	* Purpose : オクツリーと線分の衝突判定．
	*
	* Return  : なし．
	*
	*============================================================================*/
	extern GSboolean
		gsOctreeCollisionLine
		(
		GSoctree*			pOctree,		/* オクツリーデータ				*/
		const GSvector3*	pLine0,			/* 線分の始点					*/
		const GSvector3*	pLine1,			/* 線分の終点					*/
		GSvector3*			pIntersect,		/*-> メッシュと線分の交点		*/
		GSplane*			pPlane			/*-> 衝突した面の平面パラメータ	*/
		);

	/*=============================================================================
	*
	* Purpose : オクツリーとレイの衝突判定．
	*
	* Return  : なし．
	*
	*============================================================================*/
	/// <summary>
	/// オクツリーとレイの衝突判定.
	/// </summary>
	extern GSboolean
		gsOctreeCollisionRay
		(
		GSoctree*			pOctree,		/* オクツリーデータ				*/
		const GSvector3*	pRayPos,		/* レイの始点					*/
		const GSvector3*	pRayDir,		/* レイの方向					*/
		GSvector3*			pIntersect,		/*-> メッシュとレイの交点		*/
		GSplane*			pPlane			/*-> 衝突した面の平面パラメータ	*/
		);

	/*=============================================================================
	*
	* Purpose : オクツリーと球体の衝突判定．
	*
	* Return  : なし．
	*
	*============================================================================*/
	/// <summary>
	/// オクツリーと球体の衝突判定.
	/// </summary>
	extern GSboolean
		gsOctreeCollisionSphere
		(
		GSoctree*			pOctree,		/* オクツリーデータ			*/
		const GSvector3*	pCenter,		/* 球体の中心				*/
		GSfloat				Radius,			/* 球体の半径				*/
		GSvector3*			pOutCenter		/*-> 補正後の球の中心座標	*/
		);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
