/******************************************************************************
* File Name : GameApplication.h                  Ver : 1.00  Date : 2012-12-13
*
* Description :
*
*		�Q�[���A�v���P�[�V�����w�b�_�t�@�C���D
*
******************************************************************************/
#ifndef	_GAMEAPPLICATION_H_
#define	_GAMEAPPLICATION_H_


/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<string>

/// <summary>
/// �Q�[���A�v���P�[�V�����N���X.
/// </summary>
class GameApplication
{

public:
	/// <summary>
	/// �A�v���P�[�V�����̎��s.
	/// </summary>
	void Run( void );

protected:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="argc">�R�}���h���C���I�v�V�����̐��̃|�C���^</param>
	/// <param name="argv">�R�}���h���C���I�v�V������\��������̔z��</param>
	GameApplication( int argc, char* argv[] );
	/// <summary>
	/// �o�[�`�����f�X�g���N�^.
	/// </summary>
	virtual ~GameApplication( void ) {}
	/// <summary>
	/// ������.
	/// </summary>
	virtual void Initialize( void ) {}
	/// <summary>
	// �X�V.
	/// </summary>
	/// <param name="frameTimer">�t���[���^�C�}�[</param>
	virtual void Update( float frameTimer ) { (void)frameTimer; }
	/// <summary>
	/// �`��.
	/// </summary>
	virtual void Draw( void ) {}
	/// <summary>
	// �I��.
	/// </summary>
	virtual void Finish( void ) {}

public:
	/// <summary>
	/// �E�C���h�E�^�C�g���擾.
	/// </summary>
	/// <returns>�E�C���h�E������</returns>
	const std::string& GetWindowTitle( void ) const;
	/// <summary>
	/// �E�C���h�EX���W���擾.
	/// </summary>
	/// <returns>�E�C���h�E��X���W</returns>
	int GetWindowPositionX( void ) const;
	/// <summary>
	/// �E�C���h�EY���W���擾.
	/// </summary>
	/// <returns>�E�C���h�E��X���W</returns>
	int GetWindowPositionY( void ) const;
	/// <summary>
	/// �E�C���h�E�����擾.
	/// </summary>
	/// <returns>�E�C���h�E��X���W</returns>
	int GetWindowWidth( void ) const;
	/// <summary>
	/// �E�C���h�E�������擾.
	/// </summary>
	/// <returns>�E�C���h�E��X���W</returns>
	int GetWindowHeight( void ) const;
	/// <summary>
	/// ����p���擾.
	/// </summary>
	/// <returns>����p�l</returns>
	float GetPerspectiveFov( void ) const;
	/// <summary>
	/// �߃N���b�v�ʂ��擾.
	/// </summary>
	/// <returns>�߃N���b�v�l</returns>
	float GetPerspectiveNear( void ) const;
	/// <summary>
	/// ���N���b�v�ʂ��擾.
	/// </summary>
	/// <returns>���N���b�v�l</returns>
	float GetPerspectiveFar( void ) const;
	/// <summary>
	/// �E�C���h�E�^�C�g���ݒ�.
	/// </summary>
	/// <param name="title">�E�C���h�E������</param>
	void SetWindowTitle( const std::string& title );
	/// <summary>
	/// �E�C���h�EX���W��ݒ�.
	/// </summary>
	/// <param name="x">X���W</param>
	void SetWindowPositionX( int x );
	/// <summary>
	/// �E�C���h�EY���W��ݒ�.
	/// </summary>
	/// <param name="y">Y���W</param>
	void SetWindowPositionY( int y );
	/// <summary>
	/// �E�C���h�E�����ݒ�.
	/// </summary>
	/// <param name="width">����</param>
	void SetWindowWidth( int width );
	/// <summary>
	/// �E�C���h�E�c���ݒ�.
	/// </summary>
	/// <param name="height">�c��</param>
	void SetWindowHeight( int height );
	/// <summary>
	/// ����p�ݒ�.
	/// </summary>
	/// <param name="fov">����p�l</param>
	void SetPerspectiveFov( float fov );
	/// <summary>
	/// �߃N���b�v�ʂ�ݒ�.
	/// </summary>
	/// <param name="znear">�߃N���b�v�l</param>
	void SetPerspectiveNear( float znear );
	/// <summary>
	/// ���N���b�v�ʂ�ݒ�.
	/// </summary>
	/// <param name="zfar">���N���b�v�l</param>
	void SetPerspectiveFar( float zfar );
	/// <summary>
	/// �t���X�N���[�����[�h�ݒ�.
	/// </summary>
	/// <param name="mode">���[�h</param>
	void SetFullScreenMode( bool mode );
	/// <summary>
	/// �t���X�N���[�����[�h�����ׂ�.
	/// </summary>
	/// <returns>�t���X�N���[���̎��^�A�����łȂ����U��Ԃ�.</returns>
	bool IsFullScreenMode( void );

private:
	/// <summary>
	/// OpenGL�̏�����.
	/// </summary>
	void InitilaizeGL( void );
	/// <summary>
	/// �_�u���o�b�t�@�ؑ֎��̃C���^�[�o���^�C�}�̐ݒ�.
	/// </summary>
	/// <param name="interval">�C���^�[�o��</param>
	void SetSwapInterval( int interval );
	/// <summary>
	/// �E�C���h�E���A�N�e�B�u���̃R�[���o�b�N�֐�.
	/// </summary>
	static void Activate( int state );
	/// <summary>
	/// �E�C���h�E�`�掞�̃R�[���o�b�N�֐�.
	/// </summary>
	static void Display( void );
	/// <summary>
	//�C�x���g�������̃R�[���o�b�N�֐�.
	/// </summary>
	static void Idle( void );
	/// <summary>
	//�E�C���h�E�T�C�Y�R�[���o�b�N�֐�.
	/// </summary>
	/// <param name="width">�c��</param>
	/// <param name="height">����</param>
	static void Reshape( int width, int height );
	/// <summary>
	//�A�v���P�[�V�����I�����R�[���o�b�N�֐�.
	/// </summary>
	static void Destroy( void );


#pragma region �t�B�[���h�ϐ�

private:
	/// <summary>
	/// �E�C���h�E�^�C�g��.
	/// </summary>
	std::string				mWindowTitle;
	/// <summary>
	///	�E�C���h�E��X���W.
	/// </summary>
	int						mWindowPositionX;
	/// <summary>
	/// �E�C���h�E��Y���W.
	/// </summary>
	int						mWindowPositionY;
	/// <summary>
	///	�E�C���h�E�̉���.
	/// </summary>
	int						mWindowWidth;
	/// <summary>
	/// �E�C���h�E�̏c��.
	/// </summary>
	int						mWindowHeight;
	/// <summary>
	///	�t���X�N���[�����[�h.
	/// </summary>
	bool					mIsFullScreenMode;
	/// <summary>
	/// ����p�l.
	/// </summary>
	float					mPerspectiveFov;
	/// <summary>
	///	�߃N���b�v�l.
	/// </summary>
	float					mPerspectiveNear;
	/// <summary>
	///	���N���b�v�l.
	/// </summary>
	float					mPerspectiveFar;
	/// <summary>
	///	�R�[���o�b�N�֐��̂��߂̐ÓI�����o�ϐ�.
	/// </summary>
	static GameApplication*	mInstance;

#pragma endregion // �t�B�[���h�ϐ� end


}; // class GameApplication end


#endif // !_GAMEAPPLICATION_H_

/********** End of File ******************************************************/
