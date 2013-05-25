/******************************************************************************
* File Name : Unit.h                              Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ユニット抽象クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_H_
#define _UNIT_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include"Actor.h"
#include"UnitPtr.h"
#include"UnitElement.h"
#include"UnitHierarchy.h"
#include"UnitParameter.h"


/*---- 先行宣言 -------------------------------------------------------------*/

/// <summary>ワールド抽象クラス.</summary>
class IWorld;
/// <summary>ユニットID.</summary>
enum UnitID;


/// <summary>
/// ユニット抽象クラス.
/// </summary>
class Unit : public Actor
{

public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="world">ワールド</param>
	/// <param name="flag">フラグ管理者</param>
	/// <param name="parent">親ユニット</param>
	/// <param name="id">ユニットID</param>
	///	 <param name="position">初期座標</param>
	/// <param name="radius">衝突判定用の半径</param>
	Unit( IWorld& world, IFlagManager& flag, Unit* parent, UnitID id , const GSvector2& position ,float radius );


#pragma region 衝突用関数.

public:
	/// <summary>
	/// 衝突処理.
	/// </summary>
	/// <param name="unit">衝突相手ユニット</param>
	/// <returns>衝突してれば真、していなければ偽を返す</returns>
	bool IsCollide( Unit& unit );
	/// <summary>
	/// 衝突した瞬間の処理.
	/// </summary>
	/// <param name="other">相手ユニット</param>
	virtual void OnCollideEnter( Unit& other );
	/// <summary>
	/// 衝突している間の処理.
	/// </summary>
	/// <param name="other">相手ユニット</param>
	virtual void OnCollideStay( Unit& other );
	/// <summary>
	/// 衝突したオブジェクトが離れた時の処理.
	/// </summary>
	/// <param name="other">相手ユニット</param>
	virtual void OnCollideExit( Unit& other );

#pragma endregion

public:
	/// <summary>
	/// レベルアップ.
	/// </summary>
	/// <returns>処理が正常に終われば真、そうでなければ偽を返す.</returns>
	bool LevelUp();
	/// <summary>
	/// レベルダウン.
	/// </summary>
	/// <returns>処理が正常に終われば真、そうでなければ偽を返す.</returns>
	bool LevelDown();
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
	/// <summary>
	/// 要素の取得.
	/// </summary>
	/// <returns>ユニットの要素を返す</returns>
	const UnitElement& GetElement() const;
	/// <summary>
	/// GUIの登録.
	/// </summary>
	void GUIEntry();
	/// <summary>
	/// GUIの登録解除.
	/// </summary>
	void GUILeave();
	/// <summary>
	/// 親階層が同じか判定.
	/// </summary>
	/// <param name="other">比較ユニット</param>
	/// <returns>等しければ真、そうでなければ偽を返す.</returns>
	bool IsParent( const Unit& other ) const;


protected:
	/// <summary>
	/// ユニットの追加.
	/// </summary>
	/// <param name="id">追加する種類</param>
	/// <param name="frameTimer">ユニット</param>
	virtual void AddUnit( UnitID id, UnitPtr unit );
	/// <summary>
	/// ユニットの削除.
	/// </summary>
	/// <param name="frameTimer">ユニット</param>
	virtual void DeletUnit( Unit* unit );

protected:
	/// <summary>
	/// 要素.
	/// </summary>
	UnitElement		mElement;
	/// <summary>
	/// ユニット階層.
	/// </summary>
	UnitHierarchy	mHierarchy;


}; // class Unit end

#endif // _UNIT_H_ end

/********** End of File ******************************************************/
