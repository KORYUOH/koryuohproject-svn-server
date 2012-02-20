/**===File Commentary=======================================*/
/**
 *	@file	Buffer.h
 *
 *	@brief	�o�b�t�@
 *
 *	@note	OpenGL��
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
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�f�B�X�N
	 *	@param[in]	�f�[�^
	 *	@author	KORYUOH
	 */
	Buffer(const BufferDesc& desc,const void* data=0);
	/**
	 *	@brief	�f�X�g���N�^
	 *	@author	KORYUOH
	 */
	virtual ~Buffer();
		/**
	 *	@brief	�f�B�X�N�v���^�̎擾
	 *	@author	KORYUOH
	 *	@return	BufferDesc
	 */
	virtual const	BufferDesc& desc() const;
	/**
	 *	@brief	�ݒ�
	 *	@param[in]	�f�[�^
	 *	@author	KORYUOH
	 */
	virtual void	setData(const void* data);
	/**
	 *	@brief	�f�[�^�擾
	 *	@param[in]	�f�[�^
	 *	@author	KORYUOH
	 */
	virtual void	getData(void*	data) const	;
	/**
	 *	@brief	�o�b�t�@�̎擾
	 *	@author	KORYUOH
	 *	@return	�o�b�t�@
	 */
	GLuint	buffer() const;
private:
	/**	�o�b�t�@�^�C�v����*/
	static GLenum toTarget(BufferType type);
	/**	�o�b�t�@�̎g�p�@������*/
	static GLenum toUsage(BufferUsage usage);
	/**	�R�s�[�֎~*/
	Buffer (const Buffer& other);
	Buffer& operator = (const Buffer& other);

private:
	/**	�f�B�X�N�v���^*/
	BufferDesc	m_desc;
	/**	�o�b�t�@�I�u�W�F�N�g*/
	GLuint	m_buffer;
	/**	�^�[�Q�b�g*/
	GLenum	m_target;
	/**	�g�p���@*/
	GLenum	m_usage;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/