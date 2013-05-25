/******************************************************************************
* File Name : Mouse.h                             Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		マウス入力クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"MouseState.h"
#include"../Utility/Screen.h"

/// <summary>
/// コンストラクタ.
/// </summary>
MouseState::MouseState()
{
	initialize();
}

/// <summary>
/// デストラクタ.
/// </summary>
MouseState::~MouseState()
{
}

/// <summary>
/// 初期化.
/// </summary>
void MouseState::initialize()
{
	// 移動比率を設定.
	gsSetMouseMoveRatio( (float)Screen::WIDTH / (float)Screen::HEIGHT );

	// マウスカーソルの移動範囲を設定.
	gsSetMousePhysicalBlock( 0, Screen::WIDTH, 0, Screen::HEIGHT );
}

/// <summary>
/// 移動方向の取得.
/// </summary>
/// <returns>移動方向</returns>
GSvector2 MouseState::GetVelocity() const
{
	// 位置を修正する.
	MouseMoveLimit();

	// 移動量保存用変数.
	int x, y, z;

	gsGetMouseOffsetPosition( &x, &y, &z );

	// 移動量からベクトルを作成.
	GSvector2 velocity( x, y );

	return velocity.getNormalized();
}

/// <summary>
/// マウスの位置を取得.
/// </summary>
/// <returns>位置情報</returns>
GSvector2 MouseState::GetMousePosition() const
{
	// マウス保存用の変数を宣言.
	int mouseX, mouseY;

	// マウスの位置を保存.
	gsGetMouseCursorPosition( &mouseX, &mouseY );

	// マウスの位置を保存.
	GSvector2 mousePosition( mouseX, mouseY );

	// マウスの位置を返す.
	return mousePosition;
}

/// <summary>
/// マウスのボタンの押下状態を取得.
/// </summary>
/// <param name="state">調べたいマウスのボタン</param>
/// <returns>押されていれば真，押されていなければ偽を返す.</returns>
bool MouseState::IsMouseButtonDown( GMOUSTATE state ) const
{
	return gsGetMouseButtonState( state ) == GS_TRUE;
}

/// <summary>
/// マウスのボタンが押されたか調べる．
/// </summary>
/// <param name="state">調べたいマウスのボタン</param>
/// <returns>押されたら真，押されなければ偽を返す．</returns>
bool MouseState::IsMouseButtonTrigger( GMOUSTATE state ) const
{
	return gsGetMouseButtonTrigger( state ) == GS_TRUE;
}

/// <summary>
/// マウスのボタンが離されたか調べる.
/// </summary>
/// <param name="state">調べたいマウスのボタン</param>
/// <returns>マウスのボタンの離された状態を返す.</returns>
bool MouseState::IsMouseButtonUp( GMOUSTATE state ) const
{
	return gsGetMouseButtonDetach( state ) == GS_TRUE;
}

/// <summary>
/// マウスの移動範囲を固定する.
/// </summary>
void MouseState::MouseMoveLimit() const
{
	// 移動比率を設定.
	gsSetMouseMoveRatio( (float)Screen::WIDTH / (float)Screen::HEIGHT );

	// マウスカーソルの移動範囲を設定.
	gsSetMousePhysicalBlock( 0, Screen::WIDTH, 0, Screen::HEIGHT );

	// 位置を取得.
	GSvector2 position = GetMousePosition();

	position.x = CLAMP( position.x, 0, Screen::WIDTH );
	position.y = CLAMP( position.y, 0, Screen::WIDTH );

	// 位置を修正.
	gsSetMouseCursorPosition( position.x, position.y );
}

/********** End of File ******************************************************/
