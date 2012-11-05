/**===File Commentary=======================================*/
/**
 *	@file	Sprite3D.cpp
 *
 *	@brief	�񎟌��`������N���X
 *
 *	@author	keisuke Ito
 *
 *	@date	2012/10/11
 */
/**===File Include=========================================*/

#include <Sprite/Sprite2D/Sprite2D.h>
#include <gslib.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�e�N�X�`���[ID
 *	@author	Keisuke Ito
 */
/**========================================================*/

Sprite2D::Sprite2D(GLuint textureID,float x_, float y_,const Rect& rect)
	:mTextureID(textureID)
	,mPosition(x_,y_)
	,mRect(rect)
	,mCenter(0.0f,0.0f)
	,mScale(1.0f,1.0f)
	,mRotation(0.0f)
	,mColor(1.0f,1.0f,1.0f,1.0f)
	,mTexCoord(0.0f,0.0f,1.0f,1.0f)
{
	if(rect.mSize.x_<0||rect.mSize.y_<0){
		mRect.mSize.x_ = gsTextureGetWidth(gsGetTexture(textureID));
		mRect.mSize.y_ = gsTextureGetHeight(gsGetTexture(textureID));
	}
}

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�e�N�X�`���[ID
 *	@param[in]�@���W��x
 *	@param[in]�@���W��y
 *	@param[in]�@�\������摜�̉��T�C�Y
 *	@param[in]  �\������摜�̏c�̃T�C�Y
 *	@param[in]  �p�x
 *	@author	Keisuke Ito
 */
/**========================================================*/

Sprite2D::Sprite2D(GLuint textureID,float x_, float y_, float sizeX, float sizeY, float rotation)
	:mTextureID(textureID)
	,mPosition(x_,y_)
	,mRect(0.0f,0.0f,sizeX,sizeY)
	,mCenter(0.0f,0.0f)
	,mScale(1.0f,1.0f)
	,mRotation(rotation)
	,mColor(1.0f,1.0f,1.0f,1.0f)
	,mTexCoord(0.0f,0.0f,1.0f,1.0f)
{
}

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�e�N�X�`���[ID
 *	@author	KORYUOH
 */
/**========================================================*/
Sprite2D::Sprite2D(unsigned int textureID,const Vector2& position,float rotate,const Vector2& scale,const Rect & rect)
	:mTextureID(textureID)
	,mPosition(position)
	,mRotation(rotate)
	,mRect(rect)
	,mCenter(0.0f,0.0f)
	,mScale(scale)
	,mColor(1.0f,1.0f,1.0f,1.0f)
	,mTexCoord(0.0f,0.0f,1.0f,1.0f)
{
	if(rect.mSize.x_ <= 0&& rect.mSize.y_ <= 0){
		mRect.mSize.x_ = gsTextureGetWidth(gsGetTexture(textureID));
		mRect.mSize.y_ = gsTextureGetHeight(gsGetTexture(textureID));
	}
}



/**
	 *	@brief	�ʒu�̐ݒ�
	 *	@param[in]	�ʒu
	 *	@author	Keisuke Ito
	 */
	void Sprite2D::setPosition(const Vector2& position)
	{
		mPosition = position;
	}

	/**
	 *	@brief	�g�k�̐ݒ�
	 *	@param[in]	�g�嗦
	 *	@author	Keisuke Ito
	 */
	void Sprite2D::setScale(const Vector2& scale)
	{
		mScale = scale;
	}


	/**
	 *	@brief	��]�̐ݒ�
	 *	@param[in]	��]�p
	 *	@author	KORYUOH
	 */
	void Sprite2D::setRotate(float  rotate)
	{
		mRotation = rotate;
	}

	/**
	 *	@brief	��`
	 *	@param[in]	��`
	 *	@author	Keisuke Ito
	 */
	void Sprite2D::setRect(const Rect& rect)
	{
		mRect = rect;
	}


	/**
	 *	@brief	�`��͈͐ݒ�
	 *	@param[in]	�`��͈�
	 *	@author	Keisuke Ito
	 */
	void Sprite2D::setImageRect(const Rect& rect)
	{
		// �e�N�X�`�����o�C���h����
		gsBindTexture( mTextureID );

		// �o�C���h���̃e�N�X�`���̕��ƍ������擾����
		GLint width, height;
		glGetTexLevelParameteriv( GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH,  &width  );
		glGetTexLevelParameteriv( GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height );

		// �e�N�X�`�����W�̌v�Z���s��
		mTexCoord.mPos.x_	= rect.left() / width;
		mTexCoord.mPos.y_	= rect.top() / height;
		mTexCoord.mSize.x_	= rect.right() / width;
		mTexCoord.mSize.y_	= rect.bottom() / height;
	}




void Sprite2D::draw()
{
	// �e�탌���^�����O���[�h�̑ޔ�
	glPushAttrib( GL_ENABLE_BIT );

	// ���C�e�B���O�𖳌��ɂ���
	glDisable( GL_LIGHTING );

	// ���o�b�t�@�𖳌��ɂ���
	glDisable( GL_DEPTH_TEST );

	// �ʃJ�����O�𖳌��ɂ���
	glDisable( GL_CULL_FACE );

	// �J�����g�J���[���擾����
	Color4	CurrentColor;
	glGetFloatv( GL_CURRENT_COLOR, (GLfloat*)&CurrentColor );

	// �e�N�X�`�����o�C���h����
	gsBindTexture( mTextureID );

	// �����ϊ��s��̑ޔ�
	glMatrixMode( GL_PROJECTION );
	glPushMatrix();

	// �����ϊ��s��̐ݒ�
	glLoadIdentity();
	gluOrtho2D( 0, 1024, 768, 0 );

	// ���f���r���[�ϊ��s��̑ޔ�
	glMatrixMode( GL_MODELVIEW );
	glPushMatrix();

	// �ϊ��s��̏�����
	glLoadIdentity();

	// ���W�̐ݒ���s��
	glTranslatef( mPosition.x_, mPosition.y_, 0.0f );

	// �g��E�k���̐ݒ���s��
	glTranslatef( -mCenter.x_, -mCenter.y_, 0.0f );

	// ��]�p�x�̐ݒ���s��
	glRotatef( mRotation, 0.0f, 0.0f, 1.0f );

	// �g��E�k���̐ݒ���s��
	glScalef( mScale.x_, mScale.y_, 0.0f );

	// �e�N�X�`���J���[�̐ݒ���s��
	glColor4fv( (GLfloat*)& mColor );

	// �l�p�`��`��
	drawQuad();

	// ���f���r���[�ϊ��s��𕜋A
	glPopMatrix();

	// �����ϊ��s��𕜋A
	glMatrixMode( GL_PROJECTION );
	glPopMatrix();

	// ���f���r���[�ϊ��s��ɐݒ�
	glMatrixMode( GL_MODELVIEW );

	// �J�����g�J���[�𕜋A����
	glColor4fv( (GLfloat*)& CurrentColor );

	// �����_�����O���[�h�̕��A
	glPopAttrib();
}


void Sprite2D::drawQuad()
{
	glBegin( GL_QUADS );
	glTexCoord2f( mTexCoord.left(), mTexCoord.top() );
		glVertex2f( mRect.left(), mRect.top() );
		glTexCoord2f( mTexCoord.left(), mTexCoord.bottom());
		glVertex2f( mRect.left(), mRect.bottom() );
		glTexCoord2f( mTexCoord.right(), mTexCoord.bottom() );
		glVertex2f( mRect.right(), mRect.bottom() );
		glTexCoord2f( mTexCoord.right(), mTexCoord.top() );
		glVertex2f( mRect.right(), mRect.top() );
	glEnd();
}
/**========================================================*/
/**
 *	@brief	�F�ݒ�
 *	@param[in]	�F
 *	@author	KORYUOH
 */
/**========================================================*/
void  Sprite2D::setColor(const Color4& color){
	mColor = color;
}