/******************************************************************************
* File Name : IRenderer.h                        Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		描画抽象クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _I_RENDERER_H_
#define _I_RENDERER_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include	<string>
#include	<gslib.h>

/*---- 先行宣言 -------------------------------------------------------------*/

enum	TextureID;

/// <summary>
/// 描画抽象クラス.
/// </summary>
class IRenderer
{

	//メンバ関数.
public:
	/// <summary>
	/// デストラクタ.
	/// </summary>
	virtual ~IRenderer(){}
	/// <summary>
	/// 画像の読み込み.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="name">描画位置</param>
	/// <param name="GScolorKey">カラーキー.
	/// <para>trueに設定すると透過処理を有効に設定</para></param>
	virtual void LoadTexture( TextureID id,const std::string& name , bool GScolorKey = false ) = 0;
	/// <summary>
	/// テクスチャの削除.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	virtual void DeleteTexture( TextureID id ) = 0;

public:
	/// <summary>
	/// 指定されたテクスチャを描画します.
	/// </summary>
	/// <param name="id">テクスチャID.</param>
	virtual void DrawTexture( TextureID id ) = 0;
	/// <summary>
	/// 指定されたテクスチャを描画します.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">テクスチャを描画する場所 (スクリーン座標)。</param>
	virtual void DrawTexture( TextureID id, const GSvector2& position ) = 0;
	/// <summary>
	/// 指定されたテクスチャを描画します.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">テクスチャを描画する場所 (スクリーン座標)。</param>
	/// <param name="center">テクスチャの原点。デフォルト値は (0,0) で、左上隅を表します.</param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center ) = 0;
	/// <summary>
	/// 画像の描画.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">テクスチャを描画する場所 (スクリーン座標)。</param>
	/// <param name="center">テクスチャの原点。デフォルト値は (0,0) で、左上隅を表します.</param>
	/// <param name="color">テクスチャを着色する色.
	/// <para>0.0f～1.0fの範囲で着色します.</para></param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, const GScolor& color ) = 0;
	/// <summary>
	/// 指定されたテクスチャを描画します.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">描画位置</param>
	/// <param name="center">画像の中心位置</param>
	/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
	/// <param name="color">テクスチャを着色する色.
	/// <para>0.0f～1.0fの範囲で着色します.</para></param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation ) = 0;
	/// <summary>
	/// 指定されたテクスチャを描画します.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">描画位置</param>
	/// <param name="center">画像の中心位置</param>
	/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
	/// <param name="color">テクスチャを着色する色.
	/// <para>0.0f～1.0fの範囲で着色します.</para></param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, const GScolor& color ) = 0;
	/// <summary>
	/// 指定されたテクスチャを描画します.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">描画位置</param>
	/// <param name="center">画像の中心位置</param>
	/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
	/// <param name="scale">スケール係数.</param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, float scale ) = 0;
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
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, float scale, const GScolor& color ) = 0;
	/// <summary>
	/// 指定されたテクスチャを描画します.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">描画位置</param>
	/// <param name="center">画像の中心位置</param>
	/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
	/// <param name="scale">スケール係数.</param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, const GSvector2& scale ) = 0;
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
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, const GSvector2& scale, const GScolor& color ) = 0;


public:
	/// <summary>
	/// 画像を切り出して描画を行う.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">テクスチャを描画する場所 (スクリーン座標)。</param>
	/// <param name="rect">テクスチャーを切り出す範囲を指定する.</param>
	/// <param name="center">テクスチャの原点。デフォルト値は (0,0) で、左上隅を表します.</param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center ) = 0;
	/// <summary>
	/// 画像を切り出して描画を行う.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">テクスチャを描画する場所 (スクリーン座標)。</param>
	/// <param name="rect">テクスチャーを切り出す範囲を指定する.</param>
	/// <param name="center">テクスチャの原点。デフォルト値は (0,0) で、左上隅を表します.</param>
	/// <param name="color">テクスチャを着色する色.
	/// <para>0.0f～1.0fの範囲で着色します.</para></param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, const GScolor& color ) = 0;
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
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation ) = 0;
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
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, const GScolor& color ) = 0;
	/// <summary>
	/// 画像を切り出して描画を行う.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">描画位置</param>
	/// <param name="rect">テクスチャーを切り出す範囲を指定する.</param>
	/// <param name="center">画像の中心位置</param>
	/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
	/// <param name="scale">スケール係数.</param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, float scale ) = 0;
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
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, float scale, const GScolor& color ) = 0;
	/// <summary>
	/// 画像を切り出して描画を行う.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">描画位置</param>
	/// <param name="rect">テクスチャーを切り出す範囲を指定する.</param>
	/// <param name="center">画像の中心位置</param>
	/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
	/// <param name="scale">スケール係数.</param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, const GSvector2& scale ) = 0;
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
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, const GSvector2& scale, const GScolor& color ) = 0;


}; // class IRenderer end

#endif

/********** End of File ******************************************************/
