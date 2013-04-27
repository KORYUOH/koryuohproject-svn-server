/**===File Commentary=======================================*/
/**
 *	@file	TextureData.h
 *
 *	@brief	テクスチャデータ
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
	 *	@brief	コンストラクタ
	 *	@param[in]	テクスチャID
	 *	@param[in]	サイズ
	 */
	TextureData(unsigned int textureID,const Vector2& size);
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	テクスチャID
	 *	@param[in]	幅
	 *	@param[in]	高さ
	 */
	TextureData(unsigned int textureID,float width,float height);
	/**
	 *	@brief	テクスチャID取得
	 *	@return	テクスチャID
	 */
	unsigned int TextureID()const;
	/**
	 *	@brief	幅取得
	 *	@return	幅
	 */
	float Width()const;
	/**
	 *	@brief	高さ取得
	 *	@return	高さ
	 */
	float Height()const;
	/**
	 *	@brief	仮想デストラクタ
	 */
	virtual ~TextureData(){}
private:
	/**	メンバー変数*/
	unsigned int mTextureID;
	Vector2 mSize;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/