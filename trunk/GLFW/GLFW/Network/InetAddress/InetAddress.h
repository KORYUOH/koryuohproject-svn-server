/**===File Commentary=======================================*/
/**
 *	@file	InetAddress.h
 *
 *	@brief	�C���^�[�l�b�g�A�h���X�N���X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/08
 */
/**===Include Guard========================================*/
#ifndef	_INETADDRESS_H_
#define	_INETADDRESS_H_
/**===File Include=========================================*/
#include	<string>
/**===Class Definition=====================================*/
class InetAddress{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	IP���ڽ
	 *	@author	KORYUOH
	 */
	InetAddress(unsigned int address = InetAddress::NONE);
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�A�h���X
	 *	@author	KORYUOH
	 */
	InetAddress(const std::string& address);
	/**
	 *	@brief	�z�X�g�A�h���X�̎擾
	 *	@author	KORYUOH
	 *	@return	�z�X�g�A�h���X
	 */
	std::string getHostAddress()const;
	/**
	 *	@brief	������Z�q�I�[�o�[���[�h
	 *	@param[in]	��
	 *	@author	KORYUOH
	 *	@return	InetAddress
	 */
	InetAddress& operator = (const InetAddress& other);
	/**
	 *	@brief	������Z�q�I�[�o�[���[�h
	 *	@param[in]	�z�X�g��
	 *	@author	KORYUOH
	 *	@return	InetAddress
	 */
	InetAddress& operator = (const std::string& host);
	/**
	 *	@brief	IP�A�h���X�̎擾
	 *	@author	KORYUOH
	 *	@return	IP�A�h���X
	 */
	unsigned long getAddress()const;
public:
	/** ������IP�A�h���X */
	const static unsigned long NONE;

private:
	/**	IP�A�h���X */
	unsigned long mIPAddress;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/