/**===File Commentary=======================================*/
/**
 *	@file	sprite3d.h
 *
 *	@brief	3D�`��N���X
 *
 *	@author	<��Җ�>
 *
 *	@date	2012/04/29
 */
/**===Include Guard========================================*/
#ifndef	_SPRITE3D_H_
#define	_SPRITE3D_H_
/**===File Include=========================================*/
#include	<gslib.h>
/**===Class Definition=====================================*/
class Sprite3D{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�e�N�X�`��ID
	 *	@author	<��Җ�>
	 */
	Sprite3D(unsigned int textureID);
	/**
	 *	@brief	�ʒu�̐ݒ�
	 *	@param[in]	�ʒu
	 *	@author	<��Җ�>
	 */
	void setPosition(const GSvector3& positon);
	/**
	 *	@brief	�g�k�̐ݒ�
	 *	@param[in]	�g�嗦
	 *	@author	<��Җ�>
	 */
	void setScale(const GSvector2& scale);
	/**
	 *	@brief	��]�̐ݒ�
	 *	@param[in]	��]�p
	 *	@author	<��Җ�>
	 */
	void setRotate(float rotate);
	/**
	 *	@brief	��`
	 *	@param[in]	��`
	 *	@author	<��Җ�>
	 */
	void setRect(const GSrect& rect);
	/**
	 *	@brief	�F�̐ݒ�
	 *	@param[in]	�F���
	 *	@author	<��Җ�>
	 */
	void setColor(const GScolor& color);
	/**
	 *	@brief	�`��͈͐ݒ�
	 *	@param[in]	�`��͈�
	 *	@author	<��Җ�>
	 */
	void setImageRect(const GSrect& rect);
	/**
	 *	@brief	�`��
	 *	@author	<��Җ�>
	 */
	void draw();


private:
	/**	�����o�[�ϐ�*/
	unsigned int		mTextureID;
	GSvector3			mPosition;
	GSvector2			mScale;
	float			mRotate;
	GScolor			mColor;
	GSrect			mRect;
	GSrect			mTexCoord;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/