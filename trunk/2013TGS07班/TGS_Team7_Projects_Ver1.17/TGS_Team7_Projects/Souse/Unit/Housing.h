/******************************************************************************
* File Name : Housing.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		住宅施設クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_HOUSING_H_
#define _UNIT_HOUSING_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include"Unit.h"
#include"../Draw/TextureNumber.h"
#include"../GUI/GUIBarChart.h"

/*---- 先行宣言 -------------------------------------------------------------*/

/// <summary>ワールド抽象クラス.</summary>
class IWorld;


/// <summary>
/// 住宅施設クラス.
/// </summary>
class Housing : public Unit 
{

public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="world">ワールド</param>
	/// <param name="flag">フラグ管理者</param>
	/// <param name="parent">親ユニット</param>
	///	 <param name="collider">星の衝突情報</param>
	/// <param name="angle">星から見た角度</param>
	Housing( IWorld& world, IFlagManager& flag, Unit* parent, const Collider& collider, float angle );


public:
	/// <summary>
	/// 更新.
	/// </summary>
	/// <param name="frameTimer">フレームタイマー</param>
	virtual void Update( float frameTimer );
	/// <summary>
	/// 生産処理.
	/// </summary>
	/// <param name="frameTimer">フレームタイマー</param>
	virtual void Production( float frameTimer );
	/// <summary>
	/// 維持コスト支払い処理.
	/// </summary>
	/// <param name="frameTimer">フレームタイマー</param>
	virtual void Maintenance( float frameTimer );
	/// <summary>
	/// 描画.
	/// </summary>
	virtual void Draw();
	/// <summary>
	/// UIの描画.
	/// </summary>
	virtual void DrawUI();

private:
	/// <summary>
	/// 数字描画管理者.
	/// </summary>
	TextureNumber	mNumber;
	/// <summary>
	/// 角度.
	/// </summary>
	float			mAngle;
};

#endif

/********** End of File ******************************************************/
