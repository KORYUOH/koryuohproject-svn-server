/******************************************************************************
* File Name : Renderer.cpp                       Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�`��N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include	"Renderer.h"
#include	"TextureID.h"
#include	"../Draw\DrawSprite2D.h"
#include	<string>

/// <summary>
/// ���̂��擾.
/// <para>�V���O���g��</para>
/// </summary>
/// <returns>���̂�Ԃ�.</returns>
Renderer* Renderer::GetInstance()
{
	static Renderer mInstance;
	return &mInstance;
}

/// <summary>
/// �摜�̓ǂݍ���.
/// </summary>
/// <param name="id">�e�N�X�`��ID</param>
/// <param name="name">�`��ʒu</param>
/// <param name="colorKey">�J���[�L�[.
/// <para>true�ɐݒ肷��Ɠ��ߏ�����L���ɐݒ�</para></param>
void Renderer::LoadTexture( TextureID id,const std::string& name , bool colorKey )
{

	gsTextureColorKeyMode(GS_TEXCOLOR_KEY_DISABLE);
	if( colorKey )
	{
		//�摜�̃J���[�L�[���I�[�g�ɐݒ�
		gsTextureColorKeyMode(GS_TEXCOLOR_KEY_AUTO);
	}
	//GSlib�ŉ摜�̓ǂݍ���
	gsLoadTexture( id, name.c_str() );

}

/// <summary>
/// �e�N�X�`���̍폜.
/// </summary>
/// <param name="id">�e�N�X�`��ID</param>
void Renderer::DeleteTexture( TextureID id )
{
	//�e�N�X�`���̍폜.
	gsDeleteTexture( id );


}



/// <summary>
/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
/// </summary>
/// <param name="id">�e�N�X�`��ID.</param>
void Renderer::DrawTexture( TextureID id )
{
	DrawSprite2D( id, NULL, NULL, NULL, 0.0f, NULL, NULL );
}

/// <summary>
/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
/// </summary>
/// <param name="id">�e�N�X�`��ID</param>
/// <param name="position">�e�N�X�`����`�悷��ꏊ (�X�N���[�����W)�B</param>
void Renderer::DrawTexture( TextureID id, const GSvector2& position )
{
	DrawSprite2D( id, NULL, NULL, NULL, 0.0f, &position, NULL );
}

/// <summary>
/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
/// </summary>
/// <param name="id">�e�N�X�`��ID</param>
/// <param name="position">�e�N�X�`����`�悷��ꏊ (�X�N���[�����W)�B</param>
/// <param name="center">�e�N�X�`���̌��_�B�f�t�H���g�l�� (0,0) �ŁA�������\���܂�.</param>
void Renderer::DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center )
{
	DrawSprite2D( id, NULL, &center, NULL, 0.0f, &position, NULL );
}

/// <summary>
/// �摜�̕`��.
/// </summary>
/// <param name="id">�e�N�X�`��ID</param>
/// <param name="position">�e�N�X�`����`�悷��ꏊ (�X�N���[�����W)�B</param>
/// <param name="center">�e�N�X�`���̌��_�B�f�t�H���g�l�� (0,0) �ŁA�������\���܂�.</param>
/// <param name="color">�e�N�X�`���𒅐F����F.
/// <para>0.0f�`1.0f�͈̔͂Œ��F���܂�.</para></param>
void Renderer::DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, const GScolor& color )
{
	DrawSprite2D( id, NULL, &center, NULL, 0.0f, &position, &color );
}

/// <summary>
/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
/// </summary>
/// <param name="id">�e�N�X�`��ID</param>
/// <param name="position">�`��ʒu</param>
/// <param name="center">�摜�̒��S�ʒu</param>
/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
/// <param name="color">�e�N�X�`���𒅐F����F.
/// <para>0.0f�`1.0f�͈̔͂Œ��F���܂�.</para></param>
void Renderer::DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation )
{
	DrawSprite2D( id, NULL, &center, NULL, rotation, &position, NULL );
}

/// <summary>
/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
/// </summary>
/// <param name="id">�e�N�X�`��ID</param>
/// <param name="position">�`��ʒu</param>
/// <param name="center">�摜�̒��S�ʒu</param>
/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
/// <param name="color">�e�N�X�`���𒅐F����F.
/// <para>0.0f�`1.0f�͈̔͂Œ��F���܂�.</para></param>
void Renderer::DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, const GScolor& color )
{
	DrawSprite2D( id, NULL, &center, NULL, rotation, &position, &color );
}

/// <summary>
/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
/// </summary>
/// <param name="id">�e�N�X�`��ID</param>
/// <param name="position">�`��ʒu</param>
/// <param name="center">�摜�̒��S�ʒu</param>
/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
/// <param name="scale">�X�P�[���W��.</param>
void Renderer::DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, float scale )
{
	DrawSprite2D( id, NULL, &center, &(GSvector2(1.0f,1.0f)*scale), rotation, &position, NULL );
}

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
void Renderer::DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, float scale, const GScolor& color )
{
	DrawSprite2D( id, NULL, &center, &(GSvector2(1.0f,1.0f)*scale), rotation, &position, &color );
}

/// <summary>
/// �w�肳�ꂽ�e�N�X�`����`�悵�܂�.
/// </summary>
/// <param name="id">�e�N�X�`��ID</param>
/// <param name="position">�`��ʒu</param>
/// <param name="center">�摜�̒��S�ʒu</param>
/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
/// <param name="scale">�X�P�[���W��.</param>
void Renderer::DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, const GSvector2& scale )
{
	DrawSprite2D( id, NULL, &center, &scale, rotation, &position, NULL );
}

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
void Renderer::DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, const GSvector2& scale, const GScolor& color )
{
	DrawSprite2D( id, NULL, &center, &scale, rotation, &position, &color );
}


/// <summary>
/// �摜��؂�o���ĕ`����s��.
/// </summary>
/// <param name="id">�e�N�X�`��ID</param>
/// <param name="position">�e�N�X�`����`�悷��ꏊ (�X�N���[�����W)�B</param>
/// <param name="rect">�e�N�X�`���[��؂�o���͈͂��w�肷��.</param>
/// <param name="center">�e�N�X�`���̌��_�B�f�t�H���g�l�� (0,0) �ŁA�������\���܂�.</param>
void Renderer::DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center )
{
	DrawSprite2D( id, &rect, &center, NULL, 0.0f, &position, NULL );
}

/// <summary>
/// �摜��؂�o���ĕ`����s��.
/// </summary>
/// <param name="id">�e�N�X�`��ID</param>
/// <param name="position">�e�N�X�`����`�悷��ꏊ (�X�N���[�����W)�B</param>
/// <param name="rect">�e�N�X�`���[��؂�o���͈͂��w�肷��.</param>
/// <param name="center">�e�N�X�`���̌��_�B�f�t�H���g�l�� (0,0) �ŁA�������\���܂�.</param>
/// <param name="color">�e�N�X�`���𒅐F����F.
/// <para>0.0f�`1.0f�͈̔͂Œ��F���܂�.</para></param>
void Renderer::DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, const GScolor& color )
{
	DrawSprite2D( id, &rect, &center, NULL, 0.0f, &position, &color );
}

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
void Renderer::DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation )
{
	DrawSprite2D( id, &rect, &center, NULL, rotation, &position, NULL );
}

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
void Renderer::DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, const GScolor& color )
{
	DrawSprite2D( id, &rect, &center, NULL, rotation, &position, &color );
}

/// <summary>
/// �摜��؂�o���ĕ`����s��.
/// </summary>
/// <param name="id">�e�N�X�`��ID</param>
/// <param name="position">�`��ʒu</param>
/// <param name="rect">�e�N�X�`���[��؂�o���͈͂��w�肷��.</param>
/// <param name="center">�摜�̒��S�ʒu</param>
/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
/// <param name="scale">�X�P�[���W��.</param>
void Renderer::DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, float scale )
{
	DrawSprite2D( id, &rect, &center, &(GSvector2(1.0f,1.0f)*scale), rotation, &position, NULL );
}

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
void Renderer::DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, float scale, const GScolor& color )
{
	DrawSprite2D( id, &rect, &center, &(GSvector2(1.0f,1.0f)*scale), rotation, &position, &color );
}

/// <summary>
/// �摜��؂�o���ĕ`����s��.
/// </summary>
/// <param name="id">�e�N�X�`��ID</param>
/// <param name="position">�`��ʒu</param>
/// <param name="rect">�e�N�X�`���[��؂�o���͈͂��w�肷��.</param>
/// <param name="center">�摜�̒��S�ʒu</param>
/// <param name="rotation">�e�N�X�`���̒��S�̎���ŉ�]������p�x���w�肵�܂��B</param>
/// <param name="scale">�X�P�[���W��.</param>
void Renderer::DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, const GSvector2& scale )
{
	DrawSprite2D( id, &rect, &center, &scale, rotation, &position, NULL );
}

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
void Renderer::DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, const GSvector2& scale, const GScolor& color )
{
	DrawSprite2D( id, &rect, &center, &scale, rotation, &position, &color );
}

/********** End of File ******************************************************/

