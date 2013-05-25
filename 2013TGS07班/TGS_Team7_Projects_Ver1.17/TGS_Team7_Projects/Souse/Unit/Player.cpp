/******************************************************************************
* File Name : Player.cpp                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		プレイヤークラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Player.h"
#include"../Utility/Screen.h"
#include"../World/IWorld.h"
#include"../Draw/Renderer.h"
#include"../Input/InputState.h"
#include"../Utility/ToString.h"
#include"../GUI/Cursor.h"
#include"../Flag/FlagID.h"
#include"../Flag/IFlagManager.h"

/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="world">ワールド</param>
/// <param name="flag">フラグ管理者</param>
///	 <param name="position">初期座標</param>
Player::Player( IWorld& world, IFlagManager& flag, const GSvector2& position ):
	Unit( world, flag, NULL, UNIT_PLAYER, position, gsGetTexture(TEXTURE_UNIT_PLAYER)->dwWidth / 2 ),
	mSelectUnit( NULL ),
	mNumber( TEXTURE_GUI_NUMBER, 16, 32 )
{
	// アニメーションの初期化.
	mAnimation.SetTextureID( TEXTURE_UNIT_PLAYER );
	mAnimation.AddCell( "1", 0, 1,32, 32 );
	mAnimation.Initialize();

	// カーソルを追加する.
	mElement.mGUIframe->AddGUI( std::make_shared<CursorGUI>( Collider( mCollder.mPosition,mCollder.mRadius ), mFlags, &mCollder.mPosition ) );
	// マネージャーにGUIを登録する.
	mWorld.AddPlayerGUI( mElement.mGUIframe );
}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームタイマー</param>
void Player::Update( float frameTimer ) 
{
	static const float SPEED = 5.0F;

	// マウスを使った移動.
	//mCollder.mPosition = InputState::GetInstance()->GetMousePosition();
	mCollder.mPosition += InputState::GetInstance()->GetVelocity() * SPEED;

	mCollder.mPosition.x = CLAMP( mCollder.mPosition.x, mCollder.mRadius, Screen::WIDTH-mCollder.mRadius ); 
	mCollder.mPosition.y = CLAMP( mCollder.mPosition.y, mCollder.mRadius, Screen::HEIGHT-mCollder.mRadius ); 

	// アニメーションを更新する.
	mAnimation.Update( frameTimer, "1" );

	// GUIの操作を行う.
	GUIOperation();

}

/// <summary>
/// GUI操作.
/// </summary>
void Player::GUIOperation()
{
	// 選択されていない時.
	if( !IsSelectUnit() )
	{
		// 早期終了.
		return;
	}

	// 対象のレベルを上げる.
	GUILevelUp();
	// 現在の選択を解除する.
	GUIDeselect();
}

/// <summary>
/// GUIの選択解除.
/// </summary>
void Player::GUIDeselect()
{
	// 選択がされていない時.
	if( !IsSelectUnit() )
	{
		// 早期終了.
		return;
	}

	// ウインドウクローズコマンドの時.
	if( mFlags.IsFlag( FLAG_WINDOW_CLOSE ) || InputState::GetInstance()->IsCancelButton() )
	{
		// ウインドウを閉じる.
		WindowClose();
		return;
	}

}

/// <summary>
/// 対象のレベルを上げる.
/// </summary>
void Player::GUILevelUp()
{
	// 選択がされていない時.
	if( !IsSelectUnit() )
	{
		// 早期終了.
		return;
	}

	// レベルをあげる.
	if( mFlags.IsFlag( FLAG_FACILITY_LEVEL_UP ) )
	{
		// レベルを上げる.
		mSelectUnit->LevelUp();
		// フラグを無効にする.
		mFlags.FlagDisable( FLAG_FACILITY_LEVEL_UP );
	}

}

/// <summary>
/// 現在の選択があるか判定.
/// </summary>
/// <returns>選択がある時真、そうでなければ偽を返す.</returns>
bool Player::IsSelectUnit() const
{
	return mSelectUnit != NULL;
}

/// <summary>
/// 人材の移動.
/// </summary>
/// <param name="target">目標ユニット</param>
void Player::PersonnelChange( Unit& target )
{
	// 目標と選択が同じ時または選択がされていない時.
	if( !IsSelectUnit() || &target == mSelectUnit )
	{
		// 早期終了.
		return;
	}

	// 左クリックが押されていない時.
	if( !mFlags.IsFlag( FLAG_HUMAN_MUVEMENT ) || !InputState::GetInstance()->IsEnterButton() )
	{
		// 早期終了.
		return;
	}

	float human = 100;
	mFlags.FlagDisable( FLAG_HUMAN_MUVEMENT );

	// 選択中のユニットが移動できた時.
	if( mSelectUnit->AccessHuman( -human ) )
	{
		// 目標のユニットが移動失敗した時.
		if( !target.AccessHuman( human ) )
		{
			// 元に戻す.
			mSelectUnit->AccessHuman( human );
		}
	}
}

/// <summary>
/// ウインドウを閉じる.
/// </summary>
void Player::WindowClose()
{
	// 現在の選択を開放する.
	mSelectUnit->GUILeave();
	mSelectUnit = NULL;
	mFlags.FlagDisable( FLAG_WINDOW_CLOSE );
}

/// <summary>
/// UIの描画.
/// </summary>
void Player::DrawUI()
{
	mNumber.Draw( GSvector2( 0.0f, 200.0f ), mCollder.mPosition.x );
	mNumber.Draw( GSvector2( 0.0f, 250.0f ), mCollder.mPosition.y );
}

/// <summary>
/// 衝突した瞬間の処理.
/// </summary>
/// <param name="other">相手ユニット</param>
void Player::OnCollideEnter( Unit& other )
{
	(void)other;

	mCollder.mIsCollision = true;
}

/// <summary>
/// 衝突している間の処理.
/// </summary>
/// <param name="other">相手ユニット</param>
void Player::OnCollideStay( Unit& other )
{

	// 左クリックをした時.
	if( InputState::GetInstance()->IsEnterButton() && mSelectUnit == NULL )
	{
		// 衝突中のユニットのパスを取得.
		mSelectUnit = &other;
		// GUIを登録させる.
		other.GUIEntry();
	}

	// 人事異動処理
	PersonnelChange( other );

}

/// <summary>
/// 衝突したオブジェクトが離れた時の処理.
/// </summary>
/// <param name="other">相手ユニット</param>
void Player::OnCollideExit( Unit& other )
{
	(void)other;

	mCollder.mIsCollision = false;
}

/********** End of File ******************************************************/
