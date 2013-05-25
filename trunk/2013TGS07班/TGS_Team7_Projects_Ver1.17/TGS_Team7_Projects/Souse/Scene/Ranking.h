/******************************************************************************
* File Name : Ranking.h                         Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�����L���O�V�[���D
*
******************************************************************************/
#ifndef _RANKING_H_
#define _RANKING_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include	"../Scene\IScene.h"

/*---- ��s�錾 -------------------------------------------------------------*/

class World;
enum Scene;

/// <summary>
/// �����L���O�V�[��.
/// </summary>
class Ranking : public IScene
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	Ranking();
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

};

#endif

/********** End of File ******************************************************/
