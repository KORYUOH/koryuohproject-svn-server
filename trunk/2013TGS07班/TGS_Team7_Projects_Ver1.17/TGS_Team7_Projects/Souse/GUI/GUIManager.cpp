/******************************************************************************
* File Name : UIFrame.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ユーザーインターフェースフレームクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"GUIManager.h"
#include"GUIFrame.h"
#include<algorithm>

/// <summary>
/// コンストラクタ.
/// </summary>
GUIManager::GUIManager() : 
	mPlayerGUI( NULL )
{
	// 初期化する.
	mGUIColliderContainer.clear();
}

/// <summary>
/// 描画.
/// </summary>
void GUIManager::Draw() const
{
	// すべてのUIを描画する.
	std::for_each( mGUIColliderContainer.begin(), mGUIColliderContainer.end(), []( GUIFramePtr gui )
	{
		// GUIを描画する.
		gui->Draw();
	});

	// 衝突を行わないGUIを描画する.
	std::for_each( mGUIContainer.begin(), mGUIContainer.end(), []( GUIFramePtr frame )
	{
		frame->Draw();
	});

	// プレイヤーが設定されている時.
	if( mPlayerGUI != NULL )
	{
		//プレイヤーのGUIを描画.
		mPlayerGUI->Draw();
	}
}

/// <summary>
/// コマンドを取得.
/// </summary>
/// <returns>コマンドを返す.</returns>
GUICommand GUIManager::GetCommand() const
{
	// コマンドを取得.
	GUICommand command = GUI_COMMAND_FALSE;

	//for( GUIFrameContainer::iterator gui = mGUIs.begin() ; gui != mGUIs.end() ; gui++ )
	//{
	//	command = gui->get()->GetCommand();

	//	// コマンドが偽でない時,
	//	if( command != GUI_COMMAND_FALSE )
	//	{
	//		return command;
	//	}
	//}

	// コマンドを返す.
	return GUI_COMMAND_FALSE;
}

/// <summary>
/// GUIを追加する.
/// </summary>
/// <param name="gui">追加するGUI</param>
void GUIManager::Add( GUIFramePtr gui )
{
	// UIを追加する.
	mGUIColliderContainer.push_back( gui );
}

/// <summary>
/// プレイヤーGUIを追加する.
/// </summary>
/// <param name="gui">追加するGUI</param>
void GUIManager::AddPlayer( GUIFramePtr gui )
{
	mPlayerGUI = gui;
}

/// <summary>
/// UIを削除する.
/// </summary>
/// <param name="addUI">削除するUI</param>
void GUIManager::Delete( GUIFramePtr gui )
{
	// GUIを削除する.
	mGUIColliderContainer.remove( gui );
}

/// <summary>
/// 更新.
/// </summary>
/// <param name="frameTimer">フレームレート</param>
void GUIManager::Update( float frameTimer )
{
	// すべてのUIを描画する.
	std::for_each( mGUIColliderContainer.begin(), mGUIColliderContainer.end(), [&]( GUIFramePtr gui )
	{
		// GUIを更新する.
		gui->Update( frameTimer );
	});

	// プレイヤーGUIが存在している時.
	if( mPlayerGUI != NULL )
	{
		// プレイヤーGUIを更新する.
		mPlayerGUI->Update( frameTimer );

		// プレイヤーと他のGUIを衝突させる.
		Collision( mPlayerGUI );

	}

}

/// <summary>
/// 衝突判定.
/// </summary>
/// <param name="other">衝突情報</param>
void GUIManager::Collision( GUIFramePtr other )
{
	for( GUIFrameContainer::iterator gui = mGUIColliderContainer.begin() ; gui != mGUIColliderContainer.end() ; gui++ )
	{
		// 衝突処理を行う.
		gui->get()->CollisionUpdate( *other );
	}
}

/// <summary>
/// 消去.
/// </summary>
void GUIManager::Clear()
{
	mGUIColliderContainer.clear();
	mGUIContainer.clear();
	mPlayerGUI = NULL;
}

/********** End of File ******************************************************/
