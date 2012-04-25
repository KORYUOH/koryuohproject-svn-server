/**===File Commentary=======================================*/
/**
 *	@file	Texture.h
 *
 *	@brief	テクスチャクラス
 *
 *	@note	OpenGL
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/21
 */
/**===Include Guard========================================*/
#ifndef	_TEXTURE_GL_H_
#define	_TEXTURE_GL_H_
/**===File Include=========================================*/
#include	<Render/Texture/ITexture.h>
#include	<GLee/GLee.h>
/**===Class Definition=====================================*/
class TextureGL:public ITexture{
public:
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	ディスクプリタ
	 *	@param[in]	データ
	 *	@author	KORYUOH
	 */
	TextureGL(const TextureDesc& desc, const void * data);
	/**
	 *	@brief	デストラクタ
	 *	@author	KORYUOH
	 */
	virtual ~TextureGL();
	/**
	 *	@brief	ディスクプリタ取得
	 *	@author	KORYUOH
	 *	@return	ディスクプリタ
	 */
	virtual const TextureDesc& desc() const;
	/**
	 *	@brief	データ設定
	 *	@param[in]	データ
	 *	@author	KORYUOH
	 */
	virtual void setData(const void* data);
	/**
	 *	@brief	データ取得
	 *	@param[in]	データ
	 *	@author	KORYUOH
	 */
	virtual void getData(void* data);
	/**
	 *	@brief	サイズ取得
	 *	@author	KORYUOH
	 *	@return	サイズ
	 */
	virtual unsigned int size() const;

	/**
	 *	@brief	ターゲット取得
	 *	@author	KORYUOH
	 *	@return	ターゲット情報
	 */
	GLenum target() const;
	/**
	 *	@brief	テクスチャ情報取得
	 *	@author	KORYUOH
	 *	@return	テクスチャ情報
	 */
	GLuint texture() const;

protected:
	/** テクスチャタイプ構造体 */
	struct Type{
		GLenum			target;
		GLenum			arrayTarget;
		unsigned int	arraySize;
	};
	/** ピクセルフォーマット型構造体 */
	struct Pixel{
		GLenum	internalFormat;
		GLenum	format;
		GLenum	type;
		GLuint	size;
		bool		complessedFormat;
		bool		depthFormat;
		bool		stencilFormat;
	};
	/**
	 *	@brief	初期化
	 *	@param[in]	データ
	 *	@author	KORYUOH
	 */
	void initialize( const void* data);
	/**
	 *	@brief	ピクセルフォーマット取得
	 *	@author	KORYUOH
	 */
	const Pixel& pixel() const;

private:
	/**
	 *	@brief	テクスチャタイプ変換
	 *	@param[in]	テクスチャタイプ
	 *	@author	KORYUOH
	 *	@return	テクスチャ
	 */
	static const Type& toType(TextureType type);

	/**
	 *	@brief	コピー禁止
	 *	@author	KORYUOH
	 */
	TextureGL(const TextureGL& other);
	TextureGL& operator = (const TextureGL& other);
	
private:
	/** ディスクプリタ */
	TextureDesc		m_desc;
	/** テクスチャタイプ */
	Type					m_type;
	/** テクスチャオブジェクト */
	GLuint				m_texture;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/