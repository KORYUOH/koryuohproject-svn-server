/**===File Commentary=======================================*/
/**
 *	@file	Texture.cpp
 *
 *	@brief	�e�N�X�`��
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
 *	@brief	�R���X�g���N�^
 *	@param[in]	�f�B�X�N�v���^
 *	@param[in]	�f�[�^
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
 *	@brief	�f�X�g���N�^
 *	@author	KORYUOH
 */
/**========================================================*/
TextureGL::~TextureGL(){
	glDeleteTextures(1,&m_texture);
}
/**========================================================*/
/**
 *	@brief	�f�B�X�N�v���^�擾
 *	@author	KORYUOH
 *	@return	�f�B�X�N�v���^
 */
/**========================================================*/
const TextureDesc& TextureGL::desc()const{
	return m_desc;
}
/**========================================================*/
/**
 *	@brief	�f�[�^�ݒ�
 *	@param[in]	�f�[�^
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
 *	@brief	�f�[�^�擾
 *	@param[in]	�f�[�^�i�[��
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
 *	@brief	�T�C�Y�擾
 *	@author	KORYUOH
 *	@return	�T�C�Y
 */
/**========================================================*/
unsigned int TextureGL::size()const{
	return desc().width * desc().height * pixel().size;
}
/**========================================================*/
/**
 *	@brief	�e�N�X�`���擾
 *	@author	KORYUOH
 *	@return	�e�N�X�`��
 */
/**========================================================*/
GLuint TextureGL::texture() const{
	return m_texture;
}
/**========================================================*/
/**
 *	@brief	�^�[�Q�b�g�擾
 *	@author	KORYUOH
 *	@return	�^�[�Q�b�g
 */
/**========================================================*/
GLenum TextureGL::target() const{
	return m_type.target;
}
/**========================================================*/
/**
 *	@brief	�s�N�Z���t�H�[�}�b�g�ϊ�
 *	@author	KORYUOH
 *	@return	�ϊ�����
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
 *	@brief	������
 *	@param[in]	�f�[�^
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
 *	@brief	�^�C�v�ϊ�
 *	@param[in]	�^�C�v
 *	@author	KORYUOH
 *	@return	�ϊ�����
 */
/**========================================================*/
const TextureGL::Type& TextureGL::toType(TextureType type){
	static const Type types[] = {
		{GL_TEXTURE_2D,GL_TEXTURE_2D}
	};
	return types[0];
}


/**===End Of File==========================================*/