/**===File Commentary=======================================*/
/**
 *	@file	ITexture.h
 *
 *	@brief	テクスチャインターフェース
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
	 *	@brief	デストラクタ
	 *	@author	KORYUOH
	 */
	virtual ~ITexture(){}
	/**
	 *	@brief	ディスクプリタ取得
	 *	@author	KORYUOH
	 *	@return	ディスクプリタ
	 */
	virtual const TextureDesc& desc() const =0;
	/**
	 *	@brief	データ設定
	 *	@param[in]	データ
	 *	@author	KORYUOH
	 */
	virtual void setData( const void* Data) =0;
	/**
	 *	@brief	データ取得
	 *	@param[in]	データ
	 *	@author	KORYUOH
	 */
	virtual void getData(void* data)	=0;
	/**
	 *	@brief	イメージサイズ取得
	 *	@author	KORYUOH
	 *	@return	イメージサイズ
	 */
	virtual unsigned int size() const =0;


};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/