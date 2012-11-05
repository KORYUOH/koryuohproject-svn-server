/**===File Commentary=======================================*/
/**
 *	@file	Matrix4.h
 *
 *	@brief	4行4列の行列
 *
 *	@author	KORYUOH
 *
 *	@date	2012/07/03
 */
/**===Include Guard========================================*/
#ifndef	_MATRIX4_H_
#define	_MATRIX4_H_
/**===File Include=========================================*/
struct Vector3;
/**===Class Definition=====================================*/
struct Matrix4{
	//行列成分
	float m[4][4];
	/**
	 *	@brief	コンストラクタ
	 */
	Matrix4();
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
	Matrix4(	float m11,	float m12,	float m13,	float m14,
					float m21,	float m22,	float m23,	float m24,
					float m31,	float m32,	float m33,	float m34,
					float m41,	float m42,	float m43,	float m44
					);
	/**
	 *	@brief	単位行列の設定
	 *	@return	単位行列
	 */
	Matrix4& setIdentity();
	/**
	 *	@brief	拡縮の設定
	 *	 @param[in]	拡大縮小率
	 *	@return	行列
	 */
	Matrix4& setScale(const Vector3& v);
	/**
	 *	@brief	回転行列の設定
	 *	@param[in]	回転角
	 *	@return	行列
	 */
	Matrix4& setRotateX	(float angle);
	/**
	 *	@brief	回転行列の設定
	 *	@param[in]	回転角
	 *	@return	行列
	 */
	Matrix4& setRotateY	(float angle);
	/**
	 *	@brief	回転行列の設定
	 *	@param[in]	回転角
	 *	@return	行列
	 */
	Matrix4& setRotateZ	(float angle);
	
	/**
	 *	@brief	平行移動行列の設定
	 *	@param[in]	平行移動量
	 *	@return	行列
	 */
	Matrix4& setTranslate(const Vector3& v);
	/**
	 *	@brief	透視変換行列の設定
	 *	@param[in]	fov
	  *	@param[in]	アスペクト
	 *	@param[in]	近景
	 *	@param[in]	遠景
	 *	@return	透視変換行列
	 */
	Matrix4& setPerspective(float fov,float aspect,float near, float far);

	/**
	 *	@brief	視野変換行列設定
	 *	@param[in]	視点座標
	 *	@param[in]	注視点座標
	 *	@param[in]	視点の上方向
	 *	@return	視野変換行列
	 */
	Matrix4& setLookAt(const Vector3& eye,const Vector3& at ,const Vector3& up);
	/**
	 *	@brief	座標変換
	 *	@param[in]	ベクトル
	 *	@note	行列とベクトルの掛け算
	 *	@return	ベクトル
	 */
	Vector3 transForm(const Vector3& v)const;
	/**
	 *	@brief	座標変換
	 *	@param[in]	ベクトル
	 *	@note	法線ベクトルの計算
	 *	@return	法線ベクトル
	 */
	Vector3 transformNomal(const Vector3& v)const;
	/**
	 *	@brief	代入演算子オーバーロード
	 *	@param[in]	マトリックス
	 *	@return	自身
	 */
	Matrix4& operator *= (const Matrix4& matrix);
};
/*二項演算子オーバーロード*/
const Matrix4 operator * (const Matrix4& m1 ,const Matrix4& m2);
const Vector3 operator * (const Vector3& v ,	const Matrix4& m);
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/