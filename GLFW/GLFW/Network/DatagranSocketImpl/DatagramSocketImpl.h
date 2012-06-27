/**===File Commentary=======================================*/
/**
 *	@file	DatagramSocketImpl.h
 *
 *	@brief	UDPソケット実装クラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/05
 */
/**===Include Guard========================================*/
#ifndef	_DATAGRAMSOCKETIMPL_H_
#define	_DATAGRAMSOCKETIMPL_H_
/**===File Include=========================================*/
#include	<WinSock2.h>
class InetSocketAddress;
/**===Class Definition=====================================*/
class DatagramSocketImpl{
public:
	/**
	 *	@brief	コンストラクタ
	 */
	DatagramSocketImpl();
	/**
	 *	@brief	デストラクタ
	 */
	~DatagramSocketImpl();
	/**
	 *	@brief	UDPソケット作成
	 */
	void create();
	/**
	 *	@brief	ソケット閉鎖
	 */
	void close();
	/**
	 *	@brief	バインド
	 *	@param[in]	ポート番号
	 */
	void bind(int port);
	/**
	 *	@brief	送信
	 *	@param[in]	バッファ
	 *	@param[in]	サイズ
	 *	@param[in]	ソケットアドレス
	 *	@return	ソケット
	 */
	int send(const void* buffer,int size ,const InetSocketAddress& addr);
	/**
	 *	@brief	受信
	 *	@param[in]	バッファ
	 *	@param[in]	サイズ
	 *	@param[in]	アドレス
	 *	@return	整数
	 */
	int receive( void* buffer,int size,InetSocketAddress& addr);

private:
	/**
	 *	@brief	コピー禁止
	 */
	DatagramSocketImpl(const DatagramSocketImpl& other);
	DatagramSocketImpl& operator=(const DatagramSocketImpl& other);

private:
	/**	メンバー変数*/
	SOCKET	mSocket;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/