/**===File Commentary=======================================*/
/**
 *	@file	SocketImpl.h
 *
 *	@brief	ソケット実装クラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/08
 */
/**===Include Guard========================================*/
#ifndef	_SOCKETIMPL_H_
#define	_SOCKETIMPL_H_
/**===File Include=========================================*/
#include	<WinSock2.h>
#include	<Network/InetSocketAddress/InetSocketAddress.h>
/**===Class Definition=====================================*/
class SocketImpl{
public:
	/**
	 *	@brief	コンストラクタ
	 */
	SocketImpl();
	/**
	 *	@brief	デストラクタ
	 */
	~SocketImpl();
	/**
	 *	@brief	ソケットの接続
	 *	@param[in]	ソケットアドレス
	 */
	void connect(const InetSocketAddress& address);
	/**
	 *	@brief	ソケットの閉鎖
	 */
	void close();
	/**
	 *	@brief	データ送信
	 *	@param[in]	データバッファ
	 *	@param[in]	バッファサイズ
	 *	@return	状態
	 */
	int send(const void* buffer ,int size);
	/**
	 *	@brief	データ受信
	 *	@param[in]	データバッファ
	 *	@param[in]	データサイズ
	 *	@return	状態
	 */
	int receive(void * buffer ,int size);
	/**
	 *	@brief	接続の受け入れ
	 *	@return	自身
	 */
	SocketImpl* accept();
	/**
	 *	@brief	ポートにソケットを接続
	 *	@param[in]	ポート番号
	 */
	void bind (int port);
	/**
	 *	@brief	ソケットをlisten状態に
	 *	@param[in]	バックログ
	 */
	void listen(int backlog = 0);
	/**
	 *	@brief	ソケットをシャットダウンする
	 *	@param[in]	どれくらい
	 */
	void shutdown(int how);
	/**
	 *	@brief	接続先のソケットアドレスを取得
	 *	@return	ソケットアドレス
	 */
	InetSocketAddress getInetSocketAddress()const;
	/**
	 *	@brief	ローカルのソケットアドレスを取得
	 *	@return	ソケットアドレス
	 */
	InetSocketAddress getLocalInetSocketAddress()const;
	/**
	 *	@brief	接続中か確認
	 *	@return	接続中ならtrue
	 */
	bool isConnect() const;
private:
	/**
	 *	@brief	コピーの禁止
	 */
	SocketImpl(const SocketImpl& other);
	SocketImpl& operator = (const SocketImpl& other);
public:
	/**	受信をシャットダウン */
	const static int SHUTDOWN_RECEIVE;
	/**	送信をシャットダウン */
	const static int SHUTDOWN_SEND;
	/**	送受信をシャットダウン */
	const static int SHUTDOWN_BOTH;
private:
	/**	ソケットハンドラ*/
	SOCKET	mSocket;
	/**	ソケットアドレス */
	InetSocketAddress	mSocketAddress;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/