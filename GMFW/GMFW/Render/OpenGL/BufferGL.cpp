/**===File Commentary=======================================*/
/**
 *	@file	Buffer.cpp
 *
 *	@brief	�o�b�t�@
 *
 *	@note	OpenGL��
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
 *	@brief	�R���X�g���N�^
 *	@param[in]	�f�B�X�N�v���^
 *	@param[in]	�f�[�^
 *	@author	KORYUOH
 */
/**========================================================*/
BufferGL::BufferGL(const BufferDesc& desc, const void* data):
m_desc(desc),
	m_target(toTarget(desc._type)),
	m_usage(toUsage(desc._usage)){
		//�o�b�t�@�쐬
		glGenBuffersARB(1,&m_buffer);
		glBindBufferARB(m_target,m_buffer);
		glBufferDataARB(m_target,m_desc._size,data,m_usage);
		glBindBufferARB(m_target,0);
}
/**========================================================*/
/**
 *	@brief	�f�X�g���N�^
 *	@author	KORYUOH
 */
/**========================================================*/
BufferGL::~BufferGL(){
	//�o�b�t�@�폜
	glDeleteBuffersARB(1,&m_buffer);
}
/**========================================================*/
/**
 *	@brief	�f�B�X�N�v���^�擾
 *	@author	KORYUOH
 *	@return	�f�B�X�N�v���^
 */
/**========================================================*/
const BufferDesc& BufferGL::desc()const{
	return m_desc;
}
/**========================================================*/
/**
 *	@brief	�f�[�^�̐ݒ�
 *	@param[in]	�f�[�^
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
 *	@brief	�f�[�^�擾
 *	@param[in]	�f�[�^
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
 *	@brief	�o�b�t�@�擾
 *	@author	KORYUOH
 *	@return	�o�b�t�@
 */
/**========================================================*/
GLuint BufferGL::buffer()const{
	return m_buffer;
}
/**========================================================*/
/**
 *	@brief	�o�b�t�@�^�C�v�ύX
 *	@param[in]	�^�C�v
 *	@author	KORYUOH
 *	@return	�o�b�t�@�^�C�v
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
 *	@brief	�g�p�@���擾
 *	@param[in]	�g�p�@
 *	@author	KORYUOH
 *	@return	�g�p�@
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