/**===File Commentary=======================================*/
/**
 *	@file	Dice.cpp
 *
 *	@brief	�T�C�R���N���X
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
 *	@brief	�R���X�g���N�^
 */
/**========================================================*/
Dice::Dice():mSeed((unsigned int)std::time(NULL)){
	std::srand(mSeed);
}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�V�[�h
 */
/**========================================================*/
Dice::Dice(unsigned int seed):mSeed(seed){
}
/**========================================================*/
/**
 *	@brief	6�ʃ_�C�X��U��
 *	@return	�o��
 */
/**========================================================*/
int Dice::Six(){
	return getRandom(1,6);
}
/**========================================================*/
/**
 *	@brief	�����_���Ȓl���擾
 *	@param[in]	�ŏ��l
 *	@param[in]	�ő�l
 *	@return	�o��
 */
/**========================================================*/
int Dice::getRandom(int min, int max){
	return min+(std::rand()%max-min);
}
/**========================================================*/
/**
 *	@brief	�R�C�����g�X����
 *	@return	true�Ȃ�\
 */
/**========================================================*/
bool Dice::coin(){
	return getRandom(0,1);
}
/**========================================================*/
/**
 *	@brief	nDn�_�C�X��U��
 *	@param[in]	��
 *	@param[in]	��
 *	@param[in]	�ŏ��ǉ��l
 *	@return	�o�ڂ̍��v
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
 *	@brief	nDn�_�C�X��U��
 *	@param[in]	��
 *	@param[in]	��
 *	@param[in]	�ŏ��ǉ��l
 *	@param[in]	���l�\���t���O
 *	@return	�o�ڂ̍��v
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
 *	@brief	��̎擾
 *	@return	��
 */
/**========================================================*/
unsigned int Dice::getSeed()const{
	return mSeed;
}
/**========================================================*/
/**
 *	@brief	��̎擾
 *	@return	��
 */
/**========================================================*/
Dice::strBox Dice::getStrBox()const{
	return mStrBox;
}



/**===End Of File==========================================*/