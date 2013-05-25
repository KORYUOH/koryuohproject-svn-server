/******************************************************************************
* File Name : UIFrame.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ユーザーインターフェースフレームクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"GUIFrame.h"
#include<algorithm>
#include"GUI.h"
#include"GUIPtr.h"
#include"Button.h"
#include"../Draw/Renderer.h"
#include"../Flag/FlagID.h"

/// <summary>
/// コンストラクタ.
/// </summary>
GUIFrame::GUIFrame() :
	mPosition( 0.0f, 0.0f ),
	mAngle( 0.0f ),
	mRange( 0.0f, 0.0f, 0.0, 0.0f ),
	mIsWindow( false )
{
	mGUIs.clear();
}

/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="position">フレームの中央座標</param>
/// <param name="angle">角度</param>
GUIFrame::GUIFrame( const GSvector2& position, float angle ) :
	mPosition( position ),
	mAngle( angle ),
	mRange( 0.0f, 0.0f, 0.0, 0.0f ),
	mIsWindow( false )
{
	mGUIs.clear();
}

/// <summary>
/// 描画.
/// </summary>
void GUIFrame::Draw() const
{
	if( mIsWindow )
	{
		//
		GSvector2 vec;

		// ウインドウを表示する.
		Renderer::GetInstance()->DrawRectTexture( TEXTURE_GUI_FRAME, GSvector2(mRange.left,mRange.top), mRange, GSvector2(0.0f,0.0f) );
	}

	// UIが他に存在しない時.
	if( mGUIs.size() == 0 )
	{
		// 早期終了.
		return; 
	}

	// すべてのUIを描画する.
	std::for_each( mGUIs.begin(), mGUIs.end(), [&]( GUIPtr gui )
	{
		// GUIを描画する.
		gui->Draw( mPosition, mAngle );
	});
}

/// <summary>
/// 範囲を拡大.
/// </summary>
void GUIFrame::RangeExpansion( Collider& collider )
{
	GSvector2 start( collider.mPosition.x - collider.mRadius, collider.mPosition.y - collider.mRadius );
	GSvector2 end( collider.mPosition.x + collider.mRadius, collider.mPosition.y + collider.mRadius );

	// 最初のひとつ目の時.
	if( mGUIs.size() == 1 )
	{
		mRange.left = start.x;
		mRange.right = end.x;
		mRange.top = start.y;
		mRange.bottom = end.y;
		// 早期終了.
		return;
	}

	// 大きさを拡張する.
	mRange.left = MIN( mRange.left, start.x );
	mRange.top = MIN( mRange.top, start.y );
	mRange.right = MAX( mRange.right, end.x );
	mRange.bottom = MAX( mRange.bottom, end.y );
}

/// <summary>
/// UIを追加する.
/// </summary>
/// <param name="addUI">追加するUI</param>
void GUIFrame::AddGUI( GUIPtr addUI )
{
	// UIを追加する.
	mGUIs.push_back( addUI );

	// GUI範囲を拡大する.
	RangeExpansion( addUI->GetCollider() );
}

/// <summary>
/// ウインドウを追加する.
/// </summary>
/// <param name="frameTimer">フラグ管理者</param>
void GUIFrame::AddWindow( IFlagManager& flagManager )
{
	GUIPtr gui = std::make_shared<Button>( Collider( GSvector2(250.0f,20.0f),16.0f ), flagManager, FLAG_WINDOW_CLOSE, TEXTURE_GUI_BOTTON_CLOSE);
	// ウインドウ閉じるボタンを追加する.
	AddGUI( gui );

	// GUI範囲を拡張する.
	RangeExpansion( gui->GetCollider() );

	// ウインドウを作成する.
	mIsWindow = true;
}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームレート</param>
void GUIFrame::Update( float frameTimer )
{
	// GUIが存在していない時.
	if( mGUIs.size() == 0 )
	{
		return;
	}

	// すべてのUIを更新する.
	std::for_each( mGUIs.begin(), mGUIs.end(), [&]( GUIPtr gui )
	{
		// GUIを更新する.
		gui->Update( frameTimer );
	});
}

/// <summary>
/// 衝突の更新.
/// </summary>
/// <param name="other">衝突相手GUI</param>
void GUIFrame::CollisionUpdate( GUIFrame& other )
{
	std::for_each( mGUIs.begin(), mGUIs.end(), [&]( GUIPtr gui )
	{
		other.CollisionUpdate( *gui );
	});
}

/// <summary>
/// 衝突の更新.
/// </summary>
/// <param name="other">衝突相手GUI</param>
/// <returns>衝突している時真、そうでなければ偽を返す.</returns>
void GUIFrame::CollisionUpdate( GUI& other )
{
	std::for_each( mGUIs.begin(), mGUIs.end(), [&]( GUIPtr gui )
	{
		gui->CollisionUpdate( other );
	});
}

/// <summary>
/// フラグの無効化.
/// </summary>
void GUIFrame::FlagDisable()
{
	std::for_each( mGUIs.begin(), mGUIs.end(), []( GUIPtr gui )
	{
		gui->FlagDisable();
	});
}

/********** End of File ******************************************************/
