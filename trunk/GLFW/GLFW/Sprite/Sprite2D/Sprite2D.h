/**===File Commentary=======================================*/
/**
 *	@file	sprite3d.h
 *
 *	@brief	2D描画クラス
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
	 *	@brief	コンストラクタ
	 *	@param[in]	テクスチャID
	 *	@param[in]	ポジションX
	 *	@param[in]	ポジションY
	 *	@author	Keisuke Ito
	 */
	Sprite2D(const TextureData& texData,float x_, float y_ ,const Rect& rect = Rect(0,0,-1,-1));
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	テクスチャID
	 *	@param[in]	ポジションX
	 *	@param[in]	ポジションY
	 *	@param[in]  sizeX 表示したい画像の横サイズ
	 *	@param[in]  sizeY 表示したい画像の縦サイズ
	  *	@param[in]  角度
	 *	@author	Keisuke Ito
	 */
	Sprite2D(const TextureData& texData,float x_, float y_,float sizeX, float sizeY, float roration);
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	テクスチャID
	 *	@param[in]	ポジション
	 *	@param[in]	回転角
	 *	@param[in]	拡縮率
	 *	@param[in]	
	 *	@param[in]	
	 *	@author	KORYUOH
	 */
	Sprite2D(unsigned int textureID,const Vector2& position,float rotate= 0.0f, const Vector2& scale = Vector2(1.0,1.0),const Rect& rect = Rect(0.0,0.0,-1,-1));

	/**
	 *	@brief	位置の設定
	 *	@param[in]	位置
	 *	@author	Keisuke Ito
	 */
	void setPosition(const Vector2& position);

	/**
	 *	@brief	拡縮の設定
	 *	@param[in]	拡大率
	 *	@author	Keisuke Ito
	 */
	void setScale(const Vector2& scale);


	/**
	 *	@brief	回転の設定
	 *	@param[in]	回転角
	 *	@author	KORYUOH
	 */
	void setRotate(float  rotate);

	/**
	 *	@brief	矩形
	 *	@param[in]	矩形
	 *	@author	Keisuke Ito
	 */
	void setRect(const Rect& rect);

	/**
	 *	@brief	色設定
	 *	@param[in]	色
	 */
	void setColor(const Color4& color);

	/**
	 *	@brief	描画範囲設定
	 *	@param[in]	描画範囲
	 *	@author	Keisuke Ito
	 */
	void setImageRect(const Rect& rect);

	/**
	 *	@brief	描画
	 *	@author	Keisuke Ito
	 */
	void draw();

	/**
	 *	@brief	四角形描画
	 *	@author	Keisuke Ito
	 */
	void drawQuad();




private:
	/**	メンバー変数*/
	unsigned int		mTextureID;		//テクスチャＩＤ
	Vector2				mPosition;		//座標
	Rect				mRect;			//切り出し
	Vector2				mCenter;		//中心
	Vector2				mScale;			//スケール
	float				mRotation;		//回転角度
	Color4				mColor;			//カラー
	Rect				mTexCoord;
};	




/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/