/******************************************************************************
* File Name : ColliderPair.h                      Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		衝突クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _COLLIDER_PAIR_H_
#define _COLLIDER_PAIR_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<gslib.h>
#include<memory>

/*---- 先行宣言 -------------------------------------------------------------*/

/// <summary>ワールド抽象クラス.</summary>
class IWorld;
/// <summary>ユニット.</summary>
class Unit;

/// <summary>
/// ペアタイプ.
/// </summary>
enum PairType
{
	/// <summary>
	/// 新規ペア.
	/// </summary>
	PAIR_NEW = 0,
	/// <summary>
	/// 継続ペア.
	/// </summary>
	PAIR_KEEP,
	/// <summary>
	/// 削除ペア.
	/// </summary>
	PAIR_DELLETE,
};

/// <summary>
/// 衝突ペアクラス.
/// </summary>
class ColliderPair
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="unitA">ユニットA</param>
	/// <param name="unitB">ユニットB</param>
	ColliderPair( Unit& unitA, Unit& unitB );
	/// <summary>
	/// 衝突応答処理.
	/// </summary>
	void CollisionResponse();
	/// <summary>
	/// 新規衝突処理.
	/// </summary>
	void CollideEnter();
	/// <summary>
	/// 継続衝突処理.
	/// </summary>
	void CollideStay();
	/// <summary>
	/// 衝突解消後処理.
	/// </summary>
	void CollideExit();

public:
	bool operator == ( const ColliderPair& other );
private:
	/// <summary>
	/// コピーコンストラクタの禁止.
	/// <para>外部アクセスの禁止.</para>
	/// </summary>
	ColliderPair( const ColliderPair& other );
	/// <summary>
	/// 代入演算子オーバーロードの禁止
	/// <para>外部アクセスの禁止.</para>
	/// </summary>
	ColliderPair& operator = ( const ColliderPair& other );


public:
	/// <summary>
	/// ユニットA.
	/// </summary>
	PairType	mType;
	/// <summary>
	/// ユニットA.
	/// </summary>
	Unit&		mUnitA;
	/// <summary>
	/// ユニットB.
	/// </summary>
	Unit&		mUnitB;

};

/// <summary>
/// ユニットシェアドポインタ.
/// </summary>
typedef std::shared_ptr<ColliderPair> PairPtr;


#endif // _UNIT_FACTORY_H_ end

/********** End of File ******************************************************/
