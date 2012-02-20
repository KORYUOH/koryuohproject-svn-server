/**===File Commentary=======================================*/
/**
 *	@file	BufferDesc.h
 *
 *	@brief	パラメータ格納
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/20
 */
/**===Include Guard========================================*/
#ifndef	_BUFFER_DESC_H_
#define	_BUFFER_DESC_H_
/**===File Include=========================================*/

/**===eNum Definition=====================================*/
enum BufferUsage{
	BUFFER_USAGE_DEFAULT		=0,	// デフォルト
	BUFFER_USAGE_IMMUTABLE	=1,	// 作成時のみ
	BUFFER_USAGE_DYNAMIC		=2	// 頻繁に書き込み
};
/**===eNum Definition=====================================*/
enum BufferType{
	BUFFER_TYPE_VERTEX	=0,	// 頂点バッファ
	BUFFER_TYPE_INDEX	=1	// インデックスバッファ
};
/**===Struct Definition=====================================*/
struct BufferDesc{
	//バッファタイプ
	BufferType	_type;
	//使用法
	BufferUsage	_usage;
	//データのバイト数
	unsigned int	_size;
	//コンストラクタ
	BufferDesc():
			_type(BUFFER_TYPE_VERTEX),
			_usage(BUFFER_USAGE_IMMUTABLE),
			_size(0)
		{}
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/