/******************************************************************************
* File Name : DrawSprite2D.h                     Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�X�v���C�g2D�`��D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _DRAW_SPRITE2D_H_
#define _DRAW_SPRITE2D_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include <gslib.h>

/// <summary>
/// �Q�c�X�v���C�g�̕`��.
/// </summary>
/// <param name="uTextureID">�e�N�X�`���h�c</param>
/// <param name="pSrcRect">�e�N�`�����̈ʒu</param>
/// <param name="pCenter">�X�v���C�g�̒��S�ʒu</param>
/// <param name="pScaling">�X�P�[���l1.0���W��(�P�{������)</param>
/// <param name="fRotation">��]�p�x(�p�x)</param>
/// <param name="pTranslation">���s�ړ���</param>
/// <param name="pColor">�J���[ (1.0,1.0,10,1.0) = �ω��Ȃ�</param>
void DrawSprite2D(
	/* �e�N�X�`���h�c �@�@  */
	GSuint uTextureID,		
	/* �e�N�`�����̈ʒu		*/
	const GSrect* pSrcRect,		
	/* �X�v���C�g�̒��S�ʒu */
	const GSvector2* pCenter,	
	/* �X�P�[���l			*/
	const GSvector2* pScaling,	
	/* ��]�p�x				*/
	GSfloat fRotation,				
	/* ���s�ړ���			*/
	const GSvector2* pTranslation,
	/* �J���[ �@				*/
	const GScolor* pColor			
);


#endif

/********** End of File ******************************************************/