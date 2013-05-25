/******************************************************************************
* File Name : GUILevel.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		���[�U�[�C���^�[�t�F�[�X�t���[���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_LEVEL_H_
#define _GUI_LEVEL_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<list>
#include"GUI.h"
#include"../Draw/Animation.h"

/*---- ��s�錾 -------------------------------------------------------------*/

class IFlagManager;

/// <summary>
/// �J�[�\��GUI.
/// </summary>
class GUILevel : public GUI
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="collider">�Փˏ��</param>
	/// <param name="flagManager">�t���O�Ǘ���</param>
	/// <param name="level">���x���ւ̃p�X</param>
	/// <param name="angle">�p�x</param>
	GUILevel( Collider& collider, IFlagManager& flagManager, int* level, float angle );
	/// <summary>
	/// �X�V.
	/// </summary>
	/// <param name="frameTimer">�t���[�����[�g</param>
	virtual void Update( float frameTimer );
	/// <summary>
	/// �`��.
	/// </summary>
	/// <param name="position">�t���[���̈ʒu</param>
	/// <param name="angle">�p�x</param>
	virtual void Draw( const GSvector2& position, float angle ) const;
private:
	/// <summary>
	/// ���x���ւ̃p�X.
	/// </summary>
	int*		mLevel;
	/// <summary>
	/// �p�x.
	/// </summary>
	float		mAngle;


}; // class Button end


#endif // CursorGUI end

/********** End of File ******************************************************/
