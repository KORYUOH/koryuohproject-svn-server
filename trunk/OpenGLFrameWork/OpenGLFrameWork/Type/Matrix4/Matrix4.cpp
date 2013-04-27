/**===File Commentary=======================================*/
/**
 *	@file	Matrix4.cpp
 *
 *	@brief	4行4列の行列
 *
 *	@author	KORYUOH
 *
 *	@date	2012/07/03
 */
/**===File Include=========================================*/
#include	<Type/Matrix4/Matrix4.h>
#include	<Type/Vector3/Vector3.h>
#include	<Utility/Math_Utility.h>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	コンストラクタ
 */
/**========================================================*/
Matrix4::Matrix4(){
	setIdentity();
}
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	m11
 *	@param[in]	m12
 *	@param[in]	m13
 *	@param[in]	m14
*	@param[in]	m21
*	@param[in]	m22
*	@param[in]	m23
*	@param[in]	m24
*	@param[in]	m31
*	@param[in]	m32
*	@param[in]	m33
 *	@param[in]	m34
 *	@param[in]	m41
 *	@param[in]	m42
*	@param[in]	m43
 *	@param[in]	m44
 */
/**========================================================*/
Matrix4::Matrix4(
	float m11,float m12,float m13,float m14,
	float m21,float m22,float m23,float m24,
	float m31,float m32,float m33,float m34,
	float m41,float m42,float m43,float m44){
		m[0][0] = m11;m[0][1] = m12;m[2][0] = m13;m[3][0] = m14;
		m[1][0] = m21;m[1][1] = m22;m[2][1] = m23;m[3][1] = m24;
		m[2][0] = m31;m[2][1] = m32;m[2][2] = m33;m[3][2] = m34;
		m[3][0] = m41;m[3][1] = m42;m[2][3] = m43;m[3][3] = m44;
}
/**========================================================*/
/**
 *	@brief	単位行列を設定
 *	@return	単位行列
 */
/**========================================================*/
Matrix4& Matrix4::setIdentity(){
	return *this = Matrix4(
		1.0f,	0.0f,	0.0f,	0.0f,
		0.0f,	1.0f,	0.0f,	0.0f,
		0.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f
		);
}
/**========================================================*/
/**
 *	@brief	拡縮行列
 *	@param[in]	拡縮
 *	@return	自身
 */
/**========================================================*/
Matrix4& Matrix4::setScale(const Vector3& v){
	m[0][0] = v.x_;	m[0][1] = 0.0f;	m[0][2] = 0.0f;m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = v.y_;	m[1][2] = 0.0f;m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = v.z_;m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;	m[3][2] = 0.0f;m[3][3] = 1.0f;
	return *this;
}
/**========================================================*/
/**
 *	@brief	回転行列
 *	@param[in]	角度（度数法）
 *	@return	回転行列
 */
/**========================================================*/
Matrix4& Matrix4::setRotateX(float angle){
	float Sin = Math::sin(angle);
	float Cos = Math::cos(angle);
	m[0][0] = 1.0f;	m[0][1] = 0.0f;		m[0][2] = 0.0f;		m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = Cos;		m[1][2] = Sin;		m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = -Sin;		m[2][2] = Cos;		m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;		m[3][2] = 0.0f;		m[3][3] = 1.0f;
	return *this;
}
/**========================================================*/
/**
 *	@brief	回転行列
 *	@param[in]	角度（度数法）
 *	@return	回転行列
 */
/**========================================================*/
Matrix4& Matrix4::setRotateY(float angle){
	float Sin = Math::sin(angle);
	float Cos = Math::cos(angle);
	m[0][0] = Cos;	m[0][1] = 0.0f;		m[0][2] = -Sin;	m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = 1.0f;		m[1][2] = 0.0f;	m[1][3] = 0.0f;
	m[2][0] = Sin;	m[2][1] = 0.0f	;	m[2][2] = Cos;	m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;		m[3][2] = 0.0f;	m[3][3] = 1.0f;
	return *this;
}
/**========================================================*/
/**
 *	@brief	回転行列
 *	@param[in]	角度（度数法）
 *	@return	回転行列
 */
/**========================================================*/
Matrix4& Matrix4::setRotateZ(float angle){
	float Sin = Math::sin(angle);
	float Cos = Math::cos(angle);
	m[0][0] = Cos;	m[0][1] = Sin;	m[0][2] = 0.0f;	m[0][3] = 0.0f;
	m[1][0] = -Sin;	m[1][1] = Cos;	m[1][2] = 0.0f;	m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = 1.0f;	m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;	m[3][2] = 0.0f;	m[3][3] = 1.0f;
	return *this;
}

/**========================================================*/
/**
 *	@brief	平行移動行列
 *	@param[in]	移動ベクトル
 *	@return	自身
 */
/**========================================================*/
Matrix4& Matrix4::setTranslate(const Vector3& v){
//	this->setIdentity();
	m[0][0] = 1.0f;	m[0][1] = 0.0f;	m[0][2] = 0.0f;m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = 1.0f;	m[1][2] = 0.0f;m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = 1.0f;m[2][3] = 0.0f;
	m[3][0] = v.x_;	m[3][1] = v.y_;	m[3][2] = v.z_;m[3][3] = 1.0f;
	return *this;
}
/**========================================================*/
/**
 *	@brief	透視変換行列
 *	@param[in]	視野角
 *	@param[in]	アスペクト比
 *	@param[in]	近クリップ面
 *	@param[in]	遠クリップ面
 *	@return	透視変換行列
 */
/**========================================================*/
Matrix4& Matrix4::setPerspective(float fov,float aspect,float near,float far){
	float f = 1.0f/Math::tan(fov/2.0f);
	m[0][0] = f/aspect;		m[0][1] = 0.0f;		m[0][2] =0.0f;									m[0][3] =0.0f;
	m[1][0] = 0.0f;				m[1][1] =f;		  	m[1][2] =0.0f;									m[1][3] =0.0f;
	m[2][0] = 0.0f;				m[2][1] =0.0f;		m[2][2] =(far+near)/(near-far);			m[2][3] =-1.0f;
	m[3][0] = 0.0f;				m[3][1] =0.0f;		m[3][2] =(2*far*near)/(near-far);  		m[3][3] =0.0f;
	return *this;
}
/**========================================================*/
/**
 *	@brief	視点変換行列
 *	@param[in]	視点座標
 *	@param[in]	注視点
 *	@param[in]	上方向ベクトル
 *	@return	視点変換行列
 */
/**========================================================*/
Matrix4& Matrix4::setLookAt(const Vector3& eye,const Vector3& at ,const Vector3& up){
	Vector3 e  ((eye-at));
	e=e.normalize();
	Vector3 v ( up.OuterProduct(e));
	v=v.normalize();
	Vector3 u ( e.OuterProduct(v));
	u=u.normalize();
	m[0][0] = v.x_;								m[0][1] = u.x_;							m[0][2] = e.x_;								m[0][3] = 0.0f;
	m[1][0] = v.y_;								m[1][1] = u.y_;							m[1][2] = e.y_;								m[1][3] = 0.0f;
	m[2][0] = v.z_;								m[2][1] = u.z_;							m[2][2] = e.z_;								m[2][3] = 0.0f;
	m[3][0] = -eye.InnerProduct(v);		m[3][1] = -eye.InnerProduct(u);	m[3][2] = -eye.InnerProduct(e);		m[3][3] = 1.0f;

	return * this;
}
/**========================================================*/
/**
 *	@brief	座標変換
 *	@param[in]	３次元ベクトル
 *	@return	変換した座標
 */
/**========================================================*/
Vector3 Matrix4::transForm(const Vector3& v)const{
	float x	= v.x_	*	 m[0][0] + v.y_ * m[1][0] + v.z_ * m[2][0] + m[3][0];
	float y	= v.x_	*	 m[0][1] + v.y_ * m[1][1] + v.z_ * m[2][1] + m[3][1];
	float z	= v.x_	*	 m[0][2] + v.y_ * m[1][2] + v.z_ * m[2][2] + m[3][2];
	float w	= v.x_	*	 m[0][3] + v.y_ * m[1][3] + v.z_ * m[2][3] + m[3][3];

	return	Vector3( x / w, y / w, z / w );
}

/**========================================================*/
/**
 *	@brief	<要約>
 *	@param[in]	<引数>
 *	@attention	<注意書き>
 *	@note	<メモ書き>
 *	@author	KORYUOH
 *	@return	<戻り値>
 */
/**========================================================*/
Vector3 Matrix4::transformNomal(const Vector3& v)const{
	float x = v.x_ * m[0][0] + v.y_ * m[1][0] + v.z_ * m[2][0];
	float y = v.x_ * m[0][1] + v.y_ * m[1][1] + v.z_ * m[2][1];
	float z = v.x_ * m[0][2] + v.y_ * m[1][2] + v.z_ * m[2][2];

	return	Vector3( x, y, z );

}

/**========================================================*/
/**
 *	@brief	代入演算子オーバーロード
 *	@param[in]	他
 *	@return	自身
 */
/**========================================================*/
Matrix4& Matrix4::operator *= ( const Matrix4& other )
{
	Matrix4	temp;

	for ( int i = 0; i < 4; i++ ) {
		for ( int j = 0; j < 4; j++ ) {
			temp.m[i][j] = 0;
			for ( int k = 0; k < 4; k++ ) {
				 temp.m[i][j] += m[i][k] * other.m[k][j];
			}
		}
	}
	*this = temp;

	return	*this;
}

/**========================================================*/
/**
 *	@brief	２項演算子オーバーロード
 *	@param[in]	マトリックス
 *	@param[in]	マトリックス
 *	@return	自身
 */
/**========================================================*/
const Matrix4 operator * ( const Matrix4& m1, const Matrix4& m2 )
{
	Matrix4	temp(m1);

	return	temp *= m2;
}
/**========================================================*/
/**
 *	@brief	２項演算子オーバーロード
 *	@param[in]	ベクトル
 *	@param[in]	マトリックス
 *	@return	自身
 */
/**========================================================*/

const Vector3 operator * ( const Vector3& v, const Matrix4& m )
{
	return	m.transForm( v );
}



/**===End Of File==========================================*/