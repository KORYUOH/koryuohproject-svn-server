/**===File Commentary=======================================*/
/**
 *	@file	Sprite3D.cpp
 *
 *	@brief	二次元描画実装クラス
 *
 *	@author	keisuke Ito
 *
 *	@date	2012/10/11
 */
/**===File Include=========================================*/

#include <Sprite/Sprite2D/Sprite2D.h>
#include <gslib.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	テクスチャーID
 *	@author	Keisuke Ito
 */
/**========================================================*/

Sprite2D::Sprite2D(GLuint textureID,float x_, float y_,const Rect& rect)
	:mTextureID(textureID)
	,mPosition(x_,y_)
	,mRect(rect)
	,mCenter(0.0f,0.0f)
	,mScale(1.0f,1.0f)
	,mRotation(0.0f)
	,mColor(1.0f,1.0f,1.0f,1.0f)
	,mTexCoord(0.0f,0.0f,1.0f,1.0f)
{
	if(rect.mSize.x_<0||rect.mSize.y_<0){
		mRect.mSize.x_ = gsTextureGetWidth(gsGetTexture(textureID));
		mRect.mSize.y_ = gsTextureGetHeight(gsGetTexture(textureID));
	}
}

/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	テクスチャーID
 *	@param[in]　座標のx
 *	@param[in]　座標のy
 *	@param[in]　表示する画像の横サイズ
 *	@param[in]  表示する画像の縦のサイズ
 *	@param[in]  角度
 *	@author	Keisuke Ito
 */
/**========================================================*/

Sprite2D::Sprite2D(GLuint textureID,float x_, float y_, float sizeX, float sizeY, float rotation)
	:mTextureID(textureID)
	,mPosition(x_,y_)
	,mRect(0.0f,0.0f,sizeX,sizeY)
	,mCenter(0.0f,0.0f)
	,mScale(1.0f,1.0f)
	,mRotation(rotation)
	,mColor(1.0f,1.0f,1.0f,1.0f)
	,mTexCoord(0.0f,0.0f,1.0f,1.0f)
{
}

/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	テクスチャーID
 *	@author	KORYUOH
 */
/**========================================================*/
Sprite2D::Sprite2D(unsigned int textureID,const Vector2& position,float rotate,const Vector2& scale,const Rect & rect)
	:mTextureID(textureID)
	,mPosition(position)
	,mRotation(rotate)
	,mRect(rect)
	,mCenter(0.0f,0.0f)
	,mScale(scale)
	,mColor(1.0f,1.0f,1.0f,1.0f)
	,mTexCoord(0.0f,0.0f,1.0f,1.0f)
{
	if(rect.mSize.x_ <= 0&& rect.mSize.y_ <= 0){
		mRect.mSize.x_ = gsTextureGetWidth(gsGetTexture(textureID));
		mRect.mSize.y_ = gsTextureGetHeight(gsGetTexture(textureID));
	}
}



/**
	 *	@brief	位置の設定
	 *	@param[in]	位置
	 *	@author	Keisuke Ito
	 */
	void Sprite2D::setPosition(const Vector2& position)
	{
		mPosition = position;
	}

	/**
	 *	@brief	拡縮の設定
	 *	@param[in]	拡大率
	 *	@author	Keisuke Ito
	 */
	void Sprite2D::setScale(const Vector2& scale)
	{
		mScale = scale;
	}


	/**
	 *	@brief	回転の設定
	 *	@param[in]	回転角
	 *	@author	KORYUOH
	 */
	void Sprite2D::setRotate(float  rotate)
	{
		mRotation = rotate;
	}

	/**
	 *	@brief	矩形
	 *	@param[in]	矩形
	 *	@author	Keisuke Ito
	 */
	void Sprite2D::setRect(const Rect& rect)
	{
		mRect = rect;
	}


	/**
	 *	@brief	描画範囲設定
	 *	@param[in]	描画範囲
	 *	@author	Keisuke Ito
	 */
	void Sprite2D::setImageRect(const Rect& rect)
	{
		// テクスチャをバインドする
		gsBindTexture( mTextureID );

		// バインド中のテクスチャの幅と高さを取得する
		GLint width, height;
		glGetTexLevelParameteriv( GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH,  &width  );
		glGetTexLevelParameteriv( GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height );

		// テクスチャ座標の計算を行う
		mTexCoord.mPos.x_	= rect.left() / width;
		mTexCoord.mPos.y_	= rect.top() / height;
		mTexCoord.mSize.x_	= rect.right() / width;
		mTexCoord.mSize.y_	= rect.bottom() / height;
	}




void Sprite2D::draw()
{
	// 各種レンタリングモードの退避
	glPushAttrib( GL_ENABLE_BIT );

	// ライティングを無効にする
	glDisable( GL_LIGHTING );

	// ｚバッファを無効にする
	glDisable( GL_DEPTH_TEST );

	// 面カリングを無効にする
	glDisable( GL_CULL_FACE );

	// カレントカラーを取得する
	Color4	CurrentColor;
	glGetFloatv( GL_CURRENT_COLOR, (GLfloat*)&CurrentColor );

	// テクスチャをバインドする
	gsBindTexture( mTextureID );

	// 透視変換行列の退避
	glMatrixMode( GL_PROJECTION );
	glPushMatrix();

	// 透視変換行列の設定
	glLoadIdentity();
	gluOrtho2D( 0, 1024, 768, 0 );

	// モデルビュー変換行列の退避
	glMatrixMode( GL_MODELVIEW );
	glPushMatrix();

	// 変換行列の初期化
	glLoadIdentity();

	// 座標の設定を行う
	glTranslatef( mPosition.x_, mPosition.y_, 0.0f );

	// 拡大・縮小の設定を行う
	glTranslatef( -mCenter.x_, -mCenter.y_, 0.0f );

	// 回転角度の設定を行う
	glRotatef( mRotation, 0.0f, 0.0f, 1.0f );

	// 拡大・縮小の設定を行う
	glScalef( mScale.x_, mScale.y_, 0.0f );

	// テクスチャカラーの設定を行う
	glColor4fv( (GLfloat*)& mColor );

	// 四角形を描画
	drawQuad();

	// モデルビュー変換行列を復帰
	glPopMatrix();

	// 透視変換行列を復帰
	glMatrixMode( GL_PROJECTION );
	glPopMatrix();

	// モデルビュー変換行列に設定
	glMatrixMode( GL_MODELVIEW );

	// カレントカラーを復帰する
	glColor4fv( (GLfloat*)& CurrentColor );

	// レンダリングモードの復帰
	glPopAttrib();
}


void Sprite2D::drawQuad()
{
	glBegin( GL_QUADS );
	glTexCoord2f( mTexCoord.left(), mTexCoord.top() );
		glVertex2f( mRect.left(), mRect.top() );
		glTexCoord2f( mTexCoord.left(), mTexCoord.bottom());
		glVertex2f( mRect.left(), mRect.bottom() );
		glTexCoord2f( mTexCoord.right(), mTexCoord.bottom() );
		glVertex2f( mRect.right(), mRect.bottom() );
		glTexCoord2f( mTexCoord.right(), mTexCoord.top() );
		glVertex2f( mRect.right(), mRect.top() );
	glEnd();
}
/**========================================================*/
/**
 *	@brief	色設定
 *	@param[in]	色
 *	@author	KORYUOH
 */
/**========================================================*/
void  Sprite2D::setColor(const Color4& color){
	mColor = color;
}