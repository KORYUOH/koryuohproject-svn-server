/******************************************************************************
* File Name : GSmesh.h                           Ver : 1.00  Date : 2002-08-03
*
* Description :
*
*		���b�V���f�[�^ �w�b�_�t�@�C���D�D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSMESH_H_
#define		_GSMESH_H_

#include	"GStype.h"
#include	"GStexture.h"

/****** �萔�錾 *************************************************************/

#define	GS_MATERIAL_TEXTURE		( 1	<< 0  )	/* �e�N�X�`���t���O			*/
#define	GS_MATERIAL_SPHERE_MAP	( 1	<< 31 )	/* ���`���}�b�s���O		*/
#define	GS_MATERIAL_TEX_CLAMP	( 1	<< 30 )	/* �e�N�X�`�����N�����v		*/

/****** �f�[�^�^�錾 *********************************************************/

/*----- �}�e���A�����\���� ------------------------------------------------*/

typedef	struct							/* �}�e���A���\����			*/
{
	GSbitfield		MaterialInfo;		/* �}�e���A�����t���O		*/
	GScolor			Diffuse;			/* �g�U���J���[				*/
	GScolor			Ambient;			/* �����J���[				*/
	GScolor			Specular;			/* ���ʔ��ˌ��J���[			*/
	GScolor			Emissive;			/* ���ˌ��J���[				*/
	GSfloat			Power;				/* �n�C���C�g�̑N���x		*/
	GStexture*		pTexture;			/* �e�N�X�`��				*/

} GSmaterial;

/*----- �ʃf�[�^�O���[�v�\���� ---------------------------------------------*/

typedef	struct							/* �ʃf�[�^�O���[�v�^		*/
{
	GSbitfield		FaceInfo;			/* �ʏ��t���O				*/
	GSuint			MaterialNo;			/* �}�e���A���i���o			*/
	GSuint			numIndices;			/* ���_�C���f�b�N�X��		*/
	GSuint			StartIndices;		/* ���_�C���f�b�N�X�J�n�ʒu	*/

} GSfacegroup;

/*----- ���b�V���\���� -----------------------------------------------------*/

typedef	struct							/* ���b�V���^				*/
{
	GSbitfield		MeshInfo;			/* ���b�V�����				*/
	GSuint			numMaterials;		/* �}�e���A���f�[�^��		*/
	GSuint			numFaceGroups;		/* �����_�����O�ʏ��		*/
	GSuint			numIndices;			/* ���_�C���f�b�N�X��		*/
	GSuint			numVertices;		/* ���_�f�[�^�� 			*/
	GSuint			numTexCoords;		/* �e�N�X�`�����W��			*/
	GSuint			numWeights;			/* ���_�E�F�C�g��			*/
	GSmaterial*		pMaterials;			/* �}�e���A���f�[�^�z��		*/
	GSfacegroup*	pFaceGroups;		/* �����_�����O�ʏ��		*/
	GSushort*		pIndices;			/* ���_�C���f�b�N�X			*/
	GSvector3*		pPoints;			/* ���_���W�z��				*/
	GSvector3*		pNormals;			/* �@���x�N�g���z��			*/
	GScolor*		pDiffuseColors;		/* �g�U���J���[�z��			*/
	GScolor*		pSpecularColors;	/* ���ʔ��ˌ��J���[�z��		*/
	GSvector2**		ppTexCoords;		/* �e�N�X�`�����W�z��		*/
	GSfloat**		ppWeights;			/* ���_�E�F�C�g�z��			*/
	GSuint*			pBoneIndices;		/* �{�[���C���f�b�N�X�z��	*/
	GSplane*		pPlanes;			/* ���ʃf�[�^�z��			*/
	GSvector3		Center;				/* ���b�V���̋��E���̒��S	*/
	GSfloat			fRadius;			/* ���b�V���̋��E���̔��a	*/

} GSmesh;

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/****** �֐��v���g�^�C�v�錾 *************************************************/

/*=============================================================================
*
* Purpose : ���b�V���̐����D
*
* Return  : ���b�V����Ԃ��D
*
*============================================================================*/
extern GSmesh*
gsMeshNew
(
	void
);

/*=============================================================================
*
* Purpose : ���b�V���̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMeshDelete
(
	GSmesh*			pMesh				/* ���b�V���f�[�^		*/
);

/*=============================================================================
*
* Purpose : ���b�V���̃N���[���A�b�v�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMeshCleanUp
(
	GSmesh*			pMesh				/* ���b�V���f�[�^		*/
);

/*=============================================================================
*
* Purpose : ���b�V���t�@�C���̓ǂݍ��݁D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSboolean
gsMeshLoadFile
(
	GSmesh*			pMesh,				/* ���b�V���f�[�^		*/
	const char*		pszFileName			/* �t�@�C����			*/
);

/*=============================================================================
*
* Purpose : ���b�V���̕`��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMeshDraw
(
	GSmesh*			pMesh				/* ���b�V���f�[�^		*/
);

/*=============================================================================
*
* Purpose : ���b�V���̕`��D�i �Z���V�F�[�f�B���O �j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMeshDrawCelShade
(
	GSmesh*			pMesh,				/* ���b�V���f�[�^				*/
	GStexture*		pShadeTexture,		/* �V�F�[�f�B���O�p�e�N�X�`��	*/
	GSvector3*		pShadeLight,		/* ���C�g�̈ʒu					*/
	GScolor*		pLineColor,			/* �֊s���̐F					*/
	GSfloat			fLineWidth			/* �֊s���̑���					*/
);

/*=============================================================================
*
* Purpose : �X�L�j���O���b�V���̕`��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMeshDrawSkin
(
	GSmesh*				pMesh,			/* ���b�V���f�[�^		*/
	const GSmatrix4*	pMatrices		/* �ϊ��s��z��			*/
);

/*=============================================================================
*
* Purpose : �X�L�j���O���b�V���̕`��D�i �Z���V�F�[�f�B���O �j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMeshDrawSkinCelShade
(
	GSmesh*				pMesh,			/* ���b�V���f�[�^				*/
	const GSmatrix4*	pMatrices,		/* �ϊ��s��z��					*/
	GStexture*			pShadeTexture,	/* �V�F�[�f�B���O�p�e�N�X�`��	*/
	GSvector3*			pShadeLight,	/* ���C�g�̈ʒu					*/
	GScolor*			pLineColor,		/* �֊s���̐F					*/
	GSfloat				fLineWidth		/* �֊s���̑���					*/
);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
