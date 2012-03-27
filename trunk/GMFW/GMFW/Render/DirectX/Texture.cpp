/**===File Commentary=======================================*/
/**
 *	@file	Texture.cpp
 *
 *	@brief	�e�N�X�`������
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/21
 */
/**===File Include=========================================*/
#include	<Render/DirectX/Texture.h>
#include	<memory>
#include	<cassert>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�f�o�C�X
 *	@param[in]	�f�B�X�N�v���^
 *	@param[in]	�f�[�^
 *	@author	KORYUOH
 */
/**========================================================*/
Texture::Texture( ID3D10Device*	device,const TextureDesc& desc, const void* data):
m_desc(desc),
	m_resource(NULL),
	m_shaderResouseView(NULL){
		//���\�[�X�쐬
		D3D10_TEXTURE2D_DESC descTex;
		descTex.Width			=m_desc.width;
		descTex.Height		=m_desc.height;
		descTex.MipLevels	=m_desc.mipLevels;
		descTex.ArraySize	=1;
		descTex.SampleDesc.Count	=1;
		descTex.SampleDesc.Quality	=0;
		descTex.Format		=pixel().resourceFormat;
		descTex.Usage			=usage();
		descTex.BindFlags	=bindFlags();
		descTex.CPUAccessFlags	=cpuAccessFlags();
		descTex.MiscFlags	=miscFlags();
		//�C���[�W�f�[�^�ݒ�
		D3D10_SUBRESOURCE_DATA	initData;
		initData.pSysMem	=data;
		initData.SysMemPitch	=pixel().size * m_desc.width;
		initData.SysMemSlicePitch	= pixel().size * m_desc.width*m_desc.height;
		ID3D10Texture2D*	texture2D	= NULL;
		device->CreateTexture2D(&descTex, &initData , &texture2D);
		assert( texture2D != NULL);
		m_resource = texture2D;
		//�V�F�[�_�[���\�[�X�r���[�̍쐬
		D3D10_SHADER_RESOURCE_VIEW_DESC	descSR;
		descSR.Format	= pixel().shaderFormat;
		descSR.ViewDimension	=D3D10_SRV_DIMENSION_TEXTURE2D;
		descSR.Texture2D.MipLevels	= m_desc.mipLevels;
		descSR.Texture2D.MostDetailedMip	=0;
		device->CreateShaderResourceView(resource(),&descSR,&m_shaderResouseView);
		assert( m_shaderResouseView != NULL);
}
/**========================================================*/
/**
 *	@brief	�f�X�g���N�^
 *	@author	KORYUOH
 */
/**========================================================*/
Texture::~Texture(){
	m_shaderResouseView->Release();
	m_resource->Release();
}
/**========================================================*/
/**
 *	@brief	�f�B�X�N�v���^�擾
 *	@author	KORYUOH
 *	@return	�f�B�X�N�v���^
 */
/**========================================================*/
const TextureDesc& Texture::desc() const{
	return m_desc;
}
/**========================================================*/
/**
 *	@brief	�f�[�^�ݒ�
 *	@param[in]	�f�[�^
 *	@author	KORYUOH
 */
/**========================================================*/
void Texture::setData(const void* data){
	assert(m_desc.usage_ == TEXTURE_USAGE_DYNAMIC);
	ID3D10Texture2D* texture2D = static_cast<ID3D10Texture2D*>(resource());
	D3D10_MAPPED_TEXTURE2D mapped;
	texture2D->Map(0,D3D10_MAP_WRITE_DISCARD,0,&mapped);
	const BYTE* src = static_cast<const BYTE*>(data);
	BYTE* dst = static_cast<BYTE*>(mapped.pData);
	UINT srcRowPitch =pixel().size*desc().width;
	for(UINT y =0;y<desc().height;++y){
		std::memcpy(dst,src,srcRowPitch);
		src+=srcRowPitch;
		dst += mapped.RowPitch;
	}
	texture2D->Unmap(0);
}
/**========================================================*/
/**
 *	@brief	�f�[�^�擾
 *	@param[in]	�f�[�^
 *	@author	KORYUOH
 */
/**========================================================*/
void Texture::getData(void* data){
	//�f�o�C�X�擾
	ID3D10Device* device = NULL;
	m_resource->GetDevice(&device);
	//�ǂݍ��݃o�b�t�@�쐬
	D3D10_TEXTURE2D_DESC descTex;
	descTex.Width				=desc().width;
	descTex.Height			=desc().height;
	descTex.MipLevels		=desc().mipLevels;
	descTex.ArraySize		=1;
	descTex.SampleDesc.Count	=1;
	descTex.SampleDesc.Quality	=0;
	descTex.Format			=pixel().resourceFormat;
	descTex.Usage				=D3D10_USAGE_STAGING;
	descTex.CPUAccessFlags	=D3D10_CPU_ACCESS_READ;
	descTex.BindFlags		=0;
	descTex.MiscFlags		=0;
	ID3D10Texture2D*	readBuffer	=NULL;
	device->CreateTexture2D(&descTex,0,&readBuffer);
	//�ǂݍ��݃o�b�t�@�ɃR�s�[
	device->CopyResource(readBuffer,m_resource);
	//�ǂݍ��݃o�b�t�@����f�[�^�R�s�[
	ID3D10Texture2D* texture2D = static_cast<ID3D10Texture2D *>(readBuffer);
	D3D10_MAPPED_TEXTURE2D mapped;
	texture2D->Map(0,D3D10_MAP_READ,0,&mapped);
	const BYTE* src = static_cast<const BYTE*>(mapped.pData);
	BYTE* dst = static_cast<BYTE*>(data);
	UINT	dstRowPitch	=pixel().size * desc().width;
	for(UINT y =0;y < desc().height;++y){
		std::memcpy(dst,src,dstRowPitch);
		src += mapped.RowPitch;
		dst += dstRowPitch;
	}
	texture2D->Unmap(0);
	readBuffer->Release();
	device->Release();
}
/**========================================================*/
/**
 *	@brief	�f�[�^�T�C�Y�擾
 *	@author	KORYUOH
 *	@return	�f�[�^�T�C�Y
 */
/**========================================================*/
unsigned int Texture::size()const{
	return desc().width*desc().height*pixel().size;
}
/**========================================================*/
/**
 *	@brief	���\�[�X�擾
 *	@author	KORYUOH
 *	@return	���\�[�X
 */
/**========================================================*/
ID3D10Resource* Texture::resource(){
	return m_resource;
}
/**========================================================*/
/**
 *	@brief	�V�F�[�_�[���\�[�X�r���[�擾
 *	@author	KORYUOH
 *	@return	�V�F�[�_�[���\�[�X�r���[
 */
/**========================================================*/
ID3D10ShaderResourceView* Texture::shaderResourceView(){
	return m_shaderResouseView;
}
/**========================================================*/
/**
 *	@brief	�s�N�Z���t�H�[�}�b�g�擾
 *	@author	KORYUOH
 *	@return	�s�N�Z���t�H�[�}�b�g
 */
/**========================================================*/
const Texture::Pixel&  Texture::pixel() const{
	static const Pixel pixelFormat[] = {
		//TEXTURE_FORMAT_RGBA8
		{ DXGI_FORMAT_R8G8B8A8_TYPELESS, DXGI_FORMAT_R10G10B10A2_UNORM, DXGI_FORMAT_UNKNOWN, sizeof(BYTE)*4,false,false}
	};
	return pixelFormat[0];
}
/**========================================================*/
/**
 *	@brief	�e�N�X�`���g�p�@�擾
 *	@author	KORYUOH
 *	@return	�e�N�X�`���g�p�@
 */
/**========================================================*/
D3D10_USAGE Texture::usage() const{
	static const D3D10_USAGE usages[] ={
		D3D10_USAGE_DEFAULT,
		D3D10_USAGE_IMMUTABLE,
		D3D10_USAGE_DYNAMIC
	};
	return usages[m_desc.usage_];
}
/**========================================================*/
/**
 *	@brief	CPU�A�N�Z�X�t���O�擾
 *	@author	KORYUOH
 *	@return	CPU�A�N�Z�X�t���O
 */
/**========================================================*/
UINT Texture::cpuAccessFlags() const{
	static const UINT cpuAccessFlags[] = {
		0,										//TEXTURE_USAGE_DEFALT
		0,										//TEXTURE_USAGE_IMMUTABLE
		D3D10_CPU_ACCESS_WRITE	//TEXTURE_USAGE_DYNAMIC
	};
	return cpuAccessFlags[m_desc.usage_];
}
/**========================================================*/
/**
 *	@brief	�o�C���h�t���O�擾
 *	@author	KORYUOH
 *	@return	�o�C���h�t���O
 */
/**========================================================*/
UINT Texture::bindFlags() const{
	UINT bindFlags = D3D10_BIND_SHADER_RESOURCE;
	if(pixel().depthStencilFormat){
		bindFlags |= D3D10_BIND_DEPTH_STENCIL;
	}else if(m_desc.renderTarget_){
		bindFlags |= D3D10_BIND_RENDER_TARGET;
	}
	return bindFlags;
}
/**========================================================*/
/**
 *	@brief	�I�v�V�����t���O�擾
 *	@author	KORYUOH
 *	@return	�I�v�V�����t���O
 */
/**========================================================*/
UINT Texture::miscFlags() const{
	UINT miscFlag = 0;
	if(m_desc.type_ == TEXTURE_TYPE_CUBE){
		miscFlag |= D3D10_RESOURCE_MISC_TEXTURECUBE;
	}
	if(m_desc.renderTarget_ && m_desc.mipLevels > 1){
		miscFlag |= D3D10_RESOURCE_MISC_GENERATE_MIPS;
	}
	return miscFlag;
}















/**===End Of File==========================================*/