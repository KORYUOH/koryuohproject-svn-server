/**===File Commentary=======================================*/
/**
 *	@file	SceneManager.h
 *
 *	@brief	シーン管理者
 *
 *	@author	KORYUOH
 *
 *	@date	2013/09/14
 */
/**===Include Guard========================================*/
#ifndef	_SCENEMANAGER_H_
#define	_SCENEMANAGER_H_
/**===File Include=========================================*/
#include	<Scene/IMediator/ISceneMediator.h>
#include	<Scene/Base/SceneBase.h>
#include	<memory>
/**===Class Definition=====================================*/
class SceneManager:public ISceneMediator{
public:
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	[シーン]
	 */
	SceneManager();
	SceneManager(SceneBase* scene);
	SceneManager(std::shared_ptr<SceneBase> scene);
	/**
	 *	@brief	初期化
	 */
	void initialize();
	/**
	 *	@brief	更新
	 *	@param[in]	フレームタイム
	 */
	void update(float f);
	/**
	 *	@brief	描画
	 */
	void draw();
	/**
	 *	@brief	終了
	 */
	void finish();
	/**
	 *	@brief	シーン変更
	 *	@param[in]	シーン
	 */
	virtual void SceneChange(SceneBase* scene);
	/**
	 *	@brief	シーン変更
	 *	@param[in]	シーン
	 */
	virtual void SceneChange(std::shared_ptr<SceneBase> scene);
private:
	/**	メンバー変数*/
	std::shared_ptr<SceneBase> mFirstScene;
	std::shared_ptr<SceneBase> mNextScene;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/