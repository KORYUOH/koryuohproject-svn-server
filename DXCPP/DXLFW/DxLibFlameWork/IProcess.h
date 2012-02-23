/**===File Commentary=======================================*/
/**
 *	@file	IProcess.h
 *
 *	@brief	�v���Z�X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/20
 */
/**===Include Guard========================================*/
#ifndef	_IPROcESS_H_
#define	_IPROcESS_H_
/**===File Include=========================================*/

/**===Class Definition=====================================*/
class IProcess{
public:
	/**
	 *	@brief	������
	 *	@author	KORYUOH
	 */
	virtual void initialize()	=0;
	/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	<��Җ�>
	 *	@return	<�߂�l>
	 */
	virtual void update()	=0;
	/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	<��Җ�>
	 *	@return	<�߂�l>
	 */
	virtual void draw()	=0;
	/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	<��Җ�>
	 *	@return	<�߂�l>
	 */
	virtual void finish()	=0;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/