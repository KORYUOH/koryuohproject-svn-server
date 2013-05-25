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
#include"DrawSprite2D.h"
#include"../Utility/Screen.h"

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
void
DrawSprite2D(
	GSuint uTextureID,				/* �e�N�X�`���h�c �@�@  */
	const GSrect* pSrcRect,			/* �e�N�`�����̈ʒu		*/
	const GSvector2* pCenter,		/* �X�v���C�g�̒��S�ʒu */
	const GSvector2* pScaling,		/* �X�P�[���l1.0���W��(�P�{������)			*/
	GSfloat fRotation,				/* ��]�p�x(�p�x)				*/
	const GSvector2* pTranslation,	/* ���s�ړ���			*/
	const GScolor* pColor			/* �J���[ (1.0,1.0,10,1.0) = �ω��Ȃ��@		*/
) {
	GSrect rTexCoord;
	GLfloat fWidth;
	GLfloat fHeight;
	GLsizei sTexWidth;
	GLsizei sTexHeight;
	GScolor CurrentColor;
	/* �e�탌���_�����O���[�h�̑ޔ� */
	glPushAttrib( GL_ENABLE_BIT );
	/* ���C�e�B���O�𖳌��ɂ��� */
	glDisable( GL_LIGHTING );
	/* ���o�b�t�@�𖳌��ɂ��� */
	glDisable( GL_DEPTH_TEST );
	/* �ʃJ�����O�𖳌��ɂ��� */
	glDisable( GL_CULL_FACE );
	/* �J�����g�J���[���擾���� */
	glGetFloatv( GL_CURRENT_COLOR, (GLfloat*)&CurrentColor );
	/* �e�N�X�`�����o�C���h���� */
	gsBindTexture( uTextureID );
	/* �����ϊ��s��̑ޔ� */
	glMatrixMode( GL_PROJECTION );
	glPushMatrix();
	/* �����ϊ��s��̐ݒ� */
	glLoadIdentity();
	gluOrtho2D( 0, Screen::WIDTH, Screen::HEIGHT, 0 );
	/* ���f���r���[�ϊ��s��̑ޔ� */
	glMatrixMode( GL_MODELVIEW );
	glPushMatrix();
	/* �ϊ��s��̏����� */
	glLoadIdentity();
	/* ���s�ړ��ʂ̐ݒ���s�� */
	if ( pTranslation != NULL ) {
		glTranslatef( pTranslation->x, pTranslation->y, 0 );
	}
	/* ��]�p�x�̐ݒ���s�� */
	glRotatef( fRotation, 0.0f, 0.0f, 1.0f );
	/* �g��k�����s�� */
	if ( pScaling != NULL ) {
		glScalef( pScaling->x, pScaling->y, 0.0f );
	}
	/* ���S�ʒu�̕␳���s�� */
	if ( pCenter != NULL ) {
		glTranslatef( -pCenter->x, -pCenter->y, 0 );
	}
	/* ���_�J���[�̐ݒ� */
	if ( pColor != NULL ) {
		glColor4fv( (GLfloat*)pColor );
	}
	/* �o�C���h���̃e�N�X�`���̕��ƍ������擾 */
	glGetTexLevelParameteriv( GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &sTexWidth );
	glGetTexLevelParameteriv( GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &sTexHeight );
	if ( pSrcRect != NULL ) {
		/* �e�N�X�`�����W�̌v�Z���s�� */
		rTexCoord.left = pSrcRect->left / sTexWidth;
		rTexCoord.top = pSrcRect->top / sTexHeight;
		rTexCoord.right = pSrcRect->right / sTexWidth;
		rTexCoord.bottom = pSrcRect->bottom / sTexHeight;
		/* �l�p�`�̕��ƍ��������߂�*/
		fWidth = ABS( pSrcRect->right - pSrcRect->left );
		fHeight = ABS( pSrcRect->bottom - pSrcRect->top );
	} else {
		/* �e�N�X�`�����̈ʒu���w�肳��Ă��Ȃ��ꍇ�̓e�N�X�`����S�̕\�� */
		rTexCoord.left = 0.0f;
		rTexCoord.top = 0.0f;
		rTexCoord.right = 1.0f;
		rTexCoord.bottom = 1.0f;
		fWidth = (GLfloat)sTexWidth;
		fHeight = (GLfloat)sTexHeight;
	}
	/* �l�p�`�̕`�� */
	glBegin( GL_QUADS );
		glTexCoord2f( rTexCoord.left, rTexCoord.top );
		glVertex2f( 0, 0 );
		glTexCoord2f( rTexCoord.left, rTexCoord.bottom );
		glVertex2f( 0, fHeight );
		glTexCoord2f( rTexCoord.right, rTexCoord.bottom );
		glVertex2f( fWidth, fHeight );
		glTexCoord2f( rTexCoord.right, rTexCoord.top );
		glVertex2f( fWidth, 0 );
	glEnd();
	/* ���f���r���[�ϊ��s��𕜋A */
	glPopMatrix();
	/* �����ϊ��s��𕜋A */
	glMatrixMode( GL_PROJECTION );
	glPopMatrix();
	/* ���f���r���[�ϊ��s��ɐݒ� */
	glMatrixMode( GL_MODELVIEW );
	/* �J�����g�J���[�𕜋A���� */
	glColor4fv( (GLfloat*)&CurrentColor );
	/* �����_�����O���[�h�̕��A */
	glPopAttrib();
}


/********** End of File ******************************************************/

