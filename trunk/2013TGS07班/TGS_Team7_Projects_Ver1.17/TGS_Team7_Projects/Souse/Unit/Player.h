/******************************************************************************
* File Name : Player.h                            Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�F�����ۃN���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_PLAYER_H_
#define _UNIT_PLAYER_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include"Unit.h"
#include"../Draw/TextureNumber.h"

/*---- ��s�錾 -------------------------------------------------------------*/

/// <summary>���[���h���ۃN���X.</summary>
class IWorld;


/// <summary>
/// �v���C���[�N���X.
/// </summary>
class Player : public Unit
{

public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="world">���[���h</param>
	/// <param name="flag">�t���O�Ǘ���</param>
	///	 <param name="position">�������W</param>
	Player( IWorld& world, IFlagManager& flag, const GSvector2& position );


public:
	/// <summary>
	/// �X�V.
	/// </summary>
	/// <param name="frameTimer">�t���[���^�C�}�[</param>
	virtual void Update( float frameTimer );
	/// <summary>
	/// ���Y����.
	/// </summary>
	/// <param name="frameTimer">�t���[���^�C�}�[</param>
	virtual void Production( float frameTimer ){ (void)frameTimer; }
	/// <summary>
	/// �ێ��R�X�g�x��������.
	/// </summary>
	/// <param name="frameTimer">�t���[���^�C�}�[</param>
	virtual void Maintenance( float frameTimer ){ (void)frameTimer; }
	/// <summary>
	/// �`��.
	/// </summary>
	virtual void Draw() {};
	/// <summary>
	/// UI�̕`��.
	/// </summary>
	virtual void DrawUI();
public:
	/// <summary>
	/// �Փ˂����u�Ԃ̏���.
	/// </summary>
	/// <param name="other">���胆�j�b�g</param>
	virtual void OnCollideEnter( Unit& other );
	/// <summary>
	/// �Փ˂��Ă���Ԃ̏���.
	/// </summary>
	/// <param name="other">���胆�j�b�g</param>
	virtual void OnCollideStay( Unit& other );
	/// <summary>
	/// �Փ˂����I�u�W�F�N�g�����ꂽ���̏���.
	/// </summary>
	/// <param name="other">���胆�j�b�g</param>
	virtual void OnCollideExit( Unit& other );

private:
	/// <summary>
	/// GUI����.
	/// </summary>
	void GUIOperation();
	/// <summary>
	/// GUI�̑I������.
	/// </summary>
	void GUIDeselect();
	/// <summary>
	/// �Ώۂ̃��x�����グ��.
	/// </summary>
	void GUILevelUp();
	/// <summary>
	/// ���݂̑I�������邩����.
	/// </summary>
	/// <returns>�I�������鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
	bool IsSelectUnit() const;
	/// <summary>
	/// �l�ނ̈ړ�.
	/// </summary>
	/// <param name="target">�ڕW���j�b�g</param>
	void PersonnelChange( Unit& target );
	/// <summary>
	/// �E�C���h�E�����.
	/// </summary>
	void WindowClose();


private:

	/// <summary>
	/// �I�𒆂̃��j�b�g.
	/// </summary>
	Unit*			mSelectUnit;
	/// <summary>
	/// �����`��p�I�u�W�F�N�g.
	/// </summary>
	TextureNumber	mNumber;


}; // class Player end

#endif // _UNIT_PLAYER_H_ end

/********** End of File ******************************************************/
