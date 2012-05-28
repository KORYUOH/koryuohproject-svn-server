/**===File Commentary=======================================*/
/**
 *	@file	InetSocketAddress.cpp
 *
 *	@brief	�C���^�[�l�b�g�\�P�b�g�A�h���X�N���X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/08
 */
/**===File Include=========================================*/
#include	<Network/InetSocketAddress/InetSocketAddress.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�C���^�[�l�b�g�A�h���X
 *	@param[in]	�|�[�g�ԍ�
 */
/**========================================================*/
InetSocketAddress::InetSocketAddress(const InetAddress& address,int port)
	:mAddress(address)
	,mPort(port)
{	
}
/**========================================================*/
/**
 *	@brief	�C���^�[�l�b�g�A�h���X�̎擾
 *	@return	�C���^�[�l�b�g�A�h���X
 */
/**========================================================*/
const InetAddress& InetSocketAddress::getInetAddress()const{
	return mAddress;
}
/**========================================================*/
/**
 *	@brief	�|�[�g�ԍ��̎擾
 *	@return	�|�[�g�ԍ�
 */
/**========================================================*/
int InetSocketAddress::getPort()const{
	return mPort;
}
/**===End Of File==========================================*/