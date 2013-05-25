/******************************************************************************
* File Name : TextureNumber.cpp                  Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		����\���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include	"../Draw\DrawSprite2D.h"
#include	"TextureNumber.h"
#include	"TextureID.h"
#include	<sstream>
#include	<iomanip>

/// <summary>
/// �R���X�g���N�^.
/// <para>�e�N�X�`���i���o�[�N���X�̐V�K�쐬</para>
/// </summary>
/// <param name="textureID">�e�N�X�`��ID</param>
/// <param name="width">�摜1�����̉���</param>
/// <param name="height">�摜1�����̏c��</param>
TextureNumber::TextureNumber( TextureID textureID, float width, float height ):
	mTextureID( textureID ),
	mWidth( width ),
	mHeight( height ),
	mFill( '0' ),
	mField( 10 )
{
}

/// <summary>
/// ������`��.
/// </summary>
/// <param name="position">�\���ʒu</param>
/// <param name="number">�\������</param>
void TextureNumber::Draw( const GSvector2& position,int number ) const
{
	// ��ʂɏo������Ƀ������ɏo�͂���.
	std::stringstream stream;
	// �w�肵���t�B�[���h���Ƌ󂫃X�y�[�X��t���ĕϊ�.
	stream<<std::setw(mField)<<std::setfill(mFill)<<number;
	// ������`�悳����(stream.str()�Ń�����������o��).
	DrawString(position,stream.str());
}

/// <summary>
/// ������`��.
/// </summary>
/// <param name="position">�\���ʒu</param>
/// <param name="number">�\������</param>
void TextureNumber::Draw( const GSvector2& position,float number ) const
{
	// ��ʂɏo������Ƀ������ɏo�͂���.
	std::stringstream stream;
	// �w�肵���t�B�[���h���Ƌ󂫃X�y�[�X��t���ĕϊ�.
	stream<<std::setw(mField)<<std::setfill(mFill)<<number;
	// ������`�悳����(stream.str()�Ń�����������o��).
	DrawString(position,stream.str());
}



/// <summary>
/// �󂢂Ă���ꏊ�𖄂߂镶�����w��.
/// </summary>
/// <param name="c">�󔒂𖄂߂镶��</param>
void TextureNumber::SetFill( char c )
{
	mFill = c;
}

/// <summary>
/// �\���������w��.
/// </summary>
/// <param name="width">�\�����錅��</param>
void TextureNumber::SetField(int width)
{
	mField = width;
}

/// <summary>
/// �����\��.
/// </summary>
/// <param name="position">�\���ʒu</param>
/// <param name="number">�\������(������)</param>
void TextureNumber::DrawString( const GSvector2& position,const std::string& number ) const
{
	// �P�������\�������郋�[�v.
	for( unsigned int i = 0;i<number.size();++i )
	{
		// �`�悳����ʒu���w��.
		GSvector2 pos = position + GSvector2( i * mWidth ,0.0f );
		// �P�������`�悳����(string�^�͔z��\�L�łP�������������Ƃ��ł���).
		DrawChar(pos,number[i]);
	}
}

/// <summary>
/// 1����(����)��\��.
/// </summary>
/// <param name="position">�\���ʒu</param>
/// <param name="number">�\������(����)</param>
void TextureNumber::DrawChar( const GSvector2& position,char number ) const
{
	// �����R�[�h�����Đ����ȊO�̎�.
	if( number < '0' || number > '9' )
	{
		// �_�ł���Ε`�悷��.
		DrawDot( position, number );

		//�����I��
		return;
	}

	// �摜��؂�o���͈͂̍쐬.
	GSrect rect;
	rect.left	= ( number - '0' ) * mWidth;
	rect.right	= rect.left + mWidth;
	rect.top	= 0.0f;
	rect.bottom	= rect.top + mHeight;

	// �w��摜��`��.
	DrawSprite2D(
		mTextureID,
		&rect,
		NULL,
		NULL,
		0.0f,
		&position,
		NULL
		);

}

/// <summary>
/// 1����(����)��\��.
/// </summary>
/// <param name="position">�\���ʒu</param>
/// <param name="number">�\������(����)</param>
void TextureNumber::DrawDot(const GSvector2& position,char number) const
{
	// �����������_�̎�.
	if( number == '.' )
	{
		// �摜��؂�o���͈͂̍쐬.
		GSrect rect;
		rect.left	= 10 * mWidth;
		rect.right	= rect.left + mWidth;
		rect.top	= 0.0f;
		rect.bottom	= rect.top + mHeight;

		// �w��摜��`��.
		DrawSprite2D(
			mTextureID,
			&rect,
			NULL,
			NULL,
			0.0f,
			&position,
			NULL
			);

		return;
	}

}

/********** End of File ******************************************************/