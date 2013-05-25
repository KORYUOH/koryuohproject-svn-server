/******************************************************************************
* File Name : Star.h                             Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		惑星クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_STAR_H_
#define _UNIT_STAR_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include"Unit.h"
#include"../Draw/TextureNumber.h"

/*---- 先行宣言 -------------------------------------------------------------*/

/// <summary>ワールド抽象クラス.</summary>
class IWorld;


/// <summary>
/// 惑星クラス.
/// </summary>
class Star : public Unit
{

public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="world">ワールド</param>
	/// <param name="flag">フラグ管理者</param>
	/// <param name="parent">親ユニット</param>
	///	 <param name="position">初期座標</param>
	/// <param name="radius">衝突判定用の半径</param>
	Star( IWorld& world, IFlagManager& flag, Unit* parent, const GSvector2& position );


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

public:
	/// <summary>
	/// 食料へのアクセス.
	/// </summary>
	/// <param name="food">食料の増減量</param>
	/// <returns>正常にアクセスできれば真、できなければ偽を返す.</returns>
	virtual bool AccessFood( float food );
	/// <summary>
	/// 資金へのアクセス.
	/// </summary>
	/// <param name="money">資金の増減量</param>
	/// <returns>正常にアクセスできれば真、できなければ偽を返す.</returns>
	virtual bool AccessMoney( float money );
	/// <summary>
	/// 人材へのアクセス.
	/// </summary>
	/// <param name="human">人の増減量</param>
	/// <returns>正常にアクセスできれば真、できなければ偽を返す.</returns>
	virtual bool AccessHuman( float human );

private:
	/// <summary>
	/// 施設の作成.
	/// </summary>
	void CreateFacility();
	/// <summary>
	/// 住宅施設の作成.
	/// </summary>
	/// <param name="angle">角度</param>
	void CreateHousing( float angle );
	/// <summary>
	/// 施設の作成.
	/// </summary>
	/// <param name="angle">角度</param>
	void CreateFactory( float angle );
	/// <summary>
	/// 施設の作成.
	/// </summary>
	/// <param name="angle">角度</param>
	void CreateFarm( float angle );


private:
	/// <summary>
	/// 人材.
	/// </summary>
	float			mHumanResources;
	/// <summary>
	/// 食料.
	/// </summary>
	float			mFood;
	/// <summary>
	/// 数字描画管理者.
	/// </summary>
	TextureNumber	mNumber;

};

#endif

/********** End of File ******************************************************/
