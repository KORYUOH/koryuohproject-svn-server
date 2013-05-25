/******************************************************************************
* File Name : Renderer.h                             Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		描画クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _RENDERER_H_
#define _RENDERER_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include	"IRenderer.h"
#include	"TextureID.h"
#include	<string>

/*---- 先行宣言 -------------------------------------------------------------*/


/// <summary>
/// 描画クラス
/// </summary>
class Renderer : public IRenderer
{
public:
	/// <summary>
	/// 実体を取得.
	/// <para>シングルトン</para>
	/// </summary>
	/// <returns>実体を返す.</returns>
	static Renderer* GetInstance();

private:
	/// <summary>
	/// コンストラクタ.
	/// <para>外部アクセスの禁止.</para>
	/// </summary>
	Renderer(){}
	/// <summary>
	/// コピーコンストラクタ.
	/// <para>外部アクセスの禁止.</para>
	/// </summary>
	Renderer( const Renderer& other );
	/// <summary>
	/// 代入演算子.
	/// <para>外部アクセスの禁止.</para>
	/// </summary>
	Renderer& operator =( const Renderer& other );



	//メンバ関数
public:
	/// <summary>
	/// 画像の読み込み.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="name">描画位置</param>
	/// <param name="colorKey">カラーキー.
	/// <para>trueに設定すると透過処理を有効に設定</para></param>
	virtual void LoadTexture( TextureID id,const std::string& name , bool colorKey = false );
	/// <summary>
	/// テクスチャの削除.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	virtual void DeleteTexture( TextureID id );

public:
	/// <summary>
	/// 指定されたテクスチャを描画します.
	/// </summary>
	/// <param name="id">テクスチャID.</param>
	virtual void DrawTexture( TextureID id );
	/// <summary>
	/// 指定されたテクスチャを描画します.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">テクスチャを描画する場所 (スクリーン座標)。</param>
	virtual void DrawTexture( TextureID id, const GSvector2& position );
	/// <summary>
	/// 指定されたテクスチャを描画します.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">テクスチャを描画する場所 (スクリーン座標)。</param>
	/// <param name="center">テクスチャの原点。デフォルト値は (0,0) で、左上隅を表します.</param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center );
	/// <summary>
	/// 画像の描画.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">テクスチャを描画する場所 (スクリーン座標)。</param>
	/// <param name="center">テクスチャの原点。デフォルト値は (0,0) で、左上隅を表します.</param>
	/// <param name="color">テクスチャを着色する色.
	/// <para>0.0f～1.0fの範囲で着色します.</para></param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, const GScolor& color );
	/// <summary>
	/// 指定されたテクスチャを描画します.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">描画位置</param>
	/// <param name="center">画像の中心位置</param>
	/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
	/// <param name="color">テクスチャを着色する色.
	/// <para>0.0f～1.0fの範囲で着色します.</para></param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation );
	/// <summary>
	/// 指定されたテクスチャを描画します.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">描画位置</param>
	/// <param name="center">画像の中心位置</param>
	/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
	/// <param name="color">テクスチャを着色する色.
	/// <para>0.0f～1.0fの範囲で着色します.</para></param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, const GScolor& color );
	/// <summary>
	/// 指定されたテクスチャを描画します.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">描画位置</param>
	/// <param name="center">画像の中心位置</param>
	/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
	/// <param name="scale">スケール係数.</param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, float scale );
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
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, float scale, const GScolor& color );
	/// <summary>
	/// 指定されたテクスチャを描画します.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">描画位置</param>
	/// <param name="center">画像の中心位置</param>
	/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
	/// <param name="scale">スケール係数.</param>
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, const GSvector2& scale );
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
	virtual void DrawTexture( TextureID id, const GSvector2& position, const GSvector2& center, float rotation, const GSvector2& scale, const GScolor& color );


public:
	/// <summary>
	/// 画像を切り出して描画を行う.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">テクスチャを描画する場所 (スクリーン座標)。</param>
	/// <param name="rect">テクスチャーを切り出す範囲を指定する.</param>
	/// <param name="center">テクスチャの原点。デフォルト値は (0,0) で、左上隅を表します.</param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center );
	/// <summary>
	/// 画像を切り出して描画を行う.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">テクスチャを描画する場所 (スクリーン座標)。</param>
	/// <param name="rect">テクスチャーを切り出す範囲を指定する.</param>
	/// <param name="center">テクスチャの原点。デフォルト値は (0,0) で、左上隅を表します.</param>
	/// <param name="color">テクスチャを着色する色.
	/// <para>0.0f～1.0fの範囲で着色します.</para></param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, const GScolor& color );
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
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation );
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
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, const GScolor& color );
	/// <summary>
	/// 画像を切り出して描画を行う.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">描画位置</param>
	/// <param name="rect">テクスチャーを切り出す範囲を指定する.</param>
	/// <param name="center">画像の中心位置</param>
	/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
	/// <param name="scale">スケール係数.</param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, float scale );
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
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, float scale, const GScolor& color );
	/// <summary>
	/// 画像を切り出して描画を行う.
	/// </summary>
	/// <param name="id">テクスチャID</param>
	/// <param name="position">描画位置</param>
	/// <param name="rect">テクスチャーを切り出す範囲を指定する.</param>
	/// <param name="center">画像の中心位置</param>
	/// <param name="rotation">テクスチャの中心の周りで回転させる角度を指定します。</param>
	/// <param name="scale">スケール係数.</param>
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, const GSvector2& scale );
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
	virtual void DrawRectTexture( TextureID id, const GSvector2& position, const GSrect& rect, const GSvector2& center, float rotation, const GSvector2& scale, const GScolor& color );


}; // class Renderer end

#endif

/********** End of File ******************************************************/
