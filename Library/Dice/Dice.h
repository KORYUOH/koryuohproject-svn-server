/**===File Commentary=======================================*/
/**
 *	@file	Dice.h
 *
 *	@brief	サイコロクラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/18
 */
/**===Include Guard========================================*/
#ifndef	_DICE_H_
#define	_DICE_H_
/**===File Include=========================================*/

/**===Class Definition=====================================*/
class Dice{
public:
	/**
	 *	@brief	コンストラクタ
	 */
	Dice();
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	種
	 */
	Dice(unsigned int seed);	
	/**
	 *	@brief	6面ダイスを振る
	 *	@return	出目
	 */
	int Six();
	/**
	 *	@brief	コイントスする
	 *	@return	面
	 */
	bool coin();
	/**
	 *	@brief	nDnサイコロを振る
	 *	@param[in]	面
	 *	@param[in]	個数
	 *	@param[in]	最小追加値
	 *	@param[in]	表示フラグ
	 *	@return	合計値
	 */
	int XdY_S(int x,int y,int s,bool dispFlag);
	/**
	 *	@brief	nDnサイコロを振る
	 *	@param[in]	面
	 *	@param[in]	個数
	 *	@param[in]	最小追加値
	 *	@param[in]	表示フラグ
	 *	@return	合計値
	 */
	int XdY_S(int x,int y,int s=0);
	/**
	 *	@brief	ランダムな値を取得
	 *	@param[in]	最小値
	 *	@param[in]	最大値
	 *	@return	ランダム値
	 */
	int getRandom(int min,int max);
	/**
	 *	@brief	種の取得
	 *	@return	種
	 */
	unsigned int getSeed()const;
private:
	/**	メンバー変数*/
	unsigned int mSeed;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/