/**===File Commentary=======================================*/
/**
 *	@file	Socket.cpp
 *
 *	@brief	ソケットクラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/15
 */
/**===File Include=========================================*/
#include	<Network/Socket/Socket/Socket.h>
#include	<Network/SocketImpl/SocketImpl.h>
#include	<vector>
/**===Class Implementation=================================*/
/** 両方シャットダウン */
const int Socket::SHUTDOWN_BOTH = SocketImpl::SHUTDOWN_BOTH;
/** 受信をシャットダウン */
const int Socket::SHUTDOWN_RECIEVE = SocketImpl::SHUTDOWN_RECEIVE;
/** 送信をシャットダウン */
const int Socket::SHUTDOWN_SEND = SocketImpl::SHUTDOWN_SEND;

/**========================================================*/
/**
 *	@brief	コンストラクタ
 */
/**========================================================*/
Socket::Socket():
mImpl(new SocketImpl()){
}
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	ソケットアドレス
 */
/**========================================================*/
Socket::Socket(const InetSocketAddress& address):
mImpl(new SocketImpl()){
	connect(address);
}
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	ネットアドレス	
 *	@param[in]	ポート
 */
/**========================================================*/
Socket::Socket(const InetAddress& address,int port):
mImpl(new SocketImpl()){
	connect(address,port);
}
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	ホスト名
 *	@param[in]	ポート番号
 */
/**========================================================*/
Socket::Socket(const std::string& host,int port):
mImpl(new SocketImpl()){
	connect(host,port);
}
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	ソケット実装クラス
 */
/**========================================================*/
Socket::Socket(SocketImpl* impl ):
mImpl(impl){
}
/**========================================================*/
/**
 *	@brief	デストラクタ
 */
/**========================================================*/
Socket::~Socket(){
}
/**========================================================*/
/**
 *	@brief	接続
 *	@param[in]	ソケットアドレス
 */
/**========================================================*/
void Socket::connect(const InetSocketAddress& address){
	mImpl->connect(address);
}
/**========================================================*/
/**
 *	@brief	接続
 *	@param[in]	ネットアドレス
 *	@param[in]	ポート番号
 */
/**========================================================*/
void Socket::connect(const InetAddress& address,int port){
	connect(InetSocketAddress(address,port));
}
/**========================================================*/
/**
 *	@brief	接続
 *	@param[in]	ホスト名
 *	@param[in]	ポート番号
 */
/**========================================================*/
void Socket::connect(const std::string& host,int port){
	connect(InetSocketAddress( InetAddress(host) , port) );
}
/**========================================================*/
/**
 *	@brief	ソケット閉鎖
 */
/**========================================================*/
void Socket::close(){
	if(mImpl->isConnect() == true)
		mImpl->close();

}
/**========================================================*/
/**
 *	@brief	データ送信
 *	@param[in]	バッファ
 *	@param[in]	サイズ
 *	@return	送信サイズ
 */
/**========================================================*/
int Socket::send(const void* buffer,int size){
	int total = 0;
	while(total < size)
		total += mImpl->send(reinterpret_cast<const char*> (buffer)+total,size-total);

	return total;
}
/**========================================================*/
/**
 *	@brief	文字列送信
 *	@param[in]	文字列
 *	@return	送信サイズ
 */
/**========================================================*/
int Socket::send(const std::string& msg){
	return send(msg.c_str(),(int)msg.size()+1);
}
/**========================================================*/
/**
 *	@brief	データ受信
 *	@param[in]	バッファ
 *	@param[in]	サイズ
 *	@return	受信サイズ
 */
/**========================================================*/
int Socket::receive(void* buffer,int size){
	int total = 0;
	while(total<size)
		total += mImpl->receive(reinterpret_cast< char* >(buffer)+total,size-total);
	
	return total;
}
/**========================================================*/
/**
 *	@brief	文字列受信
 *	@return	文字列
 */
/**========================================================*/
std::string Socket::receive(){
	std::vector<char> buffer;

	char revchar;
	do{
		revchar = '\0';
		receive(&revchar,sizeof(revchar));
		buffer.push_back(revchar);
	}while(revchar != '\0');

	return std::string(&buffer[0]);
}
/**========================================================*/
/**
 *	@brief	アドレス取得
 *	@return	アドレス
 */
/**========================================================*/
InetAddress Socket::getAddress()const{
	return mImpl->getInetSocketAddress().getInetAddress();
}
/**========================================================*/
/**
 *	@brief	ポート取得
 *	@return	ポート
 */
/**========================================================*/
int Socket::getport()const{
	return mImpl->getInetSocketAddress().getPort();
}
/**========================================================*/
/**
 *	@brief	ローカルアドレス取得
 *	@return	ローカルアドレス
 */
/**========================================================*/
InetAddress Socket::getLocalAddress()const{
	return mImpl->getLocalInetSocketAddress().getInetAddress();
}
/**========================================================*/
/**
 *	@brief	ローカルポート取得
 *	@return	ローカルポート
 */
/**========================================================*/
int Socket::getLocalPort()const{
	return mImpl->getLocalInetSocketAddress().getPort();
}
/**========================================================*/
/**
 *	@brief	接続確認
 *	@return	接続中ならば真
 */
/**========================================================*/
bool Socket::isConnected()const{
	return mImpl->isConnect();
}
/**========================================================*/
/**
 *	@brief	シャットダウンを行う
 *	@param[in]	終了手順
 */
/**========================================================*/
void Socket::shutdown(int how){
	mImpl->shutdown(how);
}






/**===End Of File==========================================*/