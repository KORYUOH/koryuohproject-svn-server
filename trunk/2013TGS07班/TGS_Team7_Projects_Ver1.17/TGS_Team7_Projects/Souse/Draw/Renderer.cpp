/******************************************************************************
* File Name : Renderer.cpp                       Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		描画クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include	"Renderer.h"
#include	"TextureID.h"
#include	"../Draw\DrawSprite2D.h"
#include	<string>

/// <summary>
/// 実体を取得.
/// <para>シングルトン</para>
/// </summary>
/// <returns>実体を返す.</returns>
Renderer* Renderer::GetInstance()
{
	static Renderer mInstance;
	return &mInstance;
}

/// <summary>
/// 画像の読み込み.
/// </summary>
/// <param name="id">テクスチャID</param>
/// <param name="name">描画位置</param>
/// <param name="colorKey">カラーキー.
/// <para>trueに設定すると透過処理を有効に設定</para></param>
void Renderer::LoadTexture( TextureID id,const std::string& name , bool colorKey )
{

	gsTextureColorKeyMode(GS_TEXCOLOR_KEY_DISABLE);
	if( colorKey )
	{
		//画像のカラーキーをオートに設定
		gsTextureColorKeyMode(GS_TEXCOLOR_KEY_AUTO);
	}
	//GSlibで画像の読み込み
	gsLoadTexture( id, name.c_str() );

}

/// <summary>
/// テクスチャの削除.
/// </summary>
/// <param name="id">テクスチャID</param>
void Renderer::DeleteTexture( TextureID id )
{
	//テクスチャの削除.
	gsDeleteTexture( id );


}



/// <summary>
/// 指定されたテクスチャを描画します.
/// </summary>
/// <param name="id">テクスチャID.</param>
void Renderer::DrawTexture( TextureID id )
{
	DrawSprite2D( id, NULL, NULL, NULL, 0.0f, NULL, NULL );
}

/// <summary>
/// 指定されたテクスチャを描画します.
/// </summary>
/// <param name="id">テクスチャID</param>
/// <param name="position">テクスチャを描画する場所 (スクリーン座標)。</param>
void Renderer::DrawTexture( TextureID id, const GSvector2& position )
{
	DrawSprite2D( id, NULL, NULL, NULL, 0.0f, &position, NULL );
}

/// <summary>
/// 指定されたテクスチャを描画します.
/// </summary>
/// <param name="id">テクスチャID</param>
/// <param name="position">テクスチャを描画する場所 (スクリーン座標)。</param>
/// <param name="center">テクスチャの原点。デフォルト値は (0,0) で、左上隅を表します.</param>
void Renderer::DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center )
{
	DrawSprite2D( id, NULL, &center, NULL, 0.0f, &position, NULL );
}

/// <summary>
/// 画像の描画.
/// </summary>
/// <param name="id">テクスチャID</param>
/// <param name="position">テクスチャを描画する場所 (スクリーン座標)。</param>
/// <param name="center">テクスチャの原点。デフォルト値は (0,0) で、左上隅を表します.</param>
/// <param name="color">テクスチャを着色する色.
/// <para>0.0f～1.0fの範囲で着色します.</para></param>
void Renderer::DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, const GScolor& color )
{
	DrawSprite2D( id, NULL, &center, NULL, 0.0f, &position, &color );
}

/// <summary>
/// 指定されたテクスチャを描画します.
/// </summary>
/// <param name="id">テクスチャID</param>
/// <param name="position">描画位置</param>
/// <param name="center">画像の中心位置</param>
/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
/// <param name="color">テクスチャを着色する色.
/// <para>0.0f～1.0fの範囲で着色します.</para></param>
void Renderer::DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation )
{
	DrawSprite2D( id, NULL, &center, NULL, rotation, &position, NULL );
}

/// <summary>
/// 指定されたテクスチャを描画します.
/// </summary>
/// <param name="id">テクスチャID</param>
/// <param name="position">描画位置</param>
/// <param name="center">画像の中心位置</param>
/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
/// <param name="color">テクスチャを着色する色.
/// <para>0.0f～1.0fの範囲で着色します.</para></param>
void Renderer::DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, const GScolor& color )
{
	DrawSprite2D( id, NULL, &center, NULL, rotation, &position, &color );
}

/// <summary>
/// 指定されたテクスチャを描画します.
/// </summary>
/// <param name="id">テクスチャID</param>
/// <param name="position">描画位置</param>
/// <param name="center">画像の中心位置</param>
/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
/// <param name="scale">スケール係数.</param>
void Renderer::DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, float scale )
{
	DrawSprite2D( id, NULL, &center, &(GSvector2(1.0f,1.0f)*scale), rotation, &position, NULL );
}

/// <summary>
/// 指定されたテクスチャを描画します.
/// </summary>
/// <param name="id">テクスチャID</param>
/// <param name="position">描画位置</param>
/// <param name="center">画像の中心位置</param>
/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
/// <param name="scale">スケール係数.</param>
/// <param name="color">テクスチャを着色する色.
/// <para>0.0f～1.0fの範囲で着色します.</para></param>
void Renderer::DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, float scale, const GScolor& color )
{
	DrawSprite2D( id, NULL, &center, &(GSvector2(1.0f,1.0f)*scale), rotation, &position, &color );
}

/// <summary>
/// 指定されたテクスチャを描画します.
/// </summary>
/// <param name="id">テクスチャID</param>
/// <param name="position">描画位置</param>
/// <param name="center">画像の中心位置</param>
/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
/// <param name="scale">スケール係数.</param>
void Renderer::DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, const GSvector2& scale )
{
	DrawSprite2D( id, NULL, &center, &scale, rotation, &position, NULL );
}

/// <summary>
/// 指定されたテクスチャを描画します.
/// </summary>
/// <param name="id">テクスチャID</param>
/// <param name="position">描画位置</param>
/// <param name="center">画像の中心位置</param>
/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
/// <param name="scale">スケール係数.</param>
/// <param name="color">テクスチャを着色する色.
/// <para>0.0f～1.0fの範囲で着色します.</para></param>
void Renderer::DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, const GSvector2& scale, const GScolor& color )
{
	DrawSprite2D( id, NULL, &center, &scale, rotation, &position, &color );
}


/// <summary>
/// 画像を切り出して描画を行う.
/// </summary>
/// <param name="id">テクスチャID</param>
/// <param name="position">テクスチャを描画する場所 (スクリーン座標)。</param>
/// <param name="rect">テクスチャーを切り出す範囲を指定する.</param>
/// <param name="center">テクスチャの原点。デフォルト値は (0,0) で、左上隅を表します.</param>
void Renderer::DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center )
{
	DrawSprite2D( id, &rect, &center, NULL, 0.0f, &position, NULL );
}

/// <summary>
/// 画像を切り出して描画を行う.
/// </summary>
/// <param name="id">テクスチャID</param>
/// <param name="position">テクスチャを描画する場所 (スクリーン座標)。</param>
/// <param name="rect">テクスチャーを切り出す範囲を指定する.</param>
/// <param name="center">テクスチャの原点。デフォルト値は (0,0) で、左上隅を表します.</param>
/// <param name="color">テクスチャを着色する色.
/// <para>0.0f～1.0fの範囲で着色します.</para></param>
void Renderer::DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, const GScolor& color )
{
	DrawSprite2D( id, &rect, &center, NULL, 0.0f, &position, &color );
}

/// <summary>
/// 画像を切り出して描画を行う.
/// </summary>
/// <param name="id">テクスチャID</param>
/// <param name="position">描画位置</param>
/// <param name="rect">テクスチャーを切り出す範囲を指定する.</param>
/// <param name="center">画像の中心位置</param>
/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
/// <param name="color">テクスチャを着色する色.
/// <para>0.0f～1.0fの範囲で着色します.</para></param>
void Renderer::DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation )
{
	DrawSprite2D( id, &rect, &center, NULL, rotation, &position, NULL );
}

/// <summary>
/// 画像を切り出して描画を行う.
/// </summary>
/// <param name="id">テクスチャID</param>
/// <param name="position">描画位置</param>
/// <param name="rect">テクスチャーを切り出す範囲を指定する.</param>
/// <param name="center">画像の中心位置</param>
/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
/// <param name="color">テクスチャを着色する色.
/// <para>0.0f～1.0fの範囲で着色します.</para></param>
void Renderer::DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, const GScolor& color )
{
	DrawSprite2D( id, &rect, &center, NULL, rotation, &position, &color );
}

/// <summary>
/// 画像を切り出して描画を行う.
/// </summary>
/// <param name="id">テクスチャID</param>
/// <param name="position">描画位置</param>
/// <param name="rect">テクスチャーを切り出す範囲を指定する.</param>
/// <param name="center">画像の中心位置</param>
/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
/// <param name="scale">スケール係数.</param>
void Renderer::DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, float scale )
{
	DrawSprite2D( id, &rect, &center, &(GSvector2(1.0f,1.0f)*scale), rotation, &position, NULL );
}

/// <summary>
/// 画像を切り出して描画を行う.
/// </summary>
/// <param name="id">テクスチャID</param>
/// <param name="position">描画位置</param>
/// <param name="rect">テクスチャーを切り出す範囲を指定する.</param>
/// <param name="center">画像の中心位置</param>
/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
/// <param name="scale">スケール係数.</param>
/// <param name="color">テクスチャを着色する色.
/// <para>0.0f～1.0fの範囲で着色します.</para></param>
void Renderer::DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, float scale, const GScolor& color )
{
	DrawSprite2D( id, &rect, &center, &(GSvector2(1.0f,1.0f)*scale), rotation, &position, &color );
}

/// <summary>
/// 画像を切り出して描画を行う.
/// </summary>
/// <param name="id">テクスチャID</param>
/// <param name="position">描画位置</param>
/// <param name="rect">テクスチャーを切り出す範囲を指定する.</param>
/// <param name="center">画像の中心位置</param>
/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
/// <param name="scale">スケール係数.</param>
void Renderer::DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, const GSvector2& scale )
{
	DrawSprite2D( id, &rect, &center, &scale, rotation, &position, NULL );
}

/// <summary>
/// 画像を切り出して描画を行う.
/// </summary>
/// <param name="id">テクスチャID</param>
/// <param name="position">描画位置</param>
/// <param name="rect">テクスチャーを切り出す範囲を指定する.</param>
/// <param name="center">画像の中心位置</param>
/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
/// <param name="scale">スケール係数.</param>
/// <param name="color">テクスチャを着色する色.
/// <para>0.0f～1.0fの範囲で着色します.</para></param>
void Renderer::DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, const GSvector2& scale, const GScolor& color )
{
	DrawSprite2D( id, &rect, &center, &scale, rotation, &position, &color );
}

/********** End of File ******************************************************/

