/**===File Commentary=======================================*/
/**
 *	@file	Matrix2.cpp
 *
 *	@brief	�񎟃x�N�g��
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
 *	@brief	���Z
 *	@param[in]	���Z����l
 *	@author	KORYUOH
 *	@return	���g
 */
/**========================================================*/
Matrix2& Matrix2::add(const Matrix2& add){
	this->x += add.x;
	this->y += add.y;
	return *this;
}
/**========================================================*/
/**
 *	@brief	���Z
 *	@param[in]	���Z����l
 *	@author	KORYUOH
 *	@return	���g
 */
/**========================================================*/
Matrix2& Matrix2::sub(const Matrix2& sub){
	this->x -= sub.x;
	this->y -= sub.y;
	return *this;
}
/**========================================================*/
/**
 *	@brief	�����{
 *	@param[in]	�X�P�[��
 *	@author	KORYUOH
 *	@return	���g
 */
/**========================================================*/
Matrix2& Matrix2::scale(float s){
	this->x*s;
	this->y*s;
	return *this;
}
/**========================================================*/
/**
 *	@brief	���������߂�
 *	@author	KORYUOH
 *	@return	����
 */
/**========================================================*/
float Matrix2::length(){
	return std::sqrtf(this->x*this->x+this->y*this->y);
}
/**========================================================*/
/**
 *	@brief	���K��
 *	@note	�P�ʃx�N�g����
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
 *	@brief	���ς����߂�
 *	@param[in]	�^�[�Q�b�g
 *	@author	KORYUOH
 *	@return	���ϒl
 */
/**========================================================*/
float Matrix2::innerProduct(const Matrix2& Target){
	return this->x*Target.x+this->y*Target.y;
}




/**===End Of File==========================================*/