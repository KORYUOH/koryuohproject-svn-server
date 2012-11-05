/**===File Commentary=======================================*/
/**
 *	@file	Color4.cpp
 *
 *	@brief	RGBA色クラス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/07/03
 */
/**===File Include=========================================*/
#include	<Type/Color4/Color4.h>
#include	<algorithm>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	コンストラクタ
 */
/**========================================================*/
Color4::Color4()
	:r_(0.0f)
	,g_(0.0f)
	,b_(0.0f)
	,a_(0.0f){
}
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	赤
 *	@param[in]	緑
 *	@param[in]	青
 *	@param[in]	透過
 */
/**========================================================*/
Color4::Color4(float r,float g,float b,float a)
	:r_(r)
	,g_(g)
	,b_(g)
	,a_(a)
{}

/**========================================================*/
/**
 *	@brief	クランプ
 *	@return	クランプされた値
 */
/**========================================================*/
Color4& Color4::saturate(){
	r_	=	std::min(1.0f,std::max(0.0f,r_));
	g_	=	std::min(1.0f,std::max(0.0f,g_));
	b_	=	std::min(1.0f,std::max(0.0f,b_));
	a_	=	std::min(1.0f,std::max(0.0f,a_));
	return *this;
}
/**========================================================*/
/**
 *	@brief	グレースケール化
 *	@return	グレースケールされた値
 */
/**========================================================*/

/**========================================================*/
/**
 *	@brief	単項演算子オーバーロード
 *	@note	マイナスは補色を求める
 */
/**========================================================*/
Color4 Color4::operator+()const{
	return *this;
}
Color4 Color4::operator-()const{
	return Color4 ((1.0f-r_),(1.0f-g_),(1.0f-b_),a_);
}
/**========================================================*/
/**
 *	@brief	代入演算子オーバーロード
 */
/**========================================================*/
Color4& Color4::operator+=(const Color4& c){
	r_	+= c.r_;
	g_	+= c.g_;
	b_	+= c.b_;
	a_	+= c.a_;
	return *this;
}
Color4& Color4::operator-=(const Color4& c){
	r_	-= c.r_;
	g_	-= c.g_;
	b_	-= c.b_;
	a_	-= c.a_;
	return *this;
}
Color4& Color4::operator*=(const Color4& c){
	r_	*= c.r_;
	g_	*= c.g_;
	b_	*= c.b_;
	a_	*= c.a_;
	return *this;
}
Color4& Color4::operator/=(const Color4& c){
	r_	/= c.r_;
	g_	/= c.g_;
	b_	/= c.b_;
	a_	/= c.a_;
	return *this;
}

Color4& Color4::operator*=(float s){
	r_	*= s;
	g_	*= s;
	b_	*= s;
	a_	*= s;
	return *this;
}

Color4& Color4::operator/=(float s){
	r_	/= s;
	g_	/= s;
	b_	/= s;
	a_	/= s;
	return *this;
}
/**========================================================*/
/**
 *	@brief	二項演算子オーバーロード
 */
/**========================================================*/
const Color4 operator+(const Color4& c1,const Color4& c2){
	Color4 tmp(c1);
	tmp+=c2;
	return tmp;
}
const Color4 operator-(const Color4& c1,const Color4& c2){
	Color4 tmp(c1);
	tmp-=c2;
	return tmp;
}
const Color4 operator*(const Color4& c1,const Color4& c2){
	Color4 tmp(c1);
	tmp*=c2;
	return tmp;
}
const Color4 operator/(const Color4& c1,const Color4& c2){
	Color4 tmp(c1);
	tmp/=c2;
	return tmp;
}
const Color4 operator*(const Color4& c,float s){
	Color4 tmp(c);
	tmp*=s;
	return tmp;
}
const Color4 operator*(float s,const Color4& c){
	return c*s;
}
const Color4 operator/(const Color4& c,float s){
	Color4 tmp(c);
	tmp/=s;
	return tmp;
}


/**===End Of File==========================================*/