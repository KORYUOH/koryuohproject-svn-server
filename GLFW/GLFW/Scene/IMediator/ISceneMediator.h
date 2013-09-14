/**===File Commentary=======================================*/
/**
 *	@file	ISceneMediator.h
 *
 *	@brief	シーン通知者
 *
 *	@author	KORYUOH
 *
 *	@date	2013/09/14
 */
/**===Include Guard========================================*/
#ifndef	_ISCENEMEDIATOR_H_
#define	_ISCENEMEDIATOR_H_
/**===File Include=========================================*/
#include <memory>
class SceneBase;
/**===Class Definition=====================================*/
class ISceneMediator{
public:
	/**
	 *	@brief	シーン変更
	 *	@param[in]	シーン
	 */
	virtual void SceneChange(SceneBase* scene) = 0;
	virtual void SceneChange(std::shared_ptr<SceneBase> scene) = 0;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/