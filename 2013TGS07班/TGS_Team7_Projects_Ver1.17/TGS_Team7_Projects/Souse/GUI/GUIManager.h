/******************************************************************************
* File Name : GUIManager.h                        Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		���[�U�[�C���^�[�t�F�[�X�Ǘ��҃N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_MANAGER_H_
#define _GUI_MANAGER_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include"GUICommand.h"
#include"GUIFramePtr.h"
#include<list>
#include<memory>

/*---- ��s�錾 -------------------------------------------------------------*/


/// <summary>
/// ���[�U�[�C���^�[�t�F�[�X�Ǘ��҃N���X�D
/// </summary>
class GUIManager
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	GUIManager();
	/// <summary>
	/// GUI��ǉ�����.
	/// </summary>
	/// <param name="gui">�ǉ�����GUI</param>
	void Add( GUIFramePtr gui );
	/// <summary>
	/// �v���C���[GUI��ǉ�����.
	/// </summary>
	/// <param name="gui">�ǉ�����GUI</param>
	void AddPlayer( GUIFramePtr gui );
	/// <summary>
	/// UI���폜����.
	/// </summary>
	/// <param name="addUI">�폜����UI</param>
	void Delete( GUIFramePtr gui );
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
	/// <returns>�R�}���h��Ԃ�.</returns>
	GUICommand	GetCommand() const;
	/// <summary>
	/// �Փ˔���.
	/// </summary>
	/// <param name="other">�Փˏ��</param>
	void Collision( GUIFramePtr other );
	/// <summary>
	/// ����.
	/// </summary>
	void Clear();
private:
	/// <summary>
	/// �Փ˂��s��GUI�R���e�i.
	/// </summary>
	GUIFrameContainer	mGUIColliderContainer;
	/// <summary>
	/// �`��̂ݍs��GUI�R���e�i.
	/// </summary>
	GUIFrameContainer	mGUIContainer;
	/// <summary>
	/// �v���C���[��GUI.
	/// </summary>
	GUIFramePtr			mPlayerGUI;

};

#endif // GUIManager end

/********** End of File ******************************************************/
