/**===File Commentary=======================================*/
/**
 *	@file	sprite3d.h
 *
 *	@brief	3D描画クラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/29
 */
/**===Include Guard========================================*/
#ifndef	_SPRITE3D_H_
#define	_SPRITE3D_H_
/**===File Include=========================================*/
#include	<Sprite/Interface/IDraw.h>
#include	<Type/Vector3/Vector3.h>
#include	<Type/Vector2/Vector2.h>
#include	<Type/Rect/Rect.h>
#include	<Type/Color4/Color4.h>
#include	<Type/TextureData/TextureData.h>
/**===Class Definition=====================================*/
class Sprite3D:public IDraw{
public:
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	テクスチャID
	 *	@author	KORYUOH
	 */
	Sprite3D(const TextureData& textureData);
	/**
	 *	@brief	位置の設定
	 *	@param[in]	位置
	 *	@author	KORYUOH
	 */
	void setPosition(const Vector3& positon);
	/**
	 *	@brief	拡縮の設定
	 *	@param[in]	拡大率
	 *	@author	KORYUOH
	 */
	void setScale(const Vector2& scale);
	/**
	 *	@brief	回転の設定
	 *	@param[in]	回転角
	 *	@author	KORYUOH
	 */
	void setRotate(float rotate);
	/**
	 *	@brief	矩形
	 *	@param[in]	矩形
	 *	@author	KORYUOH
	 */
	void setRect(const Rect& rect);
	/**
	 *	@brief	色の設定
	 *	@param[in]	色情報
	 *	@author	KORYUOH
	 */
	void setColor(const Color4& color);
	/**
	 *	@brief	描画範囲設定
	 *	@param[in]	描画範囲
	 *	@author	KORYUOH
	 */
	void setImageRect(const Rect& rect);
	/**
	 *	@brief	描画
	 *	@author	KORYUOH
	 */
	virtual void draw();
private:
	void drawQuad();

private:
	/**	メンバー変数*/
	const TextureData&	mTextureData;
	Vector3			mPosition;
	Vector2			mScale;
	float				mRotate;
	Color4			mColor;
	Rect				mRect;
	Rect				mTexCoord;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/