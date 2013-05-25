/******************************************************************************
* File Name : FlagID.h                           Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		フラグID列挙型．
*
******************************************************************************/
#ifndef _FALG_ID_H_
#define _FALG_ID_H_


/// <summary>
/// フラグID.
/// </summary>
enum FlagID
{
	/// <summary>
	/// 空のフラグ.
	/// </summary>
	FLAG_NONE = 0,
	/// <summary>
	/// ウインドウを閉じる.
	/// </summary>
	FLAG_WINDOW_CLOSE,
	/// <summary>
	/// 人材の移動.
	/// </summary>
	FLAG_HUMAN_MUVEMENT,
	/// <summary>
	/// レベルアップ.
	/// </summary>
	FLAG_FACILITY_LEVEL_UP,
	/// <summary>
	/// 工場作成コマンド.
	/// </summary>
	FLAG_CREATE_FACTORY,
	/// <summary>
	/// 農場作成コマンド.
	/// </summary>
	FLAG_CREATE_FARM,
	/// <summary>
	/// 住宅作成コマンド.
	/// </summary>
	FLAG_CREATE_HOUSING,
	/// <summary>
	/// 移動施設作成コマンド.
	/// </summary>
	FLAG_CREATE_AIRFIELD,

};


#endif // _FLAG_MANAGER_H_ end

/********** End of File ******************************************************/