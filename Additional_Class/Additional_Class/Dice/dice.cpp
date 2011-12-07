/*==============================================*/
/**
 *		@FileName				dice.h
 *		@author					KORYUOH
 *		@CreateDate			2011/12/07	
 *		@LastUpdate			2011/12/07	KORYUOH
 *		@Note					This class can use the features of dice
 */
/*==============================================*/

/*==============================================*/
/**
 *										Include Headder Files
 *										�w�b�_�[�t�@�C���ǂݍ���
 */
/*==============================================*/
#include <ctime>
#include "dice.h"
/*==============================================*/
/**
 *										Method
 *										���\�b�h
 */
/*==============================================*/
int Dice::XdY_S(const int x,const int y,const int s){
	int sum = 0;
	for(int i=0;i<x;i++){
	sum+=stdDice(y);
	}
	return sum+s;
}

int Dice::stdDice(){
	return getRand(1,6);
}

int Dice::stdDice(const int aAspect){
	return getRand(1,aAspect);
}

int Dice::getRand(const int min,const int max){
	return min + std::rand() % (max - min);
}
int Dice::getRand()const{
	return m_min + std::rand() % (m_max - m_min);
}
int Dice::arrayDice(const int arrayDice){
	return getRand(0,arrayDice);
}
bool Dice::Coin(){
	return (stdDice(1) == 1)? true:false;
}
/*******		End Of File		******************************************/