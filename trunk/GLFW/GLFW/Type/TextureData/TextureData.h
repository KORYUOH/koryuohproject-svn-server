/**===File Commentary=======================================*/
/**
 *	@file	TextureData.h
 *
 *	@brief	�e�N�X�`���f�[�^
 *
 *	@author	KORYUOH
 *
 *	@date	2013/02/05
 */
/**===Include Guard========================================*/
#ifndef	_TEXTUREDATA_H_
#define	_TEXTUREDATA_H_
/**===File Include=========================================*/
#include	<Type/Vector2/Vector2.h>
/**===Class Definition=====================================*/
class TextureData{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�e�N�X�`��ID
	 *	@param[in]	�T�C�Y
	 */
	TextureData(unsigned int textureID,const Vector2& size);
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�e�N�X�`��ID
	 *	@param[in]	��
	 *	@param[in]	����
	 */
	TextureData(unsigned int textureID,float width,float height);
	/**
	 *	@brief	�e�N�X�`��ID�擾
	 *	@return	�e�N�X�`��ID
	 */
	unsigned int TextureID()const;
	/**
	 *	@brief	���擾
	 *	@return	��
	 */
	float Width()const;
	/**
	 *	@brief	�����擾
	 *	@return	����
	 */
	float Height()const;
	/**
	 *	@brief	���z�f�X�g���N�^
	 */
	virtual ~TextureData(){}
private:
	/**	�����o�[�ϐ�*/
	unsigned int mTextureID;
	Vector2 mSize;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/