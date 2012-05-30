/**===File Commentary=======================================*/
/**
 *	@file	ServerSocket.h
 *
 *	@brief	サーバーソケットクラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/15
 */
/**===Include Guard========================================*/
#ifndef	_SERVERSOCKET_H_
#define	_SERVERSOCKET_H_
/**===File Include=========================================*/
#include	<Network/Socket/Socket/Socket.h>
#include	<memory>
class SocketImpl;
/**===Class Definition=====================================*/
class ServerSocket{
public:
	/**
	 *	@brief	コンストラクタ
	 */
	ServerSocket();
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	ポート
	 *	@param[in]	バックログ
	 */
	ServerSocket(int port,int backLog=0);
	/**
	 *	@brief	デストラクタ
	 */
	virtual ~ServerSocket();
	/**
	 *	@brief	ソケット受入れ
	 *	@return	ソケットポインタ
	 */
	std::unique_ptr<Socket> accept();
	/**
	 *	@brief	バインド
	 *	@param[in]	ポート番号
	 *	@param[in]	バックログ
	 */
	void bind(int port, int backLog =0);
	/**
	 *	@brief	ソケットを閉じる
	 */
	void close();
	/**
	 *	@brief	アドレスを取得
	 *	@return	アドレス
	 */
	InetAddress getAddress()const;
	/**
	 *	@brief	ポート番号取得
	 *	@return	ポート番号
	 */
	int getPort()const;
private:
	/**
	 *	@brief	コピー禁止
	 */
	ServerSocket(const ServerSocket& other);
	ServerSocket& operator = (const ServerSocket& other);
private:
	/**	ソケット実装クラス*/
	std::unique_ptr<SocketImpl> mImpl;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/