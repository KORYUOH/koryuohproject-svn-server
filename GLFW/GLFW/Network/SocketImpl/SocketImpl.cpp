/**===File Commentary=======================================*/
/**
 *	@file	SocketImpl.cpp
 *
 *	@brief	�\�P�b�g����
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
/**	��M���V���b�g�_�E�� */
const int SocketImpl::SHUTDOWN_RECEIVE	=	SD_RECEIVE;
/**	���M���V���b�g�_�E�� */
const int SocketImpl::SHUTDOWN_SEND	=	SD_SEND;
/**	����M���V���b�g�_�E�� */
const int SocketImpl::SHUTDOWN_BOTH	=	SD_BOTH;
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 */
/**========================================================*/
SocketImpl::SocketImpl()
	:mSocket(INVALID_SOCKET)
{}
/**========================================================*/
/**
 *	@brief	�f�X�g���N�^
 */
/**========================================================*/
SocketImpl::~SocketImpl(){
	close();
}
/**========================================================*/
/**
 *	@brief	�T�[�o�[�Ɛڑ�
 *	@param[in]	�\�P�b�g�A�h���X
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
 *	@brief	�\�P�b�g��
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
 *	@brief	�f�[�^���M
 *	@param[in]	�f�[�^�o�b�t�@
 *	@param[in]	�T�C�Y
 *	@return	����
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
 *	@brief	�ڑ��悩��f�[�^��M
 *	@param[in]	�f�[�^�o�b�t�@
 *	@param[in]	�T�C�Y
 *	@return	���U���g
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
 *	@brief	�ڑ��󂯓���
 *	@return	�N���C�A���g
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
 *	@brief	�|�[�g�Ƀ\�P�b�g���o�C���h
 *	@param[in]	�|�[�g�ԍ�
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
 *	@brief	�\�P�b�g��listen��Ԃ�
 *	@param[in]	�o�b�N���O
 */
/**========================================================*/
void SocketImpl::listen(int backlog){
	//wait to Conect at Cliant
	if(::listen(mSocket,backlog) == SOCKET_ERROR)
		throw SocketException("Conecting wait Error");
}
/**========================================================*/
/**
 *	@brief	�\�P�b�g�̃V���b�g�_�E�����s��
 */
/**========================================================*/
void SocketImpl::shutdown(int how){
	::shutdown(mSocket,how);
}
/**========================================================*/
/**
 *	@brief	�ڑ���̃\�P�b�g�A�h���X�擾	
 *	@return	�\�P�b�g�A�h���X
 */
/**========================================================*/
InetSocketAddress SocketImpl::getInetSocketAddress()const{
	return mSocketAddress;
}
/**========================================================*/
/**
 *	@brief	�\�P�b�g�̃��[�J���\�P�b�g�A�h���X�̎擾
 *	@return	���[�J���\�P�b�g�A�h���X
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
 *	@brief	�ڑ��������ׂ�
 *	@return	�ڑ����Ă����true
 */
/**========================================================*/
bool SocketImpl::isConnect()const{
	return mSocket != INVALID_SOCKET;
}











/**===End Of File==========================================*/