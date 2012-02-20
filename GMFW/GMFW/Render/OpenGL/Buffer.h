/**===File Commentary=======================================*/
/**
 *	@file	Buffer.h
 *
 *	@brief	バッファ
 *
 *	@note	OpenGL版
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/20
 */
/**===Include Guard========================================*/
#ifndef	_BUFFER_GL_H_
#define	_BUFFER_GL_H_
/**===File Include=========================================*/
#include	<GLee/GLee.h>
#include	<Render/Buffer/IBuffer.h>
/**===Class Definition=====================================*/
class Buffer:public IBuffer{
public:
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	ディスク
	 *	@param[in]	データ
	 *	@author	KORYUOH
	 */
	Buffer(const BufferDesc& desc,const void* data=0);
	/**
	 *	@brief	デストラクタ
	 *	@author	KORYUOH
	 */
	virtual ~Buffer();
		/**
	 *	@brief	ディスクプリタの取得
	 *	@author	KORYUOH
	 *	@return	BufferDesc
	 */
	virtual const	BufferDesc& desc() const;
	/**
	 *	@brief	設定
	 *	@param[in]	データ
	 *	@author	KORYUOH
	 */
	virtual void	setData(const void* data);
	/**
	 *	@brief	データ取得
	 *	@param[in]	データ
	 *	@author	KORYUOH
	 */
	virtual void	getData(void*	data) const	;
	/**
	 *	@brief	バッファの取得
	 *	@author	KORYUOH
	 *	@return	バッファ
	 */
	GLuint	buffer() const;
private:
	/**	バッファタイプ交換*/
	static GLenum toTarget(BufferType type);
	/**	バッファの使用法を交換*/
	static GLenum toUsage(BufferUsage usage);
	/**	コピー禁止*/
	Buffer (const Buffer& other);
	Buffer& operator = (const Buffer& other);

private:
	/**	ディスクプリタ*/
	BufferDesc	m_desc;
	/**	バッファオブジェクト*/
	GLuint	m_buffer;
	/**	ターゲット*/
	GLenum	m_target;
	/**	使用方法*/
	GLenum	m_usage;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/