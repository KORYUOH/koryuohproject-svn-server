/**===File Commentary=======================================*/
/**
 *	@file	TextureData.cpp
 *
 *	@brief	テクスチャデータ
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
 *	@brief	コンストラクタ
 *	@param[in]	テクスチャID
 *	@param[in]	サイズ
 */
/**========================================================*/
TextureData::TextureData(unsigned int textureID,const Vector2& size)
	:mTextureID(textureID)
	,mSize(size)
{}
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	テクスチャID
 *	@param[in]	幅
 *	@param[in]	高さ
 */
/**========================================================*/
TextureData::TextureData(unsigned int textureID,float width,float height)
	:mTextureID(textureID)
	,mSize(width,height)
{}
/**========================================================*/
/**
 *	@brief	テクスチャID取得
 *	@return	テクスチャID
 */
/**========================================================*/
unsigned int TextureData::TextureID()const{
	return mTextureID;
}
/**========================================================*/
/**
 *	@brief	幅取得
 *	@return	幅
 */
/**========================================================*/
float TextureData::Width()const{
	return mSize.x_;
}
/**========================================================*/
/**
 *	@brief	高さ取得
 *	@return	高さ
 */
/**========================================================*/
float TextureData.Height()const{
	return mSize.y_;
}

/**===End Of File==========================================*/