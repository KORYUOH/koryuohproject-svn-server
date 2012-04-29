/**===File Commentary=======================================*/
/**
 *	@file	Sprite3D.cpp
 *
 *	@brief	�O�����`������N���X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/29
 */
/**===File Include=========================================*/
#include	<Sprite/Sprite3D.h>
#include	<gslib.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�e�N�X�`���[ID
 *	@author	KORYUOH
 */
/**========================================================*/
Sprite3D::Sprite3D(GLuint textureID)
	:mTextureID(textureID)
	,mPosition(0.0f,0.0f,0.0f)
	,mScale(1.0f,1.0f)
	,mRotate(0.0f)
	,mRect(-0.5f,-0.5f,0.5f,0.5f)
	,mColor(1.0f,1.0f,1.0f,1.0f)
	,mTexCoord(0.1f,0.0f,1.0f,1.0f)
{ }
/**========================================================*/
/**
 *	@brief	�ʒu�̐ݒ�
 *	@param[in]	�ʒu
 *	@author	KORYUOH
 */
/**========================================================*/
void Sprite3D::setPosition(const GSvector3& position){
	mPosition = position;
}
/**========================================================*/
/**
 *	@brief	�X�P�[���̐ݒ�
 *	@param[in]	�X�P�[��
 *	@author	KORYUOH
 */
/**========================================================*/
void Sprite3D::setScale(const GSvector2& scale){
	mScale = scale;
}
/**========================================================*/
/**
 *	@brief	��]�p�̐ݒ�
 *	@param[in]	��]�p
 *	@author	KORYUOH
 */
/**========================================================*/
void Sprite3D::setRotate(float rotate){
	mRotate = rotate;
}
/**========================================================*/
/**
 *	@brief	�`��T�C�Y�̋�`��ݒ�
 *	@param[in]	��`
 *	@author	KORYUOH
 */
/**========================================================*/
void Sprite3D::setRect(const GSrect& rect){
	mRect = rect;
}
/**========================================================*/
/**
 *	@brief	�e�N�X�`���̐F��ݒ�
 *	@param[in]	�F
 *	@author	KORYUOH
 */
/**========================================================*/
void Sprite3D::setColor(const GScolor& color){
	mColor = color;
}
/**========================================================*/
/**
 *	@brief	�]������`�C���[�W�̋�`��ݒ�
 *	@param[in]	��`
 *	@author	KORYUOH
 */
/**========================================================*/
void Sprite3D::setImageRect(const GSrect& rect){
	//�C���[�W���o�C���h
	gsBindTexture(mTextureID);

	//�o�C���h���̃e�N�X�`���̕��ƍ������擾
	GLint	width,height;
	glGetTexParameteriv(GL_TEXTURE_2D,GL_TEXTURE_WIDTH,&width);
	glGetTexParameteriv(GL_TEXTURE_2D,GL_TEXTURE_HEIGHT,&height);

	//�e�N�X�`�����W�̌v�Z
	mTexCoord.top = rect.top/height;
	mTexCoord.bottom = rect.bottom /height;
	mTexCoord.left = rect.left / width;
	mTexCoord.right = rect.right/width;
}

/**========================================================*/
/**
 *	@brief	�`��
 *	@author	KORYUOH
 */
/**========================================================*/
void Sprite3D::draw(){
	//�e�탌���_�����O���[�h�ޔ�
	glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT);

	//�ʃJ�����O����
	glDisable(GL_CULL_FACE);

	//�e�N�X�`���̃o�C���h
	gsBindTexture(mTextureID);

	//���f���r���[�ϊ��s��̑ޔ�
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	//�r���{�[�h�����p�ϊ��s��ݒ�
	GSmatrix4 billborad;
	glGetFloatv(GL_MODELVIEW_MATRIX,(GLfloat*)&billborad);
	billborad.setPosition(GSvector3(0.0f,0.0f,0.0f));
	billborad.transpose();

	//���s�ړ��ʂ̐ݒ�
	glTranslatef(mPosition.x,mPosition.y,mPosition.z);

	//�r���{�[�h�̕ϊ��s��ݒ�
	glMultMatrixf((GLfloat*)&billborad);

	//��]�p�x�̐ݒ���s��
	glRotatef(mRotate,0.0f,0.0f,1.0f);

	//�e�N�X�`���J���[�̐ݒ�
	glColor4fv((GLfloat*)&mColor);

	//�l�p�`�̕`��
	glBegin(GL_QUADS);
		glNormal3f(0.0f,0.0f,1.0f);
		glTexCoord2f(mTexCoord.left,mTexCoord.top);
		glVertex2f(mRect.left,mRect.top);

		glTexCoord2f(mTexCoord.left,mTexCoord.bottom);
		glVertex2f(mRect.left,mRect.bottom);
		
		glTexCoord2f(mTexCoord.right,mTexCoord.bottom);
		glVertex2f(mRect.right,mRect.bottom);
		
		glTexCoord2f(mTexCoord.right,mTexCoord.top);
		glVertex2f(mRect.right,mRect.top);

	glEnd();

	//���f���r���[���A
	glPopMatrix();
	//�����_�����O���[�h���A
	glPopAttrib();
}
/**===End Of File==========================================*/