/**===File Commentary=======================================*/
/**
 *	@file	Texture.h
 *
 *	@brief	�e�N�X�`���N���X
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
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�f�B�X�N�v���^
	 *	@param[in]	�f�[�^
	 *	@author	KORYUOH
	 */
	TextureGL(const TextureDesc& desc, const void * data);
	/**
	 *	@brief	�f�X�g���N�^
	 *	@author	KORYUOH
	 */
	virtual ~TextureGL();
	/**
	 *	@brief	�f�B�X�N�v���^�擾
	 *	@author	KORYUOH
	 *	@return	�f�B�X�N�v���^
	 */
	virtual const TextureDesc& desc() const;
	/**
	 *	@brief	�f�[�^�ݒ�
	 *	@param[in]	�f�[�^
	 *	@author	KORYUOH
	 */
	virtual void setData(const void* data);
	/**
	 *	@brief	�f�[�^�擾
	 *	@param[in]	�f�[�^
	 *	@author	KORYUOH
	 */
	virtual void getData(void* data);
	/**
	 *	@brief	�T�C�Y�擾
	 *	@author	KORYUOH
	 *	@return	�T�C�Y
	 */
	virtual unsigned int size() const;

	/**
	 *	@brief	�^�[�Q�b�g�擾
	 *	@author	KORYUOH
	 *	@return	�^�[�Q�b�g���
	 */
	GLenum target() const;
	/**
	 *	@brief	�e�N�X�`�����擾
	 *	@author	KORYUOH
	 *	@return	�e�N�X�`�����
	 */
	GLuint texture() const;

protected:
	/** �e�N�X�`���^�C�v�\���� */
	struct Type{
		GLenum			target;
		GLenum			arrayTarget;
		unsigned int	arraySize;
	};
	/** �s�N�Z���t�H�[�}�b�g�^�\���� */
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
	 *	@brief	������
	 *	@param[in]	�f�[�^
	 *	@author	KORYUOH
	 */
	void initialize( const void* data);
	/**
	 *	@brief	�s�N�Z���t�H�[�}�b�g�擾
	 *	@author	KORYUOH
	 */
	const Pixel& pixel() const;

private:
	/**
	 *	@brief	�e�N�X�`���^�C�v�ϊ�
	 *	@param[in]	�e�N�X�`���^�C�v
	 *	@author	KORYUOH
	 *	@return	�e�N�X�`��
	 */
	static const Type& toType(TextureType type);

	/**
	 *	@brief	�R�s�[�֎~
	 *	@author	KORYUOH
	 */
	TextureGL(const TextureGL& other);
	TextureGL& operator = (const TextureGL& other);
	
private:
	/** �f�B�X�N�v���^ */
	TextureDesc		m_desc;
	/** �e�N�X�`���^�C�v */
	Type					m_type;
	/** �e�N�X�`���I�u�W�F�N�g */
	GLuint				m_texture;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/