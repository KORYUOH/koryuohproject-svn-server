/**===File Commentary=======================================*/
/**
 *	@file	sprite3d.h
 *
 *	@brief	3D�`��N���X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/29
 */
/**===Include Guard========================================*/
#ifndef	_SPRITE3D_H_
#define	_SPRITE3D_H_
/**===File Include=========================================*/
#include	<Type/Vector3/Vector3.h>
#include	<Type/Vector2/Vector2.h>
#include	<Type/Rect/Rect.h>
#include	<Type/Color4/Color4.h>
/**===Class Definition=====================================*/
class Sprite3D{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�e�N�X�`��ID
	 *	@author	KORYUOH
	 */
	Sprite3D(unsigned int textureID);
	/**
	 *	@brief	�ʒu�̐ݒ�
	 *	@param[in]	�ʒu
	 *	@author	KORYUOH
	 */
	void setPosition(const Vector3& positon);
	/**
	 *	@brief	�g�k�̐ݒ�
	 *	@param[in]	�g�嗦
	 *	@author	KORYUOH
	 */
	void setScale(const Vector2& scale);
	/**
	 *	@brief	��]�̐ݒ�
	 *	@param[in]	��]�p
	 *	@author	KORYUOH
	 */
	void setRotate(float rotate);
	/**
	 *	@brief	��`
	 *	@param[in]	��`
	 *	@author	KORYUOH
	 */
	void setRect(const Rect& rect);
	/**
	 *	@brief	�F�̐ݒ�
	 *	@param[in]	�F���
	 *	@author	KORYUOH
	 */
	void setColor(const Color4& color);
	/**
	 *	@brief	�`��͈͐ݒ�
	 *	@param[in]	�`��͈�
	 *	@author	KORYUOH
	 */
	void setImageRect(const Rect& rect);
	/**
	 *	@brief	�`��
	 *	@author	KORYUOH
	 */
	void draw();


private:
	/**	�����o�[�ϐ�*/
	unsigned int		mTextureID;
	Vector3			mPosition;
	Vector2			mScale;
	float			mRotate;
	Color4			mColor;
	Rect			mRect;
	Rect			mTexCoord;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/