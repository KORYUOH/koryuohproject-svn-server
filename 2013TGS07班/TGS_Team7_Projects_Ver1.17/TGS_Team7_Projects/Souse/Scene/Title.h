/******************************************************************************
* File Name : Title.h                           Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�^�C�g���V�[���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _TITLE_H_
#define _TITLE_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include	"../Scene\IScene.h"
#include	"../World/World.h"

/*---- ��s�錾 -------------------------------------------------------------*/

class World;
enum Scene;

/// <summary>
/// �Q�[���v���C�V�[���N���X.
/// </summary>
class Title : public IScene
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	Title();
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


}; // class Title end

#endif

/********** End of File ******************************************************/
