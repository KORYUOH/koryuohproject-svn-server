/**===File Commentary=======================================*/
/**
 *	@file	SocketImpl.cpp
 *
 *	@brief	ソケット実装
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/08
 */
/**===File Include=========================================*/
#include	<Network/SocketImpl/SocketImpl.h>
#include	<Network/SocketException/SocketException.h>
#include	<memory>
/**===Class Implementation=================================*/
/**	受信をシャットダウン */
const int SocketImpl::SHUTDOWN_RECEIVE	=	SD_RECEIVE;
/**	送信をシャットダウン */
const int SocketImpl::SHUTDOWN_SEND	=	SD_SEND;
/**	送受信をシャットダウン */
const int SocketImpl::SHUTDOWN_BOTH	=	SD_BOTH;
/**========================================================*/
/**
 *	@brief	コンストラクタ
 */
/**========================================================*/
SocketImpl::SocketImpl()
	:mSocket(INVALID_SOCKET)
{}
/**========================================================*/
/**
 *	@brief	デストラクタ
 */
/**========================================================*/
SocketImpl::~SocketImpl(){
	close();
}
/**========================================================*/
/**
 *	@brief	サーバーと接続
 *	@param[in]	ソケットアドレス
 */
/**========================================================*/
void SocketImpl::connect(const InetSocketAddress& address){
	
	//create new socket
	SOCKET sock = ::socket(AF_INET,SOCK_STREAM,0);

	//socket is create?
	if( sock == INVALID_SOCKET)
		throw SocketException("not create socket error");

	//create to server address
	SOCKADDR_IN serverAddress;
	std::memset(&serverAddress,0,sizeof(SOCKADDR_IN));
	serverAddress.sin_family		= AF_INET;
	serverAddress.sin_port		= htons(address.getPort());
	serverAddress.sin_addr.S_un.S_addr	= address.getInetAddress().getAddress();

	//conecting server
	if( ::connect(sock,(SOCKADDR*)&serverAddress,sizeof(serverAddress)) == SOCKET_ERROR){
		::closesocket(sock);
		throw SocketException("Can't Conecting to Server");
	}

	close();
	mSocketAddress	= address;
	mSocket	= sock;
}
/**========================================================*/
/**
 *	@brief	ソケット閉鎖
 */
/**========================================================*/
void SocketImpl::close(){
	// is conecting?
	if( isConnect() == false)
		return;

	shutdown( SHUTDOWN_BOTH );
	//	socket close
	::closesocket(mSocket);

	// socket address initialize;
	mSocketAddress = InetSocketAddress();

	// socket handler initialize
	mSocket = INVALID_SOCKET;
}
/**========================================================*/
/**
 *	@brief	データ送信
 *	@param[in]	データバッファ
 *	@param[in]	サイズ
 *	@return	結果
 */
/**========================================================*/
int SocketImpl::send(const void* buffer, int size){
	
	int result = ::send(mSocket,(const char*)buffer , size , 0 );

	if( result == SOCKET_ERROR || result == 0)
		throw SocketException("Send Error");

	return result;

}
/**========================================================*/
/**
 *	@brief	接続先からデータ受信
 *	@param[in]	データバッファ
 *	@param[in]	サイズ
 *	@return	リザルト
 */
/**========================================================*/
int SocketImpl::receive(void *buffer,int size){
	int result	= ::recv(mSocket,(char*)buffer,size,0);

	if(result == SOCKET_ERROR|| result == 0)
		throw SocketException("Can't Receiveing...");

	return result;
}
/**========================================================*/
/**
 *	@brief	接続受け入れ
 *	@return	クライアント
 */
/**========================================================*/
SocketImpl*	SocketImpl::accept(){
	std::auto_ptr<SocketImpl> cliant(new SocketImpl());

	// conect accept
	SOCKADDR_IN saddr;
	int len = (int)sizeof(saddr);
	SOCKET sock = ::accept(mSocket, (SOCKADDR*)&saddr, &len);
	if(sock == INVALID_SOCKET)
		throw SocketException("Accept Error");

	//set accept socket address
	cliant->mSocketAddress = InetSocketAddress(InetAddress(::inet_ntoa(saddr.sin_addr)),saddr.sin_port);
	//set accept socket handler
	cliant->mSocket = sock;
	return cliant.release();
}
/**========================================================*/
/**
 *	@brief	ポートにソケットをバインド
 *	@param[in]	ポート番号
 */
/**========================================================*/
void SocketImpl::bind(int port){
	//create new socket
	SOCKET sock = ::socket(AF_INET,SOCK_STREAM,0);

	//creatable socket?
	if(sock == INVALID_SOCKET)
		throw SocketException("Can't Create Socket Error");

	//god father socket
	SOCKADDR_IN serverAddress;
	std::memset(&serverAddress, 0 ,sizeof(SOCKADDR_IN));
	serverAddress.sin_family	=AF_INET ;
	serverAddress.sin_port	= htons(port);
	serverAddress.sin_addr.S_un.S_addr	= htonl(INADDR_ANY);

	//binding
	if(::bind(sock,(struct sockaddr*)&serverAddress,sizeof(serverAddress)) == SOCKET_ERROR){
		::closesocket(sock);
		throw SocketException("Binding Error");
	}

	//set Socket addess
	mSocketAddress = InetSocketAddress(InetAddress(INADDR_ANY),port);

	//set Socket Handle
	mSocket = sock;
}
/**========================================================*/
/**
 *	@brief	ソケットをlisten状態に
 *	@param[in]	バックログ
 */
/**========================================================*/
void SocketImpl::listen(int backlog){
	//wait to Conect at Cliant
	if(::listen(mSocket,backlog) == SOCKET_ERROR)
		throw SocketException("Conecting wait Error");
}
/**========================================================*/
/**
 *	@brief	ソケットのシャットダウンを行う
 */
/**========================================================*/
void SocketImpl::shutdown(int how){
	::shutdown(mSocket,how);
}
/**========================================================*/
/**
 *	@brief	接続先のソケットアドレス取得	
 *	@return	ソケットアドレス
 */
/**========================================================*/
InetSocketAddress SocketImpl::getInetSocketAddress()const{
	return mSocketAddress;
}
/**========================================================*/
/**
 *	@brief	ソケットのローカルソケットアドレスの取得
 *	@return	ローカルソケットアドレス
 */
/**========================================================*/
InetSocketAddress SocketImpl::getLocalInetSocketAddress()const{
	SOCKADDR_IN saddr;
	int len = (int)sizeof(saddr);
	if(::getsockname(mSocket,(struct sockaddr*)&saddr,&len) == SOCKET_ERROR)
		return InetSocketAddress(InetAddress());

	return InetSocketAddress(saddr.sin_addr.S_un.S_addr,saddr.sin_port);
}
/**========================================================*/
/**
 *	@brief	接続中か調べる
 *	@return	接続していればtrue
 */
/**========================================================*/
bool SocketImpl::isConnect()const{
	return mSocket != INVALID_SOCKET;
}











/**===End Of File==========================================*/