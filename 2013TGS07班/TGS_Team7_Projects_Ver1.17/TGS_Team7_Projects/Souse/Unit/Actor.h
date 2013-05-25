/******************************************************************************
* File Name : Actor.h                              Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		アクター抽象クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _I_ACTOR_H_
#define _I_ACTOR_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<gslib.h>
#include"../Draw/Animation.h"
#include"../Collider/Collider.h"


/*---- 先行宣言 -------------------------------------------------------------*/

/// <summary>ワールド抽象クラス.</summary>
class IWorld;
/// <summary>フラグ管理者抽象クラス.</summary>
class IFlagManager;
/// <summary>ユニットID.</summary>
enum UnitID;


/// <summary>
/// アクター抽象クラス.
/// </summary>
class Actor
{

public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="world">ワールド</param>
	/// <param name="flag">フラグ管理者</param>
	///	 <param name="position">初期座標</param>
	/// <param name="radius">衝突判定用の半径</param>
	Actor( IWorld& world, IFlagManager& flag, const GSvector2& position ,float radius );
	/// <summary>
	/// 仮想デストラクタ.
	/// </summary>
	virtual ~Actor() {}

#pragma region 外部参照前提のクラス.

public:
	/// <summary>
	/// 更新.
	/// </summary>
	/// <param name="frameTimer">フレームタイマー</param>
	virtual void Update( float frameTimer ) = 0;
	/// <summary>
	/// 生産処理.
	/// </summary>
	/// <param name="frameTimer">フレームタイマー</param>
	virtual void Production( float frameTimer ) = 0;
	/// <summary>
	/// 維持コスト支払い処理.
	/// </summary>
	/// <param name="frameTimer">フレームタイマー</param>
	virtual void Maintenance( float frameTimer ) = 0;
	/// <summary>
	/// 描画.
	/// </summary>
	virtual void Draw() = 0;
	/// <summary>
	/// UIの描画.
	/// </summary>
	virtual void DrawUI() = 0;
	/// <summary>
	/// 死亡判定.
	/// </summary>
	/// <returns>死亡していれば真、していなければ偽を返す</returns>
	virtual bool IsDead() const;


#pragma endregion


protected:
	/// <summary>
	/// 強制死亡処理.
	/// </summary>
	void Dead();



#pragma region アクセス禁止関数


private:
	/// <summary>
	/// コピーコンストラクタの禁止.
	/// <para>外部アクセスの禁止.</para>
	/// </summary>
	Actor( const Actor& other );
	/// <summary>
	/// 代入演算子オーバーロードの禁止
	/// <para>外部アクセスの禁止.</para>
	/// </summary>
	Actor& operator = ( const Actor& other );


#pragma endregion


protected:
	/// <summary>
	/// ワールド.
	/// </summary>
	IWorld&			mWorld;
	/// <summary>
	/// フラグ管理者.
	/// </summary>
	IFlagManager&	mFlags;
	/// <summary>
	/// 衝突情報.
	/// </summary>
	Collider		mCollder;
	/// <summary>
	/// アニメーション.
	/// </summary>
	Animation		mAnimation;
	/// <summary>
	/// 生存判定フラグ(生存していれば真).
	/// </summary>
	bool			mIsAlive;

}; // class Actor end

#endif // _I_ACTOR_H_ end

/********** End of File ******************************************************/
