/******************************************************************************
* File Name : Cursor.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		���[�U�[�C���^�[�t�F�[�X�t���[���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_BOTTON_H_
#define _GUI_BOTTON_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<list>
#include"GUI.h"
#include"../Draw/Animation.h"

/*---- ��s�錾 -------------------------------------------------------------*/


/// <summary>
/// �J�[�\��GUI.
/// </summary>
class CursorGUI : public GUI
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="collider">�Փˏ��</param>
	/// <param name="flagManager">�t���O�Ǘ���</param>
	/// <param name="position">�ʒu���</param>
	CursorGUI( Collider& collider, IFlagManager& flagManager, const GSvector2* position );
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
	/// �A�j���[�V����.
	/// </summary>
	Animation			mAnimation;
	/// <summary>
	/// �A�j���[�V����.
	/// </summary>
	const GSvector2*	mPosition;


}; // class Button end


#endif // CursorGUI end

/********** End of File ******************************************************/
