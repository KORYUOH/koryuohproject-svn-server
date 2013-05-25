/******************************************************************************
* File Name : GUIFrame.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		���[�U�[�C���^�[�t�F�[�X�t���[���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_FRAME_H_
#define _GUI_FRAME_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include"GUIPtr.h"
#include"../Collider/Collider.h"
#include"../Flag/IFlagManager.h"
#include<memory>

/*---- ��s�錾 -------------------------------------------------------------*/


/// <summary>
/// UI�t���[���N���X.
/// </summary>
class GUIFrame
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	GUIFrame();
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="position">�t���[���̒������W</param>
	/// <param name="angle">�p�x</param>
	GUIFrame( const GSvector2& position, float angle );
	/// <summary>
	/// UI��ǉ�����.
	/// </summary>
	/// <param name="addUI">�ǉ�����UI</param>
	void AddGUI( GUIPtr addUI );
	/// <summary>
	/// �E�C���h�E��ǉ�����.
	/// </summary>
	/// <param name="frameTimer">�t���O�Ǘ���</param>
	void AddWindow( IFlagManager& flagManager );
	/// <summary>
	/// �X�V.
	/// </summary>
	/// <param name="frameTimer">�t���[�����[�g</param>
	void Update( float frameTimer );
	/// <summary>
	/// �`��.
	/// </summary>
	void Draw() const;
	/// <summary>
	/// �R�}���h���擾.
	/// </summary>
	void RangeExpansion( Collider& collider );
	/// <summary>
	/// �Փ˂̍X�V.
	/// </summary>
	/// <param name="other">�Փˑ���GUI</param>
	void CollisionUpdate( GUIFrame& other );
	/// <summary>
	/// �Փ˂̍X�V.
	/// </summary>
	/// <param name="other">�Փˏ��</param>
	void CollisionUpdate( GUI& other );
	/// <summary>
	/// �t���O�̖�����.
	/// </summary>
	void FlagDisable();

private:
	/// <summary>
	/// GUI�R���e�i.
	/// </summary>
	GUIContainer	mGUIs;
	/// <summary>
	/// �t���[���̈ʒu.
	/// </summary>
	GSvector2		mPosition;
	/// <summary>
	/// �p�x.
	/// </summary>
	float			mAngle;
	/// <summary>
	/// GUI�͈̔�.
	/// </summary>
	GSrect			mRange;
	/// <summary>
	/// �E�C���h�E�t���O.
	/// </summary>
	bool			mIsWindow;
};

#endif // _GUI_FRAME_H_ end

/********** End of File ******************************************************/
