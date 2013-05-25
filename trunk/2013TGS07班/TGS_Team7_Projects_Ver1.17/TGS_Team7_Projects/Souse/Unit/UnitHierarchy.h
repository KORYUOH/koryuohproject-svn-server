/******************************************************************************
* File Name : UnitHierarchy.h                     Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ユニット階層クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_HIERARCHY_H_
#define _UNIT_HIERARCHY_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<list>

/*---- 先行宣言 -------------------------------------------------------------*/

/// <summary>ワールド抽象クラス.</summary>
class IWorld;
/// <summary>ユニットID.</summary>
enum UnitID;
/// <summary>ユニット.</summary>
class Unit;

/// <summary>
/// ユニット階層.
/// </summary>
struct UnitHierarchy
{
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	UnitHierarchy() :
		mParent( NULL )
	{
		mChild.clear();
	}
	/// <summary>
	/// コンストラクタ.
	/// <param name="parent">親ユニット</param>
	/// </summary>
	UnitHierarchy( Unit* parent ) :
		mParent( parent )
	{
		mChild.clear();
	}
	/// <summary>
	/// 上の階層のユニット.
	/// </summary>
	Unit*				mParent;
	/// <summary>
	/// 下の階層のユニット.
	/// </summary>
	std::list<Unit*>	mChild;


}; // UnitHierarchy end

#endif // _UNIT_HIERARCHY_H_ end

/********** End of File ******************************************************/
