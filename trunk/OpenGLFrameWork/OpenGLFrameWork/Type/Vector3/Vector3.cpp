/**===File Commentary=======================================*/
/**
 *	@file	Vector3.cpp
 *
 *	@brief	�O�����x�N�g��
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/26
 */
/**===File Include=========================================*/
#include	<Type/Vector3/Vector3.h>
#include	<cmath>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 */
/**========================================================*/
Vector3::Vector3()
	:x_(0),y_(0),z_(0)
{}
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	X���W
 *	@param[in]	Y���W
 *	@param[in]	Z���W
 */
/**========================================================*/
Vector3::Vector3(float x , float y , float z)
	:x_(x)
	,y_(y)
	,z_(z)
{}
/**========================================================*/
/**
 *	@brief	�m�������擾
 *	@return	�m����
 */
/**========================================================*/
float Vector3::length()const{
	return (float)std::sqrtf((x_*x_)+(y_*y_)+(z_*z_));
}
/**========================================================*/
/**
 *	@brief	���K�����s��
 *	@return	���K�����ꂽ�x�N�g��
 */
/**========================================================*/
Vector3& Vector3::normalize(){
	float len = length();
	if( len != 0){
		*this /= len;
		return *this;
	}
	return *this;
}
/**========================================================*/
/**
 *	@brief	����
 *	@param[in]	���̃x�N�g��
 *	@return	���ϒl
 */
/**========================================================*/
float Vector3::InnerProduct(const Vector3& v)const{
	return (x_*v.x_)+(y_*v.y_)+(z_*v.z_);
}
/**========================================================*/
/**
 *	@brief	�O��
 *	@param[in]	���̃x�N�g��
 *	@return	�O�ϒl
 */
/**========================================================*/
Vector3 Vector3::OuterProduct(const Vector3& v) const{
	return Vector3 (
		(y_*v.z_) - (z_ * v.y_),
		(z_*v.x_) - (x_ * v.z_),
		(x_*v.y_) - (y_ * v.x_) 
		);
}
/**========================================================*/
/**
 *	@brief	�P�����Z�q�I�[�o�[���[�h
 *	@return	�x�N�g��
 */
/**========================================================*/
Vector3 Vector3::operator + () const {
	return *this;
}
/**========================================================*/
/**
 *	@brief	�P�����Z�q�I�[�o�[���[�h
 *	@return	�t�x�N�g��
 */
/**========================================================*/
Vector3 Vector3::operator-()const{
	return Vector3 (-x_,-y_,-z_);
}
/**========================================================*/
/**
 *	@brief	������Z�q�I�[�o�[���[�h
 *	@param[in]	���Z�l�x�N�g��
 *	@return	�O�����x�N�g��
 */
/**========================================================*/
Vector3& Vector3::operator += (const Vector3& v){
	x_ += v.x_;
	y_ += v.y_;
	z_ += v.z_;
	return *this;
	}
/**========================================================*/
/**
 *	@brief	������Z�q�I�[�o�[���[�h
 *	@param[in]		���Z�l�x�N�g��
 *	@return	�O�����x�N�g��
 */
/**========================================================*/
Vector3& Vector3::operator -= (const Vector3& v){
	x_ -= v.x_;
	y_ -= v.y_;
	z_ -= v.z_;
	return *this;
}
/**========================================================*/
/**
 *	@brief	������Z�q�I�[�o�[���[�h
 *	@param[in]	��Z�l
 *	@return	�O�����x�N�g��
 */
/**========================================================*/
Vector3& Vector3::operator *= (float s){
	x_ *= s;
	y_ *= s;
	z_ *= s;
	return *this;
	}
/**========================================================*/
/**
 *	@brief	������Z�q�I�[�o�[���[�h
 *	@param[in]	���Z�l
 *	@return	�O�����x�N�g��
 */
/**========================================================*/
Vector3& Vector3::operator /= (float s){
	x_ /= s;
	y_ /= s;
	z_ /= s;
	return *this;
	}
/**========================================================*/
/**
 *	@brief	2�����Z�q�I�[�o�[���[�h
 *	@param[in]	�x�N�g��1
 *	@param[in]	�x�N�g��2
 *	@return	���Z�x�N�g��
 */
/**========================================================*/
const Vector3 operator + ( const Vector3& v1 , const Vector3& v2){
	Vector3 result( v1) ;
	result += v2;
	return result;
}
/**========================================================*/
/**
 *	@brief	2�����Z�q�I�[�o�[���[�h
 *	@param[in]	�x�N�g��1
 *	@param[in]	�x�N�g��2
 *	@return	���Z�x�N�g��
 */
/**========================================================*/
const Vector3 operator - ( const Vector3& v1 , const Vector3& v2){
	Vector3 retult( v1) ;
	retult -= v2;
	return retult;

}
/**========================================================*/
/**
 *	@brief	2�����Z�q�I�[�o�[���[�h
 *	@param[in]	�x�N�g��
 *	@param[in]	�X�J��
 *	@return	�x�N�g��
 */
/**========================================================*/

const Vector3 operator * ( const Vector3& v , float s){
	Vector3 retult( v) ;
	retult *= s;
	return retult;

}
/**========================================================*/
/**
 *	@brief	2�����Z�q�I�[�o�[���[�h
 *	@param[in]	�X�J��
 *	@param[in]	�x�N�g��
*	@return	�x�N�g��
 */
/**========================================================*/
const Vector3 operator * ( float s , const Vector3& v){
	return v*s;

}
/**========================================================*/
/**
 *	@brief	2�����Z�q�I�[�o�[���[�h
 *	@param[in]	�x�N�g��
 *	@param[in]	�X�J��
 *	@return	�x�N�g��
 */
/**========================================================*/
const Vector3 operator / ( const Vector3& v , float s){
	Vector3 retult( v) ;
	retult /= s;
	return retult;

}
/**===End Of File==========================================*/