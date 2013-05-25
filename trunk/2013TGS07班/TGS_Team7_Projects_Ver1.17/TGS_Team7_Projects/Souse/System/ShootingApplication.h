/******************************************************************************
* File Name : ShootingApplication.h              Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�Q�[���A�v���P�[�V�����N���X
*
******************************************************************************/
#ifndef _OIKAKEAPPLICATION_H_
#define _OIKAKEAPPLICATION_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include	"GameApplication.h"
#include	"../Scene\SceneManager.h"

/*---- ��s�錾 -------------------------------------------------------------*/


/*---- �N���X�̐錾 ---------------------------------------------------------*/

/// <summary>
/// �V���[�e�B���O�A�v���P�[�V����.
/// </summary>
class ShootingApplication : public GameApplication
{

	//�����o�֐�
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="argc">�R�}���h���C���I�v�V�����̐��̃|�C���^</param>
	/// <param name="argv">�R�}���h���C���I�v�V������\��������̔z��</param>
	ShootingApplication(int argc,char *argv[]); 

public:
	/// <summary>
	/// ������.
	/// </summary>
	virtual void Initialize( void );
	/// <summary>
	// �X�V.
	/// </summary>
	/// <param name="frameTimer">�t���[���^�C�}�[</param>
	virtual void Update( float frameTimer );
	/// <summary>
	/// �`��.
	/// </summary>
	virtual void Draw( void );
	/// <summary>
	// �I��.
	/// </summary>
	virtual void Finish( void );

	//�����o�ϐ�
private:
	/// <summary>
	/// �V�[���Ǘ���.
	/// </summary>
	SceneManager mSceneManager;

};

#endif



/********** End of File ******************************************************/