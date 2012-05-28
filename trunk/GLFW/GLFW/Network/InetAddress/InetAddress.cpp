/**===File Commentary=======================================*/
/**
 *	@file	InetAddress.cpp
 *
 *	@brief	インターネットアドレスクラス
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
 *	@brief	無効なIPアドレス
 *	@author	KORYUOH
 */
/**========================================================*/
const unsigned long InetAddress::NONE = INADDR_NONE;

/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	IPアドレス
 *	@author	KORYUOH
 */
/**========================================================*/
InetAddress::InetAddress(unsigned int address):mIPAddress(address)
{
}
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	ホスト名
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
 *	@brief	ホスト名の取得
 *	@author	KORYUOH
 *	@return	ホスト名
 */
/**========================================================*/
std::string InetAddress::getHostAddress()const{
	in_addr addr;
	addr.S_un.S_addr = mIPAddress;
	return std::string(inet_ntoa(addr));
}
/**========================================================*/
/**
 *	@brief	代入演算子オーバーロード
 *	@param[in]	他のInetAddressクラス
 *	@author	KORYUOH
 *	@return	自身
 */
/**========================================================*/
InetAddress& InetAddress::operator=(const InetAddress& other){
	mIPAddress = other.mIPAddress;
	return *this;
}
/**========================================================*/
/**
 *	@brief	代入演算子オーバーロード
 *	@param[in]	ホスト名
 *	@author	KORYUOH
 *	@return	自身
 */
/**========================================================*/
InetAddress& InetAddress::operator= ( const std::string& host){
	*this = InetAddress(host);
	return *this;
}
/**========================================================*/
/**
 *	@brief	IPアドレスの取得
 *	@author	KORYUOH
 *	@return	IPアドレス
 */
/**========================================================*/
unsigned long InetAddress::getAddress()const{
	return  mIPAddress;
}




/**===End Of File==========================================*/