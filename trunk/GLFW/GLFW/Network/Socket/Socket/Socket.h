/**===File Commentary=======================================*/
/**
 *	@file	Socket.h
 *
 *	@brief	�\�P�b�g�N���X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/15
 */
/**===Include Guard========================================*/
#ifndef	_SOCKET_H_
#define	_SOCKET_H_
/**===File Include=========================================*/
#include	<Network/InetSocketAddress/InetSocketAddress.h>
#include	<Network/SocketException/SocketException.h>
#include	<string>
#include	<memory>
class SocketImpl;
/**===Class Definition=====================================*/
class Socket{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 */
	Socket();
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�\�P�b�g�A�h���X
	 */
	Socket(const InetSocketAddress& adress);
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�l�b�g�A�h���X
	 *	@param[in]	�|�[�g�ԍ�
	 */
	Socket(const InetAddress& adress,int port);
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�z�X�g��
	 *	@param[in]	�|�[�g�ԍ�	
	 */
	Socket(const std::string& host,int port);
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�\�P�b�g�����N���X
	 */
	Socket(SocketImpl* impl);
	/**
	 *	@brief	�f�X�g���N�^
	 */
	virtual ~Socket();
	/**
	 *	@brief	�\�P�b�g�ڑ�
	 *	@param[in]	�\�P�b�g�A�h���X
	 */
	void connect(const InetSocketAddress& adress);
	/**
	 *	@brief	�\�P�b�g�ڑ�
	 *	@param[in]	�l�b�g�A�h���X
	 *	@param[in]	�|�[�g�ԍ�
	 */
	void connect(const InetAddress& adress,int port);
	/**
	 *	@brief	�\�P�b�g�ڑ�
	 *	@param[in]	�z�X�g��	
	 *	@param[in]	�|�[�g�ԍ�
	 */
	void connect(const std::string& host,int port);
	/**
	 *	@brief	�\�P�b�g��
	 */
	void close();
	/**
	 *	@brief	�f�[�^���M
	 *	@param[in]	�o�b�t�@
	 *	@param[in]	�T�C�Y
	 *	@return	�t���O
	 */
	int send(const void*baffer,int size);
	/**
	 *	@brief	�����񑗐M
	 *	@param[in]	������
	 *	@return	�t���O
	 */
	int send(const std::string& msg);
	/**
	 *	@brief	�f�[�^��M
	 *	@param[in]	�f�[�^
	 *	@param[in]	�T�C�Y
	 */
	int receive(void* baffer,int size);
	/**
	 *	@brief	���b�Z�[�W��M
	 *	@return	���b�Z�[�W
	 */
	std::string receive();
	/**
	 *	@brief	�A�h���X�擾
	 *	@return	�\�P�b�g�A�h���X
	 */
	InetAddress getAddress()const;
	/**
	 *	@brief	�|�[�g�ԍ��擾
	 *	@return	�|�[�g�ԍ�
	 */
	int getport()const;
	/**
	 *	@brief	���[�J���A�h���X�擾
	 *	@return	���[�J���A�h���X
	 */
	InetAddress getLocalAddress()const;
	/**
	 *	@brief	���[�J���|�[�g�擾
	 *	@return	�|�[�g
	 */
	int getLocalPort()const;
	/**
	 *	@brief	�ڑ��������ׂ�
	 *	@return	�ڑ����Ȃ�^
	 */
	bool isConnected()const;
	/**
	 *	@brief	�I������
	 */
	void shutdown(int how=Socket::SHUTDOWN_BOTH);
public:
	/** ��M���V���b�g�_�E�� */
	const static int SHUTDOWN_SEND;
	/** ���M���V���b�g�_�E�� */
	const static int SHUTDOWN_RECIEVE;
	/** �����V���b�g�_�E�� */
	const static int SHUTDOWN_BOTH;

private:
	/**
	 *	@brief	�R�s�[�֎~
	 */
	Socket(const Socket& other);
	Socket& operator = (const Socket& other);


private:
	/**	�\�P�b�g�����N���X�@*/
	std::unique_ptr<SocketImpl> mImpl;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/