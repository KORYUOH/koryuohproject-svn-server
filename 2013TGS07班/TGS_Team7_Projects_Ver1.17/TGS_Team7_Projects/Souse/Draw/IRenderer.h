/******************************************************************************
* File Name : IRenderer.h                        Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�`�撊�ۃN���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _I_RENDERER_H_
#define _I_RENDERER_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include	<string>
#include	<gslib.h>

/*---- ��s�錾 -------------------------------------------------------------*/

enum	TextureID;

/// <summary>
/// �`�撊�ۃN���X.
/// </summary>
class IRenderer
{

	//�����o�֐�.
public:
	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	virtual ~IRenderer(){}
	/// <summary>
	/// �摜�̓ǂݍ���.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="name">�`��ʒu</param>
	/// <param name="GScolorKey">�J���[�L�[.
	/// <para>true�ɐݒ肷��Ɠ��ߏ�����L���ɐݒ�</para></param>
	virtual void LoadTexture( TextureID id,const std::string& name , bool GScolorKey = false ) = 0;
	/// <summary>
	/// �e�N�X�`���̍폜.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	virtual void DeleteTexture( TextureID id ) = 0;

public:
	/// <summary>
	/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID.</param>
	virtual void DrawTexture( TextureID id ) = 0;
	/// <summary>
	/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�e�N�X�`����`�悷��ꏊ (�X�N���[�����W)�B</param>
	virtual void DrawTexture( TextureID id, const GSvector2& position ) = 0;
	/// <summary>
	/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�e�N�X�`����`�悷��ꏊ (�X�N���[�����W)�B</param>
	/// <param name="center">�e�N�X�`���̌��_�B�f�t�H���g�l�� (0,0) �ŁA�������\���܂�.</param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center ) = 0;
	/// <summary>
	/// �摜�̕`��.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�e�N�X�`����`�悷��ꏊ (�X�N���[�����W)�B</param>
	/// <param name="center">�e�N�X�`���̌��_�B�f�t�H���g�l�� (0,0) �ŁA�������\���܂�.</param>
	/// <param name="color">�e�N�X�`���𒅐F����F.
	/// <para>0.0f�`1.0f�͈̔͂Œ��F���܂�.</para></param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, const GScolor& color ) = 0;
	/// <summary>
	/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�`��ʒu</param>
	/// <param name="center">�摜�̒��S�ʒu</param>
	/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
	/// <param name="color">�e�N�X�`���𒅐F����F.
	/// <para>0.0f�`1.0f�͈̔͂Œ��F���܂�.</para></param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation ) = 0;
	/// <summary>
	/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�`��ʒu</param>
	/// <param name="center">�摜�̒��S�ʒu</param>
	/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
	/// <param name="color">�e�N�X�`���𒅐F����F.
	/// <para>0.0f�`1.0f�͈̔͂Œ��F���܂�.</para></param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, const GScolor& color ) = 0;
	/// <summary>
	/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�`��ʒu</param>
	/// <param name="center">�摜�̒��S�ʒu</param>
	/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
	/// <param name="scale">�X�P�[���W��.</param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, float scale ) = 0;
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
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, float scale, const GScolor& color ) = 0;
	/// <summary>
	/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�`��ʒu</param>
	/// <param name="center">�摜�̒��S�ʒu</param>
	/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
	/// <param name="scale">�X�P�[���W��.</param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, const GSvector2& scale ) = 0;
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
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, const GSvector2& scale, const GScolor& color ) = 0;


public:
	/// <summary>
	/// �摜��؂�o���ĕ`����s��.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�e�N�X�`����`�悷��ꏊ (�X�N���[�����W)�B</param>
	/// <param name="rect">�e�N�X�`���[��؂�o���͈͂��w�肷��.</param>
	/// <param name="center">�e�N�X�`���̌��_�B�f�t�H���g�l�� (0,0) �ŁA�������\���܂�.</param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center ) = 0;
	/// <summary>
	/// �摜��؂�o���ĕ`����s��.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�e�N�X�`����`�悷��ꏊ (�X�N���[�����W)�B</param>
	/// <param name="rect">�e�N�X�`���[��؂�o���͈͂��w�肷��.</param>
	/// <param name="center">�e�N�X�`���̌��_�B�f�t�H���g�l�� (0,0) �ŁA�������\���܂�.</param>
	/// <param name="color">�e�N�X�`���𒅐F����F.
	/// <para>0.0f�`1.0f�͈̔͂Œ��F���܂�.</para></param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, const GScolor& color ) = 0;
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
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation ) = 0;
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
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, const GScolor& color ) = 0;
	/// <summary>
	/// �摜��؂�o���ĕ`����s��.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�`��ʒu</param>
	/// <param name="rect">�e�N�X�`���[��؂�o���͈͂��w�肷��.</param>
	/// <param name="center">�摜�̒��S�ʒu</param>
	/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
	/// <param name="scale">�X�P�[���W��.</param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, float scale ) = 0;
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
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, float scale, const GScolor& color ) = 0;
	/// <summary>
	/// �摜��؂�o���ĕ`����s��.
	/// </summary>
	/// <param name="id">�e�N�X�`��ID</param>
	/// <param name="position">�`��ʒu</param>
	/// <param name="rect">�e�N�X�`���[��؂�o���͈͂��w�肷��.</param>
	/// <param name="center">�摜�̒��S�ʒu</param>
	/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
	/// <param name="scale">�X�P�[���W��.</param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, const GSvector2& scale ) = 0;
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
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, const GSvector2& scale, const GScolor& color ) = 0;


}; // class IRenderer end

#endif

/********** End of File ******************************************************/
