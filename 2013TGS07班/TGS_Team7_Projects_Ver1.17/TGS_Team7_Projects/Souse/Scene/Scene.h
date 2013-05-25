/******************************************************************************
* File Name : Scene.h                             Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		ゲームシーン列挙型．
*
******************************************************************************/
#ifndef _SCENE_H_
#define _SCENE_H_

/// <summary>
/// シーン列挙型.
/// </summary>
enum Scene
{
	/// <summary>
	/// 空のシーン.
	/// </summary>
	SCENE_NONE = 0,
	/// <summary>
	/// タイトルシーン.
	/// </summary>
	SCENE_TITLE,
	/// <summary>
	/// クレジットシーン.
	/// </summary>
	SCENE_CREDIT,
	/// <summary>
	/// ゲームプレイシーン.
	/// </summary>
	SCENE_GAMEPLAY,
	/// <summary>
	/// ランキングシーン.
	/// </summary>
	SCENE_RANKING,
	/// <summary>
	/// エンディングシーン.
	/// </summary>
	SCENE_ENDING,

}; // Scene end


#endif

/********** End of File ******************************************************/
