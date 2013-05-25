/******************************************************************************
* File Name : IWorld.h                           Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		ワールド抽象クラス．
*
******************************************************************************/
#ifndef _I_WORLD_H_
#define _I_WORLD_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include	"../Unit/UnitPtr.h"
#include	"../GUI/GUIFramePtr.h"

/*---- 先行宣言 -------------------------------------------------------------*/

class Camera;
class Timer;
enum UnitID;
enum GUICommand;
class UnitParameter;

/// <summary>
/// ワールド抽象クラス.
/// </summary>
class IWorld
{
public:
	/// <summary>
	/// 仮想デストラクタ.
	/// </summary>
	virtual ~IWorld() {}
	/// <summary>
	/// アクターの追加.
	/// </summary>
	/// <param name="id">アクターマネージャID</param>
	/// <param name="actor">追加するアクター</param>
	virtual void Add( UnitID id,UnitPtr actor ) = 0;
	/// <summary>
	/// プレイヤーの生成.
	/// </summary>
	/// <param name="actor">追加するプレイヤーアクター</param>
	virtual void AddPlayer( UnitPtr actor ) = 0;
	/// <summary>
	/// プレイヤーの取得.
	/// </summary>
	/// <returns>プレイヤーアクターを取得</returns>
	virtual UnitPtr GetPlayer() const = 0;
	/// <summary>
	/// カメラを取得.
	/// </summary>
	/// <returns>カメラを返す</returns>
	virtual const Camera& GetCamera() const = 0;
	/// <summary>
	/// タイマーを取得.
	/// </summary>
	/// <returns>タイマーを返す</returns>
	virtual const Timer& GetTimer() const = 0;
	/// <summary>
	/// パラメータを取得.
	/// </summary>
	/// <returns>パラメータを返す.</returns>
	virtual const UnitParameter& GetParameter() const = 0;
	/// <summary>
	/// GUIを登録する.
	/// </summary>
	/// <param name="gui">追加するGUI</param>
	virtual void AddGUI( GUIFramePtr gui ) = 0;
	/// <summary>
	/// プレイヤーのGUIを登録する.
	/// </summary>
	/// <param name="gui">追加するGUI</param>
	virtual void AddPlayerGUI( GUIFramePtr gui ) = 0;
	/// <summary>
	/// GUIを登録からはずす.
	/// </summary>
	/// <param name="gui">削除するGUI</param>
	virtual void DeleteGUI( GUIFramePtr gui ) = 0;
	/// <summary>
	/// GUIコマンドを取得する.
	/// <para>マウスの左クリックが押されている時実行されます.</para>
	/// </summary>
	/// <returns>コマンドを返す.</returns>
	virtual GUICommand GetGUICommand() const = 0;
};

#endif

/********** End of File ******************************************************/
