/******************************************************************************
* File Name : TextureNumber.cpp                  Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		数列表示クラス．
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
/// コンストラクタ.
/// <para>テクスチャナンバークラスの新規作成</para>
/// </summary>
/// <param name="textureID">テクスチャID</param>
/// <param name="width">画像1枚分の横幅</param>
/// <param name="height">画像1枚分の縦幅</param>
TextureNumber::TextureNumber( TextureID textureID, float width, float height ):
	mTextureID( textureID ),
	mWidth( width ),
	mHeight( height ),
	mFill( '0' ),
	mField( 10 )
{
}

/// <summary>
/// 数字を描画.
/// </summary>
/// <param name="position">表示位置</param>
/// <param name="number">表示数字</param>
void TextureNumber::Draw( const GSvector2& position,int number ) const
{
	// 画面に出す代わりにメモリに出力する.
	std::stringstream stream;
	// 指定したフィールド幅と空きスペースを付けて変換.
	stream<<std::setw(mField)<<std::setfill(mFill)<<number;
	// 数字を描画させる(stream.str()でメモリから取り出す).
	DrawString(position,stream.str());
}

/// <summary>
/// 数字を描画.
/// </summary>
/// <param name="position">表示位置</param>
/// <param name="number">表示数字</param>
void TextureNumber::Draw( const GSvector2& position,float number ) const
{
	// 画面に出す代わりにメモリに出力する.
	std::stringstream stream;
	// 指定したフィールド幅と空きスペースを付けて変換.
	stream<<std::setw(mField)<<std::setfill(mFill)<<number;
	// 数字を描画させる(stream.str()でメモリから取り出す).
	DrawString(position,stream.str());
}



/// <summary>
/// 空いている場所を埋める文字を指定.
/// </summary>
/// <param name="c">空白を埋める文字</param>
void TextureNumber::SetFill( char c )
{
	mFill = c;
}

/// <summary>
/// 表示桁数を指定.
/// </summary>
/// <param name="width">表示する桁数</param>
void TextureNumber::SetField(int width)
{
	mField = width;
}

/// <summary>
/// 数列を表示.
/// </summary>
/// <param name="position">表示位置</param>
/// <param name="number">表示数列(文字列)</param>
void TextureNumber::DrawString( const GSvector2& position,const std::string& number ) const
{
	// １文字ずつ表示させるループ.
	for( unsigned int i = 0;i<number.size();++i )
	{
		// 描画させる位置を指定.
		GSvector2 pos = position + GSvector2( i * mWidth ,0.0f );
		// １文字ずつ描画させる(string型は配列表記で１文字ずつ扱うことができる).
		DrawChar(pos,number[i]);
	}
}

/// <summary>
/// 1文字(数字)を表示.
/// </summary>
/// <param name="position">表示位置</param>
/// <param name="number">表示数字(文字)</param>
void TextureNumber::DrawChar( const GSvector2& position,char number ) const
{
	// 文字コードを見て数字以外の時.
	if( number < '0' || number > '9' )
	{
		// 点であれば描画する.
		DrawDot( position, number );

		//早期終了
		return;
	}

	// 画像を切り出す範囲の作成.
	GSrect rect;
	rect.left	= ( number - '0' ) * mWidth;
	rect.right	= rect.left + mWidth;
	rect.top	= 0.0f;
	rect.bottom	= rect.top + mHeight;

	// 指定画像を描画.
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
/// 1文字(数字)を表示.
/// </summary>
/// <param name="position">表示位置</param>
/// <param name="number">表示数字(文字)</param>
void TextureNumber::DrawDot(const GSvector2& position,char number) const
{
	// 数字が小数点の時.
	if( number == '.' )
	{
		// 画像を切り出す範囲の作成.
		GSrect rect;
		rect.left	= 10 * mWidth;
		rect.right	= rect.left + mWidth;
		rect.top	= 0.0f;
		rect.bottom	= rect.top + mHeight;

		// 指定画像を描画.
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