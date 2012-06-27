/**===File Commentary=======================================*/
/**
 *	@file	DatagramSocket.cpp
 *
 *	@brief	UDP Socket class
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/05
 */
/**===File Include=========================================*/
#include	<Network/DatagranSocket/DatagramSocket.h>
#include	<Network/DatagranSocketImpl/DatagramSocketImpl.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	コンストラクタ
 */
/**========================================================*/
DatagramSocket::DatagramSocket()
	:mImpl(new DatagramSocketImpl()){
}
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	ポート
 */
/**========================================================*/
DatagramSocket::DatagramSocket(int port)
	:mImpl(new DatagramSocketImpl()){
		bind(port);
}
/**========================================================*/
/**
 *	@brief	デストラクタ
 */
/**========================================================*/
DatagramSocket::~DatagramSocket(){
}
/**========================================================*/
/**
 *	@brief	バインド
 *	@param[in]	ポート
 */
/**========================================================*/
void DatagramSocket::bind(int port){
	mImpl->bind(port);
}
/**========================================================*/
/**
 *	@brief	送信
 *	@param[in]	バッファ
 *	@param[in]	サイズ
 *	@param[in]	アドレス
 *	@return	送信サイズ
 */
/**========================================================*/
int DatagramSocket::send(const void* buffer,int size,const InetSocketAddress& addr){
	return mImpl->send(buffer,size,addr);
}
/**========================================================*/
/**
 *	@brief	受信
 *	@param[in]	バッファ
 *	@param[in]	サイズ
 *	@param[in]	アドレス
 *	@return	受信サイズ
 */
/**========================================================*/
int DatagramSocket::receive(void* buffer,int size,InetSocketAddress& addr){
	return mImpl->receive(buffer,size,addr);
}
/**========================================================*/
/**
 *	@brief	閉鎖
 */
/**========================================================*/
void DatagramSocket::close(){
	mImpl->close();
}



/**===End Of File==========================================*/