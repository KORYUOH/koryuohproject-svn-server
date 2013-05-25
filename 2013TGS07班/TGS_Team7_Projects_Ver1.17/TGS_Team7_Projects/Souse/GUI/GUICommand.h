/******************************************************************************
* File Name : GUICommand.h                        Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ユーザーインターフェースフレームクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_COMMAND_H_
#define _GUI_COMMAND_H_


/// <summary>
/// GUIコマンド列挙型.
/// </summary>
enum GUICommand
{
	/// <summary>
	/// 偽コマンド.
	/// </summary>
	GUI_COMMAND_FALSE = 0,
	/// <summary>
	/// 真コマンド.
	/// </summary>
	GUI_COMMAND_TRUE = 1,
	/// <summary>
	/// コマンドを持たないGUI.
	/// </summary>
	GUI_COMMAND_NOT_COLLIDER,
	/// <summary>
	/// ウインドウを閉じる.
	/// </summary>
	GUI_COMMAND_WINDOW_CLOSE,
	/// <summary>
	/// 人材の移動.
	/// </summary>
	GUI_COMMAND_HUMAN_MUVEMENT,
	/// <summary>
	/// レベルアップ.
	/// </summary>
	GUI_COMMAND_FACILITY_LEVEL_UP,
	/// <summary>
	/// 工場作成コマンド.
	/// </summary>
	GUI_COMMAND_CREATE_FACTORY,
	/// <summary>
	/// 農場作成コマンド.
	/// </summary>
	GUI_COMMAND_CREATE_FARM,
	/// <summary>
	/// 住宅作成コマンド.
	/// </summary>
	GUI_COMMAND_CREATE_HOUSING,
	/// <summary>
	/// 移動施設作成コマンド.
	/// </summary>
	GUI_COMMAND_CREATE_AIRFIELD,


}; // enum GUICommand end


#endif // _GUI_COMMAND_H_ end

/********** End of File ******************************************************/
