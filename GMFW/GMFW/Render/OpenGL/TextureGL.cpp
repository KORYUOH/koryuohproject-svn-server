/**===File Commentary=======================================*/
/**
 *	@file	Texture.cpp
 *
 *	@brief	テクスチャ
 *
 *	@note	OpenGL
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/22
 */
/**===File Include=========================================*/
#include	<Render/OpenGL/TextureGL.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	ディスクプリタ
 *	@param[in]	データ
 *	@author	KORYUOH
 */
/**========================================================*/
TextureGL::TextureGL(const TextureDesc& desc,const void* data)
	:m_desc(desc),
	m_type(toType(desc.type_)),
	m_texture(0)
{
	glGenTextures(1,&m_texture);
	initialize(data);
}
/**========================================================*/
/**
 *	@brief	デストラクタ
 *	@author	KORYUOH
 */
/**========================================================*/
TextureGL::~TextureGL(){
	glDeleteTextures(1,&m_texture);
}
/**========================================================*/
/**
 *	@brief	ディスクプリタ取得
 *	@author	KORYUOH
 *	@return	ディスクプリタ
 */
/**========================================================*/
const TextureDesc& TextureGL::desc()const{
	return m_desc;
}
/**========================================================*/
/**
 *	@brief	データ設定
 *	@param[in]	データ
 *	@author	KORYUOH
 */
/**========================================================*/
void TextureGL::setData(const void* data){
	glBindTexture(target(),m_texture);
	glTexSubImage2D(
		target(),
		0,
		0,0,
		desc().width,
		desc().height,
		pixel().format,pixel().type,data
		);
	glBindTexture(target(),0);
}
/**========================================================*/
/**
 *	@brief	データ取得
 *	@param[in]	データ格納先
 *	@author	KORYUOH
 */
/**========================================================*/
void TextureGL::getData(void* data){
	glBindTexture(target(),texture());
	glGetTexImage(
		target(),
		0,
		pixel().format,
		pixel().type,
		data
		);
	glBindTexture(target(),0);
}
/**========================================================*/
/**
 *	@brief	サイズ取得
 *	@author	KORYUOH
 *	@return	サイズ
 */
/**========================================================*/
unsigned int TextureGL::size()const{
	return desc().width * desc().height * pixel().size;
}
/**========================================================*/
/**
 *	@brief	テクスチャ取得
 *	@author	KORYUOH
 *	@return	テクスチャ
 */
/**========================================================*/
GLuint TextureGL::texture() const{
	return m_texture;
}
/**========================================================*/
/**
 *	@brief	ターゲット取得
 *	@author	KORYUOH
 *	@return	ターゲット
 */
/**========================================================*/
GLenum TextureGL::target() const{
	return m_type.target;
}
/**========================================================*/
/**
 *	@brief	ピクセルフォーマット変換
 *	@author	KORYUOH
 *	@return	変換結果
 */
/**========================================================*/
const TextureGL::Pixel& TextureGL::pixel() const {
	static const Pixel pixelFormat[] = {
		{GL_RGBA8,GL_RGBA,GL_UNSIGNED_BYTE,sizeof(GLubyte)*4,false,false,false}
	};
	return pixelFormat[0];
}
/**========================================================*/
/**
 *	@brief	初期化
 *	@param[in]	データ
 *	@author	KORYUOH
 */
/**========================================================*/
void TextureGL::initialize(const void* data){
	glBindTexture(target() , m_texture);
	glTexImage2D(
		target(),
		0,
		pixel().internalFormat,
		desc().width,
		desc().height,
		0,
		pixel().format,	pixel().type,	data
		);
	glTexParameteri(target()	,GL_TEXTURE_MAG_FILTER	,GL_NEAREST);
	glTexParameteri(target()	,GL_TEXTURE_MIN_FILTER	,GL_NEAREST);
	glBindTexture(target(),0);
}
/**========================================================*/
/**
 *	@brief	タイプ変換
 *	@param[in]	タイプ
 *	@author	KORYUOH
 *	@return	変換結果
 */
/**========================================================*/
const TextureGL::Type& TextureGL::toType(TextureType type){
	static const Type types[] = {
		{GL_TEXTURE_2D,GL_TEXTURE_2D}
	};
	return types[0];
}


/**===End Of File==========================================*/