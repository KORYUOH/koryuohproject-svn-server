/**===File Commentary=======================================*/
/**
 *	@file	IGameSystem.h
 *
 *	@brief	�Q�[���V�X�e���C���^�[�t�F�[�X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/22
 */
/**===Include Guard========================================*/
#ifndef	_IGAMESYSTEM_H_
#define	_IGAMESYSTEM_H_
/**===File Include=========================================*/
/**===Class Definition=====================================*/
class IGameSystem{

public:
	/**
	 *	@brief	������
	 *	@author	KORYUOH
	 */
	virtual void initialize() = 0;
	/**
	 *	@brief	�Q�[�����C��
	 *	@author	KORYUOH
	 */
	virtual void update(float f) =0;
	/**
	 *	@brief	�`��
	 *	@author	KORYUOH
	 */
	virtual void draw() = 0;
	/**
	 *	@brief	�I��
	 *	@author	KORYUOH
	 */
	virtual void finish() =0;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/