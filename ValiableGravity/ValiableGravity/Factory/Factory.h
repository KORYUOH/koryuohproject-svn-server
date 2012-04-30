/**===File Commentary=======================================*/
/**
 *	@file	Factory.h
 *
 *	@brief	ファクトリークラス
 *
 *	@author	<作者名>
 *
 *	@date	2012/04/30
 */
/**===Include Guard========================================*/
#ifndef	_FACTORY_H_
#define	_FACTORY_H_
/**===File Include=========================================*/
#include	<string>
#include	<algorithm>
#include	<map>
/**===Class Definition=====================================*/
template<class Ty>
class Factory{
public:
	/**
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	<作者名>
	 *	@return	<戻り値>
	 */
	~Factory(){
		std::for_each(mTypeContainer.begin(),mTypeContainer.end(),[&](Ty* pt){delete pt;});
	}
	void add(const std::string& name,Ty* ptr){
		mTypeContainer[name] = ptr;
	}

	std::shared_ptr<Ty> clone(const std::string& name){
		return std::shared_ptr<Ty>(new mTypeContainer[name]);
	}
private:
	/**	メンバー変数*/
	typedef std::map<std::string,Ty*> TypeContainer;
	
	TypeContainer mTypeContainer;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/