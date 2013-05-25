/******************************************************************************
* File Name : Animation.h                        Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		アニメーションクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _ANIMATION_H_
#define _ANIMATION_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

//連想配列の読み込み
#include<map>
//文字列の読み込み
#include<string>
#include<gslib.h>
#include"AnimationTimer.h"

/*---- 先行宣言 -------------------------------------------------------------*/

enum TextureID;


/// <summary>
/// アニメーションクラス.
/// </summary>
class Animation
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="id">アニメーションさせるテクスチャID</param>
	Animation( TextureID id );
	/// <summary>
	/// 初期化.
	/// </summary>
	void Initialize();
	/// <summary>
	/// テクスチャIDの設定.
	/// </summary>
	/// <param name="id">アニメーションさせるテクスチャID</param>
	void SetTextureID( TextureID id );
	/// <summary>
	/// 更新.
	/// </summary>
	/// <param name="frameTimer">フレームレート</param>
	/// <param name="initial">アニメーションさせる表示頭文字</param>
	void Update( float frameTimer, std::string initial );
	/// <summary>
	/// アニメーション画像の切り出し情報(短形)を登録.
	/// </summary>
	/// <param name="initial">アニメーションさせる表示頭文字</param>
	/// <param name="line">何行目の画像</param>
	/// <param name="peace">横画像枚数</param>
	/// <param name="width">1枚画像あたりの横幅</param>
	/// <param name="height">1枚画像あたりの縦幅</param>
	void AddCell( std::string initial, int line, int peace, int width, int height );
	/// <summary>
	/// セルキーを作成「例:D0,D1....」.
	/// </summary>
	/// <param name="initial">追加する頭文字</param>
	/// <param name="number">セルの列番号</param>
	void CreateCurrentCellCell( std::string initial, int number );
	/// <summary>
	/// リセット.
	/// </summary>
	/// <param name="centor">初期化する頭文字</param>
	void Reset( std::string initial );
	/// <summary>
	/// 描画.
	/// </summary>
	/// <param name="position">描画位置</param>
	/// <param name="centor">画像の中心</param>
	void Draw( const GSvector2& position, const GSvector2& centor = GSvector2(0.0f,0.0f) ) const;
	/// <summary>
	/// 描画.
	/// </summary>
	/// <param name="position">描画位置</param>
	/// <param name="centor">画像の中心</param>
	/// <param name="rotate">回転量</param>
	void Draw( const GSvector2& position, const GSvector2& centor, float rotate ) const;
	/// <summary>
	/// アニメーション点滅処理.
	/// </summary>
	/// <param name="position">描画位置</param>
	/// <param name="centor">画像の中心</param>
	void DrawBlink( const GSvector2& position, const GSvector2& centor = GSvector2(0.0f,0.0f) ) const;
	/// <summary>
	/// アニメーション点滅処理.
	/// </summary>
	/// <param name="position">描画位置</param>
	/// <param name="centor">画像の中心</param>
	/// <param name="rotate">回転量</param>
	void DrawBlink( const GSvector2& position, const GSvector2& centor, float rotate ) const;

	/// <summary>
	/// 点滅フラグ更新.
	/// </summary>
	void BlinkUpdate();

private:
	/// <summary>
	/// アニメーション画像の集まり.
	/// </summary>
	std::map<std::string,GSrect>	mCells;
	/// <summary>
	/// 現在のセル情報.
	/// </summary>
	std::string						mCurrentCell;
	/// <summary>
	/// 前回のセル情報.
	/// </summary>
	std::string						mPreviousCell;
	/// <summary>
	/// 表示するセルの列番号.
	/// </summary>
	int								mCellNo;
	/// <summary>
	/// アニメーションタイマーオブジェクト.
	/// </summary>
	AnimationTimer					mAnimationTimer;
	/// <summary>
	/// 表示するアニメーション画像のテクスチャID.
	/// </summary>
	TextureID						mID;
	/// <summary>
	/// 点滅用フラグ.
	/// </summary>
	bool							mIsBlink;


}; // Animation end

#endif // _ANIMATION_H_ end

/********** End of File ******************************************************/
