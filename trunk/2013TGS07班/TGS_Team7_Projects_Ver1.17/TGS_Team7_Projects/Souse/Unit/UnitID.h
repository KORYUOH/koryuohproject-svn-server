/******************************************************************************
* File Name : UnitID.h                           Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		ユニット列挙型．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_ID_H_
#define _UNIT_ID_H_

/// <summary>
/// アクターID列挙型.
/// </summary>
enum UnitID
{
	/// <summary>
	/// IDなしのアクター.
	/// </summary>
	UNIT_NONE = 0,
	/// <summary>
	/// 宇宙.
	/// </summary>
	UNIT_SPACE = 1,
	/// <summary>
	/// 星.
	/// </summary>
	UNIT_STAR,
	/// <summary>
	/// 農場施設.
	/// </summary>
	UNIT_FARM,
	/// <summary>
	/// 工場施設.
	/// </summary>
	UNIT_FACTORY,
	/// <summary>
	/// 住宅施設.
	/// </summary>
	UNIT_HOUSING,
	/// <summary>
	/// 移動施設.
	/// </summary>
	UNIT_AIRFIELD,

	/// <summary>
	/// プレイヤーID.
	///	</summary>
	UNIT_PLAYER,
	/// <summary>
	/// カメラID.
	/// </summary>
	UNIT_CAMERA,

};

#endif

/********** End of File ******************************************************/
