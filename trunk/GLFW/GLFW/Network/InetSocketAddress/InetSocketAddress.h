/**===File Commentary=======================================*/
/**
 *	@file	InetSocketAddress.h
 *
 *	@brief	インターネットソケットアドレスクラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/08
 */
/**===Include Guard========================================*/
#ifndef	_INETSOCKETADDRESS_H_
#define	_INETSOCKETADDRESS_H_
/**===File Include=========================================*/
#include	<Network/InetAddress/InetAddress.h>
/**===Class Definition=====================================*/
class InetSocketAddress{
public:
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	InetAddress
	 *	@param[in]	ポート番号
	 *	@author	KORYUOH
	 */
	InetSocketAddress( const InetAddress& address=InetAddress(), int port =0);
	/**
	 *	@brief	インターネットアドレス取得
	 *	@return	インターネットアドレス
	 */
	const InetAddress& getInetAddress()const;
	/**
	 *	@brief	ポート番号の取得
	 *	@return	ポート番号
	 */
	int getPort() const;
private:
	/**	インターネットアドレス */
	InetAddress mAddress;
	/**	ポート番号 */
	int mPort;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/