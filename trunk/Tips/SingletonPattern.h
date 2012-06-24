/**===File Commentary=======================================*/
/**
 *	@file	Singleton.h
 *
 *	@brief	シングルトンパターン
 *
 *	@note	C++ Style
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/21
 */
/**===Include Guard========================================*/
#ifndef	_SINGLETON_H_
#define	_SINGLETON_H_
/**===File Include=========================================*/
/**===Class Definition=====================================*/
class Singleton{
private:
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
	 Singleton(const Singleton& other);
	 Singleton& operator = (const Singleton& other);
	 
public:
	/**
	 *	@brief	実体取得
	 *	@return	実体
	 */
	 static Singleton& getInstance(){
	 	static Singleton Instance();
	 	return Instance;
	 }
	 /**
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	<作者名>
	 *	@return	<戻り値>
	 */

private:
	/**	メンバー変数*/

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/