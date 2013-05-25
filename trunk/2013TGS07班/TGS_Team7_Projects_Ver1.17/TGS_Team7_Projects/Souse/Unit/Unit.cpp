/******************************************************************************
* File Name : Unit.cpp                           Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ユニット抽象クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Unit.h"
#include"../Utility/Screen.h"
#include"../World/IWorld.h"
#include"../Draw/TextureID.h"
#include"../Utility/Math.h"

/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="world">ワールド</param>
/// <param name="flag">フラグ管理者</param>
/// <param name="parent">親ユニット</param>
/// <param name="id">ユニットID</param>
///	 <param name="position">初期座標</param>
/// <param name="radius">衝突判定用の半径</param>
Unit::Unit( IWorld& world, IFlagManager& flag, Unit* parent, UnitID id, const GSvector2& position, float radius ):
	Actor( world, flag, position, radius ),
	mElement( id, *this ),
	mHierarchy( parent )
{
}

/// <summary>
/// レベルアップ.
/// </summary>
/// <returns>処理が正常に終われば真、そうでなければ偽を返す.</returns>
bool Unit::LevelUp()
{
	// 親階層がない時、もしくはレベルが最大値になっている時.
	if( mHierarchy.mParent == NULL || mElement.mLevel == UNIT_LEVEL_MAX )
	{
		// 早期終了.
		return false;
	}


	// レベルアップ消費コストを支払えなかった時.
	if( mHierarchy.mParent->AccessMoney( -mWorld.GetParameter().GetLevelUpCost(mElement) ) )
	{
		// レベルを上げる.
		mElement.mLevel++;
		// 最大レベルを超えないようにする.
		mElement.mLevel = MIN( mElement.mLevel , UNIT_LEVEL_MAX );
		// 人材の最大値を更新する.
		mElement.mHuman.SetHumanMax( mWorld.GetParameter().GetHumanMax( mElement ) );
		// レベルを上げれたので真を返す.
		return true;
	}

	// コストが支払えないので偽を返す.
	return false;

}

/// <summary>
/// レベルダウン.
/// </summary>
/// <returns>処理が正常に終われば真、そうでなければ偽を返す.</returns>
bool Unit::LevelDown()
{
	// 親階層がない時、もしくはレベルが最低値の時.
	if( mHierarchy.mParent == NULL || mElement.mLevel == UNIT_LEVEL_MIN )
	{
		// 早期終了.
		return false;
	}

	// レベルアップコストの半分を払い戻す.
	if( !mHierarchy.mParent->AccessMoney( mWorld.GetParameter().GetLevelUpCost(mElement)*0.5f ) )
	{
		// 払い戻しが失敗したので偽を返す.
		return false;
	}

	// レベルを下げる.
	mElement.mLevel--;
	// レベルがゼロにならないようにする.
	mElement.mLevel = Math::Max( mElement.mLevel, UNIT_LEVEL_MIN );
	// 人材の最大値を更新する.
	mElement.mHuman.SetHumanMax( mWorld.GetParameter().GetHumanMax( mElement ) );

	// 人材のオーバーしている量を調べる.
	float rezultHuman = mElement.mHuman.GetHuman() - mElement.mHuman.GetHumanMax();;

	// 最大値より大きい時.
	if( rezultHuman > 0.0f )
	{
		// 親階層に人材を託す.
		mHierarchy.mParent->AccessHuman( rezultHuman );
		AccessHuman( -rezultHuman );
	}

	return true;
}

/// <summary>
/// 衝突処理.
/// </summary>
/// <param name="unit">衝突相手ユニット</param>
/// <returns>衝突してれば真、していなければ偽を返す</returns>
bool Unit::IsCollide( Unit& unit )
{
	return mCollder.IsCollide( unit.mCollder );
}

/// <summary>
/// 衝突した瞬間の処理.
/// </summary>
/// <param name="other">相手ユニット</param>
void Unit::OnCollideEnter( Unit& other )
{
	(void)other;
	mCollder.mIsCollision = true;
}

/// <summary>
/// 衝突している間の処理.
/// </summary>
/// <param name="other">相手ユニット</param>
void Unit::OnCollideStay( Unit& other )
{
	(void)other;
}

/// <summary>
/// 衝突したオブジェクトが離れた時の処理.
/// </summary>
/// <param name="other">相手ユニット</param>
void Unit::OnCollideExit( Unit& other )
{
	(void)other;
	mCollder.mIsCollision = false;
}

/// <summary>
/// ユニットの追加.
/// </summary>
/// <param name="id">追加する種類</param>
/// <param name="frameTimer">ユニット</param>
void Unit::AddUnit( UnitID id, UnitPtr unit )
{
	// ワールドに追加.
	mWorld.Add( id, unit );
	// 子階層に追加.
	mHierarchy.mChild.push_back( unit.get() );
}

/// <summary>
/// ユニットの削除.
/// </summary>
/// <param name="frameTimer">ユニット</param>
void Unit::DeletUnit( Unit* unit )
{
	mHierarchy.mChild.remove( unit );
}

/// <summary>
/// 食料へのアクセス.
/// </summary>
/// <param name="food">食料の増減量</param>
/// <returns>正常にアクセスできれば真、できなければ偽を返す.</returns>
bool Unit::AccessFood( float food )
{
	(void)food;
	return false;
}

/// <summary>
/// 資金へのアクセス.
/// </summary>
/// <param name="money">資金の増減量</param>
/// <returns>正常にアクセスできれば真、できなければ偽を返す.</returns>
bool Unit::AccessMoney( float money )
{
	(void)money;
	return false;
}

/// <summary>
/// 人材へのアクセス.
/// </summary>
/// <param name="human">人の増減量</param>
/// <returns>正常にアクセスできれば真、できなければ偽を返す.</returns>
bool Unit::AccessHuman( float human )
{
	// 人材の人事異動が可能の時.
	if( !mElement.mHuman.IsPersonnelChange( human ) )
	{
		return false;
	}

	// 人事異動をする.
	mElement.mHuman.PersonnelChange( human );

	return true;
}


/// <summary>
/// 要素の取得.
/// </summary>
/// <returns>ユニットの要素を返す</returns>
const UnitElement& Unit::GetElement() const
{
	return mElement;
}

/// <summary>
/// GUIの登録.
/// </summary>
void Unit::GUIEntry()
{
	mElement.mGUIframe->FlagDisable();
	// GUIを追加する.
	mWorld.AddGUI( mElement.mGUIframe );
}

/// <summary>
/// GUIの登録解除.
/// </summary>
void Unit::GUILeave()
{
	mElement.mGUIframe->FlagDisable();
	// GUIを追加する.
	mWorld.DeleteGUI( mElement.mGUIframe );
}

/// <summary>
/// 親階層が同じか判定.
/// </summary>
/// <param name="other">比較ユニット</param>
/// <returns>等しければ真、そうでなければ偽を返す.</returns>
bool Unit::IsParent( const Unit& other ) const
{
	return mHierarchy.mParent == other.mHierarchy.mParent;
}

/********** End of File ******************************************************/