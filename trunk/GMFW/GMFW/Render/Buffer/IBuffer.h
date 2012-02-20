/**===File Commentary=======================================*/
/**
 *	@file	<ヘッダーファイル名>.h
 *
 *	@brief	<要約>
 *
 *	@attention	<注意書き>
 *
 *	@note	<メモ書き>
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/20
 */
/**===Include Guard========================================*/
#ifndef	_H_
#define	_H_
/**===File Include=========================================*/
#include	<Render/Buffer/BufferDesc.h>
/**===Class Definition=====================================*/
class IBuffer{
public:
	/**
	 *	@brief	デストラクタ
	 *	@author	KORYUOH
	 */
	virtual	~IBuffer()	{};
	/**
	 *	@brief	ディスクプリタの取得
	 *	@author	KORYUOH
	 *	@return	BufferDesc
	 */
	virtual const	BufferDesc& desc() const	=0;
	/**
	 *	@brief	設定
	 *	@param[in]	データ
	 *	@author	KORYUOH
	 */
	virtual void	setData(const void* data)	=0;
	/**
	 *	@brief	データ取得
	 *	@param[in]	データ
	 *	@author	KORYUOH
	 */
	virtual void	getData(void*	data) const	=0;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/