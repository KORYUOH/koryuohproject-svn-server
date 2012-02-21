/**===File Commentary=======================================*/
/**
 *	@file	Texture.cpp
 *
 *	@brief	テクスチャ実装
 *
 *	@author	KORYUOH
 *
 *	@date	yyyy/mm/dd
 */
/**===File Include=========================================*/
#include	<Render/DirectX/Texture.h>
#include	<memory>
#include	<cassert>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	<要約>
 *	@param[in]	<引数>
 *	@attention	<注意書き>
 *	@note	<メモ書き>
 *	@author	KORYUOH
 *	@return	<戻り値>
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
		device->CreateShaderResourceView(resouse(),&descSR,&m_shaderResouseView,);
		assert( shaderResourceView != NULL);
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
	ID3D10Texture2D* texture2D = static_cast<ID3D10Texture2D*>(resouse());
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
 *	@author	<作者名>
 *	@return	リソース
 */
/**========================================================*/
ID3D10Resource* Texture::resource(){
	return m_resource;
}
/**========================================================*/
/**
 *	@brief	<要約>
 *	@param[in]	<引数>
 *	@attention	<注意書き>
 *	@note	<メモ書き>
 *	@author	<作者名>
 *	@return	<戻り値>
 */
/**========================================================*/







}










/**===End Of File==========================================*/