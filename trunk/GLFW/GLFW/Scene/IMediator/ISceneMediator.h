/**===File Commentary=======================================*/
/**
 *	@file	ISceneMediator.h
 *
 *	@brief	�V�[���ʒm��
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
	 *	@brief	�V�[���ύX
	 *	@param[in]	�V�[��
	 */
	virtual void SceneChange(SceneBase* scene) = 0;
	virtual void SceneChange(std::shared_ptr<SceneBase> scene) = 0;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/