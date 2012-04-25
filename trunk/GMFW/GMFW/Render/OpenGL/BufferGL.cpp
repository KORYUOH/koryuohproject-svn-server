/**===File Commentary=======================================*/
/**
 *	@file	Buffer.cpp
 *
 *	@brief	バッファ
 *
 *	@note	OpenGL版
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/20
 */
/**===File Include=========================================*/
#include	<Render/OpenGL/BufferGL.h>
#include	<memory>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	ディスクプリタ
 *	@param[in]	データ
 *	@author	KORYUOH
 */
/**========================================================*/
BufferGL::BufferGL(const BufferDesc& desc, const void* data):
m_desc(desc),
	m_target(toTarget(desc._type)),
	m_usage(toUsage(desc._usage)){
		//バッファ作成
		glGenBuffersARB(1,&m_buffer);
		glBindBufferARB(m_target,m_buffer);
		glBufferDataARB(m_target,m_desc._size,data,m_usage);
		glBindBufferARB(m_target,0);
}
/**========================================================*/
/**
 *	@brief	デストラクタ
 *	@author	KORYUOH
 */
/**========================================================*/
BufferGL::~BufferGL(){
	//バッファ削除
	glDeleteBuffersARB(1,&m_buffer);
}
/**========================================================*/
/**
 *	@brief	ディスクプリタ取得
 *	@author	KORYUOH
 *	@return	ディスクプリタ
 */
/**========================================================*/
const BufferDesc& BufferGL::desc()const{
	return m_desc;
}
/**========================================================*/
/**
 *	@brief	データの設定
 *	@param[in]	データ
 *	@author	KORYUOH
 */
/**========================================================*/
void BufferGL::setData(const void* data){
	glBindBufferARB(m_target,m_buffer);
	void* buf = glMapBufferARB(m_target,GL_WRITE_ONLY_ARB);
	std::memcpy(buf,data,m_desc._size);
	glUnmapBufferARB(m_target);
	glBindBufferARB(m_target,0);
}
/**========================================================*/
/**
 *	@brief	データ取得
 *	@param[in]	データ
 *	@author	KORYUOH
 */
/**========================================================*/
void BufferGL::getData(void* data)const {
	glBindBufferARB(m_target,m_buffer);
	void* buf = glMapBufferARB(m_target,GL_READ_ONLY_ARB);
	std::memcpy(buf,data,m_desc._size);
	glUnmapBufferARB(m_target);
	glBindBufferARB(m_target,0);
}
/**========================================================*/
/**
 *	@brief	バッファ取得
 *	@author	KORYUOH
 *	@return	バッファ
 */
/**========================================================*/
GLuint BufferGL::buffer()const{
	return m_buffer;
}
/**========================================================*/
/**
 *	@brief	バッファタイプ変更
 *	@param[in]	タイプ
 *	@author	KORYUOH
 *	@return	バッファタイプ
 */
/**========================================================*/
GLenum	BufferGL::toTarget(BufferType type){
	static const GLenum targets[] = {
		GL_ARRAY_BUFFER_ARB,		// BUFFER_TYPE_VERTEX		=0
		GL_ELEMENT_ARRAY_BUFFER_ARB		// BUFFER_TYPE_INDEX		=1
	};
	return	targets[type];
}

/**========================================================*/
/**
 *	@brief	使用法を取得
 *	@param[in]	使用法
 *	@author	KORYUOH
 *	@return	使用法
 */
/**========================================================*/
GLenum BufferGL::toUsage(BufferUsage usage){
	static const GLenum usages[] = {
		GL_STREAM_DRAW,		//BUFFER_USAGE_DEFAULT		 = 0
		GL_STATIC_DRAW,		//BUFFER_USAGE_IMMUTABLE	 = 1
		GL_DYNAMIC_DRAW	//BUFFER_USAGE_DYNAMIC		 = 2
	};
	return usages[usage];
}



/**===End Of File==========================================*/