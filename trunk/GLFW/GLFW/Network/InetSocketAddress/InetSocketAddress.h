/**===File Commentary=======================================*/
/**
 *	@file	InetSocketAddress.h
 *
 *	@brief	�C���^�[�l�b�g�\�P�b�g�A�h���X�N���X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/08
 */
/**===Include Guard========================================*/
#ifndef	_INETSOCKETADDRESS_H_
#define	_INETSOCKETADDRESS_H_
/**===File Include=========================================*/
#include	<Network/InetAddress/InetAddress.h>
/**===Class Definition=====================================*/
class InetSocketAddress{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	InetAddress
	 *	@param[in]	�|�[�g�ԍ�
	 *	@author	KORYUOH
	 */
	InetSocketAddress( const InetAddress& address=InetAddress(), int port =0);
	/**
	 *	@brief	�C���^�[�l�b�g�A�h���X�擾
	 *	@return	�C���^�[�l�b�g�A�h���X
	 */
	const InetAddress& getInetAddress()const;
	/**
	 *	@brief	�|�[�g�ԍ��̎擾
	 *	@return	�|�[�g�ԍ�
	 */
	int getPort() const;
private:
	/**	�C���^�[�l�b�g�A�h���X */
	InetAddress mAddress;
	/**	�|�[�g�ԍ� */
	int mPort;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/