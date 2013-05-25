/******************************************************************************
* File Name : GamePlay.h                         Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�Q�[���v���C�N���X�D
*
******************************************************************************/
#ifndef _GAMEPLAY_H_
#define _GAMEPLAY_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include"../Scene\IScene.h"
#include"../World/World.h"
#include"../Flag/FlagManager.h"

/*---- ��s�錾 -------------------------------------------------------------*/

class World;
class FlagManager;
enum Scene;


/// <summary>
/// �Q�[���v���C�V�[���N���X.
/// </summary>
class GamePlay : public IScene
{
public:
/// <summary>
/// �R���X�g���N�^.
/// </summary>
	GamePlay();
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


private:
	/// <summary>
	/// ���[���h.
	/// </summary>
	World	mWorld;
	/// <summary>
	/// �t���O�Ǘ���.
	/// </summary>
	FlagManager	mFlagManager;

}; // class GamePlay end


#endif // !_GAMEPLAY_H_

/********** End of File ******************************************************/
