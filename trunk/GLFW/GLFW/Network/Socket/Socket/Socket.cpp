/**===File Commentary=======================================*/
/**
 *	@file	Socket.cpp
 *
 *	@brief	�\�P�b�g�N���X
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
/** �����V���b�g�_�E�� */
const int Socket::SHUTDOWN_BOTH = SocketImpl::SHUTDOWN_BOTH;
/** ��M���V���b�g�_�E�� */
const int Socket::SHUTDOWN_RECIEVE = SocketImpl::SHUTDOWN_RECEIVE;
/** ���M���V���b�g�_�E�� */
const int Socket::SHUTDOWN_SEND = SocketImpl::SHUTDOWN_SEND;

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 */
/**========================================================*/
Socket::Socket():
mImpl(new SocketImpl()){
}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�\�P�b�g�A�h���X
 */
/**========================================================*/
Socket::Socket(const InetSocketAddress& address):
mImpl(new SocketImpl()){
	connect(address);
}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�l�b�g�A�h���X	
 *	@param[in]	�|�[�g
 */
/**========================================================*/
Socket::Socket(const InetAddress& address,int port):
mImpl(new SocketImpl()){
	connect(address,port);
}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�z�X�g��
 *	@param[in]	�|�[�g�ԍ�
 */
/**========================================================*/
Socket::Socket(const std::string& host,int port):
mImpl(new SocketImpl()){
	connect(host,port);
}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�\�P�b�g�����N���X
 */
/**========================================================*/
Socket::Socket(SocketImpl* impl ):
mImpl(impl){
}
/**========================================================*/
/**
 *	@brief	�f�X�g���N�^
 */
/**========================================================*/
Socket::~Socket(){
}
/**========================================================*/
/**
 *	@brief	�ڑ�
 *	@param[in]	�\�P�b�g�A�h���X
 */
/**========================================================*/
void Socket::connect(const InetSocketAddress& address){
	mImpl->connect(address);
}
/**========================================================*/
/**
 *	@brief	�ڑ�
 *	@param[in]	�l�b�g�A�h���X
 *	@param[in]	�|�[�g�ԍ�
 */
/**========================================================*/
void Socket::connect(const InetAddress& address,int port){
	connect(InetSocketAddress(address,port));
}
/**========================================================*/
/**
 *	@brief	�ڑ�
 *	@param[in]	�z�X�g��
 *	@param[in]	�|�[�g�ԍ�
 */
/**========================================================*/
void Socket::connect(const std::string& host,int port){
	connect(InetSocketAddress( InetAddress(host) , port) );
}
/**========================================================*/
/**
 *	@brief	�\�P�b�g��
 */
/**========================================================*/
void Socket::close(){
	if(mImpl->isConnect() == true)
		mImpl->close();

}
/**========================================================*/
/**
 *	@brief	�f�[�^���M
 *	@param[in]	�o�b�t�@
 *	@param[in]	�T�C�Y
 *	@return	���M�T�C�Y
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
 *	@brief	�����񑗐M
 *	@param[in]	������
 *	@return	���M�T�C�Y
 */
/**========================================================*/
int Socket::send(const std::string& msg){
	return send(msg.c_str(),(int)msg.size()+1);
}
/**========================================================*/
/**
 *	@brief	�f�[�^��M
 *	@param[in]	�o�b�t�@
 *	@param[in]	�T�C�Y
 *	@return	��M�T�C�Y
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
 *	@brief	�������M
 *	@return	������
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
 *	@brief	�A�h���X�擾
 *	@return	�A�h���X
 */
/**========================================================*/
InetAddress Socket::getAddress()const{
	return mImpl->getInetSocketAddress().getInetAddress();
}
/**========================================================*/
/**
 *	@brief	�|�[�g�擾
 *	@return	�|�[�g
 */
/**========================================================*/
int Socket::getport()const{
	return mImpl->getInetSocketAddress().getPort();
}
/**========================================================*/
/**
 *	@brief	���[�J���A�h���X�擾
 *	@return	���[�J���A�h���X
 */
/**========================================================*/
InetAddress Socket::getLocalAddress()const{
	return mImpl->getLocalInetSocketAddress().getInetAddress();
}
/**========================================================*/
/**
 *	@brief	���[�J���|�[�g�擾
 *	@return	���[�J���|�[�g
 */
/**========================================================*/
int Socket::getLocalPort()const{
	return mImpl->getLocalInetSocketAddress().getPort();
}
/**========================================================*/
/**
 *	@brief	�ڑ��m�F
 *	@return	�ڑ����Ȃ�ΐ^
 */
/**========================================================*/
bool Socket::isConnected()const{
	return mImpl->isConnect();
}
/**========================================================*/
/**
 *	@brief	�V���b�g�_�E�����s��
 *	@param[in]	�I���菇
 */
/**========================================================*/
void Socket::shutdown(int how){
	mImpl->shutdown(how);
}






/**===End Of File==========================================*/