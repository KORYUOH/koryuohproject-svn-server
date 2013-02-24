/**===File Commentary=======================================*/
/**
 *	@file	sprite3d.h
 *
 *	@brief	2D�`��N���X
 *
 *	@author	Keisuke Ito
 *
 *	@date	2012/10/11
 */
/**===Include Guard========================================*/
#ifndef _SPRITE2D_H_
#define _SPRITE2D_H_
/**===File Include=========================================*/
//#include<gslib.h>
#include	<Type/Rect/Rect.h>
#include	<Type/Vector2/Vector2.h>
#include	<Type/Color4/Color4.h>
#include	<Type/TextureData/TextureData.h>
/**===Class Definition=====================================*/
class Sprite2D{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�e�N�X�`��ID
	 *	@param[in]	�|�W�V����X
	 *	@param[in]	�|�W�V����Y
	 *	@author	Keisuke Ito
	 */
	Sprite2D(const TextureData& texData,float x_, float y_ ,const Rect& rect = Rect(0,0,-1,-1));
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�e�N�X�`��ID
	 *	@param[in]	�|�W�V����X
	 *	@param[in]	�|�W�V����Y
	 *	@param[in]  sizeX �\���������摜�̉��T�C�Y
	 *	@param[in]  sizeY �\���������摜�̏c�T�C�Y
	  *	@param[in]  �p�x
	 *	@author	Keisuke Ito
	 */
	Sprite2D(const TextureData& texData,float x_, float y_,float sizeX, float sizeY, float roration);
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�e�N�X�`��ID
	 *	@param[in]	�|�W�V����
	 *	@param[in]	��]�p
	 *	@param[in]	�g�k��
	 *	@param[in]	
	 *	@param[in]	
	 *	@author	KORYUOH
	 */
	Sprite2D(unsigned int textureID,const Vector2& position,float rotate= 0.0f, const Vector2& scale = Vector2(1.0,1.0),const Rect& rect = Rect(0.0,0.0,-1,-1));

	/**
	 *	@brief	�ʒu�̐ݒ�
	 *	@param[in]	�ʒu
	 *	@author	Keisuke Ito
	 */
	void setPosition(const Vector2& position);

	/**
	 *	@brief	�g�k�̐ݒ�
	 *	@param[in]	�g�嗦
	 *	@author	Keisuke Ito
	 */
	void setScale(const Vector2& scale);


	/**
	 *	@brief	��]�̐ݒ�
	 *	@param[in]	��]�p
	 *	@author	KORYUOH
	 */
	void setRotate(float  rotate);

	/**
	 *	@brief	��`
	 *	@param[in]	��`
	 *	@author	Keisuke Ito
	 */
	void setRect(const Rect& rect);

	/**
	 *	@brief	�F�ݒ�
	 *	@param[in]	�F
	 */
	void setColor(const Color4& color);

	/**
	 *	@brief	�`��͈͐ݒ�
	 *	@param[in]	�`��͈�
	 *	@author	Keisuke Ito
	 */
	void setImageRect(const Rect& rect);

	/**
	 *	@brief	�`��
	 *	@author	Keisuke Ito
	 */
	void draw();

	/**
	 *	@brief	�l�p�`�`��
	 *	@author	Keisuke Ito
	 */
	void drawQuad();




private:
	/**	�����o�[�ϐ�*/
	unsigned int		mTextureID;		//�e�N�X�`���h�c
	Vector2				mPosition;		//���W
	Rect				mRect;			//�؂�o��
	Vector2				mCenter;		//���S
	Vector2				mScale;			//�X�P�[��
	float				mRotation;		//��]�p�x
	Color4				mColor;			//�J���[
	Rect				mTexCoord;
};	




/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/