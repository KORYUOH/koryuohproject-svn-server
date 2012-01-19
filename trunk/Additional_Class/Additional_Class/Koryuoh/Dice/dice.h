/*==============================================*/
/**
 *		@FileName				dice.h
 *		@author					KORYUOH
 *		@CreateDate			2011/12/07	
 *		@LastUpdate			2011/12/07	KORYUOH
 *		@Note					This class can use the features of dice
 */
/*==============================================*/
#ifndef	__Dice
#define	__Dice
#include <ctime>
#include <cstdlib>
/*==============================================*/
namespace KORYUOH{
class Dice{
public:
/*==============================================*/
/**
 *										constructor
 *										コンストラクタ
 */
/*==============================================*/
	Dice():m_min(0),m_max(1){
		std::srand((unsigned)std::time(NULL));
	};
/*==============================================*/
/**
 *										constructor
 *										コンストラクタ
 _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
 *		@param[in]	aMin			int			//Dice Parameter Minimum
 *		@param[in]	aMax			int			//Dice Parameter Maximum
 */
/*==============================================*/
	Dice(int aMin,int aMax):m_min(aMin),m_max(aMax){
		std::srand((unsigned)std::time(NULL));
	}
/*==============================================*/
/**
 *										Virtual destructor
 *										仮想デストラクタ
 */
/*==============================================*/
	virtual ~Dice(){};
/*==============================================*/
private:
/*==============================================*/
/**
 *										Member Variables
 *										メンバー変数
 */
/*==============================================*/
	int		m_min,m_max;
/*==============================================*/
public:
/*==============================================*/
/**
 *									Additional Methods
 *										追加メソッド
 */
/*==============================================*/
	int XdY_S(const int x,const int y,const int s);
	int getRand(const int min,const int max);
	int getRand()const;
	int stdDice();
	int stdDice(const int aTry);
	int arrayDice(const int arrayMax);
	bool Coin();
};
};
#endif
/*******		End Of File		******************************************/