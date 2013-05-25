/******************************************************************************
* File Name : SceneManager.h                     Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		シーン管理クラス．
*
******************************************************************************/
#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<map>
#include<memory>

/*---- 先行宣言 -------------------------------------------------------------*/

enum Scene;
class IScene;

/*---- クラス宣言 -----------------------------------------------------------*/

/// <summary>
/// シーン管理者クラス.
/// </summary>
class SceneManager
{
private:
	// 型の置き換え.
	typedef std::shared_ptr<IScene> IScenePtr;
	typedef std::map<Scene,IScenePtr> SceneContainer;


public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	SceneManager();
	/// <summary>
	/// 初期化.
	/// </summary>
	void Initialize();
	/// <summary>
	/// 更新.
	/// </summary>
	/// <param name="frameTimer">フレームタイマー</param>
	void Update(float frameTimer);
	/// <summary>
	/// 描画.
	/// </summary>
	void Draw(); 
	/// <summary>
	/// 終了.
	/// </summary>
	void Shutdown();
	/// <summary>
	/// シーンの追加.
	/// </summary>
	/// <param name="name">登録するのシーン列挙</param>
	/// <param name="scene">登録するのシーン情報</param>
	void Add ( Scene name, IScene* scene);
	/// <summary>
	/// シーンの追加.
	/// </summary>
	/// <param name="name">登録するのシーン列挙</param>
	/// <param name="scene">登録するのシーン情報</param>
	void Add ( Scene name, IScenePtr scene);
	/// <summary>
	/// シーンの変更.
	/// </summary>
	/// <param name="name">次のシーン列挙</param>
	void Change(Scene name);

private:
	SceneManager(const SceneManager& other);
	SceneManager& operator = (const SceneManager& other);

private:
	/// <summary>
	/// シーンコンテナ.
	/// </summary>
	SceneContainer scenes;
	/// <summary>
	/// 現在のシーン.
	/// </summary>
	IScenePtr currentScene;
};

#endif

/********** End of File ******************************************************/
