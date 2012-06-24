/**===File Commentary=======================================*/
/**
 *	@file	Singleton.h
 *
 *	@brief	シングルトンパターン
 *
 *	@note	Java Style
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/21
 */
/**===Include Guard========================================*/
#ifndef	_SINGLETON_H_
#define	_SINGLETON_H_
/**===File Include=========================================*/
#include	<memory>
typedef std::unique_ptr<Singleton> Singleton_ptr;
/**===Class Definition=====================================*/
class Singleton{
//_/_/_/_/Singleton Block _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
private:
	Singleton_ptr Instance;
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
	static Singleton_ptr& getInstance(){
		if(Instance.enpty())
			Instance.reset(new Singleton());
		return Instance;
	}
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
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