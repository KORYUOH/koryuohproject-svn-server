/******************************************************************************
* File Name : Animation.h                        Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�A�j���[�V�����N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _ANIMATION_H_
#define _ANIMATION_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

//�A�z�z��̓ǂݍ���
#include<map>
//������̓ǂݍ���
#include<string>
#include<gslib.h>
#include"AnimationTimer.h"

/*---- ��s�錾 -------------------------------------------------------------*/

enum TextureID;


/// <summary>
/// �A�j���[�V�����N���X.
/// </summary>
class Animation
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="id">�A�j���[�V����������e�N�X�`��ID</param>
	Animation( TextureID id );
	/// <summary>
	/// ������.
	/// </summary>
	void Initialize();
	/// <summary>
	/// �e�N�X�`��ID�̐ݒ�.
	/// </summary>
	/// <param name="id">�A�j���[�V����������e�N�X�`��ID</param>
	void SetTextureID( TextureID id );
	/// <summary>
	/// �X�V.
	/// </summary>
	/// <param name="frameTimer">�t���[�����[�g</param>
	/// <param name="initial">�A�j���[�V����������\��������</param>
	void Update( float frameTimer, std::string initial );
	/// <summary>
	/// �A�j���[�V�����摜�̐؂�o�����(�Z�`)��o�^.
	/// </summary>
	/// <param name="initial">�A�j���[�V����������\��������</param>
	/// <param name="line">���s�ڂ̉摜</param>
	/// <param name="peace">���摜����</param>
	/// <param name="width">1���摜������̉���</param>
	/// <param name="height">1���摜������̏c��</param>
	void AddCell( std::string initial, int line, int peace, int width, int height );
	/// <summary>
	/// �Z���L�[���쐬�u��:D0,D1....�v.
	/// </summary>
	/// <param name="initial">�ǉ����铪����</param>
	/// <param name="number">�Z���̗�ԍ�</param>
	void CreateCurrentCellCell( std::string initial, int number );
	/// <summary>
	/// ���Z�b�g.
	/// </summary>
	/// <param name="centor">���������铪����</param>
	void Reset( std::string initial );
	/// <summary>
	/// �`��.
	/// </summary>
	/// <param name="position">�`��ʒu</param>
	/// <param name="centor">�摜�̒��S</param>
	void Draw( const GSvector2& position, const GSvector2& centor = GSvector2(0.0f,0.0f) ) const;
	/// <summary>
	/// �`��.
	/// </summary>
	/// <param name="position">�`��ʒu</param>
	/// <param name="centor">�摜�̒��S</param>
	/// <param name="rotate">��]��</param>
	void Draw( const GSvector2& position, const GSvector2& centor, float rotate ) const;
	/// <summary>
	/// �A�j���[�V�����_�ŏ���.
	/// </summary>
	/// <param name="position">�`��ʒu</param>
	/// <param name="centor">�摜�̒��S</param>
	void DrawBlink( const GSvector2& position, const GSvector2& centor = GSvector2(0.0f,0.0f) ) const;
	/// <summary>
	/// �A�j���[�V�����_�ŏ���.
	/// </summary>
	/// <param name="position">�`��ʒu</param>
	/// <param name="centor">�摜�̒��S</param>
	/// <param name="rotate">��]��</param>
	void DrawBlink( const GSvector2& position, const GSvector2& centor, float rotate ) const;

	/// <summary>
	/// �_�Ńt���O�X�V.
	/// </summary>
	void BlinkUpdate();

private:
	/// <summary>
	/// �A�j���[�V�����摜�̏W�܂�.
	/// </summary>
	std::map<std::string,GSrect>	mCells;
	/// <summary>
	/// ���݂̃Z�����.
	/// </summary>
	std::string						mCurrentCell;
	/// <summary>
	/// �O��̃Z�����.
	/// </summary>
	std::string						mPreviousCell;
	/// <summary>
	/// �\������Z���̗�ԍ�.
	/// </summary>
	int								mCellNo;
	/// <summary>
	/// �A�j���[�V�����^�C�}�[�I�u�W�F�N�g.
	/// </summary>
	AnimationTimer					mAnimationTimer;
	/// <summary>
	/// �\������A�j���[�V�����摜�̃e�N�X�`��ID.
	/// </summary>
	TextureID						mID;
	/// <summary>
	/// �_�ŗp�t���O.
	/// </summary>
	bool							mIsBlink;


}; // Animation end

#endif // _ANIMATION_H_ end

/********** End of File ******************************************************/
