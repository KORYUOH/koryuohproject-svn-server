/******************************************************************************
* File Name : GUINumber.h                         Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		���[�U�[�C���^�[�t�F�[�X�t���[���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_NUMBER_H_
#define _GUI_NUMBER_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<list>
#include"GUI.h"
#include"../Draw/TextureNumber.h"

/*---- ��s�錾 -------------------------------------------------------------*/

class IFlagManager;


/// <summary>
/// UI�t���[���N���X.
/// </summary>
class GUINumber : public GUI
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="collider">�Փˏ��</param>
	/// <param name="flagManager">�t���O�Ǘ���</param>
		/// <param name="drawNumber">�`�悷�鐔���ւ̃p�X</param>
	GUINumber( Collider& collider, IFlagManager& flagManager, float* drawNumber  );
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
	/// </summary>
	/// �`�悷�鐔��.
	/// </summary>
	float*			mNumber;
	/// <summary>
	/// �����`��p�I�u�W�F�N�g.
	/// </summary>
	TextureNumber	mDrawNumber;

}; // class Button end


#endif // _GUI_NUMBER_H_ end

/********** End of File ******************************************************/
