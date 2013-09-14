/**===File Commentary=======================================*/
/**
 *	@file	SceneBase.h
 *
 *	@brief	シーン基底ファイル
 *
 *	@author	KORYUOH
 *
 *	@date	2013/09/14
 */
/**===Include Guard========================================*/
#ifndef	_SCENEBASE_H_
#define	_SCENEBASE_H_
/**===File Include=========================================*/
#include	<memory>
#include	<Scene/IMediator/ISceneMediator.h>
/**===Class Definition=====================================*/
class SceneBase{
public:
	/**
	 *	@brief	コンストラクタ
	 */
	SceneBase();
	/**
	 *	@brief	初期化
	 */
	void initialize();
	/**
	 *	@brief	更新
	 *	@param[in]	フレーム
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
	void SceneChange(SceneBase* scene);
	/**
	 *	@brief	シーン変更
	 *	@param[in]	シーン
	 */
	void SceneChange(std::shared_ptr<SceneBase> scene);
	/**
	 *	@brief	通知者設定
	 *	@param[in]	通知者
	 */
	void setMediator(ISceneMediator& mediator);
	/**
	 *	@brief	仮想デストラクタ
	 */
	virtual ~SceneBase(){}
private:
	/**	メンバー変数*/
	ISceneMediator* mMediator;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/