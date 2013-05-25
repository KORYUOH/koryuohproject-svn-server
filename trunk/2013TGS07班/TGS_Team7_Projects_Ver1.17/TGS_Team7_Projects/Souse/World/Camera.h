/******************************************************************************
* File Name : Camera.h                           Ver : 1.00  Date : 2013-02-11
*
* Description :
*
*		カメラクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef		_CAMERA_H_
#define		_CAMERA_H_

#include	<gslib.h>

/// <summary>
/// カメラクラス.
/// </summary>
class Camera
{

public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	Camera();
	/// <summary>
	/// デストラクタ.
	/// </summary>
	~Camera();


public:
	/// <summary>
	/// カメラの初期化.
	/// </summary>
	void Initialize();

	/// <summary>
	/// カメラの位置を設定.
	/// </summary>
	/// <param name="x">X座標</param>
	/// <param name="y">Y座標</param>
	/// <param name="z">Z座標</param>
	void SetPosition( float x, float y, float z );
	/// <summary>
	/// カメラの位置を設定.
	/// </summary>
	/// <param name="position">位置</param>
	void SetPosition( const GSvector3& position );
	/// <summary>
	/// カメラの注視点を設定.
	/// </summary>
	/// <param name="x">X座標</param>
	/// <param name="y">Y座標</param>
	/// <param name="z">Z座標</param>
	void SetEye( float x, float y, float z );
	/// <summary>
	/// カメラの注視点を設定.
	/// </summary>
	/// <param name="position">位置</param>
	void SetEye( const GSvector3& eye );
	/// <summary>
	/// カメラのズーム.
	/// </summary>
	/// <param name="fov">フォー</param>
	/// <param name="aspect">アスペクト</param>
	void Zoom( float fov, float aspect );
	/// <summary>
	/// 視点の設定.
	/// </summary>
	void LookAt();

#pragma region アクセスの禁止

private:
	/// <summary>
	/// コピーコンストラクタ(外部から禁止).
	/// </summary>
	Camera( const Camera& camera );
	/// <summary>
	/// 代入演算子オーバロード禁止.
	/// </summary>
	Camera& operator = ( const Camera& camera );

#pragma endregion


private:
	///// <summary>
	///// ビューマトリクス.
	///// </summary>
	//GSmatrix3		m_view_mat;
	///// <summary>
	///// 射影マトリクス.
	///// </summary>
	//D3DXMATRIX		m_proj_mat;	
	///// <summary>
	///// ビューポート.
	///// </summary>
	//D3DVIEWPORT9	m_view_port;	// ビューポート
	/// <summary>
	// 注視点.
	/// </summary>
	GSvector3	mEye;			
	/// <summary>
	/// カメラの位置.
	/// </summary>
	GSvector3	mPosition;
	/// <summary>
	/// 揺れの位置.
	/// </summary>
	GSvector3	mShakePosition;
	/// <summary>
	///	近クリップ値.
	/// </summary>
	float		mNear;
	/// <summary>
	///	遠クリップ値.
	/// </summary>
	float		mFar;
	//float			m_zoom;			// ズーム
	//int			m_shake_time;	// シェイク時間

};

#endif // !_CAMERA_H_

/********** End of File ******************************************************/
