/******************************************************************************
* File Name : Vector2.h                          Ver : 1.00  Date : 2005-04-27
*
* Description :
*
*       ２Ｄベクトル計算 ヘッダファイル．
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_VECTOR2_H_
#define		_VECTOR2_H_

struct Vector2
{
	float		x;								// x成分
	float		y;								// y成分

	// コンストラクタ
	Vector2();
	Vector2( float X, float Y );

	// メンバ関数
	float    length() const;					// ノルムを求める
	Vector2& normalize();						// 正規化する
	float    dot( const Vector2& v ) const; 	// 内積を求める

	// 単項演算子オーバーロード
	Vector2  operator + () const;
	Vector2  operator - () const;

	// 代入演算子オーバーロード
	Vector2&  operator += ( const Vector2& v );
	Vector2&  operator -= ( const Vector2& v );
	Vector2&  operator *= ( float s );
	Vector2&  operator /= ( float s );
};

// ２項演算子オーバーロード
const Vector2 operator + ( const Vector2& v1, const Vector2& v2 );
const Vector2 operator - ( const Vector2& v1, const Vector2& v2 );
const Vector2 operator * ( const Vector2& v, float s );
const Vector2 operator * ( float s, const Vector2& v );
const Vector2 operator / ( const Vector2& v, float s );

#endif

/********** End of File ******************************************************/
