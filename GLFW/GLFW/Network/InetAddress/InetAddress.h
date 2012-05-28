/**===File Commentary=======================================*/
/**
 *	@file	InetAddress.h
 *
 *	@brief	インターネットアドレスクラス
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
	 *	@brief	コンストラクタ
	 *	@param[in]	IPｱﾄﾞﾚｽ
	 *	@author	KORYUOH
	 */
	InetAddress(unsigned int address = InetAddress::NONE);
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	アドレス
	 *	@author	KORYUOH
	 */
	InetAddress(const std::string& address);
	/**
	 *	@brief	ホストアドレスの取得
	 *	@author	KORYUOH
	 *	@return	ホストアドレス
	 */
	std::string getHostAddress()const;
	/**
	 *	@brief	代入演算子オーバーロード
	 *	@param[in]	他
	 *	@author	KORYUOH
	 *	@return	InetAddress
	 */
	InetAddress& operator = (const InetAddress& other);
	/**
	 *	@brief	代入演算子オーバーロード
	 *	@param[in]	ホスト名
	 *	@author	KORYUOH
	 *	@return	InetAddress
	 */
	InetAddress& operator = (const std::string& host);
	/**
	 *	@brief	IPアドレスの取得
	 *	@author	KORYUOH
	 *	@return	IPアドレス
	 */
	unsigned long getAddress()const;
public:
	/** 無効なIPアドレス */
	const static unsigned long NONE;

private:
	/**	IPアドレス */
	unsigned long mIPAddress;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/