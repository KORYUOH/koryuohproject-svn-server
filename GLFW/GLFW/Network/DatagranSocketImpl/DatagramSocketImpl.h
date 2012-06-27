/**===File Commentary=======================================*/
/**
 *	@file	DatagramSocketImpl.h
 *
 *	@brief	UDP�\�P�b�g�����N���X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/05
 */
/**===Include Guard========================================*/
#ifndef	_DATAGRAMSOCKETIMPL_H_
#define	_DATAGRAMSOCKETIMPL_H_
/**===File Include=========================================*/
#include	<WinSock2.h>
class InetSocketAddress;
/**===Class Definition=====================================*/
class DatagramSocketImpl{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 */
	DatagramSocketImpl();
	/**
	 *	@brief	�f�X�g���N�^
	 */
	~DatagramSocketImpl();
	/**
	 *	@brief	UDP�\�P�b�g�쐬
	 */
	void create();
	/**
	 *	@brief	�\�P�b�g��
	 */
	void close();
	/**
	 *	@brief	�o�C���h
	 *	@param[in]	�|�[�g�ԍ�
	 */
	void bind(int port);
	/**
	 *	@brief	���M
	 *	@param[in]	�o�b�t�@
	 *	@param[in]	�T�C�Y
	 *	@param[in]	�\�P�b�g�A�h���X
	 *	@return	�\�P�b�g
	 */
	int send(const void* buffer,int size ,const InetSocketAddress& addr);
	/**
	 *	@brief	��M
	 *	@param[in]	�o�b�t�@
	 *	@param[in]	�T�C�Y
	 *	@param[in]	�A�h���X
	 *	@return	����
	 */
	int receive( void* buffer,int size,InetSocketAddress& addr);

private:
	/**
	 *	@brief	�R�s�[�֎~
	 */
	DatagramSocketImpl(const DatagramSocketImpl& other);
	DatagramSocketImpl& operator=(const DatagramSocketImpl& other);

private:
	/**	�����o�[�ϐ�*/
	SOCKET	mSocket;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/