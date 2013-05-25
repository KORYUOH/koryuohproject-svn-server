/******************************************************************************
* File Name : Camera.cpp                           Ver : 1.00  Date : 2013-02-11
*
* Description :
*
*		�J�����N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include	"Camera.h"


/// <summary>
/// �R���X�g���N�^.
/// </summary>

Camera::Camera():
	mEye(0.0f,0.0,0.0),
	mPosition(0.0f,0.0f,30.0f),
	mNear( 0.0f ),
	mFar( 0.0f )
{
	// ����������.
	Initialize();
}
/// <summary>
/// �f�X�g���N�^.
/// </summary>
Camera::~Camera()
{
}

/// <summary>
/// �J�����̏�����.
/// </summary>
void Camera::Initialize()
{
}

/// <summary>
/// �J�����̈ʒu��ݒ�.
/// </summary>
/// <param name="x">X���W</param>
/// <param name="y">Y���W</param>
/// <param name="z">Z���W</param>
void Camera::SetPosition( float x, float y, float z )
{
	mPosition.x = x;
	mPosition.y = y;
	mPosition.z = z;
}

/// <summary>
/// ������ݒ�.
/// </summary>
/// <param name="position">�ʒu</param>
void Camera::SetPosition( const GSvector3& position )
{
	mPosition = position;
}

/// <summary>
/// �J�����̒����_��ݒ�.
/// </summary>
/// <param name="x">X���W</param>
/// <param name="y">Y���W</param>
/// <param name="z">Z���W</param>
void Camera::SetEye( float x, float y, float z )
{
	mEye.x = x;
	mEye.y = y;
	mEye.z = z;
}

/// <summary>
/// �J�����̒����_��ݒ�.
/// </summary>
/// <param name="position">�ʒu</param>
void Camera::SetEye( const GSvector3& eye )
{
	mEye = eye;
}

/// <summary>
/// �J�����̃Y�[��.
/// </summary>
/// <param name="fov">�t�H�[</param>
/// <param name="aspect">�A�X�y�N�g</param>
void Camera::Zoom( float fov, float aspect )
{
}


/// <summary>
/// ���_�̐ݒ�.
/// </summary>
void Camera::LookAt()
{
	// ���_�̐ݒ������.
	glMatrixMode( GL_MODELVIEW );

	// ���݂̐ݒ��P�ʍs��ɐݒ�.
	glLoadIdentity();

	// ����p��ݒ�.
	gluLookAt(
		mPosition.x,mPosition.y,mPosition.z,
		mEye.x , mEye.y ,mEye.z,
		0.0f,1.0f,0.0f
		);
}

/********** End of File ******************************************************/
