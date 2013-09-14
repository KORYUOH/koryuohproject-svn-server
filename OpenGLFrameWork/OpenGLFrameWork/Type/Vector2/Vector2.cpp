/**===File Commentary=======================================*/
/**
 *	@file	Vector2.cpp
 *
 *	@brief	�񎟌��x�N�g��
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/26
 */
/**===File Include=========================================*/
#include	<Type/Vector2/Vector2.h>
#include	<cmath>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 */
/**========================================================*/
Vector2::Vector2()
	:x_(0),y_(0)
{}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	x���W
  *	@param[in]	y���W
 */
/**========================================================*/
Vector2::Vector2(float x,float y)
	:x_(x),y_(y)
{}
/**========================================================*/
/**
 *	@brief	�m���������߂�
 *	@return	�m����
 */
/**========================================================*/
float Vector2::length()const{
	return (float)std::sqrtf(x_*x_+y_*y_);
}
/**========================================================*/
/**
 *	@brief	���K�����s��
 *	@return	���K���ł����ꍇ�͐��K�������l
 */
/**========================================================*/
Vector2& Vector2::normalize(){
	float len = length();
	if(len != 0){
		return *this /= len;
	}
	return *this;
}
/**========================================================*/
/**
 *	@brief	���ς����߂�
 *	@param[in]	���̃x�N�g��
 *	@return	����
 */
/**========================================================*/
float Vector2::InnerProduct(const Vector2& v)const{
	return x_ * v.x_ + y_*v.y_;
}
/**========================================================*/
/**
 *	@brief	�P�����Z�q�I�[�o�[���[�h
 *	@return	�x�N�g��
 */
/**========================================================*/
Vector2 Vector2::operator+(){
	return *this;
}
/**========================================================*/
/**
 *	@brief	�P�����Z�q�I�[�o�[���[�h
 *	@return	�t�x�N�g��
 */
/**========================================================*/
Vector2 Vector2::operator-(){
	return Vector2(-x_,-y_);
}
/**========================================================*/
/**
 *	@brief	������Z�q�I�[�o�[���[�h
 *	@param[in]	���Z�x�N�g��
 *	@return	�x�N�g��
 */
/**========================================================*/
Vector2& Vector2::operator+=(const Vector2& v){
	x_ += v. x_;
	y_ += v.y_;
	return *this;
}
/**========================================================*/
/**
 *	@brief	������Z�q�I�[�o�[���[�h
 *	@param[in]	���Z�x�N�g��
 *	@return	�x�N�g��
 */
/**========================================================*/
Vector2& Vector2::operator-=(const Vector2& v){
	x_ -= v.x_;
	y_ -= v.y_;
	return *this;
}
/**========================================================*/
/**
 *	@brief	������Z�q�I�[�o�[���[�h
 *	@param[in]	��Z�X�J���[
 *	@return	�x�N�g��
 */
/**========================================================*/
Vector2& Vector2::operator*= (float s){
	x_ *= s;
	y_ *= s;
	return *this;
}
/**========================================================*/
/**
 *	@brief	������Z�q�I�[�o�[���[�h
 *	@param[in]	���Z�X�J���[
 *	@return	�x�N�g��
 */
/**========================================================*/
Vector2& Vector2::operator /= (float s){
	x_ /= s;
	y_ /= s;
	return *this;
}
/**========================================================*/
/**
 *	@brief	2�����Z�q�I�[�o�[���[�h
 *	@param[in]	�x�N�g��
 *	@param[in]	�x�N�g��
 *	@return	�x�N�g��
 */
/**========================================================*/
const Vector2 operator+(const Vector2& v1,const Vector2& v2){
	Vector2 tmp(v1);
	tmp += v2;
	return tmp;
}
/**========================================================*/
/**
 *	@brief	2�����Z�q�I�[�o�[���[�h
 *	@param[in]	�x�N�g��
 *	@param[in]	�x�N�g��
 *	@return	�x�N�g��
 */
/**========================================================*/
const Vector2 operator-(const Vector2& v1,const Vector2& v2 ){
	Vector2 tmp ( v1);
	tmp -= v2;
	return tmp;
}
/**========================================================*/
/**
 *	@brief	2�����Z�q�I�[�o�[���[�h
 *	@param[in]	�x�N�g��
 *	@param[in]	�X�J���[
 *	@return	�x�N�g��
 */
/**========================================================*/
const Vector2 operator*(const Vector2& v,float s){
	Vector2 tmp(v);
	tmp*=s;
	return tmp;
}
/**========================================================*/
/**
 *	@brief	2�����Z�q�I�[�o�[���[�h
 *	@param[in]	�X�J���[
 *	@param[in]	�x�N�g��
 *	@return	�x�N�g��
 */
/**========================================================*/
const Vector2 operator*(float s,const Vector2& v){
	return v * s;
}
/**========================================================*/
/**
 *	@brief	2�����Z�q�I�[�o�[���[�h
 *	@param[in]	�x�N�g��
 *	@param[in]	�X�J���[
 *	@return	�x�N�g��
 */
/**========================================================*/
const Vector2 operator / (const Vector2& v,float s){
	Vector2 tmp(v);
	tmp /= s;
	return tmp;
}

/**===End Of File==========================================*/