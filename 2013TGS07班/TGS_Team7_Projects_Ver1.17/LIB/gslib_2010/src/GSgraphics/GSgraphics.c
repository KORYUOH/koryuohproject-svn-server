/******************************************************************************
* File Name : GSgraphics.c                       Ver : 1.00  Date : 2002-07-31
*
* Description :
*
*       �Q�[���V�X�e���p �O���t�B�b�N�X�����D
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

/****** �萔�錾 *************************************************************/

#define	GS_MESH_MAX			1024	/* ���b�V���f�[�^�̍ő吔		*/
#define	GS_SKELETON_MAX		1024	/* �X�P���g���f�[�^�̍ő吔		*/
#define	GS_ANIMATION_MAX	1024	/* �A�j���[�V�����f�[�^�̍ő吔	*/
#define	GS_TEXTURE_MAX		1024	/* �e�N�X�`���f�[�^�̍ő吔		*/
#define	GS_OCTREE_MAX		1024	/* �I�N�c���[�f�[�^�̍ő吔		*/

#define	GS_MATRIX_MAX		256		/* �ϊ��s��̍ő吔				*/

/****** �֐��v���g�^�C�v�錾 *************************************************/

/* ���b�V���C�X�P���g���C�A�j���[�V����,�e�N�X�`���f�[�^ */
static GSmesh*		s_pMeshs[ GS_MESH_MAX ];
static GSskeleton*	s_pSkeletons[ GS_SKELETON_MAX ];
static GSanimation*	s_pAnimations[ GS_ANIMATION_MAX ];
static GStexture*	s_pTextures[ GS_TEXTURE_MAX ];
static GSoctree*	s_pOctrees[ GS_OCTREE_MAX ];

/* �Z���V�F�[�f�B���O�p�p�����[�^ */
static GSvector3	s_CelShadeLightPosition = { 1.0f, 1.0f, 1.0f };
static GSfloat		s_CelShadeLineWidth     = 1.5f;
static GSuint		s_CelShadeTexture       = 0;
static GScolor		s_CelShadeLineColor		= { 0.0f, 0.0f, 0.0f, 1.0f };

/* �e�N�X�`���̃J���[�L�[�̃��[�h */
static GSenum		s_TexColorKeyMode = GS_TEXCOLOR_KEY_DISABLE;
static GSbyte		s_TexColorKeyR = 0;
static GSbyte		s_TexColorKeyG = 0;
static GSbyte		s_TexColorKeyB = 0;

/* �o�C���h���̃X�P���g���i���o */
static GSuint		s_BindSkeleton = 0;

/* �A�j���[�V�����ϊ��s�� */
static GSmatrix4	s_AnimationMatrices[ GS_MATRIX_MAX ];

/* �p���ϊ��s�� */
static GSmatrix4	s_OrientationMatrices[ GS_MATRIX_MAX ];

/* ���W�ϊ��s�� */
static GSmatrix4	s_TransformMatrices[ GS_MATRIX_MAX ];

/* �e���ԃt���O */
static GSboolean	s_bSkinMesh          = GS_TRUE;
static GSboolean	s_bCalculateSkeleton = GS_TRUE;
static GSboolean	s_bCelShade          = GS_FALSE;

/* �����t�H���g��� */
static GSbitfield	s_FontCode     = GS_FONT_NORMAL;
static GSuint		s_FontPoint    = 10;
static char			s_FontName[32] = "�l�r �S�V�b�N";

/* �e�L�X�g�̕\���ʒu */
static GSvector2	s_TextPosition = { 0.0f, 0.0f };

/*=============================================================================
*
* Purpose : �O���t�B�b�N�V�X�e���̏������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsInitGraphics
(
	void
)
{
	GSuint		i;

	/* �e�탊�\�[�X�̏����� */
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

	/* �Z���V�F�[�h�p�����[�^�̏����� */
	gsVector3Init( &s_CelShadeLightPosition, 1.0f, 1.0f, 1.0f );
	s_CelShadeLineWidth = 1.5f;
	s_CelShadeTexture   = 0;
	gsColorInit( &s_CelShadeLineColor, 0.0f, 0.0f, 0.0f, 1.0f );

	/* �e�N�X�`���̃J���[�L�[�̏����� */
	s_TexColorKeyMode = GS_TEXCOLOR_KEY_DISABLE;
	s_TexColorKeyR    = 0;
	s_TexColorKeyG    = 0;
	s_TexColorKeyB    = 0;

	/* �o�C���h���̃X�P���g���̏����� */
	s_BindSkeleton = 0;

	/* �A�j���[�V�����ϊ��s��̏����� */
	for ( i = 0; i < GS_MATRIX_MAX; i++ )
	{
		gsMatrix4Identity( &s_AnimationMatrices[i] );
	}

	/* �p���ϊ��s��̏����� */
	for ( i = 0; i < GS_MATRIX_MAX; i++ )
	{
		gsMatrix4Identity( &s_OrientationMatrices[i] );
	}

	/* ���W�ϊ��s��̏����� */
	for ( i = 0; i < GS_MATRIX_MAX; i++ )
	{
		gsMatrix4Identity( &s_TransformMatrices[i] );
	}

	/* �����t�H���g���̏����� */
	s_FontCode  = GS_FONT_NORMAL;
	s_FontPoint = 10;
	strcpy( s_FontName, "�l�r �S�V�b�N" );

	/* �e�L�X�g�̕\���ʒu�������� */
	s_TextPosition.x = 0.0f;
	s_TextPosition.y = 0.0f;

	/* �e���ԃt���O�̏����� */
	s_bSkinMesh          = GS_TRUE;
	s_bCalculateSkeleton = GS_TRUE;
	s_bCelShade          = GS_FALSE;
}

/*=============================================================================
*
* Purpose : �O���t�B�b�N�V�X�e���̏I�������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsFinishGraphics
(
	void
)
{
	GSuint		i;

	/* �e�탊�\�[�X�̉�����s�� */
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
* Purpose : ���b�V���f�[�^�̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsLoadMesh
(
	GSuint			MeshID,				/* ���b�V���h�c				*/
	const char*		pszMshFileName		/* ���b�V���t�@�C����		*/
)
{
	GSboolean		Result;

	/* ���b�V���f�[�^�����ɑ��݂��邩�H */
	if ( s_pMeshs[ MeshID ] == NULL )
	{
		/* ���b�V���f�[�^�̐��� */
		s_pMeshs[ MeshID ] = gsMeshNew();
	}

	/* ���b�V���f�[�^�̓ǂݍ��� */
	Result = gsMeshLoadFile( s_pMeshs[ MeshID ], pszMshFileName );

	/* �ǂݍ��݂Ɏ��s�����ꍇ�͐����������b�V���f�[�^���폜���� */
	if ( Result == GS_FALSE )
	{
		gsDeleteMesh( MeshID );
	}

	return	Result;
}

/*=============================================================================
*
* Purpose : �X�P���g���f�[�^�t�@�C���̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsLoadSkeleton
(
	GSuint			SkeletonID,			/* �X�P���g���h�c			*/
	const char*		pszSklFileName		/* �X�P���g���t�@�C����		*/
)
{
	GSboolean		Result;

	/* �X�P���g���f�[�^�����ɑ��݂��邩�H */
	if ( s_pSkeletons[ SkeletonID ] == NULL )
	{
		/* �X�P���g���f�[�^�̐��� */
		s_pSkeletons[ SkeletonID ] = gsSkeletonNew();
	}

	/* �X�P���g���f�[�^�̓ǂݍ��� */
	Result = gsSkeletonLoadFile( s_pSkeletons[ SkeletonID ], pszSklFileName );

	/* �ǂݍ��݂Ɏ��s�����ꍇ�͐��������X�P���g���f�[�^���폜���� */
	if ( Result == GS_FALSE )
	{
		gsDeleteSkeleton( SkeletonID );
	}

	return	Result;
}

/*=============================================================================
*
* Purpose : �A�j���[�V�����f�[�^�t�@�C���̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsLoadAnimation
(
	GSuint			AnimationID,		/* �A�j���[�V�����h�c		*/
	const char*		pszAnmFileName		/* �A�j���[�V�����t�@�C����	*/
)
{
	GSboolean		Result;

	/* �A�j���[�V�����f�[�^�����ɑ��݂��邩�H */
	if ( s_pAnimations[ AnimationID ] == NULL )
	{
		/* �A�j���[�V�����f�[�^�̐��� */
		s_pAnimations[ AnimationID ] = gsAnimationNew();
	}

	/* �A�j���[�V�����f�[�^�̓ǂݍ��� */
	Result = gsAnimationLoadFile( s_pAnimations[ AnimationID ], pszAnmFileName );

	/* �ǂݍ��݂Ɏ��s�����ꍇ�͐��������A�j���[�V�����f�[�^���폜���� */
	if ( Result == GS_FALSE )
	{
		gsDeleteAnimation( AnimationID );
	}

	return	Result;
}

/*=============================================================================
*
* Purpose : �e�N�X�`���f�[�^�̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsLoadTexture
(
	GSuint			TextureID,			/* �e�N�X�`���h�c			*/
	const char*		pszTexFileName		/* �e�N�X�`���t�@�C����		*/
)
{
	GSubyte*		pTexcel;
	GSboolean		Result;

	if ( s_pTextures[ TextureID ] == NULL )
	{
		/* �e�N�X�`���f�[�^�̐��� */
		s_pTextures[ TextureID ] = gsTextureNew();
	}

	/* �e�N�X�`���f�[�^�̓ǂݍ��� */
	Result = gsTextureLoadBmpFile( s_pTextures[ TextureID ], pszTexFileName );

	/* �ǂݍ��݂Ɏ��s�����ꍇ�͐��������e�N�X�`���f�[�^���폜���� */
	if ( Result == GS_FALSE )
	{
		gsDeleteTexture( TextureID );

		return	GS_FALSE;
	}

	/* �J���[�L�[��ݒ肷�� */
	switch ( s_TexColorKeyMode )
	{
	case GS_TEXCOLOR_KEY:
		/* �J���[�L�[�̐ݒ� */
		gsTextureSetColorKey
		(
			s_pTextures[ TextureID ],
			s_TexColorKeyR,
			s_TexColorKeyG,
			s_TexColorKeyB
		);
		break;

	case GS_TEXCOLOR_KEY_AUTO:
		/* ����̃e�N�Z�����擾���� */
		pTexcel = gsTextureLock( s_pTextures[ TextureID ] );

		/* ����̃e�N�Z�����J���[�L�[�Ƃ��Đݒ肷�� */
		gsTextureSetColorKey
		(
			s_pTextures[ TextureID ],
			pTexcel[0], pTexcel[1], pTexcel[2]
		);
		break;

	case GS_TEXCOLOR_KEY_BLACK:
		/* �����J���[�L�[�Ƃ��Đݒ肷�� */
		gsTextureSetColorKey( s_pTextures[ TextureID ], 0, 0, 0 );
		break;

	case GS_TEXCOLOR_KEY_WHITE:
		/* �����J���[�L�[�Ƃ��Đݒ肷�� */
		gsTextureSetColorKey( s_pTextures[ TextureID ], 0xff, 0xff, 0xff );
		break;
	}

	return	Result;
}

/*=============================================================================
*
* Purpose : �I�N�c���[�f�[�^�̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsLoadOctree
(
	GSuint			OctreeID,			/* �I�N�c���[�h�c			*/
	const char*		pszOctFileName		/* �I�N�c���[�t�@�C����		*/
)
{
	GSboolean		Result;

	/* �I�N�c���[�f�[�^�����ɑ��݂��邩�H */
	if ( s_pOctrees[ OctreeID ] == NULL )
	{
		/* �I�N�c���[�f�[�^�̐��� */
		s_pOctrees[ OctreeID ] = gsOctreeNew();
	}

	/* �I�N�c���[�f�[�^�̓ǂݍ��� */
	Result = gsOctreeLoadFile( s_pOctrees[ OctreeID ], pszOctFileName );

	/* �ǂݍ��݂Ɏ��s�����ꍇ�͐��������I�N�c���[�f�[�^���폜���� */
	if ( Result == GS_FALSE )
	{
		gsDeleteOctree( OctreeID );
	}

	return	Result;
}

/*=============================================================================
*
* Purpose : �e�N�X�`���f�[�^�̓����F�̎w��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsTextureColorKey
(
	GSubyte			ColorKeyR,			/* �Ԑ���					*/
	GSubyte			ColorKeyG,			/* ����					*/
	GSubyte			ColorKeyB			/* �ΐ���					*/
)
{
	/* �����F�̐ݒ������ */
	s_TexColorKeyR = ColorKeyR;
	s_TexColorKeyG = ColorKeyG;
	s_TexColorKeyB = ColorKeyB;
}

/*=============================================================================
*
* Purpose : �e�N�X�`���f�[�^�̓����F���[�h�̎w��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsTextureColorKeyMode
(
	GSenum			ColorKeyMode		/* �J���[�L�[���[�h			*/
)
{
	/* �����F�̑I����@�̐ݒ� */
	s_TexColorKeyMode = ColorKeyMode;
}

/*=============================================================================
*
* Purpose : ���b�V���f�[�^�̍폜�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDeleteMesh
(
	GSuint			MeshID				/* ���b�V���h�c				*/
)
{
	if ( s_pMeshs[ MeshID ] != NULL )
	{
		/* ���b�V���f�[�^�����ł����� */
		gsMeshDelete( s_pMeshs[ MeshID ] );

		s_pMeshs[ MeshID ] = NULL;
	}
}

/*=============================================================================
*
* Purpose : �X�P���g���f�[�^�̍폜�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDeleteSkeleton
(
	GSuint			SkeletonID			/* �X�P���g���h�c			*/
)
{
	if ( s_pSkeletons[ SkeletonID ] != NULL )
	{
		/* �X�P���g���f�[�^�����ł����� */
		gsSkeletonDelete( s_pSkeletons[ SkeletonID ] );

		s_pSkeletons[ SkeletonID ] = NULL;
	}
}

/*=============================================================================
*
* Purpose : �A�j���[�V�����f�[�^�t�@�C���̍폜�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDeleteAnimation
(
	GSuint			AnimationID			/* �A�j���[�V�����h�c		*/
)
{
	if ( s_pAnimations[ AnimationID ] != NULL )
	{
		/* �A�j���[�V�����f�[�^�����ł����� */
		gsAnimationDelete( s_pAnimations[ AnimationID ] );

		s_pAnimations[ AnimationID ] = NULL;
	}
}

/*=============================================================================
*
* Purpose : �e�N�X�`���f�[�^�t�@�C���̍폜�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDeleteTexture
(
	GSuint			TextureID			/* �e�N�X�`���h�c		*/
)
{
	if ( s_pTextures[ TextureID ] != NULL )
	{
		/* �A�j���[�V�����f�[�^�����ł����� */
		gsTextureDelete( s_pTextures[ TextureID ] );

		s_pTextures[ TextureID ] = NULL;
	}
}

/*=============================================================================
*
* Purpose : �I�N�c���[�f�[�^�̍폜�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDeleteOctree
(
	GSuint			OctreeID				/* �I�N�c���[�h�c		*/
)
{
	if ( s_pOctrees[ OctreeID ] != NULL )
	{
		/* �I�N�c���[�f�[�^�����ł����� */
		gsOctreeDelete( s_pOctrees[ OctreeID ] );

		s_pOctrees[ OctreeID ] = NULL;
	}
}

/*=============================================================================
*
* Purpose : ���b�V���̕`��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDrawMesh
(
	GSuint			MeshID				/* ���b�V���h�c				*/
)
{
	GSskeleton*		pSkeleton;
	GSmesh*			pMesh;

	/* ���b�V���f�[�^���擾���� */
	if ( ( pMesh = s_pMeshs[ MeshID ] ) == NULL )
	{
		return;
	}

	/* �o�C���h���̃X�P���g���̎擾 */
	pSkeleton = s_pSkeletons[ s_BindSkeleton ];

	/* �X�L�j���O���b�V����`�悷�邩�H */
	if ( s_bSkinMesh == GS_TRUE && pSkeleton != NULL )
	{
		/* �X�P���g���̎����v�Z���ݒ肳��Ă��邩�H */
		if ( s_bCalculateSkeleton == TRUE )
		{
			/* �p���ϊ��s��̌v�Z���s�� */
			gsCalculateSkeleton( NULL, s_OrientationMatrices );
		}

		/* �ŏI�I�ȍ��W�ϊ��s����v�Z���� */
		gsSkeletonCalculateTransform
		(
			pSkeleton,
			s_TransformMatrices,
			s_OrientationMatrices
		);

		/* �Z���V�F�[�f�B���O���s�����H */
		if ( s_bCelShade == GS_TRUE )
		{
			/* �Z���V�F�[�f�B���O���g���ĕ`�悷�� */
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
			/* ���b�V����`�悷�� */
			gsMeshDrawSkin( pMesh, s_TransformMatrices );
		}
	}
	else
	{
		/* �Z���V�F�[�f�B���O���s�����H */
		if ( s_bCelShade == GS_TRUE )
		{
			/* �Z���V�F�[�f�B���O���g���ă��b�V����`�悷�� */
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
			/* ���b�V����`�悷�� */
			gsMeshDraw( pMesh );
		}
	}
}

/*=============================================================================
*
* Purpose : �I�N�c���[�̕`��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDrawOctree
(
	GSuint			OctreeID				/* �I�N�c���[�h�c				*/
)
{
	GSoctree*		pOctree;

	/* �I�N�c���[�f�[�^���擾���� */
	if ( ( pOctree = s_pOctrees[ OctreeID ] ) == NULL )
	{
		return;
	}

	/* �I�N�c���[�̕`�� */
	gsOctreeDraw( pOctree );
}

/*=============================================================================
*
* Purpose : �e�N�X�`�����o�C���h����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsBindTexture
(
	GSuint			TextureID			/* �e�N�X�`���h�c			*/
)
{
	GStexture*		pTexture;

	if ( ( pTexture = s_pTextures[ TextureID ] ) == NULL )
	{
		return;
	}

	/* �e�N�X�`�����o�C���h���� */
	gsTextureBind( s_pTextures[ TextureID ] );

	/* �e�N�X�`����L���ɂ��� */
	glEnable( GL_TEXTURE_2D );
}

/*=============================================================================
*
* Purpose : �X�P���g�����o�C���h����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsBindSkeleton
(
	GSuint			SkeletonID			/* �X�P���g���h�c			*/
)
{
	/* �X�P���g�����o�C���h���� */
	s_BindSkeleton = SkeletonID;
}

/*=============================================================================
*
* Purpose : �A�j���[�V�������o�C���h����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsBindAnimation
(
	GSuint			AnimationID,		/* �A�j���[�V�����h�c		*/
	GSuint			AnimationNo,		/* �A�j���[�V�����i���o		*/
	GSfloat			fTimer				/* �A�j���[�V�����^�C�}		*/
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

	/* �A�j���[�V�����f�[�^�����݂��邩�H */
	if ( ( pAnimation = s_pAnimations[ AnimationID ] ) == NULL )
	{
		/* �A�j���[�V�������擾�ł��Ȃ������ꍇ�͑S�ĒP�ʍs���ݒ肷�� */
		for ( BoneNo = 0; BoneNo < GS_MATRIX_MAX; BoneNo++ )
		{
			gsMatrix4Identity( &s_AnimationMatrices[ BoneNo ] );

		}
		return;
	}

	/* �{�[���f�[�^�����擾���� */
	numBones = gsAnimationGetNumBones( pAnimation, AnimationNo );

	/* �A�j���[�V�����ϊ��s��ɐݒ肷�� */
	for ( BoneNo = 0; BoneNo < numBones; BoneNo++ )
	{
		/* �L�[�t���[���f�[�^���擾���� */
		gsAnimationGetKeyFrame
		(
			pAnimation,
			AnimationNo, BoneNo, fTimer,
			&Scale, &Rotate, &Position
		);

		/* �e�L�[���s��ɕϊ����� */
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
* Purpose : �A�j���[�V�������o�C���h����D�i ���`��� �j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsBindAnimationLerp
(
	GSuint			AnimationID1,		/* �A�j���[�V�����h�c		*/
	GSuint			AnimationNo1,		/* �A�j���[�V�����i���o		*/
	GSfloat			fTimer1,			/* �A�j���[�V�����^�C�}		*/
	GSuint			AnimationID2,		/* �A�j���[�V�����h�c		*/
	GSuint			AnimationNo2,		/* �A�j���[�V�����i���o		*/
	GSfloat			fTimer2,			/* �A�j���[�V�����^�C�}		*/
	GSfloat			fLerp				/* ��Ԓl					*/
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

	/* �Q�̃A�j���[�V�����f�[�^���擾���� */
	if ( ( pAnimation1 = s_pAnimations[ AnimationID1 ] ) == NULL )
	{
		return;
	}
	if ( ( pAnimation2 = s_pAnimations[ AnimationID2 ] ) == NULL )
	{
		/* ��Ԑ悪�Ȃ��ꍇ�̓A�j���[�V�����P�̂݃o�C���h */
		gsBindAnimation( AnimationID1, AnimationNo1, fTimer1 );

		return;
	}

	/* �{�[���f�[�^�����擾���� */
	numBones = gsAnimationGetNumBones( pAnimation1, AnimationNo1 );

	/* �A�j���[�V�����ϊ��s��ɐݒ肷�� */
	for ( BoneNo = 0; BoneNo < numBones; BoneNo++ )
	{
		/* �L�[�t���[���f�[�^���擾���� */
		gsAnimationGetKeyFrame
		(
			pAnimation1,
			AnimationNo1, BoneNo, fTimer1,
			&Scale1, &Rotate1, &Position1
		);
		/* �L�[�t���[���f�[�^���擾���� */
		gsAnimationGetKeyFrame
		(
			pAnimation2,
			AnimationNo2, BoneNo, fTimer2,
			&Scale2, &Rotate2, &Position2
		);

		/* �e�L�[����`��Ԃ��� */
		gsVector3Lerp( &Scale, &Scale1, &Scale2, fLerp );
		gsQuaternionSlerp( &Rotate, &Rotate1, &Rotate2, fLerp );
		gsVector3Lerp( &Position, &Position1, &Position2, fLerp );

		/* �e�L�[���s��ɕϊ����� */
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
* Purpose : �Z���V�F�[�f�B���O�p�e�N�X�`�����o�C���h����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsBindCelShadeTexture
(
	GSuint			TextureID			/* �e�N�`���h�c				*/
)
{
	/* �Z���V�F�[�f�B���O�p�e�N�X�`���̃o�C���h */
	s_CelShadeTexture = TextureID;
}

/*=============================================================================
*
* Purpose : �Z���V�F�[�f�B���O�p���C�g�̐ݒ������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsLightPositionCelShade
(
	GSfloat			LightPositionX,		/* ���C�g�����W 			*/
	GSfloat			LightPositionY,		/* ���C�g�����W 			*/
	GSfloat			LightPositionZ		/* ���C�g�����W 			*/
)
{
	s_CelShadeLightPosition.x = LightPositionX;
	s_CelShadeLightPosition.y = LightPositionY;
	s_CelShadeLightPosition.z = LightPositionZ;
}

/*=============================================================================
*
* Purpose : �Z���V�F�[�f�B���O�̗֊s���̑�����ݒ肷��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsLineWidthCelShade
(
	GSfloat			LineWidth			/* �֊s���̑���				*/
)
{
	s_CelShadeLineWidth = LineWidth;
}

/*=============================================================================
*
* Purpose : �Z���V�F�[�f�B���O�̗֊s���̃J���[��ݒ肷��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsLineColorCelShade
(
	GSfloat			LineColorR,			/* �֊s���̐F�̐Ԑ���		*/
	GSfloat			LineColorG,			/* �֊s���̐F�̗ΐ���		*/
	GSfloat			LineColorB,			/* �֊s���̐F�̐���		*/
	GSfloat			LineColorA			/* �֊s���̃A���t�@����		*/
)
{
	s_CelShadeLineColor.r = LineColorR;
	s_CelShadeLineColor.g = LineColorG;
	s_CelShadeLineColor.b = LineColorB;
	s_CelShadeLineColor.a = LineColorA;
}

/*=============================================================================
*
* Purpose : �X�P���g���f�[�^�̎p���ϊ��s����v�Z����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsCalculateSkeleton
(
	GSmatrix4*		pParentMatrix,		/* �e�̃��f�����O�ϊ��s��	*/
	GSmatrix4*		pOrientMatrices		/*-> �p���ϊ��s��z��		*/
)
{
	GSskeleton*		pSkeleton;

	/* �X�P���g���f�[�^���擾����*/
	if ( ( pSkeleton = s_pSkeletons[ s_BindSkeleton ] ) != NULL )
	{
		/* �X�P���g���f�[�^����p���ϊ��s����v�Z���� */
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
* Purpose : �X�P���g���̎p���ϊ��s���ݒ肷��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSetMatrixOrientation
(
	GSuint			numMatrices,		/* ���W�ϊ��s��			*/
	GSmatrix4*		pOrientMatrices		/* ���W�ϊ��s��z��			*/
)
{
	GSuint			i;

	/* �ϊ��s��̐ݒ������ */
	for ( i = 0; i < numMatrices; i++ )
	{
		s_OrientationMatrices[i] = pOrientMatrices[i];
	}
}

/*=============================================================================
*
* Purpose : �X�P���g���f�[�^�̃{�[�������擾����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSuint
gsGetSkeletonNumBones
(
	GSuint		SkeletonID				/* �X�P���g���̂h�c 		*/
)
{
	GSskeleton*	pSkeleton;

	if ( ( pSkeleton = s_pSkeletons[ SkeletonID ] ) == NULL )
	{
		return	0;
	}

	/* �X�P���g���f�[�^����{�[�������擾���� */
	return	gsSkeletonGetNumBones( pSkeleton );
}

/*=============================================================================
*
* Purpose : �A�j���[�V�����̏I���^�C�}���擾����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSuint
gsGetEndAnimationTimer
(
	GSuint		AnimationID,			/* �A�j���[�V�����̂h�c		*/
	GSuint		AnimationNo				/* �A�j���[�V�����i���o		*/
)
{
	GSanimation*	pAnimation;

	if ( ( pAnimation = s_pAnimations[ AnimationID ] ) == NULL )
	{
		return	0;
	}

	/* �A�j���[�V�����f�[�^����A�j���[�V�����̏I���^�C�}���擾 */
	return	gsAnimationGetEndTimer( pAnimation, AnimationNo );
}

/*=============================================================================
*
* Purpose : �����t�H���g�̃p�����[�^��ݒ肷��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsTextPos
(
	GSfloat		PositoinX,		/* �����W					*/
	GSfloat		PositoinY		/* �����W					*/
)
{
	s_TextPosition.x = PositoinX;
	s_TextPosition.y = PositoinY;
}

/*=============================================================================
*
* Purpose : �����t�H���g�̃p�����[�^��ݒ肷��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsFontParameter
(
	GSbitfield	FontCode,		/* �����t�H���g�̑���		*/
	GSuint		FontPoint,		/* �����t�H���g�̃|�C���g��	*/
	const char*	pszFontName		/* �����t�H���g��			*/
)
{
	/* �����t�H���g�̑�����ݒ� */
	s_FontCode = FontCode;

	/* �����t�H���g�̃|�C���g����ݒ� */
	s_FontPoint = FontPoint;

	/* �����t�H���g���̐ݒ� */
	strcpy( s_FontName, pszFontName );
}

/*=============================================================================
*
* Purpose : �e�L�X�g�`��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDrawText
(
	const char*	pString,			/* �\�����镶����		*/
	...								/* �I�v�V�����̈���		*/
)
{
	char		String[512];		/* �\��������o�b�t�@	*/
	GLint		ViewPort[4];
	va_list		ArgList;

	/* �ϒ������̎g�p�J�n */
	va_start( ArgList, pString );

	/* ������̃t�H�[�}�b�g�ϊ����s�� */
	vsprintf( String, pString, ArgList );

	/* �ϐ������̎g�p�I�� */
	va_end( ArgList );

	/* �e��ݒ�t���O�̑ޔ� */
	glPushAttrib( GL_ENABLE_BIT );

	/* ���C�e�B���O�𖳌��ɂ��� */
	glDisable( GL_LIGHTING );

	/* ���o�b�t�@�𖳌��ɂ��� */
	glDisable( GL_DEPTH_TEST );

	/* �ʃJ�����O�𖳌��ɂ��� */
	glDisable( GL_CULL_FACE );

	/* �����ϊ��s��̑ޔ� */
	glMatrixMode( GL_PROJECTION );
	glPushMatrix();

	/* �r���[�|�[�g�̎擾 */
	glGetIntegerv( GL_VIEWPORT, ViewPort );

	/* �����ϊ��s��̐ݒ� */
	glLoadIdentity();
	gluOrtho2D( 0, ViewPort[2], ViewPort[3], 0 );

	/* ���f���r���[�ϊ��s��̑ޔ� */
	glMatrixMode( GL_MODELVIEW );
	glPushMatrix();

	/* �ϊ��s��̏����� */
	glLoadIdentity();

	/* �e�L�X�g�̈ʒu��ݒ肷�� */
	glRasterPos2f( s_TextPosition.x, s_TextPosition.y );

	/* �e�L�X�g��`�悷�� */
	gsTextDraw
	(
		s_FontCode,			/* �t�H���g�R�[�h		*/
		s_FontPoint,		/* �t�H���g�̃|�C���g��	*/
		s_FontName,			/* �t�H���g��			*/
		String				/* ������				*/
	);

	/* ���f���r���[�ϊ��s��𕜋A */
	glPopMatrix();

	/* �����ϊ��s��𕜋A */
	glMatrixMode( GL_PROJECTION );
	glPopMatrix();

	/* ���f���r���[�ϊ��s��ɐݒ� */
	glMatrixMode( GL_MODELVIEW );

	/* �e��ݒ�t���O�̕��A */
	glPopAttrib();
}

/*=============================================================================
*
* Purpose : �X�N���[�����W���烌�C���v�Z����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsCalculateRay
(
	GSint		ScreenX,				/* �X�N���[�������W		*/
	GSint		ScreenY,				/* �X�N���[�������W		*/
	GSfloat*	pRayPosX,				/*-> ���C�̂����W		*/
	GSfloat*	pRayPosY,				/*-> ���C�̂����W		*/
	GSfloat*	pRayPosZ,				/*-> ���C�̂����W		*/
	GSfloat*	pRayDirX,				/*-> ���C�̃x�N�g��		*/
	GSfloat*	pRayDirY,				/*-> ���C�̃x�N�g��		*/
	GSfloat*	pRayDirZ				/*-> ���C�̃x�N�g��		*/
)
{
	GSvector3	Pos;
	GSvector3	Dir;
	GSvector2	Window;
	GSmatrix4	matProj;
	GSmatrix4	matView;
	GLint		ViewPort[4];

	/* �r���[�|�[�g�̎擾 */
	glGetIntegerv( GL_VIEWPORT, ViewPort );

	/* �����ϊ��s��̎擾 */
	glGetFloatv( GL_PROJECTION_MATRIX, (GLfloat*)&matProj );

	/* ���_�ϊ��s��̎擾 */
	glGetFloatv( GL_MODELVIEW_MATRIX, (GLfloat*)&matView );

	/* �}�E�X�J�[�\���̍��W���E�B���h�E���W�ɕϊ� */
	Window.x = (GSfloat)ScreenX;
	Window.y = ViewPort[3] - (GSfloat)ScreenY;

	/* �r���[�|�[�g�ϊ��̋t�ϊ����s�� */
	Pos.x = ( ( ( Window.x - ViewPort[0] ) * 2.0f / ViewPort[2] ) - 1.0f );
	Pos.y = ( ( ( Window.y - ViewPort[1] ) * 2.0f / ViewPort[3] ) - 1.0f );

	/* �����ϊ��̋t�ϊ����s�� */
	Pos.x /= matProj.m[0][0];
	Pos.y /= matProj.m[1][1];
	Pos.z = -1.0f;

	/* ����ϊ��s��̋t�s������߂� */
	gsMatrix4InverseFast( &matView, &matView );

	/* ����ϊ��̋t�ϊ����s�� */
	gsVector3TransformNormal( &Dir, &Pos, &matView );

	/* ���C�̈ʒu��ݒ� */
	*pRayPosX = matView.m[3][0];
	*pRayPosY = matView.m[3][1];
	*pRayPosZ = matView.m[3][2];

	/* ���C�̕����𐳋K������ */
	gsVector3Normalize( &Dir, &Dir );

	/* ���C�̕�����ݒ肷�� */
	*pRayDirX = Dir.x;
	*pRayDirY = Dir.y;
	*pRayDirZ = Dir.z;
}

/*=============================================================================
*
* Purpose : ���b�V���f�[�^�̎擾�D
*
* Return  : ���b�V���f�[�^�̃|�C���^��Ԃ��D
*
*============================================================================*/
extern GSmesh*
gsGetMesh
(
	GSuint			MeshID				/* ���b�V���h�c				*/
)
{
	return	s_pMeshs[ MeshID ];
}

/*=============================================================================
*
* Purpose : �X�P���g���f�[�^�̎擾�D
*
* Return  : �X�P���g���f�[�^�̃|�C���^��Ԃ��D
*
*============================================================================*/
extern GSskeleton*
gsGetSkeleton
(
	GSuint			SkeletonID			/* �X�P���g���h�c			*/
)
{
	return	s_pSkeletons[ SkeletonID ];
}

/*=============================================================================
*
* Purpose : �A�j���V���[���f�[�^�̎擾�D
*
* Return  : �A�j���[�V�����f�[�^�̃|�C���^��Ԃ��D
*
*============================================================================*/
extern GSanimation*
gsGetAnimation
(
	GSuint			AnimationID			/* �A�j���[�V�����h�c		*/
)
{
	return	s_pAnimations[ AnimationID ];
}

/*=============================================================================
*
* Purpose : �I�N�c���[�f�[�^�̎擾�D
*
* Return  : �I�N�c���[�f�[�^�̃|�C���^��Ԃ��D
*
*============================================================================*/
extern GSoctree*
gsGetOctree
(
	GSuint			OctreeID			/* �I�N�c���[�h�c		*/
)
{
	return	s_pOctrees[ OctreeID ];
}

/*=============================================================================
*
* Purpose : �e�N�X�`���f�[�^�̎擾�D
*
* Return  : �e�N�X�`���f�[�^�̃|�C���^��Ԃ��D
*
*============================================================================*/
extern GStexture*
gsGetTexture
(
	GSuint			TextureID			/* �e�N�X�`���h�c		*/
)
{
	return	s_pTextures[ TextureID ];
}

/*=============================================================================
*
* Purpose : ����@�\�̗L�����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsEnable
(
	GSenum		Cap					/* ����@�\�������V���{���萔 */
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
* Purpose : ����@�\�̖������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDisable
(
	GSenum		Cap					/* ����@�\�������V���{���萔 */
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
