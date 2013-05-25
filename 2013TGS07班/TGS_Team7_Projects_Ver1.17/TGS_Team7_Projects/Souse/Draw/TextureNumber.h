/******************************************************************************
* File Name : TextureNumber.h                    Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		数列表示クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _TEXTURE_NUMBER_H_
#define _TEXTURE_NUMBER_H_
/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<string>
#include<gslib.h>

/*---- 先行宣言 -------------------------------------------------------------*/

//テクスチャID
enum TextureID;

/// <summary>
/// テクスチャナンバークラス.
/// </summary>
class TextureNumber
{
public:
	/// <summary>
	/// コンストラクタ.
	/// <para>テクスチャナンバークラスの新規作成</para>
	/// </summary>
	/// <param name="textureID">テクスチャID</param>
	/// <param name="width">画像1枚分の横幅</param>
	/// <param name="height">画像1枚分の縦幅</param>
	TextureNumber(TextureID textureID,float width,float height);
	/// <summary>
	/// 数字を描画.
	/// </summary>
	/// <param name="position">表示位置</param>
	/// <param name="number">表示数字</param>
	void Draw(const GSvector2& position,int number) const;
	/// <summary>
	/// 数字を描画.
	/// </summary>
	/// <param name="position">表示位置</param>
	/// <param name="number">表示数字</param>
	void Draw(const GSvector2& position,float number) const;
	/// <summary>
	/// 空いている場所を埋める文字を指定.
	/// </summary>
	/// <param name="c">空白を埋める文字</param>
	void SetFill(char c);
	/// <summary>
	/// 表示桁数を指定.
	/// </summary>
	/// <param name="width">表示する桁数</param>
	void SetField(int width);
	/// <summary>
	/// 数列を表示.
	/// </summary>
	/// <param name="position">表示位置</param>
	/// <param name="number">表示数列(文字列)</param>
	void DrawString(const GSvector2& position,const std::string& number) const;
	/// <summary>
	/// 1文字(数字)を表示.
	/// </summary>
	/// <param name="position">表示位置</param>
	/// <param name="number">表示数字(文字)</param>
	void DrawChar(const GSvector2& position,char number) const;
	/// <summary>
	/// 1文字(数字)を表示.
	/// </summary>
	/// <param name="position">表示位置</param>
	/// <param name="number">表示数字(文字)</param>
	void DrawDot(const GSvector2& position,char number) const;

private:
	/// <summary>
	/// テクスチャID.
	/// </summary>
	TextureID	mTextureID;
	/// <summary>
	/// 画像の横幅.
	/// </summary>
	float		mWidth;
	/// <summary>
	/// 画像の縦幅.
	/// </summary>
	float		mHeight;
	/// <summary>
	/// 空白を埋める文字.
	/// </summary>
	char		mFill;
	/// <summary>
	/// フィールド幅(何桁で表示するか).
	/// </summary>
	int			mField;
};

#endif
/********** End of File ******************************************************/
