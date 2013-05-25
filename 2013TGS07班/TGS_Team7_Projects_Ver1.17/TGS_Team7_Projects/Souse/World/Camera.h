/******************************************************************************
* File Name : Camera.h                           Ver : 1.00  Date : 2013-02-11
*
* Description :
*
*		�J�����N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef		_CAMERA_H_
#define		_CAMERA_H_

#include	<gslib.h>

/// <summary>
/// �J�����N���X.
/// </summary>
class Camera
{

public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	Camera();
	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	~Camera();


public:
	/// <summary>
	/// �J�����̏�����.
	/// </summary>
	void Initialize();

	/// <summary>
	/// �J�����̈ʒu��ݒ�.
	/// </summary>
	/// <param name="x">X���W</param>
	/// <param name="y">Y���W</param>
	/// <param name="z">Z���W</param>
	void SetPosition( float x, float y, float z );
	/// <summary>
	/// �J�����̈ʒu��ݒ�.
	/// </summary>
	/// <param name="position">�ʒu</param>
	void SetPosition( const GSvector3& position );
	/// <summary>
	/// �J�����̒����_��ݒ�.
	/// </summary>
	/// <param name="x">X���W</param>
	/// <param name="y">Y���W</param>
	/// <param name="z">Z���W</param>
	void SetEye( float x, float y, float z );
	/// <summary>
	/// �J�����̒����_��ݒ�.
	/// </summary>
	/// <param name="position">�ʒu</param>
	void SetEye( const GSvector3& eye );
	/// <summary>
	/// �J�����̃Y�[��.
	/// </summary>
	/// <param name="fov">�t�H�[</param>
	/// <param name="aspect">�A�X�y�N�g</param>
	void Zoom( float fov, float aspect );
	/// <summary>
	/// ���_�̐ݒ�.
	/// </summary>
	void LookAt();

#pragma region �A�N�Z�X�̋֎~

private:
	/// <summary>
	/// �R�s�[�R���X�g���N�^(�O������֎~).
	/// </summary>
	Camera( const Camera& camera );
	/// <summary>
	/// ������Z�q�I�[�o���[�h�֎~.
	/// </summary>
	Camera& operator = ( const Camera& camera );

#pragma endregion


private:
	///// <summary>
	///// �r���[�}�g���N�X.
	///// </summary>
	//GSmatrix3		m_view_mat;
	///// <summary>
	///// �ˉe�}�g���N�X.
	///// </summary>
	//D3DXMATRIX		m_proj_mat;	
	///// <summary>
	///// �r���[�|�[�g.
	///// </summary>
	//D3DVIEWPORT9	m_view_port;	// �r���[�|�[�g
	/// <summary>
	// �����_.
	/// </summary>
	GSvector3	mEye;			
	/// <summary>
	/// �J�����̈ʒu.
	/// </summary>
	GSvector3	mPosition;
	/// <summary>
	/// �h��̈ʒu.
	/// </summary>
	GSvector3	mShakePosition;
	/// <summary>
	///	�߃N���b�v�l.
	/// </summary>
	float		mNear;
	/// <summary>
	///	���N���b�v�l.
	/// </summary>
	float		mFar;
	//float			m_zoom;			// �Y�[��
	//int			m_shake_time;	// �V�F�C�N����

};

#endif // !_CAMERA_H_

/********** End of File ******************************************************/
