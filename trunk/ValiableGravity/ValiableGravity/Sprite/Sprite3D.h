/**===File Commentary=======================================*/
/**
 *	@file	sprite3d.h
 *
 *	@brief	3D描画クラス
 *
 *	@author	<作者名>
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
	 *	@brief	コンストラクタ
	 *	@param[in]	テクスチャID
	 *	@author	<作者名>
	 */
	Sprite3D(unsigned int textureID);
	/**
	 *	@brief	位置の設定
	 *	@param[in]	位置
	 *	@author	<作者名>
	 */
	void setPosition(const GSvector3& positon);
	/**
	 *	@brief	拡縮の設定
	 *	@param[in]	拡大率
	 *	@author	<作者名>
	 */
	void setScale(const GSvector2& scale);
	/**
	 *	@brief	回転の設定
	 *	@param[in]	回転角
	 *	@author	<作者名>
	 */
	void setRotate(float rotate);
	/**
	 *	@brief	矩形
	 *	@param[in]	矩形
	 *	@author	<作者名>
	 */
	void setRect(const GSrect& rect);
	/**
	 *	@brief	色の設定
	 *	@param[in]	色情報
	 *	@author	<作者名>
	 */
	void setColor(const GScolor& color);
	/**
	 *	@brief	描画範囲設定
	 *	@param[in]	描画範囲
	 *	@author	<作者名>
	 */
	void setImageRect(const GSrect& rect);
	/**
	 *	@brief	描画
	 *	@author	<作者名>
	 */
	void draw();


private:
	/**	メンバー変数*/
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