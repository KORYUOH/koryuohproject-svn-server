/**===File Commentary=======================================*/
/**
 *	@file	ServerSocket.cpp
 *
 *	@brief	�T�[�o�[�\�P�b�g�N���X
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
 *	@brief	�R���X�g���N�^
 */
/**========================================================*/
ServerSocket::ServerSocket():mImpl(new SocketImpl){
}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�|�[�g�ԍ�
 *	@param[in]	�o�b�N���O
*/
/**========================================================*/
ServerSocket::ServerSocket(int port,int backlog):mImpl(new SocketImpl){
	bind(port,backlog);
}
/**========================================================*/
/**
 *	@brief	�f�X�g���N�^
 */
/**========================================================*/
ServerSocket::~ServerSocket(){
}
/**========================================================*/
/**
 *	@brief	�ڑ��ҋ@�\�P�b�g�����
 *	@return	�\�P�b�g
 */
/**========================================================*/
std::unique_ptr<Socket> ServerSocket::accept(){
	return std::unique_ptr<Socket>(new Socket( mImpl->accept() ) );
}
/**========================================================*/
/**
 *	@brief	�o�C���h����
 *	@param[in]	�|�[�g�ԍ�
 *	@param[in]	�o�b�N���O
 */
/**========================================================*/
void ServerSocket::bind(int port,int backLog){
	mImpl->bind(port);
	mImpl->listen(backLog);
}
/**========================================================*/
/**
 *	@brief	�\�P�b�g��
 */
/**========================================================*/
void ServerSocket::close(){
	if(mImpl->isConnect() == true)
		mImpl->close();
}
/**========================================================*/
/**
 *	@brief	�A�h���X�擾
 */
/**========================================================*/
InetAddress ServerSocket::getAddress()const{
	return mImpl->getLocalInetSocketAddress().getInetAddress().getAddress();
}
/**========================================================*/
/**
 *	@brief	�|�[�g�擾
 */
/**========================================================*/
int ServerSocket::getPort()const{
	return mImpl->getLocalInetSocketAddress().getPort();
}



/**===End Of File==========================================*/