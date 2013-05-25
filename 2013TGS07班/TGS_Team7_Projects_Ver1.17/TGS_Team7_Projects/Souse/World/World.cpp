/******************************************************************************
* File Name : World.cpp                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ワールドクラス．
*
******************************************************************************/
#include	"World.h"
#include	<cassert>
#include	"../Unit/UnitID.h"
#include	"../Unit/UnitPtr.h"
#include	"../GUI/GUIFrame.h"
#include	"../Input/InputState.h"

#pragma region "コンストラクタ."


/// <summary>
/// コンストラクタ.
/// </summary>
World ::World():
	mUnits(),
	mPlayer(),
	mGUIManager(),
	mCamera(),
	mTimer(),
	mParameter()
{
	// ワールドアクターの初期化.
	Clear();

	// タイマーの初期化.
	mTimer.Initialize( 60.0f );
	// パラメータの読み込み.
	mParameter.Initialize();
}


/// <summary>
/// デストラクタ.
/// </summary>
World ::~World()
{
	// ワールドアクターの消去.
	Clear();
}

#pragma endregion


#pragma region "抽象でも呼び出せる処理."



/// <summary>
/// アクターの追加.
/// </summary>
/// <param name="id">アクターマネージャID</param>
/// <param name="actor">追加するアクター</param>
void World::Add( UnitID id,UnitPtr actor )
{
	mUnits.Add(id,actor);
}

/// <summary>
/// プレイヤーの生成.
/// </summary>
/// <param name="actor">追加するプレイヤーアクター</param>
void World::AddPlayer( UnitPtr actor )
{
	assert( mPlayer == nullptr );
	mPlayer = actor;
	Add( UNIT_PLAYER, mPlayer );
}

/// <summary>
/// オブジェクトの追加.
/// </summary>
/// <param name="object">追加するアクターオブジェクト</param>
void World::AddObject( UnitPtr object )
{
	// オブジェクトを追加.
	Add( UNIT_NONE, object );
}

/// <summary>
/// プレイヤーの取得.
/// </summary>
/// <returns>プレイヤーアクターを取得</returns>
UnitPtr World::GetPlayer()const
{
	//プレイヤーを返す
	return mPlayer;
}

/// <summary>
/// カメラを取得.
/// </summary>
/// <returns>カメラを返す</returns>
const Camera& World::GetCamera() const
{
	return mCamera;
}

/// <summary>
/// タイマーを取得.
/// </summary>
/// <returns>タイマーを返す</returns>
const Timer& World::GetTimer() const
{
	return mTimer;
}

/// <summary>
/// パラメータを取得.
/// </summary>
/// <returns>パラメータを返す.</returns>
const UnitParameter& World::GetParameter() const
{
	return mParameter;
}

/// <summary>
/// GUIを登録する.
/// </summary>
/// <param name="gui">追加するGUI</param>
void World::AddGUI( GUIFramePtr gui )
{
	mGUIManager.Add( gui );
}

/// <summary>
/// プレイヤーのGUIを登録する.
/// </summary>
/// <param name="gui">追加するGUI</param>
void World::AddPlayerGUI( GUIFramePtr gui )
{
	mGUIManager.AddPlayer( gui );
}

/// <summary>
/// GUIを登録からはずす.
/// </summary>
/// <param name="gui">削除するGUI</param>
void World::DeleteGUI( GUIFramePtr gui )
{
	mGUIManager.Delete( gui );
}

/// <summary>
/// GUIコマンドを取得する.
/// <para>マウスの左クリックが押されている時実行されます.</para>
/// </summary>
/// <returns>コマンドを返す.</returns>
GUICommand World::GetGUICommand() const
{
	// マウスが押されている時実行.
	if( InputState::GetInstance()->IsEnterButton() )
	{
		// GUI管理者からコマンドを取得.
		return mGUIManager.GetCommand();
	}

	// 取得できないので、FALSEコマンドを返す.
	return GUI_COMMAND_FALSE;
}

#pragma endregion


#pragma region "抽象では呼び出せない処理."

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームレート</param>
void World::Update( float frameTimer )
{

	// タイマーを更新.
	mTimer.Update( frameTimer );

	// アクターを更新.
	mUnits.Update( frameTimer );


	// 生産処理.
	mUnits.Production( frameTimer );
	// 消費コスト処理.
	mUnits.Maintenance( frameTimer );


	// GUIを更新する.
	mGUIManager.Update( frameTimer );

}

/// <summary>
/// 描画.
/// </summary>
void World::Draw()
{
	// ユニットの描画.
	mUnits.Draw();
}

/// <summary>
/// UIの描画.
/// </summary>
void World::DrawUI()
{
	// タイマーの描画.
	mTimer.Draw();

	// ユニットのUIを描画.
	mUnits.DrawUI();

	mGUIManager.Draw();
}

/// <summary>
/// 消去.
/// </summary>
void World::Clear()
{
	// すべてのアクターマネージャーを消去.
	mUnits.Clear();
	// プレイヤーをnullに設定.
	mPlayer = nullptr;
	// GUIの消去.
	mGUIManager.Clear();
	// タイマーを初期化.
	mTimer.Initialize( 60.0f );

}


#pragma endregion


/********** End of File ******************************************************/