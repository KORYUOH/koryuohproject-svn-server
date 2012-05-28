/**===File Commentary=======================================*/
/**
 *	@file	SocketException.h
 *
 *	@brief	ソケット例外クラスヘッダファイル
 *
 *	@note	ランタイムエラー継承
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/08
 */
/**===Include Guard========================================*/
#ifndef	_SOCKETEXCEPTION_H_
#define	_SOCKETEXCEPTION_H_
/**===File Include=========================================*/
#include	<stdexcept>
/**===Class Definition=====================================*/
class SocketException:public std::runtime_error{
public:
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	例外メッセージ
	 */
	SocketException(const std::string& msg)
		:std::runtime_error(msg){
	}
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/