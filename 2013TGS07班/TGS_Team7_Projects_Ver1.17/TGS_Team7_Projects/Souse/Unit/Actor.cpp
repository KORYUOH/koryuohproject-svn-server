/******************************************************************************
* File Name : Actor.cpp                           Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		アクター抽象クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Actor.h"
#include"../World/IWorld.h"
#include"../Draw/TextureID.h"

	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="world">ワールド</param>
	/// <param name="flag">フラグ管理者</param>
	///	 <param name="position">初期座標</param>
	/// <param name="radius">衝突判定用の半径</param>
Actor::Actor( IWorld& world, IFlagManager& flag, const GSvector2& position ,float radius ) :
	mWorld( world ),
	mFlags( flag ),
	mCollder( position , radius ),
	mAnimation( TEXTURE_NULL ),
	mIsAlive( true )
{
}


/// <summary>
/// 死亡判定.
/// </summary>
/// <returns>死亡していれば真、していなければ偽を返す</returns>
bool Actor::IsDead() const
{
	return !mIsAlive;
}


/// <summary>
/// 強制死亡処理.
/// </summary>
void Actor::Dead()
{
	// 死亡させる
	mIsAlive = false;
}


/********** End of File ******************************************************/