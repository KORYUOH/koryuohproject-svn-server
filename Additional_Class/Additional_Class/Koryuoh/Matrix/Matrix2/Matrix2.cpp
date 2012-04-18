/**===File Commentary=======================================*/
/**
 *	@file	Matrix2.cpp
 *
 *	@brief	二次ベクトル
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/18
 */
/**===File Include=========================================*/
#include	"Matrix2.h"
#include	<cmath>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	加算
 *	@param[in]	加算する値
 *	@author	KORYUOH
 *	@return	自身
 */
/**========================================================*/
Matrix2& Matrix2::add(const Matrix2& add){
	this->x += add.x;
	this->y += add.y;
	return *this;
}
/**========================================================*/
/**
 *	@brief	減算
 *	@param[in]	減算する値
 *	@author	KORYUOH
 *	@return	自身
 */
/**========================================================*/
Matrix2& Matrix2::sub(const Matrix2& sub){
	this->x -= sub.x;
	this->y -= sub.y;
	return *this;
}
/**========================================================*/
/**
 *	@brief	実数倍
 *	@param[in]	スケール
 *	@author	KORYUOH
 *	@return	自身
 */
/**========================================================*/
Matrix2& Matrix2::scale(float s){
	this->x*s;
	this->y*s;
	return *this;
}
/**========================================================*/
/**
 *	@brief	長さを求める
 *	@author	KORYUOH
 *	@return	長さ
 */
/**========================================================*/
float Matrix2::length(){
	return std::sqrtf(this->x*this->x+this->y*this->y);
}
/**========================================================*/
/**
 *	@brief	正規化
 *	@note	単位ベクトル化
 *	@author	KORYUOH
 */
/**========================================================*/
void Matrix2::nomalize(){
	float len = this->length();
	if(len !=0){
	this->x/=len;
	this->y/=len;
	}
}
/**========================================================*/
/**
 *	@brief	内積を求める
 *	@param[in]	ターゲット
 *	@author	KORYUOH
 *	@return	内積値
 */
/**========================================================*/
float Matrix2::innerProduct(const Matrix2& Target){
	return this->x*Target.x+this->y*Target.y;
}




/**===End Of File==========================================*/