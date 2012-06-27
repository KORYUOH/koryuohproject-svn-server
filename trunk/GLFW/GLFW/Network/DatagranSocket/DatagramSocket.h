/**===File Commentary=======================================*/
/**
 *	@file	DatagramSocket.h
 *
 *	@brief	UDP�\�P�b�g�N���X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/05
 */
/**===Include Guard========================================*/
#ifndef	_DATAGRAMSOCKET_H_
#define	_DATAGRAMSOCKET_H_
/**===File Include=========================================*/
#include	<Network/InetSocketAddress/InetSocketAddress.h>
#include	<memory>
class DatagramSocketImpl;
/**===Class Definition=====================================*/
class DatagramSocket{
public:
	/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	KORYUOH
	 *	@return	<�߂�l>
	 */
	DatagramSocket();

	DatagramSocket(int port);
		/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	KORYUOH
	 *	@return	<�߂�l>
	 */
	virtual ~DatagramSocket();
		/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	KORYUOH
	 *	@return	<�߂�l>
	 */
	void bind (int port);
		/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	KORYUOH
	 *	@return	<�߂�l>
	 */
	int send(const void*buffer,int size,const InetSocketAddress& addr);
		/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	KORYUOH
	 *	@return	<�߂�l>
	 */
	int receive(void* buffer,int size,InetSocketAddress& addr);
		/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	KORYUOH
	 *	@return	<�߂�l>
	 */
	void close();
private:
	DatagramSocket(const DatagramSocket& other);
	DatagramSocket& operator = (const DatagramSocket& other);

private:
	/**	�����o�[�ϐ�*/
	std::unique_ptr<DatagramSocketImpl> mImpl;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/