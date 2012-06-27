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
 *	@brief	�R���X�g���N�^
 */
/**========================================================*/
DatagramSocket::DatagramSocket()
	:mImpl(new DatagramSocketImpl()){
}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�|�[�g
 */
/**========================================================*/
DatagramSocket::DatagramSocket(int port)
	:mImpl(new DatagramSocketImpl()){
		bind(port);
}
/**========================================================*/
/**
 *	@brief	�f�X�g���N�^
 */
/**========================================================*/
DatagramSocket::~DatagramSocket(){
}
/**========================================================*/
/**
 *	@brief	�o�C���h
 *	@param[in]	�|�[�g
 */
/**========================================================*/
void DatagramSocket::bind(int port){
	mImpl->bind(port);
}
/**========================================================*/
/**
 *	@brief	���M
 *	@param[in]	�o�b�t�@
 *	@param[in]	�T�C�Y
 *	@param[in]	�A�h���X
 *	@return	���M�T�C�Y
 */
/**========================================================*/
int DatagramSocket::send(const void* buffer,int size,const InetSocketAddress& addr){
	return mImpl->send(buffer,size,addr);
}
/**========================================================*/
/**
 *	@brief	��M
 *	@param[in]	�o�b�t�@
 *	@param[in]	�T�C�Y
 *	@param[in]	�A�h���X
 *	@return	��M�T�C�Y
 */
/**========================================================*/
int DatagramSocket::receive(void* buffer,int size,InetSocketAddress& addr){
	return mImpl->receive(buffer,size,addr);
}
/**========================================================*/
/**
 *	@brief	��
 */
/**========================================================*/
void DatagramSocket::close(){
	mImpl->close();
}



/**===End Of File==========================================*/