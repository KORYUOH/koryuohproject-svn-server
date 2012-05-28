/**===File Commentary=======================================*/
/**
 *	@file	SocketImpl.h
 *
 *	@brief	�\�P�b�g�����N���X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/08
 */
/**===Include Guard========================================*/
#ifndef	_SOCKETIMPL_H_
#define	_SOCKETIMPL_H_
/**===File Include=========================================*/
#include	<WinSock2.h>
#include	<Network/InetSocketAddress/InetSocketAddress.h>
/**===Class Definition=====================================*/
class SocketImpl{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 */
	SocketImpl();
	/**
	 *	@brief	�f�X�g���N�^
	 */
	~SocketImpl();
	/**
	 *	@brief	�\�P�b�g�̐ڑ�
	 *	@param[in]	�\�P�b�g�A�h���X
	 */
	void connect(const InetSocketAddress& address);
	/**
	 *	@brief	�\�P�b�g�̕�
	 */
	void close();
	/**
	 *	@brief	�f�[�^���M
	 *	@param[in]	�f�[�^�o�b�t�@
	 *	@param[in]	�o�b�t�@�T�C�Y
	 *	@return	���
	 */
	int send(const void* buffer ,int size);
	/**
	 *	@brief	�f�[�^��M
	 *	@param[in]	�f�[�^�o�b�t�@
	 *	@param[in]	�f�[�^�T�C�Y
	 *	@return	���
	 */
	int receive(void * buffer ,int size);
	/**
	 *	@brief	�ڑ��̎󂯓���
	 *	@return	���g
	 */
	SocketImpl* accept();
	/**
	 *	@brief	�|�[�g�Ƀ\�P�b�g��ڑ�
	 *	@param[in]	�|�[�g�ԍ�
	 */
	void bind (int port);
	/**
	 *	@brief	�\�P�b�g��listen��Ԃ�
	 *	@param[in]	�o�b�N���O
	 */
	void listen(int backlog = 0);
	/**
	 *	@brief	�\�P�b�g���V���b�g�_�E������
	 *	@param[in]	�ǂꂭ�炢
	 */
	void shutdown(int how);
	/**
	 *	@brief	�ڑ���̃\�P�b�g�A�h���X���擾
	 *	@return	�\�P�b�g�A�h���X
	 */
	InetSocketAddress getInetSocketAddress()const;
	/**
	 *	@brief	���[�J���̃\�P�b�g�A�h���X���擾
	 *	@return	�\�P�b�g�A�h���X
	 */
	InetSocketAddress getLocalInetSocketAddress()const;
	/**
	 *	@brief	�ڑ������m�F
	 *	@return	�ڑ����Ȃ�true
	 */
	bool isConnect() const;
private:
	/**
	 *	@brief	�R�s�[�̋֎~
	 */
	SocketImpl(const SocketImpl& other);
	SocketImpl& operator = (const SocketImpl& other);
public:
	/**	��M���V���b�g�_�E�� */
	const static int SHUTDOWN_RECEIVE;
	/**	���M���V���b�g�_�E�� */
	const static int SHUTDOWN_SEND;
	/**	����M���V���b�g�_�E�� */
	const static int SHUTDOWN_BOTH;
private:
	/**	�\�P�b�g�n���h��*/
	SOCKET	mSocket;
	/**	�\�P�b�g�A�h���X */
	InetSocketAddress	mSocketAddress;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/