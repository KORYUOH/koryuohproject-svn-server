/******************************************************************************
* File Name : GUIManager.h                        Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ユーザーインターフェース管理者クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_MANAGER_H_
#define _GUI_MANAGER_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include"GUICommand.h"
#include"GUIFramePtr.h"
#include<list>
#include<memory>

/*---- 先行宣言 -------------------------------------------------------------*/


/// <summary>
/// ユーザーインターフェース管理者クラス．
/// </summary>
class GUIManager
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	GUIManager();
	/// <summary>
	/// GUIを追加する.
	/// </summary>
	/// <param name="gui">追加するGUI</param>
	void Add( GUIFramePtr gui );
	/// <summary>
	/// プレイヤーGUIを追加する.
	/// </summary>
	/// <param name="gui">追加するGUI</param>
	void AddPlayer( GUIFramePtr gui );
	/// <summary>
	/// UIを削除する.
	/// </summary>
	/// <param name="addUI">削除するUI</param>
	void Delete( GUIFramePtr gui );
	/// <summary>
	/// 更新.
	/// </summary>
	/// <param name="frameTimer">フレームレート</param>
	void Update( float frameTimer );
	/// <summary>
	/// 描画.
	/// </summary>
	void Draw() const;
	/// <summary>
	/// コマンドを取得.
	/// </summary>
	/// <returns>コマンドを返す.</returns>
	GUICommand	GetCommand() const;
	/// <summary>
	/// 衝突判定.
	/// </summary>
	/// <param name="other">衝突情報</param>
	void Collision( GUIFramePtr other );
	/// <summary>
	/// 消去.
	/// </summary>
	void Clear();
private:
	/// <summary>
	/// 衝突も行うGUIコンテナ.
	/// </summary>
	GUIFrameContainer	mGUIColliderContainer;
	/// <summary>
	/// 描画のみ行うGUIコンテナ.
	/// </summary>
	GUIFrameContainer	mGUIContainer;
	/// <summary>
	/// プレイヤーのGUI.
	/// </summary>
	GUIFramePtr			mPlayerGUI;

};

#endif // GUIManager end

/********** End of File ******************************************************/
