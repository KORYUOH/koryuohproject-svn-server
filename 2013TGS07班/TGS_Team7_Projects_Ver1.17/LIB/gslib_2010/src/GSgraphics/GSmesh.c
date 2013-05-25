/******************************************************************************
* File Name : GSmesh.c                           Ver : 1.00  Date : 2003-01-31
*
* Description :
*
*       ���b�V���f�[�^�D
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

/****** �֐��v���g�^�C�v�錾 *************************************************/

static void	DrawMesh( GSmaterial*, GSuint, GSfacegroup*, GSushort*, GSvector3*, GSvector3*, GScolor*, GSuint, GSvector2** );
static void	DrawMeshCelShade( GSmaterial*, GSuint, GSfacegroup*, GSuint, GSushort*, GSuint, GSvector3*, GSvector3*, GScolor*, GSuint, GSvector2**, GStexture*,  GSvector3*, GScolor*, GSfloat );
static void	SetMaterial( GSmaterial* );
static void	LoadMaterial( GSmaterial*, GFILE );
static void	TransformPoints( GSvector3*, GSuint, GSvector3*, GSuint, GSfloat**, GSuint*, const GSmatrix4* );
static void	TransformNormals( GSvector3*, GSuint, GSvector3*, GSuint, GSfloat**, GSuint*, const GSmatrix4* );
static void CalculatePlanes( GSmesh* );

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
)
{
	GSmesh*		pMesh;

	/* ���b�V���̐��� */
	pMesh = new_object( sizeof( GSmesh ) );

	/* �S�Ẵ����o���[���N���A���� */
	memset( pMesh, 0, sizeof( GSmesh ) );

	return	pMesh;
}

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
)
{
	/* ���b�V�����N���[���A�b�v���� */
	gsMeshCleanUp( pMesh );

	/* ���b�V���̏��� */
	del_object( pMesh );
}

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
)
{
	GSuint		i;

	/* �{�[���C���f�b�N�X�z��̏��� */
	if ( pMesh->pBoneIndices != NULL )
	{
		del_object( pMesh->pBoneIndices );
	}

	/* ���_�E�F�C�g�z��̏��� */
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

	/* �e�N�X�`�����W�z��̏��� */
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

	/* ���ˌ��J���[�z��̏��� */
	if ( pMesh->pSpecularColors != NULL )
	{
		del_object( pMesh->pSpecularColors );
	}

	/* �g�U���J���[�z��̏��� */
	if ( pMesh->pDiffuseColors != NULL )
	{
		del_object( pMesh->pDiffuseColors );
	}

	/* �@���x�N�g���z��̏��� */
	if ( pMesh->pNormals != NULL )
	{
		del_object( pMesh->pNormals );
	}

	/* ���_���W�z��̏��� */
	if ( pMesh->pPoints != NULL )
	{
		del_object( pMesh->pPoints );
	}

	/* �}�e���A���f�[�^�̏��� */
	if ( pMesh->pMaterials != NULL )
	{
		for ( i = 0; i < pMesh->numMaterials; i++ )
		{
			/* �e�N�X�`���̏��� */
			if ( pMesh->pMaterials[i].pTexture != NULL )
			{
				gsTextureDelete( pMesh->pMaterials[i].pTexture );
			}
		}
		del_object( pMesh->pMaterials );
	}

	/* ���_�C���f�b�N�X�z��̏��� */
	if ( pMesh->pIndices != NULL )
	{
		del_object( pMesh->pIndices );
	}

	/* �ʃf�[�^�z��̏��� */
	if ( pMesh->pFaceGroups != NULL )
	{
		del_object( pMesh->pFaceGroups );
	}

	/* ���ʃf�[�^�z��̏��� */
	if ( pMesh->pPlanes != NULL )
	{
		del_object( pMesh->pPlanes );
	}

	/* �S�Ẵ����o���[���N���A���� */
	memset( pMesh, 0, sizeof( GSmesh ) );
}

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
)
{
	GFILE			file;
	GSuint			bPoints;
	GSuint			bNormals;
	GSuint			bDiffuseColors;
	GSuint			bSpecularColors;
	GSuint			bBoneIndices;
	GSuint			i;

	/* ���b�V���t�@�C�����I�[�v������ */
	if ( ( file = GFileOpen( pszFileName, "r" ) ) == NULL )
	{
		/* �t�@�C�����I�[�v���ł��Ȃ����� */
		return	GS_FALSE;
	}

	/* ���b�V���̃N���[���A�b�v */
	gsMeshCleanUp( pMesh );

	/* ���b�V�����t���O��ǂݍ��� */
	GFileReadDwordHex( file, &pMesh->MeshInfo );

	/* ���_�f�[�^��񐔂̓ǂݍ��� ( �����_�ł͎g�p���Ă��Ȃ� �j*/
	GFileReadDword( file, &bPoints );

	/* ���_�f�[�^�t���O�̓ǂݍ��� */
	GFileReadDword( file, &bPoints );

	/* �@���x�N�g���f�[�^�t���O�̓ǂݍ��� */
	GFileReadDword( file, &bNormals );

	/* �g�U���J���[�f�[�^�t���O�̓ǂݍ��� */
	GFileReadDword( file, &bDiffuseColors );

	/* ���ʔ��ˌ��J���[�f�[�^�t���O�̓ǂݍ��� */
	GFileReadDword( file, &bSpecularColors );

	/* �e�N�X�`�����W�f�[�^���̓ǂݍ��� */
	GFileReadDword( file, &pMesh->numTexCoords );

	/* ���_�E�F�C�g�f�[�^���̓ǂݍ��� */
	GFileReadDword( file, &pMesh->numWeights );

	/* �{�[���C���f�b�N�X�f�[�^�t���O�̓ǂݍ��� */
	GFileReadDword( file, &bBoneIndices );

	/* �}�e���A���f�[�^���̓ǂݍ��� */
	GFileReadDword( file, &pMesh->numMaterials );

	/* �ʃf�[�^�O���[�v���̓ǂݍ��� */
	GFileReadDword( file, &pMesh->numFaceGroups );

	/* ���_�C���f�b�N�X�f�[�^���̓ǂݍ��� */
	GFileReadDword( file, &pMesh->numIndices );

	/* ���_�f�[�^���̓ǂݍ��� */
	GFileReadDword( file, &pMesh->numVertices );

	/* �}�e���A���f�[�^�z��̐��� */
	pMesh->pMaterials = new_object( sizeof( GSmaterial ) * pMesh->numMaterials );

	/* �}�e���A���f�[�^�z��̓ǂݍ��� */
	for ( i = 0; i < pMesh->numMaterials; i++ )
	{
		LoadMaterial( &pMesh->pMaterials[i], file );
	}

	/* �ʃO���[�v�z��̐��� */
	pMesh->pFaceGroups = new_object( sizeof( GSfacegroup ) * pMesh->numFaceGroups );

	/* �ʃO���[�v�̔z��̓ǂݍ��� */
	for ( i = 0; i < pMesh->numFaceGroups; i++ )
	{
		/* �ʏ��t���O�̓ǂݍ��� */
		GFileReadDwordHex( file, &pMesh->pFaceGroups[i].FaceInfo );

		/* �}�e���A���C���f�b�N�X�̓ǂݍ���	*/
		GFileReadDword( file, &pMesh->pFaceGroups[i].MaterialNo );

		/* ���_�C���f�b�N�X�̊J�n�ʒu�̓ǂݍ��� */
		GFileReadDword( file, &pMesh->pFaceGroups[i].StartIndices );

		/* ���_�C���f�b�N�X���̓ǂݍ��� */
		GFileReadDword( file, &pMesh->pFaceGroups[i].numIndices );
	}

	/* ���_�C���f�b�N�X�z��̓ǂݍ��� */
	if ( pMesh->numIndices != 0 )
	{
		pMesh->pIndices = new_object( sizeof( GSushort ) * pMesh->numIndices );

		GFileReadWordArray( file, pMesh->numIndices, pMesh->pIndices );
	}

	/* ���_�f�[�^�z��̓ǂݍ��� */
	if ( bPoints == GS_TRUE )
	{
		pMesh->pPoints = new_object( sizeof( GSvector3 ) * pMesh->numVertices );

		GFileReadVector3Array( file, pMesh->numVertices, pMesh->pPoints );
	}

	/* �@���x�N�g���z��̓ǂݍ��� */
	if ( bNormals == GS_TRUE )
	{
		pMesh->pNormals = new_object( sizeof( GSvector3 ) * pMesh->numVertices );

		GFileReadVector3Array( file, pMesh->numVertices, pMesh->pNormals );
	}

	/* �g�U���J���[�z��̓ǂݍ��� */
	if ( bDiffuseColors == GS_TRUE )
	{
		pMesh->pDiffuseColors = new_object( sizeof( GScolor ) * pMesh->numVertices );

		GFileReadColorArray( file, pMesh->numVertices, pMesh->pDiffuseColors );
	}

	/* ���ʔ��ˌ��J���[�z��̓ǂݍ��� */
	if ( bSpecularColors == GS_TRUE )
	{
		pMesh->pSpecularColors = new_object( sizeof( GScolor ) * pMesh->numVertices );

		GFileReadColorArray( file, pMesh->numVertices, pMesh->pSpecularColors );
	}

	/* �e�N�X�`�����W�z��̓ǂݍ��� */
	if ( pMesh->numTexCoords != 0 )
	{
		pMesh->ppTexCoords = new_object( sizeof( GSvector2* ) * pMesh->numTexCoords );

		for ( i = 0; i < pMesh->numTexCoords; i++ )
		{
			pMesh->ppTexCoords[i] = new_object( sizeof( GSvector2 ) * pMesh->numVertices );

			GFileReadTexCoordArray( file, pMesh->numVertices, pMesh->ppTexCoords[i] );
		}
	}

	/* ���_�E�F�C�g�z��̓ǂݍ��� */
	if ( pMesh->numWeights != 0 )
	{
		pMesh->ppWeights = new_object( sizeof( GSfloat* ) * pMesh->numWeights );

		for ( i = 0; i < pMesh->numWeights; i++ )
		{
			pMesh->ppWeights[i] = new_object( sizeof( GSfloat ) * pMesh->numVertices );

			GFileReadFloatArray( file, pMesh->numVertices, pMesh->ppWeights[i] );
		}
	}

	/* �{�[���C���f�b�N�X�z��̓ǂݍ��� */
	if ( bBoneIndices == TRUE )
	{
		pMesh->pBoneIndices = new_object( sizeof( GSuint ) * pMesh->numVertices );

		GFileReadDwordHexArray( file, pMesh->numVertices, pMesh->pBoneIndices );
	}

	/* ���b�V���t�@�C���̃N���[�Y */
	GFileClose( file );

	/* ���b�V���̕��ʃf�[�^�z����v�Z���� */
	CalculatePlanes( pMesh );

	return	GS_TRUE;
}

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
)
{
	/* ���b�V����`�悷�� */
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
)
{
	/* �Z���V�F�[�f�B���O���s�����b�V����`�悷�� */
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
)
{
	GSvector3*			pPoints;
	GSvector3*			pNormals;

	/* �{�[���C���f�b�N�X�������Ă��邩�H */
	if ( pMesh->pBoneIndices == NULL )
	{
		/* �{�[���C���f�b�N�X���Ȃ��ꍇ�̓X�L�j���O�̌v�Z�͂��Ȃ� */
		gsMeshDraw( pMesh );

		return;
	}

	/* ���_�f�[�^�z��𐶐����� */
	pPoints = new_object( sizeof( GSvector3 ) * pMesh->numVertices );

	/* �@���x�N�g���z��𐶐�����	*/
	pNormals = new_object( sizeof( GSvector3 ) * pMesh->numVertices );

	/* ���_�f�[�^�z������W�ϊ����� */
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

	/* �@���f�[�^�z������W�ϊ����� */
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

	/* ���b�V����`�悷�� */
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

	/* �@���x�N�g���z������ł����� */
	del_object( pNormals );

	/* ���_�f�[�^�z������ł����� */
	del_object( pPoints );
}

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
)
{
	GSvector3*			pPoints;
	GSvector3*			pNormals;

	/* �{�[���C���f�b�N�X�������Ă��邩�H */
	if ( pMesh->pBoneIndices == NULL )
	{
		/* �{�[���C���f�b�N�X���Ȃ��ꍇ�̓X�L�j���O�̌v�Z�͂��Ȃ� */
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

	/* ���_�f�[�^�z��𐶐����� */
	pPoints = new_object( sizeof( GSvector3 ) * pMesh->numVertices );

	/* �@���x�N�g���z��𐶐�����	*/
	pNormals = new_object( sizeof( GSvector3 ) * pMesh->numVertices );

	/* ���_�f�[�^�z������W�ϊ����� */
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

	/* �@���f�[�^�z������W�ϊ����� */
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

	/* �Z���V�F�[�f�B���O���s�����b�V����`�悷�� */
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

	/* �@���x�N�g���z������ł����� */
	del_object( pNormals );

	/* ���_�f�[�^�z������ł����� */
	del_object( pPoints );
}

/*-----------------------------------------------------------------------------
*
* Purpose : ���b�V���̕`��D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
DrawMesh
(
	GSmaterial*		pMaterials,			/* �}�e���A���f�[�^�z��	*/
	GSuint			numFaceGroups,		/* �ʃf�[�^�O���[�v��	*/
	GSfacegroup*	pFaceGroups,		/* �ʃf�[�^�O���[�v		*/
	GSushort*		pIndices,			/* ���_�C���f�b�N�X		*/
	GSvector3*		pPoints,			/* ���_�f�[�^�z��		*/
	GSvector3*		pNormals,			/* �@���x�N�g���z��		*/
	GScolor*		pDiffuseColors,		/* �g�U���z��			*/
	GSuint			numTexCoords,		/* �e�N�X�`�����W�z��	*/
	GSvector2**	ppTexCoords			/* �e�N�X�`�����W�z��	*/
)
{
	GScolor			CurrentColor;
	GSuint			i;

	/* �e�탌���_�����O���[�h�̑ޔ� */
	glPushAttrib( GL_ENABLE_BIT );

	/* ���݂̃J���[���擾���� */
	glGetFloatv( GL_CURRENT_COLOR, (GLfloat*)&CurrentColor );

	/* ���_�f�[�^�z��̐ݒ� */
	glDisableClientState( GL_NORMAL_ARRAY );
	if ( pPoints != NULL )
	{
		glEnableClientState( GL_VERTEX_ARRAY );
		glVertexPointer( 3, GL_FLOAT, 0, pPoints );
	}

	/* �@���x�N�g���z��̐ݒ� */
	glDisableClientState( GL_NORMAL_ARRAY );
	if ( pNormals != NULL )
	{
		glEnableClientState( GL_NORMAL_ARRAY );
		glNormalPointer( GL_FLOAT, 0, pNormals );
	}

	/* �J���[�f�[�^�z��̐ݒ� */
	glDisableClientState( GL_COLOR_ARRAY );
	if ( pDiffuseColors != NULL )
	{
		glEnableClientState( GL_COLOR_ARRAY );
		glColorPointer( 4, GL_FLOAT, 0, pDiffuseColors );
	}

	/* �e�N�X�`�����W�z��̐ݒ� */
	glDisableClientState( GL_TEXTURE_COORD_ARRAY );
	if ( numTexCoords != 0 )
	{
		glEnableClientState( GL_TEXTURE_COORD_ARRAY );
		glTexCoordPointer( 2, GL_FLOAT, 0, ppTexCoords[0] );
	}

	for ( i = 0; i < numFaceGroups; i++ )
	{
		/* �}�e���A�����̐ݒ������ */
		SetMaterial( &pMaterials[ pFaceGroups[i].MaterialNo ] );

		/* �O�p�`��`�悷�� */
		glDrawElements
		(
			GL_TRIANGLES,
			pFaceGroups[i].numIndices,
			GL_UNSIGNED_SHORT, 
			&pIndices[ pFaceGroups[i].StartIndices ]
		);

		/* �J�����g�J���[��ݒ肷�� */
		glColor4fv( (GLfloat*)&CurrentColor );
	}

	/* �����_�����O���[�h�̕��A */
	glPopAttrib();
}

/*-----------------------------------------------------------------------------
*
* Purpose : ���b�V���̕`��D�i �Z���V�F�[�f�B���O �j
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
DrawMeshCelShade
(
	GSmaterial*		pMaterials,			/* �}�e���A���f�[�^�z��			*/
	GSuint			numFaceGroups,		/* �ʃf�[�^�O���[�v��			*/
	GSfacegroup*	pFaceGroups,		/* �ʃf�[�^�O���[�v				*/
	GSuint			numIndices,			/* ���_�C���f�b�N�X��			*/
	GSushort*		pIndices,			/* ���_�C���f�b�N�X				*/
	GSuint			numVertices,		/* ���_�f�[�^��					*/
	GSvector3*		pPoints,			/* ���_�f�[�^�z��				*/
	GSvector3*		pNormals,			/* �@���x�N�g���z��				*/
	GScolor*		pDiffuseColors,		/* �g�U���z��					*/
	GSuint			numTexCoords,		/* �e�N�X�`�����W�z��			*/
	GSvector2**	ppTexCoords,		/* �e�N�X�`�����W�z��			*/
	GStexture*		pShadeTexture,		/* �V�F�[�f�B���O�p�e�N�X�`��	*/
	GSvector3*		pShadeLight,		/* ���C�g�̈ʒu					*/
	GScolor*		pLineColor,			/* �֊s���̐F					*/
	GSfloat			fLineWidth			/* �֊s���̑���					*/
)
{
	GSmaterial*		pMaterial;
	GSvector2*		pTexCoords;
	GScolor			CurrentColor;
	GSmatrix4		tmpMat;
	GSvector3		tmpLight;
	GScolor			tmpColor;
	GSuint			i;

	/* ���݂̃J���[���擾���� */
	glGetFloatv( GL_CURRENT_COLOR, (GLfloat*)&CurrentColor );

	/* �g�D�[���V�F�[�f�B���O�p�̃e�N�X�`�����W�z��𐶐� */
	pTexCoords = new_object( sizeof( GSvector2 ) * numVertices );

	/* ���f���r���[�ϊ��}�g���N�X���擾���� */
	glGetFloatv( GL_MODELVIEW_MATRIX, (GLfloat*)&tmpMat );

	/* ���C�g�̕����Ƀ��f���r���[�ϊ��s��̋t�s����|���Z���� */
	tmpLight.x = pShadeLight->x * tmpMat.m[0][0]
			   + pShadeLight->y * tmpMat.m[0][1]
			   + pShadeLight->z * tmpMat.m[0][2];
	tmpLight.y = pShadeLight->x * tmpMat.m[1][0]
			   + pShadeLight->y * tmpMat.m[1][1]
			   + pShadeLight->z * tmpMat.m[1][2];
	tmpLight.z = pShadeLight->x * tmpMat.m[2][0]
			   + pShadeLight->y * tmpMat.m[2][1]
			   + pShadeLight->z * tmpMat.m[2][2];

	/* ���C�g�̃x�N�g���𐳋K������ */
	gsVector3Normalize( &tmpLight, &tmpLight );

	if ( pNormals != NULL )
	{
		/* �g�D�[���V�F�[�f�B���O�̃e�N�X�`�����W�̌v�Z���s�� */
		for ( i = 0; i < numVertices; i++ )
		{
			/* ���C�g�̕����Ɩ@���x�N�g������e�N�X�`�����W�����߂� */
			pTexCoords[i].s = MAX( 0.0f, gsVector3Dot( &pNormals[i], &tmpLight ) );
			pTexCoords[i].t = 0.0f;
		}
	}
	else
	{
		/* �@���x�N�g�������݂��Ȃ��ꍇ�̓V�F�[�f�B���O�ł��Ȃ� */
		for ( i = 0; i < numVertices; i++ )
		{
			pTexCoords[i].s = 1.0f;
			pTexCoords[i].t = 0.0f;
		}
	}

	/* �e�탌���_�����O���[�h�̑ޔ� */
	glPushAttrib
	(
		GL_ENABLE_BIT 		|
		GL_DEPTH_BUFFER_BIT |
		GL_COLOR_BUFFER_BIT |
		GL_POLYGON_BIT
	);

	/* ���C�e�B���O���I�t�ɂ��� */
	glDisable( GL_LIGHTING );
	glDepthFunc( GL_LEQUAL );
	glEnable( GL_BLEND );

	/* ���_�f�[�^�z��̐ݒ� */
	glDisableClientState( GL_VERTEX_ARRAY );
	if ( pPoints != NULL )
	{
		glEnableClientState( GL_VERTEX_ARRAY );
		glVertexPointer( 3, GL_FLOAT, 0, pPoints );
	}

	/* �J���[�f�[�^�z��̐ݒ� */
	glDisableClientState( GL_COLOR_ARRAY );
	if ( pDiffuseColors != NULL )
	{
		glEnableClientState( GL_COLOR_ARRAY );
		glColorPointer( 4, GL_FLOAT, 0, pDiffuseColors );
	}

	/* �@���x�N�g���z��̐ݒ� */
	glDisableClientState( GL_NORMAL_ARRAY );
	if ( pNormals != NULL )
	{
		glEnableClientState( GL_NORMAL_ARRAY );
		glNormalPointer( GL_FLOAT, 0, pNormals );
	}

	for ( i = 0; i < numFaceGroups; i++ )
	{
		/* �}�e���A���f�[�^�̎擾 */
		pMaterial = &pMaterials[ pFaceGroups[i].MaterialNo ];

		/* �}�e���A���̐ݒ� */
		gsColorModulate( &tmpColor, &pMaterial->Diffuse, &CurrentColor );
		glColor4fv( (GLfloat*)&tmpColor );

		/* �@���x�N�g���z��𖳌��ɂ��� */
		glDisableClientState( GL_NORMAL_ARRAY );

		/* �e�N�X�`�����W��L���ɂ��� */
		glEnableClientState( GL_TEXTURE_COORD_ARRAY );

		/* �Z���V�F�[�f�B���O�p�̃e�N�X�`�����o�C���h���� */
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

		/* �Z���V�F�[�f�B���O�p�̃e�N�X�`�����W��ݒ肷�� */
		glTexCoordPointer( 2, GL_FLOAT, 0, pTexCoords );

		/* �Z���V�F�[�f�B���O�p�|���S����`�悷�� */
		glDrawElements
		(
			GL_TRIANGLES,
			pFaceGroups[i].numIndices,
			GL_UNSIGNED_SHORT, 
			&pIndices[ pFaceGroups[i].StartIndices ]
		);

		if ( pMaterial->pTexture != NULL )
		{
			/* �e�N�X�`���}�b�s���O�̐ݒ� */
			gsTextureBind( pMaterial->pTexture );
			glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
			glBlendFunc( GL_DST_COLOR, GL_ZERO );
			glEnable( GL_TEXTURE_2D );

			/* �e�N�X�`�����N�����v���邩�H*/
			if ( ( pMaterial->MaterialInfo & GS_MATERIAL_TEX_CLAMP ) != 0 )
			{
				/* �e�N�X�`�����N�����v�ɐݒ肷�� */
				glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP );
				glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP );

				/* EDGE�N�����v���L���ł���Ύg�p���� */
				glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
				glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
			}
			else
			{
				/* �e�N�X�`�������b�v������ */
				glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
				glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
			}

			/* ���`���}�b�s���O���s�����H */
			if ( ( pMaterial->MaterialInfo & GS_MATERIAL_SPHERE_MAP ) != 0 )
			{
				/* ���`���}�b�s���O��L���ɂ��� */
				glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP );
				glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP );
				glEnable( GL_TEXTURE_GEN_S );
				glEnable( GL_TEXTURE_GEN_T );
				glDisableClientState( GL_TEXTURE_COORD_ARRAY );

				/* �@���x�N�g���z���L���ɂ��� */
				glEnableClientState( GL_NORMAL_ARRAY );
			}
			else
			{
				/* �ʏ�̃e�N�X�`�����W�z��̐ݒ� */
				glTexCoordPointer( 2, GL_FLOAT, 0, ppTexCoords[0] );
			}

			/* �ʏ�̃e�N�X�`����`�悷�� */
			glDrawElements
			(
				GL_TRIANGLES,
				pFaceGroups[i].numIndices,
				GL_UNSIGNED_SHORT, 
				&pIndices[ pFaceGroups[i].StartIndices ]
			);

			/* ���`���}�b�s���O�𖳌��ɂ��� */
			glDisable( GL_TEXTURE_GEN_S );
			glDisable( GL_TEXTURE_GEN_T );
		}

		/* �J�����g�J���[�𕜋A���� */
		glColor4fv( (GLfloat*)&CurrentColor );
	}

	/* �֊s���̕`����s�� */
	if ( fLineWidth > 0 )
	{
		float scale = fLineWidth * 0.01f;
	
		/* �@�������ɒ��_�f�[�^���g�傷�� */
		for ( i = 0; i < numVertices; i++ )
		{
			pPoints[i].x += pNormals[i].x * scale;
			pPoints[i].y += pNormals[i].y * scale;
			pPoints[i].z += pNormals[i].z * scale;
		}

		/* �e�N�X�`���𖳌��ɂ��� */
		glDisableClientState( GL_TEXTURE_COORD_ARRAY );
		glDisable( GL_TEXTURE_2D );

		/* �֊s���̐F��ݒ肷�� */
		gsColorModulate( &tmpColor, pLineColor, &CurrentColor );
		glColor4fv( (GLfloat*)&tmpColor );

		/* �����_�����O���[�h�̐ݒ� */
		glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
		glCullFace( GL_FRONT );

		/* �֊s����`�悷�� */
		glDrawElements
		(
			GL_TRIANGLES,
			numIndices,
			GL_UNSIGNED_SHORT,
			pIndices
		);

		/* �J�����g�J���[�𕜋A���� */
		glColor4fv( (GLfloat*)&CurrentColor );
	}

	/* �e�탌���_�����O���[�h�̕��A */
	glPopAttrib();

	/* �g�D�[���V�F�[�f�B���O�p�̃e�N�X�`�����W�����ł����� */
	del_object( pTexCoords );
}

/*-----------------------------------------------------------------------------
*
* Purpose : �}�e���A���̐ݒ�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
SetMaterial
(
	GSmaterial*		pMaterial			/* �}�e���A���f�[�^	*/
)
{
	GScolor			Diffuse;
	GScolor			Ambient;
	GScolor			CurrentColor;

	/* ���݂̃J���[���擾���� */
	glGetFloatv( GL_CURRENT_COLOR, (GLfloat*)&CurrentColor );

	/* �����Ɗg�U���J���[�����݂̃J���[�ƕϒ����� */
	gsColorModulate( &Diffuse, &pMaterial->Diffuse, &CurrentColor );
	gsColorModulate( &Ambient, &pMaterial->Ambient, &CurrentColor );

	/* �}�e���A�����̐ݒ� */
	glMaterialfv( GL_FRONT, GL_DIFFUSE,   (GLfloat*)&Diffuse );
	glMaterialfv( GL_FRONT, GL_AMBIENT,   (GLfloat*)&Ambient );
	glMaterialfv( GL_FRONT, GL_SPECULAR,  (GLfloat*)&pMaterial->Specular );
	glMaterialfv( GL_FRONT, GL_EMISSION,  (GLfloat*)&pMaterial->Emissive );
	glMaterialf(  GL_FRONT, GL_SHININESS, (GLfloat)pMaterial->Power      );

	/* ���C�e�B���O���I�t�̏ꍇ�̃}�e���A���ݒ� */
	glColor4fv( (GLfloat*)&Diffuse );

	if ( pMaterial->pTexture == NULL )
	{
		/* �e�N�X�`���}�b�s���O�̐ݒ���� */
		glDisableClientState( GL_TEXTURE_COORD_ARRAY );
		glDisable( GL_TEXTURE_2D );
		glDisable( GL_TEXTURE_1D );
	}
	else
	{
		/* �e�N�X�`���}�b�s���O�̐ݒ� */
		gsTextureBind( pMaterial->pTexture );
		glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
		glEnable( GL_TEXTURE_2D );
		glEnableClientState( GL_TEXTURE_COORD_ARRAY );

		/* �e�N�X�`�����N�����v���邩�H*/
		if ( ( pMaterial->MaterialInfo & GS_MATERIAL_TEX_CLAMP ) != 0 )
		{
			/* �e�N�X�`�����N�����v�ɐݒ肷�� */
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP );

			/* EDGE�N�����v���L���ł���Ύg�p���� */
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
		}
		else
		{
			/* �e�N�X�`�������b�v������ */
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
		}
	}

	if ( ( pMaterial->MaterialInfo & GS_MATERIAL_SPHERE_MAP ) != 0 )
	{
		/* ���`���}�b�s���O��L���ɂ��� */
		glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP );
		glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP );
		glEnable( GL_TEXTURE_GEN_S );
		glEnable( GL_TEXTURE_GEN_T );
		glDisableClientState( GL_TEXTURE_COORD_ARRAY );
	}
	else
	{
		/* ���`���}�b�s���O�𖳌��ɂ��� */
		glDisable( GL_TEXTURE_GEN_S );
		glDisable( GL_TEXTURE_GEN_T );
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : �}�e���A���̓ǂݍ��݁D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
LoadMaterial
(
	GSmaterial*	pMaterial,				/* �}�e���A��		*/
	GFILE		file					/* �t�@�C��			*/
)
{
	/* �}�e���A�����t���O�̓ǂݍ��� */
	GFileReadDwordHex( file, &pMaterial->MaterialInfo );

	/* �g�U���J���[�̓ǂݍ��� */
	GFileReadColor( file, &pMaterial->Diffuse );

	/* �����J���[�̓ǂݍ��� */
	GFileReadColor( file, &pMaterial->Ambient );

	/* ���ʔ��ˌ��J���[�̓ǂݍ��� */
	GFileReadColor( file, &pMaterial->Specular );

	/* ���ˌ��J���[�̓ǂݍ��� */
	GFileReadColor( file, &pMaterial->Emissive );

	/* �n�C���C�g�̑N���x�̓ǂݍ��� */
	GFileReadFloat( file, &pMaterial->Power );

	/* �e�N�X�`���������Ă��邩�H */
	pMaterial->pTexture = NULL;
	if ( ( pMaterial->MaterialInfo & GS_MATERIAL_TEXTURE ) != 0 )
	{
		char	TexFileName[_MAX_PATH];
		char	Drive[_MAX_DRIVE];
		char	Dir[_MAX_DIR];

		/* �I�[�v�����Ă��郁�b�V���t�@�C���̃p�X���擾���� */
		_splitpath( GFileGetFileName( file ), Drive, Dir, NULL, NULL );
		strcpy( TexFileName, Drive );
		strcat( TexFileName, Dir );

		/* �e�N�X�`���t�@�C�����̓ǂݍ��� */
		GFileReadString( file, TexFileName + strlen( TexFileName ) );

		/* �e�N�X�`���𐶐� */
		pMaterial->pTexture = gsTextureNew();

		/* �e�N�X�`���f�[�^��ǂݍ��� */
		gsTextureLoadBmpFile( pMaterial->pTexture, TexFileName );
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : ���_�f�[�^�̍��W�ϊ��D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
TransformPoints
(
	GSvector3*		pOutPoints,			/*-> �v�Z�㒸�_�f�[�^�z��	*/
	GSuint			numPoints,			/* ���_�f�[�^��				*/
	GSvector3*		pPoints,			/* ���_�f�[�^�z��			*/
	GSuint			numWeights,			/* ���_�E�F�C�g��			*/
	GSfloat**		ppWeights,			/* ���_�E�F�C�g				*/
	GSuint*			pBoneIndices,		/* �{�[���C���f�b�N�X		*/
	const GSmatrix4* pMatrices			/* �ϊ��s��					*/
)
{
	GSvector3		tmpPoint;
	GSfloat			fWeight;
	GSuint			m;
	GSuint			i;
	GSuint			j;

	for ( i = 0; i < numPoints; i++ )
	{
		/* �v�Z���ʗp���_�f�[�^�������� */
		gsVector3Init( &pOutPoints[i], 0.0f, 0.0f, 0.0f );

		/* �E�F�C�g�l�̏�����*/
		fWeight = 0.0f;

		/* ���_���W�̍��W�ϊ����s�� */
		for ( j = 0; j < numWeights; j++ )
		{
			/* �}�g���N�X�C���f�b�N�X�����o�� */
			m = ( pBoneIndices[i] >> ( j * 8 ) ) & 0xff;

			/* ���_���W�����W�ϊ� */
			gsVector3Transform( &tmpPoint, &pPoints[i], &pMatrices[m] );

			/* ���_���W�ɃE�F�C�g�̌v�Z������ */
			gsVector3Scale( &tmpPoint, &tmpPoint, ppWeights[j][i] );
			gsVector3Add( &pOutPoints[i], &pOutPoints[i], &tmpPoint );

			fWeight += ppWeights[j][i];
		}

		/* �}�g���N�X�C���f�b�N�X�����o�� */
		m = ( pBoneIndices[i] >> ( j * 8 ) ) & 0xff;

		/* ���_���W�����W�ϊ� */
		gsVector3Transform( &tmpPoint, &pPoints[i], &pMatrices[m] );

		/* ���_���W�ɃE�F�C�g�̌v�Z������ */
		gsVector3Scale( &tmpPoint, &tmpPoint, ( 1.0f - fWeight ) );
		gsVector3Add( &pOutPoints[i], &pOutPoints[i], &tmpPoint );
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : �@���x�N�g���̍��W�ϊ��D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
TransformNormals
(
	GSvector3*		pOutNormals,		/*-> �v�Z��@���x�N�g���z��	*/
	GSuint			numNormals,			/* �@���x�N�g���f�[�^��		*/
	GSvector3*		pNormals,			/* �@���x�N�g���z��			*/
	GSuint			numWeights,			/* ���_�E�F�C�g��			*/
	GSfloat**		ppWeights,			/* ���_�E�F�C�g				*/
	GSuint*			pBoneIndices,		/* �{�[���C���f�b�N�X		*/
	const GSmatrix4* pMatrices			/* �ϊ��s��					*/
)
{
	GSvector3		tmpNormal;
	GSfloat			fWeight;
	GSuint			m;
	GSuint			i;
	GSuint			j;

	for ( i = 0; i < numNormals; i++ )
	{
		/* �v�Z���ʗp�@���x�N�g���f�[�^�������� */
		gsVector3Init( &pOutNormals[i], 0.0f, 0.0f, 0.0f );

		/* �E�F�C�g�l�̏�����*/
		fWeight = 0.0f;

		/* �@���x�N�g���̍��W�ϊ����s�� */
		for ( j = 0; j < numWeights; j++ )
		{
			/* �}�g���N�X�C���f�b�N�X�����o�� */
			m = ( pBoneIndices[i] >> ( j * 8 ) ) & 0xff;

			/* �@���x�N�g�������W�ϊ� */
			gsVector3TransformNormal( &tmpNormal, &pNormals[i], &pMatrices[m] );

			/* �@���x�N�g���ɃE�F�C�g�̌v�Z������ */
			gsVector3Scale( &tmpNormal, &tmpNormal, ppWeights[j][i] );
			gsVector3Add( &pOutNormals[i], &pOutNormals[i], &tmpNormal );

			fWeight += ppWeights[j][i];
		}

		/* �}�g���N�X�C���f�b�N�X�����o�� */
		m = ( pBoneIndices[i] >> ( j * 8 ) ) & 0xff;

		/* �@���x�N�g�������W�ϊ� */
		gsVector3TransformNormal( &tmpNormal, &pNormals[i], &pMatrices[m] );

		/* �@���x�N�g���ɃE�F�C�g�̌v�Z������ */
		gsVector3Scale( &tmpNormal, &tmpNormal, ( 1.0f - fWeight ) );
		gsVector3Add( &pOutNormals[i], &pOutNormals[i], &tmpNormal );

		/* �@���x�N�g���𐳋K������ */
		gsVector3Normalize( &pOutNormals[i], &pOutNormals[i] );
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : ���b�V���̕��ʃp�����[�^�̌v�Z������D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
CalculatePlanes
(
	GSmesh*			pMesh				/* ���b�V��					*/
)
{
	GSuint			i;

	/* ���Ƀv���[������������Ă���ꍇ�͏��ł����� */
	if ( pMesh->pPlanes != NULL )
	{
		del_object( pMesh->pPlanes );
	}

	/* ���ʃp�����[�^�̔z��𐶐����� */
	pMesh->pPlanes = new_object( sizeof(GSplane) * ( pMesh->numIndices / 3 ) );

	/* �S�|���S���ƃ��C�̏Փ˔�����s�� */
	for ( i = 0; i < ( pMesh->numIndices / 3 ); i++ )
	{
		/* �|���S���̂R���_���擾���� */
		gsPlaneFromPoints(
			&pMesh->pPlanes[i],
			&pMesh->pPoints[ pMesh->pIndices[i*3+0] ],
			&pMesh->pPoints[ pMesh->pIndices[i*3+1] ],
			&pMesh->pPoints[ pMesh->pIndices[i*3+2] ]
		);
	}
}

/********** End of File ******************************************************/
