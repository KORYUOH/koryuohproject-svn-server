/******************************************************************************
* File Name : Camera.cpp                           Ver : 1.00  Date : 2013-02-11
*
* Description :
*
*		カメラクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include	"Camera.h"


/// <summary>
/// コンストラクタ.
/// </summary>

Camera::Camera():
	mEye(0.0f,0.0,0.0),
	mPosition(0.0f,0.0f,30.0f),
	mNear( 0.0f ),
	mFar( 0.0f )
{
	// 初期化する.
	Initialize();
}
/// <summary>
/// デストラクタ.
/// </summary>
Camera::~Camera()
{
}

/// <summary>
/// カメラの初期化.
/// </summary>
void Camera::Initialize()
{
}

/// <summary>
/// カメラの位置を設定.
/// </summary>
/// <param name="x">X座標</param>
/// <param name="y">Y座標</param>
/// <param name="z">Z座標</param>
void Camera::SetPosition( float x, float y, float z )
{
	mPosition.x = x;
	mPosition.y = y;
	mPosition.z = z;
}

/// <summary>
/// 方向を設定.
/// </summary>
/// <param name="position">位置</param>
void Camera::SetPosition( const GSvector3& position )
{
	mPosition = position;
}

/// <summary>
/// カメラの注視点を設定.
/// </summary>
/// <param name="x">X座標</param>
/// <param name="y">Y座標</param>
/// <param name="z">Z座標</param>
void Camera::SetEye( float x, float y, float z )
{
	mEye.x = x;
	mEye.y = y;
	mEye.z = z;
}

/// <summary>
/// カメラの注視点を設定.
/// </summary>
/// <param name="position">位置</param>
void Camera::SetEye( const GSvector3& eye )
{
	mEye = eye;
}

/// <summary>
/// カメラのズーム.
/// </summary>
/// <param name="fov">フォー</param>
/// <param name="aspect">アスペクト</param>
void Camera::Zoom( float fov, float aspect )
{
}


/// <summary>
/// 視点の設定.
/// </summary>
void Camera::LookAt()
{
	// 視点の設定をする.
	glMatrixMode( GL_MODELVIEW );

	// 現在の設定を単位行列に設定.
	glLoadIdentity();

	// 視野角を設定.
	gluLookAt(
		mPosition.x,mPosition.y,mPosition.z,
		mEye.x , mEye.y ,mEye.z,
		0.0f,1.0f,0.0f
		);
}

/********** End of File ******************************************************/
