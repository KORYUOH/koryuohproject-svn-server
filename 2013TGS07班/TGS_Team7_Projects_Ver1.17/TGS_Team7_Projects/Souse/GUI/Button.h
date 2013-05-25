/******************************************************************************
* File Name : Button.h                           Ver : 1.00  Date : 2013-04-25
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
/// UI�t���[���N���X.
/// </summary>
class Button : public GUI
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="collider">�Փˏ��</param>
	/// <param name="flag">�t���O�Ǘ���.</param>
	/// <param name="flagID">�t���OID.</param>
	/// <param name="textureID">�e�N�X�`��ID.</param>
	Button( Collider& collider, IFlagManager& flag, FlagID flagID, TextureID textureID );
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
	Animation		mAnimation;

}; // class Button end


#endif // _GUI_BOTTON_H_ end

/********** End of File ******************************************************/
