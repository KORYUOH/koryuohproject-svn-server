/**===File Commentary=======================================*/
/**
 *	@file	ITexture.h
 *
 *	@brief	�e�N�X�`���C���^�[�t�F�[�X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/20
 */
/**===Include Guard========================================*/
#ifndef	_ITEXTURE_H_
#define	_ITEXTURE_H_
/**===File Include=========================================*/
#include	<Render/Texture/Texture_Desc.h>
/**===Class Definition=====================================*/
class ITexture{
public:
	/**
	 *	@brief	�f�X�g���N�^
	 *	@author	KORYUOH
	 */
	virtual ~ITexture(){}
	/**
	 *	@brief	�f�B�X�N�v���^�擾
	 *	@author	KORYUOH
	 *	@return	�f�B�X�N�v���^
	 */
	virtual const TextureDesc& desc() const =0;
	/**
	 *	@brief	�f�[�^�ݒ�
	 *	@param[in]	�f�[�^
	 *	@author	KORYUOH
	 */
	virtual void setData( const void* Data) =0;
	/**
	 *	@brief	�f�[�^�擾
	 *	@param[in]	�f�[�^
	 *	@author	KORYUOH
	 */
	virtual void getData(void* data)	=0;
	/**
	 *	@brief	�C���[�W�T�C�Y�擾
	 *	@author	KORYUOH
	 *	@return	�C���[�W�T�C�Y
	 */
	virtual unsigned int size() const =0;


};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/