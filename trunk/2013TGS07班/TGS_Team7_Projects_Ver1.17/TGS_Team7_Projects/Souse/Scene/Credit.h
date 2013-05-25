/******************************************************************************
* File Name : Credit.h                           Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�N���W�b�g�V�[���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _CREDIT_H_
#define _CREDIT_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include	"../Scene\IScene.h"

/*---- ��s�錾 -------------------------------------------------------------*/

enum Scene;

/// <summary>
/// �N���W�b�g�V�[���N���X.
/// </summary>
class Credit : public IScene
{
public:
	/// <summary>
	/*�R���X�g���N�^*/
	/// </summary>
	Credit();
	/// <summary>
	/// ������.
	/// </summary>
	virtual void Initialize();
	/// <summary>
	/// �X�V.
	/// </summary>
	/// <param name="frameTimer">�t���[���^�C�}�[</param>
	virtual void Update(float frameTimer);
	/// <summary>
	/// �`��.
	/// </summary>
	virtual void Draw();
	/// <summary>
	/// �V�[���̏I������.
	/// </summary>
	/// <returns>�V�[�����I�����Ă���ΐ^�A���Ă��Ȃ���΋U��Ԃ�</returns>
	virtual bool IsEnd() const;
	/// <summary>
	/// ���̃V�[���Ɉڍs.
	/// </summary>
	/// <returns>���̃V�[���񋓌^��Ԃ�</returns>
	virtual Scene Next() const;
	/// <summary>
	/// �I��.
	/// </summary>
	virtual void Shutdown();

}; // Credit end

#endif

/********** End of File ******************************************************/
