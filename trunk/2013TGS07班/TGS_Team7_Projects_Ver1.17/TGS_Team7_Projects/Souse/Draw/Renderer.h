/******************************************************************************
* File Name : Renderer.h                             Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�`��N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _RENDERER_H_
#define _RENDERER_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include	"IRenderer.h"
#include	"TextureID.h"
#include	<string>

/*---- ��s�錾 -------------------------------------------------------------*/


/// <summary>
/// �`��N���X
/// </summary>
class Renderer : public IRenderer
{
public:
	/// <summary>
	/// ���̂��擾.
	/// <para>�V���O���g��</para>
	/// </summary>
	/// <returns>���̂�Ԃ�.</returns>
	static Renderer* GetInstance();

private:
	/// <summary>
	/// �R���X�g���N�^.
	/// <para>�O���A�N�Z�X�̋֎~.</para>
	/// </summary>
	Renderer(){}
	/// <summary>
	/// �R�s�[�R���X�g���N�^.
	/// <para>�O���A�N�Z�X�̋֎~.</para>
	/// </summary>
	Renderer( const Renderer& other );
	/// <summary>
	/// ������Z�q.
	/// <para>�O���A�N�Z�X�̋֎~.</para>
	/// </summary>
	Renderer& operator =( const Renderer& other );



	//�����o�֐�
public:
	/// <summary>
	/// �摜�̓ǂݍ���.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="name">�`��ʒu</param>
	/// <param name="colorKey">�J���[�L�[.
	/// <para>true�ɐݒ肷��Ɠ��ߏ�����L���ɐݒ�</para></param>
	virtual void LoadTexture( TextureID id,const std::string& name , bool colorKey = false );
	/// <summary>
	/// �e�N�X�`���̍폜.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	virtual void DeleteTexture( TextureID id );

public:
	/// <summary>
	/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID.</param>
	virtual void DrawTexture( TextureID id );
	/// <summary>
	/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�e�N�X�`����`�悷��ꏊ (�X�N���[�����W)�B</param>
	virtual void DrawTexture( TextureID id, const GSvector2& position );
	/// <summary>
	/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�e�N�X�`����`�悷��ꏊ (�X�N���[�����W)�B</param>
	/// <param name="center">�e�N�X�`���̌��_�B�f�t�H���g�l�� (0,0) �ŁA�������\���܂�.</param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center );
	/// <summary>
	/// �摜�̕`��.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�e�N�X�`����`�悷��ꏊ (�X�N���[�����W)�B</param>
	/// <param name="center">�e�N�X�`���̌��_�B�f�t�H���g�l�� (0,0) �ŁA�������\���܂�.</param>
	/// <param name="color">�e�N�X�`���𒅐F����F.
	/// <para>0.0f�`1.0f�͈̔͂Œ��F���܂�.</para></param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, const GScolor& color );
	/// <summary>
	/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�`��ʒu</param>
	/// <param name="center">�摜�̒��S�ʒu</param>
	/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
	/// <param name="color">�e�N�X�`���𒅐F����F.
	/// <para>0.0f�`1.0f�͈̔͂Œ��F���܂�.</para></param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation );
	/// <summary>
	/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�`��ʒu</param>
	/// <param name="center">�摜�̒��S�ʒu</param>
	/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
	/// <param name="color">�e�N�X�`���𒅐F����F.
	/// <para>0.0f�`1.0f�͈̔͂Œ��F���܂�.</para></param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, const GScolor& color );
	/// <summary>
	/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�`��ʒu</param>
	/// <param name="center">�摜�̒��S�ʒu</param>
	/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
	/// <param name="scale">�X�P�[���W��.</param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, float scale );
	/// <summary>
	/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�`��ʒu</param>
	/// <param name="center">�摜�̒��S�ʒu</param>
	/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
	/// <param name="scale">�X�P�[���W��.</param>
	/// <param name="color">�e�N�X�`���𒅐F����F.
	/// <para>0.0f�`1.0f�͈̔͂Œ��F���܂�.</para></param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, float scale, const GScolor& color );
	/// <summary>
	/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�`��ʒu</param>
	/// <param name="center">�摜�̒��S�ʒu</param>
	/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
	/// <param name="scale">�X�P�[���W��.</param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, const GSvector2& scale );
	/// <summary>
	/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�`��ʒu</param>
	/// <param name="center">�摜�̒��S�ʒu</param>
	/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
	/// <param name="scale">�X�P�[���W��.</param>
	/// <param name="color">�e�N�X�`���𒅐F����F.
	/// <para>0.0f�`1.0f�͈̔͂Œ��F���܂�.</para></param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, const GSvector2& scale, const GScolor& color );


public:
	/// <summary>
	/// �摜��؂�o���ĕ`����s��.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�e�N�X�`����`�悷��ꏊ (�X�N���[�����W)�B</param>
	/// <param name="rect">�e�N�X�`���[��؂�o���͈͂��w�肷��.</param>
	/// <param name="center">�e�N�X�`���̌��_�B�f�t�H���g�l�� (0,0) �ŁA�������\���܂�.</param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center );
	/// <summary>
	/// �摜��؂�o���ĕ`����s��.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�e�N�X�`����`�悷��ꏊ (�X�N���[�����W)�B</param>
	/// <param name="rect">�e�N�X�`���[��؂�o���͈͂��w�肷��.</param>
	/// <param name="center">�e�N�X�`���̌��_�B�f�t�H���g�l�� (0,0) �ŁA�������\���܂�.</param>
	/// <param name="color">�e�N�X�`���𒅐F����F.
	/// <para>0.0f�`1.0f�͈̔͂Œ��F���܂�.</para></param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, const GScolor& color );
	/// <summary>
	/// �摜��؂�o���ĕ`����s��.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�`��ʒu</param>
	/// <param name="rect">�e�N�X�`���[��؂�o���͈͂��w�肷��.</param>
	/// <param name="center">�摜�̒��S�ʒu</param>
	/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
	/// <param name="color">�e�N�X�`���𒅐F����F.
	/// <para>0.0f�`1.0f�͈̔͂Œ��F���܂�.</para></param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation );
	/// <summary>
	/// �摜��؂�o���ĕ`����s��.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�`��ʒu</param>
	/// <param name="rect">�e�N�X�`���[��؂�o���͈͂��w�肷��.</param>
	/// <param name="center">�摜�̒��S�ʒu</param>
	/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
	/// <param name="color">�e�N�X�`���𒅐F����F.
	/// <para>0.0f�`1.0f�͈̔͂Œ��F���܂�.</para></param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, const GScolor& color );
	/// <summary>
	/// �摜��؂�o���ĕ`����s��.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�`��ʒu</param>
	/// <param name="rect">�e�N�X�`���[��؂�o���͈͂��w�肷��.</param>
	/// <param name="center">�摜�̒��S�ʒu</param>
	/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
	/// <param name="scale">�X�P�[���W��.</param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, float scale );
	/// <summary>
	/// �摜��؂�o���ĕ`����s��.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�`��ʒu</param>
	/// <param name="rect">�e�N�X�`���[��؂�o���͈͂��w�肷��.</param>
	/// <param name="center">�摜�̒��S�ʒu</param>
	/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
	/// <param name="scale">�X�P�[���W��.</param>
	/// <param name="color">�e�N�X�`���𒅐F����F.
	/// <para>0.0f�`1.0f�͈̔͂Œ��F���܂�.</para></param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, float scale, const GScolor& color );
	/// <summary>
	/// �摜��؂�o���ĕ`����s��.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�`��ʒu</param>
	/// <param name="rect">�e�N�X�`���[��؂�o���͈͂��w�肷��.</param>
	/// <param name="center">�摜�̒��S�ʒu</param>
	/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
	/// <param name="scale">�X�P�[���W��.</param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, const GSvector2& scale );
	/// <summary>
	/// �摜��؂�o���ĕ`����s��.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�`��ʒu</param>
	/// <param name="rect">�e�N�X�`���[��؂�o���͈͂��w�肷��.</param>
	/// <param name="center">�摜�̒��S�ʒu</param>
	/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
	/// <param name="scale">�X�P�[���W��.</param>
	/// <param name="color">�e�N�X�`���𒅐F����F.
	/// <para>0.0f�`1.0f�͈̔͂Œ��F���܂�.</para></param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, const GSvector2& scale, const GScolor& color );


}; // class Renderer end

#endif

/********** End of File ******************************************************/
