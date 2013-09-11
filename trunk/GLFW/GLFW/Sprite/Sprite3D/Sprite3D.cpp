/**===File Commentary=======================================*/
/**
 *	@file	Sprite3D.cpp
 *
 *	@brief	三次元描画実装クラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/29
 */
/**===File Include=========================================*/
#include	<Sprite/Sprite3D/Sprite3D.h>
#include	<Type/Vector3/Vector3.h>
#include	<gslib.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	テクスチャーID
 *	@author	KORYUOH
 */
/**========================================================*/
Sprite3D::Sprite3D(const TextureData& textureData)
	:mTextureData(textureData)
	,mPosition(0.0f,0.0f,0.0f)
	,mScale(1.0f,1.0f)
	,mRotate(0.0f)
	,mRect(-0.5f,-0.5f,0.5f,0.5f)
	,mColor(1.0f,1.0f,1.0f,1.0f)
	,mTexCoord(0.1f,0.0f,1.0f,1.0f)
{ }
/**========================================================*/
/**
 *	@brief	位置の設定
 *	@param[in]	位置
 *	@author	KORYUOH
 */
/**========================================================*/
void Sprite3D::setPosition(const Vector3& position){
	mPosition = position;
}
/**========================================================*/
/**
 *	@brief	スケールの設定
 *	@param[in]	スケール
 *	@author	KORYUOH
 */
/**========================================================*/
void Sprite3D::setScale(const Vector2& scale){
	mScale = scale;
}
/**========================================================*/
/**
 *	@brief	回転角の設定
 *	@param[in]	回転角
 *	@author	KORYUOH
 */
/**========================================================*/
void Sprite3D::setRotate(float rotate){
	mRotate = rotate;
}
/**========================================================*/
/**
 *	@brief	描画サイズの矩形を設定
 *	@param[in]	矩形
 *	@author	KORYUOH
 */
/**========================================================*/
void Sprite3D::setRect(const Rect& rect){
	mRect = rect;
}
/**========================================================*/
/**
 *	@brief	テクスチャの色を設定
 *	@param[in]	色
 *	@author	KORYUOH
 */
/**========================================================*/
void Sprite3D::setColor(const Color4& color){
	mColor = color;
}
/**========================================================*/
/**
 *	@brief	転送元矩形イメージの矩形を設定
 *	@param[in]	矩形
 *	@author	KORYUOH
 */
/**========================================================*/
void Sprite3D::setImageRect(const Rect& rect){
	//イメージをバインド
	gsBindTexture(mTextureData.TextureID());

	//バインド中のテクスチャの幅と高さを取得
	int	width=mTextureData.Width(),height=mTextureData.Height();
//	glGetTexParameteriv(GL_TEXTURE_2D,GL_TEXTURE_WIDTH,&width);
//	glGetTexParameteriv(GL_TEXTURE_2D,GL_TEXTURE_HEIGHT,&height);


	//テクスチャ座標の計算
	mTexCoord.mPos.y_ = rect.top()/height;
	mTexCoord.mSize.y_ = rect.bottom() /height;
	mTexCoord.mPos.x_ = rect.left() / width;
	mTexCoord.mSize.x_ = rect.right()/width;
}

/**========================================================*/
/**
 *	@brief	描画
 *	@author	KORYUOH
 */
/**========================================================*/
void Sprite3D::draw(){
	//各種レンダリングモード退避
	glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT);

	//面カリング無効
	glDisable(GL_CULL_FACE);

	//テクスチャのバインド
	gsBindTexture(mTextureData.TextureID());

	//モデルビュー変換行列の退避
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	//ビルボード処理用変換行列設定
	GSmatrix4 billborad;
	glGetFloatv(GL_MODELVIEW_MATRIX,(GLfloat*)&billborad);
	billborad.setPosition(GSvector3(0.0f,0.0f,0.0f));
	billborad.transpose();

	//平行移動量の設定
	glTranslatef(mPosition.x_,mPosition.y_,mPosition.z_);

	//ビルボードの変換行列設定
	glMultMatrixf((GLfloat*)&billborad);

	//回転角度の設定を行う
	glRotatef(mRotate,0.0f,0.0f,1.0f);

	//テクスチャカラーの設定
	glColor4fv((GLfloat*)&mColor);

	//四角形の描画
	drawQuad();

	//モデルビュー復帰
	glPopMatrix();
	//レンダリングモード復帰
	glPopAttrib();
}

void Sprite3D::drawQuad(){
	glBegin(GL_QUADS);
		glNormal3f(0.0f,0.0f,1.0f);
		glTexCoord2f(mTexCoord.left(),mTexCoord.top());
		glVertex2f(mRect.left(),mRect.top());

		glTexCoord2f(mTexCoord.left(),mTexCoord.bottom());
		glVertex2f(mRect.left(),mRect.bottom());
		
		glTexCoord2f(mTexCoord.right(),mTexCoord.bottom());
		glVertex2f(mRect.right(),mRect.bottom());
		
		glTexCoord2f(mTexCoord.right(),mTexCoord.top());
		glVertex2f(mRect.right(),mRect.top());

	glEnd();
}

/**===End Of File==========================================*/