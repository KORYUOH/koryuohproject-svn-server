/******************************************************************************
* File Name : gmouse.h                             Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       ゲームシステム用 マウス入力 ヘッダファイル．
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GMOUSE_H_
#define		_GMOUSE_H_

#include	"type.h"

/****** データ型宣言 *********************************************************/

typedef	void*		GMOUSE;			/* マウスハンドラ           */

/*----- マウスボタン入力情報 ------------------------------------------------*/

/// <summary>
/// マウスボタン入力列挙型.
/// </summary>
typedef	enum
{
	/// <summary>
	/// マウスボタン1.
	/// <para>左ボタン.</para>
	/// </summary>
	GMOUSE_BUTTON_1 = 0x0001U,
	/// <summary>
	/// マウスボタン2.
	/// <para>右ボタン.</para>
	/// </summary>
	GMOUSE_BUTTON_2 = 0x0002U,
	/// <summary>
	/// マウスボタン3.
	/// <para>中ボタン(ホイール).</para>
	/// </summary>
	GMOUSE_BUTTON_3 = 0x0004U,
	/// <summary>
	/// マウスボタン4.
	/// </summary>
	GMOUSE_BUTTON_4 = 0x0008U,

} GMOUSTATE;

/****** 関数プロトタイプ宣言 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

	/// <summary>
	/// マウスの生成.
	/// </summary>
	/// <param name="hinst">インスタンスハンドラ</param>
	/// <param name="hwnd">ウィンドウハンドラ</param>
	/// <returns>マウスハンドラを返す.</returns>
	GMOUSE
		GMouseNew
		(
		HINSTANCE		hinst,			/* インスタンスハンドラ     */
		HWND			hwnd			/* ウィンドウハンドラ       */
		);

	/// <summary>
	/// マウスの消滅.
	/// </summary>
	/// <param name="hnd">マウスハンドラ</param>
	void
		GMouseDelete
		(
		GMOUSE			hnd				/* マウスハンドラ           */
		);

	/// <summary>
	/// マウスの読み込み.
	/// </summary>
	/// <param name="hnd">マウスハンドラ</param>
	void
		GMouseReadDevice
		(
		GMOUSE			hnd				/* マウスハンドラ           */
		);

	/// <summary>
	/// マウスの移動量を取得.
	/// </summary>
	/// <param name="hnd">マウスハンドラ</param>
	/// <param name="x">X方向移動量</param>
	/// <param name="y">Y方向移動量</param>
	/// <param name="z">Z方向移動量</param>
	void
		GMouseGetOffsetPosition
		(
		GMOUSE			hnd,			/* マウスハンドラ           */
		int*			x,				/*-> ｘ方向移動量           */
		int*			y,				/*-> ｙ方向移動量           */
		int*			z				/*-> ｚ方向移動量           */
		);

	/// <summary>
	/// マウスカーソルの位置を取得.
	/// </summary>
	/// <param name="hnd">マウスハンドラ</param>
	/// <param name="x">X座標</param>
	/// <param name="y">Y座標</param>
	void
		GMouseGetCursorPosition
		(
		GMOUSE			hnd,			/* マウスハンドラ           */
		int*			x,				/*-> ｘ座標                 */
		int*			y				/*-> ｙ座標                 */
		);

	/// <summary>
	/// マウスのボタンの押下状態を取得.
	/// </summary>
	/// <param name="hnd">マウスハンドラ</param>
	/// <param name="state">調べたいマウスのボタン</param>
	/// <returns>押されていれば真，押されていければ偽を返す.</returns>
	BOOL
		GMouseGetButtonState
		(
		GMOUSE			hnd,			/* マウスハンドラ           */
		GMOUSTATE		state			/* 調べたいマウスのボタン   */
		);

	/// <summary>
	/// マウスのボタンの押されたか調べる.
	/// </summary>
	/// <param name="hnd">マウスハンドラ</param>
	/// <param name="state">調べたいマウスのボタン</param>
	/// <returns>押されていれば真，押されていければ偽を返す.</returns>
	BOOL
		GMouseGetButtonTrigger
		(
		GMOUSE			hnd,			/* マウスハンドラ           */
		GMOUSTATE		state			/* 調べたいマウスのボタン   */
		);

	/// <summary>
	/// マウスのボタンが離されたか調べる.
	/// </summary>
	/// <param name="hnd">マウスハンドラ</param>
	/// <param name="state">調べたいマウスのボタン</param>
	/// <returns>押されていれば真，押されていければ偽を返す.</returns>
	BOOL
		GMouseGetButtonDetach
		(
		GMOUSE			hnd,			/* マウスハンドラ           */
		GMOUSTATE		state			/* 調べたいマウスのボタン   */
		);

	/// <summary>
	/// マウスカーソルの移動比率の取得.
	/// </summary>
	/// <param name="hnd">マウスハンドラ</param>
	/// <returns>移動比率.</returns>
	FLOAT
		GMouseGetMoveRatio
		(
		GMOUSE			hnd				/* マウスハンドラ           */
		);

	/// <summary>
	/// マウスカーソルの移動比率の設定.
	/// </summary>
	/// <param name="hnd">マウスハンドラ</param>
	/// <param name="hnd">移動比率</param>
	void
		GMouseSetMoveRatio
		(
		GMOUSE			hnd,			/* マウスハンドラ           */
		FLOAT			ratio			/* 移動比率                 */
		);

	/// <summary>
	/// マウスカーソルの位置を設定.
	/// </summary>
	/// <param name="hnd">マウスハンドラ</param>
	/// <param name="x">X座標</param>
	/// <param name="y">Y座標</param>
	void
		GMouseSetCursorPosition
		(
		GMOUSE			hnd,			/* マウスハンドラ           */
		int				x,				/* ｘ座標                   */
		int				y				/* ｙ座標                   */
		);

	/// <summary>
	/// マウスカーソルの移動範囲を設定.
	/// </summary>
	/// <param name="hnd">マウスハンドラ</param>
	/// <param name="xmin">X座標最小値</param>
	/// <param name="xmax">X座標最大値</param>
	/// <param name="ymin">Y座標最小値</param>
	/// <param name="ymax">Y座標最大値</param>
	void
		GMouseSetPhysicalBlock
		(
		GMOUSE			hnd,			/* マウスハンドラ           */
		int				xmin,			/* ｘ座標最小値             */
		int				xmax,			/* ｘ座標最大値             */
		int				ymin,			/* ｙ座標最小値             */
		int				ymax			/* ｙ座標最大値             */
		);

	/// <summary>
	/// マウスカーソルの移動範囲の取得.
	/// </summary>
	/// <param name="hnd">マウスハンドラ</param>
	/// <param name="xmin">X座標最小値</param>
	/// <param name="xmax">X座標最大値</param>
	/// <param name="ymin">Y座標最小値</param>
	/// <param name="ymax">Y座標最大値</param>
	void
		GMouseGetPhysicalBlock
		(
		GMOUSE			hnd,			/* マウスハンドラ           */
		int*			xmin,			/*-> ｘ座標最小値           */
		int*			xmax,			/*-> ｘ座標最大値           */
		int*			ymin,			/*-> ｙ座標最小値           */
		int*			ymax			/*-> ｙ座標最小値           */
		);

	/// <summary>
	/// マウスのアクセス権の再取得.
	/// </summary>
	/// <param name="hnd">マウスハンドラ</param>
	/// <returns>取得できれば真，取得できなければ偽を返す.</returns>
	BOOL
		GMouseReacquire
		(
		GMOUSE				hnd			/* マウスハンドラ           */
		);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
