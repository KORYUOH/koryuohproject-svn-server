/**===File Commentary=======================================*/
/**
 *	@file	Quaternion.cpp
 *
 *	@brief	クォータニオン
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
 *	@brief	コンストラクタ
 *	@param[in]	X成分
 *	@param[in]	Y成分
 *	@param[in]	Z成分
 *	@param[in]	虚数
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
 *	@brief	コンストラクタ
 *	@param[in]	座標
 *	@param[in]	角度
 */
/**========================================================*/
Quaternion::Quaternion(const Vector3& v,float angle){
	float theta = Math::sin(angle / 2.0f);
	::Quaternion(theta *v.x_, theta * v.y_,theta * v.z_, Math::cos(angle /2.0f));
}
/**========================================================*/
/**
 *	@brief	内積
 *	@param[in]	他のクォータニオン
 *	@return	内積値
 */
/**========================================================*/
float Quaternion::InnerProduct(const Quaternion& q)const{
	return x_ * q.x_ + y_ * q.y_ + z_ * q.z_ + w_ * q.w_;
}
/**========================================================*/
/**
 *	@brief	長さ取得
 *	@return	長さ
 */
/**========================================================*/
float Quaternion::length()const{
	return std::sqrtf(InnerProduct(*this));
}
/**========================================================*/
/**
 *	@brief	正規化
 *	@return	単位クォータニオン
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
 *	@brief	単項演算子オーバーロード
 */
/**========================================================*/
Quaternion Quaternion::operator+()const{
	return *this;
}
/**========================================================*/
/**
 *	@brief	単項演算子オーバーロード
 */
/**========================================================*/
Quaternion Quaternion::operator-()const{
	return Quaternion(-x_,-y_, -z_,-w_);
}
/**========================================================*/
/**
 *	@brief	代入演算子オーバーロード
 *	@param[in]	他のクォータニオン
 *	@return	加算された値
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
 *	@brief	代入演算子オーバーロード
 *	@param[in]	他のクォータニオン
 *	@return	減算された値
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
 *	@brief	代入演算子オーバーロード
 *	@param[in]	乗算
 *	@return	乗算
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
 *	@brief	乗算（スカラ倍）
 *	@param[in]	倍率
 *	@return	計算値
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
 *	@brief	除算（スカラ）
 *	@param[in]	スカラ
 *	@return	除算された値
 */
/**========================================================*/
Quaternion& Quaternion::operator/=(float s){
	return *this *= 1.0f / s;
}
/**========================================================*/
/**
 *	@brief	二項演算子オーバーロード
 *	@param[in]	足す値
  *	@param[in]	足す値
 *	@return	クォータニオン
 */
/**========================================================*/
const Quaternion operator+(const Quaternion& q1,const Quaternion& q2){
	Quaternion tmp(q1);
	return (tmp += q2);
}
/**========================================================*/
/**
 *	@brief	二項演算子オーバーロード
 *	@param[in]	クォータニオン
 *	@param[in]	クォータニオン
 *	@return	計算値
 */
/**========================================================*/
const Quaternion operator-(const Quaternion& q1,const Quaternion& q2){
	Quaternion tmp(q1);
	return (tmp -= q2);
}
/**========================================================*/
/**
 *	@brief	二項演算子オーバーロード
 *	@param[in]	クォータニオン
 *	@param[in]	クォータニオン
 *	@return	クォータニオン
 */
/**========================================================*/
const Quaternion operator*(const Quaternion& q1,const Quaternion& q2){
	Quaternion tmp(q1);
	return (tmp *= q2);
}
/**========================================================*/
/**
 *	@brief	二項演算子オーバーロード
 *	@param[in]	クォータニオン
 *	@param[in]	スカラ
 *	@return	計算値
 */
/**========================================================*/
const Quaternion operator*(const Quaternion& q,float s){
	Quaternion tmp(q);
	return (tmp *= s);
}
/**========================================================*/
/**
 *	@brief	二項演算子オーバーロード
 *	@param[in]	クォータニオン
  *	@param[in]	クォータニオン
 *	@return	クォータニオン
 */
/**========================================================*/
const Quaternion operator * (float s,const Quaternion& q){
	Quaternion tmp(q);
	return (tmp *= s);
}
/**========================================================*/
/**
 *	@brief	二項演算子オーバーロード
 *	@param[in]	クォータニオン
  *	@param[in]	クォータニオン
 *	@return	クォータニオン
 */
/**========================================================*/
const Quaternion operator / (const Quaternion& q,float s){
	Quaternion tmp ( q);
	return tmp /= s;
}
/**========================================================*/
/**
 *	@brief	二項演算子オーバーロード
 *	@param[in]	クォータニオン
  *	@param[in]	クォータニオン
 *	@return	クォータニオン
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