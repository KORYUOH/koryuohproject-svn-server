/**===File Commentary=======================================*/
/**
 *	@file	Dice.cpp
 *
 *	@brief	サイコロクラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/18
 */
/**===File Include=========================================*/
#include	"Dice.h"
#include	<cstdlib>
#include	<string>
#include	<ctime>
#include	<vector>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	コンストラクタ
 */
/**========================================================*/
Dice::Dice():mSeed((unsigned int)std::time(NULL)){
	std::srand(mSeed);
}
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	シード
 */
/**========================================================*/
Dice::Dice(unsigned int seed):mSeed(seed){
}
/**========================================================*/
/**
 *	@brief	6面ダイスを振る
 *	@return	出目
 */
/**========================================================*/
int Dice::Six(){
	return getRandom(1,6);
}
/**========================================================*/
/**
 *	@brief	ランダムな値を取得
 *	@param[in]	最小値
 *	@param[in]	最大値
 *	@return	出目
 */
/**========================================================*/
int Dice::getRandom(int min, int max){
	return min+(std::rand()%max-min);
}
/**========================================================*/
/**
 *	@brief	コインをトスする
 *	@return	trueなら表
 */
/**========================================================*/
bool Dice::coin(){
	return getRandom(0,1);
}
/**========================================================*/
/**
 *	@brief	nDnダイスを振る
 *	@param[in]	面
 *	@param[in]	個数
 *	@param[in]	最小追加値
 *	@return	出目の合計
 */
/**========================================================*/
int Dice::XdY_S(int x,int y,int s){
	int sum=0;
	for(int i=0;i<x;i++){
		sum+=getRandom(1,y);
	}
	return sum+s;
}

/**========================================================*/
/**
 *	@brief	nDnダイスを振る
 *	@param[in]	面
 *	@param[in]	個数
 *	@param[in]	最小追加値
 *	@param[in]	数値表示フラグ
 *	@return	出目の合計
 */
/**========================================================*/
int Dice::XdY_S(int x,int y,int s,bool dispFlag){
	if( !dispFlag )
		return XdY_S(x,y,s);
	mStrBox.clear();
	int sum=0;
	for(int i=0;i<x;i++){
		int temp = getRandom(1,y);
		std::string str = "Roll ";
		str += i+1 +":"+ temp;
		mStrBox.push_back(str);
		sum+=temp;
	}
	return sum+s;
}
/**========================================================*/
/**
 *	@brief	種の取得
 *	@return	種
 */
/**========================================================*/
unsigned int Dice::getSeed()const{
	return mSeed;
}
/**========================================================*/
/**
 *	@brief	種の取得
 *	@return	種
 */
/**========================================================*/
Dice::strBox Dice::getStrBox()const{
	return mStrBox;
}



/**===End Of File==========================================*/