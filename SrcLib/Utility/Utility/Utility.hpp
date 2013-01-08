/**===File Commentary=======================================*/
/**
 *	@file	Utility.h
 *
 *	@brief	ゲーム用ユーティリティー
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/23
 */
/**===Include Guard========================================*/
#ifndef	_UTILITY_H_
#define	_UTILITY_H_
/**===File Include=========================================*/
#include	<cmath>
#include	<xutility>
/**===Class Definition=====================================*/
class Utility{
public:
	/**
	 *	@brief	クランプ
	 *	@param[in]	最小値
	 *	@param[in]	最大値
	 *	@param[in]	クランプ対象
	 *	@return	クランプされた値
	 */
	template<typename Ty>
	static Ty clamp(const Ty& minimum,const Ty& maximum,const Ty& target){
		return std::min(maximum,std::max(minimum,target));
	}

	/**
	 *	@brief	レンジ判定
	 *	@param[in]	現在値
	 *	@param[in]	最小値
	 *	@param[in]	最大値
	 *	@return 範囲内ならtrue
	 */
	template<typename Ty>
	static bool isInRange(const Ty& now ,const Ty& minimum , const Ty& maximum){
		if(now < minimum)
			return false;
		if(now > maximum)
			return false;
		return true;
	}
	/**
	 *	@brief	線形補完
	 *	@param[in]	出発
	 *	@param[in]	到着
	 *	@param[in]	パーセント
	 *	@return 線形保管された値
	 */
	template <typename T>
	static T lerp(const T& start,const T& end,float persent){
		return (start + persent*(end-start));
	}

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/