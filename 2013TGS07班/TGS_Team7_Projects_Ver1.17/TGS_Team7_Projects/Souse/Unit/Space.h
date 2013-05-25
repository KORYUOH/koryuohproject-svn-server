/******************************************************************************
* File Name : Space.h                              Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		宇宙クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_SPACE_H_
#define _UNIT_SPACE_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include"Unit.h"
#include"../Draw/TextureNumber.h"

/*---- 先行宣言 -------------------------------------------------------------*/

/// <summary>ワールド抽象クラス.</summary>
class IWorld;


/// <summary>
/// 宇宙クラス.
/// </summary>
class Space : public Unit 
{

public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="world">ワールド</param>
	/// <param name="flag">フラグ管理者</param>
	///	 <param name="position">初期座標</param>
	/// <param name="radius">衝突判定用の半径</param>
	Space( IWorld& world, IFlagManager& flag, const GSvector2& position, float radius );


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

protected:	
	/// <summary>
	/// 資金へのアクセス.
	/// </summary>
	/// <param name="money">資金の増減量</param>
	/// <returns>正常にアクセスできれば真、できなければ偽を返す.</returns>
	virtual bool AccessMoney( float money );

private:
	/// <summary>
	/// 資金.
	/// </summary>
	float			mManey;
	/// <summary>
	/// 数字描画管理者.
	/// </summary>
	TextureNumber	mNumber;
};

#endif

/********** End of File ******************************************************/
