/******************************************************************************
* File Name : Animation.cpp                       Ver : 1.00  Date : 2012-12-16
*
* Description :
*
*		アニメーションクラスの実装．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Animation.h"
#include"AnimationTimer.h"

#include"../Draw\Renderer.h"
#include"../Draw\TextureID.h"
#include<algorithm>
#include"../Utility\ToString.h"


/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="id">アニメーションさせるテクスチャID</param>
Animation::Animation( TextureID id ):
	mCurrentCell(""),
	mPreviousCell(""),
	mCellNo( 0 ),
	mAnimationTimer(),
	mID(id),
	mIsBlink( false )
{
	mCells.clear();
}


/// <summary>
/// 初期化.
/// </summary>
void Animation::Initialize()
{
	//最初の連想配列のキーを現在のキーに変更
	mCurrentCell =  mCells.begin()->first;
	//アニメーションタイマーの初期化
	mAnimationTimer.Initialize();
	//セル番号初期化
	mCellNo = 0;
	//最後のキーに空の短形を追加する
	mCells["EndKey"] = GSrect(0,0,0,0);
	//点滅を無効に設定
	mIsBlink = false;
}

/// <summary>
/// テクスチャIDの設定.
/// </summary>
/// <param name="id">アニメーションさせるテクスチャID</param>
void Animation::SetTextureID( TextureID id )
{
	mID = id;
}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームレート</param>
/// <param name="initial">アニメーションさせる表示頭文字</param>
void Animation::Update( float frameTimer, std::string initial )
{
	// アニメーションタイマーを更新.
	mAnimationTimer.Update( frameTimer );

	// 現在のセルを1フレーム前のせるとして代入.
	mPreviousCell = mCurrentCell;

	// セルキーを作成.
	CreateCurrentCellCell(initial,mCellNo);

	// 作成したキーがマップに登録されていない時.
	if( mCurrentCell != mPreviousCell )
	{
		// リセット.
		Reset(initial);
	}

	// アニメーションタイマーがゼロでない時.
	if( !mAnimationTimer.IsZero() )
	{
		// 早期終了.
		return;
	}

	// 表示させるセルの列番号をインクリメント.
	mCellNo++;

	// 受け取った頭文字でキーを作成して現在のセルとして設定.
	CreateCurrentCellCell(initial,mCellNo);

	// 作成したキーがマップに登録されていなければ.
	if( mCells.find(mCurrentCell) == mCells.end() /*&& currentCell != cells.end()->first*/ )
	{
		// リセットする.
		Reset(initial);
	}

	// アニメーションタイマーをリセット.
	mAnimationTimer.Reset();
	// 点滅を更新.
	BlinkUpdate();
}

/// <summary>
/// アニメーション画像の切り出し情報(短形)を登録.
/// </summary>
/// <param name="initial">アニメーションさせる表示頭文字</param>
/// <param name="line">何行目の画像</param>
/// <param name="peace">横画像枚数</param>
/// <param name="width">1枚画像あたりの横幅</param>
/// <param name="height">1枚画像あたりの縦幅</param>
void Animation::AddCell( std::string initial, int line, int peace, int width, int height)
{
	//1セルずつ座標番号を登録
	for( int i = 0 ; i < peace ; ++i)
	{
		//マップキーに頭文字の番号を振って管理
		std::string key = initial + IntToString(i);

		//短形情報を設定
		GSrect rect(i*width,(line-1)*height, width, height);
		rect.right = rect.left + width;
		rect.bottom = rect.top + height;

		//番号の短形を登録
		mCells[key] = rect;
	}
}

/// <summary>
/// セルキーを作成「例:D0,D1....」.
/// </summary>
/// <param name="initial">追加する頭文字</param>
/// <param name="number">セルの列番号</param>
void Animation::CreateCurrentCellCell( std::string initial, int number )
{
	mCurrentCell = initial + IntToString(number);
}

/// <summary>
/// リセット.
/// </summary>
/// <param name="centor">初期化する頭文字</param>
void Animation::Reset(std::string initial)
{
	// セルの列番号を初期化.
	mCellNo = 0;
	// セルキーを作成.
	CreateCurrentCellCell( initial,mCellNo );
	// アニメーションタイマーをリセット.
	mAnimationTimer.Reset();
}


/// <summary>
/// 描画.
/// </summary>
/// <param name="position">描画位置</param>
/// <param name="centor">画像の中心</param>
void Animation::Draw( const GSvector2& position, const GSvector2& centor ) const
{
	// アニメーション画像がない時.
	if( mCells.size() == 0 )
	{
		// 描画を行わない.
		return;
	}

	// 画像を切り出して描画
	Renderer::GetInstance()->DrawRectTexture( mID, position, mCells.find(mCurrentCell)->second, centor );
}

/// <summary>
/// 描画.
/// </summary>
/// <param name="position">描画位置</param>
/// <param name="centor">画像の中心</param>
/// <param name="rotate">回転量</param>
void Animation::Draw( const GSvector2& position, const GSvector2& centor, float rotate ) const
{
	// アニメーション画像がない時.
	if( mCells.size() == 0 )
	{
		// 描画を行わない.
		return;
	}

	// 画像を切り出して描画
	Renderer::GetInstance()->DrawRectTexture( mID, position, mCells.find(mCurrentCell)->second, centor, rotate );
}

/// <summary>
/// アニメーション点滅処理.
/// </summary>
/// <param name="position">描画位置</param>
/// <param name="centor">画像の中心</param>
void Animation::DrawBlink( const GSvector2& position, const GSvector2& centor ) const
{
	// ガード節
	// 点滅フラグが有効の時は早期終了
	if( mIsBlink )
	{
		return;
	}

	// 画像を切り出して描画.
	Draw( position, centor );
}

/// <summary>
/// アニメーション点滅処理.
/// </summary>
/// <param name="position">描画位置</param>
/// <param name="centor">画像の中心</param>
/// <param name="rotate">回転量</param>
void Animation::DrawBlink( const GSvector2& position, const GSvector2& centor, float rotate ) const
{
	// ガード節
	// 点滅フラグが有効の時は早期終了
	if( mIsBlink )
	{
		return;
	}

	// 画像を切り出して描画.
	Draw( position, centor, rotate );
}

/// <summary>
/// 点滅フラグ更新.
/// </summary>
void Animation::BlinkUpdate()
{
	//フラグを反転させる.
	mIsBlink = (mIsBlink) ? (false) : (true);
}

/********** End of File ******************************************************/