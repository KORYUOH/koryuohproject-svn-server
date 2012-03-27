/**===File Commentary=======================================*/
/**
 *	@file	Texture.cpp
 *
 *	@brief	テクスチャ実装
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
 *	@brief	コンストラクタ
 *	@param[in]	デバイス
 *	@param[in]	ディスクプリタ
 *	@param[in]	データ
 *	@author	KORYUOH
 */
/**========================================================*/
Texture::Texture( ID3D10Device*	device,const TextureDesc& desc, const void* data):
m_desc(desc),
	m_resource(NULL),
	m_shaderResouseView(NULL){
		//リソース作成
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
		//イメージデータ設定
		D3D10_SUBRESOURCE_DATA	initData;
		initData.pSysMem	=data;
		initData.SysMemPitch	=pixel().size * m_desc.width;
		initData.SysMemSlicePitch	= pixel().size * m_desc.width*m_desc.height;
		ID3D10Texture2D*	texture2D	= NULL;
		device->CreateTexture2D(&descTex, &initData , &texture2D);
		assert( texture2D != NULL);
		m_resource = texture2D;
		//シェーダーリソースビューの作成
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
 *	@brief	デストラクタ
 *	@author	KORYUOH
 */
/**========================================================*/
Texture::~Texture(){
	m_shaderResouseView->Release();
	m_resource->Release();
}
/**========================================================*/
/**
 *	@brief	ディスクプリタ取得
 *	@author	KORYUOH
 *	@return	ディスクプリタ
 */
/**========================================================*/
const TextureDesc& Texture::desc() const{
	return m_desc;
}
/**========================================================*/
/**
 *	@brief	データ設定
 *	@param[in]	データ
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
 *	@brief	データ取得
 *	@param[in]	データ
 *	@author	KORYUOH
 */
/**========================================================*/
void Texture::getData(void* data){
	//デバイス取得
	ID3D10Device* device = NULL;
	m_resource->GetDevice(&device);
	//読み込みバッファ作成
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
	//読み込みバッファにコピー
	device->CopyResource(readBuffer,m_resource);
	//読み込みバッファからデータコピー
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
 *	@brief	データサイズ取得
 *	@author	KORYUOH
 *	@return	データサイズ
 */
/**========================================================*/
unsigned int Texture::size()const{
	return desc().width*desc().height*pixel().size;
}
/**========================================================*/
/**
 *	@brief	リソース取得
 *	@author	KORYUOH
 *	@return	リソース
 */
/**========================================================*/
ID3D10Resource* Texture::resource(){
	return m_resource;
}
/**========================================================*/
/**
 *	@brief	シェーダーリソースビュー取得
 *	@author	KORYUOH
 *	@return	シェーダーリソースビュー
 */
/**========================================================*/
ID3D10ShaderResourceView* Texture::shaderResourceView(){
	return m_shaderResouseView;
}
/**========================================================*/
/**
 *	@brief	ピクセルフォーマット取得
 *	@author	KORYUOH
 *	@return	ピクセルフォーマット
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
 *	@brief	テクスチャ使用法取得
 *	@author	KORYUOH
 *	@return	テクスチャ使用法
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
 *	@brief	CPUアクセスフラグ取得
 *	@author	KORYUOH
 *	@return	CPUアクセスフラグ
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
 *	@brief	バインドフラグ取得
 *	@author	KORYUOH
 *	@return	バインドフラグ
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
 *	@brief	オプションフラグ取得
 *	@author	KORYUOH
 *	@return	オプションフラグ
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