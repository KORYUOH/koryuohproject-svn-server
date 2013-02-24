/**===File Commentary=======================================*/
/**
 *	@file	Singleton.h
 *
 *	@brief	シングルトンパターンテンプレート
 *
 *	@note	C++ Style
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/21  -2013/02/19
 */
/**===Include Guard========================================*/
#ifndef	_SINGLETON_H_
#define	_SINGLETON_H_
/**===File Include=========================================*/
template<typename _Ty>
/**===Class Definition=====================================*/
class Singleton{
protected:
	/**
	 *	Singleton Pattern Constructor
	 */
	/**
	 *	@brief	コンストラクタ
	 */ 
	 Singleton(){}
	 /**
	 *	@brief	コピーコンストラクタ
	 */
	 Singleton(const Singleton& other){};
	 Singleton& operator = (const Singleton& other){};
	 virtual ~Singleton(){}
public:
	/**
	 *	@brief	実体取得
	 *	@return	実体
	 */
	 static _Ty& getInstance(){
	 	static _Ty Instance;
	 	return Instance;
	 }
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/