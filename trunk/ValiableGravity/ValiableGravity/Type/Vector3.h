/******************************************************************************
* File Name : Vector3.h                          Ver : 1.00  Date : 2005-04-27
*
* Description :
*
*       ３Ｄベクトル計算 ヘッダファイル．
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_Vector3_H_
#define		_Vector3_H_

struct Vector3
{
	float		x;								// x成分
	float		y;								// y成分
	float		z;								// z成分

	// コンストラクタ
	Vector3();
	Vector3( float X, float Y, float Z );

	// メンバ関数
	float    length() const;					// ノルムを求める
	Vector3& normalize();						// 正規化する
	float    dot( const Vector3& v ) const; 	// 内積を求める
	Vector3  cross( const Vector3& v ) const;	// 外積を求める

	// 単項演算子オーバーロード
	Vector3  operator + () const;
	Vector3  operator - () const;

	// 代入演算子オーバーロード
	Vector3&  operator += ( const Vector3& v );
	Vector3&  operator -= ( const Vector3& v );
	Vector3&  operator *= ( float s );
	Vector3&  operator /= ( float s );
};

// ２項演算子オーバーロード
const Vector3 operator + ( const Vector3& v1, const Vector3& v2 );
const Vector3 operator - ( const Vector3& v1, const Vector3& v2 );
const Vector3 operator * ( const Vector3& v, float s );
const Vector3 operator * ( float s, const Vector3& v );
const Vector3 operator / ( const Vector3& v, float s );

#endif

/********** End of File ******************************************************/
