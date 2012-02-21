/**===File Commentary=======================================*/
/**
 *	@file	Texture.h
 *
 *	@brief	�e�N�X�`���N���X
 *
 *	@note	DirectX10
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/21
 */
/**===Include Guard========================================*/
#ifndef	_TEXTURE_DX10_H_
#define	_TEXTURE_DX10_H_
/**===File Include=========================================*/
#include	<Render/Texture/ITexture.h>
#include	<d3d10.h>
/**===Class Definition=====================================*/
class Texture:public ITexture{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�f�o�C�X
	 *	@param[in]	�f�B�X�N�v���^
	 *	@param[in]	�f�[�^
	 *	@author	KORYUOH
	 */
	Texture( ID3D10Device* device	,const TextureDesc& desc, const void* data);
	/**
	 *	@brief	�f�X�g���N�^
	 *	@author	KORYUOH
	 */
	virtual ~Texture();
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
	 *	@param[in]	�f�[�^�擾
	 *	@author	KORYUOH
	 */
	virtual void getData(void* data);
	/**
	 *	@brief	�T�C�Y�擾
	 *	@author	KORYUOH
	 *	@return	�T�C�Y
	 */
	virtual unsigned int size()const;
	/**
	 *	@brief	���\�[�X�擾
	 *	@author	KORYUOH
	 *	@return	���\�[�X
	 */
	ID3D10Resource* resource();
	/**
	 *	@brief	�V�F�[�_�[���\�[�X�r���[�擾
	 *	@author	KORYUOH
	 *	@return	�V�F�[�_�[���\�[�X�r���[
	 */
	ID3D10ShaderResourceView* shaderResourceView();
protected:
	/** �s�N�Z���t�H�[�}�b�g�\���� */
	struct Pixel{
		DXGI_FORMAT	resourceFormat;		//���\�[�X�t�H�[�}�b�g
		DXGI_FORMAT	shaderFormat;		//�V�F�[�_�[�t�H�[�}�b�g
		DXGI_FORMAT	depthStencilFormat;	//�f�v�X�E�X�e���V���r���[�t�H�[�}�b�g
		unsigned int	size;					//1�s�N�Z���̃o�C�g�T�C�Y
		bool	complessed;						//���k�t�H�[�}�b�g���H
		bool	depthStencil;						//�f�v�X�E�X�e���V���p�t�H�[�}�b�g���H
	};
	/**
	 *	@brief	�s�N�Z���t�H�[�}�b�g�擾
	 *	@author	KORYUOH
	 *	@return	�s�N�Z���t�H�[�}�b�g
	 */
	const Pixel& pixel () const;
	/**
	 *	@brief	�e�N�X�`���̎g�p�@�擾
	 *	@author	KORYUOH
	 *	@return	�e�N�X�`���g�p�@
	 */
	D3D10_USAGE	usage() const;
	/**
	 *	@brief	CPU�A�N�Z�X�t���O�擾
	 *	@author	KORYUOH
	 *	@return	CPU�A�N�Z�X�t���O
	 */
	UINT cpuAccessFlags() const;
	/**
	 *	@brief	�o�C���h�t���O�擾
	 *	@author	KORYUOH
	 *	@return	�o�C���h�t���O
	 */
	UINT bindFlags() const;
	/**
	 *	@brief	�I�v�V�����t���O�擾
	 *	@author	KORYUOH
	 *	@return	�I�v�V�����t���O
	 */
	UINT miscFlags() const;
private:
	/**
	 *	@brief	�R�s�[�֎~
	 *	@author	KORYUOH
	 */
	Texture( const Texture& other);
	Texture& operator = (const Texture& other );

private:
	/**	�f�B�X�N�v���^*/
	TextureDesc		m_desc;
	/**	���\�[�X*/
	ID3D10Resource*	m_resource;
	/**	�V�F�[�_�[���\�[�X�r���[*/
	ID3D10ShaderResourceView*	m_shaderResouseView;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/