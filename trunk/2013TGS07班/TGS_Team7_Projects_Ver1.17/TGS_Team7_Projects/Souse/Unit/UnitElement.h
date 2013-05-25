/******************************************************************************
* File Name : UnitElement.h                      Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ユニット要素構造体．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_ELEMENT_H_
#define _UNIT_ELEMENT_H_


/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include"../Managers/Human.h"
#include"../GUI/GUIFrame.h"
#include"../GUI/GUIFramePtr.h"

/*---- 先行宣言 -------------------------------------------------------------*/

/// <summary>ユニットID.</summary>
enum UnitID;

/// <summary>
/// ユニット要素構造体.
/// </summary>
struct UnitElement
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="id">ユニットID</param>
	/// <param name="unit">要素を持つユニット</param>
	UnitElement( UnitID id, Unit& unit ) : 
		mID( id ),
		mLevel( 1 ),
		mHuman(),
		mGUIframe( std::make_shared<GUIFrame>() )
	{
	}	


public:
	/// <summary>
	/// ユニットID.
	/// </summary>
	UnitID			mID;
	/// <summary>
	/// 最大人員数.
	/// </summary>
	int				mLevel;
	/// <summary>
	/// 人材.
	/// </summary>
	Human			mHuman;
	/// <summary>
	/// ユーザーインターフェース.
	/// </summary>
	GUIFramePtr		mGUIframe;

}; // class UnitElement end


#endif // _UNIT_ELEMENT_H_ end

/********** End of File ******************************************************/
