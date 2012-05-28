/**===File Commentary=======================================*/
/**
 *	@file	InetSocketAddress.cpp
 *
 *	@brief	インターネットソケットアドレスクラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/08
 */
/**===File Include=========================================*/
#include	<Network/InetSocketAddress/InetSocketAddress.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	インターネットアドレス
 *	@param[in]	ポート番号
 */
/**========================================================*/
InetSocketAddress::InetSocketAddress(const InetAddress& address,int port)
	:mAddress(address)
	,mPort(port)
{	
}
/**========================================================*/
/**
 *	@brief	インターネットアドレスの取得
 *	@return	インターネットアドレス
 */
/**========================================================*/
const InetAddress& InetSocketAddress::getInetAddress()const{
	return mAddress;
}
/**========================================================*/
/**
 *	@brief	ポート番号の取得
 *	@return	ポート番号
 */
/**========================================================*/
int InetSocketAddress::getPort()const{
	return mPort;
}
/**===End Of File==========================================*/