/**===File Commentary=======================================*/
/**
 *	@file	instanceof.hpp
 *
 *	@brief	Run Time Type Idenfication
 *
 *	@author	KORYUOH
 *
 *	@date	2013/01/08
 */
/**===Include Guard========================================*/
#ifndef	__INSTANCEOF_HPP_
#define	__INSTANCEOF_HPP_
/**===File Include=========================================*/
/**===Class Definition=====================================*/
class Instanceof{
public:
	/**
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	KORYUOH
	 *	@return	<戻り値>
	 */
	template <typename T,typename Ty>
	bool Instanceof (T &typeOne,Ty TypeTow){
		return typeid(typeOne) == typeid(TypeTow);
	}	
private:
	/**	メンバー変数*/

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/