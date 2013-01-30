/**===File Commentary=======================================*/
/**
 *	@file	Quaternion.cpp
 *
 *	@brief	�N�H�[�^�j�I��
 *
 *	@author	KORYUOH
 *
 *	@date	2013/01/30
 */
/**===File Include=========================================*/
#include	<Type/Quaternion/Quaternion.h>
#include	<Type/Vector3/Vector3.h>
#include	<Utility/Math_Utility.h>
#include	<cmath>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	X����
 *	@param[in]	Y����
 *	@param[in]	Z����
 *	@param[in]	����
 */
/**========================================================*/
Quaternion::Quaternion(float x,float y,float z,float w)
	:x_(x)
	,y_(y)
	,z_(z)
	,w_(w)
{
}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	���W
 *	@param[in]	�p�x
 */
/**========================================================*/
Quaternion::Quaternion(const Vector3& v,float angle){
	float theta = Math::sin(angle / 2.0f);
	::Quaternion(theta *v.x_, theta * v.y_,theta * v.z_, Math::cos(angle /2.0f));
}
/**========================================================*/
/**
 *	@brief	����
 *	@param[in]	���̃N�H�[�^�j�I��
 *	@return	���ϒl
 */
/**========================================================*/
float Quaternion::InnerProduct(const Quaternion& q)const{
	return x_ * q.x_ + y_ * q.y_ + z_ * q.z_ + w_ * q.w_;
}
/**========================================================*/
/**
 *	@brief	�����擾
 *	@return	����
 */
/**========================================================*/
float Quaternion::length()const{
	return std::sqrtf(InnerProduct(*this));
}
/**========================================================*/
/**
 *	@brief	���K��
 *	@return	�P�ʃN�H�[�^�j�I��
 */
/**========================================================*/
Quaternion& Quaternion::normalize(){
	float len = length();
	if(len != 0)
		*this /= len;
	return *this;
}
/**========================================================*/
/**
 *	@brief	�P�����Z�q�I�[�o�[���[�h
 */
/**========================================================*/
Quaternion Quaternion::operator+()const{
	return *this;
}
/**========================================================*/
/**
 *	@brief	�P�����Z�q�I�[�o�[���[�h
 */
/**========================================================*/
Quaternion Quaternion::operator-()const{
	return Quaternion(-x_,-y_, -z_,-w_);
}
/**========================================================*/
/**
 *	@brief	������Z�q�I�[�o�[���[�h
 *	@param[in]	���̃N�H�[�^�j�I��
 *	@return	���Z���ꂽ�l
 */
/**========================================================*/
Quaternion& Quaternion::operator+=(const Quaternion& q){
	x_ += q.x_;
	y_ += q.y_;
	z_ += q.z_;
	w_ += q.w_;
	return *this;
}
/**========================================================*/
/**
 *	@brief	������Z�q�I�[�o�[���[�h
 *	@param[in]	���̃N�H�[�^�j�I��
 *	@return	���Z���ꂽ�l
 */
/**========================================================*/
Quaternion& Quaternion::operator-=(const Quaternion& q){
	x_ -= q.x_;
	y_ -= q.y_;
	z_ -= q.z_;
	w_-= q.w_;
	return *this;
}
/**========================================================*/
/**
 *	@brief	������Z�q�I�[�o�[���[�h
 *	@param[in]	��Z
 *	@return	��Z
 */
/**========================================================*/
Quaternion& Quaternion::operator*=(const Quaternion& q){
	x_=	x_		*	q.w_	+	y_ * q.z_	- z_ * q.y_  + w_ * q.x_;
	y_=	x_		*	q.z_	+	y_ * q.w_	+ z_ * q.x_  + w_ * q.y_;
	z_=	x_		*	q.y_	-	y_ * q.x_	- z_ * q.w_  + w_ * q.z_;
	w_=	-x_	*	q.x_	-	y_ * q.y_	+ z_ * q.z_  + w_ * q.w_;
	return *this;
}
/**========================================================*/
/**
 *	@brief	��Z�i�X�J���{�j
 *	@param[in]	�{��
 *	@return	�v�Z�l
 */
/**========================================================*/
Quaternion& Quaternion::operator*=(float s){
	x_		*=s;
	y_		*=s;
	z_		*=s;
	w_	*=s;
	return *this;
}
/**========================================================*/
/**
 *	@brief	���Z�i�X�J���j
 *	@param[in]	�X�J��
 *	@return	���Z���ꂽ�l
 */
/**========================================================*/
Quaternion& Quaternion::operator/=(float s){
	return *this *= 1.0f / s;
}
/**========================================================*/
/**
 *	@brief	�񍀉��Z�q�I�[�o�[���[�h
 *	@param[in]	�����l
  *	@param[in]	�����l
 *	@return	�N�H�[�^�j�I��
 */
/**========================================================*/
const Quaternion operator+(const Quaternion& q1,const Quaternion& q2){
	Quaternion tmp(q1);
	return (tmp += q2);
}
/**========================================================*/
/**
 *	@brief	�񍀉��Z�q�I�[�o�[���[�h
 *	@param[in]	�N�H�[�^�j�I��
 *	@param[in]	�N�H�[�^�j�I��
 *	@return	�v�Z�l
 */
/**========================================================*/
const Quaternion operator-(const Quaternion& q1,const Quaternion& q2){
	Quaternion tmp(q1);
	return (tmp -= q2);
}
/**========================================================*/
/**
 *	@brief	�񍀉��Z�q�I�[�o�[���[�h
 *	@param[in]	�N�H�[�^�j�I��
 *	@param[in]	�N�H�[�^�j�I��
 *	@return	�N�H�[�^�j�I��
 */
/**========================================================*/
const Quaternion operator*(const Quaternion& q1,const Quaternion& q2){
	Quaternion tmp(q1);
	return (tmp *= q2);
}
/**========================================================*/
/**
 *	@brief	�񍀉��Z�q�I�[�o�[���[�h
 *	@param[in]	�N�H�[�^�j�I��
 *	@param[in]	�X�J��
 *	@return	�v�Z�l
 */
/**========================================================*/
const Quaternion operator*(const Quaternion& q,float s){
	Quaternion tmp(q);
	return (tmp *= s);
}
/**========================================================*/
/**
 *	@brief	�񍀉��Z�q�I�[�o�[���[�h
 *	@param[in]	�N�H�[�^�j�I��
  *	@param[in]	�N�H�[�^�j�I��
 *	@return	�N�H�[�^�j�I��
 */
/**========================================================*/
const Quaternion operator * (float s,const Quaternion& q){
	Quaternion tmp(q);
	return (tmp *= s);
}
/**========================================================*/
/**
 *	@brief	�񍀉��Z�q�I�[�o�[���[�h
 *	@param[in]	�N�H�[�^�j�I��
  *	@param[in]	�N�H�[�^�j�I��
 *	@return	�N�H�[�^�j�I��
 */
/**========================================================*/
const Quaternion operator / (const Quaternion& q,float s){
	Quaternion tmp ( q);
	return tmp /= s;
}
/**========================================================*/
/**
 *	@brief	�񍀉��Z�q�I�[�o�[���[�h
 *	@param[in]	�N�H�[�^�j�I��
  *	@param[in]	�N�H�[�^�j�I��
 *	@return	�N�H�[�^�j�I��
 */
/**========================================================*/
Quaternion Quaternion::slerp(const Quaternion& q,float t)const{
	float dot = InnerProduct(q);
	Quaternion tmp = q;
	if( dot < 0.0f){
		dot = -dot;
		tmp = -q;
	}
	float k0 = 1.0f - t;
	float k1 = t;
	if((1.0f - dot) > 0.0001){
		float theta = std::acosf(dot); 
		k0 = std::sinf(theta + k0) / std::sinf(theta);
		k1 = std::sinf(theta + k1) / std::sinf(theta);
	}
	return *this * k0 + tmp*k1;
}

/**===End Of File==========================================*/