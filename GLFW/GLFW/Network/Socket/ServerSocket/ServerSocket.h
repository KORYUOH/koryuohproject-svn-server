/**===File Commentary=======================================*/
/**
 *	@file	ServerSocket.h
 *
 *	@brief	�T�[�o�[�\�P�b�g�N���X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/15
 */
/**===Include Guard========================================*/
#ifndef	_SERVERSOCKET_H_
#define	_SERVERSOCKET_H_
/**===File Include=========================================*/
#include	<Network/Socket/Socket/Socket.h>
#include	<memory>
class SocketImpl;
/**===Class Definition=====================================*/
class ServerSocket{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 */
	ServerSocket();
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�|�[�g
	 *	@param[in]	�o�b�N���O
	 */
	ServerSocket(int port,int backLog=0);
	/**
	 *	@brief	�f�X�g���N�^
	 */
	virtual ~ServerSocket();
	/**
	 *	@brief	�\�P�b�g�����
	 *	@return	�\�P�b�g�|�C���^
	 */
	std::unique_ptr<Socket> accept();
	/**
	 *	@brief	�o�C���h
	 *	@param[in]	�|�[�g�ԍ�
	 *	@param[in]	�o�b�N���O
	 */
	void bind(int port, int backLog =0);
	/**
	 *	@brief	�\�P�b�g�����
	 */
	void close();
	/**
	 *	@brief	�A�h���X���擾
	 *	@return	�A�h���X
	 */
	InetAddress getAddress()const;
	/**
	 *	@brief	�|�[�g�ԍ��擾
	 *	@return	�|�[�g�ԍ�
	 */
	int getPort()const;
private:
	/**
	 *	@brief	�R�s�[�֎~
	 */
	ServerSocket(const ServerSocket& other);
	ServerSocket& operator = (const ServerSocket& other);
private:
	/**	�\�P�b�g�����N���X*/
	std::unique_ptr<SocketImpl> mImpl;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/