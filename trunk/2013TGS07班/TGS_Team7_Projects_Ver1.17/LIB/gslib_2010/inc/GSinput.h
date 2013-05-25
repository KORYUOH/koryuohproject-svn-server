/******************************************************************************
* File Name : gsinput.h                            Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       入力デバイスシステム ヘッダファイル．
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSINPUT_H_
#define		_GSINPUT_H_

#include	"ginput.h"

/****** 関数プロトタイプ宣言 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/// <summary>
/// 入力デバイスシステムの初期化.
/// </summary>
/// <param name="hwnd">ウィンドウハンドラ</param>
/// <returns>初期化に成功すれば真，失敗すれば偽を返す</returns>
BOOL
gsInitInput
(
	HWND			hwnd			/* ウィンドウハンドラ           */
);

/// <summary>
/// 入力デバイスシステムの終了処理.
/// </summary>
void
gsFinishInput
(
	void
);

/// <summary>
/// ウィンドウがアクティブになった時の処理.
/// </summary>
/// <param name="active">アクティブフラグ</param>
void
gsActivateInput
(
	BOOL		active				/* アクティブフラグ             */
);

/// <summary>
/// 入力デバイスの状態を読み込む.
/// </summary>
void
gsReadInput
(
	void
);

/// <summary>
/// キーの入力状態を調べる.
/// </summary>
/// <param name="key_code">キーコード</param>
/// <returns>キーが押されていれば真，押されていなければ偽を返す</returns>
BOOL
gsGetKeyState
(
	GKEYCODE		key_code		/* キーコード                   */
);

/// <summary>
/// キーが押されたか調べる.
/// </summary>
/// <param name="key_code">キーコード</param>
/// <returns>キーが押されていれば真，押されていなければ偽を返す</returns>
BOOL
gsGetKeyTrigger
(
	GKEYCODE		key_code		/* キーコード                   */
);

/// <summary>
/// キーが離されたか調べる.
/// </summary>
/// <param name="key_code">キーコード</param>
/// <returns>キーが離されれば真，離されていなければ偽を返す</returns>
BOOL
gsGetKeyDetach
(
	GKEYCODE		key_code		/* キーコード                   */
);

/// <summary>
/// キーボードの押されているキーを調べる.
/// </summary>
/// <returns>押されているキーのキーコードを返す.
/// <para>何も押されていなければ０を返す</para>
/// </returns>
GKEYCODE
gsGetKey
(
	void
);

/// <summary>
/// 接続されているジョイスティック数を調べる.
/// </summary>
/// <returns>接続されているジョイスティック数を返す.</returns>
int
gsGetJoyCount
(
	void
);

/// <summary>
/// ジョイスティックの入力状態を調べる.
/// </summary>
/// <param name="joy_no">ジョイスティックナンバ</param>
/// <param name="state">調べたいジョイステックの状態</param>
/// <returns>押されていれば真，押されていなければ偽を返す.</returns>
BOOL
gsGetJoyState
(
	int				joy_no,			/* ジョイスティックナンバ       */
	GJOYSTATE		state			/* 調べたいジョイステックの状態 */
);

/// <summary>
/// ジョイスティックが押されたか調べる.
/// </summary>
/// <param name="joy_no">ジョイスティックナンバ</param>
/// <param name="state">調べたいジョイステックの状態</param>
/// <returns>押されたら真，押されなければ偽を返す.</returns>
BOOL
gsGetJoyTrigger
(
	int				joy_no,			/* ジョイスティックナンバ       */
	GJOYSTATE		state			/* 調べたいジョイステックの状態 */
);

/// <summary>
/// ジョイスティックが離されたか調べる.
/// </summary>
/// <param name="joy_no">ジョイスティックナンバ</param>
/// <param name="state">調べたいジョイステックの状態</param>
/// <returns>離されたら真，離されなければ偽を返す.</returns>
BOOL
gsGetJoyDetach
(
	int				joy_no,			/* ジョイスティックナンバ       */
	GJOYSTATE		state			/* 調べたいジョイステックの状態 */
);

/// <summary>
/// ジョイスティックの軸の状態を調べる.
/// </summary>
/// <param name="joy_no">ジョイスティックナンバ</param>
/// <param name="x">ジョイステッィクのX軸の状態</param>
/// <param name="y">ジョイステッィクのY軸の状態</param>
/// <param name="z">ジョイステッィクのZ軸の状態</param>
void
gsGetJoyAxis
(
	int				joy_no,			/* ジョイスティックナンバ           */
	int*			x,				/*-> ジョイステッィクのｘ軸の状態   */
	int*			y,				/*-> ジョイステッィクのｙ軸の状態   */
	int*			z				/*-> ジョイステッィクのｚ軸の状態   */
);

/// <summary>
/// マウスの移動量を取得.
/// </summary>
/// <param name="x">X方向移動量</param>
/// <param name="x">Y方向移動量</param>
/// <param name="x">Z方向移動量</param>
void
gsGetMouseOffsetPosition
(
	int*			x,				/*-> ｘ方向移動量               */
	int*			y,				/*-> ｙ方向移動量               */
	int*			z				/*-> ｚ方向移動量               */
);

/// <summary>
/// マウスカーソルの位置を取得.
/// </summary>
/// <param name="x">X座標</param>
/// <param name="y">Y座標</param>
void
gsGetMouseCursorPosition
(
	int*			x,				/*-> ｘ座標                     */
	int*			y				/*-> ｙ座標                     */
);

/// <summary>
/// マウスのボタンの押下状態を取得.
/// </summary>
/// <param name="state">調べたいマウスのボタン</param>
/// <returns>押されていれば真，押されていなければ偽を返す.</returns>
BOOL
gsGetMouseButtonState
(
	GMOUSTATE		state			/* 調べたいマウスのボタン       */
);

/// <summary>
/// マウスのボタンが押されたか調べる．
/// </summary>
/// <param name="state">調べたいマウスのボタン</param>
/// <returns>押されたら真，押されなければ偽を返す．</returns>
BOOL
gsGetMouseButtonTrigger
(
	GMOUSTATE		state			/* 調べたいマウスのボタン       */
);

/// <summary>
/// マウスのボタンが離されたか調べる.
/// </summary>
/// <param name="state">調べたいマウスのボタン</param>
/// <returns>マウスのボタンの離された状態を返す.</returns>
BOOL
gsGetMouseButtonDetach
(
	GMOUSTATE		state			/* 調べたいマウスのボタン       */
);

/// <summary>
/// マウスカーソルの移動比率の設定.
/// </summary>
/// <param name="ratio">移動比率</param>
void
gsSetMouseMoveRatio
(
	FLOAT			ratio			/* 移動比率                     */
);

/// <summary>
/// マウスカーソルの位置を設定.
/// </summary>
/// <param name="x">X座標</param>
/// <param name="y">X座標</param>
void
gsSetMouseCursorPosition
(
	int				x,				/* ｘ座標                       */
	int				y				/* ｙ座標                       */
);

/// <summary>
/// マウスカーソルの移動範囲を設定.
/// </summary>
/// <param name="xmin">X座標最小値</param>
/// <param name="xmax">X座標最大値</param>
/// <param name="ymin">Y座標最小値</param>
/// <param name="ymax">Y座標最大値</param>
void
gsSetMousePhysicalBlock
(
	int				xmin,			/* ｘ座標最小値                 */
	int				xmax,			/* ｘ座標最大値                 */
	int				ymin,			/* ｙ座標最小値                 */
	int				ymax			/* ｙ座標最大値                 */
);

#ifdef __cplusplus
}
#endif

/****** ライブラリ設定 ********************************************************/

#pragma comment( lib, "dinput.lib"  )
#pragma comment( lib, "dxguid.lib"  )

#ifdef	NDEBUG
# ifdef _MT
#  ifdef _DLL
#   pragma comment( lib, "gsinput_md.lib" )
#   pragma comment( lib, "gsutil_md.lib" )
#  else
#   pragma comment( lib, "gsinput_mt.lib" )
#   pragma comment( lib, "gsutil_mt.lib" )
#  endif
# else
#  pragma comment( lib, "gsinput_ml.lib" )
#  pragma comment( lib, "gsutil_ml.lib" )
# endif
#else
# ifdef _MT
#  ifdef _DLL
#   pragma comment( lib, "gsinput_mdd.lib" )
#   pragma comment( lib, "gsutil_mdd.lib" )
#  else
#   pragma comment( lib, "gsinput_mtd.lib" )
#   pragma comment( lib, "gsutil_mtd.lib" )
#  endif
# else
#  pragma comment( lib, "gsinput_mld.lib" )
#  pragma comment( lib, "gsutil_mld.lib" )
# endif
#endif

#endif

/********** End of File ******************************************************/
