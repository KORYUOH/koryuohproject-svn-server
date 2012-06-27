/**===File Commentary=======================================*/
/**
 *	@file	DatagramSocket.h
 *
 *	@brief	UDPソケットクラス
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
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	KORYUOH
	 *	@return	<戻り値>
	 */
	DatagramSocket();

	DatagramSocket(int port);
		/**
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	KORYUOH
	 *	@return	<戻り値>
	 */
	virtual ~DatagramSocket();
		/**
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	KORYUOH
	 *	@return	<戻り値>
	 */
	void bind (int port);
		/**
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	KORYUOH
	 *	@return	<戻り値>
	 */
	int send(const void*buffer,int size,const InetSocketAddress& addr);
		/**
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	KORYUOH
	 *	@return	<戻り値>
	 */
	int receive(void* buffer,int size,InetSocketAddress& addr);
		/**
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	KORYUOH
	 *	@return	<戻り値>
	 */
	void close();
private:
	DatagramSocket(const DatagramSocket& other);
	DatagramSocket& operator = (const DatagramSocket& other);

private:
	/**	メンバー変数*/
	std::unique_ptr<DatagramSocketImpl> mImpl;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/