/**===File Commentary=======================================*/
/**
 *	@file	ClassDefine.h
 *
 *	@brief	�N���X�^�ݒ�t�@�C��
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/22
 */
/**===Include Guard========================================*/
#ifndef	_CLASSDEFINE_H_
#define	_CLASSDEFINE_H_
/**===File Include=========================================*/
#include	<memory>
#include	<Type/Vector3.h>
#include	<gslib.h>
class	IGameSystem;
/**===Class Definition=====================================*/

typedef	std::shared_ptr<IGameSystem>	GameSystem_ptr_t;
typedef	Vector3 Circle_t;

#define	MOUSE_LEFT		GLUT_LEFT_BUTTON				//���N���b�N
#define	MOUSE_RIGHT	GLUT_RIGHT_BUTTON			//�E�N���b�N
#define	MOUSE_MIDLE	GLUT_MIDDLE_BUTTON		//�z�C�[���N���b�N

#define	MOUSE_STATE_UP			GLUT_UP			//�}�E�X�{�^�������ꂽ
#define	MOUSE_STATE_DOWN	GLUT_DOWN		//�}�E�X�{�^���������ꂽ

/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/