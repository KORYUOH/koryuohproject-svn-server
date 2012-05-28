/******************************************************************************
* File Name : Matrix4.h                          Ver : 1.00  Date : 2005-04-27
*
* Description :
*
*       三次元座標変換行列計算 ヘッダファイル．
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_MATRIX4_H_
#define		_MATRIX4_H_

struct Vector3;

struct Matrix4
{
	float			m[4][4];			// 行列成分

	// コンストラクタ
	Matrix4();
	Matrix4( float m11, float m12, float m13, float m14,
			 float m21, float m22, float m23, float m24,
			 float m31, float m32, float m33, float m34,
			 float m41, float m42, float m43, float m44 );

	// 単位行列の設定
	Matrix4& setIdentity();

	// 拡大縮小行列の設定
	Matrix4& setScale( const Vector3& v );

	// 回転行列の設定
	Matrix4& setRotateX( float angle );	// x軸周りの回転
	Matrix4& setRotateY( float angle );	// y軸周りの回転
	Matrix4& setRotateZ( float angle );	// z軸周りの回転

	// 平行移動行列の設定
	Matrix4& setTranslate( const Vector3& v );

	// 透視変換行列の設定
	Matrix4& setPerspective( float fov, float aspect, float near, float far );

	// 視野変換行列の設定
	Matrix4& setLookAt( const Vector3& eye, const Vector3& at, const Vector3& up );

	// 座標変換（ベクトルと行列の掛け算をする）
	Vector3 transform( const Vector3& v ) const;

	// 座標変換（法線ベクトル用で回転のみで平行移動はさせない）
	Vector3 transformNormal( const Vector3& v ) const;

	// 代入演算子オーバーロード
	Matrix4& operator *= ( const Matrix4& other );
};

// ２項演算子オーバーロード
const Matrix4 operator * ( const Matrix4& m1, const Matrix4& m2 );
const Vector3 operator * ( const Vector3& v , const Matrix4& m  );

#endif

/********** End of File ******************************************************/
