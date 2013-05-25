/******************************************************************************
* File Name : IScene.h                           Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�V�[���C���^�[�t�F�C�X�N���X�D
*
******************************************************************************/
#ifndef		_ISCENE_H_
#define		_ISCENE_H_


/*---- ��s�錾 -------------------------------------------------------------*/

enum Scene;
class World;


/// <summary>
/// �V�[���C���^�[�t�F�C�X.
/// </summary>
class IScene
{
public:
	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	virtual ~IScene() {}
	/// <summary>
	/// ������.
	/// </summary>
	virtual void Initialize() = 0;
	/// <summary>
	/// �X�V.
	/// </summary>
	/// <param name="frameTimer">�t���[���^�C�}�[</param>
	virtual void Update(float frameTimer) = 0;
	/// <summary>
	/// �`��.
	/// </summary>
	virtual void Draw() = 0;
	/// <summary>
	/// �V�[���̏I������.
	/// </summary>
	virtual bool IsEnd() const = 0;
	/// <summary>
	/// ���̃V�[���Ɉڍs.
	/// </summary>
	virtual Scene Next() const = 0;
	/// <summary>
	/// �I��.
	/// </summary>
	virtual void Shutdown() = 0;

		/// <summary>
	/// �V�[���̏I���t���O.
	/// </summary>
	bool	mIsEnd;


}; // IScene end


#endif // _ISCENE_H_ end

/********** End of File ******************************************************/
