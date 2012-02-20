/**===File Commentary=======================================*/
/**
 *	@file	Texture_Desc.h
 *
 *	@brief	�e�N�X�`�����\����
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/20
 */
/**===Include Guard========================================*/
#ifndef	_TEXTURE_DESC_H_
#define	_TEXTURE_DESC_H_
/**===File Include=========================================*/

/**===eNum Definition=====================================*/
enum TextureType{
	TEXTURE_TYPE_1D	=0,
	TEXTURE_TYPE_2D,
	TEXTURE_TYPE_3D,
	TEXTURE_TYPE_CUBE
};
/**===eNum Definition=====================================*/
enum	TextureFormat{
	TEXTURE_FORMAT_I8 =0,
	TEXTURE_FORMAT_IA8,
	TEXTURE_FORMAT_RGBA8,
	TEXTURE_FORMAT_I16,
	TEXTURE_FORMAT_IA16,
	TEXTURE_FORMAT_RGBA16,
	TEXTURE_FORMAT_I16F,
	TEXTURE_FORMAT_IA16F,
	TEXTURE_FORMAT_RGBA16F,
	TEXTURE_FORMAT_I32F,
	TEXTURE_FORMAT_IA32F,
	TEXTURE_FORMAT_RGB32F,
	TEXTURE_FORMAT_RGBA32F,
	TEXTURE_FORMAT_R11G11B10F,
	TEXTURE_FORMAT_DXT1,
	TEXTURE_FORMAT_DXT3,
	TEXTURE_FORMAT_DXT5,
	TEXTURE_FORMAT_D16,
	TEXTURE_FORMAT_D32F,
	TEXTURE_FORMAT_D24S8
};
/**===eNum Definition=====================================*/
enum TextureUsage{
	TEXTURE_USAGE_DEFAULT =0,
	TEXTURE_USAGE_IMMUABLE,
	TEXTURE_USAGE_DYNAMIC
};
/**===Struct Definition====================================*/
struct TextureDesc {
	/** �e�N�X�`���^�C�v */
	TextureType type_;
	/** �e�N�X�`���t�H�[�}�b�g*/
	TextureFormat format_;
	/** �� */
	unsigned int width;
	/** ���� */
	unsigned int height;
	/** �[�� */
	unsigned int depth;
	/** �~�b�v�}�b�v���x�� */
	unsigned int mipLevels;
	/** �e�N�X�`���g�p�@ */
	TextureUsage usage_;
	/** �����_�[�^�[�Q�b�g�H */
	bool		renderTarget_;
	/**
	 *	@brief	�R���X�g���N�^
	 *	@author	KORYUOH
	 */
	TextureDesc():
	type_(TEXTURE_TYPE_2D),
		format_(TEXTURE_FORMAT_RGBA8),
		width(1),
		height(1),
		depth(1),
		mipLevels(1),
		usage_(TEXTURE_USAGE_DEFAULT),
		renderTarget_(false)
	{}

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/