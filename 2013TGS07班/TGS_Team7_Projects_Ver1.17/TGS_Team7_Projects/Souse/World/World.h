/******************************************************************************
* File Name : World.h                             Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		ワールドクラス．
*
******************************************************************************/
#ifndef _WORLD_H_
#define _WORLD_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include"IWorld.h"
#include"WorldUnit.h"
#include"../Unit/UnitID.h"
#include"../Unit/UnitParameter.h"
#include"Timer.h"
#include"Camera.h"
#include"../GUI/GUIManager.h"

/*---- 先行宣言 -------------------------------------------------------------*/


/// <summary>
/// ワールドクラス.
/// </summary>
class World : public IWorld
{
#pragma region "コンストラクタ."

public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	World();
	/// <summary>
	/// デストラクタ.
	/// </summary>
	~World();


#pragma endregion


#pragma region "抽象でも呼び出せる処理."

public:
	/// <summary>
	/// アクターの追加.
	/// </summary>
	/// <param name="id">ユニットマネージャID</param>
	/// <param name="actor">追加するアクター</param>
	virtual void Add( UnitID id,UnitPtr actor );
	/// <summary>
	/// プレイヤーの生成.
	/// </summary>
	/// <param name="actor">追加するプレイヤーアクター</param>
	virtual void AddPlayer( UnitPtr actor );
	/// <summary>
	/// オブジェクトの追加.
	/// </summary>
	/// <param name="object">追加するアクターオブジェクト</param>
	virtual void AddObject( UnitPtr object );
	/// <summary>
	/// プレイヤーの取得.
	/// </summary>
	/// <returns>プレイヤーアクターを取得</returns>
	virtual UnitPtr GetPlayer()const;
	/// <summary>
	/// カメラを取得.
	/// </summary>
	/// <returns>カメラを返す</returns>
	virtual const Camera& GetCamera() const;
	/// <summary>
	/// タイマーを取得.
	/// </summary>
	/// <returns>タイマーを返す</returns>
	virtual const Timer& GetTimer() const;
	/// <summary>
	/// パラメータを取得.
	/// </summary>
	/// <returns>パラメータを返す.</returns>
	virtual const UnitParameter& GetParameter() const;
	/// <summary>
	/// GUIを登録する.
	/// </summary>
	/// <param name="gui">追加するGUI</param>
	virtual void AddGUI( GUIFramePtr gui );
	/// <summary>
	/// プレイヤーのGUIを登録する.
	/// </summary>
	/// <param name="gui">追加するGUI</param>
	virtual void AddPlayerGUI( GUIFramePtr gui );
	/// <summary>
	/// GUIを登録からはずす.
	/// </summary>
	/// <param name="gui">削除するGUI</param>
	virtual void DeleteGUI( GUIFramePtr gui );
	/// <summary>
	/// GUIコマンドを取得する.
	/// <para>マウスの左クリックが押されている時実行されます.</para>
	/// </summary>
	/// <returns>コマンドを返す.</returns>
	virtual GUICommand GetGUICommand() const;

#pragma endregion


#pragma region "抽象では呼び出せない処理."

public:
	/// <summary>
	/// 更新.
	/// </summary>
	/// <param name="frameTimer">フレームレート</param>
	void Update( float frameTimer );
	/// <summary>
	/// 描画.
	/// </summary>
	void Draw();
	/// <summary>
	/// UIの描画.
	/// </summary>
	void DrawUI();
	/// <summary>
	/// 消去.
	/// </summary>
	void Clear();

#pragma endregion


#pragma region "アクセスの禁止"

private:
	/// <summary>
	/// コピーコンストラクタ(外部からは禁止).
	/// </summary>
	World( const World& world );
	/// <summary>
	/// 代入演算子オーバロード禁止.
	/// </summary>
	World& operator =(const World& world);


#pragma endregion


#pragma region "メンバ変数"

private:
	/// <summary>
	/// ワールドアクター.
	/// </summary>
	WorldUnit		mUnits;
	/// <summary>
	/// プレイヤー.
	/// </summary>
	UnitPtr			mPlayer;
	/// <summary>
	/// GUIマネージャー.
	/// </summary>
	GUIManager		mGUIManager;
	/// <summary>
	/// カメラ.
	/// </summary>
	Camera			mCamera;
	/// <summary>
	/// タイマー.
	/// </summary>
	Timer			mTimer;
	/// <summary>
	/// ユニットのパラメータ.
	/// </summary>
	UnitParameter	mParameter;

#pragma endregion


};

#endif

/********** End of File ******************************************************/
