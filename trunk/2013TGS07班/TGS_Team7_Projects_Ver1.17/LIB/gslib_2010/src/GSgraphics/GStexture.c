/******************************************************************************
* File Name : gtexture.c                         Ver : 1.00  Date : 2002-08-13
*
* Description :
*
*       �e�N�X�`���Ǘ��D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GStexture.h"
#include	"heap.h"
#include	<memory.h>

/*=============================================================================
*
* Purpose : �e�N�X�`���̐����D
*
* Return  : �e�N�X�`����Ԃ��D
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
* Purpose : �e�N�X�`���̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsTextureDelete
(
	GStexture*		pTexture			/* �e�N�X�`�� 			*/
)
{
	gsTextureCleanUP( pTexture );

	/* �e�N�X�`���̏��� */
	del_object( pTexture );
}

/*=============================================================================
*
* Purpose : �e�N�X�`���̃N���[���A�b�v�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsTextureCleanUP
(
	GStexture*		pTexture			/* �e�N�X�`�� 			*/
)
{
	/* �e�N�`���C���[�W�̍폜 */
	if ( pTexture->pImage != NULL )
	{
		del_object( pTexture->pImage );

		/* �e�N�X�`���I�u�W�F�N�g�̍폜 */
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
* Purpose : �e�N�X�`���̏������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsTextureInitialize
(
	GStexture*		pTexture,			/* �e�N�X�`�� 				*/
	GStexformat		Format,				/* �e�N�X�`���t�H�[�}�b�g	*/
	GSuint			dwWidth,			/* �e�N�X�`���̕�			*/
	GSuint			dwHeight			/* �e�N�X�`���̍���			*/
)
{
	size_t			size;

	/* �e�N�`���̃N���[���A�b�v */
	gsTextureCleanUP( pTexture );

	/* �e�N�X�`���t�H�[�}�b�g�̐ݒ� */
	pTexture->Format = Format;

	/* �C���[�W�T�C�Y�����߂� */
	if ( ( size = sizeof(GSuint) * dwWidth * dwHeight ) == 0 )
	{
		return;
	}

	/* �e�N�X�`���̕��ƍ�����ݒ� */
	pTexture->dwWidth  = dwWidth;
	pTexture->dwHeight = dwHeight;

	/* �e�N�X�`���C���[�W�̐���*/
	pTexture->pImage = new_object( sizeof(GSuint) * dwWidth * dwHeight );

	/* �����ݒ�ł͔� */
	memset( pTexture->pImage, 0xff, size );

	/* �e�N�X�`�����𐶐� */
	glGenTextures( 1, &pTexture->dwTexName );

	glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );

	/* �e�N�`���I�u�W�F�N�g���o�C���h���� */
	glBindTexture( GL_TEXTURE_2D, pTexture->dwTexName );

	/* �e�N�X�`���C���[�W��ݒ� */
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

	/* �e�N�`���p�����[�^�̐ݒ� */
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
}

/*=============================================================================
*
* Purpose : �e�N�X�`���t�H�[�}�b�g�̎擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GStexformat
gsTextureGetFormat
(
	GStexture*		pTexture			/* �e�N�X�`�� 				*/
)
{
	return	pTexture->Format;
}

/*=============================================================================
*
* Purpose : �e�N�X�`���̕��̎擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSuint
gsTextureGetWidth
(
	GStexture*		pTexture			/* �e�N�X�`�� 				*/
)
{
	return	pTexture->dwWidth;
}

/*=============================================================================
*
* Purpose : �e�N�X�`���̍����̎擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSuint
gsTextureGetHeight
(
	GStexture*		pTexture			/* �e�N�X�`�� 				*/
)
{
	return	pTexture->dwHeight;
}

/*=============================================================================
*
* Purpose : �e�N�X�`�����̎擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsTextureBind
(
	GStexture*		pTexture			/* �e�N�X�`�� 				*/
)
{
	/* �e�N�`���I�u�W�F�N�g���o�C���h���� */
	glBindTexture( GL_TEXTURE_2D, pTexture->dwTexName );
}

/*=============================================================================
*
* Purpose : �e�N�X�`���C���[�W�̃��b�N�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void*
gsTextureLock
(
	GStexture*		pTexture			/* �e�N�X�`�� 				*/
)
{
	return	pTexture->pImage;
}

/*=============================================================================
*
* Purpose : �e�N�X�`���C���[�W�̃A�����b�N�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsTextureUnLock
(
	GStexture*		pTexture			/* �e�N�X�`�� 				*/
)
{
	if ( pTexture->pImage != NULL )
	{
		/* �e�N�X�`���C���[�W�̍X�V */
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
* Purpose : �e�N�X�`���̃J���[�L�[��ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsTextureSetColorKey
(
	GStexture*		pTexture,			/* �e�N�X�`�� 				*/
	GSubyte			Red,				/* �J���[�L�[�Ԑ���			*/
	GSubyte			Green,				/* �J���[�L�[�ΐ���			*/
	GSubyte			Blue				/* �J���[�L�[����			*/
)
{
	GSubyte*		pImage;
	GSuint			i;

	if ( pTexture->pImage == NULL || pTexture->Format != GS_TEX_RGBA )
	{
		return;
	}

	/* �e�N�X�`���C���[�W�����b�N���� */
	pImage = (GSubyte*)gsTextureLock( pTexture );

	for ( i = 0; i < ( pTexture->dwWidth * pTexture->dwHeight ); i++ )
	{
		/* �J���[�L�[�ƃC���[�W�̃s�N�Z�������������H */
		pImage[3] = 0xff;
		if ( Red   == pImage[0]
		  && Green == pImage[1]
		  && Blue  == pImage[2] )
		{
			/* �J���[�L�[�Ɠ������ꍇ�͓����ɂ��� */
			pImage[3] = 0;
		}
		pImage += 4;
	}

	/* �e�N�X�`���C���[�W���A�����b�N���� */
	gsTextureUnLock( pTexture );
}

/********** End of File ******************************************************/
