/**===File Commentary=======================================*/
/**
 *	@file	Socket.h
 *
 *	@brief	ソケットクラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/15
 */
/**===Include Guard========================================*/
#ifndef	_SOCKET_H_
#define	_SOCKET_H_
/**===File Include=========================================*/
#include	<Network/InetSocketAddress/InetSocketAddress.h>
#include	<Network/SocketException/SocketException.h>
#include	<string>
#include	<memory>
class SocketImpl;
/**===Class Definition=====================================*/
class Socket{
public:
	/**
	 *	@brief	コンストラクタ
	 */
	Socket();
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	ソケットアドレス
	 */
	Socket(const InetSocketAddress& adress);
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	ネットアドレス
	 *	@param[in]	ポート番号
	 */
	Socket(const InetAddress& adress,int port);
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	ホスト名
	 *	@param[in]	ポート番号	
	 */
	Socket(const std::string& host,int port);
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	ソケット実装クラス
	 */
	Socket(SocketImpl* impl);
	/**
	 *	@brief	デストラクタ
	 */
	virtual ~Socket();
	/**
	 *	@brief	ソケット接続
	 *	@param[in]	ソケットアドレス
	 */
	void connect(const InetSocketAddress& adress);
	/**
	 *	@brief	ソケット接続
	 *	@param[in]	ネットアドレス
	 *	@param[in]	ポート番号
	 */
	void connect(const InetAddress& adress,int port);
	/**
	 *	@brief	ソケット接続
	 *	@param[in]	ホスト名	
	 *	@param[in]	ポート番号
	 */
	void connect(const std::string& host,int port);
	/**
	 *	@brief	ソケット閉鎖
	 */
	void close();
	/**
	 *	@brief	データ送信
	 *	@param[in]	バッファ
	 *	@param[in]	サイズ
	 *	@return	フラグ
	 */
	int send(const void*baffer,int size);
	/**
	 *	@brief	文字列送信
	 *	@param[in]	文字列
	 *	@return	フラグ
	 */
	int send(const std::string& msg);
	/**
	 *	@brief	データ受信
	 *	@param[in]	データ
	 *	@param[in]	サイズ
	 */
	int receive(void* baffer,int size);
	/**
	 *	@brief	メッセージ受信
	 *	@return	メッセージ
	 */
	std::string receive();
	/**
	 *	@brief	アドレス取得
	 *	@return	ソケットアドレス
	 */
	InetAddress getAddress()const;
	/**
	 *	@brief	ポート番号取得
	 *	@return	ポート番号
	 */
	int getport()const;
	/**
	 *	@brief	ローカルアドレス取得
	 *	@return	ローカルアドレス
	 */
	InetAddress getLocalAddress()const;
	/**
	 *	@brief	ローカルポート取得
	 *	@return	ポート
	 */
	int getLocalPort()const;
	/**
	 *	@brief	接続中か調べる
	 *	@return	接続中なら真
	 */
	bool isConnected()const;
	/**
	 *	@brief	終了処理
	 */
	void shutdown(int how=Socket::SHUTDOWN_BOTH);
public:
	/** 受信をシャットダウン */
	const static int SHUTDOWN_SEND;
	/** 送信をシャットダウン */
	const static int SHUTDOWN_RECIEVE;
	/** 両方シャットダウン */
	const static int SHUTDOWN_BOTH;

private:
	/**
	 *	@brief	コピー禁止
	 */
	Socket(const Socket& other);
	Socket& operator = (const Socket& other);


private:
	/**	ソケット実装クラス　*/
	std::unique_ptr<SocketImpl> mImpl;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/