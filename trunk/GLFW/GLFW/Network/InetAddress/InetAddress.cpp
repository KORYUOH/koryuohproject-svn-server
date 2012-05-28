/**===File Commentary=======================================*/
/**
 *	@file	InetAddress.cpp
 *
 *	@brief	�C���^�[�l�b�g�A�h���X�N���X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/08
 */
/**===File Include=========================================*/
#include	<Network/InetAddress/InetAddress.h>
#include	<WinSock2.h>
/**===Class Implementation=================================*/
/**========================================================*/
/**
 *	@brief	������IP�A�h���X
 *	@author	KORYUOH
 */
/**========================================================*/
const unsigned long InetAddress::NONE = INADDR_NONE;

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	IP�A�h���X
 *	@author	KORYUOH
 */
/**========================================================*/
InetAddress::InetAddress(unsigned int address):mIPAddress(address)
{
}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�z�X�g��
 *	@author	KORYUOH
 */
/**========================================================*/
InetAddress::InetAddress(const std::string& address){
	unsigned long uaddr = ::inet_addr(address.c_str());
	if(uaddr == INADDR_NONE){
		hostent* ent = ::gethostbyname(address.c_str());
		if(ent != 0 && ent->h_addr_list[0] != 0)
			uaddr = * (unsigned long*)ent->h_addr_list[0];
	}
	mIPAddress = uaddr;
}
/**========================================================*/
/**
 *	@brief	�z�X�g���̎擾
 *	@author	KORYUOH
 *	@return	�z�X�g��
 */
/**========================================================*/
std::string InetAddress::getHostAddress()const{
	in_addr addr;
	addr.S_un.S_addr = mIPAddress;
	return std::string(inet_ntoa(addr));
}
/**========================================================*/
/**
 *	@brief	������Z�q�I�[�o�[���[�h
 *	@param[in]	����InetAddress�N���X
 *	@author	KORYUOH
 *	@return	���g
 */
/**========================================================*/
InetAddress& InetAddress::operator=(const InetAddress& other){
	mIPAddress = other.mIPAddress;
	return *this;
}
/**========================================================*/
/**
 *	@brief	������Z�q�I�[�o�[���[�h
 *	@param[in]	�z�X�g��
 *	@author	KORYUOH
 *	@return	���g
 */
/**========================================================*/
InetAddress& InetAddress::operator= ( const std::string& host){
	*this = InetAddress(host);
	return *this;
}
/**========================================================*/
/**
 *	@brief	IP�A�h���X�̎擾
 *	@author	KORYUOH
 *	@return	IP�A�h���X
 */
/**========================================================*/
unsigned long InetAddress::getAddress()const{
	return  mIPAddress;
}




/**===End Of File==========================================*/