/**===File Commentary=======================================*/
/**
 *	@file	ServerSocket.cpp
 *
 *	@brief	サーバーソケットクラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/15
 */
/**===File Include=========================================*/
#include	<Network/Socket/ServerSocket/ServerSocket.h>
#include	<Network/SocketImpl/SocketImpl.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	コンストラクタ
 */
/**========================================================*/
ServerSocket::ServerSocket():mImpl(new SocketImpl){
}
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	ポート番号
 *	@param[in]	バックログ
*/
/**========================================================*/
ServerSocket::ServerSocket(int port,int backlog):mImpl(new SocketImpl){
	bind(port,backlog);
}
/**========================================================*/
/**
 *	@brief	デストラクタ
 */
/**========================================================*/
ServerSocket::~ServerSocket(){
}
/**========================================================*/
/**
 *	@brief	接続待機ソケット受入れ
 *	@return	ソケット
 */
/**========================================================*/
std::unique_ptr<Socket> ServerSocket::accept(){
	return std::unique_ptr<Socket>(new Socket( mImpl->accept() ) );
}
/**========================================================*/
/**
 *	@brief	バインドする
 *	@param[in]	ポート番号
 *	@param[in]	バックログ
 */
/**========================================================*/
void ServerSocket::bind(int port,int backLog){
	mImpl->bind(port);
	mImpl->listen(backLog);
}
/**========================================================*/
/**
 *	@brief	ソケット閉鎖
 */
/**========================================================*/
void ServerSocket::close(){
	if(mImpl->isConnect() == true)
		mImpl->close();
}
/**========================================================*/
/**
 *	@brief	アドレス取得
 */
/**========================================================*/
InetAddress ServerSocket::getAddress()const{
	return mImpl->getLocalInetSocketAddress().getInetAddress().getAddress();
}
/**========================================================*/
/**
 *	@brief	ポート取得
 */
/**========================================================*/
int ServerSocket::getPort()const{
	return mImpl->getLocalInetSocketAddress().getPort();
}



/**===End Of File==========================================*/