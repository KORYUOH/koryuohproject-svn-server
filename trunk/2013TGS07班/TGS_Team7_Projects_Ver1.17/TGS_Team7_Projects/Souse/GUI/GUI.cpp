/******************************************************************************
* File Name : IUI.cpp                            Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ユーザーインターフェースフレームクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"GUI.h"
#include"../Draw/Renderer.h"
#include"GUICommand.h"
#include"../Utility/SubVector.h"
#include"../Flag/IFlagManager.h"
#include"../Input/InputState.h"

/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="collider">衝突情報</param>
/// <param name="command">フラグ管理者.</param>
/// <param name="command">フラグID.</param>
GUI::GUI( Collider& collider, IFlagManager& flag, FlagID flagID ) :
	mFlagManager( flag ),
	mFlagID( flagID ),
	mCollider( collider )
{
}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームレート</param>
void GUI::Update( float frameTimer )
{
	(void)frameTimer;
}

/// <summary>
/// 衝突フラグを更新する.
/// </summary>
/// <param name="other">衝突相手</param>
void GUI::CollisionUpdate( GUI& other )
{
	if( mCollider.IsCollide( other.mCollider ) )
	{
		mCollider.mIsCollision = true;
		other.mCollider.mIsCollision = true;
	}
	else
	{
		mCollider.mIsCollision = false;
		other.mCollider.mIsCollision = false;
	}
}

/// <summary>
/// フレームとの位置関係を取得する.
/// </summary>
/// <param name="angle">角度</param>
const GSvector2& GUI::GetFreamPositon( float angle ) const
{
	return Velocity( Angle( mCollider.mPosition ) + angle, mCollider.mPosition.length() );
}

/// <summary>
/// フラグの無効化.
/// </summary>
void GUI::FlagDisable()
{
	mFlagManager.FlagDisable( mFlagID );
}

/// <summary>
/// フラグの有効化.
/// </summary>
void GUI::FlagEnable()
{
	if( mCollider.mIsCollision && InputState::GetInstance()->IsEnterButton() )
	{
		mFlagManager.FlagEnable( mFlagID );
	}
}

/// <summary>
/// 衝突情報を取得.
/// </summary>
/// <returns>衝突情報を返す.</returns>
Collider GUI::GetCollider() const
{
	return mCollider;
}

/********** End of File ******************************************************/
