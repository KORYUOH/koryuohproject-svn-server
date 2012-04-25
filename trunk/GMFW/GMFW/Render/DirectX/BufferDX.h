/**===File Commentary=======================================*/
/**
 *	@file	Buffer.h
 *
 *	@brief	バッファ
 *
 *	@note	DirectX10
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/20
 */
/**===Include Guard========================================*/
#ifndef	_BUFFER_DX_H_
#define	_BUFFER_DX_H_
/**===File Include=========================================*/
#include	<d3d10.h>
#include	<Render/Buffer/IBuffer.h>
/**===Class Definition=====================================*/
class BufferDX:public IBuffer{
public:
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	ディスク
	 *	@param[in]	データ
	 *	@author	KORYUOH
	 */
	BufferDX(ID3D10Device* devise, const BufferDesc& desc,const void* data=0);
	/**
	 *	@brief	デストラクタ
	 *	@author	KORYUOH
	 */
	virtual ~BufferDX();
		/**
	 *	@brief	ディスクプリタの取得
	 *	@author	KORYUOH
	 *	@return	BufferDesc
	 */
	virtual const	BufferDesc& desc() const;
	/**
	 *	@brief	設定
	 *	@param[in]	データ
	 *	@author	KORYUOH
	 */
	virtual void	setData(const void* data);
	/**
	 *	@brief	データ取得
	 *	@param[in]	データ
	 *	@author	KORYUOH
	 */
	virtual void	getData(void*	data) const	;
	/**
	 *	@brief	バッファの取得
	 *	@author	KORYUOH
	 *	@return	バッファ
	 */
	ID3D10Buffer* buffer() const;
private:

	/**
	 *	@brief	バインドフラグ取得
	 *	@author	KORYUOH
	 *	@return	バインドフラグ
	 */
	UINT bindFlag()const;
	/**
	 *	@brief	バッファ使用法取得
	 *	@author	KORYUOH
	 *	@return	バッファ使用法
	 */
	D3D10_USAGE	Usage() const;
	/**
	 *	@brief	CPUアクセスフラグ取得
	 *	@author	KORYUOH
	 *	@return	アクセスフラグ
	 */
	UINT cpuAccessFlag() const;
	/**
	 *	@brief	コピー禁止
	 *	@author	KORYUOH
	 */
	BufferDX (const BufferDX& other);
	BufferDX& operator = (const BufferDX& other);


private:
	/**	ディスクプリタ*/
	BufferDesc	 m_desc;
	/**	バッファクラス*/
	ID3D10Buffer*	m_Buffer;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/