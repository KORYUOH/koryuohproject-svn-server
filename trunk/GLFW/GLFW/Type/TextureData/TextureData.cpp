/**===File Commentary=======================================*/
/**
 *	@file	TextureData.cpp
 *
 *	@brief	�e�N�X�`���f�[�^
 *
 *	@author	KORYUOH
 *
 *	@date	2013/02/05
 */
/**===File Include=========================================*/
#include	<Type/TextureData/TextureData.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�e�N�X�`��ID
 *	@param[in]	�T�C�Y
 */
/**========================================================*/
TextureData::TextureData(unsigned int textureID,const Vector2& size)
	:mTextureID(textureID)
	,mSize(size)
{}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�e�N�X�`��ID
 *	@param[in]	��
 *	@param[in]	����
 */
/**========================================================*/
TextureData::TextureData(unsigned int textureID,float width,float height)
	:mTextureID(textureID)
	,mSize(width,height)
{}
/**========================================================*/
/**
 *	@brief	�e�N�X�`��ID�擾
 *	@return	�e�N�X�`��ID
 */
/**========================================================*/
unsigned int TextureData::TextureID()const{
	return mTextureID;
}
/**========================================================*/
/**
 *	@brief	���擾
 *	@return	��
 */
/**========================================================*/
float TextureData::Width()const{
	return mSize.x_;
}
/**========================================================*/
/**
 *	@brief	�����擾
 *	@return	����
 */
/**========================================================*/
float TextureData.Height()const{
	return mSize.y_;
}

/**===End Of File==========================================*/