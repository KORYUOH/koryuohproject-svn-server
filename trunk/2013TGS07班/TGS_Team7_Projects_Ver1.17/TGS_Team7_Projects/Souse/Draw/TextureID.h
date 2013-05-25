/******************************************************************************
* File Name : TextureID.h                         Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		テクスチャID．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _TEXTURE_ID_H_
#define _TEXTURE_ID_H_


/// <summary>
/// テクスチャID列挙型.
/// </summary>
enum TextureID
{

	/*---- ユニット画像 -----------------------------------------------------*/

	/// <summary>
	/// 宇宙画像.
	/// </summary>
	TEXTURE_UNIT_SPACE= 0,

	/// <summary>
	/// 惑星画像1.
	/// </summary>
	TEXTURE_UNIT_STAR,

	/// <summary>
	/// 住宅施設画像1
	/// </summary>
	TEXTURE_UNIT_HOUSE,

	/// <summary>
	/// 農場施設画像.
	/// </summary>
	TEXTURE_UNIT_FARM,

	/// <summary>
	/// 工場施設画像.
	/// </summary>
	TEXTURE_UNIT_FACTORY,

	/// <summary>
	/// 移動施設画像.
	/// </summary>
	TEXTURE_UNIT_AIRFIELD,


	/*---- キャラクター画像ID -----------------------------------------------*/

	/// <summary>
	/// プレイヤー画像.
	/// </summary>
	TEXTURE_UNIT_PLAYER,
	/// <summary>
	/// プレイヤー画像.
	/// </summary>
	TEXTURE_UNIT_PLAYER2,


	/*---- UI画像 -------------------------------------------------------*/

	/// <summary>
	/// UIフレーム画像.
	/// </summary>
	TEXTURE_GUI_FRAME,
	/// <summary>
	/// ボタンGUI画像.
	/// </summary>
	TEXTURE_GUI_BUTTON,	
	/// <summary>
	/// ボタンGUI画像.
	/// </summary>
	TEXTURE_GUI_BOTTON_CLOSE,
	/// <summary>
	/// レベルアップボタン画像.
	/// </summary>
	TEXTURE_GUI_BOTTON_LEVEL_UP,
	/// <summary>
	/// 住宅ボタン画像.
	/// </summary>
	TEXTURE_GUI_BOTTON_HOUSING,
	/// <summary>
	/// 工場ボタン画像.
	/// </summary>
	TEXTURE_GUI_BOTTON_FACTORY,
	/// <summary>
	/// 農場ボタン画像.
	/// </summary>
	TEXTURE_GUI_BOTTON_FRAM,
	/// <summary>
	/// 棒グラフの画像.
	/// </summary>
	TEXTURE_GUI_BAR_CHART,

	/// <summary>
	/// スコア画像
	/// </summary>
	TEXTURE_GUI_SCORE,
	/// <summary>
	/// タイマー画像.
	/// </summary>
	TEXTURE_GUI_TIMER,
	/// <summary>
	/// 資金画像.
	/// </summary>
	TEXTURE_GUI_MONEY,	
	/// <summary>
	/// 人材画像.
	/// </summary>
	TEXTURE_GUI_HUMAN,
	/// <summary>
	/// 人材最大画像.
	/// </summary>
	TEXTURE_GUI_HUMAN_MAX,
	/// <summary>
	/// 食料画像.
	/// </summary>
	TEXTURE_GUI_FOOD,
	/// <summary>
	/// レベル画像.
	/// </summary>
	TEXTURE_GUI_LEVEL,
	/// <summary>
	/// 数字画像.
	/// </summary>
	TEXTURE_GUI_NUMBER,

	/*---- シーン画像 ---------------------------------------------------*/

	//タイトル画像
	TEXTURE_SCENE_TITLE,
	//タイトル文字画像
	TEXTURE_SCENE_TITLE_NAME,
	//タイトル説明画像
	TEXTURE_SCENE_TITLE_TUTOLAL,
	//エンディング画像
	TEXTURE_SCENE_ENDING,

	/*---- その他の画像 -------------------------------------------------*/

	/// <summary>
	/// デバッグ用画像.
	/// </summary>
	TEXTURE_DEBUG,

	/// <summary>
	/// 空のテクスチャID.
	/// </summary>
	TEXTURE_NULL,

}; // enum TextureID end


#endif // _TEXTURE_ID_H_ end

/********** End of File ******************************************************/
