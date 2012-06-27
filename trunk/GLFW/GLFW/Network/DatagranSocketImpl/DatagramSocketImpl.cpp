/**===File Commentary=======================================*/
/**
 *	@file	DatagramSocketImpl.cpp
 *
 *	@brief	UDPソケット実装クラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/05
 */
/**===File Include=========================================*/
#include	<Network/DatagranSocketImpl/DatagramSocketImpl.h>
#include	<Network/InetSocketAddress/InetSocketAddress.h>
#include	<Network/SocketException/SocketException.h>
#include	<memory>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	コンストラクタ
 */
/**========================================================*/
DatagramSocketImpl::DatagramSocketImpl()
	:mSocket(INVALID_SOCKET){}
/**========================================================*/
/**
 *	@brief	デストラクタ
 */
/**========================================================*/
DatagramSocketImpl::~DatagramSocketImpl(){
	close();
}
/**========================================================*/
/**
 *	@brief	UDPソケット作成
 */
/**========================================================*/
void DatagramSocketImpl::create(){
	if(mSocket != INVALID_SOCKET)
		return;

	mSocket = ::socket(AF_INET , SOCK_DGRAM ,0);
	if(mSocket == INVALID_SOCKET)
		throw SocketException("Can't create UDP Sockets");

}
/**========================================================*/
/**
 *	@brief	ソケット閉鎖
 */
/**========================================================*/
void DatagramSocketImpl::close(){
	if(mSocket != INVALID_SOCKET){
		::closesocket(mSocket);
		mSocket = INVALID_SOCKET;
	}
}
/**========================================================*/
/**
 *	@brief	バインド
 *	@param[in]	ポート番号
 */
/**========================================================*/
void DatagramSocketImpl::bind(int port){
	//?Create UDP Socket
	create();

	//named socket
	SOCKADDR_IN serverAddress;
	std::memset(&serverAddress,0,sizeof(SOCKADDR_IN));
	serverAddress.sin_family	=	AF_INET;
	serverAddress.sin_port=	htons((u_short)port);
	serverAddress.sin_addr.S_un.S_addr	=	htonl(INADDR_ANY);

	if(::bind(mSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR){
		close();
		throw SocketException("Bind failture");
	}
}
/**========================================================*/
/**
 *	@brief	送信
 *	@param[in]	バッファ
 *	@param[in]	サイズ
 *	@param[in]	アドレス
 *	@return	送信データサイズ
 */
/**========================================================*/
int DatagramSocketImpl::send(const void* buffer,int size,const InetSocketAddress& addr){
	create();

	//?sending address setting
	SOCKADDR_IN sendAddress;
	std::memset(&sendAddress,0,sizeof(sendAddress));
	sendAddress.sin_family = AF_INET;
	sendAddress.sin_port = htons((u_short)addr.getPort());
	sendAddress.sin_addr.S_un.S_addr = addr.getInetAddress().getAddress();

	//?+Send Data
	int result = ::sendto(
		mSocket,
		(const char*)buffer,
		size,
		0,
		(LPSOCKADDR)&sendAddress,
		sizeof(sendAddress)
		);
	//! Check result
	if( result != size)
		throw SocketException("Sending ERROR...");

	return result;
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
int DatagramSocketImpl::receive(void* buffer,int size,InetSocketAddress& addr){
	create();

	SOCKADDR_IN fromAddress;
	int fromSize = sizeof(fromAddress);
	int result = ::recvfrom(mSocket,
		(char*)buffer,size,
		0,
		(SOCKADDR*)&fromAddress,
		&fromSize
		);

	//! checkResult
	if(result == SOCKET_ERROR)
		throw SocketException("Receive Error");

	//Set toSend Address
	addr = InetSocketAddress(fromAddress.sin_addr.S_un.S_addr,::ntohs(fromAddress.sin_port));

	//recv size
	return result;

}

/**===End Of File==========================================*/