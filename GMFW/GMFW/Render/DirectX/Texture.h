/**===File Commentary=======================================*/
/**
 *	@file	Texture.h
 *
 *	@brief	テクスチャクラス
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
	 *	@brief	コンストラクタ
	 *	@param[in]	デバイス
	 *	@param[in]	ディスクプリタ
	 *	@param[in]	データ
	 *	@author	KORYUOH
	 */
	Texture( ID3D10Device* device	,const TextureDesc& desc, const void* data);
	/**
	 *	@brief	デストラクタ
	 *	@author	KORYUOH
	 */
	virtual ~Texture();
	/**
	 *	@brief	ディスクプリタ取得
	 *	@author	KORYUOH
	 *	@return	ディスクプリタ
	 */
	virtual const TextureDesc& desc() const;
	/**
	 *	@brief	データ設定
	 *	@param[in]	データ
	 *	@author	KORYUOH
	 */
	virtual void setData(const void* data);
	/**
	 *	@brief	データ取得
	 *	@param[in]	データ取得
	 *	@author	KORYUOH
	 */
	virtual void getData(void* data);
	/**
	 *	@brief	サイズ取得
	 *	@author	KORYUOH
	 *	@return	サイズ
	 */
	virtual unsigned int size()const;
	/**
	 *	@brief	リソース取得
	 *	@author	KORYUOH
	 *	@return	リソース
	 */
	ID3D10Resource* resource();
	/**
	 *	@brief	シェーダーリソースビュー取得
	 *	@author	KORYUOH
	 *	@return	シェーダールソースビュー
	 */
	ID3D10ShaderResourceView* shaderResourceView();
protected:
	/** ピクセルフォーマット構造体 */
	struct Pixel{
		DXGI_FORMAT	resourceFormat;		//リソースフォーマット
		DXGI_FORMAT	shaderFormat;		//シェーダーフォーマット
		DXGI_FORMAT	depthStencilFormat;	//デプス・ステンシルビューフォーマット
		unsigned int	size;					//1ピクセルのバイトサイズ
		bool	complessed;						//圧縮フォーマットか？
		bool	depthStencil;						//デプス・ステンシル用フォーマットか？
	};
	/**
	 *	@brief	ピクセルフォーマット取得
	 *	@author	KORYUOH
	 *	@return	ピクセルフォーマット
	 */
	const Pixel& pixel () const;
	/**
	 *	@brief	テクスチャの使用法取得
	 *	@author	KORYUOH
	 *	@return	テクスチャ使用法
	 */
	D3D10_USAGE	usage() const;
	/**
	 *	@brief	CPUアクセスフラグ取得
	 *	@author	KORYUOH
	 *	@return	CPUアクセスフラグ
	 */
	UINT cpuAccessFlags() const;
	/**
	 *	@brief	バインドフラグ取得
	 *	@author	KORYUOH
	 *	@return	バインドフラグ
	 */
	UINT bindFlags() const;
	/**
	 *	@brief	オプションフラグ取得
	 *	@author	KORYUOH
	 *	@return	オプションフラグ
	 */
	UINT miscFlags() const;
private:
	/**
	 *	@brief	コピー禁止
	 *	@author	KORYUOH
	 */
	Texture( const Texture& other);
	Texture& operator = (const Texture& other );

private:
	/**	ディスクプリタ*/
	TextureDesc		m_desc;
	/**	リソース*/
	ID3D10Resource*	m_resource;
	/**	シェーダーリソースビュー*/
	ID3D10ShaderResourceView*	m_shaderResouseView;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/