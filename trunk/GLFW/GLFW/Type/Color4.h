/******************************************************************************
* File Name : Color4.h                           Ver : 1.00  Date : 2005-04-27
*
* Description :
*
*       ＲＧＢＡカラー ヘッダファイル．
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_COLOR4_H_
#define		_COLOR4_H_

struct Color4
{
	float		r;					// ｒ成分
	float		g;					// ｇ成分
	float		b;					// ｂ成分
	float		a;					// ａ成分

	// コンストラクタ
	Color4();
	Color4( float R, float G, float B, float A );

	// メンバ関数
	Color4& saturate();				// 0.0～1.0の範囲にクランプ

	// 単項演算子オーバーロード
	Color4  operator + () const;
	Color4  operator - () const;	// 補色を求める

	// 代入演算子オーバーロード
	Color4&  operator += ( const Color4& c2 );
	Color4&  operator -= ( const Color4& c2 );
	Color4&  operator *= ( const Color4& c2 );
	Color4&  operator /= ( const Color4& c2 );
	Color4&  operator *= ( float s );
	Color4&  operator /= ( float s );

};

// ２項演算子オーバーロード
const Color4 operator + ( const Color4& c1, const Color4& c2 );
const Color4 operator - ( const Color4& c1, const Color4& c2 );
const Color4 operator * ( const Color4& c1, const Color4& c2 );
const Color4 operator * ( float s, const Color4& c );
const Color4 operator * ( const Color4& c, float s );
const Color4 operator / ( const Color4& c, float s );

#endif

/********** End of File ******************************************************/
